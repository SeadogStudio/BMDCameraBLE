// Protocol constants and structures
namespace BMDProtocol {
    // Command categories
    constexpr uint8_t CAT_LENS = 0x00;
    constexpr uint8_t CAT_VIDEO = 0x01;
    constexpr uint8_t CAT_AUDIO = 0x02;
    constexpr uint8_t CAT_OUTPUT = 0x03;
    constexpr uint8_t CAT_DISPLAY = 0x04;
    constexpr uint8_t CAT_TALLY = 0x05;
    constexpr uint8_t CAT_REFERENCE = 0x06;
    constexpr uint8_t CAT_CONFIG = 0x07;
    constexpr uint8_t CAT_COLOR = 0x08;
    constexpr uint8_t CAT_STATUS = 0x09;
    constexpr uint8_t CAT_TRANSPORT = 0x0A;
    constexpr uint8_t CAT_EXTENDED_LENS = 0x0C;
    
    // Parameter definitions by category
    namespace Lens {
        constexpr uint8_t FOCUS = 0x00;
        constexpr uint8_t AUTO_FOCUS = 0x01;
        constexpr uint8_t APERTURE_FSTOP = 0x02;
        constexpr uint8_t APERTURE_NORM = 0x03;
        constexpr uint8_t APERTURE_AUTO = 0x05;
        constexpr uint8_t ZOOM_MM = 0x07;
        constexpr uint8_t ZOOM_NORM = 0x08;
    }
    
    namespace Video {
        constexpr uint8_t WB = 0x02;
        constexpr uint8_t AUTO_WB = 0x03;
        constexpr uint8_t DYNAMIC_RANGE = 0x07;
        constexpr uint8_t SHUTTER_ANGLE = 0x0B;
        constexpr uint8_t SHUTTER_SPEED = 0x0C;
        constexpr uint8_t GAIN = 0x0D;
        constexpr uint8_t ISO = 0x0E;
        constexpr uint8_t DISPLAY_LUT = 0x0F;
    }
    
    namespace Transport {
        constexpr uint8_t MODE = 0x01;
    }
    
    namespace ExtendedLens {
        constexpr uint8_t MODEL = 0x09;
        constexpr uint8_t FOCAL_LENGTH = 0x0B;
        constexpr uint8_t DISTANCE = 0x0C;
        constexpr uint8_t FILENAME = 0x0F;
    }
    
    // Data types
    constexpr uint8_t TYPE_VOID = 0x00;
    constexpr uint8_t TYPE_INT8 = 0x01;
    constexpr uint8_t TYPE_INT16 = 0x02;
    constexpr uint8_t TYPE_INT32 = 0x03;
    constexpr uint8_t TYPE_STRING = 0x05;
    constexpr uint8_t TYPE_FIXED16 = 0x80;
    
    // Operations
    constexpr uint8_t OP_ASSIGN = 0x00;
    constexpr uint8_t OP_OFFSET = 0x01;
    constexpr uint8_t OP_REPORT = 0x02;
    
    // UUIDs
    constexpr const char* SERVICE_UUID = "291d567a-6d75-11e6-8b77-86f30ca893d3";
    constexpr const char* OUTGOING_CONTROL_UUID = "5DD3465F-1AEE-4299-8493-D2ECA2F8E1BB";
    constexpr const char* INCOMING_CONTROL_UUID = "B864E140-76A0-416A-BF30-5876504537D9";
    constexpr const char* TIMECODE_UUID = "6D8F2110-86F1-41BF-9AFB-451D87E976C8";
    constexpr const char* CAMERA_STATUS_UUID = "7FE8691D-95DC-4FC5-8ABD-CA74339B51B9";
    constexpr const char* DEVICE_NAME_UUID = "FFAC0C52-C9FB-41A0-B063-CC76282EB89C";
    
    // Packet structure definition
    struct CommandPacket {
        uint8_t destination;  // Always 0xFF
        uint8_t length;       // Length of data following this byte
        uint8_t commandId;    // Always 0x00
        uint8_t reserved;     // Always 0x00
        uint8_t category;     // Command category
        uint8_t parameter;    // Parameter within category
        uint8_t dataType;     // Data type
        uint8_t operation;    // Operation type
        uint8_t data[56];     // Variable length data
    };
}
