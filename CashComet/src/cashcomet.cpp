/*
 * cashcomet.cpp
 *
 *  Created on: Nov 27, 2023
 *      Author: Mohamad EL mansour, Katrina Co, Rachel Andal
 */

#include <stdio.h>
#include <gl/glut.h>
#include <windows.h> // for playing sound
#include <mmsystem.h>

#include "pixmap/RGBpixmap.h"

#include "Menu.hpp"
#include "World.hpp"
#include "Camera.hpp"
#include "Light.hpp"

// Global variables
GLint winWidth = 800, winHeight = 800;
World myWorld;
Camera myCamera;
GLuint texture;
RGBpixmap pix[1]; /* pixmaps for textures */

int w1 = 0; // coordinates for displaying background
int h1 = 0;


// Function to get the absolute path of the executable
std::string getExecutablePath() {
    char buffer[MAX_PATH];
    GetModuleFileNameA(NULL, buffer, MAX_PATH);
    return std::string(buffer);
}


// Function to get the directory part of a path
std::string getDirectory(const std::string& path) {
    size_t found = path.find_last_of("/\\");
    if (found != std::string::npos) {
        size_t secondLastFound = path.find_last_of("/\\", found - 1);
        if (secondLastFound != std::string::npos) {
            return path.substr(0, secondLastFound);
        }
    }
    return "";
}

void init(void) {
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);  // GLUT_DOUBLE for double frame buffer
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("CashComet!");
	glClearColor(1.0, 1.0, 1.0, 0.0); // Set display-window color to white
	glMatrixMode(GL_PROJECTION);

	// The following code is used to get the absolute path of the project folder and concatenate it with the audio file
    char buffer[MAX_PATH];
    GetModuleFileNameA(NULL, buffer, MAX_PATH);
    std::string executablePath(buffer);

    // Get the parent directory of the executable path
    std::string parentDirectory = getDirectory(executablePath);

    // Concatenate the parent directory and the file name
    std::string filePath = parentDirectory + "\\LL - Puzzle.wav";

    // Play the sound using the absolute path
    PlaySound(filePath.c_str(), NULL, SND_FILENAME | SND_ASYNC); // Plays the background music


	//PlaySound(TEXT("D:\\Temporary school data\\CP411\\cp411_software\\cp411_software\\cp411\\workspace\\CashComet\\LL - Puzzle.wav"), NULL, SND_FILENAME | SND_ASYNC);
	//PlaySound(TEXT("Puzzle.wav"), NULL, SND_FILENAME | SND_ASYNC);

//	gluOrtho2D(0.0, winWidth, winHeight, 0.0); // set top left as origin

//	pix[0].readBMPFile("Background.bmp"); // doesn't work, but program still runs
//	pix[0].setTexture(0);
}

//void orthogonalStart()
//{
//    glMatrixMode(GL_PROJECTION);
//    glPushMatrix();
//    glLoadIdentity();
//    gluOrtho2D(-w1/2, w1/2, -h1/2, h1/2);
//    glMatrixMode(GL_MODELVIEW);
//}
//
//void orthogonalEnd()
//{
//    glMatrixMode(GL_PROJECTION);
//    glPopMatrix();
//    glMatrixMode(GL_MODELVIEW);
//}
//
//GLuint LoadTexture()
//{
//    unsigned char data[] = { 255,0,0, 0,255,0, 0,0,255, 255,255,255 };
//
//    glGenTextures( 1, &texture);
//    glBindTexture( GL_TEXTURE_2D, texture );
//    glPixelStorei( GL_UNPACK_ALIGNMENT, 1 );
//    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
//
//    //even better quality, but this will do for now.
//    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_NEAREST);
//    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_NEAREST);
//
//    //to the edge of our shape.
//    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
//    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
//
//    //Generate the texture
//    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 2, 2, 0,GL_RGB, GL_UNSIGNED_BYTE, data);
//    return texture; //return whether it was successful
//}
//
//
//void background()
//{
//    glBindTexture(GL_TEXTURE_2D, texture);
//
//    orthogonalStart();
//
//    // texture width/height
//    const int iw = 500;
//    const int ih = 500;
//
//    glPushMatrix();
//    glTranslatef( -iw/2, -ih/2, 0 );
//    glBegin(GL_QUADS);
//	glTexCoord2i(0,0); glVertex2i(0, 0);
//	glTexCoord2i(1,0); glVertex2i(iw, 0);
//	glTexCoord2i(1,1); glVertex2i(iw, ih);
//	glTexCoord2i(0,1); glVertex2i(0, ih);
//    glEnd();
//    glPopMatrix();
//
//    orthogonalEnd();
//}



void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	myCamera.setProjectionMatrix();
	myWorld.draw();

    glLoadIdentity();
    glEnable(GL_TEXTURE_2D);

//    background();
    //gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);


	glFlush();
	glutSwapBuffers();
}

void winReshapeFcn(GLint newWidth, GLint newHeight) {
	glViewport(0, 0, newWidth, newHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	winWidth = newWidth;
	winHeight = newHeight;
}

int main(int argc, char** argv) {
	setvbuf(stdout, NULL, _IONBF, 0); // For Eclipse stdout debugging
	setvbuf(stderr, NULL, _IONBF, 0);
	glutInit(&argc, argv);

	init();
	glutDisplayFunc(display);
//	glutReshapeFunc(winReshapeFcn);
	glutMainLoop();
	return 0;
}
