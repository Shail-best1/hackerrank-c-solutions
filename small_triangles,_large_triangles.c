#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void sort_by_area(triangle* tr, int n) {
	/**
	* Sort an array a of the length n
	*/
    triangle *temp=tr;
    int a[n];
    
    for (int i=0;i<n;i++)
    {
        int s=tr[i].a+tr[i].b+tr[i].c;
        a[i]=sqrt(s*(s-tr[i].a)*(s-tr[i].b)*(s-tr[i].c));
    }
   
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if (a[j]>a[j+1])
            {
                 swap(&tr[j].a, &tr[j + 1].a);
                 swap(&tr[j].b, &tr[j + 1].b);
                 swap(&tr[j].c, &tr[j + 1].c);
               
            }
        }
    }
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}