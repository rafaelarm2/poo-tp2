/*
 * Matriz.cpp
 *
 *  Created on: 28 de out de 2019
 *      Author: rafaelamoreira
 */

#include "Matriz.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

Matriz::Matriz() {
	matriz = (double **) malloc(0 * sizeof(double *));
	matriz[0] = (double *) malloc(0 * sizeof(double));
}

Matriz::~Matriz() {
	// TODO Auto-generated destructor stub
}

Matriz::Matriz(int linhas, int colunas, const double &valor) {
	matriz = (double **) malloc(linhas * sizeof(double *));
	for (int i = 0; i < linhas; i++) {
		matriz[i] = (double *) malloc(colunas * sizeof(double));
	}

	for (int i = 0; i < linhas; i++) {
		for (int j = 0; j < colunas; j++) {
			matriz[i][j] = valor;
		}
	}

}

double ** Matriz::getMatriz() {
	return matriz;
}

int Matriz::getRows() {
	int rows = (int)((sizeof(matriz) / sizeof(matriz[0])) + 1);
	return rows;

}

int Matriz::getCols() {
	int cols = (int)((sizeof(matriz[0]) / sizeof(matriz[0][0])) + 1);
	return cols;
}

void Matriz::zeros() {
	for (int i = 0; i < getCols(); i++) {
		for (int j = 0; j < getRows(); j++) {
			matriz[i][j] = 0;
		}
	}
}

Matriz Matriz::operator*(Matriz& m) {

	Matriz c = Matriz(this->getRows(), m.getCols(), 0);

	for (int i = 0; i < this->getRows(); i++) {
		for (int j = 0; j < m.getCols(); j++) {
			c(i,j) = 0;
			for (int k = 0; k < this->getCols(); k++) {
				c(i,j) += this->getMatriz()[i][k] * m.getMatriz()[k][j];
			}
	    }
	}

	return c;
}

double& Matriz::operator()(const int i, const int j) {
	return this->getMatriz()[i][j];

}

