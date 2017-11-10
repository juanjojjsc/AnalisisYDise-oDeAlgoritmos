#include "Poligon.h"

#ifndef Prismas_h
#define Prismas_h


vector<pair<float, float> > c1; //Cuadrado 1 de frente
vector<pair<float, float> > c2; //Cuadrado 2 atrás

vector<pair<float, float> > cc1; //Cuadrado 1 de frente
vector<pair<float, float> > cc2; //Cuadrado 2 atrás

vector<float> an;
vector<float> an1;

GLdouble lado =  (width * .40); //Radio del cuadrado
GLdouble radius_c = (lado/2);

float angle_increment = 360 / 4; //Incremento en grados
float angle_rectangle = 360 / 6;
float inc_rad = angle_increment * (M_PI/180); //incremento en radianes
float angle_rad = 0.00; //inicio de angulo en radianes
float angle_lad = inc_rad/2;
float lado_radio_x = radius_c * cos(angle_lad);
float lado_x = 2 * lado_radio_x;
float lado_sup_x = lado_x / 3;
float cx1 = 0.0, cy1 = 0.0, cx2 , cy2;
float ccx1 = 0.0, ccy1 = 0.0, ccx2 , ccy2;

void print_Prisma1(int pr){
    pair<float, float> p;
    
    cx2 = cx1 + lado_sup_x; cy2 = cy1 + lado_sup_x;
    if (refle == true) {
        ccx2 = ccx1 + lado_sup_x; ccy2 = ccy1 + lado_sup_x;
    }
    
    if (pr == 1 || pr == 2) {
        //plot(cx1,cy1); //Referencia centro del plano; CUADRADO1
        //plot(cx2, cy2);
        if (pr == 2) {
            an.push_back(  angle_rectangle * (M_PI/180));
            an.push_back(2*angle_rectangle * (M_PI/180));
            an.push_back(4*angle_rectangle * (M_PI/180));
            an.push_back(5*angle_rectangle * (M_PI/180));
            if (refle == true) {
                an1.push_back(  angle_rectangle * (M_PI/180));
                an1.push_back(2*angle_rectangle * (M_PI/180));
                an1.push_back(4*angle_rectangle * (M_PI/180));
                an1.push_back(5*angle_rectangle * (M_PI/180));
            }
        }
        for (int i=0; i<4; i++) {
            if(i!=0){
                if (pr == 1) {
                    angle_rad += inc_rad;
                    an.push_back(angle_rad);
                    if (refle == true) {
                        an1.push_back(angle_rad);
                    }
                }
                p.first = cx1 + (radius_c * cos(an[i])); p.second = cy1 + (radius_c *  sin(an[i]));
                c1.push_back(p);
                if (refle == true) {
                    p.first = ccx1 + (radius_c * cos(an[i])); p.second = ccy1 + (radius_c *  sin(an1[i]));
                    cc1.push_back(p);
                }
                
                p.first = cx2 + (radius_c * cos(an[i])); p.second = cy2 + (radius_c *  sin(an[i]));
                c2.push_back(p);
                if (refle == true) {
                    p.first = ccx2 + (radius_c * cos(an[i])); p.second = ccy2 + (radius_c *  sin(an1[i]));
                    cc2.push_back(p);
                }
                //plot(c1[i].first, c1[i].second);
                //plot(c2[i].first, c2[i].second);
            }
            else{
                if (pr == 1) {
                    angle_rad += angle_lad;
                    an.push_back(angle_rad);
                    if (refle == true) {
                        an1.push_back(angle_rad);
                    }
                }
                p.first = cx1 + (radius_c * cos(an[i])); p.second = cy1 + (radius_c *  sin(an[i]));
                c1.push_back(p);
                if (refle == true) {
                    p.first = ccx1 + (radius_c * cos(an[i])); p.second = ccy1 + (radius_c *  sin(an1[i]));
                    cc1.push_back(p);
                }
                p.first = cx2 + (radius_c * cos(an[i])); p.second = cy2 + (radius_c *  sin(an[i]));
                c2.push_back(p);
                if (refle == true) {
                    p.first = ccx2 + (radius_c * cos(an[i])); p.second = ccy2 + (radius_c *  sin(an1[i]));
                    cc2.push_back(p);
                }
                //plot(c1[i].first, c1[i].second);
                //plot(c2[i].first, c2[i].second);
            }
        }
        
        if (c1.size() > 4) {
            for (int i = c1.size(); i > 4; i--) {
                c1.pop_back(); c2.pop_back(); an.pop_back();
                if (refle==true) {
                    cc1.pop_back(); cc2.pop_back(); an1.pop_back();
                }
            }
        }
    }
    if (pr==3) {
        for (int i=0; i<3; i++) {
            if(i!=0){
                angle_rad += inc_rad;
                an.push_back(angle_rad);
                if (refle == true) {
                    an1.push_back(angle_rad);
                }
                p.first = cx1 + (radius_c * cos(an[i])); p.second = cy1 + (radius_c *  sin(an[i]));
                c1.push_back(p);
                if (refle == true) {
                    p.first = ccx1 + (radius_c * cos(an[i])); p.second = ccy1 + (radius_c *  sin(an1[i]));
                    cc1.push_back(p);
                }
                
                p.first = cx2 + (radius_c * cos(an[i])); p.second = cy2 + (radius_c *  sin(an[i]));
                c2.push_back(p);
                if (refle == true) {
                    p.first = ccx2 + (radius_c * cos(an[i])); p.second = ccy2 + (radius_c *  sin(an1[i]));
                    cc2.push_back(p);
                }
                //plot(c1[i].first, c1[i].second);
                //plot(c2[i].first, c2[i].second);
            }
            else{
                angle_rad += angle_lad;
                an.push_back(angle_rad);
                if (refle == true) {
                    an1.push_back(angle_rad);
                }
                
                p.first = cx1 + (radius_c * cos(an[i])); p.second = cy1+ (radius_c *  sin(an[i]));
                c1.push_back(p);
                if (refle == true) {
                    p.first = ccx1 + (radius_c * cos(an[i])); p.second = ccy1 + (radius_c *  sin(an1[i]));
                    cc1.push_back(p);
                }
                
                p.first = cx2 + (radius_c * cos(an[i])); p.second = cy2 + (radius_c *  sin(an[i]));
                c2.push_back(p);
                if (refle == true) {
                    p.first = ccx2 + (radius_c * cos(an[i])); p.second = ccy2 + (radius_c *  sin(an1[i]));
                    cc2.push_back(p);
                }
                //plot(c1[i].first, c1[i].second);
                //plot(c2[i].first, c2[i].second);
            }
            if (c1.size() > 3) {
                for (int i = c1.size(); i > 3; i--) {
                    c1.pop_back(); c2.pop_back(); an.pop_back();
                    if (refle==true) {
                        cc1.pop_back(); cc2.pop_back(); an1.pop_back();
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < c1.size(); i++) {
        if (i<=c1.size()-2) {
            DDA_Line(c1[i].first, c1[i].second, c1[i+1].first, c1[i+1].second);
            DDA_Line(c2[i].first, c2[i].second, c2[i+1].first, c2[i+1].second);
            if (refle==true) {
                DDA_Line(cc1[i].first, cc1[i].second, cc1[i+1].first, cc1[i+1].second);
                DDA_Line(cc2[i].first, cc2[i].second, cc2[i+1].first, cc2[i+1].second);
            }
        }
        if (i == c1.size()-1) {
            DDA_Line(c1[i].first, c1[i].second, c1[0].first, c1[0].second);
            DDA_Line(c2[i].first, c2[i].second, c2[0].first, c2[0].second);
            if (refle==true) {
                DDA_Line(cc1[i].first, cc1[i].second, cc1[0].first, cc1[0].second);
                DDA_Line(cc2[i].first, cc2[i].second, cc2[0].first, cc2[0].second);
            }
        }
        DDA_Line(c1[i].first, c1[i].second, c2[i].first, c2[i].second);
        if (refle==true) {
            DDA_Line(cc1[i].first, cc1[i].second, cc2[i].first, cc2[i].second);
        }
    }
}


void print_Cone(void){
    float top_x = 0;
    float top_y = (height / 100.00) * 50.00;
    
    pair<float, float> p;
    vector<pair<float, float> > el;
    
    plot(top_x,top_y);
    p.first = top_x; p.second = top_y;
    el.push_back(p);
    int base = width / 2;
    plot(-base, -top_y);
    p.first = -base; p.second = -top_y;
    el.push_back(p);
    p.first = base; p.second = -top_y;
    el.push_back(p);
    
    DDA_Line(el[0].first, el[0].second, el[1].first, el[1].second);
    DDA_Line(el[0].first, el[0].second, el[2].first, el[2].second);
    
    ellipse(top_x, -top_y, base , base / 4 );
}



#endif /* Prismas_h */
