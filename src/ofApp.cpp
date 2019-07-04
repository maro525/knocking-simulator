#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetFrameRate(30);
    view.setModel(&model);
    // model.setup();

    ofBackground(249, 237, 219);
    ofSetCircleResolution(100);

    ofAddListener(model.knockOnTableEvent, &view, &View::addKnock);
}

//--------------------------------------------------------------
void ofApp::update()
{
    model.monitor();
}

//--------------------------------------------------------------
void ofApp::draw()
{
    view.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    if (key == OF_KEY_SHIFT)
    {
        bShift = true;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
    if (key == OF_KEY_SHIFT)
    {
        bShift = false;
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
    ofVec2f clickpos = ofVec2f(x, y);
    if (bShift)
    {
        model.addBox(clickpos);
    }
    else
    {
        // model.knocked(clickpos);
        int value = int(ofRandom(0, 100));
        model.knockedv(value);
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{
}
