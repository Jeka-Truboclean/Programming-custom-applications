#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

//	����� ������� ��� ����� ��������� ��� ��������� "����������" �����
const int TITLE_LENGTH = 100, AUTHOR_LENGTH = 50, PUBLISHER_LENGTH = 40, GENRE_LENGTH = 50;

struct Book {
	char title[TITLE_LENGTH];
	char author[AUTHOR_LENGTH];
	char publisher[PUBLISHER_LENGTH];
	char genre[GENRE_LENGTH];
};

/*	������ ������� ��� ������ ����, ��� ��� ��� ��� ����� ����� ������ � 3 �������: ��� ������� ���������,
	��� ������ �� ���� �������������� ����� � ����� ������� ������	*/
void printMenu();

void searchByAuthor(Book library[], int size); // ����

void searchByTitle(Book library[], int size); // ����

void sortByTitle(Book library[], int size); // ������

void sortByAuthor(Book library[], int size); // ������

void sortByPublisher(Book library[], int size); // ����

void printAllBooks(Book library[], unsigned int size); // ����

void printBook(Book library[], unsigned int bookIndex); // ����

void editBook(Book library[]); // �����

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const unsigned int SIZE = 5;

	Book Library[SIZE] = {
		{ "������� ����", "Jeorge Orwille", "Harvill Secker", "������" },
		{ "����� ������ � ����������� ������", "����� �������", "Bloomsbury Publishing", "�������" },
		{ "����� ���� � ����", "Jeorge Orwille", "Bantam Books", "�������" },
		{ "����� � ���", "��� �������", "������� �������", "�����" },
		{ "����������� ������� ������", "����� ����� ����", "George Newnes", "��������" }
	};

	unsigned int userChoice;

	printMenu();
	do
	{
		cout << "\n�������� ��������: ";

		cin >> userChoice;

		switch (userChoice)
		{
		case 1:
			cin.ignore();
			editBook(Library);
			printMenu();
			break;
		case 2:
			printAllBooks(Library, SIZE);
			break;
		case 3:
			cin.ignore();
			searchByAuthor(Library, SIZE);
			break;
		case 4:
			cin.ignore();
			searchByTitle(Library, SIZE);
			break;
		case 5:
			sortByTitle(Library, SIZE);
			break;
		case 6:
			sortByAuthor(Library, SIZE);
			break;
		case 7:
			sortByPublisher(Library, SIZE);
			break;
		case 8:
			system("cls");
			printMenu();
			break;
		case 0:
			return 0;
		default:
			cout << "������� �������� ��������! ��������� �������.\n";
			break;
		}

	} while (userChoice != 0);
	return 0;
}

void editBook(Book library[]) {
	unsigned int bookIndex, fieldIndex;
	//	������ ���� ��� �������� ������������ ����� ������ �����, ����� �� ������� ������� � ����� � if
	bool flag;
	do
	{
		cout << "\n�������� ����� ��� �������������� (1-5): ";
		cin >> bookIndex;
		if (!cin)
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
		flag = (bookIndex >= 1 && bookIndex <= 5) ? true : false;
		if (!flag)
		{
			cout << "����� �� �������! ��������� �������.\n";
		}
	} while (!flag);
	//	�������� �� ��������� ����� 1, ������ ��� � ��� ����� ���������� � 0
	bookIndex -= 1;
	system("cls");
	cout << "������� ���������� � �����:\n";
	printBook(library, bookIndex);
	flag = false;
	do
	{
		cout << "\n\n�������� ���� ��� ��������������:\n1 - ��������\n2 - �����\n3 - ������������\n4 - ����\n5 - �����\n����: ";
		cin >> fieldIndex;
		if (!cin)
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
		flag = (fieldIndex >= 1 && fieldIndex <= 5) ? true : false;
		if (!flag)
		{
			cout << "������� �������� ��������! ��������� �������.\n";
		}
	} while (!flag);
	// ���������� ������ �������� ������ � �������� �����
	cin.ignore();
	switch (fieldIndex) {
	case 1:
		cout << "������� ��������: ";
		cin.getline(library[bookIndex].title, TITLE_LENGTH);
		break;
	case 2:
		cout << "������� ������: ";
		cin.getline(library[bookIndex].author, AUTHOR_LENGTH);
		break;
	case 3:
		cout << "������� ������������: ";
		cin.getline(library[bookIndex].publisher, PUBLISHER_LENGTH);
		break;
	case 4:
		cout << "������� ����: ";
		cin.getline(library[bookIndex].genre, GENRE_LENGTH);
		break;
	case 5:
		system("cls");
		return;
	}
	cout << "\n����� ������� ��������!\n��� ����������� ������� ����� �������...";
	_getch();
	system("cls");
}

void printBook(Book library[], unsigned int bookIndex) {
	cout << "\n��������: " << library[bookIndex].title;
	cout << "\n�����: " << library[bookIndex].author;
	cout << "\n������������: " << library[bookIndex].publisher;
	cout << "\n����: " << library[bookIndex].genre << '\n';
}

void printAllBooks(Book library[], unsigned int size) {
	cout << '\n';
	for (size_t i = 0; i < size; i++)
	{
		cout << library[i].title << " | " << library[i].author << " | " << library[i].publisher << " | " << library[i].genre << endl;
	}
}

void searchByAuthor(Book library[], int size) {
	setlocale(LC_ALL, "");
	char author[50];
	cout << "������� ������ ��� ������: ";
	cin.getline(author, 50);
	bool bookIsFound = false;
	for (size_t i = 0; i < size; i++)
	{
		if (_stricmp(author, library[i].author) == 0)
		{
			printBook(library, i);
			bookIsFound = true;
		}
	}
	if (!bookIsFound)
	{
		cout << "\n����� �� ������!\n";
	}
}

void searchByTitle(Book library[], int size) {
	setlocale(LC_ALL, "");
	char title[50];
	cout << "������� �������� ��� ������: ";
	cin.getline(title, 50);
	bool bookIsFound = false;
	for (size_t i = 0; i < size; i++)
	{
		if (_stricmp(title, library[i].title) == 0)
		{
			printBook(library, i);
			bookIsFound = true;
		}
	}
	if (!bookIsFound)
	{
		cout << "\n����� �� �������!\n";
	}
}

void sortByTitle(Book library[], int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (_stricmp(library[j].title, library[j + 1].title) > 0) {
				Book temp = library[j];
				library[j] = library[j + 1];
				library[j + 1] = temp;
			}
		}
	}
	cout << endl << "������ ���� ������������ �� ��������." << endl;
}

void sortByAuthor(Book library[], int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (_stricmp(library[j].author, library[j + 1].author) > 0) {
				Book temp = library[j];
				library[j] = library[j + 1];
				library[j + 1] = temp;
			}
		}
	}
	cout << endl << "������ ���� ������������ �� ������." << endl;
}

void sortByPublisher(Book library[], int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (_stricmp(library[j].publisher, library[j + 1].publisher) > 0) {
				Book temp = library[j];
				library[j] = library[j + 1];
				library[j + 1] = temp;
			}
		}
	}
	cout << endl << "������ ���� ������������ �� ������������." << endl;
}

void printMenu() {
	cout << "\t����� ���������� � ����������!\n\n";
	cout << "�������� ��������:\n1 - ������������� �����\n2 - ������ ���� ����\n3 - ����� ���� �� ������\n4 - ����� ���� �� ��������\n"
		<< "5 - ���������� ������� �� �������� ����\n6 - ���������� ������� �� ������\n7 - ���������� ������� �� ������������\n8 - �������� �����\n0 - �����";
}