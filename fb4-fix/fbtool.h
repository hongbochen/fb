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

typedef struct fbdev{
	int fb;   //framebuffer打开后的唯一标识符
	struct fb_fix_screeninfo fb_fix;
	struct fb_var_screeninfo fb_var;
	char dev[20];
}FBDEV,*PFBDEV;

//打开framebuffer
int fb_open(PFBDEV pFbdev);
//关闭framebuffer
int fb_close(PFBDEV pFbdev);
//打印frame buffer 所占内存的开始地址　
void pmem_start(PFBDEV pFbdev);
//打印FB_TYPE
void p_type(PFBDEV pFbdev);
//打印可见清晰度
void p_visible_res(PFBDEV pFbdev);
//打印虚拟分辨率
void p_virt_res(PFBDEV pFbdev);
//打印虚拟到可见的偏移量
void p_offset(PFBDEV pFbdev);
//打印每个像素的位数
void p_bpp(PFBDEV pFbdev);
//打印R,G,B和透明度
void p_rgbt(PFBDEV pFbdev);
//打印在内存中的高度和宽度
void p_hw(PFBDEV pFbdev);

#endif
