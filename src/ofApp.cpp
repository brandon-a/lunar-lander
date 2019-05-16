
//--------------------------------------------------------------
//
//  Kevin M. Smith 
//
//  Mars HiRise Project - startup scene
// 
//  This is an openFrameworks 3D scene that includes an EasyCam
//  and example 3D geometry which I have reconstructed from Mars
//  HiRis photographs taken the Mars Reconnaisance Orbiter
//
//  You will use this source file (and include file) as a starting point
//  to implement assignment 5  (Parts I and II)
//
//  Please do not modify any of the keymappings.  I would like 
//  the input interface to be the same for each student's 
//  work.  Please also add your name/date below.

//  Please document/comment all of your work !
//  Have Fun !!
//
//  Student Name:   Brandon Archbold
//  Date: April 22, 2019


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
//	ofSetWindowShape(1024, 768);
	cam.setDistance(10);
	cam.setNearClip(.1);
	cam.setFov(65.5);   // approx equivalent to 28mm in 35mm format
	ofSetVerticalSync(true);
	cam.disableMouseInput();
	ofEnableSmoothing();
	ofEnableDepthTest();
	sphere.setRadius(50);

	altitude = -1;
	// Code by Brandon Archbold
	ship = new Particle();

	// set up forces for ship
	pSys.add(*ship);
	pSys.particles[0].position = ofVec3f(0, 1000, 0);
	pSys.particles[0].velocity = ofVec3f(0, 0, 0);
	pSys.particles[0].lifespan = -1;
	pSys.particles[0].mass = 10;

    ofVec3f temp = ofVec3f(0, 0, 0);
	turbForce = new TurbulenceForce(ofVec3f(-20, -20, -20), ofVec3f(20, 20, 20));
	gravityForce = new GravityForce(ofVec3f(0, -10, 0));
	thrustForce = new ThrustForce(temp, 200.0);

	pSys.addForce(turbForce);
	pSys.addForce(gravityForce);
	pSys.addForce(thrustForce);
	// Code by Brandon Archbold
	// set up the cameras
	currCam = &followCam;
	followCam.setPosition(glm::vec3(pSys.particles[0].position.x, pSys.particles[0].position.y, pSys.particles[0].position.z + 90));
	followCam.setFov(90);
	followCam.setNearClip(.1);
	leftSideCam.setPosition(glm::vec3(-1580, 0,1000));
	leftSideCam.setFov(115);
	rightSideCam.setPosition(glm::vec3(pSys.particles[0].position.x + 100, pSys.particles[0].position.y + 20, pSys.particles[0].position.z));
	rightSideCam.setFov(90);
	frontCam.setPosition(glm::vec3(pSys.particles[0].position.x, pSys.particles[0].position.y, pSys.particles[0].position.z + 20));
	frontCam.setFov(90);
	bottomCam.setPosition(glm::vec3(pSys.particles[0].position.x, pSys.particles[0].position.y, pSys.particles[0].position.z));
	bottomCam.setFov(90);
	trackingCam.setPosition(glm::vec3(500, 500, 500));
	trackingCam.setFov(90);
	trackingCam.setOrientation(pSys.particles[0].position);

	gui.setup();
	gui.add(numLevels.setup("levels", 10, 1, 30));

    // setup rocketBottomLight
    // Code by Abraham Kong
//    rocketBottomLight.setup();
//    rocketBottomLight.enable();
//    rocketBottomLight.setSpotlight();
//    rocketBottomLight.setscale
//    rocketBottomLight.setPosition(pSys.particles[0].position.x, pSys.particles[0].position.y , pSys.particles[0].position.z);
//    rocketBottomLight.setDirectional();
//    rocketBottomLight.setAreaLight(100, 100);
    
    
//    rocketBottomLight.setup();
//    rocketBottomLight.enable();
//    rocketBottomLight.setSpotlight();
//    rocketBottomLight.setScale(.05);
//    rocketBottomLight.setSpotlightCutOff(30);
//    rocketBottomLight.setAttenuation(.2, .001, .001);
//    rocketBottomLight.setAmbientColor(ofFloatColor(0.1, 0.1, 0.1));
//    rocketBottomLight.setDiffuseColor(ofFloatColor(.3, 0, 1));
//    rocketBottomLight.setSpecularColor(ofFloatColor(1, 1, 1));
//    rocketBottomLight.rotate(180, ofVec3f(0, 1, 0));
//    rocketBottomLight.setPosition(pSys.particles[0].position.x, pSys.particles[0].position.y , pSys.particles[0].position.z );
    // Code by Abraham Kong
    
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
	octree.create(terrain.getMesh("pPlane1"), (int) numLevels);
	// Code by Brandon Archbold
}

//--------------------------------------------------------------
// incrementally update scene (animation)
//
void ofApp::update() {
	if (!isPaused) {
		// update cameras
		// Code by Brandon Archbold
		followCam.setPosition(glm::vec3(pSys.particles[0].position.x, pSys.particles[0].position.y, pSys.particles[0].position.z + 90));
		trackingCam.setOrientation(pSys.particles[0].position);
		exhastParticles.setPosition(ofVec3f(pSys.particles[0].position.x, pSys.particles[0].position.y - 30, pSys.particles[0].position.z));
		exhastParticles.update();
		currLevel = (int)numLevels;
		pSys.update();
		altitudeDetection();
		rocket.setPosition(pSys.particles[0].position.x, pSys.particles[0].position.y, pSys.particles[0].position.z);
        // Code by Brandon Archbold
        // Code by Abraham Kong
        
        // Code by Abraham Kong
        
	}
}
//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(ofColor::black);
	/*gui.draw();
	numLevels.draw();*/
//	ofBackgroundGradient(ofColor(20), ofColor(0));   // pick your own backgroujnd
	
//	cout << ofGetFrameRate() << endl;
	ofSetColor(ofColor::white);
	//sphere.draw();
	loadVbo();
	currCam->begin();
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
		ofDrawSphere(selectedPoint, .1);
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
//    rocketBottomLight.draw();
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
	ofDrawBitmapString(str, ofGetWindowWidth() - 170, 15);
	string str2 = "Altitude: " + std::to_string(altitude);
	ofDrawBitmapString(str2, 0, 15);
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
	case 'C':
	case 'c':
		if (cam.getMouseInputEnabled()) cam.disableMouseInput();
		else cam.enableMouseInput();
		break;
	case 'F':
	case 'f':
		ofToggleFullscreen();
		break;
	case 'H':
	case 'h':

		break;
	case 'r':
		cam.reset();
		break;
	case 's':
		//savePicture();
		break;
	case 'l':
		leaf = !leaf;
		break;
	case 't':
		setCameraTarget();
		break;
	case 'u':
		break;
	case 'v':
		togglePointsDisplay();
		break;
	case 'p': isPaused = !isPaused;
		break;
	case 'w':
		toggleWireframeMode();
		break;
	case OF_KEY_ALT:
		cam.enableMouseInput();
		bAltKeyDown = true;
		break;
	case OF_KEY_CONTROL:
		bCtrlKeyDown = true;
		break;
		// Code by Brandon Archbold
	case OF_KEY_SHIFT: thrustForce->setDirection(ofVec3f(thrustForce->getDirection().x, -1, thrustForce->getDirection().z));
		break;
	case ' ': thrustForce->setDirection(ofVec3f(thrustForce->getDirection().x, 1, thrustForce->getDirection().z));
		exhastParticles.start();
		if(!thrustSound.isPlaying())
			thrustSound.play();
		break;
	case OF_KEY_UP: thrustForce->setDirection(ofVec3f(thrustForce->getDirection().x, thrustForce->getDirection().y, -1));
		break;
	case OF_KEY_DOWN: thrustForce->setDirection(ofVec3f(thrustForce->getDirection().x, thrustForce->getDirection().y, 1));
		break;
	case OF_KEY_LEFT: thrustForce->setDirection(ofVec3f(-1, thrustForce->getDirection().y, thrustForce->getDirection().z));
		break;
	case OF_KEY_RIGHT: thrustForce->setDirection(ofVec3f(1, thrustForce->getDirection().y, thrustForce->getDirection().z));
		break;
	case OF_KEY_F1: currCam = &followCam;
		break;
	case OF_KEY_F2: currCam = &cam;
		break;
		// Code by Brandon Archbold
        //Code by Abraham Kong
    case OF_KEY_F3: currCam = &leftSideCam;
        break;
    case OF_KEY_F4: currCam = &rightSideCam;
        break;
    case OF_KEY_F5: currCam = &frontCam;
        break;
    case OF_KEY_F6: currCam = &bottomCam;
        break;
    case OF_KEY_F7: currCam = &surfaceCam;
        break;
    case OF_KEY_F8: currCam = &trackingCam;
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
		cam.disableMouseInput();
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
	ofTime* time = new ofTime();
	uint64_t end;
	uint64_t start = time->getAsMilliseconds();
	if (octree.intersect(ray, octree.root, nodeRtn)) {
		ofVec3f pos = terrain.getMesh("pPlane1").getVertex(nodeRtn.points.at(0));
		sphere.setGlobalPosition(pos);
		cout << "Intersects at: " << pos << endl;
		end = time->getAsMilliseconds();
		uint64_t total = end - start;
		cout << "Selection time: " << total << "ms\n";
	}
}
// Code by Brandon Archbold
void ofApp::altitudeDetection() {
	ofVec3f shipPos = pSys.particles[0].position;
    ofVec3f rayPoint = ofVec3f(shipPos.x, shipPos.y - 30, shipPos.z);
    ofVec3f rayDir = rayPoint - ofVec3f(shipPos.x, shipPos.y, shipPos.z);
    rayDir.normalize();
    Ray ray = Ray(Vector3(rayPoint.x, rayPoint.y, rayPoint.z), Vector3(rayDir.x, rayDir.y, rayDir.z));
    TreeNode nodeRtn;
    if (octree.intersect(ray, octree.root, nodeRtn)) {
        if (nodeRtn.points.size() != 0) {
            ofVec3f pos = terrain.getMesh("pPlane1").getVertex(nodeRtn.points.at(0));
            altitude = shipPos.y - 30 + abs(pos.y);
        }
    }
}
// Code by Brandon Archbold


//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {


}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}


////
////  ScreenSpace Selection Method: 
////  This is not the octree method, but will give you an idea of comparison
////  of speed between octree and screenspace.
////
////  Select Target Point on Terrain by comparing distance of mouse to 
////  vertice points projected onto screenspace.
////  if a point is selected, return true, else return false;
////
//bool ofApp::doPointSelection() {
//
//	ofMesh mesh = terrain.getMesh(0);
//	int n = mesh.getNumVertices();
//	float nearestDistance = 0;
//	int nearestIndex = 0;
//
//	bPointSelected = false;
//
//	ofVec2f mouse(mouseX, mouseY);
//	vector<ofVec3f> selection;
//
//	// We check through the mesh vertices to see which ones
//	// are "close" to the mouse point in screen space.  If we find 
//	// points that are close, we store them in a vector (dynamic array)
//	//
//	for (int i = 0; i < n; i++) {
//		ofVec3f vert = mesh.getVertex(i);
//		ofVec3f posScreen = cam.worldToScreen(vert);
//		float distance = posScreen.distance(mouse);
//		if (distance < selectionRange) {
//			selection.push_back(vert);
//			bPointSelected = true;
//		}
//	}
//
//	//  if we found selected points, we need to determine which
//	//  one is closest to the eye (camera). That one is our selected target.
//	//
//	if (bPointSelected) {
//		float distance = 0;
//		for (int i = 0; i < selection.size(); i++) {
//			ofVec3f point =  cam.worldToCamera(selection[i]);
//
//			// In camera space, the camera is at (0,0,0), so distance from 
//			// the camera is simply the length of the point vector
//			//
//			float curDist = point.length(); 
//
//			if (i == 0 || curDist < distance) {
//				distance = curDist;
//				selectedPoint = selection[i];
//			}
//		}
//	}
//	return bPointSelected;
//}

// Set the camera to use the selected point as it's new target
//  
void ofApp::setCameraTarget() {

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

//--------------------------------------------------------------
//
// support drag-and-drop of model (.obj) file loading.  when
// model is dropped in viewport, place origin under cursor
//
void ofApp::dragEvent(ofDragInfo dragInfo) {
/*
	ofVec3f point;
	mouseIntersectPlane(ofVec3f(0, 0, 0), cam.getZAxis(), point);

	if (rover.loadModel(dragInfo.files[0])) {
		rover.setScaleNormalization(false);
		rover.setScale(.005, .005, .005);
		rover.setPosition(point.x, point.y, point.z);
		bRoverLoaded = true;
	}
	else cout << "Error: Can't load model" << dragInfo.files[0] << endl;*/
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
