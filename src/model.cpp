#include "model.h"

Model::Model()
{
    soundsrc = "knock.mp3";
}

Model::~Model()
{
}

void Model::setup()
{
    int num = 10;
    addBoxes(num);
}

void Model::addBoxes(int num)
{
    for (int i = 0; i < num; i++)
    {
        ofVec2f pos = ofVec2f(ofRandom(100, ofGetWidth() - 100), ofRandom(100, ofGetHeight() - 100));
        addBox(pos);
    }
}

void Model::addBox(ofVec2f pos)
{
    std::cout << "Box Added at " << pos << endl;
    Box *b;
    b = new Box(pos);
    int s;
    if (bSoundDiversity)
        s = ofRandom(0, 8);
    else
        s = ofRandom(0, 1);

    switch (s)
    {
    case 0:
        soundsrc = "knock.mp3";
        break;
    case 1:
        soundsrc = "1.mp3";
        break;
    case 2:
        soundsrc = "2.mp3";
        break;
    case 3:
        soundsrc = "3.mp3";
        break;
    case 4:
        soundsrc = "4.mp3";
        break;
    case 5:
        soundsrc = "5.mp3";
        break;
    case 6:
        soundsrc = "6.mp3";
        break;
    case 7:
        soundsrc = "7.mp3";
        break;
    case 8:
        soundsrc = "8.mp3";
        break;
    default:
        break;
    }
    b->loadSound(soundsrc);
    b->set_normal_interval_time();
    // ofAddListener(b->knockEvent, this, &Model::knocked);
    ofAddListener(b->knockValueEvent, this, &Model::knockedv);
    boxes.push_back(b);
}

void Model::knocked(ofVec2f &c_pos)
{
    ofNotifyEvent(knockOnTableEvent, c_pos);

    for (auto box : boxes)
    {
        box->trigger(c_pos);
    }
}

void Model::knockedv(int &value)
{
    ofNotifyEvent(knockVOnTableEvent, value);
    for (auto box : boxes)
    {
        box->triggerByValue(value);
    }
}

void Model::monitor()
{
    for (auto box : boxes)
    {
        box->monitor();
    }
}