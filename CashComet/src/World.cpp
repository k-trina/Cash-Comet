#include "World.hpp"
#include "Sphere.hpp"
#include "Coin.hpp"
#include "Cube.hpp"
#include <stdio.h>
using namespace std;

World::World() {

	// must be a small negative number
	speed = -0.025;

    /* add Coins to the object list here */
	numOfCoins=10;
	srand(time(NULL));
	float random_float;
	Shape *obj;
	for(int i=0;i<numOfCoins;i++){
		random_float  = ((float)rand() / RAND_MAX) * 10 - 5;
		obj = new Coin();
		obj->CoinOrBomb =1;
		objlist.push_back(obj);
		obj->translate(5,random_float,0);

	}


	// Add bombs
	numOfBombs = 3;
	for(int i=0;i<numOfBombs;i++){
		random_float  = ((float)rand() / RAND_MAX) * 10 - 5;
		obj = new Sphere(0.5);
		obj->CoinOrBomb =2;
		objlist.push_back(obj);
		obj->translate(5,random_float,0);
	}


}

World::~World(){
	Shape *obj;
	while (!objlist.empty()) {
		obj = objlist.front();
		objlist.pop_front();
		free(obj);
	}
}

void lineSegment(float x1, float y1, float z1, float x2, float y2, float z2) {
	glBegin(GL_LINES);
	glVertex3f(x1, y1, z1);
	glVertex3f(x2, y2, z2);
	glEnd();
}

void World::draw() {
	glColor3f(1.0, 0.0, 0.0);
	lineSegment(-2, 0, 0, 4, 0, 0); /* x-axis in red */
 	glColor3f(0.0, 1.0, 0.0);
	lineSegment(0, -2, 0, 0, 4, 0); /* y-axis in green */
	glColor3f(0.0, 0.0, 1.0);
	lineSegment(0, 0, -2, 0, 0, 4); /* z-axis in blue */

	std::list<Shape*>::iterator it;
	for (it = objlist.begin(); it !=  objlist.end(); ++it) {
	  (*it)->draw();
    }
}

void World::reset(){


}

void World::resetObj(Shape* it){
	(*it).reset();
	float random_float = ((float)rand() / RAND_MAX) * 10 - 5;
	(*it).translate(6,random_float,0);
}

// Will iterator through object list and return if a object is clicked
// 1 = Coin is clicked 2 = bomb is clicked
int World::findMatch(int xMouse,int yMouse) {
	std::list<Shape*>::iterator it;
	for (it = objlist.begin(); it !=  objlist.end(); ++it) {

	  if ((*it)->isInside(xMouse,yMouse)){
		  resetObj(*it);
		  if ((*it)->CoinOrBomb == 1){
			  return 1;
		  }else{
			  return 2;
		  }
	  }
    }
	return 0;
}

Shape* World::searchById(GLint i) {
	std::list<Shape*>::iterator it;
	for (it = objlist.begin(); it !=  objlist.end(); ++it) {
	  if ((*it)->getId() == i) return *it;
    }
	return NULL;
}

void World::falling(){
	std::list<Shape*>::iterator it;
	for (it = objlist.begin(); it !=  objlist.end(); ++it) {

	  (*it)->translate(speed,0,0);
	  if ((*it)->getMC().mat[0][3] <= -5.5){
		  resetObj(*it);
	  }
	}
	glutPostRedisplay();

}
