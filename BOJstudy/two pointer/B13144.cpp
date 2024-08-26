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
const int N = 100'005;

ll n;
ll a[N];
bool num[N];

void printnum() {
    for (int i = 0; i < n; i++) if (num[i]) cout << i << " ";
    cout << nl;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    ll en = 0, rs = 0;
    for (int st = 0; st < n; st++) {
        while (en < n && !num[a[en]]) {
            num[a[en++]] = 1;
            rs += en - st;
        }
        num[a[st]] = 0;
    }

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