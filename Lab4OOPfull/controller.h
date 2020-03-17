#pragma once
#include "Repository.h";
#include <vector>
class Controller
{
private: ContRepo repo;
public:
	Controller() {};
	Controller(ContRepo repo);
	void addElem(int zi, int bani, char* tip, char* desc, int id);
	void deleteElem(int pos);
	void update(int zi, int bani, char* tip, char* desc, int pos);
	vector<ContBancar>getAll();
	int getSize();
	int cautareData(int data);
	int cautareTip(char* t);
	int nrTranzactii(vector<ContBancar>list, int zi);
	vector<ContBancar> printTip(char* t, vector<ContBancar>list, vector<ContBancar>l);
	vector<ContBancar> printTipBig(char* t, vector<ContBancar>list, vector<ContBancar>l, int val);
	vector<ContBancar>printTipEqual(char* t, vector<ContBancar>list, vector<ContBancar>l, int val);
	void elimData(int data);
	void elimDate(int st, int sf);
	void elimTip(char* t);
	int sumaElem(vector<ContBancar>list, char* t);
	int cautareMax(vector<ContBancar>list);
	void filtrareTip(vector<ContBancar>list, char* t);
	void filtrareMin(vector<ContBancar>list, char* t, int val);
	int cautareCont(int id);
	int sold(int data);
};