#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;
/*
* односвязный список
* реализация
*/
class List
{
public:
	List() {}
	int insert();
	bool isTypeCorrect();
	int inputNum(int, int);       // Указатель вершины списка
	struct St {
		int num;
		double info;	     // Информационная часть элемента, например int
		St *next;    // Адресная часть – указатель на следующий элемент 
	} *top;
	void View(St*);
	int findAverage(St *);
	double Element(St **);
	void Del_All(St **);

	St* InStack(St *p, int in) {
		St *t = new St;			// Захватываем память для элемента
		t->info = in;			// Формируем информационную часть
		t->next = p;			// Формируем адресную часть
		return t;
	}
	St* OutStack(St* p, int *out) {
		St *t = p;			// Устанавливаем указатель t на вершину p
		*out = p->info;
		p = p->next; 		// Переставляем вершину p на следующий
		delete t; 			// Удаляем бывшую вершину t
		return p; 			// Возвращаем новую вершину p
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
			cout << "Некорректный ввод ! Введите заново: \n";
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
			cout << "\n\n\tВведено некорректное число(№)!";
			if ((number <= left_range) || (number >= right_range))
				cout << "\t Число может быть только от " << left_range << " и до " << right_range << " !";
			cout << "\n\t\tПопробуйте ещё раз: ";
		}
	}
}
void List::View(St *p) {
	St *t = p;
	while (t != NULL) {
		// Вывод на экран информационной части, например,
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
		cout << "----------------Ваше Меню выбора----------------" << endl;
		cout << "\n\tСоздать элементы списка - 1.\n\tДобавить элементы списка  - 2.\n\tПросмотреть элементы списка  - 3.\n\tУдалить элементы списка- 4.\n\tНайти элемент(Среднее значение) в списке- 5\n\tВыход – 0.\n\t";
		cout << "Ваш выбор :";
		kod = Sp.inputNum(0, 5);
		switch (kod) {
		case 1: case 2:
			if (kod == 1 && Sp.top != NULL) {
				// Если создаем новый стек, должны освободить память, занятую предыдущим
				cout << "Почистить однсовязный список!" << endl;
				break;
			}
			cout << "Введите количество = ";
			n = Sp.insert();
			for (i = 1; i <= n; i++) {
				int a = -100, b = 100;
				in = rand() % (b - a + 1) + a;
				Sp.top = Sp.InStack(Sp.top, in);
			}


			if (kod == 1) cout << "Cоздать " << n << endl;
			else cout << "Добавить " << n << endl;
			break;
		case 3:         if (!Sp.top) {

			cout << "Односвязный список пуст!" << endl;
			break;
		}
						cout << "---Односвязный список---" << endl;
						Sp.View(Sp.top);
						break;
		case 4:
			Sp.Del_All(&Sp.top);
			cout << "Элементы списка удалены!" << endl;
			break;
		case 5: {
			cout << "Cреднее значение = " << Sp.Element(&Sp.top) << endl;
			double temp = Sp.Element(&Sp.top);
			Sp.top->info = temp;
		}
				break;
		case 0:
			if (Sp.top != NULL)
				Sp.Del_All(&Sp.top);
			return;	// Выход – EXIT
		}
	}
}