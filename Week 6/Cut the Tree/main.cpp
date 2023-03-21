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
ll dp[MAX], n, par[MAX], sum;
vector <ll> adj[MAX];
void input()
{
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> dp[i];
        sum += dp[i];
    }
    for (ll i = 1; i < n; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
void dfs(ll u, ll p)
{
    par[u] = p;
    for (ll v : adj[u])
    {
        if (v != p)
        {
            dfs(v, u);
            dp[u] += dp[v];
        }
    }
}
void solve()
{
    ll res = MOD;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j : adj[i])
        {
            if (par[j] == i) minimize(res, abs(dp[j] - (sum - dp[j])));
        }
    }
    cout << res;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("t.inp", "r", stdin);
    input();
    dfs(1, 1);
    solve();
    return 0;
}
