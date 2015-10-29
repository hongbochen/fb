#include "line.h"
#include "point.h"
#include "rectangle.h"
#include "circle.h"

int main()
{
	FBDEV fbdev;

	memset(&fbdev,0,sizeof(FBDEV));
	strcpy(fbdev.dev,"/dev/fb0");	

	if(0 == fb_open(&fbdev)){
		printf("Open fail!!\n");
		return -1;
	}

	/**
	//打印frame buffer 所占内存的开始地址　
	pmem_start(&fbdev);
	//打印FB_TYPE-c kbd.c
	p_type(&fbdev);
	//打印可见清晰度
	p_visible_res(&fbdev);
	//打印虚拟分辨率
	p_virt_res(&fbdev);
	//打印虚拟到可见的偏移量
	p_offset(&fbdev);
	//打印每个像素的位数
	p_bpp(&fbdev);
	//打印R,G,B和透明度
	p_rgbt(&fbdev);
	//打印在内存中的高度和宽度
	p_hw(&fbdev); 
	//打印fb的RGB和透明度的位域
	p_rgbt(&fbdev);

	getchar(); 
	
	//清屏
	clear_con(fbdev.fb_mem + fbdev.fb_mem_offset,-1,fbdev.fb_fix.smem_len); */

	
	POINT p;
	p.x = 100;
	p.y = 100;
	
	/*
	//画点
	draw_x_y_dot(&fbdev,100,100,0x0,0xff,0x0);
	
	RGBT c;
	c.r = 0xff;
	c.g = 0xff;
	c.b = 0xff;
	c.t = 0x00;
	//draw_x_y_color_dot_with_trans(&fbdev,100,100,RED);
	draw_x_y_color_dot_with_string(&fbdev,100,100,YELLOW);

	//划横线
	//画横线
	POINT p21;
	p21.x = 120;
	p21.y = 100;
	POINT p2;
	p2.x = 160;
	p2.y = 160;
	//draw_h_line(&fbdev,p21,p2,0x0,0xff,0x0);
	draw_h_line_with_string(&fbdev,p21,p2,RED);

	//画竖线
	POINT p31;
	p31.x = 100;
	p31.y = 120;
	POINT p3;
	p3.x = 100;
	p3.y = 160;
	draw_v_line(&fbdev,p31,p3,0x0,0xff,0x0);

	POINT p40;
	p40.x = 120;
	p40.y = 120;
	POINT p41;
	p41.x = 160;
	p41.y = 120;
	POINT p42;
	p42.x = 120;
	p42.y = 160;
	POINT p43;
	p43.x = 160;
	p43.y = 160;
	//画矩形
	draw_rec(&fbdev,p40,p42,p41,p43,0x0,0xff,0x0);

	POINT p50;
	p50.x = 100;
	p50.y = 180;
	POINT p51;
	p51.x = 160;
	p51.y = 180;
	POINT p52;
	p52.x = 100;
	p52.y = 220;
	POINT p53;
	p53.x = 160;
	p53.y = 220;
	//填充
	fill_rec(&fbdev,p50,p52,p51,p53,0x0,0xff,0x0);*/

	int x = 500;
	while(1){
		draw_circle(&fbdev,x,400,100,RED);
		usleep(100);

		x++;

		if(x == 1200)
			break;
		
		clear_con(fbdev.fb_mem + fbdev.fb_mem_offset,1,fbdev.fb_fix.smem_len);
			
	}

	fb_close(&fbdev);
		
	return 0;
}














	
