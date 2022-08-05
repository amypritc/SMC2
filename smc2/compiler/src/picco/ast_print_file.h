
/*
  OMPi OpenMP Compiler
  == Copyright since 2001 the OMPi Team
  == Department of Computer Science, University of Ioannina

  This file is part of OMPi.

  OMPi is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  OMPi is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with OMPi; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

------------------------------------------------------------------------------

modified to print to file instead of a string buffer

*/

/* ast_print_file.h -- a non-reentrant way to print the AST to a file */

#ifndef __AST_PRINT_FILE_H__
#define __AST_PRINT_FILE_H__

#include "ast.h"
#include "str.h"

extern void ast_expr_print_file(astexpr tree);
extern void ast_stmt_print_file(aststmt stmt);
extern void ast_decl_print_file(astdecl tree);
extern void ast_spec_print_file(astspec tree);
extern void ast_ompdir_print_file(ompdir tree);
extern void ast_ompcon_print_file(ompcon tree);

/* OMPi-extensions
 */
extern void ast_oxdir_print_file(oxdir tree);
extern void ast_oxcon_print_file(oxcon tree);

#endif

