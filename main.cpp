//Tetera que se mueve por MT14002

#include <GL/gl.h>
#include <GL/glut.h>

double rotate_y=0;
double rotate_x=0;
double rotate_z=0;


GLfloat scale = 1.0f;
void init(void)
{
    /* selecciona el color de borrado */
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_FLAT);
}
void display(void)
{
    /* borra la pantalla */
    glClear (GL_COLOR_BUFFER_BIT);
    /* seleccionamos la matriz modelo/vista */
    glMatrixMode(GL_MODELVIEW);
    /* color */
    glColor3f(0.855, 0.647, 0.125);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, 0.0);
    glRotatef( rotate_x, 1.0, 0.0, 0.0 );
    glRotatef( rotate_y, 0.0, 1.0, 0.0 );
    glRotatef( rotate_z, 0.0, 0.0, 1.0 );
    glScalef(scale, scale, scale);

    /* transformación modelo/vista */
    gluLookAt(0.0,0.0,0.0001, //punto de vista en el eje X,Y,Z
              0.0,0.0,0.0, //Centro del Objeto en el eje X,Y,Z
              0.0,1.0,0.0); //Orientación de la cámara (vector UP el eje X,Y,Z)

    /* Dibujamos una tetera */
    glutWireTeapot(0.5);

    /* Vacia el buffer de dibujo */
    glFlush ();
}

// Función para controlar teclas normales del teclado.
void keyboard(unsigned char key, int x, int y)
{
    //control de teclas que hacen referencia a Escalar y transladar el cubo en los ejes X,Y,Z.
    switch (key)
    {
    case '+':
        scale+=0.05;
        break;
    case '-':
        scale-=0.05;
        break;
    case 'x' :
        rotate_x += 1;
        break;
    case 'X' :
        rotate_x -= 1;
        break;
    case 'y' :
        rotate_y += 1;
        break;
    case 'Y' :
        rotate_y -= 1;
        break;
    case 'z':
        rotate_z -= 1;
        break;
    case 'Z':
        rotate_z += 1;
        break;
    case 'r':
			rotate_x=0.0;
			rotate_y=0.0;
			rotate_z=0.0;
			scale=1.0;
			break;
    case 27:
        exit(0);			// exit
    }
    glutPostRedisplay();
}



int main(int argc, char** argv)
{
// Inicializa la librería auxiliar GLUT
    glutInit(&argc, argv);
// Inicializa el modo de visualización
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
// Indica el tamaño de la ventana (ancho,alto)
    glutInitWindowSize(800, 600);
// Indica la posición inicial (xmin,ymin)
    glutInitWindowPosition(100, 100);
// Abre la ventana con el título indicado
    glutCreateWindow("Dibujando una tetera 3d");

// Inicializar valores
    init();
// Indica cual es la función de dibujo
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
// Indica cual es la función para el cambio de tamaño de laventana
    // glutReshapeFunc(reshape);
// Comienza el bucle de dibujo y proceso de eventos.
    glutMainLoop();

}
