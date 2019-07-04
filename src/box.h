#pragma once

#include "ofMain.h"

class Box
{
public:
    Box(ofVec2f _pos);
    ~Box();

    void loadSound(string src);
    void set_normal_interval_time();
    void monitor();
    void trigger(ofVec2f knockpos);
    void triggerByValue(int value);
    void knock();

    ofVec2f getPos() { return pos; };
    bool getWaiting() { return bWaiting; };
    bool getNormaling() { return bNormaling; };

    ofEvent<ofVec2f> knockEvent;
    ofEvent<int> knockValueEvent;

private:
    ofVec2f pos;
    ofSoundPlayer knocksound;
    float ringTime;
    bool bWaiting;
    bool bNormaling;
    float normalTime;
    float interval;

    float distance_thresh = 300;
    float max_waittime = 1.2;
    float normal_interval_time;
    float normal_value = 20.0;
};
