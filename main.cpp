/*
 * main.cpp
 *
 *  Created on: 28 de out de 2019
 *      Author: rafaelamoreira
 */

#include "Matriz.h"

#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char **argv, char **envp) {
//	Matriz *matriz = new Matriz(4,2);
//	cout << *matriz;
//	cout << endl << "Digite o valor da matriz: ";
//	cin >> *matriz;
//	cout << endl << *matriz;
//	cout << endl << (*matriz)(1, 1) << endl;
//	cout << matriz->getCols() << " " << matriz->getRows() << endl;


	Matriz matriz(3,3,2);
	Matriz matriz1(3,3,1);
	Matriz matriz2;
	matriz2 = matriz * matriz1;
	for (int i = 0; i < matriz.getRows(); i++) {
		for (int j = 0; j < matriz.getCols(); j++) {
			cout << matriz2.getMatriz()[i][j] << " ";
		}
		cout << " " << endl;
	}

	return 0;
}

