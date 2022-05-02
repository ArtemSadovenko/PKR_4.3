#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void find_5();
void find_3();
void print(string name);
void ignore(fstream& from);
void ignore_3(fstream& from);
void copy(fstream& from, fstream& to);
void full_once(fstream& from, fstream& to);
void read();
void find_2();
void find_more_2();
void delete_2();
bool check(int a, int b, int c, int d, int e);
int menu();
bool check(int math);
void add();
void all_copy(fstream& from, fstream& to);

int main() {
	int cont;
	string name;
	string m = "main.txt";
	string s = "save1.txt";
	do {
		do {
			cont = menu();
		} while (check(cont));

		switch (cont)
		{
		case 1:
			cout << "enter name: "; cin >> name;
			print(name);
			break;
		case 2:
			read();
			print(m);
			break;
		case 3:
			find_5();
			print(s);
			break;
		case 4:
			find_3();
			print(s);
			break;
		case 5:
			find_2();
			print(s);
			break;
		case 6:
			delete_2();
			print(s);
			break;
		case 7:
			find_more_2();
			print(s);
			break;
		case 8:
			add();
			print(m);
			break;
		case 0:
			break;
		default:
			break;
		}

	} while (cont != 0);
}

void print(string name) {
	fstream f(name);
	int n;
	string a;
	char q;
	char t;
	int math;
	int fis;
	int pkr;
	int oop;
	int angl;
	f >> n;
	cout << "---------------------------------------------------------" << endl;
	cout << "|      Student      | Math  | Phisics| PKR | OOP | Angl |" << endl;
	cout << "---------------------------------------------------------" << endl;
	for (int i = 0; i < n; i++) {
		f >> a;
		f >> q;
		f >> t;
		f >> math;
		f >> fis;
		f >> pkr;
		f >> oop;
		f >> angl;
		cout << "|" << setw(13) << a << " " << q << "." << t << ". " << "|"
			<< setw(7) << math << "|" << setw(8) << fis << "|" << setw(5) << pkr << "|"
			<< setw(5) << oop << "|" << setw(6) << angl << "|\n" <<
			"---------------------------------------------------------" << endl;
	}
}

void ignore(fstream& from) {
	string a;
	for (int i = 0; i < 8; i++) {
		from >> a;
	}
}

void copy(fstream& from, fstream& to) {
	string a;
	for (int i = 0; i < 8; i++) {
		from >> a;
		to << a << endl;
	}
}

void find_5() {
	fstream save("save1.txt", ios::trunc | ios::out);
	fstream main("main.txt");
	int* w = new int[100];
	int n;
	int math;
	int fis;
	int pkr;
	int oop;
	int angl;
	int t = 0;

	main >> n;
	int k = 0;
	for (int i = 0; i < n; i++) {
		ignore_3(main);
		main >> math;
		main >> fis;
		main >> pkr;
		main >> oop;
		main >> angl;
		if (math == 5 && fis == 5 && pkr == 5 && oop == 5 && angl == 5 ) {
			w[k] = i;
			k++;
		}
	}

	//for (int i = 0; i < n; i++) {
	//	q[i] = w[i];
	//}
	//main.close();
	//main.open("main.txt");
	//main >> n;
	//save << k  << endl; 
	//for (int i = 0; i < k; i++) {
	//	if (i != w[i]) {
	//		ignore(main);
	//	}
	//	else {
	//		full_once(main, save);
	//	}
	//}
	main.close();
	main.open("main.txt");
	main >> n;
	save << k << endl;
	for (int i = 0; i < n; i++) {
		if (i != w[t]) {
			ignore(main);
		}
		else {
			full_once(main, save);
			t++;
		}
	}
	delete[]w;
}

void ignore_3(fstream& from) {
	string a;
	for (int i = 0; i < 3; i++) {
		from >> a;
	}
}

void full_once(fstream& from, fstream& to) {
	string tmp;
	int tmp_i;
	for (int i = 0; i < 3; i++) {
		from >> tmp;
		to << tmp << endl;
	}
	for (int i = 0; i < 5; i++) {
		from >> tmp_i;
		to << tmp_i << endl;
	}
}

void find_3() {
	fstream save("save1.txt", ios::trunc | ios::out);
	fstream main("main.txt");
	int* w = new int[100];
	int n;
	int math;
	int fis;
	int pkr;
	int oop;
	int angl;
	int t = 0;

	main >> n;
	int k = 0;
	for (int i = 0; i < n; i++) {
		ignore_3(main);
		main >> math;
		main >> fis;
		main >> pkr;
		main >> oop;
		main >> angl;
		if (math == 3 || fis == 3 || pkr == 3 || oop == 3 || angl == 3) {
			w[k] = i;
			k++;
		}
	}

	//for (int i = 0; i < n; i++) {
	//	q[i] = w[i];
	//}
	main.close();
	main.open("main.txt");
	main >> n;
	save << k << endl;
	for (int i = 0; i < n; i++) {
		if (i != w[t]) {
			ignore(main);
		}
		else {
			full_once(main, save);
			t++;
		}
	}
	//while (i < n) {
	//	if (i != w[i]) {
	//		ignore(main);
	//	}
	//	else {
	//		full_once(main, save);
	//	}
	//}
	delete[]w;
}

void read() {
	fstream main("main.txt");
	fstream save2("save2.txt");
	copy(main, save2);
	main.close();
	
	int n;
	string a;
	int b;
	char ch;

	cout << "Enter amount of students: "; cin >> n;
	main.open("main.txt", ios::trunc | ios::out);
	main << n << endl;
	for (int i = 0; i < n; i++) {
		cout << "Last name: ";	 cin >> a;		main << a << endl;
		cout << "Initial 1: ";	cin >> ch;		main << ch << endl;
		cout << "Initial 2: ";	cin >> ch;		main << ch << endl;
		cout << "Enter math: "; cin >> b;		main << b << endl;
		cout << "Enter fis: "; cin >> b;		main << b << endl;
		cout << "Enter pkr: "; cin >> b;		main << b << endl;
		cout << "Enter oop: "; cin >> b;		main << b << endl;
		cout << "Enter angl:"; cin >> b;		main << b << endl;
	}
}

void find_2() {
	fstream save("save1.txt", ios::trunc | ios::out);
	fstream main("main.txt");
	int* w = new int[100];
	int n;
	int math;
	int fis;
	int pkr;
	int oop;
	int angl;
	int t = 0;

	main >> n;
	int k = 0;
	for (int i = 0; i < n; i++) {
		ignore_3(main);
		main >> math;
		main >> fis;
		main >> pkr;
		main >> oop;
		main >> angl;
		if (math == 2 || fis == 2 || pkr == 2 || oop == 2 || angl == 2) {
			w[k] = i;
			k++;
		}
	}

	//for (int i = 0; i < n; i++) {
	//	q[i] = w[i];
	//}
	main.close();
	main.open("main.txt");
	main >> n;
	save << k << endl;
	for (int i = 0; i < n; i++) {
		if (i != w[t]) {
			ignore(main);
		}
		else {
			full_once(main, save);
			t++;
		}
	}
	//while (i < n) {
	//	if (i != w[i]) {
	//		ignore(main);
	//	}
	//	else {
	//		full_once(main, save);
	//	}
	//}
	delete[]w;
}

void delete_2() {

	fstream save("save1.txt", ios::trunc | ios::out);
	fstream main("main.txt");
	int* w = new int[100];
	int n;
	int math;
	int fis;
	int pkr;
	int oop;
	int angl;
	int t = 0;
	int contr = 0;

	main >> n;
	int k = 0;
	for (int i = 0; i < n; i++) {
		ignore_3(main);
		main >> math;
		main >> fis;
		main >> pkr;
		main >> oop;
		main >> angl;

		if (check(math ,fis ,pkr ,oop ,angl) ) {
			w[k] = i;
			k++;
		}
	}

	//for (int i = 0; i < n; i++) {
	//	q[i] = w[i];
	//}
	main.close();
	main.open("main.txt");
	main >> n;
	save << k << endl;
	for (int i = 0; i < n; i++) {
		if (i != w[t]) {
			ignore(main);
		}
		else {
			full_once(main, save);
			t++;
		}
	}
	//while (i < n) {
	//	if (i != w[i]) {
	//		ignore(main);
	//	}
	//	else {
	//		full_once(main, save);
	//	}
	//}
	delete[]w;
}

bool check(int a, int b, int c, int d, int e) {
	int k = 0;
	if (a == 2) {
		k++;
	}
	if (b == 2) {
		k++;
	}
	if (c == 2) {
		k++;
	}
	if (d == 2) {
		k++;
	}
	if (e == 2) {
		k++;
	}
	if (k > 1) {
		return false;
	}
	else {
		return true;
	}
}

int menu() {
	int n;
	cout << "Choose operation:\n print list(1)\n enter list(2)\n find all 5(3)\n "
		<< "find with 3(4)\n find with 2(5)\n delete with more 2(6)\n find with more 2(7)\n add(8)\n exit(0)\n ";
	cin >> n;
	return n;
}

bool check(int math) {
	if (math == 0 || math == 1 || math == 2 || math == 3 || math == 4 || math == 5 || math == 6 || math == 7 || math == 8) {
		return false;
	}
	return true;
}

void add() {
	fstream main("main.txt");
	fstream save("save1.txt", ios::trunc | ios::out);

	int n;
	string a;
	int b;
	char ch;

	main >> n;
	save << n + 1 <<endl;
	for (int i = 0; i < n; i++) {
		full_once(main, save);
	}
	cout << "Last name: ";	 cin >> a;		save << a << endl;
	cout << "Initial 1: ";	cin >> ch;		save << ch << endl;
	cout << "Initial 2: ";	cin >> ch;		save << ch << endl;
	cout << "Enter math: "; cin >> b;		save << b << endl;
	cout << "Enter fis: "; cin >> b;		save << b << endl;
	cout << "Enter pkr: "; cin >> b;		save << b << endl;
	cout << "Enter oop: "; cin >> b;		save << b << endl;
	cout << "Enter angl:"; cin >> b;		save << b << endl;
	main.close();
	save.close();
	main.open("main.txt", ios::trunc | ios::out);
	save.open("save1.txt");
	all_copy(save, main);

}

void all_copy(fstream& from, fstream& to) {
	int n;
	from >> n;
	to << n << endl;
	for (int i = 0; i < n; i++) {
		full_once(from, to);
	}
}

void find_more_2() {
	fstream save("save1.txt", ios::trunc | ios::out);
	fstream main("main.txt");
	int* w = new int[100];
	int n;
	int math;
	int fis;
	int pkr;
	int oop;
	int angl;
	int t = 0;
	int contr = 0;

	main >> n;
	int k = 0;
	for (int i = 0; i < n; i++) {
		ignore_3(main);
		main >> math;
		main >> fis;
		main >> pkr;
		main >> oop;
		main >> angl;

		if (!check(math, fis, pkr, oop, angl)) {
			w[k] = i;
			k++;
		}
	}

	//for (int i = 0; i < n; i++) {
	//	q[i] = w[i];
	//}
	main.close();
	main.open("main.txt");
	main >> n;
	save << k << endl;
	for (int i = 0; i < n; i++) {
		if (i != w[t]) {
			ignore(main);
		}
		else {
			full_once(main, save);
			t++;
		}
	}
	//while (i < n) {
	//	if (i != w[i]) {
	//		ignore(main);
	//	}
	//	else {
	//		full_once(main, save);
	//	}
	//}
	delete[]w;
}