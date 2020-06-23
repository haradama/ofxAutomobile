//
//  ofxAutomobile.cpp
//  ofxAutomobile
//
//  Created by Masafumi Harada on 2020/02/16.
//

#include "ofxAutomobile.h"
#include "OBD2PIDs.h"

void ofxAutomobile::setup(const string device) {
    serial.setup(device);
}

std::vector<string> ofxAutomobile::query(string command) {
    ofx::IO::ByteBuffer textBuffer(command);
    serial.writeBytes(command);
    serial.flushInput();
    string result = serial.readStringUntil();
    serial.flushOutput();
    const char LF = '\n';
    const char CR = '\r';
    std::string dest;
    for (const auto c : result) {
        if (c != CR && c != LF) {
            dest += c;
        }
    }
    result = std::move(dest);
    
    std::vector<string> results;
    char sep = ' ';
    std::stringstream stringstream(result);
    std::string element;
    while (std::getline(stringstream, element, sep)) {
        results.push_back(element);
    }
    
    return results;
}

float ofxAutomobile::readCalculatedEngineLoad() {
    string command = PID_CALCULATED_ENGINE_LOAD;
    std::vector<string> results = ofxAutomobile::query(command);
    int valueA = std::stoi(results[results.size() - 2], nullptr, 16);
    float engineLoad = (100.0 / 255.0) * valueA;
    assert(0 <= engineLoad);
    assert(100 >= engineLoad);
    return engineLoad;
}

float ofxAutomobile::readEngineCoolantTemperature() {
    int value = 0;
    float engineCoolantTemperature = value - 40;
    assert(-40 <= engineCoolantTemperature);
    assert(215 >= engineCoolantTemperature);
    return engineCoolantTemperature;
}

float ofxAutomobile::readEngineRPM() {
    string command = PID_RPM;
    std::vector<string> results = ofxAutomobile::query(command);
    int valueA = std::stoi(results[results.size() - 3], nullptr, 16);
    int valueB = std::stoi(results[results.size() - 2], nullptr, 16);
    float engineRPM = ((256 * valueA) + valueB) / 4;
    assert(0 <= engineRPM);
    assert(16383.75 >= engineRPM);
    return engineRPM;
}

float ofxAutomobile::readVehicleSpeed() {
    string command = PID_SPEED;
    std::vector<string> results = ofxAutomobile::query(command);
    int vehicleSpeed = std::stoi(results[results.size() - 2], nullptr, 16);
    assert(0 <= vehicleSpeed);
    assert(vehicleSpeed <= 255);
    return vehicleSpeed;
}

float ofxAutomobile::readTimingAdvance() {
    int valueA = 0;
    float timingAdvance = valueA / 2 - 64;
    assert(-64 <= timingAdvance);
    assert(63.5 >= timingAdvance);
    return timingAdvance;
}

string ofxAutomobile::readFuelType() {
    int value = 0;
    string fuelType;
    std::map<int, string> fuelTypes {
        {1, "Gasoline"},
        {2, "Methanol"},
        {3, "Ethanol"},
        {4, "Diesel"},
        {5, "LPG"},
        {6, "CNG"},
        {7, "Propane"},
        {8, "Electric"},
        {9, "Bifuel running Gasoline"},
        {10, "Bifuel running Methanol"}
    };
    
    auto itr = fuelTypes.find(value);
    if (itr != fuelTypes.end()) {
        fuelType = fuelTypes[value];
    } else {
        fuelType = "";
    }
    return fuelType;
}


