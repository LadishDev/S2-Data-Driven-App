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
	bool validKey(int key); //checks if key is valid for search

	ofHttpRequest req;//handles request to API
	ofHttpResponse res;//handles response from API
	ofURLFileLoader loader;//object to load data
	ofxJSONElement json;//object to store data
	
	ofTrueTypeFont OpenSans;//font object
	ofTrueTypeFont OpenSanstitle;//font object

	string MachineState;

	ofImage BtnImg;
	ofRectangle LoginBtn;

	ofRectangle TextBox; //text box for search
	bool TextInput; //checks if text input is active
	string word; //stores word to be searched
};