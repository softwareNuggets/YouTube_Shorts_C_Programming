#include <stdio.h>

union Number {
  short age;  // 2 bytes
  float pi;  // 4 bytes
};

int main() {
  // A union lets you store different 
  // data types in the same memory space.

  // The size of a union is determined 
  // by its largest member 

  // This means that storing a value 
  // in one member will overwrite the value 
  // of the other member.

  union Number num;
    
  num.age = 23;
  printf("age = %d, address = %p, sizeof = %ld\n", 
            num.age, 
            (void*)&num.age, 
            sizeof(num));

  num.pi = 3.1415;
  printf("pi = %.2f, address = %p, sizeof = %ld\n", 
           num.pi, 
           (void*)&num.pi, 
           sizeof(num));

  return 0;
}