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
const int N = 55;

int n, num;
vl sn;  // 음수(0 포함) 저장
vl sp;  // 양수 저장

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (num <= 0) sn.push_back(num);
        else sp.push_back(num);
    }
    if (n == 1) { cout << num; return; }
    sort(sp.rbegin(), sp.rend());
    sort(sn.begin(), sn.end());

    ll rs = 0;
    for (int i = 0; i < sp.size(); i++) {
        if (i == sp.size() - 1) rs += sp[i];    // 마지막 남은 수는 묶을 수 없으므로 무조건 더함
        else if (sp[i + 1] == 1) rs += sp[i++] + sp[i];     // 현재 수가 1일 때, 묶을 수 없음
        else rs += sp[i++] * sp[i];     // 두 수 모두 양수일 때, 묶을 수 있음
    }

    for (int i = 0; i < sn.size(); i++) {
        if (i == sn.size() - 1) rs += sn[i];
        else if (sn[i + 1] == 0) continue;
        else rs += sn[i++] * sn[i];
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