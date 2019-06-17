#include "box.h"

Box::Box(ofVec2f _pos, float i)
{
    pos = _pos;
    interval = i;
}

Box::~Box()
{
}

void Box::loadSound(string src)
{
    knocksound.load(src);
    knocksound.setVolume(0.75f);
    knocksound.setLoop(false);
}

void Box::monitor()
{
    if (!bWaiting)
        return;

    std::cout << "monitor " << bWaiting << endl;
    float now = ofGetElapsedTimef();
    float diff = now - ringTime;
    std::cout << "waiting" << endl;
    if (diff < 0.05)
    {
        knock();
        bWaiting = false;
    }
}

void Box::trigger()
{
    float now = ofGetElapsedTimef();
    ringTime = now + interval;
    bWaiting = true;
}

void Box::knock()
{
    std::cout << "knock" << endl;
    knocksound.play();
}