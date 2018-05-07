#include<stdlib.h>
#include<graphics.h>
#include<stdio.h>

void hermite(int x1, int y1, int x4, int y4, double r1,double r4)
{
	float x,y,t;
	for(t=0.0;t<=1.0;t+=.001)
	{
		x=(2*t*t*t-3*t*t+1)*x1+(-2*t*t*t+3*t*t)*x4+(t*t*t-2*t*t+t)*r1+(t*t*t-t*t)*r4;
		y=(2*t*t*t-3*t*t+1)*y1+(-2*t*t*t+3*t*t)*y4+(t*t*t-2*t*t+1)*r1+(t*t*t-t*t)*r4;
		putpixel(x,y,YELLOW);
	 }
}
 
void main()
{
	int gd=DETECT,gm;
	float r1,r4;
	initgraph(&gd,&gm,NULL);
	int x1, y1, x2, y2;
	printf("Enter 2 hermite points:\n");
	scanf("%d%d",x1,y1);
	scanf("%d%d",x2,y2);
	printf("Enter the tangents at p1,p4");
	scanf("%f%f",r1,r4);
	hermite(x1,y1,x2,y2,r1,r4);
	putpixel(x1,y1,WHITE);
	putpixel(x2,y2,WHITE);
	getch();
	closegraph();
}
