#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef vector<int> vi;
typedef pair<int, int> pi;
const char nl = '\n';

int n;
multiset<int> team;
vector<pi> st;

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int h, k; cin >> h >> k;
        st.push_back({h, k});
    }
    sort(st.begin(), st.end());

    int idx = st.size();
    while (idx-- > 0) {
        if (st[idx].Y == 1)  team.insert(1);
        else {
            if (!team.size()) { team.insert(1); continue; }
            auto it = team.lower_bound(st[idx].Y);
            if (it != team.begin()) it--;
            else { team.insert(1); continue; }
            int tmp = *it;
            team.erase(it);
            team.insert(tmp + 1);
        }
    }
    cout << team.size();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}