#include <Arduino.h>
#include <BLEClient.h>
#include "BLEConnectionManager.h"
#include "BMDProtocol.h"
#include "BMDProtocolUtils.h"

class BMDLensControl {
public:
    BMDLensControl(BLEConnectionManager* connectionManager);
    
    // Focus controls
    bool setFocus(float normalizedValue);
    bool setFocusRaw(uint16_t rawValue);
    bool performAutoFocus();
    
    // Aperture controls
    bool setAperture(float normalizedValue);
    bool setApertureF(float fStop);
    bool performAutoAperture();
    
    // Zoom controls
    bool setZoom(float normalizedValue);
    bool setZoomMM(uint16_t focalLength);
    
    // Information retrieval
    String getLensModel() const;
    String getFocalLength() const;
    String getFocusDistance() const;
    
    // Notification processing
    void processNotification(uint8_t* pData, size_t length);
    
private:
    BLEConnectionManager* m_pConnectionManager;
    
    // Lens state variables
    String m_lensModel = "";
    String m_focalLength = "";
    String m_focusDistance = "";
    float m_currentFocus = 0.5f;
    float m_currentAperture = 0.5f;
    float m_currentZoom = 0.0f;
    
    // Send command helper
    bool sendCommand(uint8_t* commandBuffer, size_t length);
};
