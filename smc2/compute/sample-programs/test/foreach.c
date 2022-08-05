#include <stdio.h>

public int main() {
   
   public int i;
//   private int<5> x[10], y[10]; 
//   private int<10> z[10], q[10];
//  private int a[10], b[10], c[10];
   
//   smcinput(x, 1, 10);
//   smcinput(y, 1, 10);
   
   printf("bounded loop\n");

   private int<3> a = 7, b = 3;
   private int x, y, z;
   
   x = a;
   y = b;
   bound 1000
   for(i = 0; i < 1000; i = i + 1){
//      a[i] = x[i] * y[i];
//      b[i] = z[i] < a[i];
//     a[i] = q[i] < a[i];
//      c[i] = a[i] + b[i];
      z = x > y;
   }
   /*foreach x in range(0, 10) {
      y = y + x;
   }*/

   printf("bounded loop complete\n");
   printf("%d =? true(1)\n", smcopen(z));   
//   smcoutput(z, 1, 10);
   
   return 0;
}
