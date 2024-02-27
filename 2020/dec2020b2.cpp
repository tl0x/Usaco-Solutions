// code by taylor
// prefix sum is unneeded because constraints are tiny, but i used it for practice.

#include <iostream>
#include <set>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <unordered_map>

using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

using ll = long long;
using vi = std::vector<int>;

#define optimize() ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007;
#define sortcut(x) x.begin(), x.end();

void setIO(string name = "") {
    if (name == "NameHere") {
        return;
    }

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main() {
    setIO("NameHere");
    optimize();

    int n; cin >> n;
    vi flowers(n);
    for (int &i: flowers) {
        cin >> i;
    }
    vi prefix(n + 1);
    prefix[0] = 0;
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + flowers[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            double average = prefix[j + 1] - prefix[i];
            average /= j-i+1;
            for (int f = i; f <= j; f++) {
                if (flowers[f] == average) {
                    ans += 1;
                    break;
                }
            }
        }
    }

    cout << ans << endl;
}