#pragma once

#include "ofMain.h"
#include  "ofxAssimpModelLoader.h"
#include "box.h"
#include "ray.h"
#include "Octree.h"
#include <iostream>
#include <string>
#include "ofxGui.h"
#include "ParticleSystem.h"
#include "Particle.h"
#include "ParticleEmitter.h"
#include <cmath>

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		void drawAxis(ofVec3f);
		void initLightingAndMaterials();
		void savePicture();
		void toggleWireframeMode();
		void togglePointsDisplay();
		void toggleSelectTerrain();
		void setCameraTarget();
		bool  doPointSelection();
		void drawBox(const Box &box);
		Box meshBounds(const ofMesh &);
		void subDivideBox8(const Box &b, vector<Box> & boxList);
		void loadVbo();
		void altitudeDetection();
		void collisionDetection();

		bool mouseIntersectPlane(ofVec3f planePoint, ofVec3f planeNorm, ofVec3f &point);

		ofEasyCam easyCam;
		ofCamera followCam;
		ofCamera leftSideCam;
		ofCamera rightSideCam;
		ofCamera frontCam;
		ofCamera bottomCam;
		ofCamera surfaceCam;
		ofCamera trackingCam;
		ofCamera* currCam;
		ofxAssimpModelLoader terrain, rocket;
		ofLight light;
        ofLight rocketBottomLight;
		Box boundingBox;
		vector<Box> level1, level2, level3, level4;
		Octree octree;
		ofxIntSlider numLevels;
		ofxPanel gui;
		ofSpherePrimitive sphere;
		ParticleSystem pSys;
		Particle* ship;
		ParticleEmitter exhastParticles;
		ofSoundPlayer thrustSound;

		TurbulenceForce* turbForce;
		GravityForce* gravityForce;
		ThrustForce* thrustForce;
		ImpulseForce impulseForce;

		ofTexture particleTexture;
		ofVbo vbo;
		ofShader shader;
		ofImage backgroundImage;

		bool bAltKeyDown;
		bool bCtrlKeyDown;
		bool bWireframe;
		bool bDisplayPoints;
		bool bPointSelected;
		bool leaf;
		int	currLevel;
		bool isPaused;
		bool bCollision;
		bool bBackgroundLoaded;

		bool bRoverLoaded;
		bool bTerrainSelected;
		bool bTargetShip;
			
		ofVec3f selectedPoint;
		ofVec3f intersectPoint;
		ofVec3f contactPt;

		float altitude;
		const float selectionRange = 4.0;
};
