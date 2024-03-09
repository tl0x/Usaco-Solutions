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

	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main() {
    setIO("NameHere");
    optimize();

    int n, m; cin >> n >> m;
    ll heights[n];
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    for (int _ = 0; _ < m; _++) {
        int candy_cane; cin >> candy_cane;
        int amount_taken = 0;
        for (int i = 0; i < n; i++) {
            int increment = max(0, (int)min((ll)candy_cane, heights[i])-amount_taken);
            heights[i] += increment;
            amount_taken += increment;
            if (amount_taken >= candy_cane) {
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << heights[i] << "\n";
    }
}