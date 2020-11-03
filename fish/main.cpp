#include <GL/glut.h>
#include <dos.h>
#include <stdlib.h>

GLubyte fish[] = {
  0x00, 0x60, 0x01, 0x00,
  0x00, 0x90, 0x01, 0x00,
  0x03, 0xf8, 0x02, 0x80,
  0x1c, 0x37, 0xe4, 0x40,
  0x20, 0x40, 0x90, 0x40,
  0xc0, 0x40, 0x78, 0x80,
  0x41, 0x37, 0x84, 0x80,
  0x1c, 0x1a, 0x04, 0x80,
  0x03, 0xe2, 0x02, 0x40,
  0x00, 0x11, 0x01, 0x40,
  0x00, 0x0f, 0x00, 0xe0,
};

void keyboard (unsigned char key, int x, int y)
{
    // we'll switch between greenish blue and light blue when the user presses a key:
    GLfloat colors[][3] = { { 0.0f, 0.7f, 1.0f}, {0.0f, 0.6f, 0.6f } };
    static int back;

    switch (key) {
    case 27:
        exit(0);
    default:
        back ^= 1;
        glClearColor(colors[back][0], colors[back][1], colors[back][2], 1.0f);
        glutPostRedisplay();
    }
}


// Random float in the range 0.0 to 1.0 is created
GLfloat randomFloat() {
  return (GLfloat)rand() / RAND_MAX;
}

// reshape uses an orthographic projection with world coordinates ranging from 0 to 1 in the x and y directions, and -1 to 1 in z.
void reshape(int width, int height) {
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, 1, 0, 1);
}

// we first clear the window, set a background and then add fishes in the aquarium
void display() {
for(int j=0; j<20; j++){    //for animation
  glClear(GL_COLOR_BUFFER_BIT);
  for (int i = 0; i < 35; i++) {
    glColor3f(randomFloat(), randomFloat(), randomFloat());
    glRasterPos3f(randomFloat(), randomFloat(), 0.0);
    glBitmap(27, 11, 0, 0, 0, 0, fish);
  }
  glFlush();
Sleep(200);
}
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
  glutInitWindowSize(1920, 1080);
  glutCreateWindow("The Map of Fishes");
  //glClearColor(randomFloat(), randomFloat(), 0.9, 1.0);
  glutReshapeFunc(reshape);
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutMainLoop();
}
