#include "teste.h"
#include "assert.h"
#include "ContBancar.h"
#include "Repository.h"
#include"controller.h"
#include <string.h>
#include <vector>
using namespace std;

void testContBancar() {
	ContBancar c1 = ContBancar();
	assert(c1.getBani() == 0);
	assert(c1.getTip() == NULL);

	cout << "Testele pentru ContBancar au trecut cu succes" << endl;

}
void testContRepo() {
	ContBancar c = ContBancar();
	ContRepo repo = ContRepo();
	assert(repo.getAll().size() == 0);
	char t1[] = "In";
	char d1[] = "salar";
	ContBancar c1 = ContBancar(10, 100, t1, d1, 0);
	repo.addelem(c1);
	assert(repo.getAll().size() == 1);

	char t2[] = "Out";
	char d2[] = "salar";
	ContBancar c2 = ContBancar(30, 2, t2, d2, 1);
	char t3[] = "In";
	char d3[] = "salar";
	ContBancar c3 = ContBancar(1, 1500, t3, d3, 2);
	ContBancar elem = ContBancar(1, 1520, t3, d3, 3);
	repo.addelem(c2);
	repo.addelem(c3);
	repo.update(0, elem);
	vector<ContBancar>list;
	list = repo.getAll();
	assert(list[0].getBani() == 1520);
	elem = ContBancar(5, 1520, t3, d3, 3);
	repo.update(1, elem);
	list = repo.getAll();
	assert(list[1].getZi() == 5);

	repo.deleteElem(1);
	assert(repo.getAll().size() == 2);
	cout << "Testele pentru ContRepo au trecut cu succes" << endl;
}

void testCtrl()
{
	ContRepo repo;
	Controller ct1 = Controller(repo);
	assert(ct1.getAll().size() == 0);
	char t1[] = "in";
	char d1[] = "salar";
	ct1.addElem(20, 100, t1, d1, 0);
	assert(ct1.getAll().size() == 1);
	ct1.addElem(7, 3, t1, d1, 1);
	ct1.addElem(1, 2, t1, d1, 2);
	ct1.addElem(10, 2, t1, d1, 4);
	assert(ct1.getAll().size() == 4);

	ct1.deleteElem(1);
	assert(ct1.getAll().size() == 3);
	ct1.deleteElem(0);
	assert(ct1.getAll().size() == 2);

	ct1.update(20, 100, t1, d1, 0);
	ct1.deleteElem(1);
	vector<ContBancar>list = ct1.getAll();
	for (ContBancar c : list)
	{
		assert(c.getZi() == 20);
		assert(c.getBani() == 100);
		assert(c.getId() == 0);
	}
	assert(ct1.getSize() == 1);
	ct1.addElem(20, 10, t1, d1, 1);
	assert(ct1.getSize() == 2);

	assert(ct1.cautareData(20) == 0);
	assert(ct1.cautareData(2) == -1);
	assert(ct1.cautareData(7) == -1);
	assert(ct1.cautareData(8) == -1);
	assert(ct1.cautareData(30) == -1);

	char t2[] = "out";
	assert(ct1.cautareTip(t1) == 0);
	assert(ct1.cautareTip(t2) == -1);

	ct1.elimData(20);
	assert(ct1.getSize() == 0);

	cout << "Testele pentru Ctrl au trecut" << endl;
}
