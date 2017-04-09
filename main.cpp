//Tetera que se mueve por MT14002

#include <GL/gl.h>
#include <GL/glut.h>

double rotate_y=0;
double rotate_x=0;
double rotate_z=0;
GLfloat X = 0.0f;
GLfloat Y = 0.0f;
GLfloat Z = 0.0f;

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
    glTranslatef(X,Y,Z);
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
    case 'Z':
        scale+=0.05;
        break;
    case 'z':
        scale-=0.05;
        break;
    case 'x' :
        X -= 0.05f;
        break;
    case 'X' :
        X += 0.05f;
        break;
    case 'y' :
        Y -= 0.05f;
        break;
    case 'Y' :
        Y += 0.05f;
        break;
    case 'r':
        X=0.0,Y=0.0;
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


// Función para controlar teclas especiales
void specialKeys( int key, int x, int y )
{

    //  Flecha derecha: aumentar rotación 5 grados
    if (key == GLUT_KEY_RIGHT)
        rotate_y += 5;
//  Flecha izquierda: rotación en eje Y negativo 5 grados
    else if (key == GLUT_KEY_LEFT)
        rotate_y -= 5;
    //  Flecha arriba: rotación en eje X positivo 5 grados
    else if (key == GLUT_KEY_UP)
        rotate_x += 5;
    //  Flecha abajo: rotación en eje X negativo 5 grados
    else if (key == GLUT_KEY_DOWN)
        rotate_x -= 5;
     
    //  Solicitar actualización de visualización
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
    glutSpecialFunc(specialKeys);
// Indica cual es la función para el cambio de tamaño de laventana
    // glutReshapeFunc(reshape);
// Comienza el bucle de dibujo y proceso de eventos.
    glutMainLoop();

}
