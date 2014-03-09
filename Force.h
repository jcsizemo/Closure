/* 
 * File:   Player.h
 * Author: John
 *
 * Object representing the player or, in this case, the camera.
 * Acts as a wrapper for the objects in which the player can use (firebomb
 * or water balloon)
 * 
 * Created on May 1, 2013, 4:43 PM
 */

#ifndef FORCE_H
#define	FORCE_H
#include <iostream>
#include <vector>
#include "Eigen/Core"

using namespace std;
using namespace Eigen;

class Force {
public:
    Force();
    Force(const Force& orig);
    virtual ~Force();
    
    void update(Vector2f *obj);
    
private:

};

#endif	/* PLAYER_H */

