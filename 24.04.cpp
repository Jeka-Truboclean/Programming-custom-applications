#include <iostream>
using namespace std;

struct Student {
	string lastName;
	unsigned int groupNumber : 4;
	bool isFemale : 1;
	bool isProgrammer : 1;
};

int main() {
	Student s1;
	s1.lastName = "Karaman";
	s1.groupNumber = 3;
	s1.isFemale = false;
	s1.isProgrammer = true;
	Student s2;
	s2.lastName = "Kerun";
	s2.groupNumber = 5;
	s2.isFemale = true;
	s2.isProgrammer = false;
	cout << "Student 1: " << s1.lastName << ", group " << s1.groupNumber << ", ";
	cout << (s1.isFemale ? "girl" : "boy") << ", ";
	cout << (s1.isProgrammer ? "programmer" : "designer") << endl;
	cout << "Student 2: " << s2.lastName << ", group " << s2.groupNumber << ", ";
	cout << (s2.isFemale ? "girl" : "boy") << ", ";
	cout << (s2.isProgrammer ? "programmer" : "designer") << endl;
	return 0;
}
