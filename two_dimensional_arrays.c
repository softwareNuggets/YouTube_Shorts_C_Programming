#include <stdio.h>

int main() {

//        row, column
    int matrix[3][4] = {
            {10,	20,	30,	40}, 
            {110,	120,	130,	140}, 
            {1110, 	1120,	1130,	1140}
        } ;


/*
    matrix[0][0] = 10;
    matrix[0][1] = 20;
    matrix[0][2] = 30;
    matrix[0][3] = 40;

    matrix[1][0] = 110;
    matrix[1][1] = 120;
    matrix[1][2] = 130;
    matrix[1][3] = 140;

    matrix[2][0] = 1110;
    matrix[2][1] = 1120;
    matrix[2][2] = 1130;
    matrix[2][3] = 1140;   
  */  

    for(int row=0;row<3;row++)
        {
            printf("\n\nRow %d\n",row);
            for(int col=0;col<4;col++)
                {
                    printf("[%d] [%d] = %d\n",
                        row,col, matrix[row][col]);
                }
        }

    int *head = &matrix[0][0];
    int *tail = &matrix[2][3];

    printf("start location = %p\n",head);
    printf("end location   = %p\n\n\n",tail);
    
    
    while (head <= tail) {
        printf("%p %d\n", head, *head);
        head++;
    }

    printf("\n\n");
    int *ptr = &matrix[0][0];

    printf("%p %d\n",ptr,*ptr);
    ptr += 11;
    printf("%p %d\n",ptr,*ptr);
    
    
    return 0;
    