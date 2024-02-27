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
    setIO("lostcow");
    optimize();

	int x, y;
	cin >> x >> y;

	vector<int> path;

	if (x == y) {
		cout << 0 << endl;
	} 
	else {
		int dist = 1;
		if (x < y) {
			while (x + dist < y) {
				path.push_back(x + dist);
				dist *= -2;
			}
		}
		else if (x > y) {
			while (x + dist > y) {
				path.push_back(x + dist);
				dist *= -2;
			}
		}

		path.push_back(x+dist);

		int ans = 1;
		for (int i = 0; i < path.size()-1; i++) {
			ans += abs(path[i] - path[i+1]);
		}

		ans -= abs(y - path[path.size()-1]);
		cout << ans << endl;
	}

}