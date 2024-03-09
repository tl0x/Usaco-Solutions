#include <iostream>
#include <set>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <unordered_map>
#include <cmath>

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

    int N; cin >> N;
    string cows; cin >> cows;
    vector<pair<int,int> > intervals;

    int sz = 0;
    for (int i = 0; i <= N; i++) {
        if (i < N && cows[i]=='1') {
            sz++;
        } else if (sz > 0) {
            pair<int, int> temp;
            temp.first = i-sz;
            temp.second = i-1;
            intervals.push_back(temp);
            sz = 0;
        }
    }

    if (intervals.size() == 0) {
        cout << 0 << "\n";
        return 0;
    }

    int D = 1e9; 
    for (pair<int,int> p: intervals) {
        int x = p.second - p.first + 1;
        if (p.first == 0 || p.second == N-1) {
            D = min(D,x);
        } else {
            D = min(D,(x+1)/2);
        }
    }

    int ans = 0;
    for (pair<int,int> p: intervals) {
        int x = p.second - p.first + 1;
        int c = (x + 2*D-2)/(2*D-1);
        ans += c;
    }
    cout << D << endl;
    cout << ans;
}