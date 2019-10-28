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
	Matriz matriz = Matriz(2, 2, 7);
	matriz.zeros();


	int linha = sizeof(matriz.getMatriz()) / sizeof(matriz.getMatriz()[0]);
	int coluna = sizeof(matriz.getMatriz()[0]) / sizeof(matriz.getMatriz()[0][0]);

	for (int i = 0; i <= linha; i++) {
		for (int j = 0; j <= coluna; j++) {
			std::cout << matriz.getMatriz()[i][j];
		}

		std::cout << " " << endl;
	}

	return 0;
}

