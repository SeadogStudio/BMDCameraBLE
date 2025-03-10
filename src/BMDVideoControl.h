#include <Arduino.h>
#include <BLEClient.h>
#include "BLEConnectionManager.h"
#include "BMDProtocol.h"
#include "BMDProtocolUtils.h"

class BMDVideoControl {
public:
    BMDVideoControl(BLEConnectionManager* connectionManager);
    
    // White balance
    bool setWhiteBalance(uint16_t kelvin, int16_t tint = 0);
    bool performAutoWhiteBalance();
    
    // ISO/Gain
    bool setISO(uint32_t iso);
    bool setGain(int8_t gainDB);
    
    // Shutter
    bool setShutterAngle(float angle);
    bool setShutterSpeed(float speed);
    
    // Dynamic range & LUT
    bool setDynamicRangeMode(uint8_t mode);
    bool setDisplayLUT(uint8_t lut);
    
    // State access
    uint16_t getCurrentWhiteBalance() const;
    int16_t getCurrentTint() const;
    uint32_t getCurrentISO() const;
    float getCurrentShutterAngle() const;
    
    // Notification processing
    void processNotification(uint8_t* pData, size_t length);
    
private:
    BLEConnectionManager* m_pConnectionManager;
    
    // Video state variables
    uint16_t m_whiteBalance = 5600;
    int16_t m_tint = 0;
    uint32_t m_iso = 400;
    float m_shutterAngle = 180.0f;
    uint8_t m_dynamicRange = 0;
    uint8_t m_displayLUT = 0;
    
    // Send command helper
    bool sendCommand(uint8_t* commandBuffer, size_t length);
};
