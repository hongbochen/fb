**（一）：写在前面**

这是我学习framebuffer的第一篇笔记，我个人认为，要学习一个知识，就要从他的根本上学起．就像我现在刚刚接触的framebuffer，如果我想要进行framebuffer编程，就要了解framebuffer如何被定义的，以及内核中都是定义了哪些对framebuffer的ioctl的操作．所以，我首先做的就是对linux内核源码根目录/include/linux/fb.h中的有关与framebuffer的内容进行了大略的学习，将其中的关键部分进行了较为详细的注释．

**（二）：重点内容介绍**

在整个内核fb.h代码的阅读期间，我感觉理解framebuffer比较重要的几个结构体和函数：

*1:struct fb_fix_screeninfo*

该结构体用于描述显卡自身的属性包括识别符，缓存地址，显卡类型等

*2:struct fb_var_screeninfo*

用于描述显卡的一般特性，比如实际分辨率，虚拟分辨率，实际分辨率和虚拟分辨率之间的位移等

*3:struct fb_ops*

该结构体主要定义了对framebuffer的一些操作

*4:struct fb_info*

该结构体主要定义了一些关于framebuffer的一些信息以及其相关的操作

**（三）：后面内容介绍**

在后面的内容中，首先进行framebuffer编程的实验操作，打开framebuffer，打印相关属性等的操作．后铺面再进行更加深入的学习．

**（四）：写在后面**

冰冻三尺，非一日之寒．每天进步一点点，加油．