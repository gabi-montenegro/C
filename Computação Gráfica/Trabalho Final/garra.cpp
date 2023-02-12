#define _CRT_SECURE_NO_WARNINGS
#define PI 3.141592654

#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <glut.h>
#include "RgbImage.h"
#include <math.h>

using namespace std;

char filenameTexMetal1[20] = "./metalTexture1.bmp";

GLuint _textureIdMetal1;
GLuint _textureIdSphere;
GLuint _textureIdCylinder;
GLuint _textureIdEllipse;
GLUquadric* quadSphere;
GLUquadric* quadCylinder;
GLUquadric* quadEllipse;

bool textureOn = true;

float diameterCylinder = 0.3;
float diameterSphere = 0.4;
float sizeArm = 4.5;
float sizeForearm = 3.0;
float sizeHand = 2.0;
float sizeClampPart = 1.0;
float diameterBase = 2.0;
float heightBase = 0.5;

float eyeDistance = 20.0;
float eyeX;
float eyeY;
float eyeZ;
float viewAngleX = 0.0;
float viewAngleZ = 15.0;

float angleArm = 90.0;
float angleForearm = 90.0;
float angleHand = 0.0;
float angleClampZ = 0.0;
float angleClampY = 0.0;
float angleHead = 0.0;

//makes the image into a texture, and returns the id of the texture
GLuint loadTexture(char* filename) {
	GLuint textureId;

	RgbImage theTexMap(filename); //Image with texture

	glGenTextures(1, &textureId); //Make room for our texture
	glBindTexture(GL_TEXTURE_2D, textureId);	//Tell OpenGL which texture to edit
	//Map the image to the texture
	glTexImage2D(GL_TEXTURE_2D,	//Always GL_TEXTURE_2D
		0,						//0 for now
		GL_RGB,					//Format OpenGL uses for image
		theTexMap.GetNumCols(),	//Width 
		theTexMap.GetNumRows(),	//Height
		0,						//The border of the image
		GL_RGB,					//GL_RGB, because pixels are stored in RGB format
		GL_UNSIGNED_BYTE,		//GL_UNSIGNED_BYTE, because pixels are stored as unsigned numbers
		theTexMap.ImageData());	//The actual pixel data
	return textureId; //Returns the id of the texture
}

void initRendering(void) {
	quadSphere = gluNewQuadric();
	quadCylinder = gluNewQuadric();
	quadEllipse = gluNewQuadric();
	_textureIdMetal1 = loadTexture(filenameTexMetal1);
	_textureIdCylinder = _textureIdMetal1;
	_textureIdSphere = _textureIdMetal1;
	_textureIdEllipse = _textureIdMetal1;
}

void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {
	case 27: //Escape key
		exit(0);
	case 'w': //Increase view angle z axis
		if (viewAngleZ < 180) viewAngleZ += 3;
		glutPostRedisplay();
		break;
	case 'z': //Decrease view angle z axis
		if (viewAngleZ > 0) viewAngleZ -= 3;
		glutPostRedisplay();
		break;
	case 'a': //Decrease view angle x axis
		if (viewAngleX > 0) viewAngleX -= 3;
		glutPostRedisplay();
		break;
	case 's': //Increase view angle x axis
		if (viewAngleX < 180) viewAngleX += 3;
		glutPostRedisplay();
		break;
	case 't': //Use texture or not
		textureOn = !textureOn;
		glutPostRedisplay();
		break;
	case '1': //Increase arm angle
		angleArm += 3;
		if (angleArm >= 360) angleArm = 0;
		glutPostRedisplay();
		break;
	case '2': //Decrease arm angle
		angleArm -= 3;
		if (angleArm <= 0) angleArm = 360;
		glutPostRedisplay();
		break;
	case '3': //Increase forearm angle
		if (angleForearm < 90) angleForearm += 3;
		glutPostRedisplay();
		break;
	case '4': //Decrease forearm angle
		if (angleForearm > -90) angleForearm -= 3;
		glutPostRedisplay();
		break;
	case '5': //Increase clamp angle y axis
		if (angleClampY < 60) angleClampY += 3;
		glutPostRedisplay();
		break;
	case '6': //Decrease clamp angle y axis
		if (angleClampY > 0) angleClampY -= 3;
		glutPostRedisplay();
		break;
	}
}

void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (float)w / (float)h, 1.0, 50.0);
}

void drawCylinder(float diameter, float lenght) {
	if (textureOn) {
		glBindTexture(GL_TEXTURE_2D, _textureIdCylinder);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		gluQuadricTexture(quadCylinder, 1);
	}
	else
		gluQuadricTexture(quadCylinder, 0);
	gluCylinder(quadCylinder, diameter, diameter, lenght, 40.0, lenght * 30.0);
}

void drawCone(float diameter, float lenght) {
	if (textureOn) {
		glBindTexture(GL_TEXTURE_2D, _textureIdCylinder);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		gluQuadricTexture(quadCylinder, 1);
	}
	else
		gluQuadricTexture(quadCylinder, 0);
	gluCylinder(quadCylinder, diameter, 0, lenght, 40.0, lenght * 30.0);
}

void drawDisk(float diameterInner, float diameterOuter) {
	if (textureOn) {
		glBindTexture(GL_TEXTURE_2D, _textureIdCylinder);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		gluQuadricTexture(quadCylinder, 1);
	}
	else
		gluQuadricTexture(quadCylinder, 0);
	gluDisk(quadCylinder, diameterInner, diameterOuter, 40.0, 30.0);
}

void drawSphere(float diameter) {
	if (textureOn) {
		glBindTexture(GL_TEXTURE_2D, _textureIdSphere);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		gluQuadricTexture(quadSphere, 1);
	}
	else
		gluQuadricTexture(quadSphere, 0);
	gluSphere(quadSphere, diameter, 40.0, 40.0);
}

void drawEllipse(float diameterX, float diameterY) {
	if (textureOn) {
		glBindTexture(GL_TEXTURE_2D, _textureIdSphere);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		gluQuadricTexture(quadEllipse, 1);
	}
	else
		gluQuadricTexture(quadEllipse, 0);
	gluDisk(quadEllipse, diameterX, diameterY, 40, 30);
}

void drawScene(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_TEXTURE_2D);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	eyeX = eyeDistance * cos(viewAngleZ * PI / 180) * cos(viewAngleX * PI / 180);
	eyeY = eyeDistance * cos(viewAngleZ * PI / 180) * sin(viewAngleX * PI / 180);
	eyeZ = eyeDistance * sin(viewAngleZ * PI / 180);
	if (viewAngleZ < 90)
		gluLookAt(eyeX, eyeY, eyeZ, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
	else
		gluLookAt(eyeX, eyeY, eyeZ, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0);

	// drawing color
	glColor3f(1.0f, 1.0f, 1.0f);

	// draws the base
	drawCylinder(diameterBase, heightBase); // desenha cilindro base
	glTranslatef(0.0f, 0.0f, heightBase); // translação do cilindro base
	drawDisk(diameterCylinder, diameterBase); //disco que fica dentro do cilindro

	// move to arm referential
	glRotatef(angleArm, 0.0f, 0.0f, 1.0f); //angulo do braço em relação ao referencial (braço aberto)

	//draws the arm
	drawCylinder(diameterCylinder, sizeArm); //corpo do robo

	glPushMatrix();

	// move to forearm referential
	glTranslatef(0.0f, 0.0f, sizeArm + diameterSphere / 5); // translação do braço
	glRotatef(90, 0.0f, 1.0f, 0.0f); // rotação do braço aberto

	//draws the forearm
	drawSphere(diameterSphere); //coração do robô
	glTranslatef(0.0f, 0.0f, diameterSphere / 5); //translação do braço
	drawCylinder(diameterCylinder, sizeForearm); // antibraço do robô (somente cilindro)

	//move to clamp referential
	glTranslatef(0.0f, 0.0f, sizeForearm + diameterSphere / 5); // translação do pulso + mão
	glRotatef(angleClampZ, 0.0f, 0.0f, 1.0f); //rotação pulso + mão (mais pra mão)

	//draws the clamp sphere
	drawSphere(diameterSphere); // desenha pulso
	glTranslatef(0.0f, 0.0f, diameterSphere / 2); //translação da mão

	glPushMatrix(); //inserção

	//draws top part of clamp
	glRotatef(angleClampY + 60, 0.0f, 1.0f, 0.0f); //angulo dos dedos

	drawCylinder(diameterCylinder / 3, sizeClampPart); // cilindro 1 do dedo inferior 
	glTranslatef(0.0f, 0.0f, sizeClampPart + diameterSphere / 15); // translação dos dedos tirando a parte de cima
	drawSphere(diameterSphere / 3); // articulação 1 do dedo inferior

	glTranslatef(0.0f, 0.0f, diameterSphere / 15); // translação do cilindro 2 em diante do dedo inferior
	glRotatef(-60, 0.0f, 1.0f, 0.0f); // rotação da esfera em diante

	drawCylinder(diameterCylinder / 3, sizeClampPart); // cilindro 2 do dedo inferior
	glTranslatef(0.0f, 0.0f, sizeClampPart + diameterSphere / 15); //translação da ultima articulação (esfera) + cilindro 
	drawSphere(diameterSphere / 3); // esfera da mão (ultima articulação)

	//translação, rotação do cone
	glTranslatef(0.0f, 0.0f, diameterSphere / 15); // translação do ultimo cilindro (cone)
	glRotatef(-60, 0.0f, 1.0f, 0.0f); //rotação do cone
	drawCone(diameterCylinder / 3, sizeClampPart);

	glPopMatrix();
	glPushMatrix();

	//draws bottom part of clamp
	glRotatef(-angleClampY - 60, 0.0f, 1.0f, 0.0f);

	drawCylinder(diameterCylinder / 3, sizeClampPart);
	glTranslatef(0.0f, 0.0f, sizeClampPart + diameterSphere / 15);
	drawSphere(diameterSphere / 3);

	glTranslatef(0.0f, 0.0f, diameterSphere / 15);
	glRotatef(60, 0.0f, 1.0f, 0.0f);

	drawCylinder(diameterCylinder / 3, sizeClampPart);
	glTranslatef(0.0f, 0.0f, sizeClampPart + diameterSphere / 15);
	drawSphere(diameterSphere / 3);

	glTranslatef(0.0f, 0.0f, diameterSphere / 15);
	glRotatef(60, 0.0f, 1.0f, 0.0f);
	drawCone(diameterCylinder / 3, sizeClampPart);

	
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();

	//LADO ESQUERDO (BRAÇO E MÃO)

	//braço esquerdo
	//glTranslatef(0.0f, 0.0f, (diameterSphere / 5 - sizeArm) + 0.8); // translação do braço
	glTranslatef(0.0f, 0.0f, (diameterSphere / 5 + sizeArm));
	glRotatef(-90, 0.0f, 1.0f, 0.0f); // rotação do braço aberto

	//draws the forearm
	//drawSphere(diameterSphere); //coração do robô
	//glTranslatef(0.0f, 0.0f, diameterSphere / 5); //translação do braço
	drawCylinder(diameterCylinder, sizeForearm); // antibraço do robô (somente cilindro)

	//move to clamp referential
	glTranslatef(0.0f, 0.0f, sizeForearm + diameterSphere / 5); // translação do pulso 
	glRotatef(angleClampZ, 0.0f, 0.0f, 1.0f); //rotação pulso 

	//draws the clamp sphere
	drawSphere(diameterSphere); // desenha pulso

	//MAO...
	glTranslatef(0.0f, 0.0f, diameterSphere / 2); //translação da mão

	glPushMatrix(); //inserção

	//draws top part of clamp
	glRotatef(angleClampY + 60, 0.0f, 1.0f, 0.0f); //angulo dos dedos

	drawCylinder(diameterCylinder / 3, sizeClampPart); // cilindro 1 do dedo inferior 
	glTranslatef(0.0f, 0.0f, sizeClampPart + diameterSphere / 15); // translação dos dedos tirando a parte de cima
	drawSphere(diameterSphere / 3); // articulação 1 do dedo inferior

	glTranslatef(0.0f, 0.0f, diameterSphere / 15); // translação do cilindro 2 em diante do dedo inferior
	glRotatef(-60, 0.0f, 1.0f, 0.0f); // rotação da esfera em diante

	drawCylinder(diameterCylinder / 3, sizeClampPart); // cilindro 2 do dedo inferior
	glTranslatef(0.0f, 0.0f, sizeClampPart + diameterSphere / 15); //translação da ultima articulação (esfera) + cilindro 
	drawSphere(diameterSphere / 3); // esfera da mão (ultima articulação)

	//translação, rotação do cone
	glTranslatef(0.0f, 0.0f, diameterSphere / 15); // translação do ultimo cilindro (cone)
	glRotatef(-60, 0.0f, 1.0f, 0.0f); //rotação do cone
	drawCone(diameterCylinder / 3, sizeClampPart);

	glPopMatrix();

	//draws bottom part of clamp
	glRotatef(-angleClampY - 60, 0.0f, 1.0f, 0.0f);

	drawCylinder(diameterCylinder / 3, sizeClampPart);
	glTranslatef(0.0f, 0.0f, sizeClampPart + diameterSphere / 15);
	drawSphere(diameterSphere / 3);

	glTranslatef(0.0f, 0.0f, diameterSphere / 15);
	glRotatef(60, 0.0f, 1.0f, 0.0f);

	drawCylinder(diameterCylinder / 3, sizeClampPart);
	glTranslatef(0.0f, 0.0f, sizeClampPart + diameterSphere / 15);
	drawSphere(diameterSphere / 3);

	glTranslatef(0.0f, 0.0f, diameterSphere / 15);
	glRotatef(60, 0.0f, 1.0f, 0.0f);
	drawCone(diameterCylinder / 3, sizeClampPart);


	glPopMatrix();
	glPopMatrix();
	glPushMatrix();

	////PESCOÇO E CABEÇA
	glTranslatef(0.0f, 0.0f, (diameterSphere / 5 + sizeArm)); // translação do pescoço
	glRotatef(0, 0.0f, 1.0f, 0.0f); // rotação do braço aberto

	////draws the forearm
	////drawSphere(diameterSphere); //coração do robô
	////glTranslatef(0.0f, 0.0f, diameterSphere / 5); //translação do braço
	drawCylinder(diameterCylinder, 1); // pescoço

	//CABEÇA
	glPushMatrix();
	glTranslatef(0.0f, 0.f, 2); // translação cabeça
	glRotatef(angleHead, 0.0f, 0.0f, 1.0f); //rotação cabeça
	drawSphere(1.2);


	



	glPopMatrix();
	glPopMatrix();
	glutSwapBuffers();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Garra");

	initRendering();
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);

	glutMainLoop();
	return 0;
}