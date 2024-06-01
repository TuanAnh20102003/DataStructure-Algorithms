#include <iostream>
#include <cassert>
using namespace std;

int binaryToDecimal(int n)
{
   int temp = n;
   int dec = 0;
   int base = 1;
   while (temp)
   {
        int last_digit = temp % 10;
        if(last_digit != 0 && last_digit != 1)
        {
            cout << "Invalid Input" << endl;
            assert(0);
        }
        temp = temp / 10;
        dec += last_digit * base;
        base = base * 2;
   }
    return dec;
}
int main()
{
    int n;
    cin >> n;
    cout << binaryToDecimal(n);
    return 0;

}