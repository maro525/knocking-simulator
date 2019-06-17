#pragma once

#include "model.h"

class View
{
public:
    View();
    ~View();
    void setModel(Model *ref) { model = ref; };

    void draw();

    void drawBoxes();
    void drawBox(Box *b);

private:
    Model *model;
    float BoxSize = 20.0;
};