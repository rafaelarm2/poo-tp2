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
	Matriz *matriz = new Matriz(4,2);
	cout << *matriz;
	cout << endl << "Digite o valor da matriz: ";
	cin >> *matriz;
	cout << endl << *matriz;


	return 0;
}

