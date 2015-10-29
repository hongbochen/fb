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
