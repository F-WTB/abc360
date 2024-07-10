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

int N, A[200000], x[200000];

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> A[i];
    vector<int> a(N + 2, 2e9), b(N + 2, 2e9);
    a[0] = -2e9;
    a[1] = A[0];
    b[0] = -2e9;
    b[1] = 0;
    x[0] = 1;
    for (int i = 1; i < N; ++i) {
        x[i] = lower_bound(a.begin(), a.end(), A[i]) - a.begin();
        a[x[i]] = A[i];
        int y = lower_bound(b.begin(), b.end(), A[i]) - b.begin();
        b[y] = A[i];
        chmin(b[x[i - 1] + 1], A[i - 1] + 1);
    }
    int c = 0;
    while (b[c + 1] < 2e9) ++c;
    cout << c << '\n';
}
