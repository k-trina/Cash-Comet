#include "Sphere.hpp"
#include "Star.hpp"

// extern RenderMode renderMode;

Sphere::Sphere(GLdouble size) {
    radius = size;
    splices = 50;
    stacks = 50;
    textureID = 0;
    r = 0.2;  // Dark gray
    g = 0.2;
    b = 0.4;
    //fuseHeight = 0.2;  // Height of the fuse cylinder
    quad = gluNewQuadric();


}



void Sphere::setTextureID(GLuint id) {
    textureID = id;
}

void Sphere::draw() { // this function simulates shading through gradient computation, but doesn't use openGL lighting
    glPushMatrix();
    ctmMultiply();

    glBegin(GL_QUADS);

    for (int i = 0; i < stacks; ++i) {
        for (int j = 0; j < splices; ++j) {
            // Compute angles for each vertex
            float theta1 = (float)i / stacks * M_PI;
            float theta2 = (float)(i + 1) / stacks * M_PI;
            float phi1 = (float)j / splices * 2.0 * M_PI;
            float phi2 = (float)(j + 1) / splices * 2.0 * M_PI;

            // Compute vertex positions for the sphere
            float x1 = radius * sin(theta1) * cos(phi1);
            float y1 = radius * cos(theta1);
            float z1 = radius * sin(theta1) * sin(phi1);

            float x2 = radius * sin(theta2) * cos(phi1);
            float y2 = radius * cos(theta2);
            float z2 = radius * sin(theta2) * sin(phi1);

            float x3 = radius * sin(theta1) * cos(phi2);
            float y3 = radius * cos(theta1);
            float z3 = radius * sin(theta1) * sin(phi2);

            float x4 = radius * sin(theta2) * cos(phi2);
            float y4 = radius * cos(theta2);
            float z4 = radius * sin(theta2) * sin(phi2);

            // Compute color intensity based on y-coordinate
            float intensity1 = 1.0 - (y1 / radius);
            float intensity2 = 1.0 - (y2 / radius);
            float intensity3 = 1.0 - (y3 / radius);
            float intensity4 = 1.0 - (y4 / radius);

            // Set color for each vertex of the sphere
            glColor3f(r * intensity1, g * intensity1, b * intensity1);
            glVertex3f(x1, y1, z1);

            glColor3f(r * intensity2, g * intensity2, b * intensity2);
            glVertex3f(x2, y2, z2);

            glColor3f(r * intensity4, g * intensity4, b * intensity4);
            glVertex3f(x4, y4, z4);

            glColor3f(r * intensity3, g * intensity3, b * intensity3);
            glVertex3f(x3, y3, z3);
        }
    }

    // Draw the fuse (cylinder) on top of the sphere
    glColor3f(0.6, 0.3, 0.1);  // Brown color

    // Draw a rectangle
    glBegin(GL_QUADS);
    glVertex3f(0.15, 0.3, 0.1);
    glVertex3f(0.3, 0.3, 0.1);
    glVertex3f(0.3, 0.6, 0.1);
    glVertex3f(0.2, 0.6, 0.1);


//	int segments = 100;
//	for (int i = 0; i <= segments; ++i) {
//		float angle = i * 2.0 * M_PI / segments;
//
//		// Modify the radius to add some convexity
//		float modifiedRadius = 0.1 + 0.2 * sin(angle * 5.0);
//
//		// Use a gradient color to simulate shading
//		float shade = 0.5 + 0.5 * cos(angle);
//		glColor3f(2 * shade, 1 * shade, 0 * shade);
//
//		glVertex2f(modifiedRadius * cos(angle), modifiedRadius * sin(angle));
//	}

//    glEnd();

//    for (int i = 0; i < splices; ++i) {
//        float theta = (float)stacks / stacks * M_PI;
//        float phi1 = (float)i / splices * 2.0 * M_PI;
//        float phi2 = (float)(i + 1) / splices * 2.0 * M_PI;
//
//        // Compute vertex positions for the fuse rectangle
//        float x1 = 0.0;
//        float y1 = radius * cos(theta);
//        float z1 = radius * sin(theta);
//
//        float x2 = fuseHeight * sin(phi1);
//        float y2 = y1 + fuseHeight * cos(phi1);
//        float z2 = radius * sin(theta) + fuseHeight * sin(phi1);
//
//        float x3 = fuseHeight * sin(phi2);
//        float y3 = y1 + fuseHeight * cos(phi2);
//        float z3 = radius * sin(theta) + fuseHeight * sin(phi2);

        // Set color for each vertex of the fuse
//        glColor3f(0.4, 0.4, 0.4);  // Light gray for the fuse
//        glVertex3f(x1, y1, z1);
//        glVertex3f(x2, y2, z2);
//        glVertex3f(x3, y3, z3);
//        glVertex3f(0.0, y1 + fuseHeight, radius * sin(theta));


//    }

    glEnd();
	Shape *spark = new Star();
	spark->draw();
//	spark->translate(0.225, 0.6, 0.1);
    glPopMatrix();



}

//    glPopMatrix();
//}

//void Sphere::draw() {
//    glPushMatrix();
//    ctmMultiply();
//
//    // Enable lighting
//    glEnable(GL_LIGHTING);
//
//    // Set material properties
//    GLfloat ambient[] = { r * 0.3, g * 0.3, b * 0.3, 1.0 };
//    GLfloat diffuse[] = { r, g, b, 1.0 };
//    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
//    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
//
//    // Set up a simple directional light
//    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 }; // Directional light from the top-right
//    GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 }; // White light
//    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
//    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
//    glEnable(GL_LIGHT0);
//
//    // Draw the shaded bomb
//    glutSolidSphere(radius, splices, stacks);
//
//    // Disable lighting for other objects if needed
//    glDisable(GL_LIGHTING);
//
//    glPopMatrix();
//}



//
//Sphere::Sphere(GLdouble size) {
//	radius = size;
//	splices = 50;
//	stacks = 50;
//	textureID = 0;
//	r=0;
//	g=0;
//	b=0;
//	quad = gluNewQuadric();
//}
//
//
//void Sphere::setTextureID(GLuint id){
//	textureID = id;
//}
//
//void Sphere::draw() {
//	glPushMatrix();
//	ctmMultiply();
//
//	glColor3f(r, g, b);
//	glutSolidSphere(radius, splices, stacks);
//
//	//glRotatef(rotation, 0.0, 1.0, 0.0);
//
//
////	switch (renderMode) {
////	case WIRE:
////		glColor3f(r, g, b);
////		glutWireSphere(radius, splices, stacks);
////		break;
////	case CONSTANT:
////		glColor3f(r, g, b);
////		glutSolidSphere(radius, splices, stacks);
////		break;
////	case FLAT:
////		glColor3f(r, g, b);
////		glutSolidSphere(radius, splices, stacks);
////		break;
////	case SMOOTH:
////		glColor3f(r, g, b);
////		glutSolidSphere(radius, splices, stacks);
////		break;
////
////	case TEXTURE:
////		gluQuadricTexture(this->quad, GL_TRUE);
////		gluQuadricOrientation(this->quad, GLU_OUTSIDE);
////		gluQuadricNormals(this->quad, GLU_SMOOTH);
////		glEnable(GL_TEXTURE_2D);
////		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
////		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
////		glBindTexture(GL_TEXTURE_2D, textureID);
////		gluSphere(quad, radius, splices, stacks);
////		glDisable(GL_TEXTURE_2D);
////		break;
////	}
//
////	case PHONG:
////		// your code
////		break;
////	}
//
//	glPopMatrix();
//}
//
//
