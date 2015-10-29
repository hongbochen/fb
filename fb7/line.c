#include "line.h"

//画横线
void draw_h_line(PFBDEV pFbdev,POINT minX,POINT maxX,uint8_t r,uint8_t g,uint8_t b)
{
	int m;
	
	int length = maxX.x - minX.x;
	for(m = 0;m < length;m++){
		POINT tp;
		tp.x = minX.x + m;
		tp.y = minX.y;

		draw_dot(pFbdev,tp,r,g,b);
	}
}

void draw_h_line_with_trans(PFBDEV pFbdev,POINT minX,POINT maxX,uint8_t r,uint8_t g,uint8_t b,uint8_t t){
	int m;
	
	int length = maxX.x - minX.x;
	for(m = 0;m < length;m++){
		POINT tp;
		tp.x = minX.x + m;
		tp.y = minX.y;

		draw_dot_with_trans(pFbdev,tp,r,g,b,t);
	}
}

//画竖线
void draw_v_line(PFBDEV pFbdev,POINT minY,POINT maxY,uint8_t r,uint8_t g,uint8_t b)
{
	int m;
	
	int length = maxY.y - minY.y;
	for(m = 0;m < length;m++){
		POINT tp;
		tp.x = minY.x;
		tp.y = minY.y + m;

		draw_dot(pFbdev,tp,r,g,b);
	}
}

//划横线
void draw_h_line_with_string(PFBDEV pFbdev,POINT minX,POINT maxX,const char *color)
{
	RGBT rgbt = getRGBT(color);

	draw_h_line_with_trans(pFbdev,minX,maxX,rgbt.r,rgbt.g,rgbt.b,rgbt.t);
}

