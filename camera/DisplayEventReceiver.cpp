#include <stdint.h>
#include <gui/ISurfaceComposer.h>

namespace android {
    extern "C" void _ZN7android20DisplayEventReceiverC2ENS_16ISurfaceComposer11VsyncSourceENS_5FlagsINS1_17EventRegistrationEEE(ISurfaceComposer::VsyncSource vsyncSource, ISurfaceComposer::EventRegistrationFlags eventRegistration);

    extern "C" void _ZN7android20DisplayEventReceiverC1ENS_16ISurfaceComposer11VsyncSourceE(ISurfaceComposer::VsyncSource vsyncSource) {
    			ISurfaceComposer::EventRegistrationFlags eventRegistration = {};
                    _ZN7android20DisplayEventReceiverC2ENS_16ISurfaceComposer11VsyncSourceENS_5FlagsINS1_17EventRegistrationEEE(vsyncSource, eventRegistration);
    }
}
