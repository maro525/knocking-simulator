#pragma once

#include "box.h"

class Model
{
public:
    Model();
    ~Model();
    void setup();
    void addBoxes(int num);
    void addBox(ofVec2f pos);
    void knocked(ofVec2f &c_pos);
    void knockedv(int &value);

    void monitor();
    vector<Box *> getBoxes() { return boxes; };
    ofEvent<ofVec2f> knockOnTableEvent;
    ofEvent<int> knockVOnTableEvent;

private:
    vector<Box *> boxes;
    string soundsrc;
    bool bSoundDiversity = false;
};