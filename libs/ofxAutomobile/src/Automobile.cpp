#include "Automobile.h"

ofxAutomobile::ofxAutomobile(){};

ofxAutomobile::~ofxAutomobile(){};

void ofxAutomobile::setup(std::string device) {
    is_connected = serial.setup(device);
    if (is_connected) {
        ofLogNotice("ofxAutomobile::setup") << "Device is connected";
    }
};

std::array<int, 2> ofxAutomobile::ask(OBD2::PID pid) {
    std::stringstream stream;
    stream << std::hex << pid;
    ofx::IO::ByteBuffer textBuffer(stream.str());

    serial.writeBytes(textBuffer);
    serial.writeByte('\n');

    return std::array<int, 2>{1, 2};
}

std::future<float> ofxAutomobile::readVehicleSpeed() {
    auto result = std::async(std::launch::async, [this] {
        auto res_ = ask(OBD2::PID::SPEED);
        int vehicleSpeed = std::stoi(res_[res_.size() - 2], nullptr, 16);
        return vehicleSpeed
    });

    return result;
}