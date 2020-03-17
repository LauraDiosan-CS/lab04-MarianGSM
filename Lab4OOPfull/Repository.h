#pragma once
#include <iostream>
#include "ContBancar.h"
#include <vector>
using namespace std;

class ContRepo {
private:
	vector<ContBancar> conturibancare;
public:
	ContRepo();
	~ContRepo();
	void addelem(ContBancar c);
	vector <ContBancar> getAll();
	void deleteElem(int pozitie);
	int getSize();
	void update(int pozitie, ContBancar elem);
};