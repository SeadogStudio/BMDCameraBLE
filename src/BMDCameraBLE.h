#include <Arduino.h>
#include "BLEConnectionManager.h"
#include "BMDLensControl.h"
#include "BMDVideoControl.h"
#include "BMDTransportControl.h"
#include "BMDStatusMonitor.h"
#include "BMDDisplayInterface.h"
#include "BMDCallbacks.h"

class BMDCameraBLE {
public:
    BMDCameraBLE(const char* deviceName = "ESP32CameraControl");
    ~BMDCameraBLE();
    
    // Initialization
    bool begin(bool useDisplay = false, int sda = 21, int scl = 22);
    void update();
    
    // Module access
    BLEConnectionManager* getConnectionManager() { return m_pConnectionManager; }
    BMDLensControl* getLensControl() { return m_pLensControl; }
    BMDVideoControl* getVideoControl() { return m_pVideoControl; }
    BMDTransportControl* getTransportControl() { return m_pTransportControl; }
    BMDStatusMonitor* getStatusMonitor() { return m_pStatusMonitor; }
    BMDDisplayInterface* getDisplayInterface() { return m_pDisplayInterface; }
    
    // Convenience methods (delegated to appropriate modules)
    bool connect();
    void disconnect();
    bool isConnected() const;
    
    // Focus controls
    bool setFocus(float normalizedValue);
    bool performAutoFocus();
    
    // White balance
    bool setWhiteBalance(uint16_t kelvin);
    bool performAutoWhiteBalance();
    
    // Recording
    bool startRecording();
    bool stopRecording();
    bool toggleRecording();
    bool isRecording() const;
    
    // Display control
    void setDisplayMode(BMDDisplayInterface::DisplayMode mode);
    
    // Callback registration convenience methods
    void setConnectionCallback(BMDCallbacks::ConnectionCallback callback);
    void setPINRequestCallback(BMDCallbacks::PINRequestCallback callback);
    
private:
    // Module components
    BLEConnectionManager* m_pConnectionManager = nullptr;
    BMDLensControl* m_pLensControl = nullptr;
    BMDVideoControl* m_pVideoControl = nullptr;
    BMDTransportControl* m_pTransportControl = nullptr;
    BMDStatusMonitor* m_pStatusMonitor = nullptr;
    BMDDisplayInterface* m_pDisplayInterface = nullptr;
    
    // State tracking
    bool m_initialized = false;
    bool m_displayEnabled = false;
    
    // Other helpers
    void processIncomingControl(uint8_t* pData, size_t length);
};
