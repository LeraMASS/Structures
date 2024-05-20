#include <iostream>
#include <string>

struct MyPerson {// глобальная структура (!!!!!!!! Полезно для проекта)
	std::string name;
	int age;
	std::string job;
};

void print_person(const MyPerson& MP) {//(!!!!!Полезно для проекта) const ссылка(&) на объект структуры, чтоб его не повредить
	std::cout << "Name: " << MP.name << std::endl;//обязательно через точку имя поля структуры
	std::cout << "Age: " << MP.age << std::endl;
	std::cout << "Position: " << MP.job << std::endl;
}

MyPerson input_person() {// Полезно для проекта(!!!!!!!)
	MyPerson result;
	std::cout << "Enter name -> ";
	std::getline(std::cin, result.name);

	std::cout << "Enter age -> ";
	std::cin >> result.age;
	std::cin.ignore();//очищение потокак ввода, очищает от мусора.

	std::cout << "Enter Position -> ";
	std::getline(std::cin, result.job);

	return result;
}
//Задача 1.
struct Date {
	int dey;
	int month;
	int year;
};
struct CoinsKeeper {
	std::string name;
	Date birsthdey;
	int coins_number = 0;
	int* coins = nullptr;
};
void print_keeper(const CoinsKeeper& CK) {
	std::cout << "Имя: " << CK.name << std::endl;
	std::cout << "Дата рождения: "
		<< CK.birsthdey.dey << "."
		<< CK.birsthdey.month << '.'
		<< CK.birsthdey.year << std::endl;
	std::cout << "Млнеты: ";
	for (int i = 0; i < CK.coins_number; i++)
		std::cout << CK.coins[i] << ' ';
	std::cout << std::endl;
}
inline int age(const CoinsKeeper& CK, int year) {
	return (year - CK.birsthdey.year);
}
int cash(const CoinsKeeper& CK) {
	int result = 0;
	for (int i = 0; i < CK.coins_number; i++)
		result += CK.coins[i];
	return result;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	//Объявление структуры 
	struct Person {
		std::string name;//имя
		int age;//возраст
		std::string job;//работа
		int salary;//зп
	}p4, p2;// можно записать доп. объекты , можно пречислить = {};

	Person p1;//person имя структуры, p1 объект структуры, все остальное это поля.
	p1.name = "Tomy First";
	p1.age = 28;
	p1.job = "progpamer";
	p1.salary = 300000;//Запись в переменные.

	std::cout << "Name: " << p1.name << std::endl;
	std::cout << "Age: " << p1.age << std::endl;
	std::cout << "Job: " << p1.job << std::endl;
	std::cout << "Salary: " << p1.salary << std::endl;
	std::cout << "------------------------------" << std::endl;

	//Быстрый вариант создания структуры (сокращенный вариант,
	//на основе одной структуры можно создать несколько объектов, не ограниченое кол-во раз)
	Person p2{ "Bob Smit", 20, "Med", 10000};
	std::cout << "Name: " << p2.name << std::endl;
	std::cout << "Age: " << p2.age << std::endl;
	std::cout << "Job: " << p2.job << std::endl;
	std::cout << "Salary: " << p2.salary << std::endl;

	std::cout << "--------------------" << std::endl;

	Person p3 = p1; //ошибки не будет, синтаксис похож на синтаксис переменной
	std::cout << "Name: " << p3.name << std::endl;
	std::cout << "Age: " << p3.age << std::endl;
	std::cout << "Job: " << p3.job << std::endl;
	std::cout << "Salary: " << p3.salary << std::endl;

	//Поля по умолчанию, вложенные структуры и указатели на объекты структур
	struct Date {
		int dey = 2;//поля по умолчанию.
		int month= 2;
		int year = 1998;
	};

	Date d1;
	std::cout << d1.dey << "." << d1.month << "." << d1.year << std::endl;
	Date d2{ 23, 6, 2021 };
	std::cout << d2.dey << "." << d2.month << "." << d2.year << std::endl;

	struct Human {
		std::string name;
		Date birthdey; // Date значения по умолчанию { 20, 8, 2001}
		std::string job;
	};

	Human h1{ "Zina Hok", { 20, 8, 2001}, "Powar" };// при создании структуры, можно записать структуру
	std::cout << "Name: " << h1.name << std::endl;
	std::cout << "Birthdey: " << h1.birthdey.dey << '.' <<
		h1.birthdey.month << '.' << h1.birthdey.year << std::endl
		<< "Position: " << h1.job << std::endl;
	// Указатели и структуры
	Human* ph = &h1;
	std::cout << ph->name << std::endl;// -> это разименовыватель, используется в ооп
	std::cout << ph->birthdey.dey << std::endl;

	// Структуры и функции
	MyPerson mp1{"Vila Donna", 45, "Sistem admin"};
	print_person(mp1);

	std::cout << "------------------" << std::endl;

	MyPerson mp2 = input_person();
	print_person(mp2);//происходит копирование полей

	//Задача 1 Хранитель монет
	std::cout << "Задача 1.\n Информация о хранители:\n";
	CoinsKeeper ck{
		"Женя Васина",
		{ 12, 9, 2015 },
		5,
		new int[5] { 1, 10, 2, 2, 10 }
	};

	print_keeper(ck);
	std::cout << "Возраст: " << age(ck, 2024) << std::endl;
	std::cout << "Общие сбережения: " << cash(ck) << " рублей" << std::endl;

	return 0;
}



