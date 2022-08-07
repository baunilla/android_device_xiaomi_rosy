/* Copyright (c) 2018-2020, The Linux Foundation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials provided
 *    with the distribution.
 *  * Neither the name of The Linux Foundation nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.

 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#define LOG_TAG "ThermalHAL-TARGET"
#include <utils/Log.h>

#include <hardware/hardware.h>
#include <hardware/thermal.h>
#include <stdlib.h>
#include "thermal_common.h"

#define SYSFS_PLATFORMID   "/sys/devices/soc0/soc_id"
#define SOC_INFO_NAME_LEN  15

struct therm_msm_soc_type {
    enum therm_msm_id msm_id;
    int  soc_id;
};

static struct therm_msm_soc_type msm_soc_table[] = {
    {THERM_MSM_8953, 293},
    {THERM_MSM_8953, 304},
    {THERM_MSM_8953, 338},
    {THERM_MSM_8953, 351},
};

static char *cpu_sensors_8953[] =
{
    "apc0-cpu0-usr",
    "apc0-cpu1-usr",
    "apc0-cpu2-usr",
    "apc0-cpu3-usr",
    "apc1-cpu0-usr",
    "apc1-cpu1-usr",
    "apc1-cpu2-usr",
    "apc1-cpu3-usr",
};

static char *misc_sensors_8953[] =
{
    "gpu0-usr",
    "battery",
    "xo-therm-adc"
};

static struct target_therm_cfg sensor_cfg_8953[] = {
    {
        .type = DEVICE_TEMPERATURE_CPU,
        .sensor_list = cpu_sensors_8953,
        .sens_cnt = ARRAY_SIZE(cpu_sensors_8953),
        .mult = 0.001,
    },
    {
        .type = DEVICE_TEMPERATURE_GPU,
        .sensor_list = &misc_sensors_8953[0],
        .sens_cnt = 1,
        .mult = 0.001,
        .label = "GPU",
    },
    {
        .type = DEVICE_TEMPERATURE_BATTERY,
        .sensor_list = &misc_sensors_8953[1],
        .sens_cnt = 1,
        .mult = 0.001,
        .label = "battery",
    },
    {
        .type = DEVICE_TEMPERATURE_SKIN,
        .sensor_list = &misc_sensors_8953[2],
        .sens_cnt = 1,
        .mult = 0.001,
        .label = "skin",
    }
};

static int get_soc_info(char *buf)
{
    int ret = 0;

    ret = read_line_from_file(SYSFS_PLATFORMID, buf, SOC_INFO_NAME_LEN);
    if (ret < 0) {
        ALOGE("Error getting platform_id %d", ret);
        return ret;
    }
    if (ret && buf[ret - 1] == '\n')
        buf[ret - 1] = '\0';

    return ret;
}

enum therm_msm_id therm_get_soc_id(void)
{
    static enum therm_msm_id msm_id;
    int soc_id = -1;

    if (!msm_id) {
        int idx;
        char buf[SOC_INFO_NAME_LEN];

        if (get_soc_info(buf) <= 0)
            return msm_id;

        soc_id = atoi(buf);
        for (idx = 0; idx < ARRAY_SIZE(msm_soc_table); idx++) {
            if (soc_id == msm_soc_table[idx].soc_id) {
                msm_id = msm_soc_table[idx].msm_id;
                break;
            }
        }
        if (!msm_id)
            ALOGE("Unknown target identified with soc id %d\n", soc_id);
   }

   return msm_id;
}

ssize_t get_temperatures(thermal_module_t *module, temperature_t *list, size_t size) {
    ALOGD("Entering %s",__func__);
    static int thermal_sens_size;

    if (!thermal_sens_size) {
	struct target_therm_cfg *cfg = sensor_cfg_8953;
        size_t num_cfg = ARRAY_SIZE(sensor_cfg_8953);

	thermal_sens_size = thermal_zone_init(cfg, num_cfg);
	if (thermal_sens_size <= 0 || therm_get_soc_id() != THERM_MSM_8953) {
            ALOGE("thermal sensor initialization is failed\n");
            thermal_sens_size = 0;
	    return 0;
        }
    }

    if (list == NULL)
        return thermal_sens_size;

    return get_temperature_for_all(list, size);
}
