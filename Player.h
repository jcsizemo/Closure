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

#ifndef PLAYER_H
#define	PLAYER_H
#include <iostream>
#include <vector>
#include "Eigen/Core"

using namespace std;
using namespace Eigen;

class Player {
public:
    Player();
    Player(const Player& orig);
    virtual ~Player();

    // keyboard function controlling movement per time
    void keyboard(bool *keys, double dt);
    
    // draw function for displaying the player
    void draw();
    
    Vector3f x;
    Vector3f v;
    
private:

};

#endif	/* PLAYER_H */

