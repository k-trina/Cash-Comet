/*
 * Coin.hpp
 *
 *  Created on: Nov 30, 2023
 *      Author: User
 */

#ifndef COIN_HPP_
#define COIN_HPP_


#include <GL/glut.h>
#include "Shape.hpp"
#include "Vector.hpp"
#include "Light.hpp"
#include "Camera.hpp"

class Coin: public Shape {
public:
	// Properties
	GLfloat r, g, b; // red, green, blue
	GLdouble radius; // radius
	int segments; // number of triangular pieces pieced together to create disk-shaped object to form coin. 100 by default
	//GLuint textureID;
	bool isInside(int xMouse, int yMouse);
	// Methods
	Coin(); // constructor of coin object
    virtual ~Coin();  // destructor
    void draw();  // declare draw as a virtual function
	//void changeColor(GLfloat, GLfloat, GLfloat); // added function to change color of object


};



#endif /* SRC_COIN_HPP_ */
