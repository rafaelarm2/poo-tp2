/*
 * Matriz.h
 *
 *  Created on: 28 de out de 2019
 *      Author: rafaelamoreira
 */

#ifndef POO_TP2_MATRIZ_H_
#define POO_TP2_MATRIZ_H_

class Matriz {
private:

public:
	Matriz();
	Matriz(int linhas, int colunas, const double &valor = 0);
	virtual ~Matriz();
	Matriz(const Matriz &m);
};

#endif /* POO_TP2_MATRIZ_H_ */
