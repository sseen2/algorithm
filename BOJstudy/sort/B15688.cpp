#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define ll long long
#define X first
#define Y second

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;

const char nl = '\n';

int n;
int num[2000005];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        num[1000000 + a]++;
    }

    int cnt = 0;
    for (int i = 0; i <= 2000000; i++) {
        while (num[i]--) cout << i - 1000000 << nl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}