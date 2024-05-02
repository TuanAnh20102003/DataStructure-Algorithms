#include <iostream>

using namespace std;
void reverseArray (int *arr, int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;

    }
    
}
void lexicographicOder (int size)
{
    
    int arr[64];
    for (int num = 0; num < (1 << size); num++)
    {
        int temp = num;
        if (num == 0)
        {
            for (int i = 0; i < size; i++)
            {
                arr[i] = 0;
            }
        }
         for (int a = 0; a < size; a++)
    {
        arr[a] = temp % 2;
        temp /= 2;
        
    }
    reverseArray(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
    }
        cout << endl;
    }
}
int main()
{
    
    int n;
    cin >> n;
    lexicographicOder(n);
}