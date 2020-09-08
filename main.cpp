#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include "windows.h"


#define READ 0
#define WRITE 1

using namespace std;

fstream myFile;	//поток для считывания данных с файла

struct Animal{
	string name;		//название
	string kind;		//вид
	string color;		//цвет окраски
	unsigned amount;	//численность
	vector<string> countryLiving;	//Страны обитания животного
};

struct Country{
	string name;
	vector<Animal> animal;
};

vector<Animal> animals;

vector<Country> country;

//функция вывода меню
void printMenu(){
	cout << endl;
	cout << "===================================================" << endl;
	cout << "Главное меню:" << endl;
	cout << "1)Вывести информацию о всех животных" << endl;
	cout << "2)Добавить животное" << endl;
	cout << "3)Удалить животное" << endl;
	cout << "4)Редактировать информацию о животном" << endl;
	cout << "5)Добавить страну обитания животного" << endl;
	cout << "6)Удалить страну обитания животного" << endl;
	cout << "7)Редактировать страну обитания животного" << endl;
	cout << "8)Поиск животных" << endl;
	cout << "9)Вывод данных о животных с выбором типа сортировки" << endl;
	cout << "10)Очистить экран" << endl;
	cout << "11)Сохранить данные" << endl;
	cout << "12)Выход" << endl;
	cout << "===================================================" << endl;
	cout << "> ";
}

//Функция вывода всех животных
void printAnimals(){
	if (animals.size() > 0){
		cout << setw(24) << right << "Животное";
		cout << setw(20) << right << "Вид";
		cout << setw(20) << right << "Численность";
		cout << setw(20) << right << "Цвет окраски";
		cout << setw(20) << right << "Страны обитания" << endl;
		cout << "========================================================================================================" << endl;

		for (int i = 0;i < animals.size();i++){
			cout << setw(3) << right << (i + 1) << ")";
			cout << setw(20) << right << animals[i].name;
			cout << setw(20) << right << animals[i].kind;
			cout << setw(20) << right << animals[i].amount;
			cout << setw(20) << right << animals[i].color;
			for (int j = 0;j < animals[i].countryLiving.size();j++){
				cout << setw(20) << right << animals[i].countryLiving[j] << endl;
				for (int k = 0;k < 84;k++) cout << " ";
			}
			cout << endl <<"________________________________________________________________________________________________________" << endl;
		}
		
	}
	else{
		cout << "Файл с данными пуст..." << endl;
	}	
}

void selectSort(int select){
	switch(select){
	case 1:{
		int n;
		do{
			cout << endl << "Введите значение N: ";
			cin >> n;
			fflush(stdin);
		}while(n < 1);
		cout << setw(24) << right << "Животное";
		cout << setw(20) << right << "Вид";
		cout << setw(20) << right << "Численность";
		cout << setw(20) << right << "Цвет окраски";
		cout << setw(20) << right << "Страны обитания" << endl;
		cout << "========================================================================================================" << endl;
		for (int i = 0;i < animals.size();i++){
			if (animals[i].amount < n){
				cout << setw(24) << right << animals[i].name;
				cout << setw(20) << right << animals[i].kind;
				cout << setw(20) << right << animals[i].amount;
				cout << setw(20) << right << animals[i].color;
				for (int j = 0;j < animals[i].countryLiving.size();j++){
					cout << setw(20) << right << animals[i].countryLiving[j] << endl;
					for (int k = 0;k < 84;k++) cout << " ";
				}
				cout << endl <<"________________________________________________________________________________________________________" << endl;
			}
		}
		break;
		   }
	case 2:{
		int n;
		do{
			cout << endl << "Введите значение N: ";
			cin >> n;
			fflush(stdin);
		}while(n < 1);

		cout << setw(24) << right << "Животное";
		cout << setw(20) << right << "Вид";
		cout << setw(20) << right << "Численность";
		cout << setw(20) << right << "Цвет окраски";
		cout << setw(20) << right << "Страны обитания" << endl;
		cout << "========================================================================================================" << endl;

		for (int i = 0;i < animals.size();i++){
			
			if (animals[i].amount > n){
				cout << setw(24) << right << animals[i].name;
				cout << setw(20) << right << animals[i].kind;
				cout << setw(20) << right << animals[i].amount;
				cout << setw(20) << right << animals[i].color;
				for (int j = 0;j < animals[i].countryLiving.size();j++){
					cout << setw(20) << right << animals[i].countryLiving[j] << endl;
					for (int k = 0;k < 84;k++) cout << " ";
				}
				cout << endl <<"________________________________________________________________________________________________________" << endl;
			}
		}
		break;
		break;
		   }
	case 3:{
		vector<Animal> temp = animals;
		for (int i = 0;i < animals.size();i++){
			for (int j = 0;j < animals.size() - i;j++){
				if (strcmp(animals[j].name.c_str(), animals[j + 1].name.c_str()) > 0){
					Animal a = animals[j];
					animals[j] = animals[j + 1];
					animals[j + 1] = a;
				}
			}
		}
		printAnimals();
		animals = temp;
		break;
		   }
	case 4:{
		vector<Animal> temp = animals;
		for (int i = 1;i < animals.size();i++){
			for (int j = 0;j < animals.size() - i;j++){
				if (strcmp(animals[j].kind.c_str(), animals[j + 1].kind.c_str()) > 0){
					Animal a = animals[j];
					animals[j] = animals[j + 1];
					animals[j + 1] = a;
				}
			}
		}
		printAnimals();
		animals = temp;
		break;
		   }
	case 5:{
		vector<Animal> temp = animals;
		for (int i = 1;i < animals.size();i++){
			for (int j = 0;j < animals.size() - i;j++){
				if (strcmp(animals[j].color.c_str(), animals[j + 1].color.c_str()) > 0){
					Animal a = animals[j];
					animals[j] = animals[j + 1];
					animals[j + 1] = a;
				}
			}
		}
		printAnimals();
		animals = temp;
		break;
		}
	case 6:{
		//получаем все страны обитания
		for (int i = 0;i < animals.size();i++){
			for (int j = 0;j < animals[i].countryLiving.size();j++){
				Country c;
				Animal a;
				c.name = animals[i].countryLiving[j];
				a.name = animals[i].name;
				c.animal.push_back(a);
				country.push_back(c);
			}
		}

		//удаляем одинаковые элементы вектора
		vector<Country>::iterator it;
		for (int i = 0;i < country.size();i++){
			for (int j = 0;j < country.size();j++){
				if (i == j) continue;
				else{
					if (country[i].name == country[j].name){
						for (int k = 0;k < country[j].animal.size();k++) 
							country[i].animal.push_back(country[j].animal[k]);
						it = country.begin() + j;
						country.erase(it);
					}
				}
			}
		}

		vector<Animal>::iterator itr;
		for (int i = 0;i < country.size();i++){
			for (int j = 0;j < country[i].animal.size();j++){
				for (int k = 0;k < country[i].animal.size();k++){
					if (k == j) continue;
					else{
						if (country[i].animal[j].name == country[i].animal[k].name){
							itr = country[i].animal.begin() + k;
							country[i].animal.erase(itr);
						}
					}
				}
			}
		}
		//сортируем по названию стран
		vector<Country> c = country;
		Country tmp;
		for (int i = 1;i < country.size();i++){
			for (int j = 0;j < country.size() - i;j++){
				if (strcmp(country[j].name.c_str(), country[j + 1].name.c_str()) > 0){
					tmp = country[j];
					country[j] = country[j + 1];
					country[j + 1] = tmp;
				}
			}
		}
		cout << endl << setw(20) << right << "Страна" << setw(50) << right << "Животные, обитающие в стране";
		cout << endl << "======================================================================";
		//выводим сортированный вектор
		for (int i = 0;i < country.size();i++){
			cout << endl << setw(20) << right << country[i].name << " ";
			for (int j = 0;j < country[i].animal.size();j++){
				cout << setw(40) << right << country[i].animal[j].name << endl;
				for (int k = 0;k < 22;k++) cout << " ";
			}
			cout << endl << "______________________________________________________________________";
		}
		country = c;
		break;
		   }
	}
	

}

//Вывод меню при нажатии "6"
void printAnimalsSortTypeMenu(){
	cout << endl;
	cout << "===================================================" << endl;
	cout << "Выберите тип сортировки:" << endl;
	cout << "1)Вывести животных, численность которых меньше N" << endl;
	cout << "2)Вывести животных, численность которых больше N" << endl;
	cout << "3)Вывод животных с сортировкой по названию" << endl;
	cout << "4)Вывод животных с сортировкой по виду" << endl;
	cout << "5)Вывод животных с сортировкой по цвету" << endl;
	cout << "6)Вывод стран обитания с обитающими в них животными (отсортировать по странам обитания)" << endl;
	cout << "===================================================" << endl;
	
	
	int num;
	do {
		cout << endl << ">> ";
		cin >> num;
		fflush(stdin);
	}while(num < 1 || num > 6);
	selectSort(num);
}

//Функция открытия файла с данными
//type = 0 0- чтение, type = 1 - запись
int openDBFile(int type){
	if (type == 0){
		myFile.open("data.txt", ios::in);
	}
	else if (type == 1){
		myFile.open("data.txt", ios::out);
	}
	if (myFile.is_open()){
		return 0;
	}
	else{
		return -1;
	}

}
//закрываем поток
void closeDBFile(){
	myFile.close();
}

//Функция добавления животного
void addNote(){
	Animal a;
	cout << endl << "Введите название животного: ";
	string s;
	cin >> s;
	a.name = s;
	fflush(stdin);
	cout << endl << "Введите вид животного: ";
	cin >> s;
	a.kind = s;
	fflush(stdin);
	cout << endl << "Введите численность данного животного: ";
	int amount;
	cin >> amount;
	a.amount = amount;
	fflush(stdin);
	cout << endl << "Введите цвет данного животного: ";
	cin >> s;
	a.color = s;
	fflush(stdin);
	cout << endl << "Введите страны обитания данного животного (через пробел): ";
	getline(cin, s);
	char *str = new char[s.size() + 1]();
	int i = 0;
	strcpy(str, s.c_str());
	char *p = strtok(str, " ");
	while(p != NULL){
		a.countryLiving.push_back(p);
		p = strtok(NULL, " ");
	}
	delete[] str;
	fflush(stdin);
	animals.push_back(a);
}

void readDBFile(){
	int res = openDBFile(READ);
	if (res == 0){
		
		string str;
		//считываем построчно весь файл
		while(getline(myFile, str)){
			Animal a;
			char *s = new char[str.size() + 1]();
			char *elem[10];
			strcpy(s, str.c_str());
			//разбиваем на лексемы и форматированно выводим
			char *p = strtok(s, " ");
			int i = 0;
			while(p != NULL){
				elem[i++] = p;
				p = strtok(NULL, " ");
			}
			a.name = elem[0];
			a.kind = elem[1];
			a.amount = atoi(elem[2]);
			a.color = elem[3];
			for (int j = 4;j < i;j++){
				a.countryLiving.push_back(elem[j]);
			}
			animals.push_back(a);
			delete[] s;
			fflush(stdin);
		}
		closeDBFile();
	}
	else{
		cout << "Не удалось открыть файл для чтения..." << endl;
		return;
	}
}



//функция удаления животного по его номеру
void deleteAnimal(){
	if (animals.size() == 0){
		cout << "Нет данных о животных!" << endl;
	}
	else{
		int number;
		do{
			cout << endl << "Введите номер животного, которое вы хотите удалить (от 1 до " << animals.size() << "): ";
			cin >> number;
			fflush(stdin);
		}while(number > animals.size() || number < 1);

		vector<Animal>::iterator it;
		it = animals.begin() + number - 1;
		animals.erase(it);
	}
}

//Функция редактирования животного по его номеру
void editAnimal(){
	if (animals.size() == 0){
		cout << "Нет данных о животных! Сначала добавьте данные!" << endl;
		return;
	}
	else{
		int number;
		do{
			cout << endl << "Введите номер животного, которое вы хотите редактировать (от 1 до " << animals.size() << "): ";
			cin >> number;
			fflush(stdin);
		}while(number > animals.size() || number < 1);
		cout <<"--------------------------------------------------------------------------------------------------------" << endl;

		cout << "Введите новое название животного (если не менять - нажмите Enter): ";
		string s;
		getline(cin, s);
		fflush(stdin);
		if (s != ""){
			animals[number - 1].name = s;
		}

		cout << "Введите новый вид животного (если не менять - нажмите Enter): ";
		getline(cin, s);
		fflush(stdin);
		if (s != ""){
			animals[number - 1].kind = s;
		}

		cout << "Введите численность животного (если не менять - нажмите Enter): ";
		getline(cin, s);
		fflush(stdin);
		if (s != ""){
			int a = atoi(s.c_str());
			animals[number - 1].amount = a;
		}
		cout << "Введите цвет животного (если не менять - нажмите Enter): ";
		getline(cin, s);
		fflush(stdin);
		if (s != ""){
			animals[number - 1].color = s;
		}

		cout << "Введите страны обитания животного через пробел (если не менять - нажмите Enter): ";
		getline(cin, s);
		fflush(stdin);
		if (s != ""){
			char *str = new char[s.size() + 1]();
			char *elem[10];
			strcpy(str, s.c_str());
			//разбиваем на лексемы и форматированно выводим
			char *p = strtok(str, " ");
			int i = 0;
			while(p != NULL){
				elem[i++] = p;
				p = strtok(NULL, " ");
			}
			animals[number - 1].countryLiving.clear();
			for (int j = 0;j < i;j++){
				animals[number - 1].countryLiving.push_back(elem[j]);
			}
			delete[] str;
		}
	}
}


void searchFunction(int type){
	switch(type){
	case 1: {
			cout << endl << "Введите название животного, которое нужно найти: ";
			string s;
			getline(cin, s);
			fflush(stdin);
			for (int i = 0;i < animals.size();i++){
				if (animals[i].name == s){
					cout << endl <<"________________________________________________________________________________________________________" << endl;
					cout << setw(3) << right << (i + 1) << ")";
					cout << setw(20) << right << animals[i].name;
					cout << setw(20) << right << animals[i].kind;
					cout << setw(20) << right << animals[i].amount;
					cout << setw(20) << right << animals[i].color;
					for (int j = 0;j < animals[i].countryLiving.size();j++){
						cout << setw(20) << right << animals[i].countryLiving[j] << endl;
						for (int k = 0;k < 84;k++) cout << " ";
					}
					cout << endl <<"________________________________________________________________________________________________________" << endl;
				}
			}
			break;
		};
		case 2:{
			cout << endl << "Введите вид животного, которое нужно найти: ";
			string s;
			getline(cin, s);
			fflush(stdin);
			for (int i = 0;i < animals.size();i++){
				if (animals[i].kind == s){
					cout << endl <<"________________________________________________________________________________________________________" << endl;
					cout << setw(3) << right << (i + 1) << ")";
					cout << setw(20) << right << animals[i].name;
					cout << setw(20) << right << animals[i].kind;
					cout << setw(20) << right << animals[i].amount;
					cout << setw(20) << right << animals[i].color;
					for (int j = 0;j < animals[i].countryLiving.size();j++){
						cout << setw(20) << right << animals[i].countryLiving[j] << endl;
						for (int k = 0;k < 84;k++) cout << " ";
					}
					cout << endl <<"________________________________________________________________________________________________________" << endl;
				}
			}
			break;
		};
		case 3:{
			cout << endl << "Введите цвет животного, которое нужно найти: ";
			string s;
			getline(cin, s);
			fflush(stdin);
			for (int i = 0;i < animals.size();i++){
				if (animals[i].color == s){
					cout << endl <<"________________________________________________________________________________________________________" << endl;
					cout << setw(3) << right << (i + 1) << ")";
					cout << setw(20) << right << animals[i].name;
					cout << setw(20) << right << animals[i].kind;
					cout << setw(20) << right << animals[i].amount;
					cout << setw(20) << right << animals[i].color;
					for (int j = 0;j < animals[i].countryLiving.size();j++){
						cout << setw(20) << right << animals[i].countryLiving[j] << endl;
						for (int k = 0;k < 84;k++) cout << " ";
					}
					cout << endl <<"________________________________________________________________________________________________________" << endl;
				}
			}
			break;
		};
		case 4:{
			cout << endl << "Введите страну обитания животного, которое нужно найти: ";
			string s;
			getline(cin, s);
			fflush(stdin);
			for (int i = 0;i < animals.size();i++){
				for (int j = 0;j < animals[i].countryLiving.size();j++){
					if (animals[i].countryLiving[j] == s){
						cout << endl <<"________________________________________________________________________________________________________" << endl;
						cout << setw(3) << right << (i + 1) << ")";
						cout << setw(20) << right << animals[i].name;
						cout << setw(20) << right << animals[i].kind;
						cout << setw(20) << right << animals[i].amount;
						cout << setw(20) << right << animals[i].color;
						for (int j = 0;j < animals[i].countryLiving.size();j++){
							cout << setw(20) << right << animals[i].countryLiving[j] << endl;
							for (int k = 0;k < 84;k++) cout << " ";
						}
						cout << endl <<"________________________________________________________________________________________________________" << endl;
					}
				}
			}
			break;
		};
	}
}

//Функция поиска животного
void searchAnimal(){
	if (animals.size() == 0){
		cout << "Нет данных о животных! Сначала добавьте записи" << endl;
		return;
	}
	else{
		cout << "Выберите поле, по которому искать животных:" << endl;
		cout << "1)Название" << endl;
		cout << "2)Вид" << endl;
		cout << "3)Цвет" << endl;
		cout << "4)Страны обитания" << endl;
		int number;
		do{
			cout << ">>";
			cin >> number;
			fflush(stdin);
		}while(number < 1 || number > 4);

		searchFunction(number);
	}
}

//сохранение данных в файл
void saveData(){
	int res = openDBFile(WRITE);
	if (res == 0){
		for (int i = 0;i < animals.size();i++){
			myFile << animals[i].name << " " << animals[i].kind << " " << animals[i].amount << " " << animals[i].color << " ";
			for (int j = 0;j < animals[i].countryLiving.size();j++){
				myFile << animals[i].countryLiving[j] << " ";
			}
			myFile << endl;
		}
		closeDBFile();
		cout << endl << "Данные сохранены!" << endl;
	}
	else{
		cout << "Не удалось открыть файл для записи..." << endl;
		return;
	}
}


//добавить страну обитания животного
void addCountry(){
	if (animals.size() == 0){
		cout << "Нет данных..." << endl;
		return;
	}
	else{
		int num;
		do{
			cout << "Введите номер животного, которому нужно добавить страну обитания (от 1 до " << animals.size() << "): ";
			cin >> num;
			fflush(stdin);
		}while(num > animals.size() || num < 1);

		cout << endl << "Введите страну, которую хотите добавить (через пробел, если несколько): ";
		string s;
		getline(cin, s);
		char *str = new char[s.size() + 1]();
		strcpy(str, s.c_str());
		char *p = strtok(str, " ");
		while(p != NULL){
			animals[num - 1].countryLiving.push_back(p);
			p = strtok(NULL, " ");
		}

		delete[] str;
	}
}

//Редактировать страну обитания животного
void editCountry(){
	if (animals.size() == 0){
		cout << "Нет данных..." << endl;
		return;
	}
	else{
		
		int num;
		do{
			cout << "Введите номер животного, страны обитания которого нужно редактировать (от 1 до " << animals.size() << "): ";
			cin >> num;
			fflush(stdin);
		}while(num > animals.size() || num < 1);
		if (animals[num - 1].countryLiving.size() == 0){
			cout << endl << "У данного животного отсутствуют страны обитания..." << endl;
			return;
		}
		bool flag = false;
		string s;
		int index = 0;
		do{
			cout << endl << "Введите страну, которую хотите редактировать: ";
			
			getline(cin, s);
			fflush(stdin);
						
			for (int i = 0;i < animals[num - 1].countryLiving.size();i++){
				if (animals[num - 1].countryLiving[i] == s){
					flag = true;
					index = i;
					break;
				}
			}
		}while(!flag);

		cout << endl << "Введите страну вместо \'" << s << "\': ";
		getline(cin, s);
		
		animals[num - 1].countryLiving[index] = s;

		cout << endl << "Готово!" << endl;
		
	}
}

//Удалить страну обитания животного
void deleteCountry(){
	if (animals.size() == 0){
		cout << "Нет данных..." << endl;
		return;
	}
	else{
		
		int num;
		do{
			cout << "Введите номер животного, страны обитания которого нужно редактировать (от 1 до " << animals.size() << "): ";
			cin >> num;
			fflush(stdin);
		}while(num > animals.size() || num < 1);
		if (animals[num - 1].countryLiving.size() == 0){
			cout << endl << "У данного животного отсутствуют страны обитания..." << endl;
			return;
		}
		bool flag = false;
		string s;
		int index = 0;
		do{
			cout << endl << "Введите страну, которую хотите удалить: ";
			
			getline(cin, s);
			fflush(stdin);
						
			for (int i = 0;i < animals[num - 1].countryLiving.size();i++){
				if (animals[num - 1].countryLiving[i] == s){
					flag = true;
					index = i;
					break;
				}
			}
		}while(!flag);

		vector<string>::iterator it;
		it = animals[num - 1].countryLiving.begin() + index;

		animals[num - 1].countryLiving.erase(it);
		
		cout << endl << "Готово!" << endl;
		
	}
}

int main(){
	//Поддержка русского языка
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	readDBFile();
	
	while(1){
		int num = 0;
		printMenu();
		cin >> num;
		fflush(stdin);
		if (cin.good()){
			switch(num){
				case 1:{
					printAnimals();
					break;
						}
				case 2:{
					addNote();
					break;
						}
				case 3:{
					deleteAnimal();
					break;
						}
				case 4:{
					editAnimal();
					break;
						}
				case 5:{
					addCountry();
					break;
						}
				case 6:{
					deleteCountry();
					break;
						}

				case 7:{
					editCountry();
					break;
						}
				case 8:{
					searchAnimal();
					break;
						}
				case 9:{
					printAnimalsSortTypeMenu();
					break;
						}
				case 10:{
					system("cls");
					break;
						}
				case 11:{
					saveData();
					break;
						}
				case 12:{
					exit(0);
				}
			}
			
		}
		else{
			cout << endl << "Некорректный ввод!" << endl;
		}
	}
	

	
	cout << endl;
	system("pause");
	return 0;
}