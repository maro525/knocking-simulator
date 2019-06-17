#include "view.h"

View::View()
{
}

View::~View()
{
}

void View::draw()
{
    drawBoxes();
}

void View::drawBoxes()
{
    for (auto box : model->getBoxes())
    {
        drawBox(&box);
    }
}

void View::drawBox(Box *b)
{
    ofPushStyle();
    ofSetColor(255);
    ofDrawRectRounded(b->getPos(), BoxSize, BoxSize, 1);
    ofPopStyle();
}