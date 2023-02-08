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
double MIN(double a, double b)
{
    return (a + b - abs(a - b)) / 2;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    double a, b, c, d, e;
    double aver;
    cin >> a >> b >> c >> d >> e;
    aver = 1.0 * (a + b + c + d + e) / 5;
    cout << aver << '\n';
    a -= aver; b -= aver; c -= aver; d -= aver;
    cout << a << " " << b << " " << c << " " << d << " " << e << '\n';
    double res = MIN(MIN(a, b), MIN(c, MIN(d, e)));
    cout << aver + res;
    return 0;
}
