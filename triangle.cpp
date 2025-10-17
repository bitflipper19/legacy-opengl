#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Point {
    float x, y;
};

int main() {
    if (!glfwInit()) {
        cout<< "Boo"<< endl;
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 800, "Triangle", NULL, NULL);
    if (!window) {
        cout<< "Boo"<< endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) {
        cout<< "Boo"<< endl;
        return -1;
    }

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 800, 0, 800, -1, 1);
    glMatrixMode(GL_MODELVIEW);

    Point vertices[3] = {
        {400.0f, 780.0f},
        {50.0f,  20.0f},
        {750.0f, 20.0f}
    };

    // Point vertices[4] = {
    //     {20.0f, 20.0f},
    //     {720.0f, 20.0f},
    //     {20.0f, 720.0f},
    //     {720.0f, 720.0f}
    // };

    // Point vertices[5] = {
    //     {20.0f, 20.0f},
    //     {341.54f, 20.0f},
    //     {20.0f, 341.54f},
    //     {341.54f, 341.54f},
    //     {180.77f, 620.0f}
    // };

    srand((unsigned)time(nullptr));
    Point current = {400.0f, 400.0f};

    int iterations = 0;
    const int maxIterations = 10000;

    glPointSize(1.5f);

    while (!glfwWindowShouldClose(window)) {
        // glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POINTS);

        for (int k = 0; k < 10 && iterations < maxIterations; k++) {
            int choice = rand() % 3;
            current.x = (current.x + vertices[choice].x) / 2.0f;
            current.y = (current.y + vertices[choice].y) / 2.0f;
            // GLfloat r = (rand() % 256) / 255.0f;
            // GLfloat g = (rand() % 256) / 255.0f;
            // GLfloat b = (rand() % 256) / 255.0f;
            glColor3f(0.0f, 1.0f, 1.0f);

            glVertex2f(current.x, current.y);

            iterations++;
        }

        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();

        if (iterations >= maxIterations) {
            while (!glfwWindowShouldClose(window)) {
                glfwSwapBuffers(window);
                glfwPollEvents();
            }
        }
    }

    glfwTerminate();
    return 0;
}
