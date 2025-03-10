#include <Arduino.h>
#include "BMDProtocol.h"

namespace BMDProtocolUtils {
    // Data conversion functions
    String dataToHexString(const uint8_t* data, size_t length);
    String dataToBinaryString(const uint8_t* data, size_t length);
    float fixed16ToFloat(uint16_t value);
    uint16_t floatToFixed16(float value);
    
    // Parameter extraction
    int8_t extractInt8(const uint8_t* data, size_t length, size_t offset = 8);
    int16_t extractInt16(const uint8_t* data, size_t length, size_t offset = 8);
    int32_t extractInt32(const uint8_t* data, size_t length, size_t offset = 8);
    float extractFixed16(const uint8_t* data, size_t length, size_t offset = 8);
    String extractString(const uint8_t* data, size_t length, size_t offset = 8);
    
    // Packet building helpers
    void buildCommandHeader(uint8_t* buffer, uint8_t category, uint8_t parameter, 
                           uint8_t dataType, uint8_t operation, uint8_t dataLength);
    
    // Interpretive functions
    String interpretDynamicRange(uint8_t value);
    String interpretDisplayLUT(uint8_t value);
    String interpretShutterAngle(int32_t value);
    String interpretShutterSpeed(int32_t value);
}
