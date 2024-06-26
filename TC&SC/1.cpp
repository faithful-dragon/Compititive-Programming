#include <iostream>
using namespace std;

// TC = O(N)
void f(int n){
    if (n > 0){
        // DoSomething(n); // O(n)
        f(n / 2);
    }
}

// TC = O(NLogN)
void f(int n)
{
    if (n > 0)
    {
        // DoSomething(n); // O(n)
        f(n / 2);
        f(n / 2);
    }
}

// TC = O(N^2)
void f(int n)
{
    if (n > 0)
    {
        // DoSomething(n); // O(n)
        f(n - 1);
    }
}

// TC = O(2^N)
void f(int n)
{
    if (n > 0)
    {
        // DoSomething(); // O(1)
        f(n - 1);
        f(n - 1);
    }
}

int main()
{
    int n = 10;
    int cnt = 0;

    // TC = O(N)
    for (int i = 0; i < n; i++)
    {
        cnt++;
    }

    cout << "cnt = " << cnt << endl;
    cnt = 0;

    // TC = O(N^2)
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> ";
        for (int j = 0; j < i; j++)
        {
            cnt++;
            cout << j << " ";
        }
        cout << endl;
    }

    cout << "cnt = " << cnt << endl;

    cnt = 0;

    // TC = O(N)
    for (int i = n; i > 0; i /= 2)
    {
        cout << i << " -> ";
        for (int j = 0; j < i; j++)
        {
            cout << j << " ";
            cnt++;
        }
        cout << endl;
    }

    cout << "cnt = " << cnt << endl;
}