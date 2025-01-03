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
#define pii pair<int,int>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define all(x) x.begin(), x.end()
#define allr(x) (x).rbegin(), (x).rend()
#define cntbit(x) __builtin_popcountll(x)
#define cntbit0(x) __builtin_ctzll(x)
#define X first
#define Y second
#define pb emplace_back
#define eb emplace_back
#define MASK(n) (1 << (n))
#define BIT(x,i) (((x) >> (i)) & 1)
#define SETBIT(x,i) (x | MASK(i))
#define LOWBIT(x) (x & (-x))

// MOD
const ll mod = 1e9;

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
const ll INF = 0x3f3f;
const ll inf = 1e9;
const ll bit_inf = (1 << 30) - 1;
const ll base = 31;
const int d4x[] = {-1, 1, 0, 0} , d4y[] = {0, 0, -1, 1};
const int d8x[] = {-1, -1, 0, 1, 1, 1, 0, -1}, d8y[] = {0, 1, 1, 1, 0, -1, -1, -1};
const string yesno[] = {"YES","NO"};

typedef tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update> osp;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> os;
typedef pair<vector<int>, vector<int>> pvv;
typedef priority_queue<int,vector<int>,greater<int>> pre_q;

// main code
#define int long long
const int MAXN = 2e5+5;
int n,a[MAXN],ok[MAXN],dp[MAXN];

inline void woody (void) {
    cin >> n;
    FOR(i,1,n) cin >> a[i], ok[i] = a[i] % 3;
    dp[0]=0;
    FOR(i,1,n) dp[i] = (ok[i] == 0 ? 0 : dp[i-1] + a[i]);
    int res = 0;
    FOR(i,1,n) maximize(res,dp[i]);
    cout << res;
}

woodynguyne {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    JUDGE("woody");
    ll nTest=1;
    //cin >> nTest;
    while (nTest--) woody();
}
