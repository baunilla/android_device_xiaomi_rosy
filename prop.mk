
# Audio
PRODUCT_PROPERTY_OVERRIDES += \
persist.vendor.audio.fluence.speaker=false \
persist.vendor.audio.fluence.voicecall=true \
persist.vendor.audio.fluence.voicerec=false \
ro.vendor.audio.sdk.fluencetype=fluence \
ro.vendor.audio.sdk.ssr=false \
vendor.audio.flac.sw.decoder.24bit=true \
vendor.audio.hal.boot.timeout.ms=20000 \
vendor.audio.offload.buffer.size.kb=64 \
vendor.audio.offload.gapless.enabled=true \
vendor.audio.offload.multiaac.enable=true \
vendor.audio.offload.multiple.enabled=false \
vendor.audio.offload.passthrough=false \
vendor.audio.offload.track.enable=true \
vendor.audio.parser.ip.buffer.size=262144 \
vendor.audio.playback.mch.downsample=true \
vendor.audio.pp.asphere.enabled=false \
vendor.audio.read.wsatz.type=true \
vendor.audio.safx.pbe.enabled=true \
vendor.audio.spkr_prot.tx.sampling_rate=48000 \
vendor.audio.tunnel.encode=false \
vendor.audio.use.sw.alac.decoder=false \
vendor.audio.use.sw.ape.decoder=true \
vendor.audio_hal.period_size=192 \
vendor.voice.conc.fallbackpath=deep-buffer \
vendor.voice.path.for.pcm.voip=true \
vendor.voice.playback.conc.disabled=true \
vendor.voice.record.conc.disabled=false \
vendor.voice.voip.conc.disabled=true

PRODUCT_PROPERTY_OVERRIDES += \
vendor.audio.feature.snd_mon.enable=true \
vendor.audio.feature.compr_cap.enable=false \
vendor.audio.feature.hifi_audio.enable=true \
vendor.audio.feature.hdmi_edid.enable=false  \
vendor.audio.feature.dsm_feedback.enable=false \
vendor.audio.feature.ssrec.enable=false  \
vendor.audio.feature.compr_voip.enable=true \
vendor.audio.feature.kpi_optimize.enable=true \
vendor.audio.feature.usb_offload.enable=false  \
vendor.audio.feature.usb_offload_burst_mode.enable=false \
vendor.audio.feature.usb_offload_sidetone_volume.enable=false \
vendor.audio.feature.src_trkn.enable=true \
vendor.audio.feature.ras.enable=false \
vendor.audio.feature.a2dp_offload.enable=false \
vendor.audio.feature.wsa.enable=true \
vendor.audio.feature.compress_meta_data.enable=true \
vendor.audio.feature.vbat.enable=false \
vendor.audio.feature.display_port.enable=false \
vendor.audio.feature.fluence.enable=true \
vendor.audio.feature.custom_stereo.enable=true \
vendor.audio.feature.anc_headset.enable=true \
vendor.audio.feature.spkr_prot.enable=false \
vendor.audio.feature.fm.enable=true \
vendor.audio.feature.external_dsp.enable=false \
vendor.audio.feature.external_speaker.enable=false \
vendor.audio.feature.external_speaker_tfa.enable=false \
vendor.audio.feature.hwdep_cal.enable=false \
vendor.audio.feature.hfp.enable=true \
vendor.audio.feature.ext_hw_plugin.enable=false \
vendor.audio.feature.record_play_concurency.enable=false \
vendor.audio.feature.hdmi_passthrough.enable=false \
vendor.audio.feature.concurrent_capture.enable=false \
vendor.audio.feature.compress_in.enable=false \
vendor.audio.feature.battery_listener.enable=false \
vendor.audio.feature.maxx_audio.enable=false \
vendor.audio.feature.audiozoom.enable=false \
vendor.audio.feature.auto_hal.enable=false \
vendor.audio.read.wsatz.type=true \
vendor.audio.feature.multi_voice_session.enable=true \
vendor.audio.feature.incall_music.enable=true

# Bluetooth
PRODUCT_PROPERTY_OVERRIDES += \
vendor.qcom.bluetooth.soc=pronto \
persist.vendor.qcom.bluetooth.enable.splita2dp=false \
ro.vendor.bluetooth.wipower=false

# Dalvik
PRODUCT_VENDOR_PROPERTIES += \
dalvik.vm.heapstartsize=16m \
dalvik.vm.heapgrowthlimit=192m \
dalvik.vm.heapsize=512m \
dalvik.vm.heaptargetutilization=0.75 \
dalvik.vm.heapminfree=2m \
dalvik.vm.heapmaxfree=8m

# Display
PRODUCT_PROPERTY_OVERRIDES += \
ro.opengles.version=196610 \
ro.hardware.vulkan=adreno \
ro.hardware.egl=adreno

# DRM
PRODUCT_PROPERTY_OVERRIDES += \
drm.service.enabled=true

# FRP
PRODUCT_PROPERTY_OVERRIDES += \
ro.frp.pst=/dev/block/bootdevice/by-name/config

# IORap
PRODUCT_PRODUCT_PROPERTIES += \
ro.iorapd.enable=false

# Media
PRODUCT_PROPERTY_OVERRIDES += \
debug.stagefright.omx_default_rank=0 \
vendor.audio.hw.aac.encoder=true

# Radio
PRODUCT_PROPERTY_OVERRIDES += \
persist.dbg.volte_avail_ovr=1 \
persist.dbg.vt_avail_ovr=1 \
persist.dbg.wfc_avail_ovr=1 \
persist.radio.multisim.config=dsds \
persist.vendor.data.iwlan.enable=true \
persist.vendor.radio.add_power_save=1 \
persist.vendor.radio.apm_sim_not_pwdn=1 \
persist.vendor.radio.5g_mode_pref=0 \
persist.vendor.radio.custom_ecc=1 \
persist.vendor.radio.enableadvancedscan=false \
persist.vendor.radio.mt_sms_ack=30 \
persist.vendor.radio.procedure_bytes=SKIP \
persist.vendor.radio.rat_on=combine \
persist.vendor.radio.sib16_support=1 \
ro.telephony.call_ring.multiple=false \
ro.telephony.iwlan_operation_mode=legacy \
vendor.rild.libpath=/vendor/lib64/libril-qc-qmi-1.so \
service.qti.ims.enabled=1

# Sensors
PRODUCT_PROPERTY_OVERRIDES += \
ro.vendor.sensors.smd=false

# SoC
PRODUCT_VENDOR_PROPERTIES += \
ro.soc.manufacturer=Qualcomm \
ro.soc.model=MSM8953

# SurfaceFlinger
PRODUCT_PROPERTY_OVERRIDES += \
ro.surface_flinger.force_hwc_copy_for_virtual_displays=true \
ro.surface_flinger.max_frame_buffer_acquired_buffers=3 \
ro.surface_flinger.max_virtual_display_dimension=4096 \
ro.surface_flinger.protected_contents=true

# TCP
PRODUCT_PROPERTY_OVERRIDES += \
net.tcp.2g_init_rwnd=10

# USB
PRODUCT_PROPERTY_OVERRIDES += \
persist.vendor.usb.config.extra=none

# WiFi
PRODUCT_PROPERTY_OVERRIDES += \
wifi.interface=wlan0

# Zygote
PRODUCT_PROPERTY_OVERRIDES += \
zygote.critical_window.minute=10
