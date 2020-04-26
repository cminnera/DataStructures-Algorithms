//************************  vonKoch.h  ***************************
// Modified from Drozdek's code to use PC Graphics library
// to draw the snowflake.
//*****************************************************************
#include <iostream>

#define _USE_MATH_DEFINES
#include <math.h>
#include <PCDraw.h>
using namespace std;

struct kpoint{
	double x;
	double y;
};

class vonKoch {
public:
    vonKoch(double,int);
    void snowflake();
    void cross();
private:
    double side, angle;
    int level;
    kpoint currPt, pt;
    void right(double x) {
         angle += x;
    }
    void left (double x) {
         angle -= x;
    }
    void drawFourLines(double side, int level);
    
};

vonKoch::vonKoch(double s, int lvl) {
    currPt.x = 200;
    currPt.y = 100;
	
    angle = 0.0;
	side = s;
	level = lvl;
	cout << "side = " << side << ", level = " << lvl << endl;
   
}

void vonKoch::drawFourLines(double side, int level) { 
    // arguments to sin() and cos() are angles
    // specified in radians, i.e., the coefficient
    // PI/180 is necessary;
	const double cf = M_PI / 180.0;
    if (level == 0) {
       	 pt.x = int(cos(angle*cf)*side) + currPt.x; 
         pt.y = int(sin(angle*cf)*side) + currPt.y;
		// cout << "DrawLine(" << int(currPt.x) << "," << int(currPt.y) << "),(" << int(pt.x) << "," << int(pt.y) << ")\n";
		 DrawLine(int(currPt.x), int(currPt.y), int(pt.x), int(pt.y));
         currPt.x = pt.x;
       	 currPt.y = pt.y;
	}
    else {                                        
         drawFourLines(side/3,level-1);
         left (60);
         drawFourLines(side/3,level-1);
         right(120);
         drawFourLines(side/3,level-1);
         left (60);
         drawFourLines(side/3,level-1);
    }
}

void vonKoch::snowflake() {
    for (int i = 1; i <= 3; i++) {
        drawFourLines(side,level);
            right(120);
    }
}

