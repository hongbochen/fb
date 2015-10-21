#include "fbtool.h"

int main()
{
	FBDEV fbdev;

	memset(&fbdev,0,sizeof(FBDEV));
	strcpy(fbdev.dev,"/dev/fb0");	

	if(0 == fb_open(&fbdev)){
		printf("Open fail!!\n");
		return -1;
	}
	
	//打印frame buffer 所占内存的开始地址　
	pmem_start(&fbdev);
	//打印FB_TYPE
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

	fb_close(&fbdev);

	return 0;
}
