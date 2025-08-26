#include <bits/stdc++.h>
#include <GL/glew.h> // Mfw wraangler libs need to to be included before glfw >_<
#include <GLFW/glfw3.h>
using namespace std;

void drawCircle(GLfloat center[], GLfloat radius) {
    int smoothness =  100;
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < smoothness; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(smoothness);
        float x = radius * cosf(theta);
        float y = radius * sinf(theta);
        glVertex2f(center[0] + x, center[1] + y); // Parametric equation of a circle
    }
    glEnd();
}

void drawRectangle(GLfloat p[]) {
    glBegin(GL_TRIANGLES);
    glVertex2f(p[0], p[1]); 
    glVertex2f(p[2], p[3]);
    glVertex2f(p[4], p[5]);
    glVertex2f(p[2], p[3]);
    glVertex2f(p[4], p[5]);
    glVertex2f(p[6], p[7]);
    glEnd();
}

int main() {
    if(!glfwInit()) {
        exit(EXIT_FAILURE);
    }
    GLFWwindow* window = glfwCreateWindow(600, 600, "car", NULL, NULL);

    if(!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glewInit();

    while(!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        // Draw
        GLfloat a[2] = {0.0f, 0.0f};
        GLfloat p[8] = {0.0f, 0.0f, 0.5f, 0.0f, 0.0f, 0.5f, 0.5f, 0.5f};
        drawCircle(a, 0.5f);
        drawRectangle(p);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
}