#include <iostream>
using namespace std;
void numberOfEvenKSequence (int size, int k, int *arr)
{
    int *p = new int[size + 1];
    p[0] = 0;
    for (int i = 1; i <= size; i++)
    {
        p[i] = p[i - 1] + arr[i - 1];
    }
    
    int count = 0;
    for (int i = k; i <= size; i++)
    {
        long long sum = 0;
        sum = p[i] - p[i - k];
        if (sum % 2 == 0)
    {
        count++;
    }
    }
    cout << count;
}
int main()
{
    int size, k;
    
    cin >> size >> k;
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    numberOfEvenKSequence (size, k, arr);
    delete [] arr;
    return 0;
}