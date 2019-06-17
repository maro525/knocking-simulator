#include "box.h"

Box::Box(ofVec2f _pos, float i)
{
    pos = _pos;
    interval = i;
    bWaiting = false;
}

Box::~Box()
{
}

void Box::loadSound(string src)
{
    knocksound.load(src);
    knocksound.setVolume(0.75f);
    knocksound.setLoop(false);
    std::cout << "load " << src << endl;
}

void Box::monitor()
{
    if (!bWaiting)
        return;
    float now = ofGetElapsedTimef();
    float diff = ringTime - now;
    if(diff < 0){
        bWaiting = false;
    }
    else if (diff < 0.5)
    {
        knock();
        bWaiting = false;
    }
}

void Box::trigger()
{
    if(bWaiting) return;

    float now = ofGetElapsedTimef();
    ringTime = now + interval;
    bWaiting = true;
    std::cout << "trigger! " << bWaiting << endl;
}

void Box::knock()
{
    std::cout << "knock" << endl;
    knocksound.play();
    ofNotifyEvent(knockEvent, pos);
}