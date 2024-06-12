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
const int N = 500'005;

int n, m;
int arr[N];

int lower_idx(int num) {
    int st = 0, en = n;
    while (st < en) {
        int mid = (st + en) / 2;
        if (arr[mid] >= num) en = mid;
        else st = mid + 1;
    }
    return st;
}

int upper_idx(int num) {
    int st = 0, en = n;
    while (st < en) {
        int mid = (st + en) / 2;
        if (arr[mid] > num) en = mid;
        else st = mid + 1;
    }
    return st;
}


void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    cin >> m;
    while (m--) {
        int num; cin >> num;
        cout << upper_idx(num) - lower_idx(num) << " ";
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