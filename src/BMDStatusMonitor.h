#include <Arduino.h>
#include <BLEClient.h>
#include "BLEConnectionManager.h"
#include "BMDProtocol.h"
#include "BMDProtocolUtils.h"
#include "BMDCallbacks.h"

class BMDStatusMonitor {
public:
    BMDStatusMonitor(BLEConnectionManager* connectionManager);
    
    // Status monitoring
    void begin();
    void update();
    
    // Battery monitoring
    float getBatteryVoltage() const;
    int getBatteryPercentage() const;
    bool isExternalPower() const;
    
    // Camera information
    uint8_t getCameraStatus() const;
    String getCameraModel() const;
    
    // Notification registration
    void registerStatusCallback(BMDCallbacks::StatusCallback callback);
    void registerIncomingControlCallback(BMDCallbacks::ControlCallback callback);
    void registerTimecodeCallback(BMDCallbacks::TimecodeCallback callback);
    
    // Internal notification handlers
    static void incomingControlNotify(BLERemoteCharacteristic* pChar, uint8_t* pData, size_t length, bool isNotify);
    static void timecodeNotify(BLERemoteCharacteristic* pChar, uint8_t* pData, size_t length, bool isNotify);
    static void statusNotify(BLERemoteCharacteristic* pChar, uint8_t* pData, size_t length, bool isNotify);
    
private:
    BLEConnectionManager* m_pConnectionManager;
    
    // Status variables
    float m_batteryVoltage = 0.0f;
    int m_batteryPercentage = 0;
    bool m_externalPower = false;
    uint8_t m_cameraStatus = 0;
    String m_cameraModel = "";
    
    // Callbacks
    BMDCallbacks::StatusCallback m_statusCallback = nullptr;
    BMDCallbacks::ControlCallback m_controlCallback = nullptr;
    BMDCallbacks::TimecodeCallback m_timecodeCallback = nullptr;
    
    // Static instance for callbacks
    static BMDStatusMonitor* s_instance;
};
