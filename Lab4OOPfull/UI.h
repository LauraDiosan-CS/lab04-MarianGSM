#pragma once
#include "controller.h"
class Ui
{
private: Controller ctrl;
	   void printMenu();
	   void  printList(vector<ContBancar> list);
	   void printContBancar(int id, int bani, char* tip, char* desc, int zi);
public: Ui() {};
	  Ui(Controller ctrl);
	  void run();
};