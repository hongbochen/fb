**（一）：写在前面**

在这个小节中，主要介绍了frame buffer中的R,G,B以及透明度的位域属性．由于在上一个小节当中，我自私的以为这几个位域能够获得相应的R,G,B以及透明度的数值，然后再将其转化为图像，但是，经过我后来的学习，发现我错了．正确的将frame buffer读取并转换为图像的方法是首先读取(read)frame buffer，然后，再将读取的char数组转换为相应的图片．所以，后面，着重学习如何读取frame buffer，以及如何将其转化为图片．

**（二）：R,G,B以及透明度位域**

在fb.h头文件中的结构 fb_var_screeninfo中定义了R,G,B以及透明度的位域，他们都是一个结构体fb_bitfield的一个实例．下面我们来看一下bitfield的定义：

```
struct fb_bitfield {
	__u32 offset;			/* 位域的开始	*/
	__u32 length;			/* length of bitfield　位域的长度　*/
	__u32 msb_right;		/* != 0 : Most significant bit is　right 不等于０，大多数重要的位是右边的 */ 
};
```

那么如果要打印该值的话，我们就需要使用该结构体．

**（三）：完善上一节中的p_rgbt(PFBDEV pFbdev)函数**

在我们的上一节中，我们留下了这个函数而没有去实现，这个来源于我的无知．所以，现在我们来完善一下这个函数．在上面我们知道这个关系之后，这个函数的实现就显得相对简单了．

```
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
```

**（四）：编译运行方法**

编译和运行方法和上一节的编译运行方法是一样的．

**（五）：运行结果展示**

下面我们来看一下我们的运行结果：

```
frame buffer所占内存的开始地址为:-1341710336
frame buffer 的类型为:0
frame buffer的可见清晰度为：
	x = 1366
	y = 768
frame buffer的虚拟清晰度为：
	x = 1366
	y = 768
frame buffer的虚拟分辨率到可见分辨率的偏移量为:
	x = 0
	y = 0
frame buffer的BPP为：32
R位域:
	开始:16
	长度:8
	MSB:0
G位域:
	开始:8
	长度:8
	MSB:0
B位域:
	开始:0
	长度:8
	MSB:0
透明度位域:
	开始:0
	长度:0
	MSB:0
frame buffer在内存中所占的高度和宽度分别是:
	宽度 = -1
	高度 = -1
R位域:
	开始:16
	长度:8
	MSB:0
G位域:
	开始:8
	长度:8
	MSB:0
B位域:
	开始:0
	长度:8
	MSB:0
透明度位域:
	开始:0
	长度:0
	MSB:0

```

**（六）：写在后面**

今天很残酷，明天很残酷，后天很没有，但是绝大多数人死在了明天晚上．－－－－马云