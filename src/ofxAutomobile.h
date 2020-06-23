//
//  ofxAutomobile.h
//  ofxAutomobile
//
//  Created by Masafumi Harada on 2020/02/16.
//

#ifndef ofxAutomobile_h
#define ofxAutomobile_h

#include "ofMain.h"
#include "ofxSerial.h"

class Sprite {
    public:
        void addImage(string imagePath);
        void addAnimation(string imagePath, string...);
        void changeAnimation(string label);
        void setSpeed(int speed);
        void draw();
    
    bool visible;
    int x;
    int y;
    int width;
    int height;
    ofImage image;
    std::vector<ofImage> animation;
};

class ofxAutomobile {
    private:
        int sendOBD2PID();
    public:
        void setup(const string device);
        std::vector<string> query(string command);
        float readCalculatedEngineLoad();
        float readEngineCoolantTemperature();
        float readEngineRPM();
        float readVehicleSpeed();
        float readTimingAdvance();
        float readIntakeAirTemperature();
        float readMAFAirFlowRate();
        float readThrottlePosition();
        float readCommandedSecondaryAirStatus();
        
        string readFuelType();
    
        Sprite* createSprite(int x, int y, int width, int height);
    
    ofx::IO::SerialDevice serial;
};

#endif /* ofxAutomobile_h */
