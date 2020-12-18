#include<bits/stdc++.h>
using namespace std;

const ll inf64 = LLONG_MAX;
ll MOD;
ll add(ll x, ll y) {ll res = x + y; return (res >= MOD ? res - MOD : res);}
ll mul(ll x, ll y) {ll res = x * y; return (res >= MOD ? res % MOD : res);}
ll sub(ll x, ll y) {ll res = x - y; return (res < 0 ? res + MOD : res);}
ll power(ll x, ll y) {ll res = 1; x %= MOD; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}

typedef long long int ll;

//*********************** TONELLI SHANKS ALGORITHM ****************
uint64_t modpow(uint64_t a, uint64_t b, uint64_t n)
{
    uint64_t x = 1, y = a;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            x = (x * y) % n;
        }
        y = (y * y) % n;
        b /= 2;
    }
    return x % n;
}

struct Solution
{
    uint64_t root1, root2;
    bool exists;
};

struct Solution makeSolution(uint64_t root1, uint64_t root2, bool exists)
{
    struct Solution sol;
    sol.root1 = root1;
    sol.root2 = root2;
    sol.exists = exists;
    return sol;
}

struct Solution ts(uint64_t n, uint64_t p)
{
    uint64_t q = p - 1;
    uint64_t ss = 0;
    uint64_t z = 2;
    uint64_t c, r, t, m;

    if (modpow(n, (p - 1) / 2, p) != 1)
    {
        return makeSolution(0, 0, false);
    }

    while ((q & 1) == 0)
    {
        ss += 1;
        q >>= 1;
    }

    if (ss == 1)
    {
        uint64_t r1 = modpow(n, (p + 1) / 4, p);
        return makeSolution(r1, p - r1, true);
    }

    while (modpow(z, (p - 1) / 2, p) != p - 1)
    {
        z++;
    }

    c = modpow(z, q, p);
    r = modpow(n, (q + 1) / 2, p);
    t = modpow(n, q, p);
    m = ss;

    while (true)
    {
        uint64_t i = 0, zz = t;
        uint64_t b = c, e;
        if (t == 1)
        {
            return makeSolution(r, p - r, true);
        }
        while (zz != 1 && i < (m - 1))
        {
            zz = zz * zz % p;
            i++;
        }
        e = m - i - 1;
        while (e > 0)
        {
            b = b * b % p;
            e--;
        }
        r = r * b % p;
        c = b * b % p;
        t = t * c % p;
        m = i;
    }
}

int tonelli_shanks(uint64_t n, uint64_t p)
{
    struct Solution sol = ts(n, p);
    if (sol.exists)
        return sol.root1;
    return -1;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        ll n,p;
        cin>>n>>p;
        vector<int> g[n+1],c(n+1);
        for(int i = 2;i<=n;i++)
        {
            int parent;
            cin>>parent;
            g[parent].push_back(i);
        }
        for(int i = 1;i<=n;i++)
        {
            cin>>c[i];
        }
        vector<ll> stsum(n+1,0),ans(n+1,0);
        ll cnt = 1;//The count of number of possible sequences a which suffices the conditions
        for(int i = n;i>=1;i--)
        {
            ll D = c[i];
            for(auto x:g[i])//iterate over all the children of the node
            {
                stsum[i] = add(stsum[i],stsum[x]);
                D = add(D, power(stsum[x],2));
            }

            ll b = stsum[i];

            ll val = TonelliShanks(D,p);

            if(D == 0 )
            {
                ans[i] = sub(0,b);
            }
            else if(val == -1)//No solution exists
            {
                cnt = 0;
                break;
            }
            else
            {
                cnt = (cnt*2ll)%(998'244'353);
                ans[i] = sub(val - b);
            }
            stsum[i] = add(stsum[i], ans[i]);
        }

        if(cnt == 0)
        {
            cout<<"0\n-1\n";
        }
        else
        {
            cout<<cnt<<endl;
            for(int i = 1;i<=n;i++)
            {
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }
        

}