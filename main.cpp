// This program demonstrates double buffering for flicker-free animation.
// It spins a white square on a black background.  It comes from Chapter 1
// of the OpenGL Programming Guide, but I made some minor changes, and did
// the animation properly, using timers, not the idle function.  Start the
// animation with the left mouse button and stop it with the right.

#ifdef __APPLE_CC__

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
static const int FPS = 1'000'000;

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
    dt = static_cast<GLfloat>(elapsed) / static_cast<GLfloat>(utils::TIME_UNIT);
    lastTime = now;
}


void timer(int v) {
    glutPostRedisplay();
    glutTimerFunc(1000/FPS, timer, v);
}


int main(int argc, char** argv) {
    std::srand(std::time(0));

    Point pos;
    GLfloat angle, distance, mass;
    GLint size;
    Color color;
    Point velocity;

    pos = Point(0, 0);
    size = 1;
    mass = 100;
    color = Color(utils::randbyte(0, 192), utils::random(64, 128), utils::random(128, 255));
    velocity = Point(0, 0);

    auto star = new Celestial(pos, size, mass, color, velocity);

    solarSystem.setStar(star);


    for (int i = 0; i < SolarSystem::MAX_PLANETS; i++) {

        angle = utils::random(0.f, 2 * M_PI);
        distance = std::sqrt(utils::random(1.f, 20000.f));
        pos = Point(distance * std::cos(angle), distance * std::sin(angle));
        size = utils::randint(1, 1);
        mass = 1;
        color = Color(utils::randbyte(0, 0), utils::random(64, 128), utils::random(0, 0));
        velocity = star->perfectVelocity(pos) * utils::random(0.6f, 0.8f);

        auto planet = new Celestial(pos, size, mass, color, velocity);

        solarSystem.addPlanet(*planet);
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