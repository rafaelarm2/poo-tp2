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

	(matriz)(0,0) = 10;

	Matriz matriz2 = Matriz(2, 2, 2);

	Matriz matriz3;
	matriz3 = (matriz) * (matriz2);

	for (int i = 0; i <= 1; i++) {
		for (int j = 0; j <= 1; j++) {
			std::cout << matriz3.getMatriz()[i][j] << " ";
		}

		std::cout << " " << endl;
	}


	return 0;
}

