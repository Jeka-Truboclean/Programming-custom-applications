#include <iostream>
using namespace std;

struct Utug {
    char firm[100];
    char model[100];
    char color[100];
    int min_temp;
    int max_temp;
    bool vapor;
    int power;
};

struct Animal {
    char name[100];
    char classs[100];
    char clicka[100];
};

void full(Animal& animal) {
    cout << "Enter the animal - ";
    cin >> animal.name;
    cout << "Enter the class of the animal - ";
    cin >> animal.classs;
    cout << "Enter the name of the animal - ";
    cin >> animal.clicka;
}

void printtt(const Animal& animal) {
    cout << "Animal: " << animal.name << endl;
    cout << "Class: " << animal.classs << endl;
    cout << "Name: " << animal.clicka << endl;
}

int main() {
    //No 1
    Utug utug = { "PHILIPS", "DST7510/80", "blue gold", 120, 220, true, 3200 };
    cout << "Firm: " << utug.firm << endl;
    cout << "Model: " << utug.model << endl;
    cout << "Color: " << utug.color << endl;
    cout << "Min temperature: " << utug.min_temp << endl;
    cout << "Max temperature: " << utug.max_temp << endl;
    cout << "Vapor: " << (utug.vapor ? "Yes" : "No") << endl;
    cout << "Power: " << utug.power << " W" << endl;

    //Mo 2
    Animal myAnimal;
    full(myAnimal);
    printtt(myAnimal);
    return 0;
}