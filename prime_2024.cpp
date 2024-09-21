/*****Ronnied0734 a.k.a woodynguyen - 22TI_LTV*****/

// #pragma GCC optimize("Ofast")
// #pragma GCC optimization("unroll-loops, no-stack-protector")
// #pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define woodynguyne signed main()
#define FOR(i, a, b) for (int i = a, _b = (b); i <= _b; ++i)
#define REP(i, a, b) for (int i = a, _b = (b); i < _b; ++i)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; --i)
#define nl cout << endl
#define endl '\n'
#define JUDGE(name) if (fopen(name".inp", "r")) { freopen(name".inp","r",stdin); freopen(name".out","w",stdout); }
#define ll int64_t
#define pii pair<int,ll>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define all(x) x.begin(), x.end()
#define allr(x) (x).rbegin(), (x).rend()
#define cntbit(x) __builtin_popcountll(x)
#define cntbit0(x) __builtin_ctzll(x)
#define add_edge(u,v) adj[u].emplace_back(v)
#define X first
#define Y second
#define pb emplace_back
#define eb emplace_back
#define MASK(n) (1 << (n))
#define BIT(x,i) (((x) >> (i)) & 1)
#define SETBIT(x,i) (x | MASK(i))
#define LOWBIT(x) (x & (-x))

// MOD
const ll mod = 1e9+7;

template<class X, class Y> bool maximize(X &x, Y y) { if (x < y) { x = y; return 1; } return 0; }
template<class X, class Y> bool minimize(X &x, Y y) { if (x > y) { x = y; return 1; } return 0; }
template<class T> T OnBit (T s, int i) { return s | (T(1) << i); }
template<class T> T OffBit (T s, int i) { return s & (~(T(1) << i));}
template<class T> T TurrnBit (T s, int i) { return s ^ (1 << i); }
template <class T> T Abs(const T &x) { return (x < 0 ? -x : x); }
template<class X, class Y> void add (X &x, Y y, ll mod=mod) { x += y; if (x>=mod) x-=mod;}
template<class X, class Y> void sub (X &x, Y y, ll mod=mod) { x -= y; if (x<0) x+=mod;}

inline void mul(ll &a, ll b, ll mod = mod){ a*=b; a%=mod; }
inline ll prod(ll a, ll b, ll mod = mod){ return mul(a, b), a; }
inline ll binpow(ll a, ll b, ll mod = mod){ ll cur = 1; while (b){ if (b & 1){ mul(cur, a); } mul(a, a); b >>= 1; } return cur; }
inline ll Inv(ll a, ll mod = mod){ return binpow(a, mod - 2); }
inline ll Div(ll a, ll b, ll mod = mod) { return prod(a, Inv(b, mod), mod); }

// declaration
const ll INF = 1e8*1LL;
const ll inf = 1e18;
const ll bit_inf = (1 << 30) - 1;
const ll base = 31;
const int d4x[] = {-1, 1, 0, 0} , d4y[] = {0, 0, -1, 1};
const int d8x[] = {-1, -1, 0, 1, 1, 1, 0, -1}, d8y[] = {0, 1, 1, 1, 0, -1, -1, -1};
const string yesno[] = {"YES","NO"};

typedef tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update> osp;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> os;
typedef pair<vector<int>, vector<int>> pvv;
typedef priority_queue<pii,vector<pii>,greater<pii>> pre_q;

// main code
#define int long long
const int MAXN = 105;
int f[MAXN];
vector<int> compress;

inline void detach (int num) {
    int cnt = 1, cur = num;
    while (cur > 0) {
        cnt *= 10;
        if (cnt >= mod) cnt -= mod;
        cur /= 10;
    }

    cnt /= 10;
    while (num > 0) {
        compress.emplace_back(num / cnt);
        num %= cnt;
        cnt /= 10;
    }
}

inline void woody (void) {
    FOR(i,2,MAXN) {
        bool ok = 1;
        FOR(j,2,(int)sqrt(i)) if (i % j == 0) {
            ok = 0;
            break;
        }

        if (ok) detach(i);
    }

    REP(i,0,compress.size()) {
        if (i==0) f[i] = compress[i];
        else f[i] = prod(f[i-1], compress[i]);
    }

    int casee; cin >> casee;
    while (casee--) {
        int n; cin >> n;
        cout << (n > compress.size() ? 0 : f[n-1]) << endl;
    }
}

woodynguyne {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    JUDGE("woody");
    ll nTest=1;
    while (nTest--) woody();
}
