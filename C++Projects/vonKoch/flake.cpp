#include "vonKoch.h"

int main(void){
	InitGraphics("Lower Left");
	vonKoch drawing(300,5);
	SetPenColor("Black");
	drawing.snowflake();
	return 0;
}