//Problem link-https://codeforces.com/contest/1092/problem/F

void dfs(ll vertex, ll par, vector<ll> g[], vector<ll> &a, vector<ll> &cost, vll &cs)
{
    cs[vertex] += a[vertex - 1];
    for (auto child : g[vertex])
    {
        if (child == par)
            continue;
 
        dfs(child, vertex, g, a, cost, cs);
        cost[vertex] += (cost[child] + cs[child]);
        cs[vertex] += cs[child];
    }
}
void dfs1(ll vertex, ll par, vector<ll> g[], vector<ll> &a, vector<ll> &cost, vll &cs, sll &s)
{
    s.insert(cost[vertex]);
    for (auto child : g[vertex])
    {
        if (child == par)
            continue;
        ll ms = cost[vertex] - cost[child] - cs[child];
        cost[child] += ms + cs[vertex] - cs[child];
 
        cs[child] = cs[vertex];
        dfs1(child, vertex, g, a, cost, cs,s);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    ll n;
    cin >> n;
 
    vector<ll> a(n);
 
    loop(i, 0, n)
    {
        cin >> a[i];
    }
    vll g[n + 1];
    loop(i, 0, n - 1)
    {
 
        ll l, r;
 
        cin >> l >> r;
 
        g[l].pb(r);
 
        g[r].pb(l);
    }
 
    vll cost(n + 1);
 
    vll cs(n + 1);
    sll s1;
    dfs(1, 0, g, a, cost, cs);
 
    dfs1(1, 0, g, a, cost, cs, s1);
 
 
 
 
    pr(*s1.rbegin());
}