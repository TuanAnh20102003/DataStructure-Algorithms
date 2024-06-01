//Print out the fibonacci number sequence with the input limit value is 2^32 follow formmat “order – value”
//I did not use 40 elements array, I used n elements array instead
#include <stdio.h>
#include <stdlib.h>

void Copy(long long n, int* arr1, int* arr2)
{
    for(int i = 0; i < n; i++)
    {
        arr1[i] = arr2[i];
    }
}

void Print(long long n, int* arr) // print the array
{
    int leading = 1;
    for (int j = 0; j < n; j++)
    {
        if (leading && arr[j] == 0)
            continue;
        leading = 0;
        printf("%d", arr[j]);
    }
    printf("\n");
}

void Add(long long n, int* arr1, int* arr2, int* arr3) // add arr1 and arr2, store the result in arr2
{
    Copy(n, arr3, arr2);
    for(int i = n - 1; i >= 0; i--)
    {
        if(arr2[i] + arr1[i] > 9)
        {
            arr2[i] = (arr2[i] + arr1[i]) % 10;
            if(i != 0)
            {
                arr2[i - 1] += 1;
            }
        }
        else
        {
            arr2[i] = arr2[i] + arr1[i];
        }
    }
    Copy(n, arr1, arr3);
}

void Check(long long n) // check if n is valid
{
    if (n <= 0)
    {
        printf("Error: Invalid n\n");
        exit(1);
    }
    else if (n > 2147483647)
    {
        printf("Error: n is too large\n");
        exit(1);
    }
    else
    {
        int* arr1 = calloc(n, sizeof(int)); // allocate memory for the array
        int* arr2 = calloc(n, sizeof(int)); 
        int* arr3 = calloc(n, sizeof(int));
        arr2[n - 1] = 1;
        for(int i = 2; i <= n; i++)
        {
            Add(n, arr1, arr2, arr3);
        }
        printf("The %d - th number of the Fibonacci sequence is: ", n);
        Print(n, arr1);
        free(arr1); // free the memory
        free(arr2);
        free(arr3);
    }
}

int main()
{
    long long n;
    scanf("%lld", &n);
    printf("n equal %lld\n", n);
    Check(n);
    int* arr1 = calloc(n, sizeof(int)); // allocate memory for the array
    int* arr2 = calloc(n, sizeof(int)); 
    int* arr3 = calloc(n, sizeof(int));
    arr2[n - 1] = 1;
    
    printf("Order      Value\n");
    printf("1  -       0\n");
    for(int i = 2; i <= n; i++)
    { 
        printf("%d  -       ", i);
        Print(n, arr2);
        Add(n, arr1, arr2, arr3);
    }
    free(arr1); // free the memory
    free(arr2);
    free(arr3);
}

