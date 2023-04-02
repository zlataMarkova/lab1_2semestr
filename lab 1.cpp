// lab 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
#include <string>
struct student
{
	string name;
	string sex;
	int group, num;
	int grades[8]; 
	float ball;
};
const int n = 30;
struct student students[n];
int k;

//1-ое задание.
void create()
{
		cout << "Введите ФИО студента: ";
		getline(cin >> ws, students[k].name);
		cout << "Введите пол: ";
		getline(cin >> ws, students[k].sex);
		cout << "Введите номер группы: ";
		cin >> students[k].group;
		cout << "Введите номер студента: ";
		cin >> students[k].num;
		
		for (int i = 0; i < 8; i++)
		{
			do
			{
				cout << "Введите " << i+1 << "-ую" << " оценку:";
				cin >> students[k].grades[i];
				if (students[k].grades[i] > 5 or 3 > students[k].grades[i])
					cout<< "Неправильное значение, введите ещё раз\n\n";
			} while (students[k].grades[i] > 5 or 3 > students[k].grades[i]);
		}
		cout << "\n";
		k += 1;
}

//3-ие задание
void output()
{
	for (int i = 0; i < k; i++)
	{
		cout << "ФИО студента: " << students[i].name;
		cout << "\n";
		cout << "Пол студента: " << students[i].sex;
		cout << "\n";
		cout << "Номер группы: " << students[i].group;
		cout << "\n";
		cout << "Номер студента: " << students[i].num;
		cout << "\n";
		for (int j = 0; j < 3; j++)
			cout << "Результат " << j + 1 << "-ого экзамена: " << students[i].grades[j] << "\n";
		for (int j = 3; j < 8; j++)
			cout << "Результат " << j + 1 << "-ого зачёта: " << students[i].grades[j] << "\n";
		cout << "\n\n";
	}
	cout << "\n";
}

//2-ое задание
void replace()
{
	cout << "Введите номер записи которую хотите изменить: ";
	int c;
	cin >> c;
	cout << "Выберите что изменить?\n" << "1.ФИО\n" << "2.Пол\n" << "3.Номер группы\n" << "4.Номер студента\n" << "5.Оценку за 1-ый экз\n" << "6.Оценку за 2-ый экз\n" << "7.Оценку за 3-ий экз\n" << "8.Оценку за 1-ый зачёт\n" << "9.Оценку за 2-ый зачёт\n" << "10.Оценку за 3-ий зачёт\n" << "11.Оценку за 4-ый зачёт\n" << "12.Оценку за 5-ый зачёт\n";
	cout << "Ваш выбор: ";
	int m;
	cin >> m;
	cout << "Введите новое значение: ";
	switch (m)
	{
	case 1:
		getline(cin >> ws, students[c - 1].name);
		break;
	case 2:
		getline(cin >> ws, students[c - 1].sex);
		break;
	case 3:
		cin >> students[c-1].group;
		break;
	case 4:
		cin >> students[c-1].num;
		break;
	case 5:
		cin >> students[c-1].grades[0];
		break;
	case 6:
		cin >> students[c-1].grades[1];
		break;
	case 7:
		cin >> students[c-1].grades[2];
		break;
	case 8:
		cin >> students[c-1].grades[3];
		break;
	case 9:
		cin >> students[c-1].grades[4];
		break;
	case 10:
		cin >> students[c-1].grades[5];
		break;
	case 11:
		cin >> students[c-1].grades[6];
		break;
	case 12:
		cin >> students[c-1].grades[7];
		break;
	}
	cout << "\n";
}

//4-ое задание.
void ngroup()
{
	cout << "Введите номер группы:";
	int numb;
	cin >> numb;
	cout << "Студенты с таким номером в списке:\n";
	for (int i = 0; i < n; i++)
	{
		if (students[i].group == numb)
		{
			cout << "ФИО студента: " << students[i].name << "\n";
			cout << "Пол студента: " << students[i].sex << "\n";
			cout << "Номер группы: " << students[i].group << "\n";
			cout << "Номер студента: " << students[i].num << "\n";
			for (int j=0; j<3; j++)
				cout << "Результат "<< j+1<<"-ого экзамена: " << students[i].grades[j] << "\n";
			for (int j = 3; j < 8; j++)
				cout << "Результат " << j + 1 << "-ого зачёта: " << students[i].grades[j] << "\n";
			cout << "\n";
		}
	}
}

//5-ое задание.
void top()
{
	for (int i = 0; i < k; i++)
	{
		float s = 0;
		for (int j = 0; j < 8; j++)
			s += students[i].grades[j];
		students[i].ball = s / 8;
	}
	/*for (int i = 0; i < k; i++)
	{
		cout << students[i].ball<<"\n";
	}*/
	
	for (int i = 0; i < k - 1; i++)
	{
		for (int j = 0; j < k - i - 1; j++)
		{
			if (students[j+1].ball > students[j].ball)
			{
				swap(students[j], students[j+1]);
			}
		}
	}
	for (int i = 0; i < k; i++)
	{
		cout <<i+1<<". "<< students[i].name<<" (Средний балл: "<<students[i].ball<<")"<<"\n";
	}
}

//6-ое задание.
void pol()
{
	int malecount = 0;
	int femalecount = 0;
	for (int i = 0; i < n; i++)
	{
		if (students[i].sex == "F")
			femalecount += 1;
		if (students[i].sex == "M")
			malecount += 1;
	}
	cout << "Количество студентов женского пола: " << femalecount<<"\n";
	cout << "Количество студентов мужского пола: " << malecount << "\n";
}

//7-ое задание
void marks()
{
	cout << "Студенты без стипендии:\n";
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (students[i].grades[j] == 3)
			{
				cout << "ФИО студента: " << students[i].name << "\n";
				cout << "Пол студента: " << students[i].sex << "\n";
				cout << "Номер группы: " << students[i].group << "\n";
				cout << "Номер студента: " << students[i].num << "\n";
				for (int j = 0; j < 3; j++)
					cout << "Результат " << j + 1 << "-ого экзамена: " << students[i].grades[j] << "\n";
				for (int j = 3; j < 8; j++)
					cout << "Результат " << j + 1 << "-ого зачёта: " << students[i].grades[j] << "\n";
				cout << "\n";
				break;
			}
		}
	}
	cout << "Студенты ударники:\n";
	for (int i = 0; i < k; i++)
	{
		int four = 0;
		int three = 0;
		for (int j = 0; j < 8; j++)
		{
			if (students[i].grades[j] == 3)
				three += 1;
			if (students[i].grades[j] == 4)
				four += 1;
		}
		if (four > 0 and three==0)
		{
			cout << "ФИО студента: " << students[i].name << "\n";
			cout << "Пол студента: " << students[i].sex << "\n";
			cout << "Номер группы: " << students[i].group << "\n";
			cout << "Номер студента: " << students[i].num << "\n";
			for (int j = 0; j < 3; j++)
				cout << "Результат " << j + 1 << "-ого экзамена: " << students[i].grades[j] << "\n";
			for (int j = 3; j < 8; j++)
				cout << "Результат " << j + 1 << "-ого зачёта: " << students[i].grades[j] << "\n";
			cout << "\n";
		}
		
	}
	cout << "Студенты отличники:\n";
	for (int i = 0; i < k; i++)
	{
		int five = 0;
		for (int j = 0; j < 8; j++)
		{
			if (students[i].grades[j] == 5)
				five += 1;
		}
		if (five==8)
		{
				cout << "ФИО студента: " << students[i].name << "\n";
				cout << "Пол студента: " << students[i].sex << "\n";
				cout << "Номер группы: " << students[i].group << "\n";
				cout << "Номер студента: " << students[i].num << "\n";
				for (int j = 0; j < 3; j++)
					cout << "Результат " << j + 1 << "-ого экзамена: " << students[i].grades[j] << "\n";
				for (int j = 3; j < 8; j++)
					cout << "Результат " << j + 1 << "-ого зачёта: " << students[i].grades[j] << "\n";
				cout << "\n";
		}
		
	}
}

//8-ое задание
void list()
{
	cout << "Введите номер студента в списке: ";
	int order;
	cin >> order;
	for (int i = 0; i < k; i++)
	{
		if (students[i].num == order)
		{
			cout << "Студенты с таким номером в списке:\n";
			cout << "ФИО студента: " << students[i].name<< "\n";
			cout << "Пол студента: " << students[i].sex<< "\n";
			cout << "Номер группы: " << students[i].group<< "\n";
			cout << "Номер студента: " << students[i].num<< "\n";
			for (int j = 0; j < 3; j++)
				cout << "Результат " << j + 1 << "-ого экзамена: " << students[i].grades[j] << "\n";
			for (int j = 3; j < 8; j++)
				cout << "Результат " << j + 1 << "-ого зачёта: " << students[i].grades[j] << "\n";
			cout << "\n";
		}

	}
}
int main()
{
	setlocale(0, "");
	//cout << sizeof(student)<<"\n";
	cout << "Какое количество студентов вы хотите ввести: ";
	
	cin >> k;

	for (int i = 0; i < k; i++)
	{
		cout << "Введите ФИО студента: ";
		getline(cin >> ws, students[i].name);
		cout << "Введите пол: ";
		getline(cin >> ws, students[i].sex);
		cout << "Введите номер группы: ";
		cin >> students[i].group;
		cout << "Введите номер студента: ";
		cin >> students[i].num;
		for (int j = 0; j < 8; j++)
		{
			do
			{
				cout << "Введите " << j+1 << "-ую " << "оценку:";
				cin >> students[i].grades[j];
				if (students[i].grades[j] > 5 or 3 > students[i].grades[j])
					cout << "Неправильное значение, введите ещё раз\n\n";
			} while (students[i].grades[j] > 5 or 3 > students[i].grades[j]);
		}
		cout << "\n";
	}
	
	while (true)
	{
		cout << "Что вы хотите сделать?\n" << "1.Создать новую запись о студенте\n" << "2.Изменить запись\n" << "3.Вывести записи\n" <<"4.Вывести список группы\n"<<"5.Топ студентов\n"<<"6.Количество студентов разного пола\n"<<"7.Успеваемость студентов\n"<<"8.Список студентов под определенным номером\n"<<"0.Ничего\n";
		int l;
		cin >> l;
		if (l == 0)
			break;
		switch (l)
		{
		case 1:
			create();
			system("pause");
			system("cls");
			break;
		case 2:
			replace();
			system("pause");
			system("cls");
			break;
		case 3:
			output();
			system("pause");
			system("cls");
			break;
		case 4:
			ngroup();
			system("pause");
			system("cls");
			break;
		case 5:
			top();
			system("pause");
			system("cls");
			break;
		case 6:
			pol();
			system("pause");
			system("cls");
			break;
		case 7:
			marks();
			system("pause");
			system("cls");
			break;
		case 8:
			list();
			system("pause");
			system("cls");
			break;

		}
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
