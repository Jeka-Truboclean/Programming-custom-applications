#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

//	Задаём размеры для полей структуры для избежания "магических" чисел
const int TITLE_LENGTH = 100, AUTHOR_LENGTH = 50, PUBLISHER_LENGTH = 40, GENRE_LENGTH = 50;

struct Book {
	char title[TITLE_LENGTH];
	char author[AUTHOR_LENGTH];
	char publisher[PUBLISHER_LENGTH];
	char genre[GENRE_LENGTH];
};

/*	создаём функцию для печати меню, так как оно нам нужно будет только в 3 случаях: при запуске программы,
	при выходе из меню редактирования книги и после очистки экрана	*/
void printMenu();

void searchByAuthor(Book library[], int size); // Олег

void searchByTitle(Book library[], int size); // Олег

void sortByTitle(Book library[], int size); // Максим

void sortByAuthor(Book library[], int size); // Максим

void sortByPublisher(Book library[], int size); // Жека

void printAllBooks(Book library[], unsigned int size); // Жека

void printBook(Book library[], unsigned int bookIndex); // Жека

void editBook(Book library[]); // Назар

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const unsigned int SIZE = 5;

	Book Library[SIZE] = {
		{ "Скотный двор", "Jeorge Orwille", "Harvill Secker", "Сатира" },
		{ "Гарри Поттер и философский камень", "Джоан Роулинг", "Bloomsbury Publishing", "Фэнтези" },
		{ "Песнь льда и огня", "Jeorge Orwille", "Bantam Books", "Фэнтези" },
		{ "Война и мир", "Лев Толстой", "Русский вестник", "Роман" },
		{ "Приключения Шерлока Холмса", "Артур Конан Дойл", "George Newnes", "Детектив" }
	};

	unsigned int userChoice;

	printMenu();
	do
	{
		cout << "\nВыберите действие: ";

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
			cout << "Указано неверное действие! Повторите попытку.\n";
			break;
		}

	} while (userChoice != 0);
	return 0;
}

void editBook(Book library[]) {
	unsigned int bookIndex, fieldIndex;
	//	создаём флаг для проверки правильности ввода номера книги, чтобы не длинное условие в цикле и if
	bool flag;
	do
	{
		cout << "\nВыберите книгу для редактирования (1-5): ";
		cin >> bookIndex;
		if (!cin)
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
		flag = (bookIndex >= 1 && bookIndex <= 5) ? true : false;
		if (!flag)
		{
			cout << "Книга не найдена! Повторите попытку.\n";
		}
	} while (!flag);
	//	вычитаем от введеного числа 1, потому что у нас книги начинаются с 0
	bookIndex -= 1;
	system("cls");
	cout << "Текущая информация о книге:\n";
	printBook(library, bookIndex);
	flag = false;
	do
	{
		cout << "\n\nВыберите поле для редактирования:\n1 - Название\n2 - Автор\n3 - Издательство\n4 - Жанр\n5 - Назад\nВвод: ";
		cin >> fieldIndex;
		if (!cin)
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
		flag = (fieldIndex >= 1 && fieldIndex <= 5) ? true : false;
		if (!flag)
		{
			cout << "Введено неверное действие! Повторите попытку.\n";
		}
	} while (!flag);
	// игнорируем символ переноса строки с прошлого ввода
	cin.ignore();
	switch (fieldIndex) {
	case 1:
		cout << "Введите название: ";
		cin.getline(library[bookIndex].title, TITLE_LENGTH);
		break;
	case 2:
		cout << "Введите автора: ";
		cin.getline(library[bookIndex].author, AUTHOR_LENGTH);
		break;
	case 3:
		cout << "Введите издательство: ";
		cin.getline(library[bookIndex].publisher, PUBLISHER_LENGTH);
		break;
	case 4:
		cout << "Введите жанр: ";
		cin.getline(library[bookIndex].genre, GENRE_LENGTH);
		break;
	case 5:
		system("cls");
		return;
	}
	cout << "\nКнига успешно изменена!\nДля продолжения нажмите любую клавишу...";
	_getch();
	system("cls");
}

void printBook(Book library[], unsigned int bookIndex) {
	cout << "\nНазвание: " << library[bookIndex].title;
	cout << "\nАвтор: " << library[bookIndex].author;
	cout << "\nИздательство: " << library[bookIndex].publisher;
	cout << "\nЖанр: " << library[bookIndex].genre << '\n';
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
	cout << "Введите автора для поиска: ";
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
		cout << "\nАвтор не найден!\n";
	}
}

void searchByTitle(Book library[], int size) {
	setlocale(LC_ALL, "");
	char title[50];
	cout << "Введите название для поиска: ";
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
		cout << "\nКнига не найдена!\n";
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
	cout << endl << "Список книг отсортирован по названию." << endl;
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
	cout << endl << "Список книг отсортирован по автору." << endl;
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
	cout << endl << "Список книг отсортирован по издательству." << endl;
}

void printMenu() {
	cout << "\tДобро пожаловать в библиотеку!\n\n";
	cout << "Выберите действие:\n1 - Редактировать книгу\n2 - Печать всех книг\n3 - Поиск книг по автору\n4 - Поиск книг по названию\n"
		<< "5 - Сортировка массива по названию книг\n6 - Сортировка массива по автору\n7 - Сортировка массива по издательству\n8 - Очистить экран\n0 - Выход";
}