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
	int linhas;
	int colunas;
	double **matriz;

public:
	Matriz();
	Matriz(int linhas, int colunas, const double &valor);
	virtual ~Matriz();
	Matriz(const Matriz &m);

	double **  getMatriz();
	int getRows();
	int getCols();
	void zeros();

	Matriz operator*(Matriz& m);
	double& operator()(const int i, const int j) ;

};

#endif /* POO_TP2_MATRIZ_H_ */
