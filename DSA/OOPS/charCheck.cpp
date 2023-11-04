#include <iostream>
using namespace std;

class charAnalyzer{
    public:
        int check(char n){
            n = toupper(n);
            if(n >= 65 && n <= 90){
                if(n=='A' || n=='E' || n=='I' || n=='O' || n=='U') return 1;
                else return 0;
            }
            else return -1;
        }
};

enum test{
    consonant = 0,
    vow = 1,
    invalid = -1
};


int main(){
    char n;
    cin >> n;
    charAnalyzer a;
    test vowel;
    vowel = (test)a.check(n); //to get enum input as int use Name of enum class in front
   switch (vowel)
   {
   case consonant:
        cout << "Consonant";
    break;
   case vow:
        cout << "vowel";
    break;
   case invalid:
        cout << "invalid";
    break;
   
   default:
    break;
   }
    return 0;
}
