#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;
/*
* ����������� ������
* ����������
*/
class List
{
public:
	List() {}
	int insert();
	bool isTypeCorrect();
	int inputNum(int, int);       // ��������� ������� ������
	struct St {
		int num;
		double info;	     // �������������� ����� ��������, �������� int
		St *next;    // �������� ����� � ��������� �� ��������� ������� 
	} *top;
	void View(St*);
	int findAverage(St *);
	double Element(St **);
	void Del_All(St **);

	St* InStack(St *p, int in) {
		St *t = new St;			// ����������� ������ ��� ��������
		t->info = in;			// ��������� �������������� �����
		t->next = p;			// ��������� �������� �����
		return t;
	}
	St* OutStack(St* p, int *out) {
		St *t = p;			// ������������� ��������� t �� ������� p
		*out = p->info;
		p = p->next; 		// ������������ ������� p �� ���������
		delete t; 			// ������� ������ ������� t
		return p; 			// ���������� ����� ������� p
	}

};
int List::insert()
{
	int l;
	while (true)
	{
		cin >> l;
		if (cin.get() == '\n') {
			break;
		}
		else {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "������������ ���� ! ������� ������: \n";
		}

	}
	return l;
}
bool List::isTypeCorrect()
{
	if (cin.get() == '\n')
		return true;
	else
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return false;
	}
}
int List::inputNum(int left_range, int right_range)
{
	int number;
	while (true)
	{
		cin >> number;
		if (isTypeCorrect() && (number >= left_range) && (number <= right_range))
		{
			return number;
		}
		else
		{
			cout << "\n\n\t������� ������������ �����(�)!";
			if ((number <= left_range) || (number >= right_range))
				cout << "\t ����� ����� ���� ������ �� " << left_range << " � �� " << right_range << " !";
			cout << "\n\t\t���������� ��� ���: ";
		}
	}
}
void List::View(St *p) {
	St *t = p;
	while (t != NULL) {
		// ����� �� ����� �������������� �����, ��������,
		cout << t->info << endl;
		t = t->next;
	}
}
int List::findAverage(St *p) {
	int amount = 0, i = 0;
	for (St *t = p; t; t = t->next, i++)
		amount += t->num;
	return amount / i;
}
double List::Element(St **top)
{
	double i = 0, summa = 0;
	St *t = *top;
	do
	{
		summa += t->info;
		i++;
		t = t->next;
	} while (t != NULL);
	return summa / i;
}
void List::Del_All(St **p) {
	St *t;
	while (*p != NULL) {
		t = *p;
		*p = (*p)->next;
		delete t;
	}
}




void main()
{
	int i, in, n, kod;
	List Sp;
	Sp.top = NULL;
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	while (true) {
		cout << "----------------���� ���� ������----------------" << endl;
		cout << "\n\t������� �������� ������ - 1.\n\t�������� �������� ������  - 2.\n\t����������� �������� ������  - 3.\n\t������� �������� ������- 4.\n\t����� �������(������� ��������) � ������- 5\n\t����� � 0.\n\t";
		cout << "��� ����� :";
		kod = Sp.inputNum(0, 5);
		switch (kod) {
		case 1: case 2:
			if (kod == 1 && Sp.top != NULL) {
				// ���� ������� ����� ����, ������ ���������� ������, ������� ����������
				cout << "��������� ����������� ������!" << endl;
				break;
			}
			cout << "������� ���������� = ";
			n = Sp.insert();
			for (i = 1; i <= n; i++) {
				int a = -100, b = 100;
				in = rand() % (b - a + 1) + a;
				Sp.top = Sp.InStack(Sp.top, in);
			}


			if (kod == 1) cout << "C������ " << n << endl;
			else cout << "�������� " << n << endl;
			break;
		case 3:         if (!Sp.top) {

			cout << "����������� ������ ����!" << endl;
			break;
		}
						cout << "---����������� ������---" << endl;
						Sp.View(Sp.top);
						break;
		case 4:
			Sp.Del_All(&Sp.top);
			cout << "�������� ������ �������!" << endl;
			break;
		case 5: {
			cout << "C������ �������� = " << Sp.Element(&Sp.top) << endl;
			double temp = Sp.Element(&Sp.top);
			Sp.top->info = temp;
		}
				break;
		case 0:
			if (Sp.top != NULL)
				Sp.Del_All(&Sp.top);
			return;	// ����� � EXIT
		}
	}
}