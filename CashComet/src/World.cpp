#include "World.hpp"
#include "Sphere.hpp"
#include "Coin.hpp"
#include "Cube.hpp"

using namespace std;

World::World() {
	//Shape *obj = NULL;

    /* add Coins to the object list here */

//	Shape *obj = new Cube(); // test only
//	obj->setId(1);
//	objlist.push_back(obj);

	Shape *obj = new Coin();
	obj->setId(1);
	objlist.push_back(obj);
	obj->translate(0,0,0);

	Shape *obj2 = new Sphere(1.0);
	obj2->setId(2);
	objlist.push_back(obj2);
	obj2->translate(0,3,0);

//	glutWireTorus(0.2,0.8,16,16);

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
//	glColor3f(1.0, 0.0, 0.0);
//	lineSegment(-2, 0, 0, 4, 0, 0); /* x-axis in red */
// 	glColor3f(0.0, 1.0, 0.0);
//	lineSegment(0, -2, 0, 0, 4, 0); /* y-axis in green */
//	glColor3f(0.0, 0.0, 1.0);
//	lineSegment(0, 0, -2, 0, 0, 4); /* z-axis in blue */

	std::list<Shape*>::iterator it;
	for (it = objlist.begin(); it !=  objlist.end(); ++it) {
	  (*it)->draw();
    }
}

void World::reset(){
	//Shape *obj = NULL;


}

Shape* World::searchById(GLint i) {
	std::list<Shape*>::iterator it;
	for (it = objlist.begin(); it !=  objlist.end(); ++it) {
	  if ((*it)->getId() == i) return *it;
    }
	return NULL;
}

