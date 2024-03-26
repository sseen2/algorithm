#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    stack<pair<int, int>> s; // 탑의 높이와 인덱스를 저장하는 스택
    s.push({a[0], 1});
    cout << 0 << " ";   // 첫 탑은 무조건 0

    for(int i = 1; i < n; i++) {
        while (!s.empty() && s.top().first < a[i]) s.pop();

        if ((!s.empty() && s.top().first > a[i])) cout << s.top().second << " ";
        else if (s.empty()) cout << 0 << " ";
        // s가 비었다 = 앞선 탑 중에 현재 탑보다 큰 탑이 없다

        s.push({a[i], i + 1});
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
}