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

string s, num = "";
int sum;
vi p;
vi m;

void mns() {
    sum = 0;
    for (int i = 0; i < m.size(); i++) { sum += m[i]; }
    sum += stoi(num);
    p.push_back(-sum);
    m.clear();
}

void solve() {
    cin >> s;

    bool flag = false;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '-') {
            if (!flag) {
                flag = true;
                p.push_back(stoi(num));
            }
            else mns();
            num = "";
        }
        else if (s[i] == '+') {
            if (flag) m.push_back(stoi(num));
            else p.push_back(stoi(num));
            num = "";
        }
        else num += s[i];
    }

    if (!flag) p.push_back(stoi(num));
    else mns();

    int rs = 0;
    for (int i = 0; i < p.size(); i++) {rs += p[i];}
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