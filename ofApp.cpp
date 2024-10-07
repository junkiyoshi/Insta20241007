#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openframeworks");

	ofBackground(239);
	ofSetLineWidth(3);
	ofNoFill();
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateY(ofGetFrameNum() * 0.72);

	ofColor color;
	for (int i = 0; i < 20; i++) {

		auto noise_seed = glm::vec3(ofRandom(1000), ofRandom(1000), ofRandom(1000));
		color.setHsb(ofMap(i, 0, 20, 0, 255), 255, 200);

		for (int k = 0; k < 50; k++) {

			auto location = glm::vec3(
				ofMap(ofNoise(noise_seed.x, (ofGetFrameNum() + k) * 0.005), 0, 1, -200, 200),
				ofMap(ofNoise(noise_seed.y, (ofGetFrameNum() + k) * 0.005), 0, 1, -200, 200),
				ofMap(ofNoise(noise_seed.z, (ofGetFrameNum() + k) * 0.005), 0, 1, -200, 200));
			auto next = glm::vec3(
				ofMap(ofNoise(noise_seed.x, (ofGetFrameNum() + k + 1) * 0.005), 0, 1, -200, 200),
				ofMap(ofNoise(noise_seed.y, (ofGetFrameNum() + k + 1) * 0.005), 0, 1, -200, 200),
				ofMap(ofNoise(noise_seed.z, (ofGetFrameNum() + k + 1) * 0.005), 0, 1, -200, 200));

			ofSetColor(color, ofMap(k, 0, 50, 0, 255));
			ofDrawLine(location, next);
		}
	}

	ofSetColor(0);
	ofDrawBox(350);

	this->cam.end();

	/*
	int start = 50;
	if (ofGetFrameNum() > start) {

		ostringstream os;
		os << setw(4) << setfill('0') << ofGetFrameNum() - start;
		ofImage image;
		image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		image.saveImage("image/cap/img_" + os.str() + ".jpg");
		if (ofGetFrameNum() - start >= 25 * 20) {

			std::exit(1);
		}
	}
	*/
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}