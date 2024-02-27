// author: taylor
// finally solved one by myself

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
    setIO("blist");
    optimize();

    int n; cin >> n;
    const int MAX_TIME = 1000;
    vi buckets(MAX_TIME+1, 0);

    for (int i = 0; i < n; i++) {
        int start, end, amount;
        cin >> start >> end >> amount;

        buckets[start] += amount;
        buckets[end] -= amount;
    }

    int ans = 0;
    int current = 0;
    for (int i = 0; i < buckets.size(); i++) {
        current += buckets[i];
        ans = max(ans, current);
    }

    cout << ans << endl;
}