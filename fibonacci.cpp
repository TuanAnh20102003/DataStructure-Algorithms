#include <iostream>
 using namespace std;
void fibonacci (int size)
{
    unsigned long long *arr = new unsigned long long [size];
    arr[0] = 1;
    arr[1] = 1;
    for (int i = 0; i < size; i++)
    {
        arr[i + 2] = arr[i] + arr[i + 1];
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    delete [] arr;
}
int fibo_recurtor (int n)
{
    if (n == 1) return 1;
    if (n == 0) return 1;
    else
    {
        return  fibo_recurtor(n - 1) + fibo_recurtor(n - 2);
    }
}
int main()
{
    int size;
    cin >> size;
     fibonacci (size);
   
    // for(int i = 0; i < size; i++)
    // {
    //     cout << fibo_recurtor(i) << " ";
    // }
    return 0;
}