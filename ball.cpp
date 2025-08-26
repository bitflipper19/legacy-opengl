#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>

void drawCircle(float x, float y, float radius) {
    int segments = 100;
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < segments; i++) {
        float theta = 2.0f * M_PI * float(i) / float(segments);
        float cx = radius * cosf(theta);
        float cy = radius * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}

int main() {
    if (!glfwInit()) return -1;

    GLFWwindow* window = glfwCreateWindow(600, 600, "Ball", NULL, NULL);
    if (!window) { glfwTerminate(); return -1; }

    glfwMakeContextCurrent(window);

    glfwSwapInterval(1);

    glewInit();

    float x = -0.9f, y = 0.0f;
    float dx = 0.005f, dy = 0.005f; 
    float r = 0.05f;

    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.1f, 0.1f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glColor3f(1.0f, 0.5f, 0.2f); 
        drawCircle(x, y, r);

        // update position
        x += dx;
        y += dy;

        // bounce off walls
        if (x + r > 1.0f || x - r < -1.0f) dx = -dx;
        if (y + r > 1.0f || y - r < -1.0f) dy = -dy;

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
