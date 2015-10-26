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

	//将物理地址映射到虚拟地址
	pFbdev->fb_mem_offset = (unsigned long)pFbdev->fb_fix.smem_start & (~PAGE_MASK);

	pFbdev->fb_mem = (unsigned long int)mmap(NULL,pFbdev->fb_fix.smem_len + pFbdev->fb_mem_offset,PROT_READ|PROT_WRITE,MAP_SHARED,pFbdev->fb,0);
	
	if(-1L == (long)pFbdev->fb_mem){
		printf("mmap error with mem:%lu,mem_offset:%lu\n",pFbdev->fb_mem_offset,pFbdev->fb_mem);
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
	printf("frame buffer 的类型为:%d\n",pFbdev->fb_fix.type);
}

//打印可见清晰度
void p_visible_res(PFBDEV pFbdev)
{
	printf("frame buffer的可见清晰度为：\n\tx = %d\n\ty = %d\n",pFbdev->fb_var.xres,pFbdev->fb_var.yres);
}

//打印虚拟分辨率
void p_virt_res(PFBDEV pFbdev)
{
	printf("frame buffer的虚拟清晰度为：\n\tx = %d\n\ty = %d\n",pFbdev->fb_var.xres_virtual,pFbdev->fb_var.yres_virtual);
}

//打印虚拟到可见的偏移量
void p_offset(PFBDEV pFbdev)
{
	printf("frame buffer的虚拟分辨率到可见分辨率的偏移量为:\n\tx = %d\n\ty = %d\n",pFbdev->fb_var.xoffset,pFbdev->fb_var.yoffset);
}

//打印每个像素的位数
void p_bpp(PFBDEV pFbdev)
{
	printf("frame buffer的BPP为：%d\n",pFbdev->fb_var.bits_per_pixel);
}

//打印R,G,B和透明度
void p_rgbt(PFBDEV pFbdev)
{
	//R位域
	printf("R位域:\n");
	struct fb_bitfield bf = pFbdev->fb_var.red;
	printf("\t开始:%d\n",bf.offset);
	printf("\t长度:%d\n",bf.length);
	printf("\tMSB:%d\n",bf.msb_right);
	
	//G位域
	printf("G位域:\n");
	bf = pFbdev->fb_var.green;
	printf("\t开始:%d\n",bf.offset);
	printf("\t长度:%d\n",bf.length);
	printf("\tMSB:%d\n",bf.msb_right);

	// B位域
	printf("B位域:\n");
	bf = pFbdev->fb_var.blue;
	printf("\t开始:%d\n",bf.offset);
	printf("\t长度:%d\n",bf.length);
	printf("\tMSB:%d\n",bf.msb_right);

	// 透明度位域
	printf("透明度位域:\n");
	bf = pFbdev->fb_var.transp;
	printf("\t开始:%d\n",bf.offset);
	printf("\t长度:%d\n",bf.length);
	printf("\tMSB:%d\n",bf.msb_right);
}

//打印在内存中的高度和宽度
void p_hw(PFBDEV pFbdev)
{
	printf("frame buffer在内存中所占的高度和宽度分别是:\n\t宽度 = %d\n\t高度 = %d\n",pFbdev->fb_var.height,pFbdev->fb_var.width);
}

//清空控制台　
void clear_con(void *addr,int n,size_t len)
{
	memset(addr,n,len);
}

//映射到内存
void fb_memcpy(void *addr,void *color,size_t len)
{
	memcpy(addr,color,len);
}

//画点
void draw_dot(PFBDEV pFbdev,POINT p,uint8_t r,uint8_t g,uint8_t b)
{
	uint32_t offset;
	uint8_t color[4];
	color[0] = b;
	color[1] = g;
	color[2] = r;
	color[3] = 0x0; //透明度
	
	offset = p.y * pFbdev->fb_fix.line_length + 4 * p.x;
	//将操作映射到内存中
	fb_memcpy((void*)pFbdev->fb_mem + pFbdev->fb_mem_offset + offset,color,4);
	
}

//画横线
void draw_h_line(PFBDEV pFbdev,POINT minX,POINT maxX,uint8_t r,uint8_t g,uint8_t b)
{
	int m;
	
	int length = maxX.x - minX.x;
	for(m = 0;m < length;m++){
		POINT tp;
		tp.x = minX.x + m;
		tp.y = minX.y;

		draw_dot(pFbdev,tp,r,g,b);
	}
}

//画竖线
void draw_v_line(PFBDEV pFbdev,POINT minY,POINT maxY,uint8_t r,uint8_t g,uint8_t b)
{
	int m;
	
	int length = maxY.y - minY.y;
	for(m = 0;m < length;m++){
		POINT tp;
		tp.x = minY.x;
		tp.y = minY.y + m;

		draw_dot(pFbdev,tp,r,g,b);
	}
}


//画一个矩形框
void draw_rec(PFBDEV pFbdev,POINT lu,POINT ld,POINT ru,POINT rd,uint8_t r,uint8_t g,uint8_t b)
{
	draw_h_line(pFbdev,lu,ru,r,g,b);
	draw_h_line(pFbdev,ld,rd,r,g,b);
	draw_v_line(pFbdev,lu,ld,r,g,b);
	draw_v_line(pFbdev,ru,rd,r,g,b);
}

//填充一个矩形框
void fill_rec(PFBDEV pFbdev,POINT lu,POINT ld,POINT ru,POINT rd,uint8_t r,uint8_t g,uint8_t b)
{
	int xlen = ru.x - lu.x;
	int ylen = ld.y - lu.y;

	int m,n;

	for(m = 0;m < ylen;m++){
		for(n = 0;n < xlen;n++){
			POINT p;
			p.x = lu.x + n;
			p.y = lu.y + m;
	
			draw_dot(pFbdev,p,r,g,b);	
		}	
	}
}


















