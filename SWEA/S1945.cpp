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

int num[] = {2, 3, 5, 7, 11};

void solve() {
    int n; cin >> n;
    vector<int> a(5);

    for (int i = 0; i < 5; i++) {
        while (n % num[i] == 0) {
            a[i]++;
            n = n / num[i];
        }
    }

    for (int i = 0; i < 5; i++) cout << a[i] << " ";
    cout << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "#" << i << " ";
        solve();
    }
}