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

vector<int> grass_type;
vector<vector<int> > neighbors;

void dfs(int at, int previous) {
	int currentType = 1;
	for (int n : neighbors[at]) {
		if (n == previous) {
			continue;
		}

		while (currentType == grass_type[at] || currentType == grass_type[previous]) {
			currentType += 1;
		}

		grass_type[n] = currentType;
		dfs(n, at);
		currentType += 1;
	}
 }

int main() {
    setIO("planting");
    optimize();
	int n; cin >> n;

	grass_type = vector<int>(n);
	neighbors = vector<vector<int> >(n);

	grass_type[0] = 1;

	for (int i = 0; i < n-1; i++) {
		int field1, field2; cin >> field1 >> field2;
		field1--;
		field2--;
		neighbors[field1].push_back(field2);
		neighbors[field2].push_back(field1);
	}

	dfs(0, 0);

	int smallest = 0;
	for (int t: grass_type) {
		smallest = max(t, smallest);
	}

	cout << smallest << endl;
}