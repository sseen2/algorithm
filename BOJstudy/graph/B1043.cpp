#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const char nl = '\n';
const int N = 55;
int n, m, t, cnt;
vi g[N];     // 각 파티의 참여자 그래프
bool kt[N];  // 진실을 아는 사람 : 1
vi party[N]; // 파티

void solve() {
    cin >> n >> m >> t;
    if (t == 0) { cout << m; return; }

    for(int i = 0; i < t; i++) {
        int a; cin >> a;
        kt[a] = 1;
    }
    
    for (int i = 0; i < m; i++) {
        int p, pre; cin >> p >> pre;
        party[i].push_back(pre);
        for (int j = 1; j < p; j++) {
            int cur; cin >> cur;
            party[i].push_back(cur);
            g[pre].push_back(cur);
            g[cur].push_back(pre);
            pre = cur;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!kt[i]) continue;
        queue<int> q;
        q.push(i);
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            for (auto nxt : g[cur]) {
                if (kt[nxt]) continue;
                q.push(nxt);
                kt[nxt] = 1;
            }
        }
    }

    for (int i = 0; i < m; i++) 
        for (int j = 0; j < party[i].size(); j++)
            if (kt[party[i][j]]) { cnt++; break; }

    cout << m - cnt;
}


// *****************************************
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}