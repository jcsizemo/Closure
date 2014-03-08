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

// initial position and rotation values
Player::Player() {
}

Player::Player(const Player& orig) {
}

Player::~Player() {
}

void Player::keyboard(bool *keys, double dt) {

}

void Player::draw() {
    
}

