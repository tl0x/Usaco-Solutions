// easy sorting question

#include <iostream>
#include <set>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <unordered_map>
#include <cstring>
#include <queue>
#include <cmath>
#include <climits>

using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

using ll = long long;
using vi = std::vector<int>;

#define optimize() ios_base::sync_with_stdio(false);cin.tie(NULL)
#define mod 1000000007;
#define sortcut(x) x.begin(), x.end()
#define printl(x, size) for(int i=0; i<size; i++) cout << x[i] << endl;


int main() {
    optimize();
    int n; cin >> n;
    int cows[n];

    for (int i = 0; i < n; i++) {
        cin >> cows[i];    
    }

    sort(cows, cows + n);
    ll max_money = 0;
    ll optimal = 0;
    for (int i = 0; i < n; i++) {
        ll value = (ll)cows[i]*(n-i);
        if (value > max_money) {
            max_money = value;
            optimal = cows[i];
        }
    }
    cout << max_money << " " << optimal << endl;
}