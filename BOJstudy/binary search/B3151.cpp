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
const int N = 10005;

int n;
ll cnt = 0;
int arr[N];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cnt += upper_bound(arr + (j + 1), arr + n, -(arr[i] + arr[j])) - lower_bound(arr + (j + 1), arr + n, -(arr[i] + arr[j]));
        }
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