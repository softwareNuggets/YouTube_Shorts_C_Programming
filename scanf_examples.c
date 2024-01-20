//Example 1:
#include <stdio.h>

int main() {
    //scanf("format specifier", target variables)
   

	int num=0;

    printf("Enter your favorite number:");
    scanf( "%d" ,  &num );

    printf("You typed in %d\n", num);
}



//Example 2:
#include <stdio.h>
int main() {
    //scanf("format specifier", target variables)

    int year=0, month=0, day=0;
    
    printf("Enter today's date (yyyy-mm-dd):");

    //scanf("format specifier", variable)
    scanf("%d-%d-%d", &year, &month, &day );

    printf("You just typed in : \nYear=%d, Month=%d, Day=%d\n",
        year, month, day );

    return (0);
}



//Example 3:
#include <stdio.h>
#include <string.h>

int main() {
    //scanf("format specifier", target variables)
   
    
    char fword[20+1], sword[20+1];
    memset(fword, 0, 20+1);
    memset(sword, 0, 20+1);

    printf("enter two words: (two words)") ;

    scanf("%s %s",fword, sword);

    printf("\nYou typed in:\n[%s] [%s]",fword, sword );
    
    
    return (0);
}



//Example 4:
#include <stdio.h>
#include <string.h>

int main() {
    //scanf("format specifier", target variables)
   
    
    char fword[20+1], sword[20+1];
    memset(fword, 0, 20+1);
    memset(sword, 0, 20+1);

    printf("enter two words in one word: (wordword)") ;

    scanf("%4s%4s",fword, sword);

    printf("\nYou typed in:\n[%s] [%s]",fword, sword );
    
    
    return (0);
}