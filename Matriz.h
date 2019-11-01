/*
 * Matriz.h
 *
 *  Created on: 28 de out de 2019
 *      Author: rafaelamoreira
 */
#include <ostream>

#ifndef POO_TP2_MATRIZ_H_
#define POO_TP2_MATRIZ_H_

class Matriz {
private:
	int linhas;
	int colunas;
	double **matriz;

public:
	Matriz();
	Matriz(int linhas, int colunas, const double &valor = 0);
	virtual ~Matriz();
	Matriz(const Matriz &m);

	double **  getMatriz() const;
	int getRows() const;
	int getCols() const;
	void zeros();

	Matriz operator*(Matriz& m);
	double& operator()(const int i, const int j) const;

	//Write the member variables to stream objects
	friend std::ostream& operator << (std::ostream& out, const Matriz& obj);

	//Read data from stream object and fill it in member variables
	friend std::istream& operator >> (std::istream& in, Matriz& obj);

	Matriz * operator+=(const Matriz& m);
	Matriz * operator-=(const Matriz& m);
	bool operator==(const Matriz& m) const;
	bool operator!=(const Matriz& m) const;

    Matriz operator+(const Matriz& m) const;
    Matriz operator-(const Matriz& m) const;

};

#endif /* POO_TP2_MATRIZ_H_ */



