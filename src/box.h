#pragma once

#include "ofMain.h"

class Box
{
public:
    Box(ofVec2f _pos, float i = 3.0);
    ~Box();

    void loadSound(string src);
    void monitor();
    void trigger();
    void knock();

    ofVec2f getPos() { return pos; };

    ofEvent<ofVec2f> knockEvent;

private:
    ofVec2f pos;
    ofSoundPlayer knocksound;
    float interval;
    float ringTime;
    bool bWaiting;
};
