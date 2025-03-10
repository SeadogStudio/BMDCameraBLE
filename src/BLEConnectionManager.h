#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEScan.h>
#include <BLEClient.h>
#include <Preferences.h>
#include "BMDProtocol.h"
#include "BMDCallbacks.h"

class BLEConnectionManager {
public:
    BLEConnectionManager(const char* deviceName = "ESP32CameraControl");
    ~BLEConnectionManager();
    
    bool init();
    void update();
    
    // Scanning methods
    void startScan(uint32_t duration = 10);
    void stopScan();
    bool isScanning() const;
    
    // Connection methods
    bool connect();
    bool connectToAddress(const BLEAddress& address);
    void disconnect();
    bool isConnected() const;
    bool isDeviceFound() const;
    
    // Bonding management
    void forgetBonding();
    bool isBonded() const;
    
    // Characteristic access
    BLERemoteCharacteristic* getOutgoingControlCharacteristic();
    BLERemoteCharacteristic* getIncomingControlCharacteristic();
    BLERemoteCharacteristic* getTimecodeCharacteristic();
    BLERemoteCharacteristic* getCameraStatusCharacteristic();
    
    // Callback registration
    void setConnectionCallback(BMDCallbacks::ConnectionCallback callback);
    void setPINRequestCallback(BMDCallbacks::PINRequestCallback callback);
    void setDeviceFoundCallback(BMDCallbacks::DeviceFoundCallback callback);
    
    // Notification setup
    bool setNotification(BLERemoteCharacteristic* pChar, bool enable, bool isIndication);
    
private:
    // Inner classes for BLE callbacks
    class MyAdvertisedDeviceCallbacks;
    class MySecurityCallbacks;
    
    // BLE components
    BLEClient* m_pClient = nullptr;
    BLEScan* m_pBLEScan = nullptr;
    BLEAddress* m_pServerAddress = nullptr;
    MyAdvertisedDeviceCallbacks* m_pAdvertisedCallback = nullptr;
    MySecurityCallbacks* m_pSecurityCallback = nullptr;
    
    // Characteristics
    BLERemoteCharacteristic* m_pOutgoingCameraControl = nullptr;
    BLERemoteCharacteristic* m_pIncomingCameraControl = nullptr;
    BLERemoteCharacteristic* m_pTimecode = nullptr;
    BLERemoteCharacteristic* m_pCameraStatus = nullptr;
    BLERemoteCharacteristic* m_pDeviceName = nullptr;
    
    // State tracking
    bool m_initialized = false;
    bool m_deviceFound = false;
    bool m_connected = false;
    bool m_scanning = false;
    char m_deviceName[32];
    
    // Callbacks
    BMDCallbacks::ConnectionCallback m_connectionCallback = nullptr;
    BMDCallbacks::PINRequestCallback m_pinRequestCallback = nullptr;
    BMDCallbacks::DeviceFoundCallback m_deviceFoundCallback = nullptr;
    
    // Preferences for bonding info
    Preferences m_preferences;
    
    // Private methods
    bool connectToServer();
    void loadBondingInformation();
    void saveBondingInformation();
};
