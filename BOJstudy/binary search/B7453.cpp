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
const int N = 4005;

int n;
int a[N], b[N], c[N], d[N];
vi ab;
vi cd;

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0 ; j < n; j++) {
            ab.push_back(a[i] + b[j]);
            cd.push_back(c[i] + d[j]);
        }
    }
    
    sort(cd.begin(), cd.end());

    ll cnt = 0;
    for (int i = 0; i < ab.size(); i++) {
        cnt += upper_bound(cd.begin(), cd.end(), -ab[i]) - lower_bound(cd.begin(), cd.end(), -ab[i]);
    }

    cout << cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}