#pragma once

#include "ofMain.h"
#include "ofxJSON.h"
#include <vector>

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);

	ofHttpRequest req;//handles request to API
	ofHttpResponse res;//handles response from API
	ofURLFileLoader loader;//object to load data
	ofxJSONElement json;//object to store data

};