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
    drawKnocks();
}

void View::drawBoxes()
{
    ofPushStyle();
    for (auto box : model->getBoxes())
    {
        if (box->getWaiting())
            ofSetColor(214, 86, 47);
        else if (box->getNormaling())
            ofSetColor(218, 218, 242);
        else
            ofSetColor(237, 179, 99);

        ofDrawRectRounded(box->getPos(), BoxSize, BoxSize, 1);
    }
    ofPopStyle();
}

void View::addKnock(ofVec2f &pos)
{
    float r = 10.0;
    Knock k = {pos, r};
    knocks.push(k);
}

void View::drawKnocks()
{
    int size = knocks.size();
    if (size == 0)
        return;

    ofPushStyle();
    for (int i = 0; i < size; i++)
    {
        Knock k = knocks.front();
        knocks.pop();
        ofSetColor(20, 50);
        ofSetLineWidth(3);
        ofNoFill();
        ofDrawCircle(k.pos, k.radius);
        if (k.radius < 1000)
        {
            k.radius = k.radius + speed;
            knocks.push(k);
        }
    }
    ofPopStyle();
}
