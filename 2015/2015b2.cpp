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

const int ROAD = 100;

int main() {
    setIO("speeding");
    optimize();

    int n, m;
    cin >> n >> m;

    vector<int> SPEEDS(ROAD);
    int start = 0;
    for(int _ = 0; _ < n; _++) {
        int length, speed;
        cin >> length >> speed;

        for (int i = start; i < start+length; i++) {
            SPEEDS[i] = speed;
        }
        start += length;
    }

    vector<int> BESSIE(ROAD);
    start = 0;
    for(int _ = 0; _ < m; _++) {
        int length, speed;
        cin >> length >> speed;

        for (int i = start; i < start+length; i++) {
            BESSIE[i] = speed;
        }
        start += length;
    }

    int ans = 0;
    for (int i = 0; i < ROAD; i++) {
        ans = max(ans, BESSIE[i] - SPEEDS[i]);
    }

    cout << ans << endl;
}