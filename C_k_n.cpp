#include <iostream>
using namespace std;
const unsigned long long D = 1000000007;
void initial (unsigned long long **M, unsigned long long n)
{
    M[0][0] = 1; M[0][1] = 1;
    for (unsigned long long i = 1; i <= n; i++)
    {
        //M[i][0] = 1;
        for (unsigned long long j = 1; j <= n; j++)
        {
            M[i][j] = 0;
        }
    }
}
unsigned long long C (unsigned long long **M, unsigned long long k, unsigned long long n)
{
    if (k == 0 || k == n)
    {
        return 1;
    }
    if (n != 0 && M[k][n] == 0)
    {
       M[k][n] = (C(M, k, n - 1) + C(M, k - 1, n - 1)) % D ;
    }
    //int result = M[k][n] % D;
    return M[k][n];

}
int main()
{
    unsigned long long n, k;
    cin >> k >> n;
    
    
    if (k > n)
    {
        cout << "Error";
        return -1;
    }
    unsigned long long **M = new unsigned long long *[n + 1];
    for (unsigned long long i = 0; i <= n; i++)
    {
        M[i] = new unsigned long long[n + 1];
    }
    initial (M, n);
    cout << C(M, k, n) << endl;
    for (unsigned long long i = 0; i <= n; i++)
    { 
        delete [] M[i];
    }
    delete [] M;
    return 0;
}