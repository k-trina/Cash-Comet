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

class Star: public Shape {
public:
	// Properties
	GLfloat r, g, b; // red, green, blue
	GLdouble radius; // radius
	int segments; // number of triangular pieces pieced together to create disk-shaped object to form coin. 100 by default

	// Methods
    Star();
    void draw();

};



#endif /* SRC_COIN_HPP_ */
