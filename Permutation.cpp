/*Given an integer n, write a program to generate all permutations of 1, 2, ..., n 
in a lexicalgraphic order (elements of a permutation are separated by a SPACE character).*/
#include <iostream>
void quit(){
	exit(0);
}
using namespace std;
int n;
int m;
int track[1000000], visited[1000000];
void printSolution (int *arr, int size) // print the solution
{
    for (int i = 1; i <= size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
// int factorial (int n)
// {
//     int a = 1;
//     for(int i = 1; i <= n; i++)
//     {
//         a *= i;
//     }
//     return a;
// }
int check (int v) // check if the vertex is visited or not
{
    return 1 - visited[v];
}
int count = 0;
void Try(int k, int m) // try to find the solution
{
    for (int v = 1; v <= n; v++)
    {
        if(check(v))
        {
            track[k] = v;
            visited[v] = 1;
            
            if(k == n)
            {
                    count++;
                    if(count <= (m))
                    {
                    printSolution(track, n);
                    }
                    else quit();
            }
            else
            {
                Try(k + 1, m);
            }
            visited[v] = 0;
            

        }
    }
}
int main()
{
    cin >> n;
    cin >> m;
    Try(1, m);
    return 0;
}