// This program demonstrates double buffering for flicker-free animation.
// It spins a white square on a black background.  It comes from Chapter 1
// of the OpenGL Programming Guide, but I made some minor changes, and did
// the animation properly, using timers, not the idle function.  Start the
// animation with the left mouse button and stop it with the right.

#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <iostream>
#include <ctime>
#include "utils.h"
#include "celestial.h"
#include "vector"

//pragma optimize gcc fast
#pragma GCC optimize("Ofast")

// Set this to true to animate.
static bool spinning = true;

// This is the number of frames per second to render.
static const int FPS = 160;

// This global variable keeps track of the current orientation of the square.
// It is better to maintain the "state" of the animation globally rather
// than trying to successively accumulate transformations.  Over a period of
// time the approach of accumulating transformation matrices generally
// degrades due to rounding errors.
static GLfloat currentAngleOfRotation = 0.0;

// Handles the window reshape event by first ensuring that the viewport fills
// the entire drawing surface.  Then we use a simple orthographic projection
// with a logical coordinate system ranging from -50..50 in the smaller of
// the width or height, and scale the larger dimension to make the whole
// window isotropic.
void reshape(GLint w, GLint h) {
    glViewport(0, 0, w, h);
    GLfloat aspect = (GLfloat)w / (GLfloat)h;
    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();
    if (w <= h) {
        // width is smaller, go from -50 .. 50 in width
        glOrtho(-50.0, 50.0, -50.0/aspect, 50.0/aspect, -1.0, 1.0);
    } else {
        // height is smaller, go from -50 .. 50 in height
        glOrtho(-50.0*aspect, 50.0*aspect, -50.0, 50.0, -1.0, 1.0);
    }
}


int64_t lastTime = utils::now();

GLfloat dt = 0;

std::vector<Particle> planets;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);


    glPushMatrix();
    glBegin(GL_QUADS);
    for (auto &planet : planets) {
        planet.update(dt);
        planet.draw();
    }
    glEnd();
    glPopMatrix();

    glFlush();
    glutSwapBuffers();

    int64_t now = utils::now();
    int64_t elapsed = now - lastTime;
    dt = elapsed / 1'000'000.0;
    std::cout << "FPS: " << 1.0 / dt << std::endl;
    lastTime = now;
}



// Handles the timer by incrementing the angle of rotation and requesting the
// window to display again, provided the program is in the spinning state.
// Since the timer function is only called once, it sets the same function to
// be called again.
void timer(int v) {
    if (spinning) {
        currentAngleOfRotation += 1.0;
        if (currentAngleOfRotation > 360.0) {
            currentAngleOfRotation -= 360.0;
        }
        glutPostRedisplay();
    }
    glutTimerFunc(1000/FPS, timer, v);
}

// Handles mouse events as follows: when the left button is pressed, generate
// new animation frames while the application is idle; when the right button
// is pressed, remove any idle-time callbacks, thus stopping the animation.
void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        spinning = true;
    } else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        spinning = false;
    }
}

// Initializes GLUT, the display mode, and main window; registers callbacks;
// enters the main event loop.

int main(int argc, char** argv) {
    std::srand(std::time(0));

    for (int i = 0; i < 1'000'000; i++) {
        Point pos(utils::random(-50.f, 50.f), utils::random(-50.f, 50.f));
        GLfloat size = utils::random(1.f, 1.f);
        GLfloat mass = 1;
        // (randint(0, 192), 0.5 * randint(128, 255), randint(128, 255))
        Color color(utils::random(0.f, 0.75f), utils::random(0.25f, 0.5f), utils::random(0.5f, 1.f));
        Point velocity(utils::random(-10.f, 10.f), utils::random(-10.f, 10.f));
        Particle planet(pos, size, color, velocity);

        planets.push_back(planet);
    }


    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(80, 80);
    glutInitWindowSize(1600, 800);
    glutCreateWindow("Spinning Square");
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutTimerFunc(10, timer, 0);
    glutMouseFunc(mouse);
    glutMainLoop();
}