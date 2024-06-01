#include <iostream>
using namespace std;
int count = 0;
void move (int n, char a, char b, char c)
{
    if (n == 1)
    {
        cout << "Move 1 disk from " << a << " to " << b << endl;
        count++;
    }
    else
    {
        move (n - 1, a, c, b);
        move (1, a, b, c);
        move (n - 1, c, b, a);
        
    }
}
int main()
{
    int n;
    cin >> n;
    char A, B, C;
    move (n, 'A', 'B', 'C');
    cout << count << endl;


}