/*
 * Description: SimpleView reference design
 * Author: HBF (template), Rachel Andal
 * Version: 2022-10-03
 */
#ifndef CCUBE_H
#define CCUBE_H

#include <GL/glut.h>
#include "Shape.hpp"
#include "Vector.hpp"
#include "Light.hpp"
#include "Camera.hpp"

class Cube: public Shape {
protected:
	GLfloat vertex[8][3];  /* 2D array to store cube vertices */
	GLint face[6][4];      /* 2D array to store faces */
	GLfloat r, g, b;       /* color cube */

	// SimpleView 2 Components
	GLfloat faceColor[6][3], faceNormal[6][3], vertexColor[8][3],
			vertexNormal[8][3];
public:
	Cube();
	void draw();
	void drawFace(int);
	void changeColor(GLfloat, GLfloat, GLfloat); // added function to change color of object

	/* SimpleView2 properties */
	bool isFrontface(int faceindex, Camera camera);
	GLfloat getFaceShade(int faceindex, Light light);
	GLfloat getVertexShade(int vertexindex, Light light);
};

#endif
