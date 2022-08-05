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


/* ast_print_file.c -- a non-reentrant way to print the AST to a file */

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "symtab.h"
#include "ast_print_file.h"

FILE *ast_file;

static void ast_expr_prn(astexpr tree);
static void ast_stmt_prn(aststmt stmt);
static void ast_decl_prn(astdecl tree);
static void ast_spec_prn(astspec tree);
static void ast_ompdir_prn(ompdir tree);
static void ast_ompcon_prn(ompcon tree);
static void ast_ompclause_prn(ompclause t);
static void ast_oxcon_prn(oxcon t);

static int indlev;

static
void indent(){
  int i;
  if (indlev > 0)
    for (i = 2*indlev; i > 0; i--)
      fprintf(ast_file, " ");
}


static void ast_stmt_jump_prn(aststmt tree){
   switch (tree->subtype){
       case SBREAK:
            fprintf(ast_file, "break;\n");
            break;
       case SCONTINUE:
            fprintf(ast_file, "continue;\n");
            break;
       case SRETURN:
            fprintf(ast_file, "return");
            if (tree->u.expr != NULL){
                 fprintf(ast_file, " (");
                 ast_expr_prn(tree->u.expr);
                 fprintf(ast_file, ")");
            }
            fprintf(ast_file, ";\n");
            break;
       case SGOTO:
            fprintf(ast_file, "goto %s;\n", tree->u.label->name);
            break;
       default:
            fprintf(stderr, "[ast_stmt_jump_prn]: b u g !!\n");
   }
}


static void ast_stmt_iteration_prn(aststmt tree){
  switch (tree->subtype){
    case SFOR:
      fprintf(ast_file, "for (");
      if (tree->u.iteration.init != NULL)
         ast_stmt_prn(tree->u.iteration.init);
      else
         fprintf(ast_file, " ; ");
      if (tree->u.iteration.cond != NULL)
         ast_expr_prn(tree->u.iteration.cond);
      fprintf(ast_file, "; ");
      if (tree->u.iteration.incr != NULL)
         ast_expr_prn(tree->u.iteration.incr);
      fprintf(ast_file, ")\n");
      indlev++; indent();
      ast_stmt_prn(tree->body);
      indlev--;
      break;
    case SWHILE:
      fprintf(ast_file, "while (");
      ast_expr_prn(tree->u.iteration.cond);
      fprintf(ast_file, ")\n");
      indlev++; indent();
      ast_stmt_prn(tree->body);
      indlev--;
      break;
    case SDO:
      fprintf(ast_file, "do\n");
      indlev++; indent();
      ast_stmt_prn(tree->body);
      indlev--; indent();
      fprintf(ast_file, "while (");
      ast_expr_prn(tree->u.iteration.cond);
      fprintf(ast_file, ");\n");
      break;
    default:
      fprintf(stderr, "[ast_stmt_iteration_prn]: b u g !!\n");
  }
}


static void ast_stmt_selection_prn(aststmt tree){
   switch (tree->subtype){
      case SSWITCH:
         fprintf(ast_file, "switch (");
         ast_expr_prn(tree->u.selection.cond);
         fprintf(ast_file, ")\n");
         indent();
         ast_stmt_prn(tree->body);
         fprintf(ast_file, "\n");
         break;
      case SIF:
         fprintf(ast_file, "if (");
         ast_expr_prn(tree->u.selection.cond);
         fprintf(ast_file, ") { \n");
         indlev++; indent();
         ast_stmt_prn(tree->body);
         indlev--;
         fprintf(ast_file, "}\n");
         if (tree->u.selection.elsebody){
              indent();
              fprintf(ast_file, "else {\n");
              indlev++; indent();
              ast_stmt_prn(tree->u.selection.elsebody);
              fprintf(ast_file, "}\n");
              indlev--;
         }
         break;
      default:
         fprintf(stderr, "[ast_stmt_selection_prn]: b u g !!\n");
   }
}


static void ast_stmt_labeled_prn(aststmt tree){
   switch (tree->subtype){
      case SLABEL:
         fprintf(ast_file, "%s :\n", tree->u.label->name);
         break;
      case SCASE:
         fprintf(ast_file, "case ");
         ast_expr_prn(tree->u.expr);
         fprintf(ast_file, " :\n");
         break;
      case SDEFAULT:
         fprintf(ast_file, "default :\n");
         break;
      default:
         fprintf(stderr, "[ast_stmt_labeled_prn]: b u g !!\n");
   }
   indlev++; indent();
   ast_stmt_prn(tree->body);
   indlev--;
}


static void ast_stmt_prn(aststmt tree){
  switch (tree->type){
    case JUMP:
      ast_stmt_jump_prn(tree);
      break;
    case ITERATION:
      ast_stmt_iteration_prn(tree);
      break;
    case SELECTION:
      ast_stmt_selection_prn(tree);
      break;
    case LABELED:
      ast_stmt_labeled_prn(tree);
      break;
    case EXPRESSION:
      if (tree->u.expr != NULL)
        ast_expr_prn(tree->u.expr);
      fprintf(ast_file, ";\n");
      break;
    case COMPOUND:
      fprintf(ast_file, "{\n");
      if (tree->body){
        indlev++; indent();
        ast_stmt_prn(tree->body);
        indlev--;
      }
      indent();
      fprintf(ast_file, "}\n");
      break;
    case STATEMENTLIST:
      ast_stmt_prn(tree->u.next);
      indent();
      ast_stmt_prn(tree->body);
      break;
    case DECLARATION:
      ast_spec_prn(tree->u.declaration.spec);
      if (tree->u.declaration.decl){
           fprintf(ast_file, " ");
           ast_decl_prn(tree->u.declaration.decl);
      }
      fprintf(ast_file, ";\n");
      break;
    case FUNCDEF:
      fprintf(ast_file, "\n/* Function definition: */\n");
      indent();
      if (tree->u.declaration.spec){
           ast_spec_prn(tree->u.declaration.spec);
           fprintf(ast_file, " ");
      }
      ast_decl_prn(tree->u.declaration.decl);
      fprintf(ast_file, "\n");
      if (tree->u.declaration.dlist){
           indlev++; indent();
           ast_stmt_prn(tree->u.declaration.dlist);
           indlev--;
      }
      indent();
      ast_stmt_prn(tree->body);
      fprintf(ast_file, "\n");
      break;
    case OMPSTMT:
      ast_ompcon_prn(tree->u.omp);
      fprintf(ast_file, "\n");
      break;
    case VERBATIM:
      fprintf(ast_file, "%s\n", tree->u.code);
      break;
    case OX_STMT:
      ast_oxcon_prn(tree->u.ox);
      fprintf(ast_file, "\n");
      break;
    default:
      fprintf(stderr, "[ast_print_file.c][ast_stmt_prn]: b u g !!\n\t %d\n", tree->type);
    }
}


static void ast_expr_prn(astexpr tree){
   fprintf(ast_file, "%d", tree->size);
  switch (tree->type){
    case IDENT:
      fprintf(ast_file, "%s", tree->u.sym->name);
      break;
    case CONSTVAL:
      fprintf(ast_file, "%s", tree->u.str);
      break;
    case STRING:
      fprintf(ast_file, "%s", tree->u.str);
      break;
    case FUNCCALL:
      ast_expr_prn(tree->left);
      fprintf(ast_file, "(");
      if (tree->right)
        ast_expr_prn(tree->right);
      fprintf(ast_file, ")");
      break;
    case ARRAYIDX:
      ast_expr_prn(tree->left);
      fprintf(ast_file, "[");
      ast_expr_prn(tree->right);
      fprintf(ast_file, "]");
      break;
    case DOTFIELD:
      ast_expr_prn(tree->left);
      fprintf(ast_file, ".%s", tree->u.sym->name);
      break;
    case PTRFIELD:
      ast_expr_prn(tree->left);
      fprintf(ast_file, "->%s", tree->u.sym->name);
      break;
    case BRACEDINIT:
      fprintf(ast_file, "{ ");
      ast_expr_prn(tree->left);
      fprintf(ast_file, " }");
      break;
    case CASTEXPR:
      fprintf(ast_file, "(");
      ast_decl_prn(tree->u.dtype);
      fprintf(ast_file, ") ");
      ast_expr_prn(tree->left);
      break;
    case CONDEXPR:
      ast_expr_prn(tree->u.cond);
      fprintf(ast_file, " ? ");
      ast_expr_prn(tree->left);
      fprintf(ast_file, " : ");
      ast_expr_prn(tree->right);
      break;
    case UOP:
      fprintf(ast_file, "%s", UOP_symbols[tree->opid]);
      if (tree->opid == UOP_sizeoftype || tree->opid == UOP_sizeof)
        fprintf(ast_file, "(");
      if (tree->opid == UOP_sizeoftype || tree->opid == UOP_typetrick)
        ast_decl_prn(tree->u.dtype);
      else
        ast_expr_prn(tree->left);
      if (tree->opid == UOP_paren || tree->opid == UOP_sizeoftype
                                  || tree->opid == UOP_sizeof)
        fprintf(ast_file, ")");
      break;
    case BOP:
      ast_expr_prn(tree->left);
      fprintf(ast_file, " %s ", BOP_symbols[tree->opid]);
      ast_expr_prn(tree->right);
      break;
    case PREOP:
      fprintf(ast_file, "%s", UOP_symbols[tree->opid]);
      ast_expr_prn(tree->left);
      break;
    case POSTOP:
      ast_expr_prn(tree->left);
      fprintf(ast_file, "%s", UOP_symbols[tree->opid]);
      break;
    case ASS:
      ast_expr_prn(tree->left);
      fprintf(ast_file, " %s ", ASS_symbols[tree->opid]);
      ast_expr_prn(tree->right);
      break;
    case DESIGNATED:
      ast_expr_prn(tree->left);
      fprintf(ast_file, " = ");
      ast_expr_prn(tree->right);
      break;
    case IDXDES:
      fprintf(ast_file, "[");
      ast_expr_prn(tree->left);
      fprintf(ast_file, "]");
      break;
    case DOTDES:
      fprintf(ast_file, ".%s", tree->u.sym->name);
      break;
    case COMMALIST:
    case SPACELIST:
      ast_expr_prn(tree->left);
      fprintf(ast_file, "%s", tree->type == COMMALIST ? ", " : " ");
      ast_expr_prn(tree->right);
      break;
    default:
      fprintf(stderr, "[ast_expr_prn]: b u g !!\n");
  }
}


static void ast_spec_prn(astspec tree){
fprintf(ast_file, "%d", tree->size);
  switch (tree->type){
    case SPEC:
    case STCLASSSPEC:
      fprintf(ast_file, "%s", SPEC_symbols[tree->subtype]);
      break;
    case USERTYPE:
      fprintf(ast_file, "%s", tree->name->name);
      break;
    case SUE:
      switch (tree->subtype){
        case SPEC_enum:
          fprintf(ast_file, "enum");
          if (tree->name)
               fprintf(ast_file, " %s ", tree->name->name);
          if (tree->body){
               fprintf(ast_file, " {\n");
               indlev +=2 ; indent();
               ast_spec_prn(tree->body);
               fprintf(ast_file, "\n");
               indlev--; indent(); indlev--;
               fprintf(ast_file, "}");
          }
          break;
        case SPEC_struct:
        case SPEC_union:
          fprintf(ast_file, "%s", tree->subtype == SPEC_struct ? "struct":"union");
          if (tree->name)
            fprintf(ast_file, " %s ", tree->name->name);
          if (tree->u.decl){
            fprintf(ast_file, " {\n");
            indlev += 2; indent();
            ast_decl_prn(tree->u.decl);
            fprintf(ast_file, "\n");
            indlev--; indent(); indlev--;
            fprintf(ast_file, "}");
          }
          break;
        default:
          fprintf(stderr, "[ast_spec_prn]: SUE b u g !!\n");
      }
      break;
    case ENUMERATOR:
      fprintf(ast_file, "%s", tree->name->name);
      if (tree->u.expr){
        fprintf(ast_file, " = ");
        ast_expr_prn(tree->u.expr);
      }
      break;
    case SPECLIST:
      switch (tree->subtype){
        case SPEC_Rlist:
          ast_spec_prn(tree->body);
          if (tree->body->type != SPEC || tree->body->subtype != SPEC_star)
               fprintf(ast_file, " ");   /* No spaces among consecutive stars */
          ast_spec_prn(tree->u.next);
          break;
        case SPEC_Llist:
          ast_spec_prn(tree->u.next);
          fprintf(ast_file, " ");
          ast_spec_prn(tree->body);
          break;
        case SPEC_enum:
          ast_spec_prn(tree->u.next);
          fprintf(ast_file, ", ");
          ast_spec_prn(tree->body);
          break;
        default:
          fprintf(stderr, "[ast_spec_prn]: list b u g !!\n");
      }
      break;
    default:
      fprintf(stderr, "[ast_spec_prn]: b u g !!\n");
  }
  fflush(stdout);
}


static void ast_decl_prn(astdecl tree){
  switch (tree->type){
    case DIDENT:
      fprintf(ast_file, "%s", tree->u.id->name);
      break;
    case DPAREN:
      fprintf(ast_file, "(");
      ast_decl_prn(tree->decl);
      fprintf(ast_file, ") ");
      break;
    case DARRAY:
      if (tree->decl)
         ast_decl_prn(tree->decl);
      fprintf(ast_file, "[");
      if (tree->spec)
         ast_spec_prn(tree->spec);
      if (tree->u.expr){
         fprintf(ast_file, " ");
         ast_expr_prn(tree->u.expr);
      }
      fprintf(ast_file, "]");
      break;
    case DFUNC:
      if (tree->decl)
         ast_decl_prn(tree->decl);
      fprintf(ast_file, "(");
      if (tree->u.params)
         ast_decl_prn(tree->u.params);
      fprintf(ast_file, ")");
      break;
    case DINIT:
      ast_decl_prn(tree->decl);
      if (tree->u.expr != NULL){
         fprintf(ast_file, " = ");
         ast_expr_prn(tree->u.expr);
      }
      break;
    case DECLARATOR:
      if (tree->spec){      /* pointer */
         ast_spec_prn(tree->spec);
         fprintf(ast_file, " ");
      }
      ast_decl_prn(tree->decl);
      break;
    case ABSDECLARATOR:
      if (tree->spec)      /* pointer */
         ast_spec_prn(tree->spec);
      if (tree->decl){      /* could be NULL */
         fprintf(ast_file, " ");
         ast_decl_prn(tree->decl);
      }
      break;
    case DPARAM:
      ast_spec_prn(tree->spec);
      if (tree->decl){
         fprintf(ast_file, " ");
         ast_decl_prn(tree->decl);
      }
      break;
    case DELLIPSIS:
      fprintf(ast_file, "...");
      break;
    case DBIT:
      if (tree->decl)
        ast_decl_prn(tree->decl);
      fprintf(ast_file, " : ");
      ast_expr_prn(tree->u.expr);
      break;
    case DSTRUCTFIELD:
      if (tree->spec){      /* pointer */
         ast_spec_prn(tree->spec);
         fprintf(ast_file, " ");
      }
      if (tree->decl)
         ast_decl_prn(tree->decl);
      fprintf(ast_file, ";\n");
      break;
    case DCASTTYPE:
      ast_spec_prn(tree->spec);
      if (tree->decl){
         fprintf(ast_file, " ");
         ast_decl_prn(tree->decl);
      }
      break;
    case DLIST:
      switch (tree->subtype){
        case DECL_decllist:
        case DECL_idlist:
        case DECL_paramlist:
          ast_decl_prn(tree->u.next);
          fprintf(ast_file, ", ");
          ast_decl_prn(tree->decl);
          break;
        case DECL_fieldlist:
          ast_decl_prn(tree->u.next);
          fprintf(ast_file, "\n"); indent();
          ast_decl_prn(tree->decl);
          break;
        default:
          fprintf(stderr, "[ast_decl_prn]: dlist b u g !!\n");
      }
      break;
    default:
      fprintf(stderr, "[ast_decl_prn]: b u g !!\n");
  }
  fflush(stdout);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                               *
 *     OpenMP NODES                                              *
 *                                                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

static void ast_ompclause_prn(ompclause t){
    if (t->type == OCLIST){
        if (t->u.list.next != NULL){
            ast_ompclause_prn(t->u.list.next);
            fprintf(ast_file, " ");
        }
        assert((t = t->u.list.elem) != NULL);
    }
    fprintf(ast_file, "%s", clausenames[t->type]);
    switch (t->type){
        case OCIF:
        case OCFINAL:
        case OCNUMTHREADS:
            fprintf(ast_file, "("); ast_expr_prn(t->u.expr); fprintf(ast_file, ")");
            break;
        case OCSCHEDULE:
            fprintf(ast_file, "(%s%s", clausesubs[t->subtype], t->u.expr ? ", " : " ");
            if (t->u.expr)
                ast_expr_prn(t->u.expr);
            fprintf(ast_file, ")");
            break;
        case OCDEFAULT:
            fprintf(ast_file, "(%s)", clausesubs[t->subtype]);
            break;
        case OCREDUCTION:
            fprintf(ast_file, "(%s : ", clausesubs[t->subtype]);
            ast_decl_prn(t->u.varlist);
            fprintf(ast_file, ")");
            break;
        case OCCOPYIN:
        case OCPRIVATE:
        case OCCOPYPRIVATE:
        case OCFIRSTPRIVATE:
        case OCLASTPRIVATE:
        case OCSHARED:
            fprintf(ast_file, "("); ast_decl_prn(t->u.varlist); fprintf(ast_file, ")");
            break;
        case OCNOWAIT:
        case OCORDERED:
        case OCUNTIED:
        case OCMERGEABLE:
            break;
        case OCCOLLAPSE:
            fprintf(ast_file, "(%d)", t->subtype);
            break;
    }
}


static void ast_ompdir_prn(ompdir t){
    fprintf(ast_file, "#pragma omp %s ", ompdirnames[t->type]);
    switch (t->type){
        case DCCRITICAL:
            if (t->u.region)
                fprintf(ast_file, "(%s)", t->u.region->name);
            break;
        case DCFLUSH:
            if (t->u.varlist){
                fprintf(ast_file, "(");
                ast_decl_prn(t->u.varlist);
                fprintf(ast_file, ")");
            }
            break;
        case DCTHREADPRIVATE:
            if (t->u.varlist){
                fprintf(ast_file, "(");
                ast_decl_prn(t->u.varlist);
                fprintf(ast_file, ")");
            }
            break;
        default:
            if (t->clauses)
                ast_ompclause_prn(t->clauses);
            break;
    }
}


static void ast_ompcon_prn(ompcon t){
    ast_ompdir_prn(t->directive);
    if (t->body)     /* barrier & flush don't have a body */
        ast_stmt_prn(t->body);
}

void ast_expr_print_file(astexpr tree){
   ast_file = fopen("ast.txt", "w+");
   ast_expr_prn(tree);
   fclose(ast_file);
}


void ast_stmt_print_file(aststmt tree){
   ast_file = fopen("ast.txt", "w+");
   ast_stmt_prn(tree);
   fclose(ast_file);
}


void ast_decl_print_file(astdecl tree){
   ast_file = fopen("ast.txt", "w+");
   ast_decl_prn(tree);
   fclose(ast_file);
}


void ast_spec_print_file(astspec tree){
   ast_file = fopen("ast.txt", "w+");
   ast_spec_prn(tree);
   fclose(ast_file);
}

void ast_ompdir_print_file(ompdir tree){
    ast_file = fopen("ast.txt", "w+");
    ast_ompdir_prn(tree);
    fclose(ast_file);
}

void ast_ompcon_print_file(ompcon tree){
    ast_file = fopen("ast.txt", "w+");
    ast_ompcon_prn(tree);
    fclose(ast_file);
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                               *
 *     OMPi-EXTENSION NODES                                      *
 *                                                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

static
void ast_oxclause_prn(oxclause t){
    if (t->type == OX_OCLIST){
        if (t->u.list.next != NULL){
            ast_oxclause_prn(t->u.list.next);
            fprintf(ast_file, " ");
        }
        assert((t = t->u.list.elem) != NULL);
    }
    
    fprintf(ast_file, "%s", oxclausenames[t->type]);
    switch (t->type){
        case OX_OCREDUCE:
            fprintf(ast_file, "(%s : ", clausesubs[t->operator]);
            ast_decl_prn(t->u.varlist);
            fprintf(ast_file, ")");
            break;
        case OX_OCIN:
        case OX_OCOUT:
        case OX_OCINOUT:
            fprintf(ast_file, "("); ast_decl_prn(t->u.varlist); fprintf(ast_file, ")");
            break;
        case OX_OCATNODE:
        case OX_OCATWORKER:
        case OX_OCSTART:
        case OX_OCSTRIDE:
            fprintf(ast_file, "("); ast_expr_prn(t->u.expr); fprintf(ast_file, ")");
            break;
        case OX_OCSCOPE:
            fprintf(ast_file, "scope(%s)", t->u.value == OX_SCOPE_NODES ? "nodes" :
                       t->u.value == OX_SCOPE_WLOCAL ? "workers,local" :
                       t->u.value == OX_SCOPE_WGLOBAL ? "workers,global" :
                       "???");
            break;
    }
}


static
void ast_oxdir_prn(oxdir t){
    fprintf(ast_file, "#pragma ompix %s ", oxdirnames[t->type]);
    if (t->clauses)
        ast_oxclause_prn(t->clauses);
}


static
void ast_oxcon_prn(oxcon t){
    ast_oxdir_prn(t->directive);
    if (t->body)
        ast_stmt_prn(t->body);
}


void ast_oxdir_print_file(oxdir tree){
    ast_file = fopen("ast.txt", "w+");
    ast_oxdir_prn(tree);
    fclose(ast_file);
}

void ast_oxcon_print_file(oxcon tree){
    ast_file = fopen("ast.txt", "w+");
    ast_oxcon_prn(tree);
    fclose(ast_file);
}







