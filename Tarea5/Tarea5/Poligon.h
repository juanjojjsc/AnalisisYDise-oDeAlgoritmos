#ifndef Poligons_h
#define Poligons_h
#include "Lines.h"

using namespace std;


float x = 0.0, y = 0.0; //Centro de la figura original

float xp = 0.0 , yp = 0.0;

vector<float> x_p;
vector<float> y_p;
vector<float> x_p1;
vector<float> y_p1;

bool refle = false;

vector<float> angles;
vector<float> angles1;

float angle = 0;

int lad;
GLdouble radius =  (height / 100.00) * 50;



void print_lines(vector<float> v, vector<float> w, int lados){
    for (int i = 1; i <= lados; i++){
        if (i<lados)    DDA_Line(v[i], w[i], v[i+1], w[i+1]);
        else            DDA_Line(v[i], w[i], v[1], w[1]);
    }
}

void poligon_Points(int lados){
    x_p.push_back(x); y_p.push_back(y);
    //plot(x_p[0], y_p[0]);
    angles.push_back(0);
    if (refle == true) {
        x_p1.push_back(x); y_p1.push_back(y);
        plot(x_p[0], y_p[0]);
        angles1.push_back(0);
    }
    
    GLdouble radius =  (height / 100.00) * 50;
    float angle_increment = 360 / lados;
    
    for (int i = 0; i < lados; i++) {
        float angle_rad = angle * (M_PI/180);
        angles.push_back(angle_rad);
        x_p.push_back(radius * cos(angles[i+1]));
        y_p.push_back(radius * sin(angles[i+1]));
        if (refle == true) {
            angles1.push_back(angle_rad);
            x_p1.push_back(radius * cos(angles[i+1]));
            y_p1.push_back(radius * sin(angles[i+1]));
        }
        angle = angle + angle_increment;
    }
    
    print_lines(x_p, y_p, lados);
    
    if (refle == true) {
        print_lines(x_p1, y_p1, lados);
    }
    angle = 0.0;
}

#endif /* Poligons_h */
