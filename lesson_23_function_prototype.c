#include <stdio.h>
#include <stdlib.h>

// function prototypes
void loadArray(int *, int, int);
void showArray(int *, int);

int main() {
	int *ptr;
	int size=10;
	ptr = malloc(size * sizeof(int));
	loadArray(ptr, 0,9);
 
	ptr = realloc(ptr, 
            (size*2) * sizeof(int));
            
	loadArray(ptr, 10, 19);
	showArray(ptr, size*2);
}

void loadArray( int *p, int start, int last)
{
	printf("START:=%04d LAST:=%04d\n\n",
		start, last);
        
	for (int i = start; i <= last; i++) 
	{
		*(p+i)=i*last;
	}
}

void showArray(int *p, int size)
{
	printf("showArray := %04d\n\n",
				size);
        
	for (int i = 0; i < size; i++) 
	{
		printf("i=%d value=%d address=%p\n",
              i, *(p+i), (p+i));
	}
}
