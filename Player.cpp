/* 
 * File:   Player.cpp
 * Author: John
 * 
 * Created on May 1, 2013, 4:43 PM
 * 
 * Player class. Controls player movement as well as throwable object
 * interactions with other interactive structures in the scene.
 */

#include <cstdlib>
#include "Player.h"
#include "Force.h"
#include <GL/glew.h>
#if defined(_WIN32)
#include <GL/wglew.h>
#endif

#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <cmath>

#define UP 101
#define DOWN 103
#define LEFT 100
#define RIGHT 102

#define SPACE 32

#define MOVE_FORCE 5000
#define JUMP_FORCE 500000

// initial position and rotation values
Player::Player() {
    this->x << 0,0;
    this->v << 0,0;
    this->mass = 30;
}

Player::Player(const Player& orig) {
}

Player::~Player() {
}

void Player::keyboard(bool *keys, bool *specKeys, double dt) {
    
    if (specKeys[RIGHT]) { // forward
        this->v[0] += dt*MOVE_FORCE/mass;
    }

    if (specKeys[LEFT]) { // backward
        this->v[0] -= dt*MOVE_FORCE/mass;
    }
    
    if (v[0] > 20) v[0] = 20;
    if (v[0] < -20) v[0] = -20;
    
    if (keys[SPACE]) {
        this->v[1] += dt*JUMP_FORCE/mass;
        std::cout << "JUMP" << std::endl;
    }

}

void Player::draw(double dt, vector<Force*> *forces) {
    this->v[1] -= mass*9.81*dt;
    this->x += this->v*dt;
    
    glPushMatrix();
    glColor3f(1,0,0);
    glBegin(GL_QUADS);
    glVertex3f(0+this->x[0],0+this->x[1],0);
    glVertex3f(0+this->x[0],1+this->x[1],0);
    glVertex3f(1+this->x[0],1+this->x[1],0);
    glVertex3f(1+this->x[0],0+this->x[1],0);
    glEnd();
    glPopMatrix();
}

