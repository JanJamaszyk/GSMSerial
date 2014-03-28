#include "GSMSerial.h"

GSMSerial::GSMSerial(SoftwareSerial& stream) :
modem(stream)
{
}

bool GSMSerial::status() {
    modem.write("AT\r\n");
    String str;
    return queryResult(str);
}

bool GSMSerial::queryResult(String& str) {
    
    // Wait for new data
    while(!modem.available()) {
    }

    // Query Result String
    while(modem.available()) {
        str += (char)modem.read();
    }
    
    // Return if query was succesfull
    return str.endsWith("OK\r\n");
}

GSMSerial::~GSMSerial() {
}
