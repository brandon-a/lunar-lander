// CS 134 Lunar Lander Project
// Brandon Archbold and Abraham Kong

#include "ofApp.h"
#include "Util.h"



//--------------------------------------------------------------
// setup scene, lighting, state and load geometry
//
void ofApp::setup(){
	// boolean variable setup
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
	easyCam.setDistance(10);
	easyCam.setNearClip(.1);
	easyCam.setFov(65.5);   // approx equivalent to 28mm in 35mm format
	ofSetVerticalSync(true);
	easyCam.disableMouseInput();
	ofEnableSmoothing();
    ofEnableDepthTest();
	sphere.setRadius(10);

	// Code by Brandon Archbold
	altitude = -1;
	// setup the score display code
	score = 0;
	scoreString = "Score: ";
	// landing pad locations, land closer to the landing pads to score higher!
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

	// initialize the ship position, lifespan, and mass
	pSys.add(*ship);
	pSys.particles[0].position = ofVec3f(0, 500, 1000);
	pSys.particles[0].velocity = ofVec3f(0, 0, 0);
	pSys.particles[0].lifespan = -1;
	pSys.particles[0].mass = 1;

	// setup forces to act on the ship
    ofVec3f temp = ofVec3f(0, 0, 0);
	turbForce = new TurbulenceForce(ofVec3f(-20, -20, -20), ofVec3f(20, 20, 20));
	gravityForce = new GravityForce(ofVec3f(0, -10, 0));
	thrustForce = new ThrustForce(temp, 200.0);

	//add the forces to the ship
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
    //directionalLight.setSpotlight();
	directionalLight.setPointLight();
    directionalLight.setAmbientColor(ofFloatColor(0.5, 0.1, 1));
    directionalLight.setPosition(0, 2000, 2000);
	directionalLight.lookAt(glm::vec3(0, 1000, 1000));
    
    //initializing Spot Light
    rocketBottomLight.setup();
    rocketBottomLight.enable();
    rocketBottomLight.setSpotlight();
    rocketBottomLight.setSpotlightCutOff(15);
    rocketBottomLight.setPosition(shipPos.x, shipPos.y - 30, shipPos.z);
	rocketBottomLight.lookAt(glm::vec3(shipPos.x, shipPos.y - 40, shipPos.z));
    
    // initializing the wording for current action
    currentAction = "Welcome to Rocket Lander!";
    // Code by Abraham Kong
    
    
    // Code from Lightening Example and Code by Abraham Kong
    fillLight.setup();
    fillLight.enable();
    fillLight.setPointLight();
    fillLight.setScale(.05);
    fillLight.setSpotlightCutOff(15);
    fillLight.setAttenuation(2, .001, .001);
    fillLight.setAmbientColor(ofFloatColor(0.5, 0.1, 1));
    fillLight.setDiffuseColor(ofFloatColor(.3, 0, 1));
    fillLight.setSpecularColor(ofFloatColor(0, 0, 1));
    fillLight.rotate(-10, ofVec3f(1, 0, 0));
    fillLight.rotate(-90, ofVec3f(0, 1, 0));
    fillLight.setPosition(0, 1200, 500);
    fillLight.lookAt(glm::vec3(0, 900, 0));
    
    rimLight.setup();
    rimLight.enable();
    rimLight.setSpotlight();
    rimLight.setScale(.05);
    rimLight.setSpotlightCutOff(30);
    rimLight.setAttenuation(.2, .001, .001);
    rimLight.setAmbientColor(ofFloatColor(0.2, 0.1, 1));
    rimLight.setDiffuseColor(ofFloatColor(.3, 0, 1));
    rimLight.setSpecularColor(ofFloatColor(1, 1, 1));
    //rimLight.rotate(180, ofVec3f(0, 1, 0));
    rimLight.setPosition(0, 1200, -2000);
    rimLight.lookAt(glm::vec3(0, 900, 0));
    // Code from Lightening Example
    // control menu
    controlsString = "\nObjective: Land as close as you can to any\nof the white spheres watch your speed!\n\nControls:\narrow keys - movement\nspace - up\nshift - down\nc - lock/unlock easyCam\nf - fullscreen\ns - toggleEZcam target\nt - EZcam to ship\nmouse1 - select point\np - pause\nF1 - main cam\nF2 - easyCam\nF3 - leftCam\nF4 - rightCam\nF5 - frontCam\nF6 - bottomCam\nF7 - surfaceCam\nF8 - trackingCam\nh - hide this panel";
	// Code by Brandon Archbold
	// load in the meshes
	terrain.loadModel("geo/models/terrain.obj");
	terrain.setScaleNormalization(false);
	terrain.setRotation(1, 180, 0, 0, 1);
	// models for rocket and terrain created by Brandon Archbold
	if (rocket.loadModel("geo/models/rocket.obj"))
		bRoverLoaded = true;
	else {
		cout << "geo/models/rocket.obj file not found\n";
		ofExit();
	}
	rocket.setScaleNormalization(false);
	rocket.setRotation(1, 180, 0, 0, 1);
	ofDisableArbTex();
	// code by Brandon Archbold
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
	// add forces to the particle emitter for exhast
	exhastParticles.sys->addForce(new TurbulenceForce(ofVec3f(-200, -200, -200), ofVec3f(200, 200, 200)));
	exhastParticles.sys->addForce(new GravityForce(ofVec3f(0, -50, 0)));
	// setup the particle emitter
	exhastParticles.setVelocity(ofVec3f(0, 0, 0));
	exhastParticles.setEmitterType(DirectionalEmitter);
	exhastParticles.setGroupSize(50);
	exhastParticles.setLifespan(1);
	exhastParticles.setPosition(ofVec3f(0, 0, 0));
	exhastParticles.setVelocity(ofVec3f(0, -50, 0));
	exhastParticles.setRate(50);
    
	// load thruster sound
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
		// update the cameras
		glm::vec3 shipPos = pSys.particles[0].position;
		followCam.setPosition(glm::vec3(shipPos.x, shipPos.y, shipPos.z + 90));
		leftSideCam.setPosition(glm::vec3(shipPos.x - 20, shipPos.y, shipPos.z));
		leftSideCam.lookAt(glm::vec3(shipPos.x - 30, shipPos.y, shipPos.z));
		rightSideCam.setPosition(glm::vec3(shipPos.x + 20, shipPos.y, shipPos.z));
		rightSideCam.lookAt(glm::vec3(shipPos.x + 30, shipPos.y, shipPos.z));
		frontCam.setPosition(glm::vec3(shipPos.x, shipPos.y, shipPos.z - 90));
		frontCam.lookAt(glm::vec3(shipPos.x, shipPos.y, shipPos.z));
		bottomCam.setPosition(glm::vec3(shipPos.x, shipPos.y - 30, shipPos.z));
		bottomCam.lookAt(glm::vec3(shipPos.x, shipPos.y - 40, shipPos.z));
		surfaceCam.lookAt(glm::vec3(0, 0, 0));
		surfaceCam.lookAt(glm::vec3(shipPos.x, shipPos.y, shipPos.z));
		trackingCam.setPosition(glm::vec3(500, 500, 500));
		trackingCam.lookAt(glm::vec3(shipPos.x, shipPos.y, shipPos.z));

		// Code by Brandon Archbold
		// timer to stop multiple scoring 10 second between scores
		if (bScored)
			if ((ofGetSystemTimeMillis() - timeScored) > (uint64_t)10000) 
				bScored = false;
		// set the position of the exhast emitter
		exhastParticles.setPosition(ofVec3f(pSys.particles[0].position.x, pSys.particles[0].position.y - 30, pSys.particles[0].position.z));
		exhastParticles.update();
		currLevel = (int)numLevels;
		pSys.update();
		altitudeDetection();
		collisionDetection();
		rocket.setPosition(pSys.particles[0].position.x, pSys.particles[0].position.y, pSys.particles[0].position.z);	// have the rocket model follow the physics particle
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
	// code by Brandon Archbold
	// draw spheres to indicate landing zones
	ofDrawSphere(landingPad1, 5);
	ofDrawSphere(landingPad2, 5);
	ofDrawSphere(landingPad3, 5);

	ofPushMatrix();
	if (bWireframe) {                    // wireframe mode  (include axis)
		ofDisableLighting();
		ofSetColor(ofColor::slateGray);
		terrain.drawWireframe();
		ofSetColor(ofColor::white);
		if (bRoverLoaded) {
			rocket.drawWireframe();
			if (!bTerrainSelected) drawAxis(rocket.getPosition());
		}
		if (bTerrainSelected) drawAxis(ofVec3f(0, 0, 0));
	}
	else {
		ofEnableLighting();              // shaded mode
		terrain.drawFaces();
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
    areaLight.draw();
    directionalLight.draw();
    fillLight.draw();
    rimLight.draw();
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
// This method finds a point on the terrain using a ray generated by the mouse from screen to world space for selection
// when a point is selected and bPointSelected is true, a blue sphere is drawn on the terrain to indicate selection
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
// This code using ray tracing pointing down from the bottom of the ship
// to determine the altitude of the ship above any given terrain
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
			altitude = shipPos.y - 30 - y;	// the coordinates of the bottom of the ship minus the coordinates of the terrain equals the altitude of the ship
        }
    }
}
// Code by Brandon Archbold
// Thise method performs collision detection with the surface utilizing a point based selction method in the octree
// it also calculates the score when a collision is detected
// calc score will not apply any more points until a timer has expired so that you can only have
// one score generated per landing.
void ofApp::collisionDetection() {
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
// this method awards points to the user based on how close they get to the landing sphere
// if they are moving too fast no points are awarded
// points are only applied once every time interval as determined in update
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
// this is a simple method to determine the distance between two points in space
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
//  this method sets the camera target to either the point that was selected previously, or to the position of the ship
void ofApp::setCameraTarget() {
    // code by Brandon Archbold
	if (!bTargetShip && bPointSelected)
		easyCam.setPosition(glm::vec3(selectedPoint.x, selectedPoint.y, selectedPoint.z));
	else if (bTargetShip) {
        easyCam.setPosition(glm::vec3(pSys.particles[0].position.x, pSys.particles[0].position.y, pSys.particles[0].position.z));
		// code by Abraham Kong
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
