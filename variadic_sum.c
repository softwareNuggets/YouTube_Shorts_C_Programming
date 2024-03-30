#include <stdio.h>
#include <stdarg.h>
/*
https://github.com/softwareNuggets
        /YouTube_Shorts_C_Programming
        /variadic_sum.c
*/      

int sum(int count, ...) {

    va_list args;
    int total = 0;

    va_start(args, count);

    for(int i=0;i<count;i++)
    {
        int num = va_arg(args, int);  
        total +=  num;   
    }

    va_end(args);

    return(total);
}


int main() {
    int sum_of_values = sum(5,1,2,3,4,5);
    printf("sum = %d\n",sum_of_values);
}