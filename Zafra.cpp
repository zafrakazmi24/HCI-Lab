#include <iostream>
#include <GL/glut.h>// library to open window
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

float CarX=0.0f; // car X is the global variable here speed 
void specialkeys(int key,int x,int y) // this fuction used to process arrow key
{
	switch (key) {
        case GLUT_KEY_LEFT: // move the car left
            CarX -= 0.1f; // - used to move left
            break;
        case GLUT_KEY_RIGHT: // move the car right
            CarX += 0.1f; // + used to move right
            break;
	}
	glutPostRedisplay(); // used to refresh screen so that we see the movement of screen
}
void drawCar() // car ko draw krny k liye
{
    glColor3f(1.0f , 0.0f , 0.0f); // show the red color
    glBegin(GL_QUADS); // POINTS dyna ha taky 4 vertices mil kr rectangle bnay
    glVertex2f(CarX -0.2f , -0.2f);
    glVertex2f(CarX +0.2f , -0.2f);
    glVertex2f(CarX +0.2f , 0.2f);
    glVertex2f(CarX -0.2f , 0.2f);
    glEnd(); // yh btata ha k shape complete hogya ha
// wheel add krny hain
    glColor3f(0.0f,0.0f,0.0f); //  black color wheels
    glBegin(GL_QUADS); // first wheel
    glVertex2f(CarX -0.15f , -0.25f);
    glVertex2f(CarX -0.05f , -0.25f);
    glVertex2f(CarX -0.05f , -0.2f);
    glVertex2f(CarX -0.15f , -0.2f);
    glEnd();
    glBegin(GL_QUADS); // second wheel
    glVertex2f(CarX +0.15f , -0.25f);
    glVertex2f(CarX +0.05f , -0.25f);
    glVertex2f(CarX +0.05f , -0.2f);
    glVertex2f(CarX +0.15f , -0.2f);
    glEnd();
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT); //TO CLEAR OLD SCREEN
	glLoadIdentity();
	drawCar();
	glFlush(); //to show the drawing on the screen
}
void init()
{
	glClearColor(0.8f,0.8f,1.0f,1.0f); //change the bg color to sky blue
	glMatrixMode(GL_PROJECTION); // tell that the screen is 2D mode or 3D mode
	glLoadIdentity();
}
int main(int argc, char** argv) {
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); // screen aik hi hogi or rgb color hoga
	glutInitWindowSize(500,500); // setting the size of the window
	glutInitWindowPosition(100,100); // setting the position of the window
	glutCreateWindow("My OpenGL Window"); // name of the screen
	init();
	
	glutDisplayFunc(display);
	glutSpecialFunc(specialkeys);
	glutMainLoop();
	
	return 0;
}