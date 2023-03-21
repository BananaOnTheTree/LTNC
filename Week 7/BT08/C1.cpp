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
char* Reverse(char *a, int &n)
{
    char *ret = new char[n];
    for (int i = 0; i < n; i++) ret[i] = a[n - i - 1];
    return ret;
}
char* delete_char(char *a, int &n, char c)
{
    char *ret = new char[n];
    int pos = 0;
    for (int i = 0; i < n; i++) if (a[i] != c) ret[pos++] = a[i];
    //n = pos;
    return ret;
}
char* pad_right(char *a, int n, int l)
{
    int t = max(l, n);
    char *ret = new char[t];
    for (int i = 0; i < n; i++) ret[i] = a[i];
    while (n++ < l) ret[n - 1] = ' ';
    return ret;
}
char* pad_left(char *a, int n, int l)
{
    if (n >= l) return a;
    char *ret = new char[l];
    for (int i = 0; i < n; i++) ret[l - n + i] = a[i];
    for (int i = 0; i < l - n; i++) ret[i] = ' ';
    return ret;
}
char* truncate(char *a, int n, int l)
{
    if (n <= l) return a;
    char *ret = new char[l];
    for (int i = 0; i < l; i++) ret[i] = a[i];
    return ret;
}
bool is_palindrome(char *a, int n)
{
    char *temp = new char[n];
    temp = Reverse(a, n);
    for (int i = 0; i < n; i++) if (temp[i] != a[i]) return 0;
    return 1;
}
char* trim_left(char *a, int n)
{
    int l = n;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == ' ') l--;
        else break;
    }
    char *ret = new char[l];
    for (int i = 0; i < l; i++) ret[i] = a[n - l + i];
    return ret;
}
char* trim_right(char *a, int n)
{
    int l = n;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] == ' ') l--;
        else break;
    }
    char *ret = new char[l];
    for (int i = 0; i < l; i++) ret[i] = a[i];
    return ret;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    char* c = new char[n];
    getline(cin, *c);
    cout << trim_right(c, n);
    return 0;
}
