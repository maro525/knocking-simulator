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
    Box box = Box(pos, interval);
    box.loadSound(soundsrc);
    boxes.push_back(box);
}

void Model::knocked(ofVec2f c_pos)
{
    for (auto box : boxes)
    {
        box.trigger();
    }
}

void Model::monitor()
{
    for (auto box : boxes)
    {
        box.monitor();
    }
}