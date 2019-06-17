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
    ofPushStyle();
    ofSetColor(255);
    for (auto box : model->getBoxes())
    {
        ofDrawRectRounded(box->getPos(), BoxSize, BoxSize, 1);
    }
    ofPopStyle();
}
