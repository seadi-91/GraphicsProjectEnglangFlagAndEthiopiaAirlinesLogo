#include <GL/glut.h>
#include <cstdlib>

float tx = 0.0f, tz = 0.0f;

float poleThickness = 0.10f;
float coneRadius = 0.12f;
float flagSizeX = 0.8f;
float flagSizeY = 0.8f;

float flagYOffset = 0.0f;

const float MIN_SCALE = 0.8f;
const float MAX_SCALE = 2.5f;
const float LEFT_LIMIT = -6.0f;
const float RIGHT_LIMIT = 6.0f;

void init() {
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.53f, 0.81f, 0.92f, 1.0f); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.33, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}
void drawUKFlag() {
    glColor3f(0.004f, 0.129f, 0.412f);
    glBegin(GL_QUADS);
        glVertex3f(-1.4f, -0.8f, 0.0f);
        glVertex3f( 1.4f, -0.8f, 0.0f);
        glVertex3f( 1.4f,  0.8f, 0.0f);
        glVertex3f(-1.4f,  0.8f, 0.0f);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
        glVertex3f(-1.4f,  0.8f, 0.01f); glVertex3f(-1.15f, 0.8f, 0.01f);
        glVertex3f( 1.4f, -0.55f,0.01f); glVertex3f( 1.4f, -0.8f, 0.01f);
        glVertex3f( 1.15f,-0.8f, 0.01f); glVertex3f(-1.4f,  0.55f,0.01f);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex3f( 1.4f,  0.8f, 0.01f); glVertex3f( 1.15f, 0.8f, 0.01f);
        glVertex3f(-1.4f, -0.55f,0.01f); glVertex3f(-1.4f, -0.8f, 0.01f);
        glVertex3f(-1.15f,-0.8f, 0.01f); glVertex3f( 1.4f,  0.55f,0.01f);
    glEnd();

    
    glColor3f(0.784f, 0.063f, 0.180f);
    float w = 0.12f;
    glBegin(GL_QUADS);
        glVertex3f(-1.4f, 0.8f, 0.02f); glVertex3f(0.0f, 0.0f, 0.02f); glVertex3f(-w, 0.0f, 0.02f); glVertex3f(-1.4f, 0.8f-w, 0.02f);
        glVertex3f(1.4f, -0.8f, 0.02f); glVertex3f(0.0f, 0.0f, 0.02f); glVertex3f(w, 0.0f, 0.02f); glVertex3f(1.4f, -0.8f+w, 0.02f);
        glVertex3f(1.4f, 0.8f, 0.02f); glVertex3f(0.0f, 0.0f, 0.02f); glVertex3f(-0.14f,0.0f, 0.02f); glVertex3f(1.4f-w,0.8f,0.02f);
        glVertex3f(-1.4f,-0.8f,0.02f); glVertex3f(0.0f,0.0f,0.02f); glVertex3f(0.14f,0.0f,0.02f); glVertex3f(-1.4f+w,-0.8f,0.02f);
    glEnd();

    glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_QUADS);
        glVertex3f(-1.4f,-0.22f,0.03f); glVertex3f( 1.4f,-0.22f,0.03f); glVertex3f( 1.4f, 0.22f,0.03f); glVertex3f(-1.4f, 0.22f,0.03f);
        glVertex3f(-0.18f,-0.8f,0.03f); glVertex3f( 0.18f,-0.8f,0.03f); glVertex3f( 0.18f, 0.8f,0.03f); glVertex3f(-0.18f, 0.8f,0.03f);
    glEnd();
    glColor3f(0.784f, 0.063f, 0.180f);
    glBegin(GL_QUADS);
        glVertex3f(-1.4f,-0.12f,0.04f); glVertex3f( 1.4f,-0.12f,0.04f); glVertex3f( 1.4f, 0.12f,0.04f); glVertex3f(-1.4f, 0.12f,0.04f);
        glVertex3f(-0.10f,-0.8f,0.04f); glVertex3f( 0.10f,-0.8f,0.04f); glVertex3f( 0.10f, 0.8f,0.04f); glVertex3f(-0.10f, 0.8f,0.04f);
    glEnd();

    glColor3f(0.0f,0.0f,0.0f);
    glLineWidth(1.0f);
    glBegin(GL_LINES);
        glVertex3f(-1.4f, -0.8f, 0.05f); glVertex3f( 1.4f, -0.8f, 0.05f);
        glVertex3f(-1.4f,  0.8f, 0.05f); glVertex3f( 1.4f,  0.8f, 0.05f);
        glVertex3f(-1.4f, -0.8f, 0.05f); glVertex3f(-1.4f,  0.8f, 0.05f);
    glEnd();
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0, 2.0, 15.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    glColor3f(0.2f, 0.5f, 0.2f);
    glBegin(GL_QUADS);
        glVertex3f(-15.0f, -3.5f, -15.0f); glVertex3f( 15.0f, -3.5f, -15.0f);
        glVertex3f( 15.0f, -3.5f,  15.0f); glVertex3f(-15.0f, -3.5f,  15.0f);
    glEnd();

    glPushMatrix();
        glTranslatef(tx, 0.0f, tz);

        glColor3f(0.55f, 0.55f, 0.55f);
        glPushMatrix(); glTranslatef(0.0f, -3.05f, 0.0f); glScalef(2.6f, 0.35f, 2.6f); glutSolidCube(1.0); glPopMatrix();
        glColor3f(0.65f, 0.65f, 0.65f);
        glPushMatrix(); glTranslatef(0.0f, -2.70f, 0.0f); glScalef(1.9f, 0.35f, 1.9f); glutSolidCube(1.0); glPopMatrix();
        glColor3f(0.70f, 0.70f, 0.70f);
        glPushMatrix(); glTranslatef(0.0f, -2.35f, 0.0f); glScalef(1.2f, 0.35f, 1.2f); glutSolidCube(1.0); glPopMatrix();

        
        glColor3f(0.8f, 0.8f, 0.8f);
        glPushMatrix(); glTranslatef(0.0f, 0.8f, 0.0f); glScalef(poleThickness, 7.0f, poleThickness); glutSolidCube(1.0); glPopMatrix();

        
        glColor3f(1.0f, 0.84f, 0.0f);
        glPushMatrix(); glTranslatef(0.0f, 4.3f, 0.0f); glRotatef(-90, 1, 0, 0); glutSolidCone(coneRadius, 0.4, 20, 20); glPopMatrix();

      
        glPushMatrix();
            glTranslatef(poleThickness / 2.0f, 4.3f + flagYOffset, 0.0f);
            glScalef(flagSizeX * 0.8f, flagSizeY * 0.8f, 1.0f);
            glTranslatef(1.4f, -0.8f, 0.0f);
            drawUKFlag();
        glPopMatrix();
    glPopMatrix();

    glutSwapBuffers();
}
void keyboard(unsigned char key, int x, int y) {
    float flagH = 1.28f * flagSizeY;
    switch (key) {
        case 'r': case 'R': if (tx > LEFT_LIMIT) tx -= 0.2f; break;
        case 'l': case 'L': if (tx < RIGHT_LIMIT) tx += 0.2f; break;
        case 't': case 'T': if (flagYOffset < 0.0f) { flagYOffset += 0.1f; if (flagYOffset > 0.0f) flagYOffset = 0.0f; } break;
        case 'd': case 'D': if ((4.3f + flagYOffset - flagH) > -2.15f) { flagYOffset -= 0.1f; } break;
        case '+': case '=': if (flagSizeX < MAX_SCALE) { flagSizeX += 0.05f; flagSizeY += 0.05f; poleThickness += 0.01f; coneRadius += 0.01f; } break;
        case '-': case '_': if (flagSizeX > MIN_SCALE) { flagSizeX -= 0.05f; flagSizeY -= 0.05f; poleThickness -= 0.01f; coneRadius -= 0.01f; } break;
        case 27: exit(0); break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Flag Scene - No Right Border");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}