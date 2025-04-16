#include <iostream>
#include <GL/glut.h> 
#include <cmath>

void drawCircle(float cx, float cy, float r, int num_segments = 100) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy); // Center
    for (int i = 0; i <= num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the screen
    glClearColor(0.529f, 0.808f, 0.922f, 1.0f); // Light blue background
// House base
    glColor3f(1.0f, 0.878f, 0.741f);// white color
    glBegin(GL_POLYGON);
    glVertex2f( 100 , 100);
    glVertex2f( 300 , 100);
    glVertex2f( 300 , 250);
    glVertex2f( 100 , 250);
    glEnd(); // yh btata ha k shape complete hogya ha
    
// roof 
        glColor3f(0.6f, 0.0f, 0.0f); // Dark red 
        glBegin(GL_TRIANGLES);
        glVertex2f(90, 250);
        glVertex2f(310, 250);
        glVertex2f(200, 350);
    glEnd();

       glColor3f(0.5f, 0.5f, 0.5f); // grey
        glBegin(GL_POLYGON);
        glVertex2f(180, 100);
        glVertex2f(220, 100);
        glVertex2f(220, 180);
        glVertex2f(180, 180);
    glEnd();

// windows
  glColor3f(0.7f, 0.9f, 1.0f); // Light blue windows

    // Left window
    glBegin(GL_POLYGON);
        glVertex2f(120, 180);
        glVertex2f(150, 180);
        glVertex2f(150, 210);
        glVertex2f(120, 210);
    glEnd();

    // Right window
    glBegin(GL_POLYGON);
        glVertex2f(250, 180);
        glVertex2f(280, 180);
        glVertex2f(280, 210);
        glVertex2f(250, 210);
    glEnd();
// Draw clouds (white color)
glColor3f(1.0f, 1.0f, 1.0f);

// Cloud 1
drawCircle(80, 350, 20);
drawCircle(100, 360, 25);
drawCircle(130, 350, 20);

// Cloud 2
drawCircle(250, 370, 18);
drawCircle(270, 380, 22);
drawCircle(290, 370, 18);

 // Draw the sun (yellow)
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow color for the sun
    drawCircle(350, 350, 40); // Sun at position (350, 350) with radius 40
    
    
    
    glFlush(); // refresh the screen
}
void init() {
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 400, 0, 400); // Set coordinate system for 2D drawing
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500); // Window size
    glutInitWindowPosition(100, 100); // Window position
    glutCreateWindow("Simple House - OpenGL");

    init();
    glutDisplayFunc(display);
    glutMainLoop(); // Enter event-processing loop
	return 0;
}