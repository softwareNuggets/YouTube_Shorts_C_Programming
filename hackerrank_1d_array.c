//1D Dynamic Arrays in C
#include <stdio.h>
#include <stdlib.h>

//youtube video : https://youtube.com/shorts/G-sl6wjbQr8

typedef int* IntPtr;

int main() {
    int n=0;
    int sum = 0;
    
    scanf("%d", &n);
    
    IntPtr arr = (IntPtr)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    
    printf("%d\n", sum);
    free(arr);
    return 0;
}