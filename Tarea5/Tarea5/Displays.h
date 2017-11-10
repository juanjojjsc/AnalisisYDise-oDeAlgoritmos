#ifndef Displays_h
#define Displays_h
#include "Keyboards.h"

void display_poligon(){
    if (!lad) {
        cout << endl << "\tLados del prisma: "; cin >> lad;
    }
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(1.0);
    poligon_Points(lad);
    glutSwapBuffers();
}

void display_arc(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(1.0);
    circle();
    glutSwapBuffers();
    
}

void display_prisma(){
    if (!lad) {
        cout << endl << "\t1)Cubo\t2)Prisma rectangular\t3)Prisma Triangular " << endl;
        cout << "\t-Opción: "; cin >> lad;
    }
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(1.0);
    print_Prisma1(lad);
    glutSwapBuffers();
}

#endif /* Displays_h */
