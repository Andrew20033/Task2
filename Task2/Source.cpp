#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string SOGL = "qwqwrrtrtttrtrtgghgghghjkjlkkgjhlhjqwwqwtqw";
string GLAS = "aeyuioioioaaeoaeeoaeiaeiaeoaeio";
string NUMB = "1245465706731";

bool search(char ch, string arr) {
    for (size_t i = 0; i < arr.size(); i++) {
        if (ch == arr[i]) {
            return true;
        }
    }
}

int symFile() {
    int sym = 0;
    ifstream N("file.txt");
    if (!N)
    {
        exit(-1);
    }
    else
    {
        while (!N.eof())
        {
            char ch;
            N >> ch;
            sym++;
        }
    }

    return sym - 1;
}

int strFile() {
    int str = 0;
    ifstream N("file.txt");
    if (!N) {
        exit(-1);
    }
    else {
        string line;
        while (getline(N, line)) {
            str++;
        }
    }
    N.close();
    return str;
}

int glasFile() {
    int glas = 0;
    ifstream N("file.txt");
    if (!N)
    {
        exit(-1);
    }
    else
    {
        while (!N.eof())
        {
            char ch;
            N >> ch;
            if (search(ch, GLAS) == true) {
                glas++;
            }
        }
    }
    N.close();
    return glas;
}

int soglFile() {
    int sogl = 0;
    ifstream N("file.txt");
    if (!N)
    {
        exit(-1);
    }
    else
    {
        while (!N.eof())
        {
            char ch;
            N >> ch;
            if (search(ch, SOGL) == true) {
                sogl++;
            }
        }
    }
    N.close();
    return sogl;
}

int numbFile() {
    int numb = 0;
    ifstream N("file.txt");
    if (!N)
    {
        exit(-1);
    }
    else
    {
        while (!N.eof())
        {
            char ch;
            N >> ch;
            if (search(ch, NUMB) == true) {
                numb++;
            }
        }
    }
    N.close();
    return numb;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int SYM = symFile();
    int STR = strFile();
    int Glas = glasFile();
    int Sogl = soglFile();
    int Numb = numbFile();

    cout << "Symbol in file: " << SYM << endl;
    cout << "Lines in File: " << STR << endl;
    cout << "Vowels in File: " << Glas << endl;
    cout << "Consonants in File: " << Sogl << endl;
    cout << "Numbers in file: " << Numb << endl;

    ofstream out("out.txt");
    out << "Symbol in file: " << SYM << endl;
    out << "Lines in File: " << STR << endl;
    out << "Vowels in File: " << Glas << endl;
    out << "Consonants in File: " << Sogl << endl;
    out << "Numbers in file: " << Numb << endl;
    out.close();

    cout << endl;
    system("pause");
    return 0;
}