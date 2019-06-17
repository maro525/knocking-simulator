#pragma once

#include "box.h"

class Model
{
public:
    Model();
    ~Model();
    void setup();
    void addBoxes(int num);
    void addBox(ofVec2f pos, float interval);
    void knocked(ofVec2f c_pos);

    void monitor();
    vector<Box> getBoxes() { return boxes; };

private:
    vector<Box> boxes;
    float a = 5.0;
    string soundsrc;
};