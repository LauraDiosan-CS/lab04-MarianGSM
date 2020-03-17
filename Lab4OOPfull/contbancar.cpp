//#include "stdafx.h"

#include "contbancar.h"
#include <cstring>
#include <iostream>
using namespace std;

ContBancar::ContBancar() {
	this->bani = 0;
	this->tip = NULL;
	this->desc = NULL;
	this->zi = 0;
	this->id = 0;
}

ContBancar::ContBancar(int zi, int bani, char* tip, char* desc, int id) {
	this->zi = zi;
	this->bani = bani;
	this->id = id;
	this->tip = new char[strlen(tip) + 1];
	strcpy_s(this->tip, strlen(tip) + 1, tip);
	this->desc = new char[strlen(desc) + 1];
	strcpy_s(this->desc, strlen(desc) + 1, desc);
}
ContBancar::ContBancar(const ContBancar& c) {
	this->zi = c.zi;
	this->bani = c.bani;
	this->id = c.id;
	if (c.tip != NULL)
	{
		this->tip = new char[strlen(c.tip) + 1];
		strcpy_s(this->tip, strlen(c.tip) + 1, c.tip);
	}
	else
		this->tip = NULL;

	if (c.desc != NULL)
	{
		this->desc = new char[strlen(c.desc) + 1];
		strcpy_s(this->desc, strlen(c.desc) + 1, c.desc);
	}
	else
		this->desc = NULL;
}
ContBancar::~ContBancar() {
	if (this->tip != NULL) {
		delete[]this->tip;
		this->tip = NULL;
	}
	if (this->desc != NULL) {
		delete[]this->desc;
		this->desc = NULL;
	}
}
void ContBancar::setBani(int b) {
	this->bani = b;
}
void ContBancar::setZi(int z) {
	this->zi = z;
}
void ContBancar::setId(int id) {
	this->id = id;
}
void ContBancar::setTip(char* t) {
	if (this->tip) {
		delete[]this->tip;
	}
	this->tip = new char[strlen(t) + 1];
	strcpy_s(this->tip, strlen(t) + 1, t);
}
void ContBancar::setDesc(char* d) {
	if (this->desc) {
		delete[]this->desc;
	}
	this->desc = new char[strlen(d) + 1];
	strcpy_s(this->desc, strlen(d) + 1, d);
}

ContBancar& ContBancar ::operator=(const ContBancar& c) {
	if (this != &c) {
		this->setBani(c.bani);
		this->setZi(c.zi);
		this->setTip(c.tip);
		this->setId(c.id);
		this->setDesc(c.desc);
	}
	return *this;
}