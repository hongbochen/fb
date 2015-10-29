#ifndef __FBTOOL_H_
#define __FBTOOL_H_

#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stddef.h>
#include <string.h>
#include <sys/mman.h>
#include <linux/fb.h>
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
 * 根据字符串获得相应的RGBT
 * @param color 颜色对应的字符串 
 *　@return 返回代表颜色的结构体 RGBT
 */
RGBT getRGBT(const char *color);



#endif












