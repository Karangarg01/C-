#include <iostream>
using namespace std;

class year{
    public: 
        int n;
        void set(int num){
            n = num;
        }
};
enum month
{
    JANUARY,
    FEB,
    MARCH,
    APRIL
};
int main()
{
    int num;
    cin >> num;
    year y;
    y.set(num);
    month check;
    check = (month)y.n;
    switch (check)
    {
    case (JANUARY):
        cout << "January";
        break;
    case (FEB):
        cout << "feb";
        break;
    case (MARCH):
        cout << "march";
        break;

    default:
        cout << "Invalid month";
        break;
    }
    return 0;
}