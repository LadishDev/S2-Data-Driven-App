#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    /*
    API requires sign up here: https://accounts.discogs.com/login
    Once signed in you will need to create an app: https://www.discogs.com/settings/developers
    After creating an app you can generate a personal access token from this page: https://www.discogs.com/settings/developers
    As the API requires setting of headers to the steps to retrieve data are slightly different to the other APIs
    */
    req.headers["User-Agent"] = "450340_MusicAPI_BSU/v1 (callum.baldwin22@bathspa.ac.uk)";//sets user agent header - used to indentify your app
    req.method = ofHttpRequest::GET;//sets request method to get (e.g. retrieve data)
    req.url = "https://api.discogs.com/artists/125246?token=mTFAawaxdtKqkgVeBZovKdEwJKjUeLrKBJGPEvcU"; //specify the API call - this will retrieve Nirvana

    //res = loader.handleRequest(req);//load request into response object
   // json.parse(res.data);//parse response data into json object so we can work with it

    cout << json.getRawString() << endl;//output raw data

    // set background color to Ghost White
    ofBackground(248, 248, 255);


    OpenSanstitle.load("opensans.ttf", 60); //load font
    OpenSans.load("opensans.ttf", 36); //load font

    BtnImg.load("loginbtn.png");

    LoginBtn.set(340, 1000, 400, 70); // Set button position
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	// everything here
    ofSetColor(0, 0, 0); // Set text color to black
    OpenSanstitle.drawString("Disco Jam",415,120); //draw title

    // draw circle
    ofSetColor(47, 79, 79);
    ofDrawCircle(540, 560, 200);
    ofSetColor(255, 0, 0);
    ofDrawCircle(540, 560, 190);
    ofSetColor(47, 79, 79);
    ofDrawCircle(540, 560, 185);
    ofSetColor(255, 0, 07);
    ofDrawCircle(540, 560, 170);
    ofSetColor(47, 79, 79);
    ofDrawCircle(540, 560, 165);
    ofSetColor(255, 0, 0);
    ofDrawCircle(540, 560, 150);
    ofSetColor(47, 79, 79);
    ofDrawCircle(540, 560, 145);
    ofSetColor(255, 0, 0);
    ofDrawCircle(540, 560, 130);
    ofSetColor(47, 79, 79);
    ofDrawCircle(540, 560, 125);

    // black inner circle
    ofSetColor(0, 0, 0);
    ofDrawCircle(540, 560, 120);

    // Make the login button default color
    ofSetColor(255, 255, 255);
    BtnImg.draw(LoginBtn);

    //ofSetColor(255); // Set text color to white
    //OpenSans.drawString("Login", 490, 1045); // Draw text


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//-----------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}