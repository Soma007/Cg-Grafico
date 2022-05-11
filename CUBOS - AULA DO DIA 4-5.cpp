#include<GL/glut.h>

GLfloat tamanho = 0;
GLfloat posX = 0;

void desenha(void)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);//limpar o fundo da janela
	glLineWidth(1.0);//definir espessura da lina

	glPushMatrix();
	glTranslatef(posX, 0, 0);
	glRotatef(45, 0, 0, 1);
	//glScalef(2, 1, 1);
	
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_QUADS);
		glVertex2f(-0.8, 0.8);//definir vértice
		glVertex2f(0.8, 0.8);//definir vértice
		glVertex2f(0.8, -0.8);//definir vértice
		glVertex2f(-0.8, -0.8);//definir vértice
	glEnd();//fechar o desenho de vértices

	glColor3f(1.0, 0.0, 0.0);//definir uma cor (verde)
	glBegin(GL_LINES);//abrir para o desenho de vérticde
		glVertex2f(-1.0, 1.0);//definir vértice
		glVertex2f(1.0, -1.0);
	glEnd();//fechar o desenho de vértices

	glPopMatrix();
	glPushMatrix();

	glTranslatef(0, 1, 0);

	glColor3f(0, 0, 0);
	glutWireCube(1.2);

	glPopMatrix();

	glFlush();//finalizar o desnho
}

void inicializa(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	
	glMatrixMode(GL_PROJECTION);//informa que a matriz a ser utilizada é a de Projeção (recorte)
	glLoadIdentity();//carrega a matriz original
	//gluOrtho2D(-1,1,-1,1);//define o tamanho do recorte (câmera2D)
	//glOrtho(-2, 2, -2, 2, -8, 8);
	gluPerspective(60,1,1,13);
	glMatrixMode(GL_MODELVIEW);//informa que a matriz a ser utilizada é a de visualização (tela)
	glLoadIdentity();
	glViewport(0, 0, 400, 400);
	gluLookAt(3,3,4,0,0,0,0,1,0);
	glEnable(GL_DEPTH_TEST);
}

void teclado(int key, int x, int y)
{
	if (key == GLUT_KEY_PAGE_UP)
	{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(-2, 2, -2, 2);
		glutPostRedisplay();
	}
}

void anima(int parametro)
{
	if (posX > 5)
	{
		posX = -7;
	}
	posX += 0.05;
	glutPostRedisplay();
	glutTimerFunc(13, anima, 1);
}

int main(void)
{
	glutInitWindowSize(400, 400);//definir o tamanho da janela
	glutInitWindowPosition(0, 0);//definir o local da janela
	glutCreateWindow("Primeira Imagem");//Criar a janela
	inicializa();//rodar a função
	glutDisplayFunc(desenha);//rodar a função enviando o resultado para a placa gráfica
	glutSpecialFunc(teclado);
	anima(1);
	glutMainLoop();//informar que encerrou
}