#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "BLEConnectionManager.h"
#include "BMDLensControl.h"
#include "BMDVideoControl.h"
#include "BMDTransportControl.h"
#include "BMDStatusMonitor.h"

class BMDDisplayInterface {
public:
    BMDDisplayInterface(int width = 128, int height = 64, int sda = 21, int scl = 22, int address = 0x3C);
    ~BMDDisplayInterface();
    
    // Initialization
    bool begin();
    
    // Display management
    void clear();
    void update();
    void setContrast(uint8_t contrast);
    Adafruit_SSD1306* getDisplay() { return m_pDisplay; }
    
    // Content display methods
    void showConnectionStatus(BLEConnectionManager* manager);
    void showLensInfo(BMDLensControl* lensControl);
    void showRecordingStatus(BMDTransportControl* transportControl);
    void showTimecode(BMDTransportControl* transportControl);
    void showBatteryStatus(BMDStatusMonitor* statusMonitor);
    void showCameraExposureInfo(BMDVideoControl* videoControl);
    
    // Layout modes
    enum DisplayMode {
        MODE_CONNECTION,  // Scanning/connection info
        MODE_RECORDING,   // Recording status and timecode
        MODE_LENS,        // Lens info and focus status
        MODE_EXPOSURE,    // WB, ISO, shutter info
        MODE_STATUS       // Battery, camera status, etc.
    };
    
    void setDisplayMode(DisplayMode mode);
    DisplayMode getDisplayMode() const;
    
private:
    // Display components
    Adafruit_SSD1306* m_pDisplay = nullptr;
    int m_width;
    int m_height;
    int m_sda;
    int m_scl;
    int m_address;
    
    // Display state
    DisplayMode m_currentMode = MODE_CONNECTION;
    bool m_initialized = false;
    
    // Helper methods for drawing
    void drawCenteredText(const String& text, int y);
    void drawProgressBar(int x, int y, int width, int height, float percentage);
    void drawBatteryIcon(int x, int y, float percentage);
    void drawRecordingIndicator(int x, int y, bool isRecording);
};
