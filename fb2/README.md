**（一）：写在前面**

在这里我们主要实现了打印frame buffer的一些信息，其中包括分辨率，所占内存地址的开始地址，偏移量，BPP以及所占内存的宽度和高度等信息．主要是通过对这些参数的打印操作来实现对frame buffer的进一步深入的了解．

**（二）：如何编译以及运行**

首先，我们看到，在我们的目录中有三个文件，fbtool.h,fbtool.c以及test.c，其中main函数位于test.c文件中．下面是我们的编译命令．

```
gcc fbtool.h fbtool.c test.c -o test
```

编译完成之后，就会生成test的可执行文件．

一般情况下，我们只要使用
```
./test
```
便能够运行该程序文件，但是由于在运行过程中，需要打开/dev/fb0文件，所以需要使用特权用户运行该程序，我们使用下面的命令来运行我们的程序文件．

```
sudo ./test
```
这样程序就能够顺利执行了．

**（三）：执行结果展示**

下面我们来看一下我们的执行结果：

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
这个后面再说!!
frame buffer在内存中所占的高度和宽度分别是:
	宽度 = -1
	高度 = -1
```

这样就能明显的看出frame buffer的一些属性了．

**（四）：该程序的构成**

在这里我们说一下我们如果构建的该程序．

１：首先我们需要定义一个结构体，该结构体包括四个变量：
```
	int fb;   //framebuffer打开后的唯一标识符
	struct fb_fix_screeninfo fb_fix;  
	struct fb_var_screeninfo fb_var;
	char dev[20];  //设备名称
```

２：定义完成结构体之后，我们就需要定义操作frame buffer的各个方法，包括打开，关闭fb0设备，打印相关信息的函数等
```
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
```

３：接着就是这些函数的实现

这些函数的实现都是比较简单的，基本上是打印结构体中的一些信息．

４：编写测试程序，运行测试

最后就是编写我们的main函数，进行编译测试．

**（五）：后期展望**

在后面一个测试中，着重讲解fb_var里面的R,G,B和透明度的值．

**（六）：写在后面**

宝剑锋从磨砺出，梅花香自苦寒来．


