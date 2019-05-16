#pragma once
//  Kevin M. Smith - CS 134 SJSU

#include "ofMain.h"
#include "Particle.h"


//  Pure Virtual Function Class - must be subclassed to create new forces.
//
class ParticleForce {
protected:
public:
	bool applyOnce = false;
	bool applied = false;
	virtual void updateForce(Particle *) = 0;
};

class ParticleSystem {
public:
	void add(const Particle &);
	void addForce(ParticleForce *);
	void remove(int);
	void update();
	void setLifespan(float);
	void reset();
	int removeNear(const ofVec3f & point, float dist);
	void draw();
	vector<Particle> particles;
	vector<ParticleForce *> forces;
};



// Some convenient built-in forces
//
class GravityForce: public ParticleForce {
	ofVec3f gravity;
public:
	GravityForce(const ofVec3f & gravity);
	void updateForce(Particle *);
	void setGravity(ofVec3f grav) { gravity = grav; }
};

class TurbulenceForce : public ParticleForce {
	ofVec3f tmin, tmax;
public:
	TurbulenceForce(const ofVec3f & min, const ofVec3f &max);
	void updateForce(Particle *);
	void set(ofVec3f min, ofVec3f max) { tmin = min; tmax = max; }
};

class ImpulseRadialForce : public ParticleForce {
	float magnitude;
	float height;
public:
	ImpulseRadialForce(float magnitude); 
	void updateForce(Particle *);
	void setHeight(float height);
};

// code by Brandon Archbold
class ThrustForce : public ParticleForce {
	float magnitude;
	ofVec3f direction;
public:
	ThrustForce(ofVec3f &dir, float mag);
	void updateForce(Particle *);
	void setMagnitude(float mag) { magnitude = mag; }
	void setDirection(ofVec3f dir) { direction = dir; }
	float getMagnitude() { return magnitude; }
	ofVec3f getDirection() { return direction; }
};

class ImpulseForce : public ParticleForce {
public:
	ImpulseForce() {
		applyOnce = true;
		applied = true;
		force = ofVec3f(0, 0, 0);
	}
	void apply(const ofVec3f f) {
		applied = false;
		force = f;
	}
	void updateForce(Particle* particle) {
		particle->forces += force;
	}
	ofVec3f force;
};