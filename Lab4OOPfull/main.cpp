#include <iostream>
#include "contbancar.h"
#include "teste.h"
#include "Repository.h"
#include "controller.h"
#include "Ui.h"
using namespace std;

int main() {
	int a;
	testContBancar();
	testContRepo();
	testCtrl();
	ContRepo repo;
	Controller ctrl(repo);
	Ui Ui(ctrl);
	Ui.run();
	cin >> a;
	return 0;
	system("pause");
}
