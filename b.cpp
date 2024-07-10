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

string S, T;

int main() {
    cin >> S >> T;
    for (int w = 1; w < S.size(); ++w) {
        for (int c = 0; c < w; ++c) {
            string U;
            for (int i = 0; i + c < S.size(); i += w) U += S[i + c];
            if (U == T) {
                cout << "Yes" << '\n';
                return 0;
            }
        }
    }
    cout << "No\n";
}
