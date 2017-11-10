#include <GLUT/glut.h>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

#ifndef Lines_h
#define Lines_h

GLdouble width = 300;
GLdouble height = 300;

void plot(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}


void DDA_Line(float x0, float y0, float x1, float y1)
{
    float x, y, xs, ys;
    int dx, dy, steps;
    
    dx = x1 - x0;
    dy = y1 - y0;
    
    x = x0;
    y = y0;
    
    if (abs(dx) > abs(dy)) {
        steps = abs(dx);
    }
    else steps = abs(dy);
    
    
    if (steps == 0) {
        plot(x, y);
    }
    
    
    xs = dx / (float)steps;
    ys = dy / (float)steps;
    
    for (int i = 0; i <= steps; i++) {
        plot(x, y);
        x = x + xs;
        y = y + ys;
    }
}



/**** CIRCULO ****/

int x_a = 0, y_a = 0;
GLdouble radius_arc =  height - 100;

float ang_arc = 90;
float rad_arc = ang_arc * (M_PI/180);
//int x_pr = x_a + (radius_arc*cos(rad_arc)), y_pr = y_a + (radius_arc *sin(rad_arc));
int x_arc = x_a + (radius_arc*cos(rad_arc)), y_arc = y_a + (radius_arc *sin(rad_arc));


void circlePoints(int x, int y)
{
    cout << x << " " << y << endl;
    plot(x_a + x, y_a + y);
    plot(x_a + y, y_a + x);
    plot(x_a - x, y_a + y);
    //plot(x_a + y, y_a - x); //
    //plot(x_a + x, y_a - y); //
    plot(x_a - y, y_a + x);
    //plot(x_a - x, y_a - y); //
    //plot(x_a - y, y_a - x); //
}

void circle(void)
{
    plot(x_a, y_a);
    int x = x_arc , y = y_arc;
    plot(x+10, y+10);
    //plot(x_arc, y_arc + 10);
    double p = 5.0 / 4.0 - radius_arc;
    while (y > x) {
        if (p < 0) {
            x++;
            p += 2.0 * x + 3.0;
        }
        else{
            x++;
            y--;
            p += 2.0 * (x - y) + 5.0;
        }
        circlePoints(x, y);
    }
}

/**** ELLIPSE ****/
void ellipsePoints(int xc,int yc,int x,int y);
void ellipse(int xc,int yc,int rx, int ry){
    double d1,d2;
    int x = xc;
    int y = ry;
    
    d1 = ry * ry - rx * rx * ry + rx * rx/4.00;
    plot(xc, yc);
    plot(rx,yc);
    
    while (2.00 * ry * ry * x <= 2.00 * rx * rx * y) {
        if (d1<0) {
            d1 += ry * ry * (2 * x + 3);
        }
        else{
            d1 += ry * ry * (2 * x + 3) + rx * rx * (-2 * y + 2);
            y--;
        }
        x++;
        ellipsePoints(xc, yc, x, y);
    }
    
    
    d2 = ry * ry * (x + 0.50) * (x + 0.50) + rx * rx * (y - 1) * (y -1) - rx * rx * ry * ry;
    
    while (y > 0) {
        if (d2 <= 0) {
            d2 = d2 + 2 *  ry * ry * x - 2 * rx * rx * y + rx * rx;
            x++;
        }
        else{
            d2 = d2 - 2 * rx * rx * y + rx * rx;
        }
        y--;
        ellipsePoints(xc, yc, x, y);
    }
}

void ellipsePoints(int xc,int yc,int x,int y){
    plot(xc+x, yc+y);
    plot(xc-x, yc+y);
    plot(xc+x, yc-y);
    plot(xc-x, yc-y);
}



#endif /* Lines_h */
