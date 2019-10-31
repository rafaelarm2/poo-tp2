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
	this->linhas = 0;
	this->colunas = 0;
	matriz = (double **) malloc(0 * sizeof(double *));
	matriz[0] = (double *) malloc(0 * sizeof(double));
}

Matriz::~Matriz() {
	// TODO Auto-generated destructor stub
}

Matriz::Matriz(int linhas, int colunas, const double &valor) {
	this->linhas = linhas;
	this->colunas = colunas;
	if (linhas != 0  && colunas != 0) {
		matriz = (double **) malloc(linhas * sizeof(double *));
		for (int i = 0; i < linhas; i++) {
			matriz[i] = (double *) malloc(colunas * sizeof(double));
		}

		for (int i = 0; i < linhas; i++) {
			for (int j = 0; j < colunas; j++) {
				matriz[i][j] = valor;
			}
		}
	} else {
		matriz = (double **) malloc(0 * sizeof(double *));
		matriz[0] = (double *) malloc(0 * sizeof(double));
	}

}

double ** Matriz::getMatriz() const{
	return matriz;
}

int Matriz::getRows() const {
	return this->linhas;

}

int Matriz::getCols() const {
	return this->colunas;
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
	if(this->getCols() == m.getRows()) {
		for (int i = 0; i < this->getRows(); i++) {
			for (int j = 0; j < m.getCols(); j++) {
				c(i+1,j+1) = 0;
				for (int k = 0; k < this->getRows(); k++) {
					c(i+1,j+1) += this->getMatriz()[i][k] * m.getMatriz()[k][j];
				}
			}
		}
	} else {

		cout << "Nao e possivel multiplicar matrizes cujo numero de colunas da primeira e diferente do numero de linhas da segunda." << endl;
	}

	return c;

}

double& Matriz::operator()(const int i, const int j) const {
	return this->getMatriz()[i - 1][j - 1];
}

std::ostream& operator<< (std::ostream& out, const Matriz& obj)
{
	for(int i = 0; i < obj.linhas; i++){
		for(int j = 0; j < obj.colunas; j++){
			out << obj.matriz[i][j] << " ";
		}
		out << endl;
	}
	return out;
}

std::istream& operator>>(std::istream& in, Matriz& obj){
	for(int i = 0; i < obj.linhas; i++){
		for(int j = 0; j < obj.colunas; j++){
			in >> obj.matriz[i][j];
		}
	}
	return in;
}
