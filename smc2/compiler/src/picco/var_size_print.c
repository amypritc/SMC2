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



#include "var_size_print.h"
#include "var_size.h"

FILE *vartab_file;

void var_size_print(var_size var){
   fprintf(vartab_file, "current_size, %d,\t\t current_max, %d,\t\t max_size, %d\n\n", 
                         var->current_size,    var->current_max,    var->max_size);
}


void size_calc_expr_print(size_calc_expr expr){
   fprintf(vartab_file, " (type = %d) ", expr->type);
   switch (expr->type){
   case VADD:
      /* code */
      break;

   case VSUB:
      /* code */
      break;
   
   case VMUL:
      /* code */
      break;

   case VDIV:
      /* code */
      break;

   case VLSH:
      /* code */
      break;

   case VRSH:
      /* code */
      break;
   
   case VCOMP:
      /* code */
      break;

   case VID:
      /* code */
      break;

   case VCONST:
      /* code */
      break;

   case VINCR:
      /* code */
      break;

   default:
      break;
   }
}


void size_calc_stmt_print(size_calc_stmt body){
   size_calc_stmt next = body;
   while(next){
      fprintf(vartab_file, "assign to: %s\n", next->var->name);
      size_calc_expr_print(next->value);
      next = next->next;
   }
}


void func_size_print(var_size func){
   var_size_print(func);
   fprintf(vartab_file, "PARAMETERS\n");
   var_size params = func->params;
   while(params){
      var_size_print(params);
      params = params->next;
   }
   fprintf(vartab_file, "END PARAMETERS\n");
   fprintf(vartab_file, "FUNCTION BODY\n");
   size_calc_stmt body = func->body;
   while(body){
      size_calc_stmt_print(body);
      body = body->next;
   }
   fprintf(vartab_file, "\nEND FUNCTION BODY\n");
}


void var_table_print(var_table vartab){
   if(debug_msg) printf("Entering optimal variable size - variable table printing pass\n");
   var_size next = vartab->first;
   if(!next) printf("Error: Empty variable size table\n");
   else{
      vartab_file = fopen("vartab.txt", "w+");
      while(next){
         /* Print the privacy label */
         switch (next->privacy){
         case  SPEC_private:
            fprintf(vartab_file, "PRIVATE, ");
            break;
         
         case SPEC_public: 
            fprintf(vartab_file, "PUBLIC, ");
            break;
         
         default:
            fprintf(vartab_file, "Error: Unknown privacy label\n, ");
            break;
         }

         /* Print the variable type and information */
         switch (next->type) {
         case VINT: {
            fprintf(vartab_file, "INT, %s\n", next->name);
            var_size_print(next);
            break;
         }
         case VFUNC: {
            fprintf(vartab_file, "FUNCTION, %s\n", next->name);
            func_size_print(next);
            break;
         }
         case VIARR: {
            fprintf(vartab_file, "INT ARRAY: \n");
            fprintf(vartab_file, "Error: Int arrays not yet implemented\n");
            break;
         }
         case VFARR: {
            fprintf(vartab_file, "Error: Float arrays not yet implemented\n");
            break;
         }
         case VFLOAT: {
            fprintf(vartab_file, "Error: Floats not yet implemented\n");
            break;
         }
         case VIPTR: {
            fprintf(vartab_file, "Error: Int pointers not yet implemented\n");
            break;
         }
         case VFPTR: {
            fprintf(vartab_file, "Error: Float pointers not yet implemented\n");
            break;
         }
         default:{
            fprintf(vartab_file, "Error: Unknown variable type %d\n", next->type);
            break;
         }
         }
         /* move on to the next table entry */
         next = next->next;
      }
      fclose(vartab_file);
   }
   if(debug_msg) printf("Exiting optimal variable size - variable table printing pass\n");
}









