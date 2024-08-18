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

int n;
int a[N];
vi two;

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);

    for (int i = 0; i < n; i++) 
        for (int j = i; j < n; j++) 
            two.push_back(a[i] + a[j]);
    sort(two.begin(), two.end());

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            if (binary_search(two.begin(), two.end(), a[i] - a[j])) {
                cout << a[i];
                return;
            }
        }
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