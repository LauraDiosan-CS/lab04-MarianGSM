#include "controller.h"
#include <iostream>
Controller::Controller(ContRepo repo)
{
	this->repo = repo;
}

void Controller::addElem(int zi, int bani, char* tip, char* desc, int id)
{
	ContBancar c = ContBancar(zi, bani, tip, desc, id);
	this->repo.addelem(c);
}

void Controller::deleteElem(int pos)
{
	this->repo.deleteElem(pos);
}

void Controller::update(int zi, int bani, char* tip, char* desc, int pos)
{
	ContBancar c = ContBancar(zi, bani, tip, desc, pos);
	this->repo.update(pos, c);
}

vector<ContBancar>Controller::getAll()
{
	return this->repo.getAll();
}

int Controller::getSize()
{
	return this->repo.getSize();
}

int Controller::cautareData(int data)
{
	vector<ContBancar>list;
	list = getAll();
	int i = 0;
	for (ContBancar c : list)
	{
		if (c.getZi() == data)
			return i;
		i++;
	}
	return -1;
}

int Controller::cautareTip(char* t)
{
	vector<ContBancar>list;
	list = getAll();
	int i = 0;
	for (ContBancar c : list)
	{
		if (strcmp(c.getTip(), t) == 0)
			return i;
		i++;
	}
	return -1;
}
void Controller::elimData(int data)
{
	int d = this->cautareData(data);
	while (d >= 0)
	{
		this->deleteElem(d);
		d = this->cautareData(data);
	}
}
void Controller::elimDate(int st, int sf)
{
	for (int i = st; i <= sf; i++)
		this->elimData(i);
}
void Controller::elimTip(char* t)
{
	int d = this->cautareTip(t);
	while (d > -1)
	{
		this->deleteElem(d);
		d = this->cautareTip(t);
	}
}

vector<ContBancar> Controller::printTip(char* t, vector<ContBancar>list, vector<ContBancar> l)
{
	for (ContBancar c : list)
		if (strcmp(c.getTip(), t) == 0)
			l.push_back(c);
	return l;
}

vector<ContBancar>Controller::printTipBig(char* t, vector<ContBancar>list, vector<ContBancar>l, int val)
{
	l = this->printTip(t, list, l);
	int i = 0;
	for (ContBancar c : l)
	{
		if (c.getBani() < val)
			l.erase(l.begin() + i);
		else
			i++;
	}
	return l;
}

vector<ContBancar>Controller::printTipEqual(char* t, vector<ContBancar>list, vector<ContBancar>l, int val)
{
	l = this->printTip(t, list, l);
	int i = 0;
	for (ContBancar c : l)
	{
		if (c.getBani() != val)
			l.erase(l.begin() + i);
		else
			i++;
	}
	return l;
}

int Controller::sumaElem(vector<ContBancar>list, char* t)
{
	int s = 0;
	for (ContBancar c : list)
		if (strcmp(c.getTip(), t) == 0)
			s += c.getBani();
	return s;
}

int Controller::nrTranzactii(vector<ContBancar>list, int zi)
{
	int t = 0;
	for (ContBancar c : list)
		if (c.getZi() == zi)
			t++;
	return t;
}
int Controller::cautareMax(vector<ContBancar>list)
{
	int data = 0, maxi = 0, s;
	for (ContBancar c : list)
	{
		if (nrTranzactii(list, c.getZi()) > maxi)
		{
			maxi = nrTranzactii(list, c.getZi());
			data = c.getZi();
		}
	}
	return data;
}

void Controller::filtrareTip(vector<ContBancar>list, char* t)
{
	int i = 0;
	for (ContBancar c : list)
	{
		if (strcmp(c.getTip(), t) != 0)
			this->deleteElem(i);
		else

			i++;
	}
}

void Controller::filtrareMin(vector<ContBancar>list, char* t, int val)
{
	int i = 0;
	for (ContBancar c : list)
	{
		if (strcmp(c.getTip(), t) != 0)
			this->deleteElem(i);
		else
			if (c.getBani() > val)
				this->deleteElem(i);
			else
				i++;
	}
}

int Controller::cautareCont(int id)
{
	int pos = 0;
	vector<ContBancar>list = this->getAll();
	for (ContBancar i : list)
	{
		if (i.getId() == id)
			return pos;
		pos++;
	}
	return -1;
}

int Controller::sold(int data)
{
	int s = 0;
	vector<ContBancar>list = this->getAll();
	for (ContBancar c : list)
	{
		if (c.getZi() == data)
			if (!strcmp(c.getTip(), "out"))
			{
				if (s - c.getBani() < 0)
				{
					cout << "Nu este posibil" << endl;
				break;
				}
					
				
				else
					s -= c.getBani();
			}

			
			else
				
				s += c.getBani();
		
		
	}
	return s;
}