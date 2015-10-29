/*
 * 画线的实现
 * @作者 陈洪波
 */

#ifndef _LINE_H_
#define _LINE_H_

#include "fbtool.h"
#include "point.h"

/*
 * 指定x值较小的点和x值较大的点，并指定颜色的rgb值画一条横线
 *　@param pFbdev 	参考结构体 fbdev
 * @param minX		x较小的点
 *　@param maxX		x较大的点
　* @param r			颜色对应的R值
 *　@param g 		颜色对应的G值
 *　@param b			颜色对应的B值
 *　@return void
 */
void draw_h_line(PFBDEV pFbdev,POINT minX,POINT maxX,uint8_t r,uint8_t g,uint8_t b);

/*
 * 指定x值较小的点和x值较大的点，并指定颜色的rgb值和透明度画一条横线
 *　@param pFbdev 	参考结构体 fbdev
 * @param minX		x较小的点
 *　@param maxX		x较大的点
　* @param r			颜色对应的R值
 *　@param g 		颜色对应的G值
 *　@param b			颜色对应的B值
　* @param t			颜色对应的透明度
 *　@return void
 *
 */
void draw_h_line_with_trans(PFBDEV pFbdev,POINT minX,POINT maxX,uint8_t r,uint8_t g,uint8_t b,uint8_t t);

/*
 * 使用字符串作为颜色的表示来画一条横线
 *　@param pFbdev 	参考结构体 fbdev
 * @param minX		x较小的点
 *　@param maxX		x较大的点
 * @param color		颜色所对应的字符串
 *　@return void
 */
void draw_h_line_with_string(PFBDEV pFbdev,POINT minX,POINT maxX,const char *color);

/*
 * 指明y最小的一个点和一个y较大的点，并指明RGB值画一条竖线
 *　@param pFbdev 	参考结构体 fbdev
 * @param minY		y较小的点
 *　@param maxY		y较大的点
　* @param r			颜色对应的R值
 *　@param g 		颜色对应的G值
 *　@param b			颜色对应的B值
 */
void draw_v_line(PFBDEV pFbdev,POINT minY,POINT maxY,uint8_t r,uint8_t g,uint8_t b);


#endif //_LINE_H_ 
