#include <iostream>
#include <fstream>
using namespace std;
int solution[100], a[100][100], destination[100];
int min_unit_cost, n;
void initialization()
{
    for (int i = 0; i < 100; i++)
    {
        solution[i] = -1;
        destination[i] = -1;
    }
}
void input ()
{
     float v;
    ifstream inputFile("C:/Users/anhtu/Downloads/input.txt");
    if (inputFile.is_open())
    {
        //cout << "Oke" << endl;
        inputFile >> n;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                inputFile >> v;
                a[i][j] = v;
                if (v > 0 && v < min_unit_cost)
                {
                 min_unit_cost = v;
                }
            }
        }
        inputFile.close();
    }
    else 
    {
        cout << "Unable to open file." << endl;
    }
}
bool feasible()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if(destination[i] = destination[j] && destination[0] != destination[n + 1])
            {
                return false;
                break;
            }
        }
    }
}
int check()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] > 0)
            {
                return 1;
            }
        }
    }
    return 0;
}
int select()
{
    int min = 1000;
    int x, y;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] > 0 && a[i][j] < min)
            {
                min = a[i][j];
                x = i;
                y = j;
            }
        }
    }
    // a[x][y] = 0;
    // a[y][x] = 0;
    return min;
}
int* Greedy ()
{
    while (check())
    {
        
    }

}