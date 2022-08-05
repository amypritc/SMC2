#include "LocationTracking.h"

void init_mpz_flt(mpz_t* new_flt, mpz_t* old_flt){
   new_flt = (mpz_t*)malloc(sizeof(mpz_t) * 4);
   int i;
   for(i = 0; i < 4; i++){
      mpz_init_set(new_flt[i], old_flt[i]);
   }   
}




delta init_new_loc(delta current_map, int nest_level, int isPtr, int isFlt){
   delta new_loc;
   if(current_map->hasNext == -1){ // no locations in the list, so this becomes the first
      new_loc = current_map;
      current_map->prev = NULL;
      current_map->next = NULL;
      current_map->last = NULL;
      printf("\n found new delta\n");
   }
   else{
      new_loc = (delta)malloc(sizeof(struct delta_)); 
      printf("\n adding to delta\n");
      new_loc->next = NULL;
      new_loc->last = NULL;
      if(current_map->hasNext == 0){ // add this location as the next since only one location in the list
         current_map->next = new_loc;
         current_map->hasNext = 1;
         current_map->last = new_loc;
         new_loc->prev = current_map;
      }
      else{ // add this new location to the end of the linked list
         current_map->last->next = new_loc;
         new_loc->prev = current_map->last;
         current_map->last->hasNext = 1;
         current_map->last = new_loc;
      }
   }
   new_loc->nest_level = nest_level;
   new_loc->isPtr = isPtr;
   new_loc->isFlt = isFlt;
   new_loc->tag = 0;
   new_loc->hasNext = 0;
   return new_loc;
}

/* Using the Location-based Semantics to update a location storing an int */
void add_int_location(delta current_map, mpz_t* update_loc, mpz_t update_val, int nest_level){
   printf("Location-based add int\n");
   delta new_loc = init_new_loc(current_map, nest_level, 0, 0);
   new_loc->loc.int_location = update_loc;
   mpz_init_set(new_loc->u.i.origVal, update_val);
}


// Check if the pointed to int location is tracked
void check_int_pointer(delta current_map, priv_ptr update_ptr, int derefNum, int nest_level){
   printf("Location-based check if int pointer pointed-to-loc is in map\n");
   if(current_map->hasNext == -1){ // empty map
      if(derefNum == 1){ // single deref
         if(update_ptr->size == 1){ // single loc
            // Add the pointed to location to the map
            delta new_loc = init_new_loc(current_map, nest_level, 0, 0);
            new_loc->loc.int_location = update_ptr->list->head->next->u.int_var_location;
            mpz_init_set(new_loc->u.i.origVal, *(new_loc->loc.int_location));
         }
         else{
            // TODO: handle multiple locations           
         }
      }
      else{
         // TODO: handle multiple level deref
      }   
   }
   else{/*
      delta next_loc = current_map;
      // check if loc is in current map
      int found = 0;
      while(found == 0){
         if(next_loc->isFlt == 0){
            if(next_loc->isPtr == 0){
               if(update_loc == next_loc->loc.int_location){
                  printf("found!");
                  found = 1;
                  break;
               }
            }
         }
         if(next_loc->hasNext != 1) break;
         next_loc = next_loc->next;
      }
      // TODO: check outer map contains */     
   }
   printf("done\n");
}


// Check if the pointed to int pointer location is tracked
// TODO (full function rewrite)
void check_int_pointer_ptr(delta current_map, priv_ptr update_ptr, int derefNum, int nest_level){
   printf("Location-based check if int pointer pointed-to-loc is in map\n");
   /*if(current_map->hasNext == -1){ // empty map
      delta new_loc = init_new_loc(current_map, nest_level, 0, 0);
      new_loc->loc.int_location = update_loc;
      mpz_init_set(new_loc->u.i.origVal, update_val);
   }
   else{
      delta next_loc = current_map;
      // check if loc is in current map
      int found = 0;
      while(found == 0){
         if(next_loc->isFlt == 0){
            if(next_loc->isPtr == 0){
               if(update_loc == next_loc->loc.int_location){
                  printf("found!");
                  found = 1;
                  break;
               }
            }
         }
         if(next_loc->hasNext != 1) break;
         next_loc = next_loc->next;
      }
      if(found == 0){
         // TODO: add to map
         // TODO: check outer map contains 
      }     
   }*/
}


/* Using the Location-based Semantics to update a location storing a float */
// TODO (full function refactor)
void add_float_location(delta current_map, mpz_t** update_loc, mpz_t* update_val, int nest_level, enum branch_id current_branch){
   // TODO
   printf("Location-based update float\n");
   if((current_branch == B_INIT) || (current_map->hasNext == -1)){
      delta new_loc = init_new_loc(current_map, nest_level, 0, 1);
      new_loc->loc.float_location = update_loc;
      //mpz_init(new_loc->u.flt.origVal);
      //mpz_set(new_loc->u.flt.origVal, update_val);
   }
   else{
      
   }
}


/* Using the Location-based Semantics to update a location storing an int pointer(location) */
// TODO (full function refactor)
void add_int_pointer_location(delta current_map, priv_ptr update_loc, priv_ptr update_ptr, int nest_level, enum branch_id current_branch){
   printf("Location-based update int pointer\n");
   if((current_branch == B_INIT) || (current_map->hasNext == -1)){
      delta new_loc = init_new_loc(current_map, nest_level, 1, 0);
      new_loc->loc.ptr_location = update_loc;
      new_loc->u.ptr.origVal = update_ptr;
   }
   else{
      
   }
}


/* Using the Location-based Semantics to update a location storing an float pointer(location) */
// TODO (full function refactor)
void update_float_pointer(delta current_map, priv_ptr update_loc, priv_ptr update_ptr, int nest_level, enum branch_id current_branch){
   // TODO
   printf("Location-based update float pointer\n");
   if((current_branch == B_INIT) || (current_map->hasNext == -1)){
      delta new_loc = init_new_loc(current_map, nest_level, 1, 1);
      new_loc->loc.ptr_location = update_loc;
      new_loc->u.ptr.origVal = update_ptr;
   }
   else{
      
   }
}


/* Restoring values after the THEN branch has been executed */
void location_based_restore(delta current_map, int nest_level, SMC_Utils *__s){
   printf("Location-based restore\n");
   delta next_loc = current_map;
   while(next_loc != NULL){
      next_loc->tag = 1;
      // set thenVal
      // restore origVal to the location
      if(next_loc->isFlt == 1){
         if(next_loc->isPtr == 1){
            printf("TODO\n");
         }
         else{
            //__s->smc_set();
            printf("TODO\n");
         }
      }
      else if(next_loc->isPtr == 1){
         printf("TODO\n");
      }
      else{ // int, non-pointer
         printf("int location\n");
         mpz_init_set(next_loc->u.i.thenVal, *(next_loc->loc.int_location));
         printf("%d\n", __s->smc_open(next_loc->u.i.thenVal, -1));
         mpz_set(*(next_loc->loc.int_location), next_loc->u.i.origVal);
         printf("restored::%d\n", __s->smc_open(*(next_loc->loc.int_location), -1));
      }
      if(next_loc->hasNext != 1) break;
      next_loc = next_loc->next;
   }
   printf("restore done\n");
}



/* Updating a location of the next level up of nested priv-cond if  */
/* Local function (not meant for outside use) so not included in .h file */
/*
void update_top_map(delta current_loc, delta top_map, int nest_level, enum branch_id top_branch){
   // TODO: handle storing into appropriate branch of top_map
   if(current_loc->isFlt == 0){ //intSMC_Utils *__s
      if(current_loc->isPtr == 0){ //non-pointer
         update_int(top_map, current_loc->int_location, current_loc->int_location, nest_level, top_branch);
      }
      else{ //pointer
         // TODO: fix NULL
         update_int_pointer(top_map, current_loc->int_location, NULL, nest_level, top_branch);
      }
   }
   else{ //float
      if(current_loc->isPtr == 0){ //non-pointer
         update_float(top_map, current_loc->float_location, current_loc->float_location, nest_level, top_branch);
      }
      else{ //pointer
         // TODO: fix NULL
         update_float_pointer(top_map, current_loc->float_location, NULL, nest_level, top_branch);
      }
   }
}
*/


/* Resolving true values after the execution of the ELSE branch */
void location_based_resolve(delta current_map, int nest_level, mpz_t cond, SMC_Utils *__s, int threadID){
   printf("Location-based resolve\n");
   delta next_loc = current_map;
   while(next_loc != NULL){
      if(next_loc->isFlt == 1){
         if(next_loc->isPtr == 1){
            printf("TODO flt ptr\n");
         }
         else{
            printf("TODO flt\n");
         }
      }
      else if(next_loc->isPtr == 1){
         printf("TODO int ptr\n");
      }
      else{ // int, non-pointer
         printf("int location\n");
         if(next_loc->tag == 0){
            __s->smc_priv_eval(*(next_loc->loc.int_location), next_loc->u.i.origVal, cond, threadID);
         }
         else{
            __s->smc_priv_eval(*(next_loc->loc.int_location), next_loc->u.i.thenVal, cond, threadID);
         }
      }
      if(next_loc->hasNext != 1) break;
      next_loc = next_loc->next;
   }
   printf("resolve done\n");
}



