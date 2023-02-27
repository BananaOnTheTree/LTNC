#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define FORU(i , a , b) for(int i = a ; i <= b ; i++)
#define FORD(i , a , b) for(int i = a ; i >= b ; i--)
using namespace std;
const int MAX = 1e6 + 10, MOD = 1e9 + 7;
void unset(int &t, int pos)
{
    t &= (~(1ll << (pos - 1)));
}
void onset(int &t, int pos)
{
    t |= (1ll << (pos - 1));
}
int getbit(int i,int k)
{
    return (k >> (i - 1)) % 2;
}
void minimize(int &x, int y)
{
    x = min(x, y);
}
void maximize(int &x, int y)
{
    x = max(x, y);
}
int ADD(int x, int y)
{
    return (x + y) % MOD;
}
int MINUS(int x, int y)
{
    x %= MOD, y %= MOD;
    if (x < y) x += MOD;
    return (x - y) % MOD;
}
//========================================================================0========================================================================//
string s;
char c[4];
int n;
void printString(int l)
{
    for (int i = 1; i <= l; i++) cout << c[i];
    cout << " ";
}
void backtrack(int pos)
{
    for (int i = 1; i <= n; i++)
    {
        c[pos] = s[i];
        if (pos == 2)
        {
            printString(2);
            backtrack(pos + 1);
        }
        else if (pos == 3) printString(3);
        else backtrack(pos + 1);
    }
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    n = s.length();
    s = " " + s;
    backtrack(1);
    return 0;
}
