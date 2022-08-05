#include<stdio.h>


public void eqeq_false(){
   printf("testing eqeq false - public pointer\n");
   pubilc int *p1, *p2, x;
   p1 = (public int *) malloc(sizeof(int));
   p2 = (public int *) malloc(sizeof(int));
   if(p1 == p2){
      x = 1;
   }
   else{
      x = 2;
   }
   if(x == 2){
      printf("success\n");
   }
   else{
      printf("fail\n");
   }
   free(p1);
   free(p2);
}


public void eqeq_true(){
   printf("testing eqeq true - public pointer\n");
   pubilc int *p1, *p2, x;
   p1 = &x;
   p2 = &x;
   if(p1 == p2){
      x = 1;
   }
   else{
      x = 2;
   }
   if(x == 1){
      printf("success\n");
   }
   else{
      printf("fail\n");
   }
}

public void neq_false(){
   printf("testing neq false - public pointer\n");
   pubilc int *p1, *p2, x;
   p1 = &x;
   p2 = &x;
   if(p1 != p2){
      x = 1;
   }
   else{
      x = 2;
   }
   if(x == 2){
      printf("success\n");
   }
   else{
      printf("fail\n");
   }
}

public void neq_true(){
   printf("testing neq true - public pointer\n");
   pubilc int *p1, *p2, x;
   p1 = (public int *) malloc(sizeof(int));
   p2 = (public int *) malloc(sizeof(int));
   if(p1 != p2){
      x = 1;
   }
   else{
      x = 2;
   }
   if(x == 1){
      printf("success\n");
   }
   else{
      printf("fail\n");
   }
   free(p1);
   free(p2);
}

public int main(){
   eqeq_false();
   eqeq_true();
   neq_false();
   neq_true();
}
