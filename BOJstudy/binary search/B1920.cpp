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

int n, m;
int a[100'005];

int bs(int num) {
    int st = 0, en = n - 1;
    while(st <= en) {
        int mid = (st + en) / 2;
        if (a[mid] < num) st = mid + 1;
        else if (a[mid] > num) en = mid - 1;
        else return 1;
    }
    return 0;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    cin >> m;
    for (int i = 0; i < m; i++) { 
        int num; 
        cin >> num; 
        cout << bs(num) << nl; 
        
        // STL을 이용한 코드
        // * 무조건 정렬 되어 있을 때 사용할 것
        // cout << binary_search(a, a + n, num) << nl;
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