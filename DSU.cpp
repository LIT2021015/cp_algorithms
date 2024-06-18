

ll find(ll v, vll &p)
{
    if (p[v] == v)
        return v;

    return p[v] = find(p[v], p);
}
void unite(ll a, ll b, vll &siz, vll &p)
{

    if (siz[a] >= siz[b])
    {

        p[b] = a;

        siz[a] += siz[b];
    }
    else
    {

        p[a] = b;

        siz[b] += siz[a];
    }
}
