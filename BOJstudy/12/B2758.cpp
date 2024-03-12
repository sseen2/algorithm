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

int n, m, cnt;
int arr[15];
int isused[2005];

void func(int k, int val) {
    if (k == n) {
        cnt++;
        return;
    }

    for (int i = val; i <= m; i++) {
        if(isused[i]) continue;
        arr[k] = i;
        isused[i] = 1;
        func(k + 1, i * 2);
        isused[i] = 0;
    }
}

void solve() {
    cin >> n >> m;
    func(0, 1);
    cout << cnt << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
}