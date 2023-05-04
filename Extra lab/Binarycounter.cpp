#include <bits/stdc++.h>
using namespace std;
// binary counter function
void binarycounter(int n)
{
    //take bits = log2(n) + 1
    int bits = log2(n) + 1;
    vector<int> counter(bits);
    // print the initial counter
    for (int i = 0; i < bits; i++)
    {
        cout << counter[i];
    }
    cout << endl;
    // increment the counter
    for (int i = 0; i <=n; i++)
    {
        int j = bits - 1;
        while (j >= 0)
        {
            if (counter[j] == 0)
            {
                counter[j] = 1;
                break;
            }
            else
            {
                counter[j] = 0;
                j--;
            }
        }
        // print the counter
        for (int i = 0; i < bits; i++)
        {
            cout << counter[i];
        }
        cout << endl;
    }

}
// main function
int main()
{
    int n;
    cout << "Enter the number of times you want to increase the counter: ";
    cin >> n;
    // call the binary counter function
    cout << "The binary counter is: " << endl;
    binarycounter(n);
    return 0;
}
