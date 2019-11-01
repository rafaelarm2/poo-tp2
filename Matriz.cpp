/*
 * Matriz.cpp
 *
 *  Created on: 28 de out de 2019
 *      Author: rafaelamoreira
 */

#include "Matriz.h"
#include "Erro.h"
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
		Erro e("Nao e possivel multiplicar matrizes que possuem linhas e colunas diferentes.");
		cout << "" << endl;
		throw e;
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

Matriz * Matriz::operator+=(const Matriz& m) {
	if(m.getRows() == this->getRows() && m.getCols() == this->getCols()) {
		for(int i = 0; i < m.linhas; i++){
			for(int j = 0; j < m.colunas; j++){
				this->matriz[i][j] += m.getMatriz()[i][j];
			}
		}
	} else {
		Erro e("Nao e possivel somar matrizes que possuem linhas e colunas diferentes.");
		e.out();
		throw e;
	}

	return this;
}


Matriz * Matriz::operator-=(const Matriz& m) {
	if(m.getRows() == this->getRows() && m.getCols() == this->getCols()) {
		for(int i = 0; i < m.linhas; i++){
			for(int j = 0; j < m.colunas; j++){
				this->matriz[i][j] -= m.getMatriz()[i][j];
			}
		}
	} else {
		Erro e("Nao e possivel subtrair matrizes que possuem linhas e colunas diferentes.");
		cout << "" << endl;
		throw e;
	}
	return this;
}

bool Matriz::operator==(const Matriz& m) const {
	bool equal = true;
	if (m.getRows() == this->getRows() && m.getCols() == this->getCols()) {
		for (int i = 0; i < m.linhas; i++) {
			for (int j = 0; j < m.colunas; j++) {
				if (this->matriz[i][j] != m.getMatriz()[i][j]) {
					equal = false;
					return equal;
				}
			}
		}
	} else {
		Erro e("Nao e possivel comparar matrizes que possuem linhas e colunas diferentes.");
		cout << "" << endl;
		throw e;
	}

	return equal;
}

bool Matriz::operator!=(const Matriz& m) const {
	bool equal = false;
	if (m.getRows() == this->getRows() && m.getCols() == this->getCols()) {
		for (int i = 0; i < m.linhas; i++) {
			for (int j = 0; j < m.colunas; j++) {
				if (this->matriz[i][j] != m.getMatriz()[i][j]) {
					equal = true;
					return equal;
				}
			}
		}
	} else {
		Erro e("Nao e possivel comparar matrizes que possuem linhas e colunas diferentes.");
		cout << "" << endl;
		throw e;
	}

	return equal;
}

Matriz Matriz::operator+(Matriz& m){
    Matriz aux = Matriz(m.getRows(), m.getCols(), 0);
    if ((this->getRows() == m.getRows())&&(this->getCols() == m.getCols())) {
        for (int i = 0; i < aux.getRows(); i++)
        {
            for (int j = 0; j < aux.getCols(); j++)
            {
                aux(i+1,j+1) = m.getMatriz()[i][j] + this->getMatriz()[i][j];
            }
        }
    }
    else {
        Erro e("Nao e possivel somar matrizes de diferentes dimensoes");
        cout << "" << endl;
        throw e;
    }
    return aux;
}

Matriz Matriz::operator-(Matriz& m){
    Matriz aux = Matriz(m.getRows(), m.getCols(), 0);
    if ((this->getRows() == m.getRows())&&(this->getCols() == m.getCols())) {
        for (int i = 0; i < aux.getRows(); i++)
        {
            for (int j = 0; j < aux.getCols(); j++)
            {
                aux(i+1,j+1) = (this->getMatriz()[i][j] - m.getMatriz()[i][j]);
            }
        }
    }
    else {
        Erro e("Nao e possivel subtrair matrizes de diferentes dimensoes");
        cout << "" << endl;
        throw e;
    }
    return aux;
}
