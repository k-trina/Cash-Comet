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

//#include "pixmap/RGBpixmap.h"

#include "Menu.hpp"
#include "World.hpp"
#include "Camera.hpp"
#include "Light.hpp"
#include "UserInterface.hpp"

// Global variables
GLint winWidth = 800, winHeight = 800;
World myWorld;
Camera myCamera;
GLuint texture;
bool intro = true;
int userScore = 0;
//RGBpixmap pix[1]; /* pixmaps for textures */

// Concatenate the parent directory and the each audio file name
std::string bgMusicPath;
std::string coinAudioPath;
std::string bombAudioPath;

int w1 = 0; // coordinates for displaying background
int h1 = 0;

// MAY DELETE
//GLdouble modelview[16],projection[16];
//GLint viewport[4];
//GLdouble mouseX,mouseY,mouseZ;


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


void* playBGAudio(std::string filePath) { // unused at the moment due to lack of incompatibility with simultaneous audios
    PlaySound(filePath.c_str(), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    return NULL;
}

void playSEAudio(const char* filePath) {
    PlaySound(filePath, NULL, SND_FILENAME | SND_ASYNC);
}

void init(void) {
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);  // GLUT_DOUBLE for double frame buffer
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("CashComet!");
	glClearColor(1.0, 1.0, 1.0, 0.0); // Set display-window color to white
	glMatrixMode(GL_PROJECTION);

//	myCamera.set()

	// The following code is used to get the absolute path of the project folder and concatenate it with the audio file
    char buffer[MAX_PATH];
    GetModuleFileNameA(NULL, buffer, MAX_PATH);
    std::string executablePath(buffer);

    // Get the parent directory of the executable path
    std::string parentDirectory = getDirectory(executablePath);

    // Concatenate the parent directory and the each audio file name
    bgMusicPath = parentDirectory + "\\LL - Puzzle.wav";
    coinAudioPath = parentDirectory + "\\Coin.wav";
    bombAudioPath = parentDirectory + "\\Bomb.wav";

    // Play the sound using the absolute path

   //PlaySound(bgMusicPath.c_str(), NULL, SND_FILENAME | SND_ASYNC); // Plays the background music. UNCOMMENT TO HEAR MUSIC



	//PlaySound(TEXT("D:\\Temporary school data\\CP411\\cp411_software\\cp411_software\\cp411\\workspace\\CashComet\\LL - Puzzle.wav"), NULL, SND_FILENAME | SND_ASYNC);
	//PlaySound(TEXT("Puzzle.wav"), NULL, SND_FILENAME | SND_ASYNC);

	gluOrtho2D(0.0, winWidth, winHeight, 0.0); // set top left as origin

//	pix[0].readBMPFile("Background.bmp"); // doesn't work, but program still runs
//	pix[0].setTexture(0);

    //std::string bgMusicPath = "path_to_your_audio_file.wav";  // Replace with your audio file path

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

GLuint LoadTexture()
{
    unsigned char data[] = { 255,0,0, 0,255,0, 0,0,255, 255,255,255 };

    glGenTextures( 1, &texture);
    glBindTexture( GL_TEXTURE_2D, texture );
    glPixelStorei( GL_UNPACK_ALIGNMENT, 1 );
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );

    //even better quality, but this will do for now.
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_NEAREST);

    //to the edge of our shape.
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );

    //Generate the texture
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 2, 2, 0,GL_RGB, GL_UNSIGNED_BYTE, data);
    return texture; //return whether it was successful
}


void background()
{
    glBindTexture(GL_TEXTURE_2D, texture);

//    orthogonalStart();

    // texture width/height
    const int iw = 500;
    const int ih = 500;

    glPushMatrix();
    glTranslatef( -iw/2, -ih/2, 0 );
    glBegin(GL_QUADS);
	glTexCoord2i(0,0); glVertex2i(0, 0);
	glTexCoord2i(1,0); glVertex2i(iw, 0);
	glTexCoord2i(1,1); glVertex2i(iw, ih);
	glTexCoord2i(0,1); glVertex2i(0, ih);
    glEnd();
    glPopMatrix();

//    orthogonalEnd();
}


void mouseActionFcn(int button, int state, int xMouse, int yMouse) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		printf("Test\n");

	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		int coinOrBomb;
		printf("X: %d Y: %d\n",xMouse,yMouse);
		coinOrBomb = myWorld.findMatch(xMouse,yMouse);
		//PlaySound(coinAudioPath.c_str(), NULL, SND_FILENAME | SND_ASYNC);
		if (coinOrBomb == 1){
			PlaySound(coinAudioPath.c_str(), NULL, SND_FILENAME | SND_ASYNC);
			userScore += 300;
			printf("Coin clicked! User score: %d\n",userScore);
		} else if (coinOrBomb == 2){
			PlaySound(bombAudioPath.c_str(), NULL, SND_FILENAME | SND_ASYNC);
			userScore -= 600;
			if (userScore < 0) // clicking on bombs does not allow user score to go below 0
				userScore = 0;
			printf("BOOM! Clicked a bomb. User score: %d\n",userScore);
		}
//		PlaySound(coinAudioPath.c_str(), NULL, SND_FILENAME | SND_ASYNC); // Plays the background music. UNCOMMENT TO HEAR MUSIC

	}

//	if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP) { // TESTING SOUND EFFECTS ONLY
//		//isInMove = 0;
//		//printf("Test 2.\n");
//		printf("Boom!\n");
//		//PlaySound(bombAudioPath.c_str(), NULL, SND_FILENAME | SND_ASYNC); // Plays the background music. UNCOMMENT TO HEAR MUSIC
//		PlaySound(bombAudioPath.c_str(), NULL, SND_FILENAME | SND_ASYNC);
//
//	}

}

void movement(){
	myWorld.falling();
}

void startGame(){
	glutIdleFunc(movement);

}

void displayIntro(void) {
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	myCamera.setProjectionMatrix();
//	myWorld.draw();
//
//    glLoadIdentity();
//    glEnable(GL_TEXTURE_2D);
//
//    background();
////    gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
//
//
//	glFlush();
//	glutSwapBuffers();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	message("Click Anywhere To Start!",300,winHeight/2);
	gameCountDown();


	glFlush();
	glutPostRedisplay();
	glutSwapBuffers();
}

void display(void) {
	if (intro == true) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//	message("Click Anywhere To Start!",300,winHeight/2);
		gameCountDown();


		glFlush();
		glutPostRedisplay();
		glutSwapBuffers();
		intro = false;
	} else {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		myCamera.setProjectionMatrix();
		myWorld.draw();

	    glLoadIdentity();
	    glEnable(GL_TEXTURE_2D);

	    background();
	//    gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);


		glFlush();
		glutSwapBuffers();
	}

}

void winReshapeFcn(GLint newWidth, GLint newHeight) {
	glViewport(0, 0, newWidth, newHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	winWidth = newWidth;
	winHeight = newHeight;
}

void timerCallback(int value) {
    glutDisplayFunc(display);  // Set the display function after the timer expires
    glutPostRedisplay();       // Trigger a redisplay
}

int main(int argc, char** argv) {
	setvbuf(stdout, NULL, _IONBF, 0); // For Eclipse stdout debugging
	setvbuf(stderr, NULL, _IONBF, 0);
	glutInit(&argc, argv);

	init();
	glutDisplayFunc(displayIntro);
	// pause for 3 seconds before game starts

	glutTimerFunc(3000,timerCallback, 0);

//	glutReshapeFunc(winReshapeFcn);
	glutMouseFunc(mouseActionFcn); // For detecting mouse clicks
	startGame();
	glutMainLoop();
	return 0;
}
