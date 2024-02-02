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

	string MachineState, WordSearched;

	ofImage BtnImg, BtnMenuImg, BtnSearchImg, BtnHomeImg;
	ofRectangle LoginBtn, MenuBtn, SearchBtn, HomeBtn;

	ofRectangle ViewMoreBtn[7];

	ofRectangle TextBox; //text box for search
	bool TextInput; //checks if text input is active
	string word; //stores word to be searched


	// *** VIEW QUERY *** //
	std::vector<std::string> imageURL;
	std::vector<ofImage> artistImage;

	// *** Menu Page *** //
	ofRectangle MenuHomeBtn, MenuLibaryBtn, MenuGenresBtn, MenuSettingsBtn, MenuAboutBtn, MenuLogoutBtn;

	// *** Library Page *** //	
	ofRectangle LibraryBtn[7];
	ofRectangle LibraryViewMoreBtn[7];

	// *** Genres Page *** //
	ofRectangle GenresBtn[13];
	vector <string> GenresName;
};