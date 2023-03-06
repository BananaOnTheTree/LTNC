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
int n, matrix[100][100];
void draw(int x, int y, int k, int type)
{
    if (k == 1)
    {
        matrix[x][y] = type;
        return;
    }
    draw(x, y, k / 2, type);
    draw(x + k / 2, y, k / 2, type);
    draw(x, y + k / 2, k / 2, type);
    draw(x + k / 2, y + k / 2, k / 2, 1 - type);
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    draw(1, 1, n, 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++) cout << matrix[i][j];
        cout << "\n";
    }
    return 0;
}
