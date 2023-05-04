#include <bits/stdc++.h>
using namespace std;
int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}
int main()
{
    auto start = chrono::high_resolution_clock::now();
    int n;
    cout << "Enter the number of terms: ";
    cin >> n;
    cout << "Fibonacci Series: ";
    for (int i = 0; i < n; i++)
        cout << fib(i) << " ";
    cout << endl;
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " nanoseconds" << endl;
    return 0;
}
