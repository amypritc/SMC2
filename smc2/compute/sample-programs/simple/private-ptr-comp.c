#include<stdio.h>

public void eqeq_false_single_loc(){
   printf("testing eqeq false - private pointer - single location \n");
   private int *p1, *p2;
   public int x;
   p1 = (private int *) pmalloc(1, private int);
   p2 = (private int *) pmalloc(1, private int);
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
   pfree(p1);
   pfree(p2);
}

public void eqeq_true_single_loc(){
   printf("testing eqeq true - private pointer - single location\n");
   private int *p1, *p2, a;
   public int x;
   p1 = &a;
   p2 = &a;
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

public void eqeq_false_multiple_locs_all_diff(){
   printf("testing eqeq false - private pointer - multiple locations - all different\n");
   private int *p1, *p2;
   private int a = 1, b = 2, c, d;
   public int x;
   if (a < b){
      p1 = &a;
      p2 = &c;
   }
   else{
      p1 = &b;
      p2 = &d;
   }
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
}

public void eqeq_false_multiple_locs_overlap(){
   printf("testing eqeq false - private pointer - multiple locations - overlap\n");
   private int *p1, *p2;
   private int a = 1, b = 2, c;
   public int x;
   if (a < b){
      p1 = &a;
      p2 = &b;
   }
   else{
      p1 = &b;
      p2 = &c;
   }
   if(p1 == p2){
      c = 1;
   }
   else{
      c = 2;
   }
   x = smcopen(c);
   if(x == 2){
      printf("success\n");
   }
   else{
      printf("fail\n");
   }
}

public void eqeq_true_multiple_locs_overlap(){
   printf("testing eqeq true - private pointer - multiple locations - overlap\n");
   private int *p1, *p2;
   private int a = 1, b = 2, c;
   public int x;
   if (a < b){
      p1 = &a;
      p2 = &a;
   }
   else{
      p1 = &b;
      p2 = &c;
   }
   if(p1 == p2){
      c = 1;
   }
   else{
      c = 2;
   }
   x = smcopen(c);
   if(x == 1){
      printf("success\n");
   }
   else{
      printf("fail\n");
   }
}






public void neq_false_single_loc(){
   printf("testing neq false - private pointer - single location\n");
   private int *p1, *p2, a;
   public int x;
   p1 = &a;
   p2 = &a;
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

public void neq_true_single_loc(){
   printf("testing neq true - private pointer - single location \n");
   private int *p1, *p2;
   public int x;
   p1 = (private int *) pmalloc(1, private int);
   p2 = (private int *) pmalloc(1, private int);
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
   pfree(p1);
   pfree(p2);
}

public void neq_true_multiple_locs_all_diff(){
   printf("testing neq true - private pointer - multiple locations - all different\n");
   private int *p1, *p2;
   public int x;
   if (a < b){
      p1 = &a;
      p2 = &c;
   }
   else{
      p1 = &b;
      p2 = &d;
   }
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
}

public void neq_false_multiple_locs_overlap(){
   printf("testing neq false - private pointer - multiple locations - overlap\n");
   private int *p1, *p2;
   private int a = 1, b = 2, c;
   public int x;
   if (a < b){
      p1 = &a;
      p2 = &a;
   }
   else{
      p1 = &b;
      p2 = &c;
   }
   if(p1 != p2){
      c = 1;
   }
   else{
      c = 2;
   }
   x = smcopen(c);
   if(x == 2){
      printf("success\n");
   }
   else{
      printf("fail\n");
   }
}

public void neq_true_multiple_locs_overlap(){
   printf("testing neq true - private pointer - multiple locations - overlap\n");
   private int *p1, *p2;
   private int a = 1, b = 2, c;
   public int x;
   if (a < b){
      p1 = &a;
      p2 = &b;
   }
   else{
      p1 = &b;
      p2 = &c;
   }
   if(p1 != p2){
      c = 1;
   }
   else{
      c = 2;
   }
   x = smcopen(c);
   if(x == 1){
      printf("success\n");
   }
   else{
      printf("fail\n");
   }
}



public int main(){
   eqeq_false();
   eqeq_true();
   neq_false();
   neq_true();
}
