/*
 * 实现画矩形或者是填充矩形
 * @作者 陈洪波
 */

#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include "fbtool.h"
#include "point.h"
#include "line.h"

/*
 * 画一个矩形框
 *　@param pFbdev 	参考结构体 fbdev
 *　@param lu 		矩形框左上角的点		
 *　@param ld 		矩形框左下角的点
　*　@param ru		矩形框右上角的点
 * @param rd		矩形框右下角的点
 * @param r			颜色对应的R值
 *　@param g 		颜色对应的G值
 *　@param b			颜色对应的B值
　* @return void
 */
void draw_rec(PFBDEV pFbdev,POINT lu,POINT ld,POINT ru,POINT rd,uint8_t r,uint8_t g,uint8_t b);

/*
 * 填充一个矩形框
 *　@param pFbdev 	参考结构体 fbdev
 *　@param lu 		矩形框左上角的点		
 *　@param ld 		矩形框左下角的点
　*　@param ru		矩形框右上角的点
 * @param rd		矩形框右下角的点
 * @param r			颜色对应的R值
 *　@param g 		颜色对应的G值
 *　@param b			颜色对应的B值
　* @return void
 */
void fill_rec(PFBDEV pFbdev,POINT lu,POINT ld,POINT ru,POINT rd,uint8_t r,uint8_t g,uint8_t b);



#endif  //_RECTANGLE_H_

