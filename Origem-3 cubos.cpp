#include <GL/glut.h>

GLfloat tamanho = 0;
GLfloat posx = 0;
GLfloat rot = 0;
GLfloat posCubo = 0;
GLfloat sentido = 1;
void desenha(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//limpar fundo
	glLineWidth(1.0);//espessura da linha
	glPushMatrix();//grava transformação da matriz
	glTranslatef(posx, 0, 0);//andar com o desenho(x,y,z)
	glRotatef(45, 0, 0, 1);//girar o desenho(graus,eixo(x,y,z))
	
	glTranslatef(0, -1, 0);
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(-1.0, 1.0);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(1.0, 1.0);
	glColor3f(1.0, 0.0, 1.0);
	glVertex2f(1.0, -1.0);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2f(-1.0, -1.0);
	glEnd();


	glColor3f(0.0, 1.0, 0.0);//definir uma cor RGB
	glBegin(GL_LINES);//abrir desenho de vertices
	glVertex2f(-1.0, 1.0);//definir vertices (x,y)
	glVertex2f(1.0, -1.0);
	glEnd();//fechar desenho
	glPopMatrix();//elimina tranformações até o momento da ultima gravação na matriz
	glPushMatrix();
	glTranslatef(0, 1, 0);
	glPopMatrix();
	//glPushMatrix();
	//glRotatef(rot, 0, 0,1);
	glutWireCube(1.5);
	//glPopMatrix();


	glFlush();
}


void desenhaTriangulo(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(1.0);


	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2f(-0.8, 0.8);
	glVertex2f(0.8, 0.8);
	glVertex2f(0.8, -0.8);
	glVertex2f(-0.8, -0.8);
	glEnd();
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(0.0, 0.5);
	glVertex2f(-0.5, -0.5);
	glVertex2f(0.5, -0.5);
	glEnd();

	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.6, -0.3);
	glVertex2f(0.0, -0.2);
	glVertex2f(0.6, -0.3);
	glVertex2f(0.6, -0.5);
	glVertex2f(-0.6, -0.5);
	glEnd();

	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINES);
	glVertex2f(-1.0, 1.0);
	glVertex2f(1.0, -1.0);
	glEnd();
	glFlush();

}


void desenhaCubo(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLineWidth(1.0);
	glPushMatrix();
	glColor3f(0.0, 1.0, 1.0);
	glTranslatef(posCubo, 0, 0);
	glutWireCube(1.0);

	glPopMatrix();
	glPushMatrix();


	glColor3f(1.0, 0.0, 0.0);
	glTranslatef(0, posCubo, 0);
	glutWireCube(1.0);

	glPopMatrix();
	glPushMatrix();

	glColor3f(0.0, 0.0, 1.0);
	glTranslatef(0, 0, posCubo);
	glutWireCube(1.0);

	glPopMatrix();
	glPushMatrix();


	glFlush();
}



void inicializa(void) {
	glClearColor(1.0, 1.0, 1.0, 1.0);//padrão de cor de fundo RGBA
	glMatrixMode(GL_PROJECTION);//informa que a amatriz utilizada é a de projeção (recorte)
	glLoadIdentity();//carrega a matriz original
	
	glLoadIdentity();
	

	gluPerspective(60, 1, 1, 13);
	glMatrixMode(GL_MODELVIEW);//informa que a amatriz utilizada é a de tela
	glLoadIdentity();
	glViewport(0, 0, 400, 400);
	gluLookAt(3, 3, 4, 0, 0, 0, 0, 1, 0);//camera para viusalisação 3d(x,y,z,pra onde a camera olha(x,y,z),e=rotação da camera no propio eixo(x,y,z))
	glEnable(GL_DEPTH_TEST);

}


void anima(int param) {
	if (posx > 5) {
		posx -= 14;
	}
	posx += 0.05;
	//rot -= 1;
	glutPostRedisplay();
	glutTimerFunc(16, anima, 1);
}

void animaCubo(int param) {

	if (posCubo > 4) {
		sentido = -1;
	}
	else if (posCubo < 0) {
		sentido = 1;
	}
	posCubo += 0.04 * sentido;
	glutPostRedisplay();
	glutTimerFunc(16, animaCubo, 1);
}

int main(void) {

	glutInitWindowSize(1000, 1000);//definir tamanho da janela
	glutInitWindowPosition(0, 0);//liocal da janela

	glutCreateWindow("primeira imagem");//criar janela
	inicializa();
	glutDisplayFunc(desenhaCubo);
	animaCubo(1);
	glutMainLoop();
}
