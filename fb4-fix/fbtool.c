#include "fbtool.h"

//打开并且初始化该frame buffer
int fb_open(PFBDEV pFbdev)
{
	//打开frame buffer
	pFbdev->fb = open(pFbdev->dev,O_RDWR);
	
	if(pFbdev->fb < 0)
	{	
		printf("打开错误 %s : %n.请检查内核配置\n",pFbdev->dev);
		return 0;
	}

	//　初始化fb_var
	if(-1 == ioctl(pFbdev->fb,FBIOGET_VSCREENINFO,&(pFbdev->fb_var)))
	{
		printf("ioctl FBIOGET_VSCREENINFO\n");
		return 0;
	}

	//　初始化fb_fix
	if(-1 == ioctl(pFbdev->fb,FBIOGET_FSCREENINFO,&(pFbdev->fb_fix)))
	{
		printf("ioctl FBIOGET_FSCREENINFO\n");
		return 0;
	}

	return 1;
}

//关闭frame buffer
int fb_close(PFBDEV pFbdev)
{
	close(pFbdev->fb);
	pFbdev->fb = -1;
}

//打印frame buffer 所占内存的开始地址　
void pmem_start(PFBDEV pFbdev)
{
	printf("frame buffer所占内存的开始地址为:%lu\n",pFbdev->fb_fix.smem_start);
}

//打印FB_TYPE
void p_type(PFBDEV pFbdev)
{
	printf("frame buffer 的类型为:%u\n",pFbdev->fb_fix.type);
}

//打印可见清晰度
void p_visible_res(PFBDEV pFbdev)
{
	printf("frame buffer的可见清晰度为：\n\tx = %u\n\ty = %u\n",pFbdev->fb_var.xres,pFbdev->fb_var.yres);
}

//打印虚拟分辨率
void p_virt_res(PFBDEV pFbdev)
{
	printf("frame buffer的虚拟清晰度为：\n\tx = %u\n\ty = %u\n",pFbdev->fb_var.xres_virtual,pFbdev->fb_var.yres_virtual);
}

//打印虚拟到可见的偏移量
void p_offset(PFBDEV pFbdev)
{
	printf("frame buffer的虚拟分辨率到可见分辨率的偏移量为:\n\tx = %u\n\ty = %u\n",pFbdev->fb_var.xoffset,pFbdev->fb_var.yoffset);
}

//打印每个像素的位数
void p_bpp(PFBDEV pFbdev)
{
	printf("frame buffer的BPP为：%d\n",pFbdev->fb_var.bits_per_pixel);
}

//打印R,G,B和透明度
void p_rgbt(PFBDEV pFbdev)
{
	printf("这个后面再说!!\n");
}

//打印在内存中的高度和宽度
void p_hw(PFBDEV pFbdev)
{
	printf("frame buffer在内存中所占的高度和宽度分别是:\n\t宽度 = %u\n\t高度 = %u\n",pFbdev->fb_var.height,pFbdev->fb_var.width);
}






















