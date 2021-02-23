// Template by Shrayansh
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define Max 1022
#define mod 1000000007
#define ll long long int
#define ld long double
#define cel(x, a) (((x) + (a)-1) / (a))
#define deb(x) cout << #x << '=' << x << endl
#define deb2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define deb3(x, y, z) cout << #x << '=' << x << ',' << #y << '=' << y << ',' << #z << '=' << z << endl
#define pf(a, b) cout << fixed << setprecision(b) << a << '\n'
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
#define F first
#define S second
#define pb push_back
#define pob pop_back()
#define mp make_pair
#define fio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define all(s) (s).begin(), (s).end()
ll mult(ll a, ll b, ll p = mod)
{
    return ((a % p) * (b % p)) % p;
}
ll add(ll a, ll b, ll p = mod) { return (a % p + b % p) % p; }
template <typename T, typename U>
static inline void amin(T &x, U y)
{
    if (y < x)
        x = y;
}
template <typename T, typename U>
static inline void amax(T &x, U y)
{
    if (x < y)
        x = y;
}
ll i, j;

// Modular Exponentiation
ll mod_exp(ll b, ll p)
{
    ll res = 1;
    while (p)
    {
        if (p & 1)
        {
            res = mult(res, b);
            --p;
        }
        else
        {
            b = mult(b, b);
            p /= 2;
        }
    }
    return res;
}

// Function to precompute modular inverse of numbers
vl ninv(Max);
void invofn()
{
    ninv[0] = ninv[1] = 1;
    for (i = 2; i < Max; i++)
        ninv[i] = ninv[mod % i] * (mod - mod / i) % mod;
}

// Function to precompute inverse of factorials
vl factinv(Max);
void invoffact()
{
    factinv[0] = factinv[1] = 1;
    // precompute inverse of natural numbers
    for (i = 2; i < Max; i++)
        factinv[i] = mult(ninv[i], factinv[i - 1]);
}

// Function to precompute factorials
vl fact(Max);
void prefact()
{
    fact[0] = 1;
    for (i = 1; i < Max; i++)
        fact[i] = mult(fact[i - 1], i);
}

// Function to compute Modular Inverse
ll inv(ll x)
{
    return mod_exp(x, mod - 2);
}

// Calculating NCR when only one query is there
ll divide(ll a, ll b)
{
    return mult(a, inv(b));
}
ll nCr(ll n, ll r)
{
    return divide(fact[n], mult(fact[r], fact[n - r]));
}

// Function to return nCr % p in O(1) time
ll binomial(ll n, ll r)
{
    return (((fact[n] * factinv[r]) % mod * factinv[n - r]) % mod);
}

// Prime sieve
vl primes;
void sieve()
{
    vector<bool> ok(Max, true);
    ok[0] = false;
    ok[1] = false;
    for (i = 2; i * i < Max; i++)
    {
        if (ok[i])
        {
            for (j = i * i; j < Max; j += i)
                ok[j] = false;
        }
    }
    for (i = 2; i < Max; i++)
    {
        if (ok[i])
            primes.pb(i);
    }
}

// Prime factorization in O(log n)
vl ar(Max, -1);
void sieve()
{
    for (i = 2; i < Max; i++)
    {
        if (ar[i] == -1)
        {
            for (j = i; j < Max; j += i)
                if (ar[j] == -1)
                    ar[j] = i;
        }
    }
}



void solve()
{
}

int main()
{
    fio;
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}