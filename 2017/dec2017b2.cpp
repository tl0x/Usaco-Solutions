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
    setIO("shuffle");
    optimize();

    int n;
    cin >> n;
    vector<int> shuffles(n);
    vector<int> ids(n);
    for (int i = 0; i < n; i++) {
        cin >> shuffles[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> ids[i];
    }

    for (int j = 0; j < 3; j++) {
        vector<int> shuffled(n);
        for(int i = 0; i < n; i++) {
            shuffled[i] = ids[shuffles[i]-1];
        }
        ids = shuffled;
    }
    
    for(int i = 0; i < n; i++) {
        cout << ids[i] << endl;
    }
}