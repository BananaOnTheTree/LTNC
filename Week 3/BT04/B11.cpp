#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define fi first
#define se second
#define FORU(i , a , b) for(ll i = a ; i <= b ; i++)
#define FORD(i , a , b) for(ll i = a ; i >= b ; i--)
using namespace std;
const ll MAX = 1e6 + 10, MOD = 1e9 + 7;
void unset(ll &t, ll pos)
{
    t &= (~(1ll << (pos - 1)));
}
void onset(ll &t, ll pos)
{
    t |= (1ll << (pos - 1));
}
ll getbit(ll i,ll k)
{
    return (k >> (i - 1)) % 2;
}
void minimize(ll &x, ll y)
{
    x = min(x, y);
}
void maximize(ll &x, ll y)
{
    x = max(x, y);
}
ll ADD(ll x, ll y)
{
    return (x + y) % MOD;
}
ll MINUS(ll x, ll y)
{
    x %= MOD, y %= MOD;
    if (x < y) x += MOD;
    return (x - y) % MOD;
}
//========================================================================0========================================================================//
string a[MAX];
ll n;
bool comp(string a, string b)
{
    ll l = a.length();
    if (l != (ll)b.length()) return 0;
    for (ll i = 0; i < l; i++)
    {
        if (a[i] != b[l - i - 1]) return 0;
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("t.inp", "r", stdin);
    cin >> n;
    for (ll i = 1; i <= n; i++) cin >> a[i];
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            if (comp(a[i], a[j]))
            {
                ll l = a[i].length();
                cout << l << " " << a[i][l / 2];
                return 0;
            }
        }
    }
    return 0;
}
