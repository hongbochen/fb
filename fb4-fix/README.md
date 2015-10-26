**（一）：写在前面**

在这里需要修正一下我犯得一个错误，就是在结构体fb_fix_screeninfo中的smem_start的类型是unsigned long.而我在输出的时候使用的参数是"%d",是我的疏忽造成了如此大的错误．在这里我纠正一下，输出的时候应该为"%lu".还有一个地方就是在打印frame buffer在内存中的高度和宽度的时候，应该使用"%u".

**（二）：修改的位置**

1:该错误修改的位置在fbtool.c的41行：

```

//打印frame buffer 所占内存的开始地址　
void pmem_start(PFBDEV pFbdev)
{
	printf("frame buffer所占内存的开始地址为:%lu\n",pFbdev->fb_fix.smem_start);
}

```

2：该错误在fbtool.c的82行：

```
//打印在内存中的高度和宽度
void p_hw(PFBDEV pFbdev)
{
	printf("frame buffer在内存中所占的高度和宽度分别是:\n\t宽度 = %u\n\t高度 = %u\n",pFbdev->fb_var.height,pFbdev->fb_var.width);
}
```

3：还有其他的输出的参数都是有点问题的．改动在代码中，如果还有问题的话，希望大家能够指正．

**（三）：执行结果展示**

下面我们来看一下我们的执行结果：

```
frame buffer所占内存的开始地址为:2953256960
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
	宽度 = 4294967295
	高度 = 4294967295
    
```

**（五）：特别感谢**

在这里我要特别感谢我的校友：WANG-lp 
他的github地址为：

[WANG-lp](https://github.com/WANG-lp)

**（六）：写在后面**

过而能改，善莫大焉．

在这里给大家道个歉：

![sorry](http://face.zhaoxi.org/upload/201359/20070110120842.gif)


