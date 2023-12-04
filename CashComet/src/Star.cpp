/*
 * coin.cpp
 *
 *  Created on: Nov 30, 2023
 *      Author: Rachel Andal
 */

# include "Star.hpp"

Star::Star() {
	radius = 0.1;
	r=2;
	g=1;
	b=0;
	segments = 100;

}

void Star::draw() {

	// The below code generates a star shape. It was unintentionally created when experimenting.
	glPushMatrix();
	ctmMultiply();
	glColor3f(r, g, b);  // Yellow color for coin

	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(0, 0);  // Center of the disk

	for (int i = 0; i <= segments; ++i) {
		float angle = i * 2.0 * M_PI / segments;

		// Modify the radius to add some convexity
		float modifiedRadius = radius + 0.2 * sin(angle * 5.0);

		// Use a gradient color to simulate shading
		float shade = 0.5 + 0.5 * cos(angle);
		glColor3f(r * shade, g * shade, b * shade);

		glVertex2f(modifiedRadius * cos(angle), modifiedRadius * sin(angle));
	}

	glEnd();
	glPopMatrix();
}


