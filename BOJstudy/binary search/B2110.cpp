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
const int N = 200005;

int n, c;
int house[N];

// mid보다 크거나 같은 거리에 공유기를 c개 놓을 수 있는가?
bool Check(const int mid) {
    int cnt = 1;
    int pre = house[0];

    for (int i = 1; i < n; i++) {
        if (house[i] - pre < mid) continue;
        pre = house[i];
        cnt++;
    }
    return cnt >= c;
}

int bs() {
    int lo = 1, hi = house[n - 1] + 1;
    // Check(lo) = T, Check(hi) = F

    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (Check(mid)) lo = mid;
        else hi = mid;
    }

    return lo;
}

void solve() {
    cin >> n >> c;
    for (int i = 0; i < n; i++) cin >> house[i];
    sort(house, house + n);
    cout << bs();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}