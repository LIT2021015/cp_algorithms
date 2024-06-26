// problem link-https://codeforces.com/problemset/problem/1986/F
void dfs(ll vertex, ll par, vector<ll> g[], vector<ll> &a1, vector<ll> &a2, vll &su, ll n)
{
    su[vertex]++;
    for (auto child : g[vertex])
    {
        if (child == par)
            continue;
        if (a1[child] == 0)
        {
            a2[child] = a1[vertex] + 1;
            a1[child] = a1[vertex] + 1;
            dfs(child, vertex, g, a1, a2, su, n);

            su[vertex] += su[child];
        }

        a2[vertex] = min(a2[vertex], a2[child]);

        if (a1[vertex] < a2[child])
        {
            ll t1 = su[child];

            ll t2 = n - su[child];
            ans = min(ans, t1 * (t1 - 1) / 2 + t2 * (t2 - 1) / 2);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;

        vector<ll> g[n + 1];
        ans = 1e17;

        loop(i, 0, m)
        {
            ll u, v;
            cin >> u >> v;

            g[u].pb(v);
            g[v].pb(u);
        }

        vll a1(n + 1, 0);
        vll a2(n + 1, 1e9);

        vll su(n + 1, 0);
        a1[1] = 1;
        a2[1] = 1;
        dfs(1, 0, g, a1, a2, su, n);

        ans = min(ans, n * (n - 1) / 2);

        pr(ans);
    }
}