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

    res = loader.handleRequest(req);//load request into response object
    json.parse(res.data);//parse response data into json object so we can work with it

    cout << json.getRawString() << endl;//output raw data
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	// everything here

	

	

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