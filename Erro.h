/*
 * Erro.h
 *
 *  Created on: Oct 31, 2019
 *      Author: thayanlima
 */

#ifndef ERRO_H_
#define ERRO_H_

using namespace std;

#include <string>
#include <iostream>
class Erro {
	std::string message;
public:
	Erro(const std::string &tp) : message(tp){cout <<message;}

	void out() {cout <<message;}
};

#endif /* ERRO_H_ */
