#ifndef __FBTOOL_H_
#define __FBTOOL_H_

#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <stddef.h>
#include <string.h>
#include <sys/mman.h>
#include <math.h>
#include <stdint.h>
#include "page.h"
#include "color.h"

/**
 * 该结构体主要是定义了一组保存frame buffer的属性
 * @property fb 				frame buffer打开后的唯一标识符
 * @property fb_fix 			frame buffer的固定属性就保存在这个结构体中
 *　@property fb_var 			frame buffer的可变属性保存在这个结构体中
 * @property fb_mem_offset 		frame buffer所占内存的偏移量
 * @property fb_mem				frame buffer的映射到进程内存空间的起始地址
 */
typedef struct fbdev{
	int fb;  
	struct fb_fix_screeninfo fb_fix;
	struct fb_var_screeninfo fb_var;
	/* 新增 */
	unsigned long fb_mem_offset; 
	unsigned long fb_mem;

	char dev[20];
}FBDEV,*PFBDEV;

/**
 * 该结构体用于定位点的位置，包括横坐标，纵坐标，深坐标
 *　@property x 	横坐标
 * @property y	纵坐标
 * @property z	深坐标（这个用于3D）
 */
typedef struct point{
	int x;
	int y;
	int z;
}POINT,*PPOINT;

/*
 * 该函数用于打开frame buffer
 * @param pFbdev 参照结构体 fbdev
 * @return 	0 - 打开失败
　*			1 - 打开成功
 */
int fb_open(PFBDEV pFbdev);

/*
 * 该函数用于关闭frame buffer设备
 * @param pFbdev 参照结构体 fbdev
 * @return 	0 - 关闭成功
 * 			>0 - 关闭失败
 */
int fb_close(PFBDEV pFbdev);

/*
 * 该函数用于打印frame buffer 所占内存的开始地址　
 * @param pFbdev 参照结构体 fbdev
 * @return 	void 
 */
void pmem_start(PFBDEV pFbdev);

/*
 * 该函数用于打印FB_TYPE
 * @param pFbdev 参照结构体 fbdev
 * @return 	void 
 */
void p_type(PFBDEV pFbdev);

/*
 * 该函数用于打印可见清晰度
 * @param pFbdev 参照结构体 fbdev
 * @return 	void 
 */
void p_visible_res(PFBDEV pFbdev);

/*
 * 该函数用于打印虚拟分辨率
 * @param pFbdev 参照结构体 fbdev
 * @return 	void 
 */
void p_virt_res(PFBDEV pFbdev);

/*
 * 该函数用于打印虚拟到可见的偏移量
 * @param pFbdev 参照结构体 fbdev
 * @return 	void 
 */
void p_offset(PFBDEV pFbdev);

/*
 * 该函数用于打印每个像素的位数
 * @param pFbdev 参照结构体 fbdev
 * @return 	void 
 */
void p_bpp(PFBDEV pFbdev);

/*
 * 该函数用于打印R,G,B和透明度
 * @param pFbdev 参照结构体 fbdev
 * @return 	void 
 */
void p_rgbt(PFBDEV pFbdev);

/*
 * 该函数用于打印在内存中的高度和宽度
 * @param pFbdev 参照结构体 fbdev
 * @return 	void 
 */
void p_hw(PFBDEV pFbdev);

/*
 * 将addr开始的len个字符用n替换
 * @param addr	开始的地址
 * @param n		替换后的字符
 * @param len	要替换的字符的个数
 * @return 	void 
 */
void clear_con(void *addr,int n,size_t len);

/*
 * 该函数将逻辑地址空间的数据映射到内存当中
 * @param addr  内存空间的地址
 * @param color 颜色值
 * @param len 	需要映射的长度
　* @return void 
 */
void fb_memcpy(void *addr,void *color,size_t len);

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

/*
 * 根据字符串获得相应的RGBT
 * @param color 颜色对应的字符串 
 *　@return 返回代表颜色的结构体 RGBT
 */
RGBT getRGBT(const char *color);

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

#endif












