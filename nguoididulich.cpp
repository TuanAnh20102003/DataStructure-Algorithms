#include <iostream>
#include <fstream>
using namespace std;
float a[100][100];
int n, visited[100], initerary[100], min_itinerary[100];
int cost = 0, bestCost = 1000001, min_unit_cost = 999999;
void input()
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
void initial()
{
    for (int v = 1; v <= n; v++)
    {
        visited[v] = 0;
    }
}
int check (int v)
{
    return 1 - visited[v];
}
void printSolution(int k)
{
    cout << "Best cost: " << bestCost << endl;
    for (int i = 1; i <= k; i++)
    {
        cout << min_itinerary[i] << " ";
    }
    cout << endl;
}

void updateBestCost()
{
    if (cost < bestCost)
    {
        bestCost = cost;
        for (int i = 1; i <= n; i++)
        {
            min_itinerary[i] = initerary[i];
        }
    }
}

int check_early (int k)
{
    if (cost + (n - k) * min_unit_cost > bestCost)
    {
        return 1;
    }
    return 0;
}

void Try(int k)
{
    for (int v = 1; v <= n; v++)
    {
        if(check(v))
        {
            initerary[k] = v;
            visited[v] = 1;
            cost += a[initerary[k - 1]][initerary[k]];
            if (check_early(k)){
                cost -= a[initerary[k - 1]][initerary[k]];
                continue;
            }
            if(k == n)
            {
                updateBestCost();
            }
            else
            {
                Try(k + 1);
            }
            visited[v] = 0;
            cost -= a[initerary[k - 1]][initerary[k]];

        }
    }
}

int main()
{
    initial();
    input();
    Try(1);
    printSolution(n);
    return 0;
}
