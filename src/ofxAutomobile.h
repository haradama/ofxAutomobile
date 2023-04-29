#pragma once

#include "OBD2Commands.h"
#include "ofMain.h"
#include "ofxSerial.h"

class ofxAutomobile {
   public:
    ofxAutomobile();
    ~ofxAutomobile();

    bool setup(const std::string& port_name, int baud_rate = 115200);
    bool query(const std::string& command, std::string& response);

   private:
    bool send_command(const std::string& command);
    bool read_response(std::string& response);

    ofx::IO::SerialDevice device;

};
