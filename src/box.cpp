#include "box.h"

Box::Box(ofVec2f _pos)
{
    pos = _pos;
    bWaiting = false;
    bNormaling = false;
}

Box::~Box()
{
}

void Box::loadSound(string src)
{
    knocksound.load(src);
    knocksound.setVolume(3.0f);
    knocksound.setLoop(false);
    std::cout << "load " << src << endl;
}

void Box::monitor()
{
    if (!bWaiting && !bNormaling)
        return;

    float now = ofGetElapsedTimef();
    if (bWaiting)
    {
        float diff = ringTime - now;
        if (diff < 0)
        {
            bWaiting = false;
        }
        else if (diff < 0.5)
        {
            knock();
            bNormaling = true;
            bWaiting = false;
            normalTime = now + interval * 2;
        }
    }
    else if (bNormaling)
    {
        float diff = normalTime - now;
        if (diff < 0.5)
        {
            bNormaling = false;
        }
    }
}

void Box::trigger(ofVec2f knockpos)
{
    if (bWaiting || bNormaling)
        return;

    float dis = pos.distance(knockpos);
    if (dis > distance_thresh)
        return;
    interval = max_waittime * dis / distance_thresh;

    float now = ofGetElapsedTimef();
    ringTime = now + interval;
    bWaiting = true;
}

void Box::knock()
{
    std::cout << "knock" << endl;
    knocksound.play();
    ofNotifyEvent(knockEvent, pos);
}