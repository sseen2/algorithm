#include <bits/stdc++.h>
using namespace std;
const int N = 1005;

void solve() {
    string s; cin >> s;
    int n = s.length(), mn = N, a = 0;
    for (int i = 0; i < n; i++) 
        if (s[i] == 'a') a++;
    
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = i; j < i + a; j++) 
            if (s[j % n] == 'b') cnt++;
        
        mn = min(mn, cnt);
    }
    
    cout << mn;
}


// *****************************************
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}