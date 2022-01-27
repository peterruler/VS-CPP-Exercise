// ConsoleApplication1.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//
#include <windows.h> 
#include <iostream>
#include <fstream>
#include <string>
#include "add1.h"
#include "Date.h"
#include "Employee.h"
#include "Date2.h"
#include "Time.h"
#include "Meeting.h"

using namespace std;
/*
using std::cout; 
using std::endl; 
using std::cin; 
using std::string;
using std::ifstream;
using std::ofstream;
*/
bool again() {
    cout << "Again? [y/n] ";
    char answer;
    cin >> answer;
    if (answer == 'y')
        return true;
    else
        return false;
}

void swap(int& left, int& right) {
    const int temp = left;
    left = right;
    right = temp;
}

void printArray(const int[], int);
void printArray(const int a[], int size) {
    for (int i = 0; i < size; i++) {
        cout << a[i] << endl;
    }
}

#define MAX_NAME_LEN 60  // Maximum len of your name can't be more than 60

void getString() {
    char y_name[MAX_NAME_LEN];
    cout << "Enter your name: ";
    cin.getline(y_name, MAX_NAME_LEN);
    cout << "\nEntered name is:\n" << '\n';
    string s = "Foobar";
    cout << y_name << endl << "size of " << s << ": " << s.size() << endl;
}

void findAtPos(string haystack, char needle) {
    int pos = haystack.find(needle);
    while (pos != string::npos) {
        cout << "\nString: " << haystack << " found " << needle << " at " << pos << endl;
        pos = haystack.find(needle, pos + 1);
    }
}

int read() {
    ifstream fin("myfile.txt");
    if (fin.fail()) {
        cout << "Cannot open file myfile.txt";
        exit(1);
    }

    string myVar;
    while (getline(fin, myVar)) {
        cout << myVar << endl;
    }
    fin.close();
    return 0;
}


int main()
{
    Employee myObj;
    myObj.setSalary(50000);
    cout << myObj.getSalary() << endl;
    
    Date2 mybday;
    mybday.set(05, 06, 1995);
    cout << "Day five is: " << mybday.getDay() << ", Month:" << mybday.getMonth() << endl;
    
    Date today, birthdate = { 27,10,2035 };
    today.year = 2022;
    today.day = birthdate.day + 1;
    cout << "Enter the monthnumber:\n";
    cin >> today.month;
    cout << "Datum: "  << today.day << "." << today.month << "." << today.year << endl;

    Meeting met;
    
    met.setDate(24, 12, 2016);
    met.setTime(23, 15);
    cout << met.getYear() << endl;
     
    met.outputDate();
    met.outputTime();
    
    ifstream fin;
    ofstream fout;

    string filename = "myfile.txt";
    fin.open(filename);

    string var1, var2, var3;
    fin >> var1 >> var2 >> var3;
    cout << var1 << " " << var2 << " " << var3 << endl;
  
    if (read() == 0) {
        cout << "successfully read from file in while loop!" << endl;
    }
    string fileName2 = "myfile.txt";
    ifstream fin2(fileName2);
    string myVar;
    while (fin2 >> myVar) {//any file
        cout << "1 while: " << myVar << endl;
    }

    fin.close();//closing file
    fin2.close();//closing file

    string mystr("Hello");
    cout << mystr << endl;
    string s = "Hello World";
    cout << s << endl;
    string str = "";

    getString();
    string s2 = "baa baa black sheep";
    findAtPos(s2, 'a');

    cout << endl << "Extract World: " << s.substr(6, 5) << "\nFind World at pos: " << s.find("World") << endl;
    //dynamic arrays
    int *p1, *p2, num;
    num = 5;
    num = 10;
    p2 = new int[num];
    p2[10] = 5;
    cout << "dynamic arrays p1[10]: " << p2[10] << endl;

    int* ip;
    ip = new int;
    cout << "enter a number, Result is plus 20: ";
    cin >> *ip;
    *ip += 20;
    cout << *ip << endl;

    int *ip1, *ip2, one = 1, two = 2;
    ip1 = &one;
    ip2 = ip1;
    *ip2 = *ip1 + 1;
    ip1 = &two;
    *ip1 -= 1;
    cout << *ip2 << " " << *ip1 << endl;

    int *ptr2 = nullptr, i2 = 5;
    if(ptr2 == nullptr) {
        ptr2 = &i2;
        cout << "First nullpointer then 5: " << *ptr2 << endl;
    }

    const int size = 10;
    int score[size] = { 1,2,3,4,5,6,7,8,9,10 };
    printArray(score, size);

    const int numNumbers = 5;
    int numbers[numNumbers];
    cout << "Enter Numbers:";
    for (int i = 0; i < numNumbers; ++i) {
        cin >> numbers[i];
    }

    //find minimum Numer
    int minimum = 10000;
    for (int i = 0; i < numNumbers; ++i) {
        if (numbers[i] < minimum)
            minimum = numbers[i];
 
    }
    cout << "Minimum is: " << minimum << endl;

    int x[numNumbers];
    x[0] = 5;
    int studentAge = 1;
    x[studentAge] = 35;
    cout << "Array x[0] = " << x[0] << ", Student Age = " << x[1] << ", Size =" << numNumbers << endl;
    cout << "Enter a number: " << endl;
    int n;
    cin >> n;
    int newn = add1(n);
    cout << "Number plus 1 is: " << newn << endl;
    int noOfBars;
    cout << "Enter Number of Bars:\n" << endl;
    cin >> noOfBars;
    cout << "\nNumber:" << noOfBars << endl;
    MessageBox(NULL, L"The message", L"The caption", MB_OK);

    for (int i = 0; i < 20; ++i)
        cout << "i is " << i << endl;

    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j)
            cout << i << j << endl;

    int i = 1, j = 2;
    cout << "before: " << i << ' ' << j << "\n";
    swap(i, j);
    cout << "after swap: " << i << ' ' << j << "\n";

    do
        cout << "Hello, World!\n";
    while (again());
    return 0;
}

// Programm ausführen: STRG+F5 oder Menüeintrag "Debuggen" > "Starten ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.
