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
#include "solar_system.h"
#include "fps_counter.h"
#include "vector"

// This is the number of frames per second to render.
static const int FPS = 160;

#define PI 3.14159265358979323846


void reshape(GLint w, GLint h) {
    glViewport(0, 0, w, h);
    GLfloat aspect = (GLfloat)w / (GLfloat)h;
    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();
    if (w <= h) {
        glOrtho(-50.0, 50.0, -50.0/aspect, 50.0/aspect, -1.0, 1.0);
    } else {
        glOrtho(-50.0*aspect, 50.0*aspect, -50.0, 50.0, -1.0, 1.0);
    }
}


int64_t lastTime = utils::now();

GLfloat dt = 0;

SolarSystem solarSystem;
FPSCounter fpsCounter(1);


void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    solarSystem.update(dt);
    solarSystem.draw();

    fpsCounter.update();
    std::cout << "FPS: " << fpsCounter.getFPS() << std::endl;

    glFlush();
    glutSwapBuffers();

    int64_t now = utils::now();
    int64_t elapsed = now - lastTime;
    dt = elapsed / 1'000'000.0;
    lastTime = now;
}


void timer(int v) {
    glutPostRedisplay();
    glutTimerFunc(1000/FPS, timer, v);
}


int main(int argc, char** argv) {
    std::srand(std::time(0));

    Point pos;
    GLfloat angle, distance, size, mass;
    Color color;
    Point velocity;

    pos = Point(0, 0);
    size = 10;
    mass = 100;
    color = Color(utils::random(0.f, 0.75f), utils::random(0.25f, 0.5f), utils::random(0.5f, 1.f));
    velocity = Point(0, 0);

    auto star = new Celestial(pos, size, mass, color, velocity);

    solarSystem.setStar(star);


    for (int i = 0; i < 250'000; i++) {

        angle = utils::random(0.f, 2 * M_PI);
        distance = std::sqrt(utils::random(1.f, 20000.f));
        pos = Point(distance * std::cos(angle), distance * std::sin(angle));
        size = utils::random(1.f, 1.f);
        mass = 1;
        color = Color(utils::random(0.f, 0.75f), utils::random(0.25f, 0.5f), utils::random(0.5f, 1.f));
        velocity = star->perfectVelocity(pos) * utils::random(0.5f, 1.f);

        auto planet = new Celestial(pos, size, mass, color, velocity);

        solarSystem.addPlanet(planet);
    }


    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(80, 80);
    glutInitWindowSize(1600, 800);
    glutCreateWindow("Spinning Square");
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutTimerFunc(10, timer, 0);
    glutMainLoop();
}