
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

	ship = new Particle();

	// set up forces for ship
	pSys.add(*ship);
	pSys.particles[0].position = ofVec3f(0, 1000, 0);
	pSys.particles[0].velocity = ofVec3f(0, 0, 0);
	pSys.particles[0].lifespan = -1;
	pSys.particles[0].mass = 10;

	turbForce = new TurbulenceForce(ofVec3f(-20, -20, -20), ofVec3f(20, 20, 20));
	gravityForce = new GravityForce(ofVec3f(0, -10, 0));
	thrustForce = new ThrustForce(ofVec3f(0, 0, 0), 60.0);

	pSys.addForce(turbForce);
	pSys.addForce(gravityForce);
	pSys.addForce(thrustForce);

	// set up the cameras
	currCam = &followCam;
	followCam.setPosition(glm::vec3(pSys.particles[0].position.x, pSys.particles[0].position.y, pSys.particles[0].position.z + 90));
	followCam.setFov(90);
	followCam.setNearClip(.1);
	leftSideCam.setPosition(glm::vec3(pSys.particles[0].position.x - 20, pSys.particles[0].position.y, pSys.particles[0].position.z));
	leftSideCam.setFov(90);
	rightSideCam.setPosition(glm::vec3(pSys.particles[0].position.x + 20, pSys.particles[0].position.y, pSys.particles[0].position.z));
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

	// load the shader
	//
#ifdef TARGET_OPENGLES
	shader.load("shaders_gles/shader");
#else
	shader.load("shaders/shader");
#endif

	exhastParticles.sys->addForce(new TurbulenceForce(ofVec3f(-20, -20, -20), ofVec3f(20, 20, 20)));
	exhastParticles.sys->addForce(new GravityForce(ofVec3f(0, -50, 0)));

	exhastParticles.setVelocity(ofVec3f(0, 0, 0));
	exhastParticles.setEmitterType(DirectionalEmitter);
	exhastParticles.setGroupSize(1000);
	exhastParticles.setLifespan(2);
	exhastParticles.setPosition(ofVec3f(0, 0, 0));

	octree.create(terrain.getMesh("pPlane1"), (int) numLevels);


	//boundingBox = meshBounds(mars.getMesh(0));
	
	//  Test Box Subdivide
	//
	/*subDivideBox8(boundingBox, level1);
	subDivideBox8(level1[0], level2);
	subDivideBox8(level2[0], level3);
	subDivideBox8(level3[0], level4);*/
}

//--------------------------------------------------------------
// incrementally update scene (animation)
//
void ofApp::update() {
	if (!isPaused) {
		// update cameras
		followCam.setPosition(glm::vec3(pSys.particles[0].position.x, pSys.particles[0].position.y, pSys.particles[0].position.z + 90));
		trackingCam.setOrientation(pSys.particles[0].position);
		exhastParticles.update();
		currLevel = (int)numLevels;
		pSys.update();
		rocket.setPosition(pSys.particles[0].position.x, pSys.particles[0].position.y, pSys.particles[0].position.z);
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
	sphere.draw();
	loadVbo();
	currCam->begin();
	followCam.draw();
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

	// draw screen data
	//
	string str;
	str += "Frame Rate: " + std::to_string(ofGetFrameRate());
	ofSetColor(ofColor::white);
	ofDrawBitmapString(str, ofGetWindowWidth() - 170, 15);
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
		savePicture();
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
	case OF_KEY_SHIFT: thrustForce->setDirection(ofVec3f(thrustForce->getDirection().x, -1, thrustForce->getDirection().z));
		break;
	case ' ': thrustForce->setDirection(ofVec3f(thrustForce->getDirection().x, 1, thrustForce->getDirection().z));
		exhastParticles.start();
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
	case OF_KEY_SHIFT: thrustForce->setDirection(ofVec3f(thrustForce->getDirection().x, 0, thrustForce->getDirection().z));
		break;
	case ' ': thrustForce->setDirection(ofVec3f(thrustForce->getDirection().x, 0, thrustForce->getDirection().z));
		exhastParticles.stop();
		break;
	case OF_KEY_UP: thrustForce->setDirection(ofVec3f(thrustForce->getDirection().x, thrustForce->getDirection().y, 0));
		break;
	case OF_KEY_DOWN: thrustForce->setDirection(ofVec3f(thrustForce->getDirection().x, thrustForce->getDirection().y, 0));
		break;
	case OF_KEY_LEFT: thrustForce->setDirection(ofVec3f(0, thrustForce->getDirection().y, thrustForce->getDirection().z));
		break;
	case OF_KEY_RIGHT: thrustForce->setDirection(ofVec3f(0, thrustForce->getDirection().y, thrustForce->getDirection().z));
		break;
	default:
		break;

	}
}



//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
}


//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
    ofVec3f mouse(mouseX, mouseY);
	ofVec3f rayPoint = cam.screenToWorld(mouse);
	ofVec3f rayDir = rayPoint - cam.getPosition();
	rayDir.normalize();
	Ray ray = Ray(Vector3(rayPoint.x, rayPoint.y, rayPoint.z), Vector3(rayDir.x, rayDir.y, rayDir.z));
	TreeNode nodeRtn;
	ofTime* time = new ofTime();
	uint64_t end;
	uint64_t start = time->getAsMilliseconds();
	if (octree.intersect(ray, octree.root, nodeRtn)) {
		ofVec3f pos = terrain.getMesh("pPlane1").getVertex(nodeRtn.points.at(0));
		sphere.setPosition(pos);
		cout << "Intersects at: " << pos << endl;
		end = time->getAsMilliseconds();
		uint64_t total = end - start;
		cout << "Selection time: " << total << "ms\n";
	}
}


////draw a box from a "Box" class  
////
//void ofApp::drawBox(const Box &box) {
//	Vector3 min = box.parameters[0];
//	Vector3 max = box.parameters[1];
//	Vector3 size = max - min;
//	Vector3 center = size / 2 + min;
//	ofVec3f p = ofVec3f(center.x(), center.y(), center.z());
//	float w = size.x();
//	float h = size.y();
//	float d = size.z();
//	ofDrawBox(p, w, h, d);
//}
//
//// return a Mesh Bounding Box for the entire Mesh
////
//Box ofApp::meshBounds(const ofMesh & mesh) {
//	int n = mesh.getNumVertices();
//	ofVec3f v = mesh.getVertex(0);
//	ofVec3f max = v;
//	ofVec3f min = v;
//	for (int i = 1; i < n; i++) {
//		ofVec3f v = mesh.getVertex(i);
//
//		if (v.x > max.x) max.x = v.x;
//		else if (v.x < min.x) min.x = v.x;
//
//		if (v.y > max.y) max.y = v.y;
//		else if (v.y < min.y) min.y = v.y;
//
//		if (v.z > max.z) max.z = v.z;
//		else if (v.z < min.z) min.z = v.z;
//	}
//	return Box(Vector3(min.x, min.y, min.z), Vector3(max.x, max.y, max.z));
//}
//
////  Subdivide a Box into eight(8) equal size boxes, return them in boxList;
////
//void ofApp::subDivideBox8(const Box &box, vector<Box> & boxList) {
//	Vector3 min = box.parameters[0];
//	Vector3 max = box.parameters[1];
//	Vector3 size = max - min;
//	Vector3 center = size / 2 + min;
//	float xdist = (max.x() - min.x()) / 2;
//	float ydist = (max.y() - min.y()) / 2;
//	float zdist = (max.z() - min.z()) / 2;
//	Vector3 h = Vector3(0, ydist, 0);
//
//	//  generate ground floor
//	//
//	Box b[8];
//	b[0] = Box(min, center);
//	b[1] = Box(b[0].min() + Vector3(xdist, 0, 0), b[0].max() + Vector3(xdist, 0, 0));
//	b[2] = Box(b[1].min() + Vector3(0, 0, zdist), b[1].max() + Vector3(0, 0, zdist));
//	b[3] = Box(b[2].min() + Vector3(-xdist, 0, 0), b[2].max() + Vector3(-xdist, 0, 0));
//
//	boxList.clear();
//	for (int i = 0; i < 4; i++)
//		boxList.push_back(b[i]);
//
//	// generate second story
//	//
//	for (int i = 4; i < 8; i++) {
//		b[i] = Box(b[i - 4].min() + h, b[i - 4].max() + h);
//		boxList.push_back(b[i]);
//	}
//}

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