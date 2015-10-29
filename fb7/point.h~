/**
 * 画点实现
 *　@作者　陈洪波 
 */

#ifndef _POINT_H_
#define _POINT_H_

#include "fbtool.h"

/*
 * 该函数用于在命令行中画点
 * @param pFbdev 	参考结构体 fbdev
 * @param p 		点的坐标
 * @param r			颜色对应的R值
　* @param g			颜色对应的G值
 *　@param b			颜色对应的B值
 *　@return void
 */
void draw_dot(PFBDEV pFbdev,POINT p,uint8_t r,uint8_t g,uint8_t b);

/*
 * 该函数用于实现画点，不过在这个函数中需要设定透明度参数
 * @param pFbdev 	参考结构体 fbdev
 * @param p 		点的坐标
 * @param r			颜色对应的R值
　* @param g			颜色对应的G值
 *　@param b			颜色对应的B值
　* @param t			颜色对应的透明度值
 *　@return void
 */
void draw_dot_with_trans(PFBDEV pFbdev,POINT p,uint8_t r,uint8_t g,uint8_t b,uint8_t t);

/*
 * 该函数用于指定点的横坐标，纵坐标的值来画点
 * @param pFbdev 	参考结构体 fbdev
 * @param x 		点的坐标对应的横坐标的值
 * @param y			点的坐标对应的纵坐标的值
 * @param r			颜色对应的R值 
　* @param g			颜色对应的G值
 *　@param b			颜色对应的B值
 */
void draw_x_y_dot(PFBDEV pFbdev,int x,int y,uint8_t r,uint8_t g,uint8_t b);

/*
 * 该函数用于指定点的横坐标，纵坐标的值，并且必须指明透明度来画点
 * @param pFbdev 	参考结构体 fbdev
 * @param x 		点的坐标对应的横坐标的值
 * @param y			点的坐标对应的纵坐标的值
 * @param r			颜色对应的R值 
　* @param g			颜色对应的G值
 *　@param b			颜色对应的B值
　* @param t			颜色对应的透明度值
 */
void draw_x_y_dot_with_trans(PFBDEV pFbdev,int x,int y,uint8_t r,uint8_t g,uint8_t b,uint8_t t);

/*
 * 该函数指定点的横纵坐标，然后使用结构体rgbt来代替颜色来画点
 * @param pFbdev 	参考结构体 fbdev
 * @param x 		点的坐标对应的横坐标的值
 * @param y			点的坐标对应的纵坐标的值
 * @param c			用来代表颜色的结构体
 * @return void 
 *
 */
void draw_x_y_color_dot(PFBDEV pFbdev,int x,int y,RGBT c);

/*
 * 该函数指定点的横纵坐标，然后使用结构体rgbt来代替颜色来画点,不过在这里指明透明度是有效果
 * @param pFbdev 	参考结构体 fbdev
 * @param x 		点的坐标对应的横坐标的值
 * @param y			点的坐标对应的纵坐标的值
 * @param c			用来代表颜色的结构体
 * @return void 
 *
 */
void draw_x_y_color_dot_with_trans(PFBDEV pFbdev,int x,int y,RGBT c);

/*
 * 该函数指定点的横纵坐标，然后使用八位的字符串来指明颜色来画点
　* 注意：这里的字符串里面都是16进制的数值，例如,"ffff0000"
 *
 * @param pFbdev 	参考结构体 fbdev
 * @param x 		点的坐标对应的横坐标的值
 * @param y			点的坐标对应的纵坐标的值
 * @param c			用来代表颜色的结构体
 * @param color		用来指明颜色的字符串
 * @return void 
 *
 */
void draw_x_y_color_dot_with_string(PFBDEV pFbdev,int x,int y,const char *color);

#endif //_POINT_H_


