#include <iostream>
#include <fstream>
#include "Repository.h"
#include <string.h>
#include <vector>
using namespace std;

ContRepo::ContRepo() {
	/*
		desc: creeaza repo
		out: o instanta de tipul repo
	*/
	this->conturibancare = {};
}



ContRepo::~ContRepo()
{
	/*
		desc:distruge ContRepo
		in: ContRepo
		out: -
	*/
	if (this->conturibancare.size() != 0)
		this->conturibancare.clear();

}

void ContRepo::addelem(ContBancar c) {
	/*
		desc: adauga un element intr-o lista
		in: un cont bancar -c
		out: lista cu noul element adaugat
	*/
	conturibancare.push_back(c);
}
vector <ContBancar> ContRepo::getAll() {
	/*
		desc: ia toate elementele din repo
		in: lista de conturi bancare
		out: lista cu toate conturile bancare
	*/
	return conturibancare;
}

void ContRepo::deleteElem(int pozitie)
{
	/*
		desc : sterge un element din lista
		in : pozitia de la care trebuie sters elementul
		out: lista fara element
	*/
	this->conturibancare.erase(this->conturibancare.begin() + pozitie);
}

void ContRepo::update(int pozitie, ContBancar element)
{
	/*
		desc : modifica un cont bancar
		in : pozitia elementului care trebuie modificat si noua informatie
		out : lista cu elementul modificat
	*/
	this->conturibancare[pozitie] = element;
}
int ContRepo::getSize()
{
	/*
	Descr : returneaza lungimea listei din repository
	In : lista
	Out : dimensiunea listei
	*/
	return this->conturibancare.size();
}
