/* 
 * File:   main.cpp
 * Author: John
 *
 * Created on May 1, 2013, 4:26 PM
 * 
 * Terraform class acting as the driver for all other classes. Initializes
 * the OpenGL states, updates time variable used in time-based animations,
 * builds the game world, updates values used for keyboard/mouse interaction,
 * draws all structures, and updates the player's movement.
 */

#include <cstdlib>
#include <GL/glew.h>
#if defined(_WIN32)
#include <GL/wglew.h>
#endif

#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <ctime>
#include <vector>
#include "Player.h"

using namespace std;

// time variable counting time elapsed per frame
double dt = -1;
clock_t t;

Player *p;

// arrays used for keyboard and mouse interactions. used in time based animation
bool keys[255];

// Enable function. Enables the two lights, lighting, blending, colored material,
// and depth testing. Also sets the material parameters for objects in the map.

void enable(void) {
    GLfloat specular[] = {1, 1, 1, 1}; // specular light for the shiny reflections on the sphetower
    GLfloat ambient[] = {0.01, 0.01, 0.01, 1}; // low ambient light.
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
    GLfloat diffuse[] = {1, 1, 1, 1}; // diffuse light for the lighting of the sphetower
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);

    GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};  // white specular material
    GLfloat mat_shininess[] = {50.0};               // shiny!
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    GLfloat light0_position[] = {-100, 300, 0, 1}; // Last 1 means light is positional, if a zero then directional
    glShadeModel(GL_SMOOTH); // Put spotlight directly above center platform.
    glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 70.0); // 45 degree spotlight
    GLfloat spot0_direction[] = {0.0, -1.0, 0.0}; // shine directly downward
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot0_direction);
    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.5);
    glLightfv(GL_LIGHT0, GL_POSITION, light0_position);

    glEnable(GL_DEPTH_TEST); //enable the depth testing
    glEnable(GL_LIGHTING); //enable the lighting
    glEnable(GL_LIGHT0); //enable LIGHT0
    glEnable(GL_LIGHT1); // enable LIGHT1
    glEnable(GL_BLEND); // enable blending
    glEnable(GL_COLOR_MATERIAL); // enable coloring

}

// reshape viewport
void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei) w, (GLsizei) h); //set the viewport to the current window specifications
    glMatrixMode(GL_PROJECTION); //set the matrix to projection

    glLoadIdentity();
    gluPerspective(60, (GLfloat) w / (GLfloat) h, 1.0, 1000.0
            ); //set the perspective (angle of sight, width, height, , depth)
    glMatrixMode(GL_MODELVIEW); //set the matrix back to model
    glLoadIdentity();

}

void display(void) {
    //update dt for time based animation
    dt = (((double) clock() - t) / CLOCKS_PER_SEC);
    t = clock();

    glClearColor(1.0, 1.0, 1.0, 1.0); //clear the screen to black
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear the color buffer and the depth buffer
    glLoadIdentity();

    glEnable(GL_DEPTH_TEST); //enable the depth testing
    glEnable(GL_COLOR_MATERIAL); // enable coloring
//    enable();
    
    glOrtho(-10, 10, -10, 10, 0, -10);
    
    glTranslated(0,0,-2);
    
    glPushMatrix();
    p->draw();
    glPopMatrix();

    glutSwapBuffers(); //swap the buffers
}

// Function controlling keyboard inputs.

void keyDown(unsigned char key, int x, int y) {
    // set value to true if pressed down
    
    // toggle program exit with 'escape'
    if (key == 27) {
        exit(0);
    }

}

void keyUp(unsigned char key, int x, int y) {
    // set key to false if released


}

int main(int argc, char** argv) {
//     create player
    p = new Player();

    // init glut
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH); // double and depth buffering
//    glutEnterGameMode(); //full screen
    // remove comments in the below three lines and comment out the line
    // above for a game window
    glutInitWindowSize(1000, 700); // window size
    glutInitWindowPosition(100, 100); // window position on screen
    glutCreateWindow("Closure"); // window title
    glutDisplayFunc(display); // set display function
    glutIdleFunc(display); // set idle function
    glutReshapeFunc(reshape); // set reshape function

    glutKeyboardFunc(keyDown); // set key down function
    glutKeyboardUpFunc(keyUp); // set key up function

    t = clock();        // init clock
    
    glutMainLoop();
    return 0;
}

