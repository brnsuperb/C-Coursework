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

fstream myFile;	//����� ��� ���������� ������ � �����

struct Animal{
	string name;		//��������
	string kind;		//���
	string color;		//���� �������
	unsigned amount;	//�����������
	vector<string> countryLiving;	//������ �������� ���������
};

struct Country{
	string name;
	vector<Animal> animal;
};

vector<Animal> animals;

vector<Country> country;

//������� ������ ����
void printMenu(){
	cout << endl;
	cout << "===================================================" << endl;
	cout << "������� ����:" << endl;
	cout << "1)������� ���������� � ���� ��������" << endl;
	cout << "2)�������� ��������" << endl;
	cout << "3)������� ��������" << endl;
	cout << "4)������������� ���������� � ��������" << endl;
	cout << "5)�������� ������ �������� ���������" << endl;
	cout << "6)������� ������ �������� ���������" << endl;
	cout << "7)������������� ������ �������� ���������" << endl;
	cout << "8)����� ��������" << endl;
	cout << "9)����� ������ � �������� � ������� ���� ����������" << endl;
	cout << "10)�������� �����" << endl;
	cout << "11)��������� ������" << endl;
	cout << "12)�����" << endl;
	cout << "===================================================" << endl;
	cout << "> ";
}

//������� ������ ���� ��������
void printAnimals(){
	if (animals.size() > 0){
		cout << setw(24) << right << "��������";
		cout << setw(20) << right << "���";
		cout << setw(20) << right << "�����������";
		cout << setw(20) << right << "���� �������";
		cout << setw(20) << right << "������ ��������" << endl;
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
		cout << "���� � ������� ����..." << endl;
	}	
}

void selectSort(int select){
	switch(select){
	case 1:{
		int n;
		do{
			cout << endl << "������� �������� N: ";
			cin >> n;
			fflush(stdin);
		}while(n < 1);
		cout << setw(24) << right << "��������";
		cout << setw(20) << right << "���";
		cout << setw(20) << right << "�����������";
		cout << setw(20) << right << "���� �������";
		cout << setw(20) << right << "������ ��������" << endl;
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
			cout << endl << "������� �������� N: ";
			cin >> n;
			fflush(stdin);
		}while(n < 1);

		cout << setw(24) << right << "��������";
		cout << setw(20) << right << "���";
		cout << setw(20) << right << "�����������";
		cout << setw(20) << right << "���� �������";
		cout << setw(20) << right << "������ ��������" << endl;
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
		//�������� ��� ������ ��������
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

		//������� ���������� �������� �������
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
		//��������� �� �������� �����
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
		cout << endl << setw(20) << right << "������" << setw(50) << right << "��������, ��������� � ������";
		cout << endl << "======================================================================";
		//������� ������������� ������
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

//����� ���� ��� ������� "6"
void printAnimalsSortTypeMenu(){
	cout << endl;
	cout << "===================================================" << endl;
	cout << "�������� ��� ����������:" << endl;
	cout << "1)������� ��������, ����������� ������� ������ N" << endl;
	cout << "2)������� ��������, ����������� ������� ������ N" << endl;
	cout << "3)����� �������� � ����������� �� ��������" << endl;
	cout << "4)����� �������� � ����������� �� ����" << endl;
	cout << "5)����� �������� � ����������� �� �����" << endl;
	cout << "6)����� ����� �������� � ���������� � ��� ��������� (������������� �� ������� ��������)" << endl;
	cout << "===================================================" << endl;
	
	
	int num;
	do {
		cout << endl << ">> ";
		cin >> num;
		fflush(stdin);
	}while(num < 1 || num > 6);
	selectSort(num);
}

//������� �������� ����� � �������
//type = 0 0- ������, type = 1 - ������
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
//��������� �����
void closeDBFile(){
	myFile.close();
}

//������� ���������� ���������
void addNote(){
	Animal a;
	cout << endl << "������� �������� ���������: ";
	string s;
	cin >> s;
	a.name = s;
	fflush(stdin);
	cout << endl << "������� ��� ���������: ";
	cin >> s;
	a.kind = s;
	fflush(stdin);
	cout << endl << "������� ����������� ������� ���������: ";
	int amount;
	cin >> amount;
	a.amount = amount;
	fflush(stdin);
	cout << endl << "������� ���� ������� ���������: ";
	cin >> s;
	a.color = s;
	fflush(stdin);
	cout << endl << "������� ������ �������� ������� ��������� (����� ������): ";
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
		//��������� ��������� ���� ����
		while(getline(myFile, str)){
			Animal a;
			char *s = new char[str.size() + 1]();
			char *elem[10];
			strcpy(s, str.c_str());
			//��������� �� ������� � �������������� �������
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
		cout << "�� ������� ������� ���� ��� ������..." << endl;
		return;
	}
}



//������� �������� ��������� �� ��� ������
void deleteAnimal(){
	if (animals.size() == 0){
		cout << "��� ������ � ��������!" << endl;
	}
	else{
		int number;
		do{
			cout << endl << "������� ����� ���������, ������� �� ������ ������� (�� 1 �� " << animals.size() << "): ";
			cin >> number;
			fflush(stdin);
		}while(number > animals.size() || number < 1);

		vector<Animal>::iterator it;
		it = animals.begin() + number - 1;
		animals.erase(it);
	}
}

//������� �������������� ��������� �� ��� ������
void editAnimal(){
	if (animals.size() == 0){
		cout << "��� ������ � ��������! ������� �������� ������!" << endl;
		return;
	}
	else{
		int number;
		do{
			cout << endl << "������� ����� ���������, ������� �� ������ ������������� (�� 1 �� " << animals.size() << "): ";
			cin >> number;
			fflush(stdin);
		}while(number > animals.size() || number < 1);
		cout <<"--------------------------------------------------------------------------------------------------------" << endl;

		cout << "������� ����� �������� ��������� (���� �� ������ - ������� Enter): ";
		string s;
		getline(cin, s);
		fflush(stdin);
		if (s != ""){
			animals[number - 1].name = s;
		}

		cout << "������� ����� ��� ��������� (���� �� ������ - ������� Enter): ";
		getline(cin, s);
		fflush(stdin);
		if (s != ""){
			animals[number - 1].kind = s;
		}

		cout << "������� ����������� ��������� (���� �� ������ - ������� Enter): ";
		getline(cin, s);
		fflush(stdin);
		if (s != ""){
			int a = atoi(s.c_str());
			animals[number - 1].amount = a;
		}
		cout << "������� ���� ��������� (���� �� ������ - ������� Enter): ";
		getline(cin, s);
		fflush(stdin);
		if (s != ""){
			animals[number - 1].color = s;
		}

		cout << "������� ������ �������� ��������� ����� ������ (���� �� ������ - ������� Enter): ";
		getline(cin, s);
		fflush(stdin);
		if (s != ""){
			char *str = new char[s.size() + 1]();
			char *elem[10];
			strcpy(str, s.c_str());
			//��������� �� ������� � �������������� �������
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
			cout << endl << "������� �������� ���������, ������� ����� �����: ";
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
			cout << endl << "������� ��� ���������, ������� ����� �����: ";
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
			cout << endl << "������� ���� ���������, ������� ����� �����: ";
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
			cout << endl << "������� ������ �������� ���������, ������� ����� �����: ";
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

//������� ������ ���������
void searchAnimal(){
	if (animals.size() == 0){
		cout << "��� ������ � ��������! ������� �������� ������" << endl;
		return;
	}
	else{
		cout << "�������� ����, �� �������� ������ ��������:" << endl;
		cout << "1)��������" << endl;
		cout << "2)���" << endl;
		cout << "3)����" << endl;
		cout << "4)������ ��������" << endl;
		int number;
		do{
			cout << ">>";
			cin >> number;
			fflush(stdin);
		}while(number < 1 || number > 4);

		searchFunction(number);
	}
}

//���������� ������ � ����
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
		cout << endl << "������ ���������!" << endl;
	}
	else{
		cout << "�� ������� ������� ���� ��� ������..." << endl;
		return;
	}
}


//�������� ������ �������� ���������
void addCountry(){
	if (animals.size() == 0){
		cout << "��� ������..." << endl;
		return;
	}
	else{
		int num;
		do{
			cout << "������� ����� ���������, �������� ����� �������� ������ �������� (�� 1 �� " << animals.size() << "): ";
			cin >> num;
			fflush(stdin);
		}while(num > animals.size() || num < 1);

		cout << endl << "������� ������, ������� ������ �������� (����� ������, ���� ���������): ";
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

//������������� ������ �������� ���������
void editCountry(){
	if (animals.size() == 0){
		cout << "��� ������..." << endl;
		return;
	}
	else{
		
		int num;
		do{
			cout << "������� ����� ���������, ������ �������� �������� ����� ������������� (�� 1 �� " << animals.size() << "): ";
			cin >> num;
			fflush(stdin);
		}while(num > animals.size() || num < 1);
		if (animals[num - 1].countryLiving.size() == 0){
			cout << endl << "� ������� ��������� ����������� ������ ��������..." << endl;
			return;
		}
		bool flag = false;
		string s;
		int index = 0;
		do{
			cout << endl << "������� ������, ������� ������ �������������: ";
			
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

		cout << endl << "������� ������ ������ \'" << s << "\': ";
		getline(cin, s);
		
		animals[num - 1].countryLiving[index] = s;

		cout << endl << "������!" << endl;
		
	}
}

//������� ������ �������� ���������
void deleteCountry(){
	if (animals.size() == 0){
		cout << "��� ������..." << endl;
		return;
	}
	else{
		
		int num;
		do{
			cout << "������� ����� ���������, ������ �������� �������� ����� ������������� (�� 1 �� " << animals.size() << "): ";
			cin >> num;
			fflush(stdin);
		}while(num > animals.size() || num < 1);
		if (animals[num - 1].countryLiving.size() == 0){
			cout << endl << "� ������� ��������� ����������� ������ ��������..." << endl;
			return;
		}
		bool flag = false;
		string s;
		int index = 0;
		do{
			cout << endl << "������� ������, ������� ������ �������: ";
			
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
		
		cout << endl << "������!" << endl;
		
	}
}

int main(){
	//��������� �������� �����
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
			cout << endl << "������������ ����!" << endl;
		}
	}
	

	
	cout << endl;
	system("pause");
	return 0;
}