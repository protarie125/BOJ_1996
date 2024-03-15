#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<double>;
using vii = vector<pii>;
using vll = vector<pll>;
using vs = vector<string>;

using vvb = vector<vb>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vvd = vector<vd>;

ll n;
vs F;
vvl ans;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> n;

  F = vs(n);
  for (auto&& x : F) {
    cin >> x;
  }

  ans = vvl(n, vl(n, 0));
  for (auto i = 0LL; i < n; ++i) {
    for (auto j = 0LL; j < n; ++j) {
      if ('.' != F[i][j]) {
        ans[i][j] = -1;
        const auto& c = F[i][j] - '0';

        for (auto ii = -1; ii <= 1; ++ii) {
          for (auto jj = -1; jj <= 1; ++jj) {
            if (0 == ii && 0 == jj) {
              continue;
            }

            if (i + ii < 0 || n <= i + ii || j + jj < 0 || n <= j + jj) {
              continue;
            }

            if ('.' != F[i + ii][j + jj]) {
              continue;
            }

            ans[i + ii][j + jj] += c;
          }
        }
      }
    }
  }

  for (const auto& v : ans) {
    for (const auto& x : v) {
      if (-1 == x) {
        cout << '*';
      } else if (10 <= x) {
        cout << 'M';
      } else {
        cout << x;
      }
    }
    cout << '\n';
  }

  return 0;
}