#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
#include <algorithm>


/*Array97 Дан цілочисельний масив розміру N. Видалити з масиву всі однакові елементи,
залишивши їх останні входження.*/

/*Matrix34. Дана цілочисельна матриця розміру M × N. Знайти номер останньої з її
рядків, що містять тільки парні числа. Якщо таких рядків немає, то вивести
0.*/

/*Sort#15 Шейкерна Зростання Цілий*/

#define N 20
#define F 100

using namespace std;

void array97();
void get_nums();
bool checkfiles(string in, string out);
void searchPair(int*& arr, int n, string output);


void matrix34();
bool checkfile(string in);
void fillArray(string f_in, int**& arr, const int rows, const int cols);
void searchPairRows(int** arr, const int rows, const int columns, string f_out);

void sort15();
void choiceSort(int*&arr , int n, string in);

int main() {
	srand(time(NULL));

	int choice = 0;

	while (choice != 4) {

		cout << "Choose the task! : "
			"\n1.Array#97"
			"\n2.Matrix#34"
			"\n3.Sort#15"
			"\n4.Exit" << endl;

		cin >> choice;

		switch (choice) {
		case 1: {
			array97();		//Задание array97
			break;
		}
		case 2: {
			matrix34();		// Задание matrix34
			break;
		}
		case 3: {
			sort15();		// Задание sort15
			break;
		}
		case 4: {
			cout << "Program is end!";
			break;
		}
		default: {
			cout << "Wrong one, try again";
		}
		}
	}
}

// Задание Array97

void array97() {

	int n = 0, startPos = 0, size = 0;

	get_nums();
}


void get_nums() {

	string filename_in = "array_in_97.txt";
	string filename_out = "array_out_97.txt";

	ifstream f;

	if (checkfiles(filename_in, filename_out)) {

		f.open(filename_in);

		string lenght;

		getline(f, lenght);
		int size = stoi(lenght);

		int* arr = new int(size);
		int count = 0;

		ifstream porn;
		istringstream iss(filename_in);

		porn.open(filename_in);

		while (count < size && f >> arr[count]) {
			count++;
		}

		for (int i = 0; i < count; i++) {
			cout << "arr[" << i << "] = " << arr[i] << endl;
		}

		searchPair(arr, count, filename_out);

	}
	else {
		cout << "Помилка, файл не знайдено";
	}
}


bool checkfiles(string in, string out) {

	ifstream f_in;
	ifstream f_out;

	f_in.open(in);
	f_out.open(out);

	if (!f_in.is_open() || !f_out.is_open()) {
		f_in.close();
		f_out.close();
		return 0;
	}
	else if (f_in.is_open() && f_out.is_open()) {
		return 1;
	}
	else {
		return 0;
	}
}

void searchPair(int*& arr, int n, string filename_out) {
	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] == arr[j]) {
				arr[i] = 0;
			}
		}
	}
	
	ofstream outp(filename_out);
	if (!outp)
	{
		cerr << "Неможливо вiдкрити файл!" << endl;
		exit(1);
	}
	else {
		outp << "Новий масив: " << endl;
		for (int i = 0; i < n; i++) {
			outp << arr[i] << " ";
		}
	}
}
// Конец Array97

// Задание Matrix34

void matrix34() {
	int n = 0, startPos = 0, rows = 0, cols = 0, skip = 0;
	string filename;

	string filename_in = "matrix_in_34.txt";

	ifstream f;

	if (checkfile(filename_in)) {
		f.open(filename_in);

		string size;

		getline(f, size);

		for (int i = 0; i < size.size(); i++) {
			if (size[i] == ' ') {
				skip = i;
			}
		}
		rows = stoi(size);
		if (rows > 20) {
			cout << "Рядків не може бути більше за 20" << endl;
			exit(0);
		}
		else {
			for (int i = 0; i < size.size() - skip; i++) {
				size[i] = size[skip + i];
				size[skip + i] = 0;
			}

			cols = stoi(size);
			if (cols > 20) {
				cout << "Колон не може бути більше за 20" << endl;
				exit(0);
			}
			else {
				cout << "ROWS = " << rows << endl << "COLS = " << cols << endl;
				int** arr = new int* [rows];
				for (int i = 0; i < rows; i++) {
					arr[i] = new int[cols];
				}
				fillArray(filename_in, arr, rows, cols);
				searchPairRows(arr, rows, cols, filename_in);
			}
		}
	}
	else {
		cout << "Помилка, файл не знайдено";
	}
}

void fillArray(string f_in, int**& arr, const int rows, const int cols) {
	string out;
	float num = 0;
	int numRows = 0, numCols = 0;

	ifstream f;

	istringstream iss(out);
	f.open(f_in);

	std::getline(f, out);

	while (getline(f, out) && numRows < rows) {
		istringstream iss(out);
		numCols = 0;

		while (iss >> num && numCols < cols) {
			arr[numRows][numCols] = num;
			numCols++;
		}
		numRows++;
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}

bool checkfile(string in) {

	ifstream f_in;
	f_in.open(in);

	if (f_in.is_open()) {
		return 1;
	}
	else {
		return 0;
	}
}

void searchPairRows(int** arr, const int rows, const int columns, string f_out) {
	int* second = new int[rows];
	int count = 0, temp = -1, newSize = 0;

	for (int i = 0; i < rows; i++) {
		count = 0;
		for (int j = 0; j < columns; j++) {
			if (arr[i][j] % 2 == 0) {
				count++;
				if (count == columns) {
					temp = i;
				}
			}
			else {

			}

		}
	}

	ofstream outp;
	outp.open(f_out, ios::app);

	if (!outp)
	{
		cerr << "Неможливо вiдкрити файл!" << std::endl;
		exit(1);
	}
	else {
		if (temp != -1) {
			outp << "\nРядок #" << temp << " має усі парні числа";
		}
		else if (temp == -1) {
			outp << "У цьому масиві немає жодного рядка з парними числами";
		}
	}
}

// Задание Sort15

void sort15() {

	int* arr = new int[N];
	string filename;

	string filename_in = "sort_in_15.txt";

	ifstream f;
	istringstream iss(filename_in);

	int count = 0;

	if (checkfile(filename_in)) {
		f.open(filename_in);

		while (count < N && f >> arr[count]) {
			count++;
		}

		for (int i = 0; i < count; i++) {
			cout << arr[i] << " ";
		}

		cout << "\n" << count ;

		choiceSort(arr, count, filename_in);
	}
	else {
		cout << "Помилка, файл не знайдено";
	}
}

void choiceSort(int*& arr, int n, string f_in)
{
	int leftMark = 1;
	int rightMark = n - 1;
	while (leftMark <= rightMark)
	{
		for (int i = rightMark; i >= leftMark; i--)
			if (arr[i - 1] > arr[i]) {
				swap(arr[i - 1], arr[i]);
			}
		leftMark++;

		for (int i = leftMark; i <= rightMark; i++)
			if (arr[i - 1] > arr[i]) {
				swap(arr[i], arr[i - 1]);
			}
		rightMark--;
		cout << "\nIteration: " << leftMark - 1; // просмотр количества итераций
	}

	cout << "\n";

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
		ofstream outp;
		outp.open(f_in, ios::app);

		if (!outp)
		{
			cerr << "Неможливо вiдкрити файл!" << std::endl;
			exit(1);
		}
		else {
			outp << "\n";
			for (int i = 0; i < n; i++) {
				outp << arr[i] << " ";
			}
		}
}

// Конец Sort15

// Конец