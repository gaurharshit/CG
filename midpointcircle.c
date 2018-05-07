#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>

void circlepoints(int x, int y, int xc, int yc)
{
	putpixel(x+xc, y+yc, WHITE);
	putpixel(y+xc, x+yc, WHITE);
	putpixel(-x+xc, y+yc, WHITE);
	putpixel(-y+xc, x+yc, WHITE);
	putpixel(x+xc, -y+yc, WHITE);
	putpixel(y+xc, -x+yc, WHITE);
	putpixel(-x+xc, -y+yc, WHITE);
	putpixel(-y+xc, -x+yc, WHITE);	
}

void midpointcircle(int x_center, int y_center, int radius)
{
	int x = 0, y=radius;
	circlepoints(x,y,x_center,y_center);
	float p = 1.25-radius;
	while(x<y)
	{
		if(p <= 0.0)
		{
			p = p+2*x+3;	
		}
		else
		{
			p = p+2*x-2*y+5;
			y--;	
		}
		x+=1;	
		circlepoints(x,y,x_center,y_center);	
	}
	getch();	
}

void main()
{
	int gd = DETECT,gmode;
	initgraph(&gd,&gmode,NULL);
	midpointcircle(50,50,20);
	getch();
	closegraph();
}
