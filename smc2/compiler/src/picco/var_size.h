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



#ifndef __VAR_SIZE_H__
#define __VAR_SIZE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*********************************
 *                               *
 *      DEFINTIIONS              *
 *                               *
 *********************************/
/* typedefs need to come before other includes to register properly */
typedef struct size_calc_expr_   *size_calc_expr;
typedef struct size_calc_stmt_   *size_calc_stmt;
typedef struct var_size_         *var_size;
typedef struct var_table_        *var_table;

#include "picco.h"   /* Needed to access variable debug_msg*/
#include "symtab.h"
#include "ast.h"

int MAX_INT_SIZE;


enum sizetype {
   VADD = 0, VSUB, VMUL, VDIV, VLSH, VRSH, VCOMP, /* Binary  */
   VID, VCONST, VINCR   /* Unary  */
};


enum vartype {
   VINT = 1, VFUNC, VIARR, VFARR, VFLOAT, VIPTR, VFPTR
};

/* size calculation expression blocks: 
   how to calculate the resulting size of a statement */
struct size_calc_expr_ 
{
   enum sizetype type; /* type of node: operation, identifier, or constant */

   union {
      struct { size_calc_expr e1; 
               size_calc_expr e2;
      } op;          /* store operands for unary/binary operation types */
                     /* sizetype = INCR: e2 = NULL */
                     /* sizetype = MUL, DIV, LSH, RSH, COMP, ADDSUB: e1, e2 non-NULL */ 
      var_size id;  /* sizetype = ID; pointer to variable used */
      int size;      /* sizetype = CONST; size of the constant used */ 
   } u;
};

/* size calculation statement blocks: 
   used by functions to calculate the size of variables within the function at each call */
struct size_calc_stmt_ 
{
   var_size var;  /* the variable being assigned to */
   size_calc_expr value; /* the expression to use to calculate the size being assigned */
   size_calc_stmt next; /* the next statement to evalutate */
   
};


/* Variable size list */
struct var_size_
{
   char *name; /* variable name */
   int privacy; // public = SPEC_public, private = SPEC_private; anything else unknown privacy label
   enum vartype type; // int = 1, function, int array, 
                      // float array, float, int pointer, float pointer /* these are not yet implemented */

   int current_size; // current size of the variable
   int current_max;  // current maximum size needed for the variable
   int max_size;     // maximum size possible for the variable
   
   var_size next;    // pointer to the next variable
   var_size params;  // list of parameters for functions
   size_calc_stmt body; // body of the function 

};

/* Variable table: 
   Currently just using as a list.
   Could optimize and use a hash table like the symbol table (see symtab.c/.h) */
struct var_table_ 
{
   var_size first;
   var_size last;
};

/*********************************
 *                               *
 *      SIZE COMPUTATION         *
 *                               *
 *********************************/
void ast_stmt_compute_size(aststmt t, var_table vartab);
int ast_expr_compute_size(astexpr t, var_table vartab);
void ast_stmt_labeled_compute_size(aststmt t, var_table vartab);
void ast_stmt_jump_compute_size(aststmt t, var_table vartab);
void ast_stmt_iteration_compute_size(aststmt t, var_table vartab);
void ast_stmt_selection_compute_size(aststmt t, var_table vartab);
void ast_decl_compute_size(astdecl t, astspec spec, var_table vartab);
void ast_spec_compute_size(astspec t, var_table vartab);

var_table var_size_compute(aststmt ast, var_table vartab);


/*********************************
 *                               *
 *      LOOKUP /  MODIFY         *
 *                               *
 *********************************/
/* Find the variable in the table */
var_size find_var(var_table vartab, char* name);
/* Obtain the size stored for the variable */
int get_varsize(var_table vartab, char* name);
/* Update the size stored for the variable */
int update_varsize(var_table vartab, char* name, int new_size);


/*********************************
 *                               *
 *      INITIALIZE               *
 *                               *
 *********************************/
/* Create a new variable table */
var_table new_var_table();
/* Create a new variable entry (non-function) */
var_size new_var(var_table vartab, char *name, int size, int privacy);
/* Create a new function variable entry */
var_size new_func(var_table vartab, char *name, int size, int privacy);
/* Top-level general variable entry initialization */
var_size init_var(var_table vartab, char *name, enum vartype type, int size, int privacy);


/*********************************
 *                               *
 *      FREE MEMORY              *
 *                               *
 *********************************/
/* Free the memory associated with the entire variable table */
void var_table_clear(var_table vartab);
void var_size_clear(var_size current);
extern void var_table_print(var_table vartab);







#endif

