#pragma once

#include "ofMain.h"
#include "ofxJSON.h"
#include <vector>
#include <random>

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
	void loadHomePage(); //loads home page

	// Libary Functions to load and save data
	void saveToLibrary();
	void loadLibrary();

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

	// *** Home Page *** //
	ofRectangle SongBtn1[5];
	ofRectangle SongBtn2[5];
	ofRectangle SongBtn3[5];

	vector<ofImage> HomeartistImage1, HomeartistImage2, HomeartistImage3;
	vector<string> imageURL1, imageURL2, imageURL3;
	ofxJSONElement homePagejson1, homePagejson2, homePagejson3;


	// *** VIEW QUERY *** //
	std::vector<std::string> imageURL;
	std::vector<ofImage> artistImage;
	ofRectangle addToLibraryBtn, viewOnDiscogsBtn;
	ofRectangle confirmationBtn;

	// *** Menu Page *** //
	ofRectangle MenuHomeBtn, MenuLibaryBtn, MenuGenresBtn, MenuSettingsBtn, MenuAboutBtn, MenuLogoutBtn;

	// *** Library Page *** //	
	ofRectangle LibraryBtn[7];
	ofRectangle LibraryViewMoreBtn[7];

	// *** Genres Page *** //
	ofRectangle GenresBtn[12];
	vector <string> GenresName = { "Rock", "Pop", "Jazz", "Blues", "Hip-Hop", "Country", "Electronic", "Folk", "Classical", "Reggae", "Soul"};
};