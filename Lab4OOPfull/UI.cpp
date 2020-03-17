#include "UI.h"

#include"controller.h"
#include <iostream>
using namespace std;
Ui::Ui(Controller ctrl)
{
	this->ctrl = ctrl;
}
void Ui::printContBancar(int id, int bani, char* tip, char* desc, int zi)
{
	cout << id << " In data " << zi << " a fost " << tip << " suma " << bani;
}
void Ui::printMenu()
{
	cout << "Apasati: " << endl;
	cout << " 1.- Pentru adaugarea unei tranzactii in lista" << endl;
	cout << " 2. Pentru afisarea tranzactiilor" << endl;
	cout << " 3. Pentru a elimina tranzactiile dintr-o anumita data " << endl;
	cout << " 4. Pentru eliminarea interval de tranzactii" << endl;
	cout << " 5. Pentru eliminarea unui tip de tranzactie" << endl;
	cout << " 6. Pentru afisarea unui anumit tip de tranzactie" << endl;
	cout << "7. Pentru afisarea unui tip de tranzactie mai mare decat o valoare" << endl;
	cout << "8. Pentru afisarea unui tip de tranzactie egal cu o valoare" << endl;
	cout << "9. Pentru afisarea sumei totale pentru un tip de tranzactie" << endl;
	cout << "10 . Pentru afisarea zilei cu cele mai multe tranzactii" << endl;
	cout << "11. Pentru filtrare dupa tip" << endl;
	cout << "12. Pentru filtrare dupa tip si valoare" << endl;
	cout << "13. Pentru modificarea unei tranzactii" << endl;
	cout << "14. Pentru calcularea soldului unei zile" << endl;
}
void Ui::printList(vector<ContBancar> list)
{

	for (ContBancar c : list)
	{
		printContBancar(c.getId(), c.getBani(), c.getTip(), c.getDesc(), c.getZi());
		cout << endl;
	}
}

void Ui::run()
{
	vector<ContBancar>list, l;
	list = ctrl.getAll();
	int cmd = 1, zi, bani, id;
	char* tip = new char[7];
	char* desc = new char[7];
	char* t = new char[7];
	while (cmd)
	{
		this->printMenu();
		cin >> cmd;
		list = ctrl.getAll();
		switch (cmd)
		{
		case 0:
			cout << "Aplicatia a fost oprita ";
			return;
		case 1:
			cout << "Introduceti data :";
			cin >> zi;
			cout << "Introduceti suma: ";
			cin >> bani;
			cout << "Introduceti tipul: ";
			cin >> tip;
			cout << "Introduceti descrierea: ";
			cin >> desc;
			id = this->ctrl.getSize();
			this->ctrl.addElem(zi, bani, tip, desc, id);
			break;
		case 2:
			this->printList(list);
			break;
		case 3:
			cout << "Introduceti data: " << endl;
			cin >> zi;
			ctrl.elimData(zi);
			break;
		case 4:
			int st, sf;
			cout << "Introduceti data de inceput: ";
			cin >> st;
			cout << endl << "Introduceti data de sfarsit: ";
			cin >> sf;
			ctrl.elimDate(st, sf);
			break;
		case 5:

			cin >> t;
			this->ctrl.elimTip(t);
			break;
		case 6:
			cout << "Introduceti tipul: ";
			list = ctrl.getAll();
			cin >> t;
			l.clear();
			printList(ctrl.printTip(t, list, l));
			break;
		case 7:
			cout << "Introduceti tipul: ";
			cin >> t;
			l.clear();
			cout << endl << "Introduceti suma cu care doriti sa comparati: ";
			cin >> bani;
			printList(ctrl.printTipBig(t, list, l, bani));
			break;
		case 8:
			cout << "Introduceti tipul: ";
			cin >> t;
			l.clear();
			cout << endl << "Introduceti suma cu care doriti sa comparati: ";
			cin >> bani;
			printList(ctrl.printTipEqual(t, list, l, bani));
			break;
		case 9:
			cout << "Introduceti tipul: ";
			cin >> t;
			cout << ctrl.sumaElem(list, t) << endl;
			break;
		case 10:
			cout << ctrl.cautareMax(list) << endl;
			break;
		case 11:
			cout << "Introduceti tipul: ";
			cin >> t;
			ctrl.filtrareTip(list, t);
			printList(list);
			break;
		case 12:
			cout << "Introduceti tipul: ";
			cin >> t;
			cout << endl << "Introduceti valoarea cu care doriti sa comparati: ";
			cin >> bani;
			ctrl.filtrareMin(list, t, bani);
			printList(list);
			break;

		case 13:
			cout << "Introduceti id-ul: ";
			int id;
			cin >> id;
			cout << "Introduceti noua data: ";
			cin >> zi;
			cout << endl << "Introduceti noua suma: ";
			cin >> bani;
			cout << endl << "Introduceti noul tip: ";
			cin >> tip;
			cout << endl << "Introduceti noua descriere: ";
			cin >> desc;
			ctrl.update(zi, bani, tip, desc, ctrl.cautareCont(id));
			break;
		case 14:
			cout << "Introduceti data: ";
			cin >> zi;
			cout << ctrl.sold(zi) << endl;
			break;
		default:
			cout << "Comanda invalida!";
			break;
		}
	}
}