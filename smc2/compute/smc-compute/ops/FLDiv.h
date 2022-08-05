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
#ifndef FLDIV_H_
#define FLDIV_H_

#include "Operation.h"
#include "Mult.h"
#include "Trunc.h"
#include "TruncPr.h"
#include "LTZ.h"
#include "SDiv.h"

class FLDiv: public Operation{
public:
	FLDiv(NodeNetwork nodeNet, std::map<std::string, std::vector<int> > poly, int nodeID, SecretShare* s, mpz_t coeficients[]);
	virtual ~FLDiv();
	void doOperation(mpz_t** A, mpz_t** B, mpz_t** result, int K, int size, int threadID);
	void doOperationPub(mpz_t** A, mpz_t** B, mpz_t** result, int K, int size, int threadID); 
private:
	Mult *Mul;
	Trunc *T;
	LTZ *Lt;
	SDiv *Sdiv; 
};

#endif /* FLDIV_H_ */
