# S2. Data Driven App

For this assignment you are tasked with developing an application that makes use of data retrieved from an API. Your application should demonstrate the use functions, and pass arguments between these as appropriate. Where possible, the application should also implement object oriented programming techniques. 

The final application should be delivered via a functioning interactive GUI built using openFrameworks. This GUI should allow the user to interact via mouse and/or keyboard input.

For the assessment you are required to use one of the APIs listed below:

* [The Movie DB:](https://developer.themoviedb.org/)
* [Discogs:](https://www.discogs.com/developers)
* [Rest Countries:](https://restcountries.com/)
* [Currency API:](https://freecurrencyapi.com/)
* [Open Trivia:](https://opentdb.com/)
* [Pokemon API:](https://pokeapi.co/)
* [Harry Potter API:](https://potterdb.com/)

How you use your chosen API and the functionality you provide within your application is up to you. Making creative use of the API and/or providing the user with a range of options to query the API will likely afford higher marks. You should explore the documentation for each API to see what is possible in order to help select the API you wish to work with. 

As noted above the application should be built using openFrameworks and make use of the ofxJSON addon. Compatible versions of openframeworks for the assessment can be downloaded from the links below:

[openFrameworks - Visual Studio](https://bathspaonline-my.sharepoint.com/:u:/g/personal/j_hobbs_bathspa_ac_uk/Eb_CgJwMxxBHrDeLSdH3lYABtHsKVv7aj_3S3QRjbWR2Ow?e=XPeqiQ)

[openFrameworks - Xcode](https://bathspaonline-my.sharepoint.com/:u:/g/personal/j_hobbs_bathspa_ac_uk/EQMwlNADTI1Kgpt8YzOU7XgB1kPrgJryF4fSa79k1VEaXw?e=KgSWuZ)

&nbsp;

**Deadline:** 31 January 2024, 11:59am

*Please refer to Minerva for the full brief including marking criteria...*

&nbsp;
&nbsp;

## Creating the project

To create the project:

* Open the project generator
* Using the import option navigate to and select this folder (S2-Data-Driven-App) 
* Include the ```ofxJson``` addon in the addons box.
* Click ```Update```
* Click ```open in IDE``` and run the project (if you get a grey window the project has successfully generated)

&nbsp;
&nbsp;

## Starter Code

Below you will find starter code for each API listed on the brief. This starter code provides a basic example of how to call the API and retrieve data. To use the starter code simply copy/paste the code into the respective ofApp.h and ofApp.cpp files of your project. 

If you have any issues creating the initial project you should contact your tutor in a timely manner.

Jump to:
* [The Movie DB](#the-movie-db)
* [Discogs](#discogs)
* [Rest Countries](#rest-countries)
* [Currency API](#currency-api)
* [Open Trivia API](#open-trivia-api)
* [Pokemon API](#pokemon-api)
* [Harry Potter API](#harry-potter-api)

&nbsp;
&nbsp;

### The Movie DB

* API requires a key can be accessed by signing up at: https://www.themoviedb.org/signup
* Once you have signed up you will need to create an application, you can input test details for this e.g. http://example.com for the app url and "test application" for the description
* API documentation can be found at: https://developer.themoviedb.org/reference/intro/getting-started
* To display images the starting path is: https://image.tmdb.org/t/p/original/

**ofApp.h**
```C++
#pragma once

#include "ofMain.h"
#include "ofxJSON.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		
        ofxJSONElement json;//stores data from API
		
};
```

&nbsp;
&nbsp;

**ofApp.cpp**

```C++
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    /*
     You will need an api key. This can be accessed by signing up at: https://www.themoviedb.org/signup
     Once you have signed up you will need to create an application, you can input test details for this e.g. http://example.com for the app url and "test application" for the description
     API documentation can be found at: https://developer.themoviedb.org/reference/intro/getting-started
     To display images the starting path is: https://image.tmdb.org/t/p/original/
    */
    json.open("https://api.themoviedb.org/3/movie/550?api_key=YOURKEY");//returns Fight Club
    cout << json.getRawString() << endl;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//-----------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}
```

&nbsp;
&nbsp;

### Discogs

* API requires sign up here: https://accounts.discogs.com/login
* Once signed in you will need to create an app: https://www.discogs.com/settings/developers
* After creating an app you can generate a personal access token from this page: https://www.discogs.com/settings/developers

**ofApp.h**
```C++
#pragma once

#include "ofMain.h"
#include "ofxJSON.h"
#include <vector>

class ofApp : public ofBaseApp{

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
```

&nbsp;
&nbsp;

**ofApp.cpp**

```C++
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    /*
    API requires sign up here: https://accounts.discogs.com/login
    Once signed in you will need to create an app: https://www.discogs.com/settings/developers
    After creating an app you can generate a personal access token from this page: https://www.discogs.com/settings/developers
    As the API requires setting of headers to the steps to retrieve data are slightly different to the other APIs
    */
    req.headers["User-Agent"] = "YOURSTUDENTNUMBER_MusicAPI_BSU/v1 (YOUREMAIL@bathspa.ac.uk)";//sets user agent header - used to indentify your app
    req.method = ofHttpRequest::GET;//sets request method to get (e.g. retrieve data)
    req.url = "https://api.discogs.com/artists/125246?token=YOURACCESSTOKEN"; //specify the API call - this will retrieve Nirvana
    
    res = loader.handleRequest(req);//load request into response object
    json.parse(res.data);//parse response data into json object so we can work with it
  
    cout << json.getRawString() << endl;//output raw data
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//-----------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}
```

&nbsp;
&nbsp;

### Rest Countries

API documentation can be found at: https://restcountries.com/

**ofApp.h**
```C++
#pragma once

#include "ofMain.h"
#include "ofxJSON.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		
        ofxJSONElement json;//stores data from API
		
};
```

&nbsp;
&nbsp;

**ofApp.cpp**

```C++
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    /*
     API documentation can be found at: https://restcountries.com/
     */
    json.open("https://restcountries.com/v3.1/name/United%20Kingdom");//returns data on United Kingdom
    cout << json.getRawString() << endl;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//-----------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}
```

&nbsp;
&nbsp;

### Currency API

* You need an key to use this API, access here: https://freecurrencyapi.com/
* API documentation can be found at: https://freecurrencyapi.com/docs

**ofApp.h**
```C++
#pragma once

#include "ofMain.h"
#include "ofxJSON.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		
        ofxJSONElement json;//stores data from API
		
};
```

&nbsp;
&nbsp;

**ofApp.cpp**

```C++
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    /*
     You need an Key to use this API. Sign Up for one here: https://freecurrencyapi.com/
     API documentation can be found at: https://freecurrencyapi.com/docs
    */
    json.open("https://api.freecurrencyapi.com/v1/latest?apikey=YOUR_KEY_HERE&currencies=GBP");//returns Dollar to Pound Conversion
    cout << json.getRawString() << endl;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//-----------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}
```

&nbsp;
&nbsp;

### Open Trivia API

API documentation can be found at: https://opentdb.com/api_config.php

**ofApp.h**
```C++
#pragma once

#include "ofMain.h"
#include "ofxJSON.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		
        ofxJSONElement json;//stores data from API
		
};
```

&nbsp;
&nbsp;

**ofApp.cpp**

```C++
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    /*
     API documentation can be found at: https://opentdb.com/api_config.php
    */
    json.open("https://opentdb.com/api.php?amount=1&category=21&difficulty=easy&type=boolean");//returns true of false question from sports category
    cout << json.getRawString() << endl;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//-----------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}
```

&nbsp;
&nbsp;

### Pokemon API

API documentation can be found at: https://pokeapi.co/docs/v2

**ofApp.h**
```C++
#pragma once

#include "ofMain.h"
#include "ofxJSON.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		
        ofxJSONElement json;//stores data from API
		
};
```

&nbsp;
&nbsp;

**ofApp.cpp**

```C++
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    /*
     API documentation can be found at: https://pokeapi.co/docs/v2
    */
    json.open("https://pokeapi.co/api/v2/berry/cheri");//returns data on the Cheri Berry
    cout << json.getRawString() << endl;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//-----------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}
```

&nbsp;
&nbsp;

### Harry Potter API

API documentation can be found at: https://docs.potterdb.com/

**ofApp.h**
```C++
#pragma once

#include "ofMain.h"
#include "ofxJSON.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		
        ofxJSONElement json;//stores data from API
		
};
```

&nbsp;
&nbsp;

**ofApp.cpp**

```C++
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    /*
     API documentation can be found at: https://docs.potterdb.com/
    */
    json.open("https://api.potterdb.com/v1/characters/harry-potter");//returns Harry Potter
    cout << json.getRawString() << endl;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//-----------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}
```

&nbsp;
&nbsp;
