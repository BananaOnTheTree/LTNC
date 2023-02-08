#include<iostream>
#include<bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++) cout << "*";
        for (int j = 1; j <= i - 1; j++) cout << " ";
        cout << '\n';
    }
}
