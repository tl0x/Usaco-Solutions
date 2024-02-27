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
    setIO("NameHere");
    optimize();

	int x, y;
	cin >> x >> y;

	vector<int> zigzag;

	if (x == y) {
		cout << 0 << endl;
	} 
	else if (x < y) {
		int dist = 1;

		while (x + dist < y) {
			zigzag.push_back(x + dist);
			dist *= -2;
		}

		zigzag.push_back(x + dist);

		int ans = 1;

		for (int i = 0; i < zigzag.size() -1; i++) { 
			ans += abs(zigzag[i] - zigzag[i + 1]); 
		}

		ans -= (zigzag[zigzag.size() - 1] - y);
		cout << ans << endl;
	} 
	else {
		int dist = 1;

		while (x + dist > y) {
			zigzag.push_back(x + dist);
			dist *= -2;
		}

		zigzag.push_back(x + dist);

		int ans = 1;

		for (int i = 0; i < zigzag.size() -1; i++) {
			ans += abs(zigzag[i] - zigzag[i + 1]); 
		}

		ans -= (y - zigzag[zigzag.size() - 1]);
		cout << ans << endl;
	}
}