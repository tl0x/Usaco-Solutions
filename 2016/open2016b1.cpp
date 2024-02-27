// code by taylor

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
    setIO("diamond");
    optimize();

    int n, k; cin >> n >> k;
    vi sizes(n);
    for (int &i: sizes) {
        cin >> i;
    }

    int ans = 0;
    for (int x : sizes) {
		int valid = 0;
		for (int y : sizes) {
			if (x <= y && y <= x + k) { valid++; }
		}
		ans = max(ans, valid);
	}

    cout << ans << endl;
}