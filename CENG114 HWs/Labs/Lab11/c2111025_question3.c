#include <stdio.h>

struct POINT{
	int x, y;
};

struct COORDSYS{
	int topright, topleft, bottomleft, bottomright, axes;
};

void quadrants(struct POINT a[], struct COORDSYS *p)
{
	int i;
	
	for(i=0; i<10; i++)
	{
		if(a[i].x>0 && a[i].y>0)
			p->topright++;
		else if(a[i].x>0 && a[i].y<0)
			p->bottomright++;
		else if(a[i].x<0 && a[i].y>0)
			p->topleft++;
		else if(a[i].x<0 && a[i].y<0)
			p->bottomleft++;
		else
			p->axes++;
	}
}

int main(void)
{
	int i;
	struct POINT arr[10];
	struct COORDSYS coor;
	
	coor.axes = 0;
	coor.bottomleft = 0;
	coor.bottomright = 0;
	coor.topleft = 0;
	coor.topright = 0;
	
	for(i=0; i<10; i++)
	{
		printf("Enter coordinates for %d. point: ", i+1);
		scanf(" %d %d", &arr[i].x, &arr[i].y);
	}
	
	quadrants(arr, &coor);
	printf("\nOn x or y axes: %d", coor.axes);
	printf("\nTop right: %d", coor.topright);
	printf("\nTop left: %d", coor.topleft);
	printf("\nBottom left: %d", coor.bottomleft);
	printf("\nBottom right: %d", coor.bottomright);
	
	return 0;
}
