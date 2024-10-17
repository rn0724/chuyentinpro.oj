// DEMUOC.cpp
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = a, _b = (b); i <= _b; ++i)
#define REP(i, a, b) for (int i = a, _b = (b); i < _b; ++i)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; --i)
#define nl cout << endl
#define endl '\n'
#define JUDGE(name) if (fopen(name".inp", "r")) { freopen(name".inp","r",stdin); freopen(name".out","w",stdout); }
#define ll long long
const int MAXN = 0;
ll n;

inline void solve (void) {
    cin >> n;
    ll res=0;
    FOR(i,1,(ll)sqrt(n)) if (n % i == 0) res += ((i == n/i) ? 1 : 2);
    cout << res;
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    JUDGE("DEMUOC");
    ll nTest=1;
    while (nTest--) solve();
}



// BOI30.cpp
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = a, _b = (b); i <= _b; ++i)
#define REP(i, a, b) for (int i = a, _b = (b); i < _b; ++i)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; --i)
#define nl cout << endl
#define endl '\n'
#define JUDGE(name) if (fopen(name".inp", "r")) { freopen(name".inp","r",stdin); freopen(name".out","w",stdout); }
#define ll int64_t
#define all(x) x.begin(), x.end()
#define int long long
const int MAXN = 0;
string s;

inline void solve (void) {
    cin >> s;
    ll sum = 0;
    REP(i,0,s.size()) sum += (s[i] - '0');
    if (sum % 3 != 0) cout << -1 << endl;
    else {
        sort(all(s));
        reverse(all(s));
        cout << s;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    JUDGE("BOI30");
    ll nTest=1;
    while (nTest--) solve();
}


// TDSLT.cpp
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = a, _b = (b); i <= _b; ++i)
#define REP(i, a, b) for (int i = a, _b = (b); i < _b; ++i)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; --i)
#define nl cout << endl
#define endl '\n'
#define JUDGE(name) if (fopen(name".inp", "r")) { freopen(name".inp","r",stdin); freopen(name".out","w",stdout); }
#define ll int64_t
#define int long long
const int MAXN = 1e5+5;
int n,k,pos,a[MAXN],res;

inline void woody (void) {
    cin >> n >> k >> pos;
    FOR(i,1,n) cin >> a[i];
    FOR(i,pos,pos+k-1) res += a[(i % n == 0 ? n : i % n)];
    cout << res;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    JUDGE("TDSLT");
    ll nTest=1;
    while (nTest--) woody();
}


// DAYLOM.cpp
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = a, _b = (b); i <= _b; ++i)
#define REP(i, a, b) for (int i = a, _b = (b); i < _b; ++i)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; --i)
#define nl cout << endl
#define endl '\n'
#define JUDGE(name) if (fopen(name".inp", "r")) { freopen(name".inp","r",stdin); freopen(name".out","w",stdout); }
#define ll int64_t

template<class X, class Y> bool maximize(X &x, Y y) { if (x < y) { x = y; return 1; } return 0; }
template<class X, class Y> bool minimize(X &x, Y y) { if (x > y) { x = y; return 1; } return 0; }

// main code
#define int long long
const int MAXN = 5005;
const ll INF = 0x3f3f3f;
int n,a[MAXN],b[MAXN],dp[MAXN][2],pos1[MAXN], pos2[MAXN];
int f[MAXN];

inline int bsearch_1 (int x, int l, int r) {
    int res = 0;
    while (l <= r) {
        int mid = (l+r) >> 1;
        if (a[pos1[mid]] > x) {
            res = mid;
            l = mid+1;
        } else r = mid-1;
    }
    return pos1[res];
}

inline int bsearch_2 (int x, int l, int r) {
    int res = 0;
    while (l <= r) {
        int mid = (l+r) >> 1;
        if (b[pos2[mid]] > x) {
            res = mid;
            l = mid+1;
        } else r = mid-1;
    }
    return pos2[res];
}

inline void woody (void) {
    cin >> n;
    FOR(i,1,n) cin >> a[i], b[n-i+1] = a[i];

    pos1[1] = dp[1][0] = 1;
    int ans = 1;
    FOR(i,2,n) {
        int tmp = bsearch_1(a[i], 1, dp[ans][0]);
        dp[i][0] = dp[tmp][0] + 1;
        pos1[dp[i][0]] = i;
        if (dp[i][0] > dp[ans][0]) ans = i;
    }

    pos2[1] = dp[1][1] = 1;
    ans = 1;
    FOR(i,2,n) {
        int tmp = bsearch_2(b[i], 1, dp[ans][1]);
        dp[i][1] = dp[tmp][1] + 1;
        pos2[dp[i][1]] = i;
        if (dp[i][1] > dp[ans][1]) ans = i;
    }

    int res = -INF;
    FOR(i,1,n) {
        f[i] = (dp[i][0] == 1 || dp[n-i+1][1] == 1) ? 0 : dp[i][0] + dp[n-i+1][1] - 1;
        maximize(res,f[i]);
    }
    cout << res;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    JUDGE("DAYLOM");
    ll nTest=1;
    while (nTest--) woody();
}
