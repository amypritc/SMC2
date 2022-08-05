/*   
   PICCO: A General Purpose Compiler for Private Distributed Computation
   ** Copyright (C) 2013 PICCO Team
   ** Department of Computer Science and Engineering, University of Notre Dame

   PICCO is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   PICCO is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with PICCO. If not, see <http://www.gnu.org/licenses/>.
*/


#include "var_size.h"

/* Maximum size to allow for ints */
int MAX_INT_SIZE = 32;

/* Used when inside a function call to help speed along lookups */
int inside_fun_call = 0; // set to 1 when in fun call, 0 when done
var_size current_fun_params = NULL; // be careful of nested function calls

/*********************************
 *                               *
 *      SIZE  COMPUTATION        *
 *                               *
 *********************************/
int const_val_compute_size(int val){
  //printf("size of %d: ", val);
  int result = 0;
  if(val == 0){
    result = 1;
  }
  while(val >= 2){
    val = val / 2;
    result += 1;
  }
  if(val >= 1){
    result += 1;
  }
  //printf("%d\n", result);
  return result;
}


int get_size_binary_op(int a, int b, astexpr e, int bop){
   int result = -1;
   switch(bop){
      case BOP_shl:
         if(e->type == CONSTVAL){
            int s = atoi(e->u.str);
            if(s < 0){ 
               fprintf(stderr, "warning: shift count is negative. Setting size to MAX. \n");
               result = MAX_INT_SIZE;
            }
            else { 
               result = a + s;
            }
         }
         else{
            result = MAX_INT_SIZE;
         }
         break;
      case BOP_shr:
         if(e->type == CONSTVAL){
            int s = atoi(e->u.str);
            if(s < 0){ 
               fprintf(stderr, "warning: shift count is negative. Setting size to MAX. \n");
               result = MAX_INT_SIZE;
            }
            else { 
               result = a - s;
            }
         }
         else{
            result = MAX_INT_SIZE;
         }
         break;
      case BOP_leq:
      case BOP_geq:
      case BOP_eqeq:
      case BOP_neq:
      case BOP_lt:
      case BOP_gt:
         result = 1;
         break;
      case BOP_land:
      case BOP_lor:
      case BOP_band:
      case BOP_bor: 
      case BOP_xor:
         result = (a > b) ? a : b;
         break;
      case BOP_add:
      case BOP_sub:
         result = (a > b) ? a + 1 : b + 1;
         break;
      case BOP_mul:
         result = a + b;
         break;
      case BOP_div:
         result = a;
         break;
      case BOP_mod:
         result = a;
         break;
      case BOP_cast:
         // TODO
         break;
      case BOP_dot:
         // TODO
         break;
      default:
         fprintf(stderr, "[var_size: ast_expr_compute_size]: BOP: bug! BOP type %d\n", bop);
   }
   result = (result < 1) ? 1 : result;                         // can't be less than 1
   result = (result > MAX_INT_SIZE) ? MAX_INT_SIZE : result;   // can't be greater than MAX_INT_SIZE
   return result;
}




void ast_stmt_compute_size(aststmt t, var_table vartab)
{
  switch (t->type)
  {
    case JUMP:
      fprintf(stderr, "[var_size: ast_stmt_compute_size]: JUMP \n");
      ast_stmt_jump_compute_size(t, vartab);
      break;
    case ITERATION:
      fprintf(stderr, "[var_size: ast_stmt_compute_size]: ITERATION \n");
      ast_stmt_iteration_compute_size(t, vartab);
      break;
    case SELECTION:
      fprintf(stderr, "[var_size: ast_stmt_compute_size]: SELECTION \n");
      ast_stmt_selection_compute_size(t, vartab);
      break;
    case LABELED:
      fprintf(stderr, "[var_size: ast_stmt_compute_size]: LABELED \n");
      ast_stmt_labeled_compute_size(t, vartab);
      break;
    case EXPRESSION:
      fprintf(stderr, "[var_size: ast_stmt_compute_size]: EXPR \n");
      if (t->u.expr != NULL)  /* Empty statement */
        ast_expr_compute_size(t->u.expr, vartab);
      break;
    case COMPOUND:
      fprintf(stderr, "[var_size: ast_stmt_compute_size]: COMPOUND \n");
      if (t->body)
        ast_stmt_compute_size(t->body, vartab);
      break;
    case STATEMENTLIST:
      fprintf(stderr, "[var_size: ast_stmt_compute_size]: STMTLIST \n");
      ast_stmt_compute_size(t->u.next, vartab);
      ast_stmt_compute_size(t->body, vartab);
      break;
    case DECLARATION:
      fprintf(stderr, "[var_size: ast_stmt_compute_size]: DECL \n");
//      ast_spec_compute_size(t->u.declaration.spec, vartab);
      if (t->u.declaration.decl){
        if(t->u.declaration.spec->subtype == SPEC_int){
          //fprintf(stderr, "found spec_int, %d, %d", t->u.declaration.spec->type, t->u.declaration.spec->optimal_size);
          
        }
        ast_decl_compute_size(t->u.declaration.decl, t->u.declaration.spec, vartab);
        
      }
      break;
    case FUNCDEF:
      fprintf(stderr, "[var_size: ast_stmt_compute_size]: FUNCDEF \n");
//     if (t->u.declaration.spec)
//        ast_spec_compute_size(t->u.declaration.spec, vartab);
      ast_decl_compute_size(t->u.declaration.decl, t->u.declaration.spec, vartab);   /* always non-NULL */
      if (t->u.declaration.dlist)
        ast_stmt_compute_size(t->u.declaration.dlist, vartab);
      ast_stmt_compute_size(t->body, vartab);    /* always non-NULL */
      break;
    case OMPSTMT:
      fprintf(stderr, "[var_size: ast_stmt_compute_size]: OMPSTMT \n");
      //ast_ompcon_compute_size(t->u.omp);
      break;
    case VERBATIM:
      fprintf(stderr, "[var_size: ast_stmt_compute_size]: VERBATIM \n");
      //if (t->u.code)
      //   free(t->u.code);
      break;
    case OX_STMT:
      fprintf(stderr, "[var_size: ast_stmt_compute_size]: OX_STMT \n");
       //ast_oxcon_compute_size(t->u.ox);
       break;
    case SMC:
      fprintf(stderr, "[var_size: ast_stmt_compute_size]: SMC \n");
      break;
    default:
      fprintf(stderr, "[var_size: ast_stmt_compute_size]: bug!  (type = %d)\n", t->type);
  }
}



int ast_expr_compute_size(astexpr t, var_table vartab)
{
  int result = -1;
  switch (t->type)
  {
    case IDENT:
      fprintf(stderr, "[var_size: ast_expr_compute_size]: IDENT %s: %d\n", t->u.sym->name, t->optimal_size);
      result = get_varsize(vartab, t->u.sym->name);
      t->optimal_size = result;
      fprintf(stderr, "  opt-size: %d\n", result);
      break;
    case CONSTVAL:
      fprintf(stderr, "[var_size: ast_expr_compute_size]: CONSTVAL \n");
      int optimal_size = const_val_compute_size(atoi(t->u.str));
      t->optimal_size = optimal_size;
      fprintf(stderr, "  updating size of constval %s: %d->%d\n", t->u.str, t->size, t->optimal_size);
      result = t->optimal_size;
      break;
    case STRING:
      fprintf(stderr, "[var_size: ast_expr_compute_size]: STRING \n"); 
      // TODO;
      break;
    case FUNCCALL:
      fprintf(stderr, "[var_size: ast_expr_compute_size]: FUNCCALL \n");
      ast_expr_compute_size(t->left, vartab);
      if (t->right)
        ast_expr_compute_size(t->right, vartab);
      break;
    case ARRAYIDX:
      fprintf(stderr, "[var_size: ast_expr_compute_size]: ARRAYIDX \n"); 
      ast_expr_compute_size(t->left, vartab);
      ast_expr_compute_size(t->right, vartab);
      result = t->left->optimal_size;
      fprintf(stderr, "array index: %d[%d]\n", t->left->optimal_size, t->right->optimal_size);
      break;
    case DOTFIELD: 
      fprintf(stderr, "[var_size: ast_expr_compute_size]: DOTFIELD \n");
      ast_expr_compute_size(t->left, vartab);
      break;
    case PTRFIELD: 
      fprintf(stderr, "[var_size: ast_expr_compute_size]: PTRFIELD \n");
      ast_expr_compute_size(t->left, vartab);
      break;
    case BRACEDINIT: 
      fprintf(stderr, "[var_size: ast_expr_compute_size]: BRACEINIT \n");
      ast_expr_compute_size(t->left, vartab);
      break;
    case CASTEXPR: 
      fprintf(stderr, "[var_size: ast_expr_compute_size]: CASTEXPR \n");
      // TODO: not sure of the spec to pass here
      ast_decl_compute_size(t->u.dtype, NULL, vartab);
      ast_expr_compute_size(t->left, vartab);
      break;
    case CONDEXPR: 
      fprintf(stderr, "[var_size: ast_expr_compute_size]: CONDEXPR \n");
      ast_expr_compute_size(t->u.cond, vartab);
      ast_expr_compute_size(t->left, vartab);
      ast_expr_compute_size(t->right, vartab);
      break;
    case UOP:
      fprintf(stderr, "[var_size: ast_expr_compute_size]: UOP %s\n", UOP_symbols[t->opid]); 
      if (t->opid == UOP_sizeoftype || t->opid == UOP_typetrick){
         // TODO: not sure of the spec to pass here 
        ast_decl_compute_size(t->u.dtype, NULL, vartab);
      }
      else{
        result = ast_expr_compute_size(t->left, vartab);
      }
      break;
    case BOP: {
      fprintf(stderr, "[var_size: ast_expr_compute_size]: BOP %s\n", BOP_symbols[t->opid]);
      int a = ast_expr_compute_size(t->left, vartab);
      int b = ast_expr_compute_size(t->right, vartab);
      fprintf(stderr, "  found sizes: %d %s %d", a, BOP_symbols[t->opid], b);
      result = get_size_binary_op(a, b, t->right, t->opid);
      t->optimal_size = result;
      fprintf(stderr, " -> resulting size: %d\n", result);
      break;
    }
    case PREOP: 
      fprintf(stderr, "[var_size: ast_expr_compute_size]: PREOP \n");
      ast_expr_compute_size(t->left, vartab);
      break;
    case POSTOP: 
      fprintf(stderr, "[var_size: ast_expr_compute_size]: POSTOP \n");
      ast_expr_compute_size(t->left, vartab);
      break;
    case ASS: {
      fprintf(stderr, "[var_size: ast_expr_compute_size]: ASS %s\n", ASS_symbols[t->opid]);
      int a = ast_expr_compute_size(t->left, vartab);
      int b = ast_expr_compute_size(t->right, vartab);
      fprintf(stderr, "  found sizes: %d '=' %d\n", a, b);
      int res = update_varsize(vartab, t->left->u.sym->name, b);
      if(res){
         t->left->optimal_size = b;
         t->optimal_size = b;
      }
      fprintf(stderr, "  updated size: %s -> %d\n", t->left->u.sym->name, b);
      result = b;
      break;
    }
    case DESIGNATED: 
      fprintf(stderr, "[var_size: ast_expr_compute_size]: DESIGNATED! \n");
      ast_expr_compute_size(t->left, vartab);
      ast_expr_compute_size(t->right, vartab);
      break;         
    case IDXDES: 
      fprintf(stderr, "[var_size: ast_expr_compute_size]: IDXDES! \n");
      ast_expr_compute_size(t->left, vartab);
      break;
    case DOTDES: 
      fprintf(stderr, "[var_size: ast_expr_compute_size]: DOTDES! \n");
      break;
    case COMMALIST:
      fprintf(stderr, "[var_size: ast_expr_compute_size]: COMMALIST! \n");
    case SPACELIST:
      fprintf(stderr, "[var_size: ast_expr_compute_size]: SPACELIST! \n");
      ast_expr_compute_size(t->left, vartab);
      ast_expr_compute_size(t->right, vartab);
      break;         
    default:
      fprintf(stderr, "[var_size: ast_expr_compute_size]: bug !! (type = %d)\n", t->type);
  }
  if(result > MAX_INT_SIZE) result = MAX_INT_SIZE;
  return result;
}



void ast_stmt_labeled_compute_size(aststmt t, var_table vartab)
{
  switch (t->subtype)
  {
    case SLABEL:
      break;
    case SCASE:
      ast_expr_compute_size(t->u.expr, vartab);
      break;
    case SDEFAULT:
      break;
    default:
      fprintf(stderr, "[ast_stmt_labeled_compute_size]: b u g !!\n");
  }
  ast_stmt_compute_size(t->body, vartab);
}


void ast_stmt_jump_compute_size(aststmt t, var_table vartab)
{
  switch (t->subtype)
  {
    case SBREAK:
      break;
    case SCONTINUE:
      break;
    case SRETURN:
      if (t->u.expr != NULL)
        ast_expr_compute_size(t->u.expr, vartab);
      break;
    case SGOTO:
      break;
    default:
      fprintf(stderr, "[ast_stmt_jump_compute_size]: b u g !!\n");
  }
}

void ast_stmt_iteration_compute_size(aststmt t, var_table vartab)
{
  switch (t->subtype)
  {
    case SFOR:
      fprintf(stderr, "[var_size: ast_stmt_iteration_compute_size]: SFOR! ");
      if(t->u.iteration.bound){
         int bound = atoi(t->u.iteration.bound->u.str);
         if(bound > 0){
            fprintf(stderr, " (bound = %d) \n", bound);
            // This should be fine, since the effects only need to be applied once 
            if (t->u.iteration.init != NULL)
               ast_stmt_compute_size(t->u.iteration.init, vartab); /* Could also be a declaration */
            // TODO: won't handle effects on variables within the condition
            if (t->u.iteration.cond != NULL)
               ast_expr_compute_size(t->u.iteration.cond, vartab);
            // Not ideal, but should basically do what's needed - find the largest size necessary for the loop body
            for(int i = 0; i < bound; i++){
               ast_stmt_compute_size(t->body, vartab);
               // needs to be evaluated after the body, as it would be executed
               if (t->u.iteration.incr != NULL)
                  ast_expr_compute_size(t->u.iteration.incr, vartab);
            }
         }
         else{
            fprintf(stderr, "[var_size: ast_stmt_iteration_compute_size]: ERROR! for loop bound (%d); must be > 0 \n", bound);
         }
      }
      else{
         fprintf(stderr, "[var_size: ast_stmt_iteration_compute_size]: ERROR! for loop bound missing! \n");
      }
      
      break;
    case SWHILE:
      fprintf(stderr, "[var_size: ast_stmt_iteration_compute_size]: unimplemented SWHILE!\n");
      ast_expr_compute_size(t->u.iteration.cond, vartab);
      ast_stmt_compute_size(t->body, vartab);
      break;
    case SDO:
      fprintf(stderr, "[var_size: ast_stmt_iteration_compute_size]: unimplemented SDO!\n");
      ast_stmt_compute_size(t->body, vartab);
      ast_expr_compute_size(t->u.iteration.cond, vartab);
      break;
    default:
      fprintf(stderr, "[ast_stmt_iteration_compute_size]: b u g !!\n");
  }
}

void ast_stmt_selection_compute_size(aststmt t, var_table vartab)
{
  switch (t->subtype)
  {
    case SSWITCH:
      fprintf(stderr, "[var_size: ast_stmt_selection_compute_size]: unimplemented SSWITCH!\n");
      ast_expr_compute_size(t->u.selection.cond, vartab);
      ast_stmt_compute_size(t->body, vartab);
      break;
    case SIF:
      fprintf(stderr, "[var_size: ast_stmt_selection_compute_size]: unimplemented SIF!\n");
      ast_expr_compute_size(t->u.selection.cond, vartab);
      ast_stmt_compute_size(t->body, vartab);
      if (t->u.selection.elsebody, vartab)
        ast_stmt_compute_size(t->u.selection.elsebody, vartab);
      break;
    default:
      fprintf(stderr, "[ast_stmt_selection_compute_size]: b u g !!\n");
  }
}


void ast_decl_compute_size(astdecl t, astspec spec, var_table vartab)
{
  switch (t->type)
  {
    case DIDENT:
      fprintf(stderr, "[var_size: ast_decl_compute_size]: DIDENT (%s)!\n", t->u.id->name);
      if (strcmp(t->u.id->name, "main")){  // don't include main function 
         if(spec){ // skip argv_ignored, argc_ignored that don't have spec's
            //fprintf(stderr, " SPEC \n");
            if(spec->u.next){ 
               fprintf(stderr, "  SPEC->next: %d \n", spec->u.next->optimal_size);
               //fprintf(stderr, "  priv = %d, %d\n", spec->subtype, spec->body->subtype);
               new_var(vartab, t->u.id->name, spec->u.next->optimal_size, spec->body->subtype);
            }
         }
      }
      break;
    case DPAREN:
      fprintf(stderr, "[var_size: ast_decl_compute_size]: DPAREN!\n");
      ast_decl_compute_size(t->decl, NULL, vartab);
      break;
    case DARRAY:
      // TODO: fix this
      fprintf(stderr, "[var_size: ast_decl_compute_size]: DARRAY!\n");
      if (t->decl){ /* Maybe abstract declarator */
        // TODO: not sure of the spec to pass here
        ast_decl_compute_size(t->decl, spec, vartab);
      }
      if (t->spec){
        ast_spec_compute_size(t->spec, vartab);
      }
      if (t->u.expr){
        ast_expr_compute_size(t->u.expr, vartab);
      }
      break;
    case DFUNC:      /* Maybe abstract declarator */
      fprintf(stderr, "[var_size: ast_decl_compute_size]: DFUNC!\n");
      if (t->decl){
        // TODO: not sure of the spec to pass here
        ast_decl_compute_size(t->decl, spec, vartab);
      }
      if (t->u.params){
        // TODO: not sure of the spec to pass here
        ast_decl_compute_size(t->u.params, spec, vartab);
      }
      break;
    case DINIT:
      fprintf(stderr, "[var_size: ast_decl_compute_size]: DINIT!\n");
      // TODO: not sure of the spec to pass here
      ast_decl_compute_size(t->decl, spec, vartab);
      if (t->u.expr != NULL)  /* Empty statement */
        ast_expr_compute_size(t->u.expr, vartab);
      break;
    case DECLARATOR:
      fprintf(stderr, "[var_size: ast_decl_compute_size]: DECLARATOR!\n");
//      if(t->decl){
//         fprintf(stderr, "  has decl: %d, ", t->decl->subtype);
         //if(t->decl->u.id) fprintf(stderr, "%s, ", t->decl->u.id->name);
//         if(t->spec){ fprintf(stderr, "found spec %d ", t->spec->optimal_size);
//            if(t->spec->u.next) fprintf(stderr, "->u.next %d", t->spec->u.next->optimal_size);
//         }
//         fprintf(stderr, "\n");
//      }
//      if(spec) if(spec->u.next) printf("SPEC: %d ", spec->u.next->optimal_size);
      // TODO: not sure of the spec to pass here
      ast_decl_compute_size(t->decl, spec, vartab);
      break;
    case ABSDECLARATOR:
      fprintf(stderr, "[var_size: ast_decl_compute_size]: ABSDECLARATOR!\n");
      if (t->spec)      /* pointer */
        ast_spec_compute_size(t->spec, vartab);
      if (t->decl)      /* could be NULL */ // TODO: not sure of the spec to pass here
        ast_decl_compute_size(t->decl, spec, vartab);
      break;
    case DPARAM:
      fprintf(stderr, "[var_size: ast_decl_compute_size]: DPARAM!\n");
      ast_spec_compute_size(t->spec, vartab);   /* Never NULL */
      if (t->decl){      /* could be NULL */
        // TODO: not sure of the spec to pass here
        ast_decl_compute_size(t->decl, NULL, vartab);
      }
      break;
    case DELLIPSIS:
      fprintf(stderr, "[var_size: ast_decl_compute_size]: DELLIPSIS!\n");
      break;
    case DBIT:
      fprintf(stderr, "[var_size: ast_decl_compute_size]: DBIT!\n");
      if (t->decl){
        // TODO: not sure of the spec to pass here
        ast_decl_compute_size(t->decl, spec, vartab);
      }
      ast_expr_compute_size(t->u.expr, vartab);
      break;
    case DSTRUCTFIELD:
      fprintf(stderr, "[var_size: ast_decl_compute_size]: DSTRUCTFIELD!\n");
      if (t->spec)      /* pointer */
        ast_spec_compute_size(t->spec, vartab);
      if (t->decl){
        ast_decl_compute_size(t->decl, t->spec, vartab);
      }
      break;
    case DCASTTYPE:
      fprintf(stderr, "[var_size: ast_decl_compute_size]: DCASTTYPE!\n");
      ast_spec_compute_size(t->spec, vartab);        /* Always non-NULL */
      if (t->decl){
        // TODO: not sure of the spec to pass here
        ast_decl_compute_size(t->decl, t->spec, vartab);
      }
      break;
    case DLIST:
      fprintf(stderr, "[var_size: ast_decl_compute_size]: DLIST (type = %d)\n", t->subtype);
      switch (t->subtype)
      {
        case DECL_decllist:
        case DECL_idlist:
        case DECL_paramlist:
          // TODO: not sure of the spec to pass here
          ast_decl_compute_size(t->u.next, spec, vartab);
          ast_decl_compute_size(t->decl, spec, vartab);
          break;
        case DECL_fieldlist:
          ast_decl_compute_size(t->u.next, spec, vartab);
          ast_decl_compute_size(t->decl, spec, vartab);
          break;
        default:
          fprintf(stderr, "[ast_decl_compute_size]: list b u g !!\n");
      }
      break;
    default:
      fprintf(stderr, "[ast_decl_compute_size]: b u g !!\n");
  }
}


// This currently doesn't do anything, its probably not needed
void ast_spec_compute_size(astspec t, var_table vartab)
{
  fprintf(stderr, "[var_size: ast_spec_compute_size]: SPEC unimplemented (type = %d)!\n", t->type);
  switch (t->type)
  {
    case SPEC:
    case STCLASSSPEC:
      break;
    case USERTYPE:
      break;
    case SUE:
      switch (t->subtype)
      {
        case SPEC_enum:
          if (t->body)
            ast_spec_compute_size(t->body, vartab);
          break;
        case SPEC_struct:
        case SPEC_union:
          if (t->u.decl) // TODO: not sure of the spec to pass here
            ast_decl_compute_size(t->u.decl, NULL, vartab);
          break;
        default:
          fprintf(stderr, "[ast_spec_compute_size]: SUE b u g !!\n");
      }
      break;
    case ENUMERATOR: 
      if (t->u.expr)
        ast_expr_compute_size(t->u.expr, vartab);
      break;
    case SPECLIST:
      switch (t->subtype)
      {
        case SPEC_Rlist:
          ast_spec_compute_size(t->body, vartab);
          ast_spec_compute_size(t->u.next, vartab);
          break;
        case SPEC_Llist:
          ast_spec_compute_size(t->u.next, vartab);
          ast_spec_compute_size(t->body, vartab);
          break;
        case SPEC_enum:
          ast_spec_compute_size(t->u.next, vartab);
          ast_spec_compute_size(t->body, vartab);
          break;
        default:
          fprintf(stderr, "[ast_spec_compute_size]: list b u g !!\n");
      }
      break;
    default:
      fprintf(stderr, "[ast_spec_compute_size]: b u g !!\n");
  }
}






var_table var_size_compute(aststmt ast, var_table vartab){
   if(debug_msg) printf("Entering var size computation pass\n");
   ast_stmt_compute_size(ast, vartab);
   if(debug_msg) printf("Exiting var size computation pass\n");
}


/*********************************
 *                               *
 *      LOOP / FUNC  EVAL        *
 *                               *
 *********************************/




/*********************************
 *                               *
 *      LOOKUP /  MODIFY         *
 *                               *
 *********************************/
 
/* Loop to find the variable in the table */
var_size find_var_loop(var_size var, char* name){
   var_size v = NULL;
   var_size next = var;
   while(next){
      if(!strcmp(name, next->name)){ // found it!
         v = next;
         break;
      }
      else{
         next = next->next;
      }
   }
   return v;
}
 
/* Find the variable in the table */
var_size find_var(var_table vartab, char* name){
   var_size v = NULL;
   /* When in fun call, check the params first */
   if(inside_fun_call){
      v = find_var_loop(current_fun_params, name);
      if(v) return v;
   }
   /* check the variable table */
   v = find_var_loop(vartab->first, name);
   return v;
}

/* Obtain the size stored for the variable */
int get_varsize(var_table vartab, char* name){
   var_size v = find_var(vartab, name);
   int size = -1; // return -1 if the variable wasn't found
   if(v){ 
      size = v->current_size;
   }
   return size;
}

/* Update the size stored for the variable */
int update_varsize(var_table vartab, char* name, int new_size){
   var_size v = find_var(vartab, name);
   int updated = -1; // return -1 if the variable wasn't found
   if(v){ // not NULL
      if(new_size < v->max_size){ // not larger than max
         v->current_size = new_size;
         if(new_size > v->current_max){ // new max size for var
            v->current_max = new_size;
         }
         updated = 1;
      }
      else{ // >= max
         v->current_size = v->max_size;
         v->current_max = v->max_size;
         updated = 0;
      }
   }
   return updated;
}


/*********************************
 *                               *
 *      INITIALIZATION           *
 *                               *
 *********************************/

/* Top-level general variable entry initialization */
var_size init_var(var_table vartab, char *name, enum vartype type, int size, int privacy){
   fprintf(stderr, "creating new variable table entry (%s); ", name);
   var_size v = smalloc(sizeof(struct var_size_));
   v->type = type;
   /* piggy-backing on already allocated name -> do not clear out at end */
   v->name = name; 
   /* set privacy label */
   v->privacy = privacy;
   fprintf(stderr, "init size; ");
   /* initialize sizes */
   if(size > 0){ /* has declared size */
      v->current_size = size;
      v->current_max = size;
      v->max_size = size;
   }
   else{ /* Need to determine the size */
      v->current_size = 1;
      v->current_max = 1;
      v->max_size = 32;
   }
   /* doesn't have a next yet */
   v->next = NULL;
   fprintf(stderr, "adding to table; ");
   /* Add to variable table */
   if(!vartab->first){ /* empty var_table */
      vartab->first = v;
      vartab->last = v;
   }
   else{ /* add at end */
      vartab->last->next = v;
      vartab->last = v;
   }
   fprintf(stderr, "init_var complete\n");
   return v;
}

var_size new_var(var_table vartab, char *name, int size, int privacy){
   var_size v = init_var(vartab, name, VINT, size, privacy);
   /* not a function */ 
   v->params = NULL;
   v->body = NULL;
   return v;
}

var_size new_func(var_table vartab, char *name, int size, int privacy){
   var_size v = init_var(vartab, name, VFUNC, size, privacy);
   /* Add parameters */

   /* Add body */

   return v;
}

var_table new_var_table(){
  var_table vartab = smalloc(sizeof(struct var_table_));
  vartab->first = NULL;
  vartab->last = NULL;
  return vartab;
}


/*********************************
 *                               *
 *      FREE    vartab           *
 *                               * 
 *********************************/


/* Free the memory associated with a size_calc_expr element */
void size_calc_expr_clear(size_calc_expr current){
   fprintf(stderr, "   size_calc_expr_clear begin\n");
   switch(current->type){
      /* For binary ops, need to free the 2 expr lower in tree */
      /* Without breaks in between, cases fall through eachother, so should clear our both e1/e2 */
      case VADD:
      case VSUB:
      case VMUL:
      case VDIV:
      case VLSH:
      case VRSH: 
      case VCOMP:
         size_calc_expr_clear(current->u.op.e2);
      /* For ++, need to free the 1 expr lower in tree */
      case VINCR:
         size_calc_expr_clear(current->u.op.e1);
         break;
      case VID:
      case VCONST:
      default:
         break;
      free(current);
   }
   fprintf(stderr, "   size_calc_expr_clear begin\n");
}


/* Free the memory associated with a size_calc_stmt element */
void size_calc_stmt_clear(size_calc_stmt current){
   fprintf(stderr, "  size_calc_stmt_clear begin\n");
   size_calc_stmt next = current;
   while(current){
      next = current->next;
      size_calc_expr_clear(current->value);
      free(current);
      current = next;
   }
   fprintf(stderr, "  size_calc_stmt_clear begin\n");
}


/* Free the memory associated with a var_size element */
void var_size_clear(var_size current){
   fprintf(stderr, " var_size_clear begin\n");
   var_size next = current;
   while(current){
      next = current->next;
      if(current->type == VFUNC){
         size_calc_stmt_clear(next->body);
         var_size_clear(current->params);
      }
      free(current);
      current = next;
   }
   fprintf(stderr, " var_size_clear complete\n");
}

/* Free the memory associated with the entire variable table */
void var_table_clear(var_table vartab){
   fprintf(stderr, "var_table_clear begin\n");
   var_size_clear(vartab->first);
   fprintf(stderr, "var_table_clear complete\n");
}






