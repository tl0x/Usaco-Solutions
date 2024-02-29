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

unordered_map<int, int> dp;

int fib(int n) {
    if (dp.find(n) != dp.end()) {
        return dp[n];
    }
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    int temp = fib(n-1) + fib(n-2);

    dp[n] = temp;
    return temp;
}

int main() {
    setIO("NameHere");
    optimize();

    cout << fib(10) << endl;
}