#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    req.headers["User-Agent"] = "450340_MusicAPI_BSU/v1 (callum.baldwin22@bathspa.ac.uk)";//sets user agent header - used to indentify your app
    req.headers["Authorization"] = "Discogs token=mTFAawaxdtKqkgVeBZovKdEwJKjUeLrKBJGPEvcU"; //sets authorization header - used to authenticate your app
    req.method = ofHttpRequest::GET;//sets request method to get (e.g. retrieve data)

    imageURL.resize(7);
    artistImage.resize(7);
    HomeartistImage1.resize(5);
    HomeartistImage2.resize(5);
    HomeartistImage3.resize(5);

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
        ofDrawRectangle(15, 200, 1050, 300);

        // Draw artist images within rectangles
        for (int i = 0; i < json["results"].size(); ++i) {
            // Draw combined rectangle for image
            ofSetColor(255, 255, 255);
            SongBtn1[i].set(20 + i * 210, 205, 200, 290);
            ofDrawRectangle(SongBtn1[i]);

            // Draw artist image within the rectangle
            HomeartistImage1[i].draw(20 + i * 210, 205, 200, 290);
        }

        // Second Section
        ofSetColor(47, 79, 79);
        ofDrawRectangle(15, 550, 1050, 300);

        for (int i = 0; i < json2["results"].size(); ++i) {
            // Draw combined rectangle for image
            ofSetColor(255, 255, 255);
            SongBtn2[i].set(20 + i * 210, 555, 200, 290);
            ofDrawRectangle(SongBtn2[i]);

            // Draw artist image within the rectangle
            HomeartistImage2[i].draw(20 + i * 210, 555, 200, 290);
        }

        // Third Section
        ofSetColor(47, 79, 79);
        ofDrawRectangle(15, 900, 1050, 300);

        for (int i = 0; i < json3["results"].size(); ++i) {
            // Draw combined rectangle for image
            ofSetColor(255, 255, 255);
            SongBtn3[i].set(20 + i * 210, 905, 200, 290);
            ofDrawRectangle(SongBtn3[i]);

            // Draw artist image within the rectangle
            HomeartistImage3[i].draw(20 + i * 210, 905, 200, 290);
        }
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
        for (int i = 0; i < json["results"].size(); ++i) {
            // Draw image rectangle
            ofSetColor(255, 255, 255);
            ofDrawRectangle(50, 265 + i * 135, 100, 100);

            artistImage[i].draw(50, 265 + i * 135, 100, 100);

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
        artistImage[0].draw(50, 265, 200, 200);

        // Draw artist name
        ofSetColor(255, 255, 255);
        OpenSans.drawString(json["title"].asString(), 260, 310);

        // Draw Release Year
        OpenSans.drawString("Release Date: " + json["released"].asString(), 260, 420);

        // Draw genre and print out all the values within the array
        OpenSans.drawString("Genre: ", 70, 520);
        for (int i = 0; i < json["genres"].size(); ++i) {
            OpenSans.drawString(json["genres"][i].asString(), 70, 570 + i * 50);
        }

        // Draw style and print out all the values within the array
        OpenSans.drawString("Style: ", 700, 520);
        for (int i = 0; i < json["styles"].size(); ++i) {
			OpenSans.drawString(json["styles"][i].asString(), 700, 570 + i * 50);
		}

        // View on Discogs Button
        ofSetColor(255, 255, 255);
        ofDrawRectangle(addToLibraryBtn);
        ofDrawRectangle(viewOnDiscogsBtn);
        ofSetColor(0, 0, 0);
        OpenSans.drawString("Add to Library", 380, 1102);
        OpenSans.drawString("View on Discogs", 380, 1172);
    }
    else if (MachineState == "Menu Page") {
		ofBackground(47, 79, 79);
        
        // Set the Menu Options locations
		MenuHomeBtn.set(50, 200, 975, 60);
		MenuLibaryBtn.set(50, 300, 975, 60);
        MenuGenresBtn.set(50, 400, 975, 60);
		MenuSettingsBtn.set(50, 500, 975, 60);
		MenuAboutBtn.set(50, 600, 975, 60);
		MenuLogoutBtn.set(50, 700, 975, 60);
        
        // Draw the Menu Options
        ofSetColor(255, 255, 255);
        ofDrawRectangle(MenuHomeBtn);
        ofDrawRectangle(MenuLibaryBtn);
        ofDrawRectangle(MenuGenresBtn);
        ofDrawRectangle(MenuSettingsBtn);
        ofDrawRectangle(MenuAboutBtn);
        ofDrawRectangle(MenuLogoutBtn);

		// Draw the Menu Options Text
		ofSetColor(0, 0, 0);
		OpenSans.drawString("Home", 460, 245);
		OpenSans.drawString("Library", 460, 345);
        OpenSans.drawString("Genres", 460, 445);
		OpenSans.drawString("Settings", 460, 545);
		OpenSans.drawString("About", 460, 645);
		OpenSans.drawString("Logout", 460, 745);
    }
    else if (MachineState == "Library Page") {
        ofSetColor(0);
        OpenSanstitle.drawString("Library", 405, 230);

         // Big container for the library items
        ofSetColor(47, 79, 79);
        ofDrawRectangle(30, 250, 1015, 950);

        // Draw Album Art and Album Name
        ofSetColor(255, 255, 255);
        ofDrawRectangle(35, 255, 190, 290);
        ofDrawRectangle(240, 255, 190, 290);
        ofDrawRectangle(445, 255, 190, 290);
        ofDrawRectangle(655, 255, 190, 290);
        ofDrawRectangle(865, 255, 190, 290);


	}
    else if (MachineState == "Genres Page") {
        ofSetColor(47, 79, 79);
        ofDrawRectangle(30, 250, 1015, 950);

        // boxes for each genre
        ofSetColor(255, 255, 255);
        for (int i = 0; i < 12; i++) {
		    ofDrawRectangle(GenresBtn[i]);
		}

        // Draw genre names
        ofSetColor(0, 0, 0);
        for (int i = 0; i < 12; i++) {
			OpenSans.drawString(GenresName[i], 50, 295 + i * 70);
		}
    }
    else if (MachineState == "Settings Page") { // Not Exactly Sure What Options to currently add. However, this is a placeholder for now to show that the settings page is being worked on.
        OpenSanstitle.drawString("Settings", 425, 250);

        // Draw the Settings Options
        ofSetColor(47, 79, 79);
        ofDrawRectangle(50, 400, 975, 60);
        ofDrawRectangle(50, 500, 975, 60);
        ofDrawRectangle(50, 600, 975, 60);
        ofDrawRectangle(50, 700, 975, 60);
        ofDrawRectangle(50, 800, 975, 60);
        ofDrawRectangle(50, 900, 975, 60);

        // Draw the Settings Options Text
        ofSetColor(255, 255, 255);
        OpenSans.drawString("Option 1", 460, 445);
        OpenSans.drawString("Option 2", 460, 545);
        OpenSans.drawString("Option 3", 460, 645);
        OpenSans.drawString("Option 4", 460, 745);
        OpenSans.drawString("Option 5", 460, 845);
        OpenSans.drawString("Option 6", 460, 945);
    }

    else if (MachineState == "About Page") {
        OpenSanstitle.drawString("About", 460, 250);

        // Draw the About Information container 
        ofSetColor(47, 79, 79);
        ofDrawRectangle(50, 300, 975, 600);

        // Draw the About Information Text
        ofSetColor(255, 255, 255);
        OpenSans.drawString("This is a music application that allows you to search for music and view information about the music you search for.", 60, 350);
        OpenSans.drawString("This application is designed to be user friendly and easy to use.", 60, 400);
        OpenSans.drawString("You are able to save songs to come back and look back at later on or store things u wish to purchase.", 60, 450);
        OpenSans.drawString("You can use the search feature to search for song titles. If u want to search by artist and song name u can use this format (Artist - Song Name)", 60, 500);
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
            // if word has a - in it then grab the first word before the - and use that as the search query for artist name and grab the word after and store that for the track name 
            // iterate through the string and replace spaces with + signs and convert to lowercase

            if (word.find("-") != string::npos) {
                string artist = word.substr(0, word.find("-"));
                string track = word.substr(word.find("-") + 1);
                for (int i = 0; i < artist.length(); i++) {
                    if (artist[i] == ' ') {
                        artist[i] = '+';
                    }
                }
                for (int i = 0; i < track.length(); i++) {
                    if (track[i] == ' ') {
                        track[i] = '+';
                    }
                }
                // if end of string is a + sign then remove it
                if (artist[artist.length() - 1] == '+') {
                    artist.pop_back();
                }
                // set the request url to the search query
                req.url = "https://api.discogs.com/database/search?artist=" + artist + "&track=" + track + "&page=1&per_page=7";
                res = loader.handleRequest(req);//load request into response object
                json.parse(res.data);//parse response data into json object so we can work with it
            }
            else {
                for (int i = 0; i < word.length(); i++) {
                    if (word[i] == ' ') {
                        word[i] = '+';
                    }
                }
                // set the request url to the search query
                req.url = "https://api.discogs.com/database/search?track=" + word + "&page=1&per_page=7";
                res = loader.handleRequest(req);//load request into response object
                json.parse(res.data);//parse response data into json object so we can work with it
            }
            cout << req.url << endl;
            // set the request url to the search query
            imageURL.clear();
            for (int i = 0; i < json["results"].size(); ++i) {
                string url = json["results"][i]["thumb"].asString();
                imageURL.push_back(url);
                cout << "URL[" << i << "]: " << url << endl;
                artistImage[i].load(imageURL[i]);
            }
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
            loadHomePage();
            MachineState = "Home Page";
        }
    }
    else if (MachineState == "Home Page") {
        for (int i = 0; i < 13; i++) {
            if (SongBtn1[i].inside(x, y)) {
				cout << "Song Button " << i << " Pressed" << endl;
				req.url = json["results"][i]["resource_url"].asString();
				res = loader.handleRequest(req);//load request into response object
				json.parse(res.data);//parse response data into json object so we can work with it
				cout << req.url << endl;
            }
            else if (SongBtn2[i].inside(x, y)) {
                cout << "Song Button " << i << " Pressed" << endl;
                req.url = json2["results"][i]["resource_url"].asString();
                res = loader.handleRequest(req);//load request into response object
                json.parse(res.data);//parse response data into json object so we can work with it
                cout << req.url << endl;
            }
            else if (SongBtn3[i].inside(x, y)) {
				cout << "Song Button " << i << " Pressed" << endl;
				req.url = json3["results"][i]["resource_url"].asString();
				res = loader.handleRequest(req);//load request into response object
				json.parse(res.data);//parse response data into json object so we can work with it
				cout << req.url << endl;
			}
            imageURL.clear();
            imageURL.push_back(json["images"][0]["uri"].asString());
            artistImage[0].load(imageURL[0]);
            addToLibraryBtn.set(40, 1060, 994, 60);
            viewOnDiscogsBtn.set(40, 1130, 994, 60);
            MachineState = "View Song";
        }
    }
    else if (MachineState == "Search Query") { //if on search query page
        for (int i = 0; i < 7; ++i) {
            if (ViewMoreBtn[i].inside(x, y)) { //if view more button for result i is pressed
                cout << "View More Button Pressed: " << i << endl;
                req.url = json["results"][i]["resource_url"].asString();
                cout << req.url << endl;
                res = loader.handleRequest(req);//load request into response object
                json.parse(res.data);//parse response data into json object so we can work with it
                imageURL.clear();
                imageURL.push_back(json["images"][0]["uri"].asString());
                cout << "URL: " << imageURL[0] << endl;
                artistImage[0].load(imageURL[0]);
                addToLibraryBtn.set(40, 1060, 994, 60);
                viewOnDiscogsBtn.set(40, 1130, 994, 60);
                MachineState = "View Song";
            }
        }
    }
    else if (MachineState == "View Song") {
        if (addToLibraryBtn.inside(x, y)) {
            cout << "Add to Library Button Pressed" << endl;
            saveToLibrary(); // Save song to Libary
        }
        else if (viewOnDiscogsBtn.inside(x, y)) {
            cout << "View on Discogs Button Pressed" << endl;
            ofLaunchBrowser(json["uri"].asString());
        }
    }
    else if (MachineState == "Menu Page") {
        if (MenuBtn.inside(x, y)) {
            // Make the menu go back to the previous page [NEED TO IMPLEMENT]
        }
        else if (MenuHomeBtn.inside(x, y)) {
			cout << "Home Button Pressed" << endl;
            ofBackground(248, 248, 255);
            loadHomePage();
			MachineState = "Home Page";
		}
        else if (MenuLibaryBtn.inside(x, y)) {
			cout << "Library Button Pressed" << endl;
            ofBackground(248, 248, 255);
            loadLibrary();
            MachineState = "Library Page";
		}
        else if (MenuGenresBtn.inside(x, y)) {
			cout << "Genres Button Pressed" << endl;
            ofBackground(248, 248, 255);
            for (int i = 0; i < 12; i++) {
                GenresBtn[i].set(35, 255 + i * 70, 1005, 65);
            }
            MachineState = "Genres Page";
		}
        else if (MenuSettingsBtn.inside(x, y)) {
			cout << "Settings Button Pressed" << endl;
            ofBackground(248, 248, 255);
            MachineState = "Settings Page";
		}
        else if (MenuAboutBtn.inside(x, y)) {
			cout << "About Button Pressed" << endl;
            ofBackground(248, 248, 255);
            MachineState = "About Page";
		}
        else if (MenuLogoutBtn.inside(x, y)) {
			cout << "Logout Button Pressed" << endl;
            ofBackground(248, 248, 255);
            MachineState = "First Time Launch";
		}
	}
    else if (MachineState == "Genres Page") {
        for (int i = 0; i < 13; i++) {
            if (GenresBtn[i].inside(x, y)) {
				cout << "Genres Button " << GenresName[i] << " Pressed" << endl;
                req.url = "https://api.discogs.com/database/search?genre=" + GenresName[i] + "&page=1&per_page=7";
                res = loader.handleRequest(req);//load request into response object
                json.parse(res.data);//parse response data into json object so we can work with it
                cout << req.url << endl;
                WordSearched = GenresName[i];
				MachineState = "Search Query";
			}
		}
    }


    if (MachineState != "First Time Launch") {
        if (MenuBtn.inside(x, y)) {
            cout << "Menu Button Pressed" << endl;
            MachineState = "Menu Page";
        }
        else if (HomeBtn.inside(x, y)) {
            cout << "Home Button Pressed" << endl;
            ofBackground(248, 248, 255);
            if (MachineState != "Home Page") {
                loadHomePage();
                MachineState = "Home Page";
            }
        }
        if (TextBox.inside(x, y) && TextInput == false) { //if text box is pressed and text input is not active
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

bool ofApp::validKey(int key) { //checks if key is valid for search (i.e. not a modifier key)
    if (key == OF_KEY_ALT || key == OF_KEY_CONTROL || key == OF_KEY_SHIFT || key == OF_KEY_COMMAND) {
		return false;
	}
    else {
		return true;
	}
}

void ofApp::loadHomePage() {

    // First Section Data
    req.url = "https://api.discogs.com/database/search?type=release&sort=hot&page=1&per_page=5";
    res = loader.handleRequest(req);//load request into response object
    json.parse(res.data);//parse response data into json object so we can work with it
    cout << req.url << endl;

    // Second Section Data
    // get random value from genres array
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, GenresName.size()+1);
    string genre = GenresName[dis(gen)];
    req.url = "https://api.discogs.com/database/search?genre=" + genre + "&page=1&per_page=5";
    res = loader.handleRequest(req);//load request into response object
    json2.parse(res.data);//parse response data into json object so we can work with it
    cout << req.url << endl;

    // Third Section Data
    // get random value from genres array
    std::string genre2;
    do {
        std::random_device rd2;
        std::mt19937 gen2(rd2());
        std::uniform_int_distribution<> dis2(0, GenresName.size()+1);
        genre2 = GenresName[dis2(gen2)];
    } while (genre2 == genre);  // Ensure the second genre is different from the first one
    req.url = "https://api.discogs.com/database/search?genre=" + genre2 + "&page=1&per_page=5";
    res = loader.handleRequest(req);
    json3.parse(res.data);
    cout << req.url << endl;

    for (int i = 0; i < json["results"].size(); ++i) {
        string url = json["results"][i]["thumb"].asString();
        imageURL1.push_back(url);
        cout << "URL[" << i << "]: " << url << endl;
        HomeartistImage1[i].load(imageURL1[i]);
    }

    for (int i = 0; i < json2["results"].size(); ++i) {
		string url = json2["results"][i]["thumb"].asString();
		imageURL2.push_back(url);
		cout << "URL[" << i << "]: " << url << endl;
		HomeartistImage2[i].load(imageURL2[i]);
	}

    for (int i = 0; i < json3["results"].size(); ++i) {
		string url = json3["results"][i]["thumb"].asString();
		imageURL3.push_back(url);
		cout << "URL[" << i << "]: " << url << endl;
		HomeartistImage3[i].load(imageURL3[i]);
	}
}


// Add a method to save the song to the library
void ofApp::saveToLibrary() {
    // Load the library JSON file
    ofJson library;
    std::ifstream libraryFile("data/library.json");
    if (libraryFile.is_open()) {
        libraryFile >> library;
        libraryFile.close();
    }

    // Get the next valid number
    int nextNumber = 0;
    if (!library.empty()) {
        nextNumber = library["results"].size();
    }

    // Create a JSON object to store the song information
    ofJson songInfo;
    songInfo["title"] = json["title"].asString();
    songInfo["release_date"] = json["released"].asString();

    // Create a vector of strings to store the genres and styles
    vector<string> genres;
    vector<string> styles;

    // Iterate through the JSON array and store the values in the vectors
    for (int i = 0; i < json["genres"].size(); ++i) {
        genres.push_back(json["genres"][i].asString());
    }

    for (int i = 0; i < json["styles"].size(); ++i) {
        styles.push_back(json["styles"][i].asString());
    }

    songInfo["genres"] = genres;
    songInfo["styles"] = styles;

    songInfo["image_url"] = json["images"][0]["uri"].asString();
    songInfo["discogs_url"] = json["uri"].asString();

    // Append the song information to the library JSON file
    library["results"][std::to_string(nextNumber)] = songInfo;

    std::ofstream libraryFileOut("data/library.json");
    if (libraryFileOut.is_open()) {
        libraryFileOut << library.dump(4) << std::endl;
        libraryFileOut.close();
        cout << "Song added to library" << endl;
    }
    else {
        cout << "Failed to open library file for writing" << endl;
    }
}

void ofApp::loadLibrary() {
    // Load the library JSON file
    std::ifstream libraryFile("data/library.json");
    ofJson library;
    libraryFile >> library;
    libraryFile.close();

    // Iterate through the library and print out the song information
    for (auto& song : library["results"]) {
        cout << "-----------------------------------" << endl;
		cout << "Title: " << song["title"] << endl;
		cout << "Release Date: " << song["release_date"] << endl;
		cout << "Genres: ";
        for (auto& genre : song["genres"]) {
			cout << genre << " ";
		}
		cout << endl;
		cout << "Styles: ";
        for (auto& style : song["styles"]) {
			cout << style << " ";
		}
		cout << endl;
		cout << "Image URL: " << song["image_url"] << endl;
		cout << "Discogs URL: " << song["discogs_url"] << endl;
        cout << "-----------------------------------" << endl;

	}
    cout << "Library loaded" << endl;
}