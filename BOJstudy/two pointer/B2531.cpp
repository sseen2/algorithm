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
const int N = 30'005;
const int D = 3'005;

int n, d, k, c;
int a[N + D];
int isused[D];

void print() {
    for (int i = 1; i <= d; i++) if(isused[i] > 0) cout << i << " ";
    cout << nl;
}

void solve() {
    cin >> n >> d >> k >> c;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = n; i < n + k; i++) a[i] = a[i - n];
    
    int en = 0, acnt = 0, mx = 0;
    isused[c] = 1;
    for (int st = 0; st < n + k; st++) {
        while (en < n + k && acnt < k) {
            isused[a[en++]]++;
            acnt++;
            if (acnt == k) break;
        }

        int cnt = 0;
        for (int j = 1; j <= d; j++)
            if (isused[j] > 0) cnt++;
        mx = max(mx, cnt);
        if (a[st] != c) isused[a[st]]--;
        acnt--;
    }

    cout << mx;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}