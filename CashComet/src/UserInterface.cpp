#include "UserInterface.hpp"
#include <stdio.h>
#include <time.h>
#

void message(char str[], GLint x, GLint y) {
	glColor3f(0.0, 0.0, 0.0);
	glRasterPos2i(x, y);
	int i = 0;
	while (str[i]) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]);
		i++;
	}
}

void gameCountDown() {
	clock_t begin;
	double time_spent;
	int i;
	char line[5];
	/* Mark beginning time */
	begin = clock();
	int countdown = 3;
	for (i = 0; i < 4; i++) {
//		printf("hello\n");
		/* Get CPU time since loop started */

		time_spent = (double) (clock() - begin) / CLOCKS_PER_SEC;
//		glClear(GL_COLOR_BUFFER_BIT);

		if (time_spent - (int) time_spent == 0.0) {
			if (countdown == 0) {
				message("Go!", 200 + i * 50, 400);
				break;
			} else {
				sprintf(line, "%d", countdown);
				message(line, 200 + i * 50, 400);
				countdown--;
			}
			while (clock() < time_spent + 1000)
				;
		}

		// looping till required time is not achieved

	}
}
