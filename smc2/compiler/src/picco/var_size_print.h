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



#ifndef __VAR_SIZE_PRINT_H__
#define __VAR_SIZE_PRINT_H__



#include "var_size.h"
#include "picco.h"

extern void var_table_print(var_table vartab);

void var_size_print(var_size var);

void size_calc_expr_print(size_calc_expr expr);
void size_calc_stmt_print(size_calc_stmt body);

void func_size_print(var_size func);












#endif

