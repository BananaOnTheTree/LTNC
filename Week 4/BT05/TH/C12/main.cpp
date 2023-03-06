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
//To hop chap k cua n phan tu % MOD (nCk % MOD)
int s[MAX];
void init()
{
    s[0] = s[1] = 1;
    for (int i = 2; i <= MAX - 10; i++) s[i] = s[i - 1] * i % MOD;
}
int POW(int x, int y)
{
    if (!y) return 1;
    if (y == 1) return x;
    int ret = POW(x, y / 2);
    ret = ret * ret % MOD;
    return ret * POW(x, y % 2) % MOD;
}
int toHop(int k, int n)
{
    int ret = s[n];
    ret = ret * POW(s[k], MOD - 2) % MOD;
    ret = ret * POW(s[n - k], MOD - 2) % MOD;
    return ret;
}
bool kiemTra(int k, int n)
{
    return (0 <= k && k <= n && 1 <= n && n <= 20);
}
void nhapKN(int k[], int n[],int *soPhanTu)
{
    *soPhanTu = 0;
    do
    {
        (*soPhanTu) ++;
        cin >> k[*soPhanTu] >> n[*soPhanTu];
    }
    while (k[*soPhanTu] != -1);
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("t.inp", "r", stdin);
    init();
    int num = 0;
    int *k, *n;
    k = new int[MAX];
    n = new int[MAX];
    nhapKN(k, n, &num);
    for (int i = 1; i < num; i++)
    {
        cout << toHop(k[i], n[i]) << '\n';
    }
    return 0;
}
