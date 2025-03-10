#include <Arduino.h>
#include <BLEAdvertisedDevice.h>
#include <BLERemoteCharacteristic.h>

namespace BMDCallbacks {
    // Connection management callbacks
    typedef void (*ConnectionCallback)(bool connected);
    typedef uint32_t (*PINRequestCallback)(void);
    typedef void (*DeviceFoundCallback)(const BLEAdvertisedDevice& device);
    
    // Status monitoring callbacks
    typedef void (*StatusCallback)(uint8_t status);
    typedef void (*ControlCallback)(uint8_t* pData, size_t length);
    typedef void (*TimecodeCallback)(const String& timecode);
    
    // Lens callbacks
    typedef void (*FocusCallback)(float normalizedValue);
    typedef void (*ApertureCallback)(float normalizedValue);
    typedef void (*ZoomCallback)(float normalizedValue);
    
    // Video callbacks
    typedef void (*WhiteBalanceCallback)(uint16_t kelvin, int16_t tint);
    typedef void (*ISOCallback)(uint32_t iso);
    typedef void (*ShutterCallback)(float angle);
    
    // Transport callbacks
    typedef void (*RecordingCallback)(bool isRecording);
}
