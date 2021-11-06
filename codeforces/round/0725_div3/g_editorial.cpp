#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>
#include <unordered_map>
#include <unordered_set>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

void solve() {
    ll x, y, a, b;
    cin >> x >> y >> a >> b;
    ll l = 0, r = 1e9 + 100;
    if (a == b) {
        cout << min(x, y) / a << "\n";
        return;
    }
    if (a < b) {
        swap(a, b);
    }
    while (r - l > 1) {
        ll m = (l + r) / 2;
        ll right = floorl((x - m * b) * 1.0l / (a - b));
        ll left = ceill((y - m * a) * 1.0l / (b - a));
        if (max(left, 0ll) <= min(right, m)) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << l << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
