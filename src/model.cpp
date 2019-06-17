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
        float interval = (1.0 + ofRandomf()) * a;
        addBox(pos, interval);
    }
}

void Model::addBox(ofVec2f pos, float interval)
{
    std::cout << "Box Added at " << pos << endl;
    Box * b;
    b = new Box(pos, interval);
    b->loadSound(soundsrc);
    ofAddListener(b->knockEvent, this, &Model::knocked);
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

void Model::monitor()
{
    for (auto box : boxes)
    {
        box->monitor();
    }
}