#include <iostream>
#include <bits/stdc++.h>
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
char d[25];
bool used[30];
int n, k;
void print()
{
    for (int i = 1; i <= k; i++) cout << d[i];
    cout << '\n';
}
void backtrack(int pos)
{
    for (int i = 1; i <= n; i++)
    {
        if (used[i]) continue;
        used[i] = 1;
        d[pos] = char(i + 'a' - 1);
        if (pos == k) print();
        else backtrack(pos + 1);
        used[i] = 0;
    }
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    backtrack(1);
    return 0;
}
