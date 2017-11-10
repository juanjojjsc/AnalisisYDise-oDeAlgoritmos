#ifndef Keyboards_h
#define Keyboards_h
#include "Prismas.h"

void check_prisma();
void check_lad();

float ang_giro = 10.00;
float coef_ang = (ang_giro * (M_PI/180)); //Coeficiente de giro, cambiar el valor de ang_giro

void keyboard_prismas(unsigned char key, int x_, int y_){
    switch (key) {
        case 'q':
            exit(0);
            break;
            
        case 'x':
            check_prisma();
            for (int i = 0; i < x_p.size(); i++) {
                x_p[i] += 10;
                if (refle == true) {
                    x_p1[i] -= 10;
                }
            }
            glutPostRedisplay();
            break;
            
        case 'X':
            check_prisma();
            for (int i = 0; i < x_p.size(); i++) {
                x_p[i] -= 10;
                if (refle == true) {
                    x_p1[i] += 10;
                }
            }
            glutPostRedisplay();
            break;
            
        case 'y':
            check_prisma();
            for (int i = 0; i < x_p.size(); i++) {
                y_p[i] += 10;
                if (refle == true) {
                    y_p1[i] += 10;
                }
            }
            glutPostRedisplay();
            break;
            
        case 'Y':
            check_prisma();
            for (int i = 0; i < x_p.size(); i++) {
                y_p[i] -= 10;
                if (refle == true) {
                    y_p1[i] -= 10;
                }
            }
            glutPostRedisplay();
            break;
            
        case '+':
            check_prisma();
            for (int i = 1; i < angles.size(); i++) {
                x_p[i] += 5.00 * cos(angles[i]);
                y_p[i] += 5.00 * sin(angles[i]);
                if (refle == true) {
                    x_p1[i] -= 5.00 * cos(angles[i]);
                    y_p1[i] -= 5.00 * sin(angles[i]);
                }
            }
            radius += 5.00;
            glutPostRedisplay();
            break;
            
        case '-':
            check_prisma();
            for (int i = 1; i < angles.size(); i++) {
                x_p[i] += -5.00 * cos(angles[i]);
                y_p[i] += -5.00 * sin(angles[i]);
                if (refle == true) {
                    x_p1[i] += 5.00 * cos(angles[i]);
                    y_p1[i] += 5.00 * sin(angles[i]);
                }
            }
            radius -=  5.00;
            glutPostRedisplay();
            break;
            
        case 'r':
            check_prisma();
            for (int i = 1; i < angles.size(); i++){
                angles[i] += coef_ang;
                if (refle==true) {
                    angles1[i] -= coef_ang;
                }
            }
            for (int i = 1; i < angles.size(); i++) {
                x_p[i] = x_p[0] + (radius * cos(angles[i]));
                y_p[i] = y_p[0] + (radius * sin(angles[i]));
                if (refle == true) {
                    x_p1[i] = x_p1[0] + (radius * cos(angles1[i]));
                    y_p1[i] = y_p1[0] + (radius * sin(angles1[i]));
                }
            }
            glutPostRedisplay();
            break;
            
        case 'R':
            check_prisma();
            for (int i = 1; i < angles.size(); i++){
                angles[i] -= coef_ang;
                if (refle==true) {
                    angles1[i] += coef_ang;
                }
            }
            for (int i = 1; i < angles.size(); i++) {
                x_p[i] = x_p[0] + (radius * cos(angles[i]));
                y_p[i] = y_p[0] + (radius * sin(angles[i]));
                if (refle == true) {
                    x_p1[i] = x_p1[0] + (radius * cos(angles1[i]));
                    y_p1[i] = y_p1[0] + (radius * sin(angles1[i]));
                }
            }
            glutPostRedisplay();
            break;
            
        case 'a':
            refle = true;
            for (int i = 0; i<x_p.size(); i++) {
                x_p1.push_back(-x_p[i]);
                y_p1.push_back(-y_p[i]);
            }
            glutPostRedisplay();
            break;
        
        case 'A':
            refle = false;
            x_p1.clear();
            y_p1.clear();
            glutPostRedisplay();
            break;
            
        default:
            break;
    }
}



void keyboard_arc(unsigned char key, int x_, int y_){
    switch (key) {
        case 'q':
            exit(0);
            break;
            
        case 'x':
            x_a += 5;
            glutPostRedisplay();
            break;
            
        case 'X':
            x_a -= 5;
            glutPostRedisplay();
            break;
            
        case 'y':
            y_a += 5;
            glutPostRedisplay();
            break;
            
        case 'Y':
            y_a -= 5;
            glutPostRedisplay();
            break;
            
        case '+':
            radius_arc += 5;
            x_arc = x_a + (radius_arc*cos(rad_arc));
            y_arc = y_a + (radius_arc *sin(rad_arc));
            glutPostRedisplay();
            break;
            
        case '-':
            radius_arc -= 5;
            x_arc = x_a + (radius_arc*cos(rad_arc));
            y_arc = y_a + (radius_arc *sin(rad_arc));
            glutPostRedisplay();
            break;
            
        /*
        case 'r':
            //PENDIENTE
            rad_arc += coef_ang;
            x_arc = (radius_arc*cos(rad_arc));
            y_arc = (radius_arc*sin(rad_arc));
            glutPostRedisplay();
            break;
            
            
        case 'R':
            glutPostRedisplay();
            break;
        */
        default:
            break;
    }
}

/*************** PRISMAS RECTANGULARES *******************/

void keyboard_prisma(unsigned char key, int x_, int y_){
    
    switch (key) {
        case 'q':
            exit(0);
            break;
            
        case 'x':
            check_lad();
            cx1 += 5.00; cx2 += 5.00;
            ccx1 -= 5.00; ccx2 -= 5.00;
            for (int i=0; i<c1.size(); i++) {
                c1[i].first += 5.0;
                c2[i].first += 5.0;
                if (refle == true) {
                    cc1[i].first -= 5.0;
                    cc2[i].first -= 5.0;
                }
            }
            glutPostRedisplay();
            break;
            
        case 'X':
            check_lad();
            cx1 -= 5; cx2 -= 5;
            ccx1 += 5.00; ccx2 += 5.00;
            for (int i=0; i<c1.size(); i++) {
                c1[i].first -= 5.0;
                c2[i].first -= 5.0;
                if (refle == true) {
                    cc1[i].first += 5.0;
                    cc2[i].first += 5.0;
                }
            }
            glutPostRedisplay();
            break;
            
        case 'y':
            check_lad();
            cy1 += 5; cy2 += 5;
            ccy1 += 5; ccy2 += 5;
            for (int i=0; i<c1.size(); i++) {
                c1[i].second += 5.0;
                c2[i].second += 5.0;
                if (refle == true) {
                    cc1[i].second += 5.0;
                    cc2[i].second += 5.0;
                }
            }
            glutPostRedisplay();
            break;
            
        case 'Y':
            check_lad();
            cy1 -= 5; cy2 -= 5;
            ccy1 -= 5; ccy2 -= 5;
            
            for (int i=0; i<c1.size(); i++) {
                c1[i].second -= 5.0;
                c2[i].second -= 5.0;
                if (refle == true) {
                    cc1[i].second -= 5.0;
                    cc2[i].second -= 5.0;
                }
            }
            glutPostRedisplay();
            break;
            
        case '+':
            check_lad();
            radius_c += 5.00;
            lado_radio_x = radius_c * cos(angle_lad);
            lado_x = 2 * lado_radio_x;
            lado_sup_x = lado_x / 3;
            for (int i = 0; i < c1.size(); i++) {
                c1[i].first  = cx1 + radius_c * cos(an[i]);
                c1[i].second = cy1 + radius_c * sin(an[i]);
                c2[i].first  = cx2 + radius_c * cos(an[i]);
                c2[i].second = cy2 + radius_c * sin(an[i]);
                if (refle == true) {
                    cc1[i].first  = ccx1 + radius_c * cos(an[i]);
                    cc1[i].second = ccy1 + radius_c * sin(an[i]);
                    cc2[i].first  = ccx2 + radius_c * cos(an[i]);
                    cc2[i].second = ccy2 + radius_c * sin(an[i]);
                }
            }
            glutPostRedisplay();
            break;
            
        case '-':
            check_lad();
            radius_c -= 5.00;
            lado_radio_x = radius_c * cos(angle_lad);
            lado_x = 2 * lado_radio_x;
            lado_sup_x = lado_x / 3;
            for (int i = 0; i < c1.size(); i++) {
                c1[i].first  = cx1 + radius_c * cos(an[i]);
                c1[i].second = cy1 + radius_c * sin(an[i]);
                c2[i].first  = cx2 + radius_c * cos(an[i]);
                c2[i].second = cy2 + radius_c * sin(an[i]);
                if (refle == true){
                    cc1[i].first  = ccx1 + radius_c * cos(an[i]);
                    cc1[i].second = ccy1 + radius_c * sin(an[i]);
                    cc2[i].first  = ccx2 + radius_c * cos(an[i]);
                    cc2[i].second = ccy2 + radius_c * sin(an[i]);
                    
                }
            }
            glutPostRedisplay();
            break;
            
        case 'r':
            check_lad();
            for (int i = 0; i < an.size(); i++){
                an[i] += coef_ang;
                if (refle==true) {
                    an1[i] -= coef_ang;
                }
            }
            for (int i = 0; i < an.size(); i++) {
                c1[i].first  = cx1 + radius_c * cos(an[i]);
                c1[i].second = cy1 + radius_c * sin(an[i]);
                c2[i].first  = cx2 + radius_c * cos(an[i]);
                c2[i].second = cy2 + radius_c * sin(an[i]);
                if (refle == true) {
                    cc1[i].first  = ccx1 + radius_c * cos(an1[i]);
                    cc1[i].second = ccy1 + radius_c * sin(an1[i]);
                    cc2[i].first  = ccx2 + radius_c * cos(an1[i]);
                    cc2[i].second = ccy2 + radius_c * sin(an1[i]);
                }
            }
            glutPostRedisplay();
            break;
            
        case 'R':
            check_lad();
            for (int i = 0; i < an.size(); i++){
                an[i] -= coef_ang;
                if (refle==true) {
                    an1[i] += coef_ang;
                }
            }
            for (int i = 0; i < an.size(); i++) {
                c1[i].first  = cx1 + radius_c * cos(an[i]);
                c1[i].second = cy1 + radius_c * sin(an[i]);
                c2[i].first  = cx2 + radius_c * cos(an[i]);
                c2[i].second = cy2 + radius_c * sin(an[i]);
                if (refle == true) {
                    cc1[i].first  = ccx1 + radius_c * cos(an1[i]);
                    cc1[i].second = ccy1 + radius_c * sin(an1[i]);
                    cc2[i].first  = ccx2 + radius_c * cos(an1[i]);
                    cc2[i].second = ccy2 + radius_c * sin(an1[i]);
                }
            }
            glutPostRedisplay();
            break;
            
        case 'a':
            refle = true;
            ccx1 = cx1;
            ccx2 = ccx1 + lado_sup_x;
            for (int i = 0; i<c1.size(); i++) {
                pair<float, float> p1;
                float ang;
                p1.first = c1[i].first; p1.second = c1[i].second;
                cc1.push_back(p1);
                p1.first = c2[i].first; p1.second = c2[i].second;
                cc2.push_back(p1);
                ang = an[i];
                an1.push_back(ang);
            }
            glutPostRedisplay();
            break;
            
        case 'A':
            refle = false;
            cc1.clear();
            cc2.clear();
            glutPostRedisplay();
            break;
            
        default:
            break;
    }
}

void check_prisma(){
    if (lad+1 < x_p.size() && lad+1 < y_p.size() && lad+1 < angles.size()) {
        for (int i = (x_p.size()-1); i > lad; i--) {
            x_p.pop_back();
            y_p.pop_back();
            angles.pop_back();
            if (refle == true) {
                if (lad+1 < x_p1.size() && lad+1 < y_p1.size()){
                    x_p1.pop_back();
                    y_p1.pop_back();
                }
            }
        }
    }
}
void check_lad(){
    if (lad != 3) {
        if (c1.size() > 4) {
            for (int i = (c1.size()-1); i > 3; i--) {
                c1.pop_back();
                c2.pop_back();
                an.pop_back();
                if (refle == true) {
                    cc1.pop_back();
                    cc2.pop_back();
                    an1.pop_back();
                }
            }
        }
    }
    else{
        if (c1.size() > 3) {
            for (int i = (c1.size()-1); i > 2; i--) {
                c1.pop_back();
                c2.pop_back();
                an.pop_back();
                if (refle == true) {
                    cc1.pop_back();
                    cc2.pop_back();
                    an1.pop_back();
                }
            }
        }
    }
}
#endif /* Keyboards_h */
