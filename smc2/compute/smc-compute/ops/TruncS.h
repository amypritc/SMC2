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

#ifndef TRUNCS_H_
#define TRUNCS_H_

#include "Random.h"
#include "LTZ.h"
#include "Mult.h"
#include "B2U.h"
#include "PrefixMultiplication.h"
#include "Inv.h"
#include "Operation.h"

class TruncS: public Operation {
public:
	TruncS(NodeNetwork nodeNet, std::map<std::string, std::vector<int> > poly, int nodeID, SecretShare* s, mpz_t coeficients[]);
	virtual ~TruncS();
	void doOperation(mpz_t* result, mpz_t* A, int K, mpz_t* M, int size, int threadID);
private:
	LTZ *Lt;
	Mult *Mul;
	B2U *Bt;
	PrefixMultiplication *Pre;
	Inv *In;
    	Random* Rand;
};

#endif /* TRUNCS_H_ */
