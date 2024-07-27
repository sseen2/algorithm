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
const int N = 1005;

int n, rs = 0;
int p[N];
int t[N];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> p[i];
    sort(p, p + n);

    t[0] = p[0];
    for (int i = 1; i < n; i++) t[i] = t[i - 1] + p[i];
    
    for (int i = 0; i < n; i++) rs += t[i];
    cout << rs;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}