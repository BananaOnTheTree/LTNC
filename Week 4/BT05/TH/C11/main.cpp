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
string to_bin(int a)
{
    string ret = "";
    while (a)
    {
        ret = char(a % 2 + '0') + ret;
        a /= 2;
    }
    if (ret == "") return "0";
    return ret;
}
int to_dec(string a)
{
    int mul = 1, l = a.length() - 1, ret = 0;
    for (int i = l; i >= 0; i--)
    {
        ret += mul * ((int)a[i] - '0');
        mul *= 2;
    }
    return ret;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int x;
    cin >> x;
    cout << to_bin(x) << '\n' << to_dec(to_bin(x));
    return 0;
}
