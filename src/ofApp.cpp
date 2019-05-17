// CS 134 Lunar Lander Project
// Brandon Archbold and Abraham Kong

#include "ofApp.h"
#include "Util.h"



//--------------------------------------------------------------
// setup scene, lighting, state and load geometry
//
void ofApp::setup(){

	bWireframe = false;
	bDisplayPoints = false;
	bAltKeyDown = false;
	bCtrlKeyDown = false;
	bRoverLoaded = false;
	bTerrainSelected = true;
	leaf = true;
	isPaused = false;
	bTargetShip = true;
	hideControls = false;
	bScored = false;
//	ofSetWindowShape(1024, 768);
	easyCam.setDistance(10);
	easyCam.setNearClip(.1);
	easyCam.setFov(65.5);   // approx equivalent to 28mm in 35mm format
	ofSetVerticalSync(true);
	easyCam.disableMouseInput();
	ofEnableSmoothing();
    ofEnableDepthTest();
	sphere.setRadius(10);

	altitude = -1;
	// Code by Brandon Archbold
	score = 0;
	scoreString = "Score: ";

	landingPad1 = glm::vec3(226.868, -70.7067, 145.931);
	landingPad2 = glm::vec3(-233, 241.588, -1165.64);
	landingPad3 = glm::vec3(1306.03, 247.593, 232.955);

	if (!backgroundImage.load("images/sky-star-dark-constellation-color-space-blue-galaxy-nebula-outer-space-background-astronomy-stars-universe-photoshop-fantasy-pretty-astronomical-object-610854.jpg")) { // image from: https://pxhere.com/en/photo/610854
		bBackgroundLoaded = false;
		cout << "Backround image failed to load\n";
	}
	else
		bBackgroundLoaded = true;

	ship = new Particle();

	// set up forces for ship
	pSys.add(*ship);
	pSys.particles[0].position = ofVec3f(0, 500, 0);
	pSys.particles[0].velocity = ofVec3f(0, 0, 0);
	pSys.particles[0].lifespan = -1;
	pSys.particles[0].mass = 1;

    ofVec3f temp = ofVec3f(0, 0, 0);
	turbForce = new TurbulenceForce(ofVec3f(-20, -20, -20), ofVec3f(20, 20, 20));
	gravityForce = new GravityForce(ofVec3f(0, -10, 0));
	thrustForce = new ThrustForce(temp, 200.0);

	pSys.addForce(turbForce);
	pSys.addForce(gravityForce);
	pSys.addForce(thrustForce);
	pSys.addForce(&impulseForce);
	// Code by Brandon Archbold
    // set up the cameras
	glm::vec3 shipPos = pSys.particles[0].position;
    currCam = &followCam;
    followCam.setPosition(glm::vec3(shipPos.x, shipPos.y, shipPos.z + 90));
    followCam.setFov(90);
    followCam.setNearClip(.1);
	leftSideCam.setPosition(glm::vec3(shipPos.x - 20, shipPos.y, shipPos.z));
	leftSideCam.setFov(90);
	leftSideCam.lookAt(glm::vec3(shipPos.x - 30, shipPos.y, shipPos.z));
	rightSideCam.setPosition(glm::vec3(shipPos.x + 20, shipPos.y, shipPos.z));
	rightSideCam.setFov(90);
	rightSideCam.lookAt(glm::vec3(shipPos.x + 30, shipPos.y, shipPos.z));
	frontCam.setPosition(glm::vec3(shipPos.x, shipPos.y, shipPos.z + 90));
	frontCam.setFov(90);
	frontCam.lookAt(glm::vec3(shipPos.x, shipPos.y, shipPos.z));
	bottomCam.setPosition(glm::vec3(shipPos.x, shipPos.y - 30, shipPos.z));
	bottomCam.setFov(90);
	bottomCam.lookAt(glm::vec3(shipPos.x, shipPos.y - 40, shipPos.z));
    surfaceCam.lookAt(glm::vec3(0, 0, 0));
    surfaceCam.setFov(90);
	surfaceCam.lookAt(glm::vec3(shipPos.x, shipPos.y, shipPos.z));
    trackingCam.setPosition(glm::vec3(500, 500, 500));
    trackingCam.setFov(90);
    trackingCam.lookAt(glm::vec3(shipPos.x, shipPos.y, shipPos.z));

	gui.setup();
	gui.add(numLevels.setup("levels", 10, 1, 30));

    // setup rocketBottomLight
    // Code by Abraham Kong
    ofEnableLighting();
    
    //initializing Area Light
    areaLight.setup();
    areaLight.enable();
    areaLight.setAreaLight(1, 1);
    areaLight.setPosition(0, 500, 0);
    directionalLight.setup();
    directionalLight.enable();
    directionalLight.setSpotlight();
    directionalLight.rotate(-10, ofVec3f(1, 0, 0));
    directionalLight.rotate(-90, ofVec3f(1, 1, 1));
    directionalLight.setPosition(0, 0, 1000);
    
    //initializing Spot Light
    rocketBottomLight.setup();
    rocketBottomLight.enable();
    rocketBottomLight.setSpotlight();
//    rocketBottomLight.setScale(.05);
    rocketBottomLight.setSpotlightCutOff(15);
    /*rocketBottomLight.rotate(-10, ofVec3f(1, 0, 0));
    rocketBottomLight.rotate(-90, ofVec3f(1, 1, 1));*/
    rocketBottomLight.setPosition(shipPos.x, shipPos.y - 30, shipPos.z);
	rocketBottomLight.lookAt(glm::vec3(shipPos.x, shipPos.y - 40, shipPos.z));
    
    // initializing the wording for current action
    currentAction = "Welcome to Rocket Lander!";
    // Code by Abraham Kong
    controlsString = "\n\nControls:\narrow keys - movement\nspace - up\nshift - down\nc - lock/unlock easyCam\nf - fullscreen\ns - toggleEZcam target\nt - EZcam to ship\nmouse1 - select point\np - pause\nF1 - main cam\nF2 - easyCam\nF3 - leftCam\nF4 - rightCam\nF5 - frontCam\nF6 - bottomCam\nF7 - surfaceCam\nF8 - trackingCam\nh - hide this panel";
    // setup rudimentary lighting
	//
	initLightingAndMaterials();

	terrain.loadModel("geo/models/terrain.obj");
	terrain.setScaleNormalization(false);
	terrain.setRotation(1, 180, 0, 0, 1);

	if (rocket.loadModel("geo/models/rocket.obj"))
		bRoverLoaded = true;
	else {
		cout << "geo/models/rocket.obj file not found\n";
		ofExit();
	}
	rocket.setScaleNormalization(false);
	rocket.setRotation(1, 180, 0, 0, 1);
	ofDisableArbTex();
	
	// load particle image
	if (!ofLoadImage(particleTexture, "images/dot.png")) {
		cout << "Particle Texture File: images/dot.png not found" << endl;
		ofExit();
	}
	// Code by Brandon Archbold
	// load the shader
	//
#ifdef TARGET_OPENGLES
	shader.load("shaders_gles/shader");
#else
	shader.load("shaders/shader");
#endif
	// Code by Brandon Archbold
	exhastParticles.sys->addForce(new TurbulenceForce(ofVec3f(-200, -200, -200), ofVec3f(200, 200, 200)));
	exhastParticles.sys->addForce(new GravityForce(ofVec3f(0, -50, 0)));
	
	exhastParticles.setVelocity(ofVec3f(0, 0, 0));
	exhastParticles.setEmitterType(DirectionalEmitter);
	exhastParticles.setGroupSize(50);
	exhastParticles.setLifespan(1);
	exhastParticles.setPosition(ofVec3f(0, 0, 0));
	exhastParticles.setVelocity(ofVec3f(0, -50, 0));
	exhastParticles.setRate(50);
    

	if (!thrustSound.load("sounds/347575__djt4nn3r__thrusters-loopamplified.wav"))			// sound from: https://freesound.org/people/DJT4NN3R/sounds/347575/
		ofExit();
	thrustSound.setLoop(true);
	octree.create(terrain.getMesh("pPlane1"), (int) numLevels);
	// Code by Brandon Archbold
}

//--------------------------------------------------------------
// incrementally update scene (animation)
//
void ofApp::update() {
	if (!isPaused) {
		// update cameras
		// Code by Brandon Archbold, Abraham Kong

		glm::vec3 shipPos = pSys.particles[0].position;
		followCam.setPosition(glm::vec3(shipPos.x, shipPos.y, shipPos.z + 90));
		leftSideCam.setPosition(glm::vec3(shipPos.x - 20, shipPos.y, shipPos.z));
		leftSideCam.lookAt(glm::vec3(shipPos.x - 30, shipPos.y, shipPos.z));
		rightSideCam.setPosition(glm::vec3(shipPos.x + 20, shipPos.y, shipPos.z));
		rightSideCam.lookAt(glm::vec3(shipPos.x + 30, shipPos.y, shipPos.z));
		frontCam.setPosition(glm::vec3(shipPos.x, shipPos.y, shipPos.z + 90));
		frontCam.lookAt(glm::vec3(shipPos.x, shipPos.y, shipPos.z));
		bottomCam.setPosition(glm::vec3(shipPos.x, shipPos.y - 30, shipPos.z));
		bottomCam.lookAt(glm::vec3(shipPos.x, shipPos.y - 40, shipPos.z));
		surfaceCam.lookAt(glm::vec3(0, 0, 0));
		surfaceCam.lookAt(glm::vec3(shipPos.x, shipPos.y, shipPos.z));
		trackingCam.setPosition(glm::vec3(500, 500, 500));
		trackingCam.lookAt(glm::vec3(shipPos.x, shipPos.y, shipPos.z));
		// timer to stop multiple scoring 10 second between scores
		if (bScored)
			if ((ofGetSystemTimeMillis() - timeScored) > (uint64_t)10000) 
				bScored = false;
    
		exhastParticles.setPosition(ofVec3f(pSys.particles[0].position.x, pSys.particles[0].position.y - 30, pSys.particles[0].position.z));
		exhastParticles.update();
		currLevel = (int)numLevels;
		pSys.update();
		altitudeDetection();
		collisionDetection();
		rocket.setPosition(pSys.particles[0].position.x, pSys.particles[0].position.y, pSys.particles[0].position.z);
        // Code by Brandon Archbold
        // Code by Abraham Kong
        rocketBottomLight.setPosition(glm::vec3(shipPos.x, shipPos.y, shipPos.z));
        // Code by Abraham Kong
        
	}
}
//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(ofColor::black);
	if (bBackgroundLoaded) {
		ofPushMatrix();
		ofDisableDepthTest();
		ofSetColor(50, 50, 50);
		ofScale(2, 2);
		backgroundImage.draw(-200, -100);
		ofEnableDepthTest();
		ofPopMatrix();
	}
	ofSetColor(ofColor::white);
	loadVbo();
	currCam->begin();
	// draw cams for positioning
	/*followCam.draw();
	leftSideCam.draw();
	rightSideCam.draw();
	frontCam.draw();
	bottomCam.draw();
	surfaceCam.draw();
	trackingCam.draw();*/
	ofDrawSphere(landingPad1, 5);
	ofDrawSphere(landingPad2, 5);
	ofDrawSphere(landingPad3, 5);

	ofPushMatrix();
	if (bWireframe) {                    // wireframe mode  (include axis)
		ofDisableLighting();
		ofSetColor(ofColor::slateGray);
		terrain.drawWireframe();
		ofSetColor(ofColor::white);
        /*if(leaf)
            octree.drawLeafNodes(octree.root);
        else
            octree.draw(currLevel, 0);*/
		if (bRoverLoaded) {
			rocket.drawWireframe();
			if (!bTerrainSelected) drawAxis(rocket.getPosition());
		}
		if (bTerrainSelected) drawAxis(ofVec3f(0, 0, 0));
	}
	else {
		ofEnableLighting();              // shaded mode
		terrain.drawFaces();
		/*if (leaf)
			octree.drawLeafNodes(octree.root);
		else
			octree.draw(currLevel, 0);*/
		if (bRoverLoaded) {
			rocket.drawFaces();
			if (!bTerrainSelected) drawAxis(rocket.getPosition());
		}
		if (bTerrainSelected) drawAxis(ofVec3f(0, 0, 0));
	}


	if (bDisplayPoints) {                // display points as an option    
		glPointSize(3);
		ofSetColor(ofColor::green);
		terrain.drawVertices();
	}

	// highlight selected point (draw sphere around selected point)
	//
	if (bPointSelected) {
		ofSetColor(ofColor::blue);
		ofDrawSphere(selectedPoint, 1.0);
	}
	
	// Code by Brandon Archbold adapted from shader example in class
	ofNoFill();
	ofSetColor(ofColor::white);
	
	ofPopMatrix();
	currCam->end();
    

	glDepthMask(GL_FALSE);

	ofSetColor(255, 100, 90);

	// this makes everything look glowy :)
	//
	ofEnableBlendMode(OF_BLENDMODE_ADD);
	ofEnablePointSprites();


	// begin drawing in the camera
	//
	shader.begin();
	currCam->begin();

	// draw particle emitter here..
	//
//	emitter.draw();
    areaLight.draw();
    directionalLight.draw();
    rocketBottomLight.draw();
	particleTexture.bind();
	vbo.draw(GL_POINTS, 0, (int)exhastParticles.sys->particles.size());
	particleTexture.unbind();

	//  end drawing in the camera
	// 
	currCam->end();
	shader.end();

	ofDisablePointSprites();
	ofDisableBlendMode();
	ofEnableAlphaBlending();

	// set back the depth mask
	//
	glDepthMask(GL_TRUE);
	// Code by Brandon Archbold adapted from shader example in class
	// draw screen data
	//
	string str;
	str += "FPS: " + std::to_string(ofGetFrameRate());
	ofSetColor(ofColor::white);
	string str4 = scoreString + std::to_string(score);
	ofDrawBitmapString(str4, ofGetWindowWidth() - 170, 30);
	ofDrawBitmapString(str, ofGetWindowWidth() - 170, 15);
	string str2 = "Altitude: " + std::to_string(altitude);
	ofDrawBitmapString(str2, 0, 15);
    string str3 = "Current Action: " + currentAction;
    ofDrawBitmapString(str3, 0, 30);
	if(!hideControls)
		ofDrawBitmapString(controlsString, 0, 45);
}

// 

// Draw an XYZ axis in RGB at world (0,0,0) for reference.
//
void ofApp::drawAxis(ofVec3f location) {

	ofPushMatrix();
	ofTranslate(location);

	ofSetLineWidth(1.0);

	// X Axis
	ofSetColor(ofColor(255, 0, 0));
	ofDrawLine(ofPoint(0, 0, 0), ofPoint(1, 0, 0));
	

	// Y Axis
	ofSetColor(ofColor(0, 255, 0));
	ofDrawLine(ofPoint(0, 0, 0), ofPoint(0, 1, 0));

	// Z Axis
	ofSetColor(ofColor(0, 0, 255));
	ofDrawLine(ofPoint(0, 0, 0), ofPoint(0, 0, 1));

	ofPopMatrix();
}


void ofApp::keyPressed(int key) {

	switch (key) {
    // code from Abraham Kong, and part from Prof. Kevin Smith's example code
	case 'C':
	case 'c':
		if (easyCam.getMouseInputEnabled()) easyCam.disableMouseInput();
		else easyCam.enableMouseInput();
        currentAction = "Enabled/Disabled Mouse Input";
		break;
	case 'F':
	case 'f':
        ofToggleFullscreen();
        currentAction = "Enabled/Disabled Full Screen";
        break;
	case 'H':
	case 'h':
		hideControls = !hideControls;
		currentAction = "hide/unhide controls";
		break;
	case 'r':
		easyCam.reset();
        currentAction = "Reset Easy Cam";
		break;
	case 's':
		bTargetShip = !bTargetShip;
        currentAction = "Enable/Disable Target Spacecraft";
		break;
	case 'l':
		leaf = !leaf;
		break;
	case 't':
		setCameraTarget();
        currentAction = "Set Camera Target";
		break;
	case 'u':
		break;
	case 'v':
		togglePointsDisplay();
        currentAction = "Vector Mode";
		break;
	case 'p': isPaused = !isPaused;
        currentAction = "Pause/Unpause";
		break;
	case 'w':
		toggleWireframeMode();
        currentAction = "Wireframe Mode";
		break;
	case OF_KEY_ALT:
		easyCam.enableMouseInput();
		bAltKeyDown = true;
        currentAction = "Enable Mouse Input for Easy Cam";
		break;
	case OF_KEY_CONTROL:
		bCtrlKeyDown = true;
        currentAction = "ctrl key pressed";
		break;
		// Code by Brandon Archbold
	case OF_KEY_SHIFT: thrustForce->setDirection(ofVec3f(thrustForce->getDirection().x, -1, thrustForce->getDirection().z));
        currentAction = "move down";
		break;
	case ' ': thrustForce->setDirection(ofVec3f(thrustForce->getDirection().x, 1, thrustForce->getDirection().z));
		exhastParticles.start();
		if(!thrustSound.isPlaying())
			thrustSound.play();
        currentAction = "move up";
		break;
	case OF_KEY_UP: thrustForce->setDirection(ofVec3f(thrustForce->getDirection().x, thrustForce->getDirection().y, -1));
        currentAction = "move forward";
		break;
	case OF_KEY_DOWN: thrustForce->setDirection(ofVec3f(thrustForce->getDirection().x, thrustForce->getDirection().y, 1));
        currentAction = "move backward";
		break;
	case OF_KEY_LEFT: thrustForce->setDirection(ofVec3f(-1, thrustForce->getDirection().y, thrustForce->getDirection().z));
        currentAction = "move left";
		break;
	case OF_KEY_RIGHT: thrustForce->setDirection(ofVec3f(1, thrustForce->getDirection().y, thrustForce->getDirection().z));
        currentAction = "move right";
		break;
	case OF_KEY_F1: currCam = &followCam;
        currentAction = "Main Camera";
		break;
	case OF_KEY_F2: currCam = &easyCam;
        currentAction = "Easy Camera";
		break;
		// Code by Brandon Archbold
        //Code by Abraham Kong
    case OF_KEY_F3: currCam = &leftSideCam;
            currentAction = "left side cam";
        break;
    case OF_KEY_F4: currCam = &rightSideCam;
            currentAction = "right side cam";
        break;
    case OF_KEY_F5: currCam = &frontCam;
            currentAction = "front siide cam";
        break;
    case OF_KEY_F6: currCam = &bottomCam;
            currentAction = "bottom side cam";
        break;
    case OF_KEY_F7: currCam = &surfaceCam;
            currentAction = "surface tracking cam";
        break;
    case OF_KEY_F8: currCam = &trackingCam;
            currentAction = "tracking cam";
        break;
        //Code by Abraham Kong
	default:
		break;
	}
}

void ofApp::toggleWireframeMode() {
	bWireframe = !bWireframe;
}

void ofApp::toggleSelectTerrain() {
	bTerrainSelected = !bTerrainSelected;
}

void ofApp::togglePointsDisplay() {
	bDisplayPoints = !bDisplayPoints;
}

void ofApp::keyReleased(int key) {

	switch (key) {
	
	case OF_KEY_ALT:
		easyCam.disableMouseInput();
		bAltKeyDown = false;
		break;
	case OF_KEY_CONTROL:
		bCtrlKeyDown = false;
		break;
		// Code by Brandon Archbold
	case OF_KEY_SHIFT: thrustForce->setDirection(ofVec3f(thrustForce->getDirection().x, 0, thrustForce->getDirection().z));
		break;
	case ' ': thrustForce->setDirection(ofVec3f(thrustForce->getDirection().x, 0, thrustForce->getDirection().z));
		exhastParticles.stop();
		thrustSound.stop();
		break;
	case OF_KEY_UP: thrustForce->setDirection(ofVec3f(thrustForce->getDirection().x, thrustForce->getDirection().y, 0));
		break;
	case OF_KEY_DOWN: thrustForce->setDirection(ofVec3f(thrustForce->getDirection().x, thrustForce->getDirection().y, 0));
		break;
	case OF_KEY_LEFT: thrustForce->setDirection(ofVec3f(0, thrustForce->getDirection().y, thrustForce->getDirection().z));
		break;
	case OF_KEY_RIGHT: thrustForce->setDirection(ofVec3f(0, thrustForce->getDirection().y, thrustForce->getDirection().z));
		break;
		// Code by Brandon Archbold
	default:
		break;

	}
}



//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
}

// Code by Brandon Archbold
//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
    ofVec3f mouse(mouseX, mouseY);
	ofVec3f rayPoint = currCam->screenToWorld(mouse);
	ofVec3f rayDir = rayPoint - currCam->getPosition();
	rayDir.normalize();
	Ray ray = Ray(Vector3(rayPoint.x, rayPoint.y, rayPoint.z), Vector3(rayDir.x, rayDir.y, rayDir.z));
	TreeNode nodeRtn;
	if (octree.intersect(ray, octree.root, nodeRtn)) {
		Vector3 pos = nodeRtn.box.min();
		selectedPoint = ofVec3f(pos.x(), pos.y(), pos.z());
		bPointSelected = true;
		cout << selectedPoint << " selected\n";
	}
	else
		bPointSelected = false;
}
// Code by Brandon Archbold
void ofApp::altitudeDetection() {
	ofVec3f shipPos = pSys.particles[0].position;
    ofVec3f rayPoint = ofVec3f(shipPos.x, shipPos.y -1, shipPos.z);
    ofVec3f rayDir = rayPoint - ofVec3f(shipPos.x, shipPos.y, shipPos.z);
    rayDir.normalize();
    Ray ray = Ray(Vector3(rayPoint.x, rayPoint.y, rayPoint.z), Vector3(rayDir.x, rayDir.y, rayDir.z));
    TreeNode nodeRtn;
    if (octree.intersect(ray, octree.root, nodeRtn)) {
        if (nodeRtn.points.size() != 0) {
			Vector3 pos = nodeRtn.box.min();
			float y = pos.y();
			altitude = shipPos.y - 30 - y;
        }
    }
}
// Code by Brandon Archbold
void ofApp::collisionDetection() {
	//ofPoint center = rocket.getMesh("pCylinder2").getCentroid();
	//contactPt = ofVec3f(center.x, center.y - (rocket.getSceneMax().y - rocket.getSceneMin().y) / 2, center.z + rocket.getPosition().y);
	contactPt = pSys.particles[0].position - 30;
	ofVec3f vel = pSys.particles[0].velocity;
	if (vel.y > 0)
		return;

	TreeNode node;
	if (octree.intersect(contactPt, octree.root, node)) {
		bCollision = true;

		// impulse force
		ofVec3f norm = ofVec3f(0, 1, 0);
		ofVec3f f = (1 + 1.0) * ((-vel.dot(norm)) * norm);
		impulseForce.apply(ofGetFrameRate() * f);
		// score calculation
		calcScore(distanceBetween(contactPt, landingPad1), vel);
		calcScore(distanceBetween(contactPt, landingPad2), vel);
		calcScore(distanceBetween(contactPt, landingPad3), vel);
	}
}

// Code by Brandon Archbold
void ofApp::calcScore(float dist, ofVec3f vel) {
	if (bScored || vel.length() > 30) return;
	if (dist < 50) {
		score += 100;
		bScored = true;
		timeScored = ofGetSystemTimeMillis();
	}
	else if (dist <= 60) {
		score += 50;
		bScored = true;
		timeScored = ofGetSystemTimeMillis();
	}
	else if (dist <= 70) {
		score += 25;
		bScored = true;
		timeScored = ofGetSystemTimeMillis();
	}
	else if (dist <= 80){
		score += 5;
		bScored = true;
		timeScored = ofGetSystemTimeMillis();
	}
}

// Code by Brandon Archbold
float ofApp::distanceBetween(glm::vec3 p1, glm::vec3 p2){
	glm::vec3 difference = p2 - p1;
	return sqrt(difference.x * difference.x + difference.y * difference.y + difference.z * difference.z);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {


}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

// Set the camera to use the selected point as it's new target
//  
void ofApp::setCameraTarget() {
    //Code by Abraham Kong
	if (!bTargetShip && bPointSelected)
		easyCam.setPosition(glm::vec3(selectedPoint.x, selectedPoint.y, selectedPoint.z));
	else if (bTargetShip) {
        easyCam.setPosition(glm::vec3(pSys.particles[0].position.x, pSys.particles[0].position.y, pSys.particles[0].position.z));
    } else {
        easyCam.reset();
        easyCam.setDistance(180);
    }
}


//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}



//--------------------------------------------------------------
// setup basic ambient lighting in GL  (for now, enable just 1 light)
//
void ofApp::initLightingAndMaterials() {

	static float ambient[] =
	{ .5f, .5f, .5, 1.0f };
	static float diffuse[] =
	{ 1.0f, 1.0f, 1.0f, 1.0f };

	static float position[] =
	{5.0, 5.0, 5.0, 0.0 };

	static float lmodel_ambient[] =
	{ 1.0f, 1.0f, 1.0f, 1.0f };

	static float lmodel_twoside[] =
	{ GL_TRUE };


	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, position);

	glLightfv(GL_LIGHT1, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT1, GL_POSITION, position);


	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
	glLightModelfv(GL_LIGHT_MODEL_TWO_SIDE, lmodel_twoside);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
//	glEnable(GL_LIGHT1);
	glShadeModel(GL_SMOOTH);
} 

void ofApp::savePicture() {
	ofImage picture;
	picture.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
	picture.save("screenshot.png");
	cout << "picture saved" << endl;
}


void ofApp::dragEvent(ofDragInfo dragInfo) {

}

//bool ofApp::mouseIntersectPlane(ofVec3f planePoint, ofVec3f planeNorm, ofVec3f &point) {
//	glm::vec3 mouse(mouseX, mouseY, 0);
//	ofVec3f rayPoint = cam.screenToWorld(mouse);
//	ofVec3f rayDir = rayPoint - cam.getPosition();
//	rayDir.normalize();
//	return (rayIntersectPlane(rayPoint, rayDir, planePoint, planeNorm, point));
//}

// load vertex buffer in preparation for rendering
//
void ofApp::loadVbo() {
	if (exhastParticles.sys->particles.size() < 1) return;

	vector<ofVec3f> sizes;
	vector<ofVec3f> points;
	for (int i = 0; i < exhastParticles.sys->particles.size(); i++) {
		points.push_back(exhastParticles.sys->particles[i].position);
		sizes.push_back(ofVec3f(5));
	}
	// upload the data to the vbo
	//
	int total = (int)points.size();
	vbo.clear();
	vbo.setVertexData(&points[0], total, GL_STATIC_DRAW);
	vbo.setNormalData(&sizes[0], total, GL_STATIC_DRAW);
}
