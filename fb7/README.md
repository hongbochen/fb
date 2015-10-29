**（一）：写在前面**

这一次没有进行功能上的改进，主要是为了后来修改方便，而将画点，画线，画长方形，画圆等的提取出来，对Makefile进行了修改，方便于后期的维护．同时，为了后面实现我的思路，我进行了一个测试，就是实现一个运动的圆的效果．圆是可以运动了，但是效果不是特别好．后面再了解一下图形化界面是怎么实现的．我再试一下别的思路．


**（二）：功能介绍**

*１：Makefile文件的修改*

```
objects = fbtool.o point.o line.o rectangle.o circle.o 
test : test.c $(objects)
	gcc test.c $(objects) -o test -lm
fbtool.o : page.h color.h fbtool.h fbtool.c
	gcc -c page.h color.h fbtool.h fbtool.c
point.o : fbtool.h point.h point.c
	gcc -c fbtool.h point.h point.c
line.o : fbtool.h point.h line.h line.c
	gcc -c fbtool.h point.h line.h line.c
rectangle.o : fbtool.h point.h line.h rectangle.h rectangle.c
	gcc -c fbtool.h point.h line.h rectangle.h rectangle.c
circle.o : fbtool.h point.h circle.h circle.c
	gcc -c fbtool.h point.h circle.h circle.c -lm
clean:
	rm *.o *.gch test
```

*2:测试实现圆的运动*

```
int x = 500;
while(1){
    draw_circle(&fbdev,x,400,100,RED);
    usleep(100);

    x++;

    if(x == 1200)
        break;

    clear_con(fbdev.fb_mem + fbdev.fb_mem_offset,1,fbdev.fb_fix.smem_len);

}
```

这次测试暂时是这样实现的，不过界面的刷新和图形的运动是在同时发生的，也就是说是同一个频率的．这样是不行的．就会出现闪频的问题．后面我将修改这个，初步思路是将界面刷新放到一个单独的线程当中，或者是根据时钟来刷新，这个后面再说吧．

**（三）：后期规划**

后面的话主要的想法就是先实现图形的刷新，让图形能够移动或者是使图形能够一直存在．完成这个之后，就是纯图形库的编写工作了．


**（四）：写在后面**

众里寻他千百度，蓦然回首，那人却在灯火阑珊处．

<video id="video" controls="" preload="none" poster="http://media.w3.org/2010/05/sintel/poster.png">
      <source id="mp4" src="./video.mp4" type="video/mp4">
    </video>

























