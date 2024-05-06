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
string s[1000005];
ll num[1000005];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++) {
        reverse(s[i].begin(), s[i].end());
        num[i] = stoll(s[i]);
    }
    sort(num, num + n);
    for (int i = 0; i < n; i++) cout << num[i] << nl;
} 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}