#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>

void midpoint(int x1,int y1, int x2, int y2)
{
	int dy = (y2-y1);
	int dx = (x2-x1);
	int x=x1, y=y1;
	float d = dy-(dx/2);
	putpixel(x,y,WHITE);
	while(x<x2)
	{
		if(d<=0)
		{
			d = d + dy;
		}
		else
		{
			y = y+1;
			d = d + dy -dx;
		}
		x+=1;
		putpixel(x,y,WHITE);
	}
}

void main()
{
	int gd = DETECT,gmode;
	initgraph(&gd,&gmode,NULL);
	int x1=10,y1=20,x2=100,y2=150;
	midpoint(x1,y1,x2,y2);
	getch();
	closegraph();
}
