#include "rectangle.h"

//画一个矩形框
void draw_rec(PFBDEV pFbdev,POINT lu,POINT ld,POINT ru,POINT rd,uint8_t r,uint8_t g,uint8_t b)
{
	draw_h_line(pFbdev,lu,ru,r,g,b);
	draw_h_line(pFbdev,ld,rd,r,g,b);
	draw_v_line(pFbdev,lu,ld,r,g,b);
	draw_v_line(pFbdev,ru,rd,r,g,b);
}

//填充一个矩形框
void fill_rec(PFBDEV pFbdev,POINT lu,POINT ld,POINT ru,POINT rd,uint8_t r,uint8_t g,uint8_t b)
{
	int xlen = ru.x - lu.x;
	int ylen = ld.y - lu.y;

	int m,n;

	for(m = 0;m < ylen;m++){
		for(n = 0;n < xlen;n++){
			POINT p;
			p.x = lu.x + n;
			p.y = lu.y + m;
	
			draw_dot(pFbdev,p,r,g,b);	
		}	
	}
}

