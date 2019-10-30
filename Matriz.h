/*
 * Matriz.h
 *
 *  Created on: 28 de out de 2019
 *      Author: rafaelamoreira
 */

#ifndef POO_TP2_MATRIZ_H_
#define POO_TP2_MATRIZ_H_
#include <ostream>

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

	//Write the member variables to stream objects
	friend std::ostream& operator << (std::ostream& out, const Matriz& obj);

	//Read data from stream object and fill it in member variables
	friend std::istream& operator >> (std::istream& in, Matriz& obj);

};

#endif /* POO_TP2_MATRIZ_H_ */
