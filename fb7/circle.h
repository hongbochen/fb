/*
 * 画圆或者是填充圆的实现
 * @作者 陈洪波
 */

#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include "fbtool.h"
#include "point.h"
#include <math.h>

/*
 * 画一个圆
 *　@param pFbdev 	参考结构体 fbdev
　* @param x 		圆的圆心所在的点的x值
 * @param y			圆的圆心所在的点的y值
 * @param radius 	圆的半径的长度
 * @color			代表颜色的字符串
 * @return void
 */
void draw_circle(PFBDEV pFbdev,int x,int y,int radius,const char *color);

#endif //_CIRCLE_H_
