//cung k kho lam.
#include <iostream>
#include <string.h>
using namespace std;
bool checkAnagrams(string a, string b)
{
    int n = a.length();
    int m = b.length();
    if (n != m)
        return false;
    int count[256] = {0};
    for (int i = 0; i < n; i++) // check if the frequency of each character is same in both strings
    {
        count[a[i]]++; //if is there any character in a but not in b then count[a[i]] will be negative
        count[b[i]]--;
    }
    for (int i = 0; i < 256; i++)
    {
        if (count[i] != 0)
            return false;
    }
    return true;
}
int main()
{
    string a = "listen";
    string b = "silent";
    if (checkAnagrams(a, b))
        cout << "Yes";
    else
        cout << "No";
}