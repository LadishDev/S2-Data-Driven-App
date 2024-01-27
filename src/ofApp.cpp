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
    req.headers["Authorization"] = "Discogs token=mTFAawaxdtKqkgVeBZovKdEwJKjUeLrKBJGPEvcU";
    req.method = ofHttpRequest::GET;//sets request method to get (e.g. retrieve data)

    //res = loader.handleRequest(req);//load request into response object
    //json.parse(res.data);//parse response data into json object so we can work with it

    cout << json.getRawString() << endl;//output raw data

    // set background color to Ghost White
    ofBackground(248, 248, 255);


    OpenSanstitle.load("opensans.ttf", 60); //load font
    OpenSans.load("opensans.ttf", 36); //load font

    BtnImg.load("loginbtn.png");
    BtnMenuImg.load("menubtn.png");
    BtnSearchImg.load("searchbtn.png");
    BtnHomeImg.load("homebtn.png");

    MenuBtn.set(10, 10, 50, 50); // Set button position
    HomeBtn.set(75, 10, 50, 50); // Set button position
    SearchBtn.set(55, 105, 50, 50); // Set button position
    LoginBtn.set(340, 1000, 400, 80); // Set button position

    TextBox.set(55, 105, 965, 50); // Set text box position for search
    MachineState = "First Time Launch";
    TextInput = false;
    word = "";
}

//--------------------------------------------------------------
void ofApp::update() {
    if (TextInput == false) {
        word = "Click to Search";
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
    if (MachineState == "First Time Launch") {
        ofSetColor(0, 0, 0); // Set text color to black
        OpenSanstitle.drawString("DiscoJam",416,120); //draw title

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
    }
    else if (MachineState == "Home Page") {
        // First Section
        ofSetColor(47, 79, 79);
        ofDrawRectangle(30, 200, 1015, 300);
        ofSetColor(255, 255, 255);
        ofDrawRectangle(35, 205, 200, 290);
        ofDrawRectangle(245, 205, 200, 290);
        ofDrawRectangle(455, 205, 200, 290);
        ofDrawRectangle(665, 205, 200, 290);
        ofDrawRectangle(875, 205, 170, 290);

        // Second Section
        ofSetColor(47, 79, 79);
        ofDrawRectangle(30, 550, 1015, 300);
        ofSetColor(255, 255, 255);
        ofDrawRectangle(35, 555, 200, 290);
        ofDrawRectangle(245, 555, 200, 290);
        ofDrawRectangle(455, 555, 200, 290);
        ofDrawRectangle(665, 555, 200, 290);
        ofDrawRectangle(875, 555, 170, 290);

        // Third Section
        ofSetColor(47, 79, 79);
        ofDrawRectangle(30, 900, 1015, 300);
        ofSetColor(255, 255, 255);
        ofDrawRectangle(35, 905, 200, 290);
        ofDrawRectangle(245, 905, 200, 290);
        ofDrawRectangle(455, 905, 200, 290);
        ofDrawRectangle(665, 905, 200, 290);
        ofDrawRectangle(875, 905, 170, 290);
    } 
    else if (MachineState == "Search Query") {
        OpenSans.drawString("Results For " + WordSearched, 100, 210);

        // Giant Box for Results
        ofSetColor(47, 79, 79);
        ofDrawRectangle(30, 250, 1015, 950);

        // Column of results 
        ofSetColor(255, 255, 255);
        ofDrawRectangle(35, 255, 1005, 130);
        ofDrawRectangle(35, 390, 1005, 130);
        ofDrawRectangle(35, 525, 1005, 130);
        ofDrawRectangle(35, 660, 1005, 130);
        ofDrawRectangle(35, 795, 1005, 130);
        ofDrawRectangle(35, 930, 1005, 130);
        ofDrawRectangle(35, 1065, 1005, 130);

        // Draw artist images and names
        for (int i = 0; i < 7; ++i) {
            // Draw image rectangle
            ofSetColor(255, 255, 255);
            ofDrawRectangle(50, 265 + i * 135, 100, 100);

            // Load and draw artist image
            string imageURL = json["results"][i]["thumb"].asString();
            ofImage artistImage;
            artistImage.load(imageURL);
            artistImage.draw(50, 265 + i * 135, 100, 100);

            // Draw artist name
            ofSetColor(0, 0, 0);
            OpenSans.drawString(json["results"][i]["title"].asString(), 200, 310 + i * 135);

            // Make a view more box in bottom right corner of each result
            ofSetColor(47, 79, 79);
            // make button rectangle for view more button for each result with unique id
            ViewMoreBtn[i].set(835, 318 + i * 135, 200, 60);
            ofDrawRectangle(ViewMoreBtn[i]);


            ofSetColor(255, 255, 255);
            OpenSans.drawString("View More", 845, 360 + i * 135);
        }
    }
    else if (MachineState == "View Song") {
        ofSetColor(47, 79, 79);
        ofDrawRectangle(30, 250, 1015, 950);

        // Place poster in top left corner
        ofSetColor(255, 255, 255);
        string imageURL = json["images"][0]["uri"].asString();
        ofImage artistImage;
        artistImage.load(imageURL);
        artistImage.draw(50, 265, 100, 100);

        // Draw artist name
        ofSetColor(0, 0, 0);
        OpenSans.drawString(json["title"].asString(), 200, 310);
    }

    // Draw the Top Navigation Bar and Search Bar
    if (MachineState != "First Time Launch") {
        // Top Bar
        ofSetColor(47, 79, 79);
        ofDrawRectangle(0, 0, 1280, 70);

        // Title
        ofSetColor(255, 255, 255);
        OpenSans.drawString("DiscoJam", 465, 51);

        // Hamburger Menu
        BtnMenuImg.draw(MenuBtn);

        // Home Button
        BtnHomeImg.draw(HomeBtn);

        // Main Body
        // Search Bar
        ofSetColor(0, 0, 0);
        ofDrawRectangle(50, 100, 975, 60);
        if (TextInput == false) {
            ofSetColor(150);
        }
        else {
            ofSetColor(255);
        }
        ofDrawRectangle(TextBox);
        ofSetColor(0);
        OpenSans.drawString(word, 105, 145);

        // Search Icon
        ofSetColor(0, 0, 0);
        BtnSearchImg.draw(SearchBtn);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    if (TextInput == true && validKey(key)) {
        if ((key == OF_KEY_BACKSPACE || key == OF_KEY_DEL)) {
            if (word.length() != 0) {
                word.pop_back();
            }
        }
        else if (key == OF_KEY_RETURN) {
            cout << "Searching For: " << word << endl;
            WordSearched = word;
            // iterate through the string and replace spaces with + signs and convert to lowercase
            for (int i = 0; i < word.length(); i++) {
                if (word[i] == ' ') {
                    word[i] = '+';
                }
            }
            // set the request url to the search query
            req.url = "https://api.discogs.com/database/search?q=" + word;
            cout << req.url << endl;
            res = loader.handleRequest(req);//load request into response object
            json.parse(res.data);//parse response data into json object so we can work with it
            word = "";
            TextInput = false;
            MachineState = "Search Query";
		}
        else {
			ofUTF8Append(word, key);
		}
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//-----------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
    if (MachineState == "First Time Launch") {
        if (LoginBtn.inside(x, y)) {
            cout << "Login Button Pressed" << endl;
            ofBackground(248, 248, 255);
            MachineState = "Home Page";
        }
    }
    else if (MachineState == "Home Page") {

    }
    else if (MachineState == "Search Query") {
        for (int i = 0; i < 7; ++i) {
            if (ViewMoreBtn[i].inside(x, y)) {
                cout << "View More Button Pressed: " << i << endl;

                req.url = "https://api.discogs.com/artists/" + json["results"][i]["id"].asString();
                cout << req.url << endl;
                res = loader.handleRequest(req);//load request into response object
                json.parse(res.data);//parse response data into json object so we can work with it
                MachineState = "View Song";
            }
        }
    }

    if (MachineState != "First Time Launch") {
        if (MenuBtn.inside(x, y)) {
            cout << "Menu Button Pressed" << endl;
        }
        else if (HomeBtn.inside(x, y)) {
            cout << "Home Button Pressed" << endl;
            ofBackground(248, 248, 255);
            MachineState = "Home Page";
        }
        if (TextBox.inside(x, y) && TextInput == false) {
            TextInput = true;
            word = "";
        }
        else {
            TextInput = false;
        }
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

bool ofApp::validKey(int key) {
    if (key == OF_KEY_ALT || key == OF_KEY_CONTROL || key == OF_KEY_SHIFT || key == OF_KEY_COMMAND) {
		return false;
	}
    else {
		return true;
	}
}