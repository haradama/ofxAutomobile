#include "ofxAutomobile.h"

ofxAutomobile::ofxAutomobile() {}

ofxAutomobile::~ofxAutomobile() {}

bool ofxAutomobile::setup(const std::string& port_name, int baud_rate) {
    bool success = device.setup(port_name, baud_rate);
    if (success) {
        ofLogError("ofxAutomobile::setup") << "Successfully setup: " << port_name;
    } else {
        ofLogError("ofxAutomobile::setup") << "Error setting up: " << port_name;
    }

}

bool ofxAutomobile::query(const std::string& command, std::string& response) {
    if (!send_command(command)) {
        return false;
    }
    return read_response(response);
}

bool ofxAutomobile::send_command(const std::string& command) {
    std::string cmd = command + "\r";
    try {
        device.writeBytes((const uint8_t*)cmd.c_str(), cmd.length());
    } catch (const std::exception& e) {
        ofLogError("ofxAutomobile::send_command") << "Error sending command: " << e.what();
        return false;
    }
    return true;
}

bool ofxAutomobile::read_response(std::string& response) {
    try {
        uint8_t buffer[1024];
        
        std::ostringstream msg;
        std::size_t sz = device.readBytes(buffer, 1024);
        for (std::size_t i = 0; i < sz; ++i) {
            msg << buffer[i];
        }

        response = msg.str();
        return true;
    } catch (const std::exception& e) {
        ofLogError("ofxAutomobile::read_response") << "Error reading response: " << e.what();
        return false;
    }
}
