#pragma once

#include "model.h"

struct Knock{
    ofVec2f pos;
    float radius;
};

class View
{
public:
    View();
    ~View();
    void setModel(Model *ref) { model = ref; };

    void draw();

    void drawBoxes();
    void drawBox(Box *b);

    void addKnock(ofVec2f & pos);
    void drawKnocks();

private:
    Model *model;
    float BoxSize = 20.0;

    queue<Knock> knocks;
    float speed = 50.0;
};