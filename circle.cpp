#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>

void drawCircle(float x, float y, float radius) {
    int segments = 100;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); 
    for (int i = 0; i <= segments; i++) {
        float theta = 2.0f * M_PI * float(i) / float(segments);
        float cx = radius * cosf(theta);
        float cy = radius * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}

int main() {
    if (!glfwInit()) return -1;

    GLFWwindow* window = glfwCreateWindow(600, 600, "circle", NULL, NULL);
    if (!window) { glfwTerminate(); return -1; }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    glewInit();

    float baseRadius = 0.2f;   
    float amplitude  = 0.05f;  
    float speed      = 2.0f;   

    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.1f, 0.1f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        float time = (float)glfwGetTime();
        float r = baseRadius + amplitude * sin(speed * time);

        glColor3f(1.0f, 0.5f, 0.2f);
        drawCircle(0.0f, 0.0f, r);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
