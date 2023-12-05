
#ifndef CWORLD_HPP
#define CWORLD_HPP

#include <iostream>
#include <list>
#include <vector>
#include "Shape.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class World {

public:
	std::list<Shape*> objlist;
	float speed;
	World();
	~World();
	void draw();   /* draw all objects in the world */
	void reset();  /* resets all objects */
	Shape *searchById(GLint i);
	int findMatch(int xMouse,int yMouse);
	void falling();
	void resetObj(Shape* it);
	int numOfCoins;
	int numOfBombs;
};

#endif
