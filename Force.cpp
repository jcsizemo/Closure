/* 
 * File:   Force.cpp
 * Author: John
 * 
 * Created on March 8, 2014, 4:43 PM
 * 
 * Generic class for a force.
 */

#include <cstdlib>
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

Force::Force() {
}

Force::Force(const Force& orig) {
}

Force::~Force() {
}

void Force::update(Vector2f* obj) {
    
}

