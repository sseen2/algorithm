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
const int N = 105;

int n, k, rs = 0;
bool m[N];   // 멀티탭
int e[N];   // 전기 용품 순서

void printm() {
    for (int i = 1; i <= k; i++) if (m[i]) cout << i << " ";
    cout << nl;
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i < k; i++) cin >> e[i];

    int cnt = 0;
    for (int i = 0; i < k; i++) {
        if (m[e[i]]) continue; // 지금 쓰려고 하는 게 멀티탭에 꽂혀있다면 그냥 넘어감
        if (cnt < n) {  // 멀티탭이 아직 비었다면 -> 무조건 꽂음 
            cnt++;
            m[e[i]] = 1;
        }
        else {  // 멀티탭이 찼으면 -> 멀티탭에 꽂혀있는 것 중 가장 나중에 나오는 한 전기용품의 플러그를 뽑음
            int mx = 0, idx = 0;
            for (int j = 1; j <= k; j++) {
                if (m[j]) {
                    int l = k;
                    for (int h = i + 1; h < k; h++) 
                        if (j == e[h]) { l = h - i; break; }
                    if (mx < l) {
                        idx = j;
                        mx = l;
                    }
                }
            }
            
            m[idx] = 0;
            m[e[i]] = 1;
            rs++;
        }
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