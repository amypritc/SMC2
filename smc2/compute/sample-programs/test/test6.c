#include <stdio.h>

public int main() {
   

   private int<2> a = 2;
   private int<4> b = 14;
   private int<6> c = 32;
   private int x, y, z;
   public int i;
   
  // printf("init complete\n");
   
   bound 1000
   for(i = 0; i < 1000; i = i + 1){
//      printf("begin loop: %d\n", i);
      x = a << 1;
  //    printf("shl\n");
      z = a - c; 
    //  printf("sub\n");
      y = x + b;
      //printf("add\n");
      y = y * b;
 //     printf("mul\n");
      z = z >= 0;
   //   printf("geq\n");
      x = x >> 1; 
     // printf("shr\n");
   }
   
   return 0;
}
