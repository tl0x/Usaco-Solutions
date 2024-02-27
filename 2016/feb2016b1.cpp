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
    setIO("pails");
    optimize();

    int x, y, m; 
    cin >> x >> y >> m;
    int ans = 0;
    for (int i = 0; i < (m/x) + 1; i++) {
        for (int j = 0; j < (m/y) + 1; j++) { 
            int value = (x*i) + (y*j);
            if (value > m) {
                break;
            }
            ans = max(ans, value);
        }
    }

    cout << ans << endl;
}