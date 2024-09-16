#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
const char nl = '\n';
const int N = 1005;

int n, m, cnt = 0;
map<string, int> ntoi;
vector<string> rsp;
vector<string> rs;
string name[N];
string iton[N];
vi g[N];
vi c[N];
int deg[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> name[i];

    sort(name, name + n + 1);
    for (int i = 1; i <= n; i++) {
        ntoi[name[i]] = i;
        iton[i] = name[i];
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        string s1, s2; cin >> s1 >> s2;
        int a = ntoi[s1], b = ntoi[s2];
        g[b].push_back(a);
        deg[a]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) 
        if (deg[i] == 0) {
            q.push(i);
            rsp.push_back(iton[i]);
            cnt++;
        }
    
    cout << cnt << nl;
    sort(all(rsp));
    for (int i = 0; i < rsp.size(); i++) cout << rsp[i] << " ";
    cout << nl;

    while(!q.empty()) {
        int cur = q.front(); q.pop();
        rs.push_back(iton[cur]);
        for (int nxt : g[cur]) {
            deg[nxt]--;
            if (deg[nxt] == 0) { q.push(nxt); c[cur].push_back(nxt); }
        }
    }

    for (int i = 1; i <= n; i++) 
        sort(all(c[i]));
    sort(all(rs));
    
    for (int i = 0; i < rs.size(); i++) {
        int cur = ntoi[rs[i]];
        cout << rs[i] << " " << c[cur].size() << " ";
        for (int nxt : c[cur]) cout << iton[nxt] << " ";
        cout << nl;
    }
}


// *****************************************
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}