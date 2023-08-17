#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    string cmd; int n; cin >> cmd >> n;
    string s; cin >> s;
    deque<int> x;
    string num = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '[' && s[i] != ']' && s[i] != ',') {
            num.push_back(s[i]);
        }
        if (s[i] == ',' || s[i] == ']') {
            if (num.size() != 0)            
                x.push_back(stoi(num));
            num = "";
        }
    }

    bool isReverse = false;

    for (int i = 0; i < cmd.size(); i++)
    {
        if (cmd[i] == 'R') isReverse = !isReverse;
        else if (cmd[i] == 'D') {
            if (x.empty()) {
                cout << "error" << '\n';
                return;
            }
            
            if (!isReverse) x.pop_front();
            else x.pop_back();
        }
    }

    if (isReverse) {
        cout << "[";
        if (x.empty()) {
            cout << "]" << '\n';
            return;
        }
        while (x.size() != 1) {
            cout << x.back() << ",";
            x.pop_back();
        }
        cout << x.back() << "]\n";
    }
    else {
        cout << "[";
        if (x.empty()) {
            cout << "]" << '\n';
            return;
        }
        while (x.size() != 1) {
            cout << x.front() << ",";
            x.pop_front();
        }
        cout << x.front() << "]\n";
    }
        
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
}