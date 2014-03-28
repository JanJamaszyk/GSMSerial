#ifndef GSMSERIAL_H_
#define GSMSERIAL_H_

#include <SoftwareSerial.h>
#include <String.h>

class GSMSerial {

    private:
        SoftwareSerial& modem;
        bool queryResult(String& str);

    public:
        GSMSerial(SoftwareSerial& stream);
        ~GSMSerial();
        void begin(long speed);
        bool status();

};

#endif // GSMSERIAL_H_
