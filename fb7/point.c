#include "point.h"

//画点
void draw_dot(PFBDEV pFbdev,POINT p,uint8_t r,uint8_t g,uint8_t b)
{
	uint32_t offset;
	uint8_t color[4];
	color[0] = b;
	color[1] = g;
	color[2] = r;
	color[3] = 0x0; //透明度
	
	offset = p.y * pFbdev->fb_fix.line_length + 4 * p.x;
	//将操作映射到内存中
	fb_memcpy((void*)pFbdev->fb_mem + pFbdev->fb_mem_offset + offset,color,4);
}

//画点
void draw_dot_with_trans(PFBDEV pFbdev,POINT p,uint8_t r,uint8_t g,uint8_t b,uint8_t t)
{
	uint32_t offset;
	uint8_t color[4];
	color[0] = b;
	color[1] = g;
	color[2] = r;
	color[3] = t; //透明度
	
	offset = p.y * pFbdev->fb_fix.line_length + 4 * p.x;
	//将操作映射到内存中
	fb_memcpy((void*)pFbdev->fb_mem + pFbdev->fb_mem_offset + offset,color,4);
}

//画点
void draw_x_y_dot(PFBDEV pFbdev,int x,int y,uint8_t r,uint8_t g,uint8_t b)
{
	POINT p;
	p.x = x;
	p.y = y;

	draw_dot(pFbdev,p,r,g,b);
}

//画点
void draw_x_y_dot_with_trans(PFBDEV pFbdev,int x,int y,uint8_t r,uint8_t g,uint8_t b,uint8_t t)
{
	POINT p;
	p.x = x;
	p.y = y;

	draw_dot_with_trans(pFbdev,p,r,g,b,t);
}

//画点
void draw_x_y_color_dot(PFBDEV pFbdev,int x,int y,RGBT c)
{
	draw_x_y_dot(pFbdev,x,y,c.r,c.g,c.b);
}

//画点
void draw_x_y_color_dot_with_trans(PFBDEV pFbdev,int x,int y,RGBT c)
{
	draw_x_y_dot_with_trans(pFbdev,x,y,c.r,c.g,c.b,c.t);
}

//画点 color８位，分别代表RGBT
void draw_x_y_color_dot_with_string(PFBDEV pFbdev,int x,int y,const char *temp)
{
	RGBT rgbt = getRGBT(temp);
	
	draw_x_y_dot_with_trans(pFbdev,x,y,rgbt.r,rgbt.g,rgbt.b,rgbt.t);
}

