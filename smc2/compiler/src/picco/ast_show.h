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

/* This file is modified from OMPi */

/* ast_show.h */

#ifndef __AST_SHOW_H__
#define __AST_SHOW_H__

#include "ast.h"
#include "symtab.h"
#include "ast_print.h"
#include "ast_free.h"
#include "picco.h"
#include "str.h"


enum branch_id {B_THEN = 1, B_ELSE = 2, B_NONE = 0};

extern void ast_expr_show(astexpr tree);
extern void ast_stmt_show(aststmt stmt, branchnode current);
extern void ast_decl_show(astdecl tree);
extern void ast_decl_show_priv(astdecl tree, astspec spec);
extern void ast_spec_show(astspec tree);
extern void ast_ompcon_show(ompcon tree, branchnode current);
extern void ast_ompdir_show(ompdir t);
extern void ast_ompclause_show(ompclause t);

extern void ast_show(aststmt tree, char* output_filename);
extern void ast_show_stderr(aststmt tree);
extern void ast_spec_show_stderr(astspec tree);
extern void ast_decl_show_stderr(astdecl tree);
extern void ast_expr_show_stderr(astexpr tree);

/* OMPi-extensions
 */
extern void ast_oxclause_show(oxclause t);
extern void ast_oxdir_show(oxdir tree);
extern void ast_oxcon_show(oxcon tree, branchnode current);


/* PICCO-implementation
 */

void ast_comma_expr_show(astexpr);
int ast_check_priv_if(astexpr);
void ast_priv_decl_sng_show(astdecl, astspec);
void ast_priv_decl_show(astdecl, astspec, branchnode);
void ast_priv_single_expr_show(astexpr tree);
void ast_priv_cast_helper_show(astexpr tree);
void ast_decl_memory_assign_int(astdecl, char*);
void ast_decl_memory_free_int(astdecl, char*);
void ast_decl_memory_assign_float(astdecl, char*);
void ast_decl_memory_free_float(astdecl, char*);
void ast_free_memory_for_local_variables(ltablelist);
void ast_decl_stmt_show(aststmt, branchnode);
void ast_decl_sng_stmt_show(aststmt);
void ast_if_stmt_show(aststmt, branchnode, int, enum branch_id);
void ast_priv_expr_show(astexpr, branchnode);
void ast_temporary_variable_declaration();
void ast_iter_tree(aststmt, mvarstack);
void ast_is_selection_complete(aststmt, astexpr, int*);
void ast_compute_selection_completeness(aststmt, mvarstack);
void ast_shrink_ptr(mvarstack, int, int, int);
void ast_tmp_decl_show(char*, int, int);
void ast_float_tmp_decl_show(char*, int, int);
void ast_tmp_clear_show(char*, int, int);
void ast_float_tmp_clear_show(char*, int, int);
void ast_filter_cond(astexpr, astexpr*, astexpr*);
int ast_if_start_addr_find(int);
void ast_compute_type_of_assignment_var(aststmt, int*, int*);
void ast_smc_show(char*, astexpr);
void ast_priv_assignment_show(astexpr, int);
void ast_assignment_prefix_show(astexpr);
void ast_bop_prefix_show(astexpr);
void ast_compute_condition(condnode, branchnode, int);
void ast_compute_var_size(astexpr, char*);
void ast_batch_iter_tree(aststmt, int*, int*, int*);
void ast_batch_declare_counter(aststmt, char*, int, branchnode);
void ast_batch_compute_counter(aststmt, int*, branchnode);
void ast_batch_allocate_counter();
void ast_batch_declare_array_for_narrayelement(aststmt, int*, int*, int*);
void ast_batch_allocate_array_for_narrayelement(astexpr, int, int);
void ast_batch_allocate_array_for_private_indexed_element(astexpr, int, int);
void ast_batch_free_array_for_private_indexed_element(int, int, int);
void ast_batch_compute_index(aststmt, int*, int*, int*, int*, int*);
void ast_batch_compute_stmt(aststmt, int*, int*, int*, int*, int*, branchnode);
void ast_batch_print_index(aststmt, int, int, int*, int*, int*);
void ast_batch_print_index_operator(str, astexpr, int, int*);
void ast_batch_print_cond(aststmt);
void ast_batch_print_stmt(aststmt, int, int, int*, int*, branchnode);
void ast_batch_clear_counter(int, int, int*);
void ast_batch_print_private_condition(aststmt, int*, int*, int, int, int, char*, str, str, str, str, branchnode);
void ast_handle_memory_for_private_variable(astdecl, astspec, char*, int);
void ast_clear_all_tmp_variables(branchnode);
void ast_return_struct_field_info(char*, char*, int*, int*);
void ast_declare_temp_for_struct_field(char**, int, int, int);
void ast_init_temp_for_struct_field(char**, int, int);
void ast_expr_pmalloc_show(astexpr);
int  ast_compute_expression_type(astexpr);

/*

Added private if helper functions and variables

*/

typedef struct var_node_ *var_node;

/* Tag for whether pointers modified within the private if else */
//int priv_if_ptr_mod = 0;

/* string stack/list (used with extract variables) */
struct var_node_ {
   char * name;      // variable name
   int isfloat;      // float (1); int (0)
   int isptr;        // pointer (1); non-pointer (0)
   int size;         // size of variable (needed when initializing)
   int sizeexp;      // size pt.2 for float variables
   int optimal_size;         // size of variable (needed when initializing)
   int optimal_sizeexp;      // size pt.2 for float variables
   int thread_id;    // for use with threading
   var_node next;
   var_node prev;
};

/* Create a new NULL var_list */
var_node new_var_list();

/* Helper function to find all variables that are modified within a private if else */
var_node extract_variables(aststmt, var_node, int*, int*);

/* Add a new variable to the list */
var_node var_push(var_node, char*, int, int, int, int, int, int, int);

/* Check if the given variable is already in the list */
int var_exists(var_node, char*);

/* Handle printing initialization statements for temporary vars */
void initialize_variables(var_node, branchnode);
void transactional_initialize(var_node, branchnode, int);

/* Handle printing restoration statements between branches */
void restore_variables(var_node, branchnode);

/* Handle printing resolution statements and clearing for temporary vars */
void resolve_variables(var_node, branchnode, int);

/* Print statements to free memory associated with list */
void clear_var_list(var_node, branchnode, int);

/* Free memory used by the var list */
void free_var_list(var_node var_list);

#endif
