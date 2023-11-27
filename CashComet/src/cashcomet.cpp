/*
 * cashcomet.cpp
 *
 *  Created on: Nov 27, 2023
 *      Author: Mohamad EL mansour, Katrina Co, Rachel Andal
 */

#include <stdio.h>

#include "Menu.hpp"
#include "World.hpp"
#include "Camera.hpp"
#include "Light.hpp"

GLint winWidth = 800, winHeight = 800;


void init(void) {
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);  // GLUT_DOUBLE for double frame buffer
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("CashComet!");
	glClearColor(1.0, 1.0, 1.0, 0.0); // Set display-window color to white
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, winWidth, winHeight, 0.0); // set top left as origin
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	glFlush();
	glutSwapBuffers();
}


int main(int argc, char** argv) {
	setvbuf(stdout, NULL, _IONBF, 0); // For Eclipse stdout debugging
	setvbuf(stderr, NULL, _IONBF, 0);
	glutInit(&argc, argv);

	init();
	glutDisplayFunc(display);
//	glutReshapeFunc(winReshapeFcn);
	glutMainLoop();
	return 0;
}
