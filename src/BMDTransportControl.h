#include <Arduino.h>
#include <BLEClient.h>
#include "BLEConnectionManager.h"
#include "BMDProtocol.h"
#include "BMDProtocolUtils.h"

class BMDTransportControl {
public:
    BMDTransportControl(BLEConnectionManager* connectionManager);
    
    // Recording controls
    bool startRecording();
    bool stopRecording();
    bool toggleRecording();
    bool isRecording() const;
    
    // Timecode access
    String getTimecode() const;
    
    // Clip information
    String getCurrentClipName() const;
    
    // Notification processing
    void processNotification(uint8_t* pData, size_t length);
    void processTimecodeNotification(uint8_t* pData, size_t length);
    
private:
    BLEConnectionManager* m_pConnectionManager;
    
    // Transport state variables
    bool m_isRecording = false;
    String m_timecode = "--:--:--:--";
    String m_clipName = "";
    
    // Send command helper
    bool sendCommand(uint8_t* commandBuffer, size_t length);
};
