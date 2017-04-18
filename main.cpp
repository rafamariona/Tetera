#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>

double rotate_y=0;
double rotate_x=0;
double rotate_z=0;
GLfloat X = 0.0f;
GLfloat Y = 0.0f;
GLfloat Z = 0.0f;

GLfloat scale = 1.0f;


void init(void)
{
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
    // Activamos la fuente de luz
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0); //Activamos las luces en 0
    glDepthFunc(GL_LESS); //comparación de profundidad
    glEnable(GL_DEPTH_TEST); //activa GL_DEPTH_TEST
    
    glLightfv(GL_LIGHT0,GL_POSITION,light_position);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

}

void reshape(int w, int h)
{
 glViewport(0, 0, (GLsizei) w, (GLsizei) h);
// Activamos la matriz de proyeccion.
 glMatrixMode(GL_PROJECTION);
// "limpiamos" esta con la matriz identidad.
 glLoadIdentity();
// Usamos proyeccion ortogonal
 glOrtho(-300, 300, -300, 300, -300, 300);
// Activamos la matriz de modelado/visionado.
 glMatrixMode(GL_MODELVIEW);
// "Limpiamos" la matriz
 glLoadIdentity();
}
void display(void)
{
// Propiedades del material
 /*GLfloat mat_ambient[] = { 0.19225,0.19225,0.19225};
 GLfloat mat_diffuse[] = { 0.50754,0.50754,0.50754};
 GLfloat mat_specular[] = { 0.508273,0.508273,0.508273};*/
 GLfloat mat_ambient[] = { 0.1745f, 0.01175f, 0.01175f,1.0f };
    GLfloat mat_diffuse[] = { 0.61424f, 0.04136f, 0.04136f, 1.0f };
    GLfloat mat_specular[] = { 0.727811f, 0.626959f, 0.626959f, 1.0f };
    GLfloat shine[] = {25.6f};
// "Limpiamos" el frame buffer con el color de "Clear", en este
// caso negro.
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 glMatrixMode( GL_MODELVIEW_MATRIX );
 glLoadIdentity();
// Rotacion de 25 grados en torno al eje x
 //glRotated(25.0, 1.0, 0.0, 0.0);
// Rotacion de -30 grados en torno al eje y
 //glRotated(-30.0, 0.0, 1.0, 0.0);
// Dibujamos una "Tetera" y le aplico el material
 glPushMatrix();
//setMaterial
 glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
 glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
 glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
 glMaterialfv(GL_FRONT, GL_SHININESS, shine);
  glTranslatef(X,Y,Z);
    glRotatef( rotate_x, 1.0, 0.0, 0.0 );
    glRotatef( rotate_y, 0.0, 1.0, 0.0 );
    glRotatef( rotate_z, 0.0, 0.0, 1.0 );
    glScalef(scale, scale, scale);
    

    glutWireSphere (250,50,50); 
 
    
 glFlush();

}

void keyboard(unsigned char key, int x, int y)
{
    //control de teclas que hacen referencia a Escalar y trasladar la tetera en los ejes X,Y,
    switch (key)
    {
    case 'Z':
        scale+=0.05;
        break;
    case 'z':
        scale-=0.05;
        break;
    case 'x' :
        X -= 5.0f;
        break;
    case 'X' :
        X += 5.0f;
        break;
    case 'y' :
        Y -= 5.0f;
        break;
    case 'Y' :
        Y += 5.0f;
        break;
    case 'r': //resetea las posiciones de todo y el tamaño
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



int main(int argc, char **argv)
{
// Inicializo OpenGL
 glutInit(&argc, argv);
// Activamos buffer simple y colores del tipo RGB
 glutInitDisplayMode (GLUT_RGB | GLUT_DEPTH);
// Definimos una ventana de medidas 800 x 600 como ventana
// de visualizacion en pixels
 glutInitWindowSize (800, 600);
// Posicionamos la ventana en la esquina superior izquierda de
// la pantalla.
 glutInitWindowPosition (0, 0);
// Creamos literalmente la ventana y le adjudicamos el nombre que se
// observara en su barra de titulo.
 glutCreateWindow ("Tetera con materiales");
// Inicializamos el sistema
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);
    glutReshapeFunc(reshape);
    glutMainLoop();
 return 0;
}
