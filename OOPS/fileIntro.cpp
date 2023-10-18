#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream out("sample.txt");
    string name;
    cout << "Enter your name: ";
    cin >> name;
    out << "MY name is " << name << endl;
    out.close();

    ifstream in("sample.txt");
    string content;
    getline(in,content);
    cout << "Content of the file is: " << content << endl;
    in.close();

    return 0;
}