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

int N, L[100000], R[100000];
vector<int> v = {0, int(1e9 + 1)};

int op(int x, int y) { return max(x, y); }
int e() { return 0; }
int add(int f, int x) { return f + x; }

int m = 0, ans_l = 0, ans_r = 1;

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> L[i] >> R[i];
        v.push_back(L[i]);
        v.push_back(L[i] + 1);
        v.push_back(R[i]);
        v.push_back(R[i] + 1);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    vector<vector<pair<pr, int>>> q(v.size());

    int K = v.size() - 1;
    for (int i = 0; i < N; ++i) {
        int l = lower_bound(v.begin(), v.end(), L[i]) - v.begin();
        int r = lower_bound(v.begin(), v.end(), R[i]) - v.begin();

        q[0].emplace_back(make_pair(l + 1, r), 1);
        q[l].emplace_back(make_pair(l + 1, r), -1);
        q[l + 1].emplace_back(make_pair(r + 1, K), 1);
        q[r].emplace_back(make_pair(r + 1, K), -1);
    }

    lazy_segtree<int, op, e, int, add, add, e> seg(K);
    for (int x = 0; x < K; ++x) {
        for (auto [p, a] : q[x]) seg.apply(p.first, p.second, a);

        int t = seg.all_prod();
        if (t > m) {
            int y = seg.max_right(0, [t](int c) { return c < t; });
            m = t;
            ans_l = v[x];
            ans_r = v[y];
        }
    }
    cout << ans_l << ' ' << ans_r << '\n';
}
