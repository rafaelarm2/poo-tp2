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
	return (sizeof(matriz) / sizeof(matriz[0])) + 1;

}

int Matriz::getCols() {
	return (sizeof(matriz[0]) / sizeof(matriz[0][0])) + 1;
}

void Matriz::zeros() {
	for (int i = 0; i < getCols(); i++) {
		for (int j = 0; j < getRows(); j++) {
			matriz[i][j] = 0;
		}
	}
}

