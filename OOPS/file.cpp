#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream out;
    ifstream inp;
    string str;
    out.open("file.txt");
    out << "created a new file";
    out.close();
    inp.open("file.txt");
    while (getline(inp,str))
    {
        cout << str;
    }
    
    inp.close();
    return 0;
}