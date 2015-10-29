#include "circle.h"

//画圆
void draw_circle(PFBDEV pFbdev,int x,int y,int radius,const char *color)
{
	double i;

	int tmp;

	for(i = x - radius; i < x + radius;i+=0.01){
		tmp = sqrt(radius * radius - (i - x) * (i - x));

		draw_x_y_color_dot_with_string(pFbdev,i,(tmp + y),color);
		draw_x_y_color_dot_with_string(pFbdev,i,(-tmp + y),color);
	}
}

