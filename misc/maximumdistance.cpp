// author: taylor
// solution to this problem : https://codeforces.com/gym/102951/problem/A

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
    vi x(n), y(n);

    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    for (int &i : y) {
        cin >> i;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int distance = ((x[j]-x[i])*(x[j]-x[i])) + ((y[j]-y[i])*(y[j]-y[i]));
            ans = max(ans, distance);
        }
    }

    cout << ans << endl;
}