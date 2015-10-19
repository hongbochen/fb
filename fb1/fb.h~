#ifndef _LINUX_FB_H
#define _LINUX_FB_H

#include <linux/types.h>
#include <linux/i2c.h>

struct dentry;

/* Definitions of frame buffers		frame buffer的定义	*/

#define FB_MAX			32	/* sufficient for now 　对于现在来说足够了　*/

/* ioctls
   0x46 is 'F'								*/
#define FBIOGET_VSCREENINFO	0x4600
#define FBIOPUT_VSCREENINFO	0x4601
#define FBIOGET_FSCREENINFO	0x4602
#define FBIOGETCMAP		0x4604
#define FBIOPUTCMAP		0x4605
#define FBIOPAN_DISPLAY		0x4606
#ifdef __KERNEL__
#define FBIO_CURSOR            _IOWR('F', 0x08, struct fb_cursor_user)
#else
#define FBIO_CURSOR            _IOWR('F', 0x08, struct fb_cursor)
#endif
/* 0x4607-0x460B are defined below */
/* #define FBIOGET_MONITORSPEC	0x460C */
/* #define FBIOPUT_MONITORSPEC	0x460D */
/* #define FBIOSWITCH_MONIBIT	0x460E */
#define FBIOGET_CON2FBMAP	0x460F
#define FBIOPUT_CON2FBMAP	0x4610
#define FBIOBLANK		0x4611		/* arg: 0 or vesa level + 1 */
#define FBIOGET_VBLANK		_IOR('F', 0x12, struct fb_vblank)
#define FBIO_ALLOC              0x4613
#define FBIO_FREE               0x4614
#define FBIOGET_GLYPH           0x4615
#define FBIOGET_HWCINFO         0x4616
#define FBIOPUT_MODEINFO        0x4617
#define FBIOGET_DISPINFO        0x4618


#define FB_TYPE_PACKED_PIXELS		0	/* Packed Pixels 填充的像素　*/
#define FB_TYPE_PLANES			1	/* Non interleaved planes 非交错平面　*/
#define FB_TYPE_INTERLEAVED_PLANES	2	/* Interleaved planes　交错的平面　*/
#define FB_TYPE_TEXT			3	/* Text/attributes　文本/属性　*/
#define FB_TYPE_VGA_PLANES		4	/* EGA/VGA planes	EGA/VGA　平面　*/

#define FB_AUX_TEXT_MDA		0	/* Monochrome text 单色文本　*/
#define FB_AUX_TEXT_CGA		1	/* CGA/EGA/VGA Color text CGA/EGA/VGA色彩文本　*/
#define FB_AUX_TEXT_S3_MMIO	2	/* S3 MMIO fasttext */
#define FB_AUX_TEXT_MGA_STEP16	3	/* MGA Millenium I: text, attr, 14 reserved bytes */
#define FB_AUX_TEXT_MGA_STEP8	4	/* other MGAs:      text, attr,  6 reserved bytes */
#define FB_AUX_TEXT_SVGA_GROUP	8	/* 8-15: SVGA tileblit compatible modes */
#define FB_AUX_TEXT_SVGA_MASK	7	/* lower three bits says step */
#define FB_AUX_TEXT_SVGA_STEP2	8	/* SVGA text mode:  text, attr */
#define FB_AUX_TEXT_SVGA_STEP4	9	/* SVGA text mode:  text, attr,  2 reserved bytes */
#define FB_AUX_TEXT_SVGA_STEP8	10	/* SVGA text mode:  text, attr,  6 reserved bytes */
#define FB_AUX_TEXT_SVGA_STEP16	11	/* SVGA text mode:  text, attr, 14 reserved bytes */
#define FB_AUX_TEXT_SVGA_LAST	15	/* reserved up to 15 */

#define FB_AUX_VGA_PLANES_VGA4		0	/* 16 color planes (EGA/VGA) */
#define FB_AUX_VGA_PLANES_CFB4		1	/* CFB4 in planes (VGA) */
#define FB_AUX_VGA_PLANES_CFB8		2	/* CFB8 in planes (VGA) */

#define FB_VISUAL_MONO01		0	/* Monochr. 1=Black 0=White 　1=黑色，２＝白色*/
#define FB_VISUAL_MONO10		1	/* Monochr. 1=White 0=Black 1=白色，２＝黑色*/
#define FB_VISUAL_TRUECOLOR		2	/* True color 真实的颜色 */
#define FB_VISUAL_PSEUDOCOLOR		3	/* Pseudo color (like atari) 伪颜色*/
#define FB_VISUAL_DIRECTCOLOR		4	/* Direct color 直接颜色 */
#define FB_VISUAL_STATIC_PSEUDOCOLOR	5	/* Pseudo color readonly 只读伪颜色*/

#define FB_ACCEL_NONE		0	/* no hardware accelerator	没有硬件加速　*/
#define FB_ACCEL_ATARIBLITT	1	/* Atari Blitter	*/
#define FB_ACCEL_AMIGABLITT	2	/* Amiga Blitter                */
#define FB_ACCEL_S3_TRIO64	3	/* Cybervision64 (S3 Trio64)    */
#define FB_ACCEL_NCR_77C32BLT	4	/* RetinaZ3 (NCR 77C32BLT)      */
#define FB_ACCEL_S3_VIRGE	5	/* Cybervision64/3D (S3 ViRGE)	*/
#define FB_ACCEL_ATI_MACH64GX	6	/* ATI Mach 64GX family		*/
#define FB_ACCEL_DEC_TGA	7	/* DEC 21030 TGA		*/
#define FB_ACCEL_ATI_MACH64CT	8	/* ATI Mach 64CT family		*/
#define FB_ACCEL_ATI_MACH64VT	9	/* ATI Mach 64CT family VT class */
#define FB_ACCEL_ATI_MACH64GT	10	/* ATI Mach 64CT family GT class */
#define FB_ACCEL_SUN_CREATOR	11	/* Sun Creator/Creator3D	*/
#define FB_ACCEL_SUN_CGSIX	12	/* Sun cg6			*/
#define FB_ACCEL_SUN_LEO	13	/* Sun leo/zx			*/
#define FB_ACCEL_IMS_TWINTURBO	14	/* IMS Twin Turbo		*/
#define FB_ACCEL_3DLABS_PERMEDIA2 15	/* 3Dlabs Permedia 2		*/
#define FB_ACCEL_MATROX_MGA2064W 16	/* Matrox MGA2064W (Millenium)	*/
#define FB_ACCEL_MATROX_MGA1064SG 17	/* Matrox MGA1064SG (Mystique)	*/
#define FB_ACCEL_MATROX_MGA2164W 18	/* Matrox MGA2164W (Millenium II) */
#define FB_ACCEL_MATROX_MGA2164W_AGP 19	/* Matrox MGA2164W (Millenium II) */
#define FB_ACCEL_MATROX_MGAG100	20	/* Matrox G100 (Productiva G100) */
#define FB_ACCEL_MATROX_MGAG200	21	/* Matrox G200 (Myst, Mill, ...) */
#define FB_ACCEL_SUN_CG14	22	/* Sun cgfourteen		 */
#define FB_ACCEL_SUN_BWTWO	23	/* Sun bwtwo			*/
#define FB_ACCEL_SUN_CGTHREE	24	/* Sun cgthree			*/
#define FB_ACCEL_SUN_TCX	25	/* Sun tcx			*/
#define FB_ACCEL_MATROX_MGAG400	26	/* Matrox G400			*/
#define FB_ACCEL_NV3		27	/* nVidia RIVA 128              */
#define FB_ACCEL_NV4		28	/* nVidia RIVA TNT		*/
#define FB_ACCEL_NV5		29	/* nVidia RIVA TNT2		*/
#define FB_ACCEL_CT_6555x	30	/* C&T 6555x			*/
#define FB_ACCEL_3DFX_BANSHEE	31	/* 3Dfx Banshee			*/
#define FB_ACCEL_ATI_RAGE128	32	/* ATI Rage128 family		*/
#define FB_ACCEL_IGS_CYBER2000	33	/* CyberPro 2000		*/
#define FB_ACCEL_IGS_CYBER2010	34	/* CyberPro 2010		*/
#define FB_ACCEL_IGS_CYBER5000	35	/* CyberPro 5000		*/
#define FB_ACCEL_SIS_GLAMOUR    36	/* SiS 300/630/540              */
#define FB_ACCEL_3DLABS_PERMEDIA3 37	/* 3Dlabs Permedia 3		*/
#define FB_ACCEL_ATI_RADEON	38	/* ATI Radeon family		*/
#define FB_ACCEL_I810           39      /* Intel 810/815                */
#define FB_ACCEL_SIS_GLAMOUR_2  40	/* SiS 315, 650, 740		*/
#define FB_ACCEL_SIS_XABRE      41	/* SiS 330 ("Xabre")		*/
#define FB_ACCEL_I830           42      /* Intel 830M/845G/85x/865G     */
#define FB_ACCEL_NV_10          43      /* nVidia Arch 10               */
#define FB_ACCEL_NV_20          44      /* nVidia Arch 20               */
#define FB_ACCEL_NV_30          45      /* nVidia Arch 30               */
#define FB_ACCEL_NV_40          46      /* nVidia Arch 40               */
#define FB_ACCEL_XGI_VOLARI_V	47	/* XGI Volari V3XT, V5, V8      */
#define FB_ACCEL_XGI_VOLARI_Z	48	/* XGI Volari Z7                */
#define FB_ACCEL_OMAP1610	49	/* TI OMAP16xx                  */
#define FB_ACCEL_TRIDENT_TGUI	50	/* Trident TGUI			*/
#define FB_ACCEL_TRIDENT_3DIMAGE 51	/* Trident 3DImage		*/
#define FB_ACCEL_TRIDENT_BLADE3D 52	/* Trident Blade3D		*/
#define FB_ACCEL_TRIDENT_BLADEXP 53	/* Trident BladeXP		*/
#define FB_ACCEL_CIRRUS_ALPINE   53	/* Cirrus Logic 543x/544x/5480	*/
#define FB_ACCEL_NEOMAGIC_NM2070 90	/* NeoMagic NM2070              */
#define FB_ACCEL_NEOMAGIC_NM2090 91	/* NeoMagic NM2090              */
#define FB_ACCEL_NEOMAGIC_NM2093 92	/* NeoMagic NM2093              */
#define FB_ACCEL_NEOMAGIC_NM2097 93	/* NeoMagic NM2097              */
#define FB_ACCEL_NEOMAGIC_NM2160 94	/* NeoMagic NM2160              */
#define FB_ACCEL_NEOMAGIC_NM2200 95	/* NeoMagic NM2200              */
#define FB_ACCEL_NEOMAGIC_NM2230 96	/* NeoMagic NM2230              */
#define FB_ACCEL_NEOMAGIC_NM2360 97	/* NeoMagic NM2360              */
#define FB_ACCEL_NEOMAGIC_NM2380 98	/* NeoMagic NM2380              */
#define FB_ACCEL_PXA3XX		 99	/* PXA3xx			*/

#define FB_ACCEL_SAVAGE4        0x80	/* S3 Savage4                   */
#define FB_ACCEL_SAVAGE3D       0x81	/* S3 Savage3D                  */
#define FB_ACCEL_SAVAGE3D_MV    0x82	/* S3 Savage3D-MV               */
#define FB_ACCEL_SAVAGE2000     0x83	/* S3 Savage2000                */
#define FB_ACCEL_SAVAGE_MX_MV   0x84	/* S3 Savage/MX-MV              */
#define FB_ACCEL_SAVAGE_MX      0x85	/* S3 Savage/MX                 */
#define FB_ACCEL_SAVAGE_IX_MV   0x86	/* S3 Savage/IX-MV              */
#define FB_ACCEL_SAVAGE_IX      0x87	/* S3 Savage/IX                 */
#define FB_ACCEL_PROSAVAGE_PM   0x88	/* S3 ProSavage PM133           */
#define FB_ACCEL_PROSAVAGE_KM   0x89	/* S3 ProSavage KM133           */
#define FB_ACCEL_S3TWISTER_P    0x8a	/* S3 Twister                   */
#define FB_ACCEL_S3TWISTER_K    0x8b	/* S3 TwisterK                  */
#define FB_ACCEL_SUPERSAVAGE    0x8c    /* S3 Supersavage               */
#define FB_ACCEL_PROSAVAGE_DDR  0x8d	/* S3 ProSavage DDR             */
#define FB_ACCEL_PROSAVAGE_DDRK 0x8e	/* S3 ProSavage DDR-K           */


/**
 * 该结构体用于描述显卡自身的属性
 * 包括识别符，缓存地址，显卡类型等
 *
 */
struct fb_fix_screeninfo {
	char id[16];			/* identification string eg "TT Builtin"  标识符字符串*/
	unsigned long smem_start;	/* Start of frame buffer mem 　frame buffer所占内存的开始地址　*/
					/* (physical address) 这里说的是物理地址　*/
	__u32 smem_len;			/* Length of frame buffer mem frame buffer所占内存的长度 */
	__u32 type;			/* see FB_TYPE_*	查看FB_BYTE_* */
	__u32 type_aux;			/* Interleave for interleaved Planes 交织交错的平面　*/
	__u32 visual;			/* see FB_VISUAL_*	查看FB_VISUAL_*	*/ 
	__u16 xpanstep;			/* zero if no hardware panning  如何没有硬件支持的话为0 */
	__u16 ypanstep;			/* zero if no hardware panning  如果没有硬件支持的话为０*/
	__u16 ywrapstep;		/* zero if no hardware ywrap　如果没有硬件ywrap的话为０　*/
	__u32 line_length;		/* length of a line in bytes    一行的长度，以byte为单位 */
	unsigned long mmio_start;	/* Start of Memory Mapped I/O   映射到I/O的内存的开始地址 */
					/* (physical address) 物理地址*/
	__u32 mmio_len;			/* Length of Memory Mapped I/O  映射到I/O的内存长度*/
	__u32 accel;			/* Indicate to driver which	指示到驱动程序　*/
					/*  specific chip/card we have	特别是我们拥有的芯片/卡*/
	__u16 reserved[3];		/* Reserved for future compatibility 为后来的兼容性保留*/
};

/* Interpretation of offset for color fields: All offsets are from the right,
 * inside a "pixel" value, which is exactly 'bits_per_pixel' wide (means: you
 * can use the offset as right argument to <<). A pixel afterwards is a bit
 * stream and is written to video memory as that unmodified.
 *
 * 色域偏移的解释：所有的偏移量都来自于右边，在一个＂像素＂值里面，实际上是'bits_per_pixel'
 * 的宽度（也就是说：你可以使用该偏移量作为 << 的右参数）．一个像素之后是一个位流，并且
 *　作为未被修改而被写到视频内存中．
 *
 * For pseudocolor: offset and length should be the same for all color
 * components. Offset specifies the position of the least significant bit
 * of the pallette index in a pixel value. Length indicates the number
 * of available palette entries (i.e. # of entries = 1 << length).
 *
 * 对于伪色彩来说：对于所有的颜色部分，偏移量和长度应该是相同的．偏移量指定了
 *　在一个像素值里的调色板索引的最低有效位的位置．长度指明了可用的调色板入口的
 * 数量．
 */　
struct fb_bitfield {
	__u32 offset;			/* 位域的开始	*/
	__u32 length;			/* length of bitfield　位域的长度　*/
	__u32 msb_right;		/* != 0 : Most significant bit is　不等于０，大多数重要的位是右边的 */ 
					/* right */ 
};

#define FB_NONSTD_HAM		1	/* Hold-And-Modify (HAM)   保持和修改     */
#define FB_NONSTD_REV_PIX_IN_B	2	/* order of pixels in each byte is reversed  在每一个字节中的像素的顺序被保留下来　*/

#define FB_ACTIVATE_NOW		0	/* set values immediately (or vbl) 立即设定颜色　*/
#define FB_ACTIVATE_NXTOPEN	1	/* activate on next open	在下一个打开的时候激活　*/
#define FB_ACTIVATE_TEST	2	/* don't set, round up impossible 不设置 */
#define FB_ACTIVATE_MASK       15
					/* values			*/
#define FB_ACTIVATE_VBL	       16	/* activate values on next vbl  在下一个vbl的时候激活值 */
#define FB_CHANGE_CMAP_VBL     32	/* change colormap on vbl	在vbl的时候改变色彩映射　*/
#define FB_ACTIVATE_ALL	       64	/* change all VCs on this fb 在这个fb中改变所有的VC */
#define FB_ACTIVATE_FORCE     128	/* force apply even when no change */
#define FB_ACTIVATE_INV_MODE  256       /* invalidate videomode  即使在没有改变无效视频模式的时候强制应用　*/

#define FB_ACCELF_TEXT		1	/* (OBSOLETE) see fb_info.flags and vc_mode 已过时 */

#define FB_SYNC_HOR_HIGH_ACT	1	/* horizontal sync high active	高活性水平同步　*/
#define FB_SYNC_VERT_HIGH_ACT	2	/* vertical sync high active 高活性垂直同步　*/
#define FB_SYNC_EXT		4	/* external sync 外部同步　*/
#define FB_SYNC_COMP_HIGH_ACT	8	/* composite sync high active  高活性复合同步　 */
#define FB_SYNC_BROADCAST	16	/* broadcast video timings 广播视频时序     */
					/* vtotal = 144d/288n/576i => PAL  */
					/* vtotal = 121d/242n/484i => NTSC */
#define FB_SYNC_ON_GREEN	32	/* sync on green 在绿色下同步　*/

#define FB_VMODE_NONINTERLACED  0	/* non interlaced 非交错模式　*/
#define FB_VMODE_INTERLACED	1	/* interlaced	交错模式　*/
#define FB_VMODE_DOUBLE		2	/* double scan 双扫描模式 */
#define FB_VMODE_ODD_FLD_FIRST	4	/* interlaced: top line first 交错的：顶行优先　*/
#define FB_VMODE_MASK		255

#define FB_VMODE_YWRAP		256	/* ywrap instead of panning    ywrap而不是panning  */
#define FB_VMODE_SMOOTH_XPAN	512	/* smooth xpan possible (internally used)  平滑的xpan(内部使用) */
#define FB_VMODE_CONUPDATE	512	/* don't update x/yoffset	不要更新 x/yoffset*/

/*
 * Display rotation support
 *
 * 旋转支持显示
 */
#define FB_ROTATE_UR      0
#define FB_ROTATE_CW      1
#define FB_ROTATE_UD      2
#define FB_ROTATE_CCW     3

#define PICOS2KHZ(a) (1000000000UL/(a))
#define KHZ2PICOS(a) (1000000000UL/(a))

/**
 * 用于描述显卡的一般特性，比如实际分辨率，虚拟分辨率，实际分辨率和虚拟
 *　分辨率之间的位移等
　*/
struct fb_var_screeninfo {
	__u32 xres;			/* visible resolution	可见解析度	*/
	__u32 yres;
	__u32 xres_virtual;		/* virtual resolution  虚拟解析度		*/
	__u32 yres_virtual;
	__u32 xoffset;			/* offset from virtual to visible  虚拟到可见的偏移量 */
	__u32 yoffset;			/* resolution			*/

	__u32 bits_per_pixel;		/* guess what	BPP : 每个像素的位数		*/
	__u32 grayscale;		/* != 0 Graylevels instead of colors !=０指灰度而不是颜色 */

	//如果是真实的颜色的话表示在fb内存中的位域，如果不是颜色的话，仅仅就是长度
	//在这里保存的是fb缓存的R/G/B位域
	struct fb_bitfield red;		/* bitfield in fb mem if true color, */
	struct fb_bitfield green;	/* else only length is significant */
	struct fb_bitfield blue;
	struct fb_bitfield transp;	/* transparency	透明度		*/	

	__u32 nonstd;			/* != 0 Non standard pixel format !=0 非标准像素格式 */

	__u32 activate;			/* see FB_ACTIVATE_*	查看FB_ACTIVATE_*  */

	__u32 height;			/* height of picture in mm    在内存中图片的高度　*/
	__u32 width;			/* width of picture in mm    在内存中图片的宽度 */

	__u32 accel_flags;		/* (OBSOLETE) see fb_info.flags  已过时*/

	/* Timing: All values in pixclocks, except pixclock (of course) */
 	/* 除了pixclock本身外，其他的都已pixclock为单位*/
	__u32 pixclock;			/* pixel clock in ps (pico seconds) 像素时钟（皮秒）*/
	__u32 left_margin;		/* time from sync to picture	行切换：从绘图到同步之间的延迟　*/
	__u32 right_margin;		/* time from picture to sync	行切换：从绘图到同步之间的延迟　*/
	__u32 upper_margin;		/* time from sync to picture	帧切换：从同步到绘图之间的延迟　*/
	__u32 lower_margin;　　　　　//　帧切换，从绘图到同步之间的延迟　
	__u32 hsync_len;		/* length of horizontal sync	水平同步的长度　*/
	__u32 vsync_len;		/* length of vertical sync	垂直同步的长度　*/
	__u32 sync;			/* see FB_SYNC_*		查看FB_SYNC_*　*/
	__u32 vmode;			/* see FB_VMODE_*	查看	FB_VMODE_* */
	__u32 rotate;			/* angle we rotate counter clockwise 顺时针旋转的角度 */
	__u32 reserved[5];		/* Reserved for future compatibility  保留 */
};

/**
 * 用于描述设备无关的颜色映射信息
 */
struct fb_cmap {
	__u32 start;			/* First entry	第一个元素入口 */
	__u32 len;			/* Number of entries 元素的数量*/
	//R,G,B,透明度
	__u16 *red;			/* Red values	*/
	__u16 *green;
	__u16 *blue;
	__u16 *transp;			/* transparency, can be NULL 透明度，可以为空 */
};

struct fb_con2fbmap {
	__u32 console;
	__u32 framebuffer;
};

/* VESA Blanking Levels */
#define VESA_NO_BLANKING        0
#define VESA_VSYNC_SUSPEND      1
#define VESA_HSYNC_SUSPEND      2
#define VESA_POWERDOWN          3


enum {
	/* screen: unblanked, hsync: on,  vsync: on */
	FB_BLANK_UNBLANK       = VESA_NO_BLANKING,

	/* screen: blanked,   hsync: on,  vsync: on */
	FB_BLANK_NORMAL        = VESA_NO_BLANKING + 1,

	/* screen: blanked,   hsync: on,  vsync: off */
	FB_BLANK_VSYNC_SUSPEND = VESA_VSYNC_SUSPEND + 1,

	/* screen: blanked,   hsync: off, vsync: on */
	FB_BLANK_HSYNC_SUSPEND = VESA_HSYNC_SUSPEND + 1,

	/* screen: blanked,   hsync: off, vsync: off */
	FB_BLANK_POWERDOWN     = VESA_POWERDOWN + 1
};

#define FB_VBLANK_VBLANKING	0x001	/* currently in a vertical blank */
#define FB_VBLANK_HBLANKING	0x002	/* currently in a horizontal blank */
#define FB_VBLANK_HAVE_VBLANK	0x004	/* vertical blanks can be detected */
#define FB_VBLANK_HAVE_HBLANK	0x008	/* horizontal blanks can be detected */
#define FB_VBLANK_HAVE_COUNT	0x010	/* global retrace counter is available */
#define FB_VBLANK_HAVE_VCOUNT	0x020	/* the vcount field is valid */
#define FB_VBLANK_HAVE_HCOUNT	0x040	/* the hcount field is valid */
#define FB_VBLANK_VSYNCING	0x080	/* currently in a vsync */
#define FB_VBLANK_HAVE_VSYNC	0x100	/* verical syncs can be detected */

struct fb_vblank {
	__u32 flags;			/* FB_VBLANK flags FB_VBLANK标志 */
	__u32 count;			/* counter of retraces since boot 启动之后追溯的次数　*/
	__u32 vcount;			/* current scanline position 当前扫描行位置　*/
	__u32 hcount;			/* current scandot position 当前扫描点位置　*/
	__u32 reserved[4];		/* reserved for future compatibility 保留　*/
};

/* Internal HW accel 内部硬件加速　*/
#define ROP_COPY 0
#define ROP_XOR  1

//复制区域　
struct fb_copyarea {
	__u32 dx;
	__u32 dy;
	__u32 width;
	__u32 height;
	__u32 sx;
	__u32 sy;
};

//回执矩形
struct fb_fillrect {
	__u32 dx;	/* screen-relative  屏幕相关 */
	__u32 dy;
	__u32 width;
	__u32 height;
	__u32 color;
	__u32 rop;
};

struct fb_image {
	__u32 dx;		/* Where to place image 图像放在哪里　*/
	__u32 dy;
	__u32 width;		/* Size of image 图像的宽度和高度　*/
	__u32 height;
	__u32 fg_color;		/* Only used when a mono bitmap  仅仅是单色图像的时候使用　*/
	__u32 bg_color;
	__u8  depth;		/* Depth of the image 图像的深度　*/
	const char *data;	/* Pointer to image data 指向图像数据的指针　*/
	struct fb_cmap cmap;	/* color map info 颜色映射信息　*/
};

/*
 * hardware cursor control
 * 硬件光标控制　
 */

#define FB_CUR_SETIMAGE 0x01
#define FB_CUR_SETPOS   0x02
#define FB_CUR_SETHOT   0x04
#define FB_CUR_SETCMAP  0x08
#define FB_CUR_SETSHAPE 0x10
#define FB_CUR_SETSIZE	0x20
#define FB_CUR_SETALL   0xFF

//　光标位置　
struct fbcurpos {
	__u16 x, y;
};

struct fb_cursor {
	__u16 set;		/* what to set 设置成什么　*/
	__u16 enable;		/* cursor on/off 光标打开/关闭　*/
	__u16 rop;		/* bitop operation 位操作　*/
	const char *mask;	/* cursor mask bits 光标掩码位 */
	struct fbcurpos hot;	/* cursor hot spot 光标热点　*/
	struct fb_image	image;	/* Cursor image 光标图像　*/
};

#ifdef CONFIG_FB_BACKLIGHT
/* Settings for the generic backlight code */
#define FB_BACKLIGHT_LEVELS	128
#define FB_BACKLIGHT_MAX	0xFF
#endif

#ifdef __KERNEL__

#include <linux/fs.h>
#include <linux/init.h>
#include <linux/device.h>
#include <linux/workqueue.h>
#include <linux/notifier.h>
#include <linux/list.h>
#include <linux/backlight.h>
#include <asm/io.h>

struct vm_area_struct;
struct fb_info;
struct device;
struct file;

/* Definitions below are used in the parsed monitor specs */
#define FB_DPMS_ACTIVE_OFF	1
#define FB_DPMS_SUSPEND		2
#define FB_DPMS_STANDBY		4

#define FB_DISP_DDI		1
#define FB_DISP_ANA_700_300	2
#define FB_DISP_ANA_714_286	4
#define FB_DISP_ANA_1000_400	8
#define FB_DISP_ANA_700_000	16

#define FB_DISP_MONO		32
#define FB_DISP_RGB		64
#define FB_DISP_MULTI		128
#define FB_DISP_UNKNOWN		256

#define FB_SIGNAL_NONE		0
#define FB_SIGNAL_BLANK_BLANK	1
#define FB_SIGNAL_SEPARATE	2
#define FB_SIGNAL_COMPOSITE	4
#define FB_SIGNAL_SYNC_ON_GREEN	8
#define FB_SIGNAL_SERRATION_ON	16

#define FB_MISC_PRIM_COLOR	1
#define FB_MISC_1ST_DETAIL	2	/* First Detailed Timing is preferred 第一次详细的时间是首选　*/

struct fb_chroma {
	__u32 redx;	/* in fraction of 1024 1024的一小部分　*/
	__u32 greenx;
	__u32 bluex;
	__u32 whitex;
	__u32 redy;
	__u32 greeny;
	__u32 bluey;
	__u32 whitey;
};

struct fb_monspecs {
	struct fb_chroma chroma;
	struct fb_videomode *modedb;	/* mode database 模式数据库 */
	__u8  manufacturer[4];		/* Manufacturer 制造商　*/
	__u8  monitor[14];		/* Monitor String 监视字符串　*/
	__u8  serial_no[14];		/* Serial Number 序列号　*/
	__u8  ascii[14];		/* ? */
	__u32 modedb_len;		/* mode database length 模式数据库长度　*/
	__u32 model;			/* Monitor Model 监视模型　*/
	__u32 serial;			/* Serial Number - Integer 序列号－整数　*/
	__u32 year;			/* Year manufactured 制造年*/
	__u32 week;			/* Week Manufactured 制造周　*/
	__u32 hfmin;			/* hfreq lower limit (Hz) hfreq最低限制*/
	__u32 hfmax;			/* hfreq upper limit (Hz) hfreq最高限制*/
	__u32 dclkmin;			/* pixelclock lower limit (Hz) pixelclock最低限制*/
	__u32 dclkmax;			/* pixelclock upper limit (Hz) pixelclock最高限制*/
	__u16 input;			/* display type - see FB_DISP_* 显示类型　- 查看FB_DISP_*　*/
	__u16 dpms;			/* DPMS support - see FB_DPMS_   DPMS支持－查看FB_DPMS_ */
	__u16 signal;			/* Signal Type - see FB_SIGNAL_* 信号类型　－　查看FB_SIGNAL_*　*/
	__u16 vfmin;			/* vfreq lower limit (Hz) vfreq最低限制　*/
	__u16 vfmax;			/* vfreq upper limit (Hz) vfreq最高限制　*/
	__u16 gamma;			/* Gamma - in fractions of 100 100的分数　*/
	__u16 gtf	: 1;		/* supports GTF 支持 GTF */
	__u16 misc;			/* Misc flags - see FB_MISC_* Misc标识　－　查看FB_MISC_*　　*/
	__u8  version;			/* EDID version... EDID版本　*/
	__u8  revision;			/* ...and revision 修订版本　*/
	__u8  max_x;			/* Maximum horizontal size (cm) 最大水平大小　*/
	__u8  max_y;			/* Maximum vertical size (cm) 最大垂直大小　*/
};

struct fb_cmap_user {
	__u32 start;			/* First entry	第一元素入口　　*/
	__u32 len;			/* Number of entries 元素的数量　*/
	//R,G,B和透明度　
	__u16 __user *red;		/* Red values	*/
	__u16 __user *green;
	__u16 __user *blue;
	__u16 __user *transp;		/* transparency, can be NULL */
};

struct fb_image_user {
	__u32 dx;			/* Where to place image */
	__u32 dy;
	__u32 width;			/* Size of image */
	__u32 height;
	__u32 fg_color;			/* Only used when a mono bitmap */
	__u32 bg_color;
	__u8  depth;			/* Depth of the image */
	const char __user *data;	/* Pointer to image data */
	struct fb_cmap_user cmap;	/* color map info */
};

struct fb_cursor_user {
	__u16 set;			/* what to set */
	__u16 enable;			/* cursor on/off */
	__u16 rop;			/* bitop operation */
	const char __user *mask;	/* cursor mask bits */
	struct fbcurpos hot;		/* cursor hot spot */
	struct fb_image_user image;	/* Cursor image */
};

/*
 * Register/unregister for framebuffer events
　* framebuffer事件的注册/注销
 */

/*	The resolution of the passed in fb_info about to change */
//　在fb_info中通过的分辨率将要改变
#define FB_EVENT_MODE_CHANGE		0x01
/*	The display on this fb_info is beeing suspended, no access to the
 *	framebuffer is allowed any more after that call returns
 *  在这个fb_info的显示是被悬挂着的，在那个调用返回之后的对framebuffer
 *  的访问是不被允许的．
 */
#define FB_EVENT_SUSPEND		0x02
/*	The display on this fb_info was resumed, you can restore the display
 *	if you own it
　*  在这个fb_info中的显示恢复了，如果你拥有他，你可以恢复显示
 *
 */
#define FB_EVENT_RESUME			0x03
/*      An entry from the modelist was removed */
//　模式列表中的一个元素被移走了
#define FB_EVENT_MODE_DELETE            0x04
/*      A driver registered itself */
// 一个驱动注册了他自己
#define FB_EVENT_FB_REGISTERED          0x05
/*      A driver unregistered itself */
// 一个驱动注销了他自己　
#define FB_EVENT_FB_UNREGISTERED        0x06
/*      CONSOLE-SPECIFIC: get console to framebuffer mapping */
// 获取framebuffer映射的控制台
#define FB_EVENT_GET_CONSOLE_MAP        0x07
/*      CONSOLE-SPECIFIC: set console to framebuffer mapping */
//　设置framebuffer映射的控制台
#define FB_EVENT_SET_CONSOLE_MAP        0x08
/*      A hardware display blank change occured */
// 一个硬件显示空改变发生了
#define FB_EVENT_BLANK                  0x09
/*      Private modelist is to be replaced */
// 内部的模式列表将被替换
#define FB_EVENT_NEW_MODELIST           0x0A
/*	The resolution of the passed in fb_info about to change and
        all vc's should be changed         */
// 在fb_info中通过的分辨率将要改变，并且所有的vc应该被改变
#define FB_EVENT_MODE_CHANGE_ALL	0x0B
/*	A software display blank change occured */
// 一个软件显示空改变发生了
#define FB_EVENT_CONBLANK               0x0C
/*      Get drawing requirements        */
// 获取画图需求
#define FB_EVENT_GET_REQ                0x0D
/*      Unbind from the console if possible */
// 如果可能的话从控制台中接触绑定
#define FB_EVENT_FB_UNBIND              0x0E
/*      CONSOLE-SPECIFIC: remap all consoles to new fb - for vga switcheroo */
// 重新将所有的控制台映射到新的fb -- 对于vga switcheroo来说的
#define FB_EVENT_REMAP_ALL_CONSOLE      0x0F

struct fb_event {
	struct fb_info *info;
	void *data;
};

struct fb_blit_caps {
	u32 x;
	u32 y;
	u32 len;
	u32 flags;
};

extern int fb_register_client(struct notifier_block *nb);
extern int fb_unregister_client(struct notifier_block *nb);
extern int fb_notifier_call_chain(unsigned long val, void *v);
/*
 * Pixmap structure definition
 *　Pixmap 结构体定义　
 * The purpose of this structure is to translate data
 * from the hardware independent format of fbdev to what
 * format the hardware needs.
 * 该结构体的目的就是将数据从fbdev的硬件独立的格式转换成
 *　硬件需要的格式
 *
 */

#define FB_PIXMAP_DEFAULT 1     /* used internally by fbcon 被fvbcon内部使用*/
#define FB_PIXMAP_SYSTEM  2     /* memory is in system RAM  内存在系统RAM中*/
#define FB_PIXMAP_IO      4     /* memory is iomapped       内存被io映射了*/
#define FB_PIXMAP_SYNC    256   /* set if GPU can DMA       如果GPU能够使用DMA的话设置*/

struct fb_pixmap {
	u8  *addr;		/* pointer to memory	指向内存的指针		*/
	u32 size;		/* size of buffer in bytes	缓冲的字节数大小	*/
	u32 offset;		/* current offset to buffer	　当前到buffer的偏移量　　	*/
	u32 buf_align;		/* byte alignment of each bitmap　　每一个位图的字节对齐	*/
	u32 scan_align;		/* alignment per scanline	每一个扫描行的对齐	*/
	u32 access_align;	/* alignment per read/write (bits)　每一个读写位的对齐	*/
	u32 flags;		/* see FB_PIXMAP_*		查看FB_PIXMAP_*	*/
	u32 blit_x;             /* supported bit block dimensions (1-32) 支持位块尺寸(1-32) */
	u32 blit_y;             /* Format: blit_x = 1 << (width - 1)    */
	                        /*         blit_y = 1 << (height - 1)   */
	                        /* if 0, will be set to 0xffffffff (all)　如果是０，则被设置为0xffffffff  */
	/* access methods 访问方法　*/
	void (*writeio)(struct fb_info *info, void __iomem *dst, void *src, unsigned int size);
	void (*readio) (struct fb_info *info, void *dst, void __iomem *src, unsigned int size);
};

#ifdef CONFIG_FB_DEFERRED_IO
struct fb_deferred_io {
	/* delay between mkwrite and deferred handler 　在mkwrite和延期的处理程序的时间　*/
	unsigned long delay;
	struct mutex lock; /* mutex that protects the page list 保护页列表的互斥锁　*/
	struct list_head pagelist; /* list of touched pages 被创建的页的列表*/
	/* callback 回调函数*/
	void (*deferred_io)(struct fb_info *info, struct list_head *pagelist);
};
#endif

/*
 * Frame buffer operations
 *　Frame buffer 的操作
 * LOCKING NOTE: those functions must _ALL_ be called with the console
 * semaphore held, this is the only suitable locking mechanism we have
 * in 2.6. Some may be called at interrupt time at this point though.
　* 这些函数必须要使用semaphore锁．
 */

struct fb_ops {
	/* open/release and usage marking */
	//　打开/释放和使用标记
	struct module *owner;
	int (*fb_open)(struct fb_info *info, int user);
	int (*fb_release)(struct fb_info *info, int user);

	/* For framebuffers with strange non linear layouts or that do not
	 * work with normal memory mapped access
	 * 对于拥有陌生的非线性布局的framebuffer来说，不能使用普通的内存
	 *　映射访问来工作
	 */
	ssize_t (*fb_read)(struct fb_info *info, char __user *buf,
			   size_t count, loff_t *ppos);
	ssize_t (*fb_write)(struct fb_info *info, const char __user *buf,
			    size_t count, loff_t *ppos);

	/* checks var and eventually tweaks it to something supported,
	 * DO NOT MODIFY PAR */
	// 检查var并且事件性的调整到可支持状态．不要修改PAR
	int (*fb_check_var)(struct fb_var_screeninfo *var, struct fb_info *info);

	/* set the video mode according to info->var */
	// 通过info->var设置视频模式
	int (*fb_set_par)(struct fb_info *info);

	/* set color register */
	// 设置颜色寄存器
	int (*fb_setcolreg)(unsigned regno, unsigned red, unsigned green,
			    unsigned blue, unsigned transp, struct fb_info *info);

	/* set color registers in batch */
	// 批处理设置颜色寄存器
	int (*fb_setcmap)(struct fb_cmap *cmap, struct fb_info *info);

	/* blank display */
	// 空显示
	int (*fb_blank)(int blank, struct fb_info *info);

	/* pan display */
	// pan 显示
	int (*fb_pan_display)(struct fb_var_screeninfo *var, struct fb_info *info);

	/* Draws a rectangle */
	// 绘制一个矩形
	void (*fb_fillrect) (struct fb_info *info, const struct fb_fillrect *rect);
	/* Copy data from area to another */
	//　从一个区域复制数据到另外一个区域
	void (*fb_copyarea) (struct fb_info *info, const struct fb_copyarea *region);
	/* Draws a image to the display */
	// 在显示器上绘制一个图像
	void (*fb_imageblit) (struct fb_info *info, const struct fb_image *image);

	/* Draws cursor */
	// 绘制光标
	int (*fb_cursor) (struct fb_info *info, struct fb_cursor *cursor);

	/* Rotates the display */
	// 旋转显示
	void (*fb_rotate)(struct fb_info *info, int angle);

	/* wait for blit idle, optional */
	// 等待blit空闲，可选
	int (*fb_sync)(struct fb_info *info);

	/* perform fb specific ioctl (optional) */
	// 运行fb指定的ioctl(可选)
	int (*fb_ioctl)(struct fb_info *info, unsigned int cmd,
			unsigned long arg);

	/* Handle 32bit compat ioctl (optional) */
	//　处理３２位兼容的ioctl
	int (*fb_compat_ioctl)(struct fb_info *info, unsigned cmd,
			unsigned long arg);

	/* perform fb specific mmap */
	// 运行fb指定的mmap
	int (*fb_mmap)(struct fb_info *info, struct vm_area_struct *vma);

	/* get capability given var */
	// 获取给定的var的能力
	void (*fb_get_caps)(struct fb_info *info, struct fb_blit_caps *caps,
			    struct fb_var_screeninfo *var);

	/* teardown any resources to do with this framebuffer */
	// 卸载与该framebuffer相关的任何资源
	void (*fb_destroy)(struct fb_info *info);
};

#ifdef CONFIG_FB_TILEBLITTING
#define FB_TILE_CURSOR_NONE        0
#define FB_TILE_CURSOR_UNDERLINE   1
#define FB_TILE_CURSOR_LOWER_THIRD 2
#define FB_TILE_CURSOR_LOWER_HALF  3
#define FB_TILE_CURSOR_TWO_THIRDS  4
#define FB_TILE_CURSOR_BLOCK       5

struct fb_tilemap {
	__u32 width;                /* width of each tile in pixels　像素的宽度 */
	__u32 height;               /* height of each tile in scanlines 扫描行的高度　*/
	__u32 depth;                /* color depth of each tile 颜色深度　*/
	__u32 length;               /* number of tiles in the map 在映射中的数量　*/
	const __u8 *data;           /* actual tile map: a bitmap array, packed
				       to the nearest byte 实际映射：一个位图数组，被打包到最近的位　*/
};

struct fb_tilerect {
	__u32 sx;                   /* origin in the x-axis 在x轴中原点*/
	__u32 sy;                   /* origin in the y-axis 在y轴中的原点*/
	__u32 width;                /* number of tiles in the x-axis 在x-axis 中的数量　*/
	__u32 height;               /* number of tiles in the y-axis 在y-axis中的数量　*/
	__u32 index;                /* what tile to use: index to tile map 使用哪一个tile:到tile映射的索引　*/
	__u32 fg;                   /* foreground color 前景色 */
	__u32 bg;                   /* background color 后景色 */
	__u32 rop;                  /* raster operation  光栅操作　*/
};

struct fb_tilearea {
	__u32 sx;                   /* source origin in the x-axis 在X轴的源原点　*/
	__u32 sy;                   /* source origin in the y-axis 在y轴的源原点　*/
	__u32 dx;                   /* destination origin in the x-axis 在x轴的目的原点　*/
	__u32 dy;                   /* destination origin in the y-axis 在y轴的目的原点　*/
	__u32 width;                /* number of tiles in the x-axis 在x轴中的tiles的数量　*/
	__u32 height;               /* number of tiles in the y-axis 在y轴中的tiles的数量　*/
};

struct fb_tileblit {
	__u32 sx;                   /* origin in the x-axis　在x轴的原点 */
	__u32 sy;                   /* origin in the y-axis 在y轴的原点*/
	__u32 width;                /* number of tiles in the x-axis 在x轴上的tiles的数量 */
	__u32 height;               /* number of tiles in the y-axis 在y轴上的tiles的数量　*/
	__u32 fg;                   /* foreground color 前景色*/
	__u32 bg;                   /* background color 后景色*/
	__u32 length;               /* number of tiles to draw 要绘制的tiles的数量 */
	__u32 *indices;             /* array of indices to tile map 到tile映射的指数数组 */
};

struct fb_tilecursor {
	__u32 sx;                   /* cursor position in the x-axis 在x轴的光标位置*/
	__u32 sy;                   /* cursor position in the y-axis 在y轴的光标位置　*/
	__u32 mode;                 /* 0 = erase, 1 = draw 0 = 擦除，１＝绘制*/
	__u32 shape;                /* see FB_TILE_CURSOR_* 查看FB_TILE_CURSOR_*  */
	__u32 fg;                   /* foreground color 前景色*/
	__u32 bg;                   /* background color 后景色*/
};

struct fb_tile_ops {
	/* set tile characteristics 　设置tile的特征*/
	void (*fb_settile)(struct fb_info *info, struct fb_tilemap *map);

	/* all dimensions from hereon are in terms of tiles */
	//　从现在起，所有尺寸都在tiles方面
	/* move a rectangular region of tiles from one area to another*/
	// 移动一个矩形区域从一个地方到另外一个地方
	void (*fb_tilecopy)(struct fb_info *info, struct fb_tilearea *area);
	/* fill a rectangular region with a tile */
	// 使用一个tile填充一个矩形区域
	void (*fb_tilefill)(struct fb_info *info, struct fb_tilerect *rect);
	/* copy an array of tiles */	
	// 复制一个tile数组
	void (*fb_tileblit)(struct fb_info *info, struct fb_tileblit *blit);
	/* cursor */
	// 光标
	void (*fb_tilecursor)(struct fb_info *info,
			      struct fb_tilecursor *cursor);
	/* get maximum length of the tile map */
	// 获取tile映射的最大长度
	int (*fb_get_tilemax)(struct fb_info *info);
};
#endif /* CONFIG_FB_TILEBLITTING */

/* FBINFO_* = fb_info.flags bit flags FBINFO_*　＝　fb_info.flags　位标识　*/
#define FBINFO_MODULE		0x0001	/* Low-level driver is a module　底层驱动是一个模块 */
#define FBINFO_HWACCEL_DISABLED	0x0002
	/* When FBINFO_HWACCEL_DISABLED is set:
	 *  Hardware acceleration is turned off.  Software implementations
	 *  of required functions (copyarea(), fillrect(), and imageblit())
	 *  takes over; acceleration engine should be in a quiescent state */
	/* 当FBINFO_HWACCEL_DISABLED被设置的时候：
	 *	硬件加速被关掉．所需功能的软件实现(copyarea(),fillrect()和imageblit())
	 *	接管．加速引擎应该位域静态状态
	 *
/* hints 提示*/
#define FBINFO_VIRTFB		0x0004 /* FB is System RAM, not device. FB是系统RAM，不是设备*/
#define FBINFO_PARTIAL_PAN_OK	0x0040 /* otw use pan only for double-buffering otw使用pan仅仅用于双缓冲 */
#define FBINFO_READS_FAST	0x0080 /* soft-copy faster than rendering 软拷贝快于渲染 */

/* hardware supported ops */
/*  semantics: when a bit is set, it indicates that the operation is
 *   accelerated by hardware.
　* 支持的硬件操作
　* 语义：当一个位被设置，意味着操作被硬件加速了
 *
 *  required functions will still work even if the bit is not set.
　*  即使位没有被设置，所需的功能依旧工作．
 *  optional functions may not even exist if the flag bit is not set.
 *  如果标识位没有被设置，可选的功能可能甚至不存在
 */
#define FBINFO_HWACCEL_NONE		0x0000
#define FBINFO_HWACCEL_COPYAREA		0x0100 /* required 需要*/
#define FBINFO_HWACCEL_FILLRECT		0x0200 /* required 需要*/
#define FBINFO_HWACCEL_IMAGEBLIT	0x0400 /* required 需要*/
#define FBINFO_HWACCEL_ROTATE		0x0800 /* optional 可选*/
#define FBINFO_HWACCEL_XPAN		0x1000 /* optional 可选*/
#define FBINFO_HWACCEL_YPAN		0x2000 /* optional */
#define FBINFO_HWACCEL_YWRAP		0x4000 /* optional */

#define FBINFO_MISC_USEREVENT          0x10000 /* event request　
						  from userspace 从用户空间时间需要*/
#define FBINFO_MISC_TILEBLITTING       0x20000 /* use tile blitting 使用tile blitting*/
#define FBINFO_MISC_FIRMWARE           0x40000 /* a replaceable firmware
						  inited framebuffer 一个可替换的固件初始化的framebuffer*/

/* A driver may set this flag to indicate that it does want a set_par to be
 * called every time when fbcon_switch is executed. The advantage is that with
 * this flag set you can really be sure that set_par is always called before
 * any of the functions dependant on the correct hardware state or altering
 * that state, even if you are using some broken X releases. The disadvantage
 * is that it introduces unwanted delays to every console switch if set_par
 * is slow. It is a good idea to try this flag in the drivers initialization
 * code whenever there is a bug report related to switching between X and the
 * framebuffer console.
 * 一个驱动可能会设置这个标识来表明每次当fbcon_switch被执行的时候，他不想调用set_par()．
 *　他的优点就是伴随着这个标识的设置，你可以确定set_par在任何依赖于正确的硬件状态
 *　或者是改变那个状态之前被一直调用，即使你整在使用一些x发行版．他的缺点就是如果
 *　set_par太慢的话，在显示在每一个控制台的时候，会导致不希望的延迟．
 *
 *
 */
#define FBINFO_MISC_ALWAYS_SETPAR   0x40000

/*
 * Host and GPU endianness differ.
　* 主机和GPU端不同
 */
#define FBINFO_FOREIGN_ENDIAN	0x100000
/*
 * Big endian math. This is the same flags as above, but with different
 * meaning, it is set by the fb subsystem depending FOREIGN_ENDIAN flag
 * and host endianness. Drivers should not use this flag.
 * 大端数学．这个是和上面一样的标识，但是意义却是不一样的，他是被依赖于FOREIGN_ENDIAN端
 *　和主机端的fb子系统所设置的．驱动不应该使用这个标识
 *
 */
#define FBINFO_BE_MATH  0x100000

struct fb_info {
	int node;
	int flags;
	struct mutex lock;		/* Lock for open/release/ioctl funcs 用于open/release/ioctl函数的锁　*/
	struct mutex mm_lock;		/* Lock for fb_mmap and smem_* fields 用于fb_mmap和smem_* 域的锁　*/
	struct fb_var_screeninfo var;	/* Current var 可变参数*/
	struct fb_fix_screeninfo fix;	/* Current fix 固定参数　*/
	struct fb_monspecs monspecs;	/* Current Monitor specs 　显示器标准　*/
	struct work_struct queue;	/* Framebuffer event queue 帧缓冲事件队列　*/
	struct fb_pixmap pixmap;	/* Image hardware mapper 图像硬件mapper */
	struct fb_pixmap sprite;	/* Cursor hardware mapper 光标硬件mapper */
	struct fb_cmap cmap;		/* Current cmap 目前的颜色表　*/
	struct list_head modelist;      /* mode list 模式列表　*/
	struct fb_videomode *mode;	/* current mode 当前的video模式　*/

#ifdef CONFIG_FB_BACKLIGHT
	/* assigned backlight device 对应的背光设备*/
	/* set before framebuffer registration, 
	   remove after unregister 在framebuffer注册之前被设置，在注销之后移走　*/
	struct backlight_device *bl_dev;

	/* Backlight level curve 背光调整　*/
	struct mutex bl_curve_mutex;	
	u8 bl_curve[FB_BACKLIGHT_LEVELS];
#endif
#ifdef CONFIG_FB_DEFERRED_IO
	struct delayed_work deferred_work;
	struct fb_deferred_io *fbdefio;
#endif

	struct fb_ops *fbops;  //　帧缓冲操作
	struct device *device;		/* This is the parent 辐射被*/
	struct device *dev;		/* This is this fb device fb设备　*/
	int class_flag;                    /* private sysfs flags 私有sysfs标识 */
#ifdef CONFIG_FB_TILEBLITTING
	struct fb_tile_ops *tileops;    /* Tile Blitting 图块blitting */
#endif
	char __iomem *screen_base;	/* Virtual address 虚拟基地址　*/
	unsigned long screen_size;	/* Amount of ioremapped VRAM or 0 ioremapped的虚拟内存大小　或者是　０*/ 
	void *pseudo_palette;		/* Fake palette of 16 colors 伪１６色颜色表　　*/ 
#define FBINFO_STATE_RUNNING	0
#define FBINFO_STATE_SUSPENDED	1
	u32 state;			/* Hardware state i.e suspend 硬件状态，如挂起　*/
	void *fbcon_par;                /* fbcon use-only private area fbcon仅仅用于私有区域*/
	/* From here on everything is device dependent 从这里开始所有的事物都是设备依赖的　*/
	void *par;
	/* we need the PCI or similiar aperture base/size not
	   smem_start/size as smem_start may just be an object
	   allocated inside the aperture so may not actually overlap */
	resource_size_t aperture_base;
	resource_size_t aperture_size;
};

#ifdef MODULE
#define FBINFO_DEFAULT	FBINFO_MODULE
#else
#define FBINFO_DEFAULT	0
#endif

// This will go away　这将会走开
#define FBINFO_FLAG_MODULE	FBINFO_MODULE
#define FBINFO_FLAG_DEFAULT	FBINFO_DEFAULT

/* This will go away
 * fbset currently hacks in FB_ACCELF_TEXT into var.accel_flags
 * when it wants to turn the acceleration engine on.  This is
 * really a separate operation, and should be modified via sysfs.
 *  But for now, we leave it broken with the following define
 * 这将会走开．当他想要打开加速引擎的时候，fbset会到var.accel_falgs.
 *　这个事实上是一个分离的操作，并且应该有sysfs修改．但是，对于现在来说，
 *　　我们把他打破与下面的定义．
 */
#define STUPID_ACCELF_TEXT_SHIT

// This will go away
//  这个将走开
#if defined(__sparc__)

/* We map all of our framebuffers such that big-endian accesses
 * are what we want, so the following is sufficient.
　* 
 * 我们映射所有的framebuffers，例如大端访问是我们需要的，所以下面的就足够了
 */

// This will go away
#define fb_readb sbus_readb
#define fb_readw sbus_readw
#define fb_readl sbus_readl
#define fb_readq sbus_readq
#define fb_writeb sbus_writeb
#define fb_writew sbus_writew
#define fb_writel sbus_writel
#define fb_writeq sbus_writeq
#define fb_memset sbus_memset_io

#elif defined(__i386__) || defined(__alpha__) || defined(__x86_64__) || defined(__hppa__) || defined(__sh__) || defined(__powerpc__) || defined(__avr32__) || defined(__bfin__)

#define fb_readb __raw_readb
#define fb_readw __raw_readw
#define fb_readl __raw_readl
#define fb_readq __raw_readq
#define fb_writeb __raw_writeb
#define fb_writew __raw_writew
#define fb_writel __raw_writel
#define fb_writeq __raw_writeq
#define fb_memset memset_io

#else

#define fb_readb(addr) (*(volatile u8 *) (addr))
#define fb_readw(addr) (*(volatile u16 *) (addr))
#define fb_readl(addr) (*(volatile u32 *) (addr))
#define fb_readq(addr) (*(volatile u64 *) (addr))
#define fb_writeb(b,addr) (*(volatile u8 *) (addr) = (b))
#define fb_writew(b,addr) (*(volatile u16 *) (addr) = (b))
#define fb_writel(b,addr) (*(volatile u32 *) (addr) = (b))
#define fb_writeq(b,addr) (*(volatile u64 *) (addr) = (b))
#define fb_memset memset

#endif

#define FB_LEFT_POS(p, bpp)          (fb_be_math(p) ? (32 - (bpp)) : 0)
#define FB_SHIFT_HIGH(p, val, bits)  (fb_be_math(p) ? (val) >> (bits) : \
						      (val) << (bits))
#define FB_SHIFT_LOW(p, val, bits)   (fb_be_math(p) ? (val) << (bits) : \
						      (val) >> (bits))

    /*
     *  `Generic' versions of the frame buffer device operations
  	 *  framebuffer的'Generis'版本的设备操作
	 *
     */

extern int fb_set_var(struct fb_info *info, struct fb_var_screeninfo *var); 
extern int fb_pan_display(struct fb_info *info, struct fb_var_screeninfo *var); 
extern int fb_blank(struct fb_info *info, int blank);
extern void cfb_fillrect(struct fb_info *info, const struct fb_fillrect *rect); 
extern void cfb_copyarea(struct fb_info *info, const struct fb_copyarea *area); 
extern void cfb_imageblit(struct fb_info *info, const struct fb_image *image);
/*
 * Drawing operations where framebuffer is in system RAM
 * 在framebuffer所在的系统RAM绘制操作
 *
 */
extern void sys_fillrect(struct fb_info *info, const struct fb_fillrect *rect);
extern void sys_copyarea(struct fb_info *info, const struct fb_copyarea *area);
extern void sys_imageblit(struct fb_info *info, const struct fb_image *image);
extern ssize_t fb_sys_read(struct fb_info *info, char __user *buf,
			   size_t count, loff_t *ppos);
extern ssize_t fb_sys_write(struct fb_info *info, const char __user *buf,
			    size_t count, loff_t *ppos);

/* drivers/video/fbmem.c */
extern int register_framebuffer(struct fb_info *fb_info);
extern int unregister_framebuffer(struct fb_info *fb_info);
extern int fb_prepare_logo(struct fb_info *fb_info, int rotate);
extern int fb_show_logo(struct fb_info *fb_info, int rotate);
extern char* fb_get_buffer_offset(struct fb_info *info, struct fb_pixmap *buf, u32 size);
extern void fb_pad_unaligned_buffer(u8 *dst, u32 d_pitch, u8 *src, u32 idx,
				u32 height, u32 shift_high, u32 shift_low, u32 mod);
extern void fb_pad_aligned_buffer(u8 *dst, u32 d_pitch, u8 *src, u32 s_pitch, u32 height);
extern void fb_set_suspend(struct fb_info *info, int state);
extern int fb_get_color_depth(struct fb_var_screeninfo *var,
			      struct fb_fix_screeninfo *fix);
extern int fb_get_options(char *name, char **option);
extern int fb_new_modelist(struct fb_info *info);

extern struct fb_info *registered_fb[FB_MAX];
extern int num_registered_fb;
extern struct class *fb_class;

extern int lock_fb_info(struct fb_info *info);

static inline void unlock_fb_info(struct fb_info *info)
{
	mutex_unlock(&info->lock);
}

static inline void __fb_pad_aligned_buffer(u8 *dst, u32 d_pitch,
					   u8 *src, u32 s_pitch, u32 height)
{
	int i, j;

	d_pitch -= s_pitch;

	for (i = height; i--; ) {
		/* s_pitch is a few bytes at the most, memcpy is suboptimal */
		for (j = 0; j < s_pitch; j++)
			*dst++ = *src++;
		dst += d_pitch;
	}
}

/* drivers/video/fb_defio.c */
extern void fb_deferred_io_init(struct fb_info *info);
extern void fb_deferred_io_open(struct fb_info *info,
				struct inode *inode,
				struct file *file);
extern void fb_deferred_io_cleanup(struct fb_info *info);
extern int fb_deferred_io_fsync(struct file *file, struct dentry *dentry,
				int datasync);

static inline bool fb_be_math(struct fb_info *info)
{
#ifdef CONFIG_FB_FOREIGN_ENDIAN
#if defined(CONFIG_FB_BOTH_ENDIAN)
	return info->flags & FBINFO_BE_MATH;
#elif defined(CONFIG_FB_BIG_ENDIAN)
	return true;
#elif defined(CONFIG_FB_LITTLE_ENDIAN)
	return false;
#endif /* CONFIG_FB_BOTH_ENDIAN */
#else
#ifdef __BIG_ENDIAN
	return true;
#else
	return false;
#endif /* __BIG_ENDIAN */
#endif /* CONFIG_FB_FOREIGN_ENDIAN */
}

/* drivers/video/fbsysfs.c */
extern struct fb_info *framebuffer_alloc(size_t size, struct device *dev);
extern void framebuffer_release(struct fb_info *info);
extern int fb_init_device(struct fb_info *fb_info);
extern void fb_cleanup_device(struct fb_info *head);
extern void fb_bl_default_curve(struct fb_info *fb_info, u8 off, u8 min, u8 max);

/* drivers/video/fbmon.c */
#define FB_MAXTIMINGS		0
#define FB_VSYNCTIMINGS		1
#define FB_HSYNCTIMINGS		2
#define FB_DCLKTIMINGS		3
#define FB_IGNOREMON		0x100

#define FB_MODE_IS_UNKNOWN	0
#define FB_MODE_IS_DETAILED	1
#define FB_MODE_IS_STANDARD	2
#define FB_MODE_IS_VESA		4
#define FB_MODE_IS_CALCULATED	8
#define FB_MODE_IS_FIRST	16
#define FB_MODE_IS_FROM_VAR     32

extern int fbmon_dpms(const struct fb_info *fb_info);
extern int fb_get_mode(int flags, u32 val, struct fb_var_screeninfo *var,
		       struct fb_info *info);
extern int fb_validate_mode(const struct fb_var_screeninfo *var,
			    struct fb_info *info);
extern int fb_parse_edid(unsigned char *edid, struct fb_var_screeninfo *var);
extern const unsigned char *fb_firmware_edid(struct device *device);
extern void fb_edid_to_monspecs(unsigned char *edid,
				struct fb_monspecs *specs);
extern void fb_destroy_modedb(struct fb_videomode *modedb);
extern int fb_find_mode_cvt(struct fb_videomode *mode, int margins, int rb);
extern unsigned char *fb_ddc_read(struct i2c_adapter *adapter);

/* drivers/video/modedb.c */
#define VESA_MODEDB_SIZE 34
extern void fb_var_to_videomode(struct fb_videomode *mode,
				const struct fb_var_screeninfo *var);
extern void fb_videomode_to_var(struct fb_var_screeninfo *var,
				const struct fb_videomode *mode);
extern int fb_mode_is_equal(const struct fb_videomode *mode1,
			    const struct fb_videomode *mode2);
extern int fb_add_videomode(const struct fb_videomode *mode,
			    struct list_head *head);
extern void fb_delete_videomode(const struct fb_videomode *mode,
				struct list_head *head);
extern const struct fb_videomode *fb_match_mode(const struct fb_var_screeninfo *var,
						struct list_head *head);
extern const struct fb_videomode *fb_find_best_mode(const struct fb_var_screeninfo *var,
						    struct list_head *head);
extern const struct fb_videomode *fb_find_nearest_mode(const struct fb_videomode *mode,
						       struct list_head *head);
extern void fb_destroy_modelist(struct list_head *head);
extern void fb_videomode_to_modelist(const struct fb_videomode *modedb, int num,
				     struct list_head *head);
extern const struct fb_videomode *fb_find_best_display(const struct fb_monspecs *specs,
						       struct list_head *head);

/* drivers/video/fbcmap.c */
extern int fb_alloc_cmap(struct fb_cmap *cmap, int len, int transp);
extern void fb_dealloc_cmap(struct fb_cmap *cmap);
extern int fb_copy_cmap(const struct fb_cmap *from, struct fb_cmap *to);
extern int fb_cmap_to_user(const struct fb_cmap *from, struct fb_cmap_user *to);
extern int fb_set_cmap(struct fb_cmap *cmap, struct fb_info *fb_info);
extern int fb_set_user_cmap(struct fb_cmap_user *cmap, struct fb_info *fb_info);
extern const struct fb_cmap *fb_default_cmap(int len);
extern void fb_invert_cmaps(void);

struct fb_videomode {
	const char *name;	/* optional */
	u32 refresh;		/* optional */
	u32 xres;
	u32 yres;
	u32 pixclock;
	u32 left_margin;
	u32 right_margin;
	u32 upper_margin;
	u32 lower_margin;
	u32 hsync_len;
	u32 vsync_len;
	u32 sync;
	u32 vmode;
	u32 flag;
};

extern const char *fb_mode_option;
extern const struct fb_videomode vesa_modes[];

struct fb_modelist {
	struct list_head list;
	struct fb_videomode mode;
};

extern int fb_find_mode(struct fb_var_screeninfo *var,
			struct fb_info *info, const char *mode_option,
			const struct fb_videomode *db,
			unsigned int dbsize,
			const struct fb_videomode *default_mode,
			unsigned int default_bpp);

#endif /* __KERNEL__ */

#endif /* _LINUX_FB_H */
