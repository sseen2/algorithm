#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';

int n, m, p, l;
map<int, int> pb;
multiset<int> lv;

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p >> l;
        pb[p] = l;
        lv.insert(l);
    }

    cin >> m;
    while (m--) {
        string cmd; cin >> cmd;
        if (cmd == "add") {
            cin >> p >> l;
            pb[p] = l;
            lv.insert(l);
        }
        else if (cmd == "recommend") {
            int x; cin >> x;
            auto itp = pb.end(); itp--;
            auto itl = lv.end(); itl--;
            if (x == -1) { itp = pb.begin(); itl = lv.begin(); }

            while (*itl != itp->second && itp != pb.end()) 
                if (x == 1) itp--;
                else itp++;
            cout << itp->first << nl;
        }
        else if (cmd == "solved") {
            cin >> p;
            lv.erase(lv.find(pb[p]));
            pb.erase(p);
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