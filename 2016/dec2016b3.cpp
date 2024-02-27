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
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}


int main() {
    optimize();
    setIO("cowsignal");
    
    int m, n, k;
    cin >> m >> n >> k;
    
    vector<string> input(m);
    for (string &r: input) {
        cin >> r;
    }

    for (int i = 0; i < m*k; i++) {
        for (int j = 0; j < n*k; j++) {
            cout << input[i / k][j / k];
        }
        cout << "\n";
    }
}