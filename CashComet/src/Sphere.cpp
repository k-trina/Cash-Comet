#include "Sphere.hpp"

extern RenderMode renderMode;

Sphere::Sphere(GLdouble size) {
	radius = size;
	splices = 50;
	stacks = 50;
	textureID = 0;
	r=0;
	g=0;
	b=0;
	quad = gluNewQuadric();
}


void Sphere::setTextureID(GLuint id){
	textureID = id;
}

void Sphere::draw() {
	glPushMatrix();
	ctmMultiply();

	glColor3f(r, g, b);
	glutSolidSphere(radius, splices, stacks);

	//glRotatef(rotation, 0.0, 1.0, 0.0);


//	switch (renderMode) {
//	case WIRE:
//		glColor3f(r, g, b);
//		glutWireSphere(radius, splices, stacks);
//		break;
//	case CONSTANT:
//		glColor3f(r, g, b);
//		glutSolidSphere(radius, splices, stacks);
//		break;
//	case FLAT:
//		glColor3f(r, g, b);
//		glutSolidSphere(radius, splices, stacks);
//		break;
//	case SMOOTH:
//		glColor3f(r, g, b);
//		glutSolidSphere(radius, splices, stacks);
//		break;
//
//	case TEXTURE:
//		gluQuadricTexture(this->quad, GL_TRUE);
//		gluQuadricOrientation(this->quad, GLU_OUTSIDE);
//		gluQuadricNormals(this->quad, GLU_SMOOTH);
//		glEnable(GL_TEXTURE_2D);
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//		glBindTexture(GL_TEXTURE_2D, textureID);
//		gluSphere(quad, radius, splices, stacks);
//		glDisable(GL_TEXTURE_2D);
//		break;
//	}

//	case PHONG:
//		// your code
//		break;
//	}

	glPopMatrix();
}


