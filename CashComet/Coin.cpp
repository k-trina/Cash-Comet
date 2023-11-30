/*
 * coin.cpp
 *
 *  Created on: Nov 30, 2023
 *      Author: Rachel Andal
 */

# include "Coin.hpp"

Coin::Coin() {
	radius = 1.0;
	r=2;
	g=1;
	b=0;
	segments = 100;

}

Coin::~Coin() { };

void Coin::draw() {
    glPushMatrix();
    ctmMultiply();
    glColor3f(r,g,b);  // Yellow color for coin

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0, 0);  // Center of the disk
    for (int i = 0; i <= segments; ++i) {
        float angle = i * 2.0 * M_PI / segments;
        glVertex2f(radius * cos(angle), radius * sin(angle));
    }
    glEnd();
    glPopMatrix();
}

//void display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//    glColor3f(1.0, 1.0, 0.0);  // Yellow color for coin
//    draw(1.0, 100);
//    glutSwapBuffers();
//}

