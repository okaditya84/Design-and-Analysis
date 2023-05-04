#include <bits/stdc++.h>
#include <chrono>
using namespace std;

// make a function that uses iteratigve methoid for performing fibonacci series
int fib(int n)
{
    int a = 0, b = 1, c, i;
    if (n == 0)
        return a;
    for (i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main()
{
    // start the time
    auto start = chrono::high_resolution_clock::now();
    int n;
    cout << "Enter the number of terms: ";
    cin >> n;
    cout << "Fibonacci Series: ";
    for (int i = 0; i < n; i++)
        cout << fib(i) << " ";
    cout << endl;
    // count the time of executin
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " nanoseconds" << endl;

    return 0;
}
