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

void drawRectangle(GLfloat p[], GLfloat l, GLfloat b) {
    glBegin(GL_LINE_STRIP);
    glVertex2f(p[0], p[1]);
    glVertex2f(p[0]+l, p[1]);
    glVertex2f(p[0]+l, p[1]+b);
    glVertex2f(p[0], p[1]+b);
    glVertex2f(p[0], p[1]);
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
        GLfloat c1[2] = {-0.4f, -0.7f};
        GLfloat c2[2] = {0.4f, -0.7f};
        drawCircle(c1, 0.3f);
        drawCircle(c2, 0.3f);
        
        GLfloat p[2] = {-0.7f, -0.55f};
        drawRectangle(p, 1.4f, 0.8f);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
}