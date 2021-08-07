#ifndef ofxAutomobile_h
#define ofxAutomobile_h

#include <array>
#include <future>

#include "OBD2.h"
#include "ofxSerial.h"

using OBD2::PID;

class ofxAutomobile {
   public:
    ofxAutomobile();
    ~ofxAutomobile();
    void setup(const std::string device);
    std::array<int, 2> ask(OBD2::PID pid);
    std::future<int> readVehicleSpeed();

   private:
    bool is_connected;
    int query(OBD2::PID pid);
    ofx::IO::SerialDevice serial;
};

#endif /* ofxAutomobile_h */
