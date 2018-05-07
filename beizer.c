#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
float power(float a,float b)
{
	int i;
	float res=1;
 	for(i=1;i<=b;i++)
	{
		res*=a;
	}
	return res;
}


void beizer(int x[4], int y[4])
{
	int gd = DETECT,gmode; 
	initgraph (&gd,&gmode,NULL);

	int i;
	double u;
	for(u=0.0; u<1.0;u+=0.001)
	{
		double x_u = power(1-u,3)*x[0] + 3*u*power(1-u,2)*x[1] + 3*power(u,2)*(1-u)*x[2] + power(u,3)*x[3];
		double y_u = power(1-u,3)*y[0] + 3*u*power(1-u,2)*y[1] + 3*power(u,2)*(1-u)*y[2] + power(u,3)*y[3];
		putpixel(x_u,y_u,YELLOW);	
	}
	
	for(i=0;i<4;i++)
	{
		putpixel(x[i],y[i],WHITE);
	}
}

void main()
{
	int i;
	int x[4], y[4];
	printf("%d",pow(4,4));	
	printf("Enter the 4 control points\n");
	for(i=0;i<4;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
	}
	beizer(x,y);
	getch();
}
