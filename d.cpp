#include <bits/stdc++.h>
#include <atcoder/all>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using namespace atcoder;
using ll = long long;
using bint = boost::multiprecision::cpp_int;
using mint = modint998244353;
using pr = pair<int, int>;
ostream &operator<<(ostream &os, const mint &x) {
    os << x.val();
    return os;
}
template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
struct fast {
    fast() {
        cin.tie(0);
        ios::sync_with_stdio(0);
    }
} fast;

int N, X;
ll T;
string S;

int main() {
    cin >> N >> T >> S;
    vector<ll> l, r;
    for (int i = 0; i < N; ++i) {
        cin >> X;
        (S[i] == '0' ? l : r).push_back(X);
    }

    sort(l.begin(), l.end());

    ll ans = 0;
    for (ll x : r)
        ans += upper_bound(l.begin(), l.end(), x + 2 * T) - upper_bound(l.begin(), l.end(), x);

    cout << ans << '\n';
}
