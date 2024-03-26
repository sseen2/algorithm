#include <bits/stdc++.h>
using namespace std;

void solve() {
    int dwarf[9];
    int sum = 0;
    for (int i = 0; i < 9; i++) {
        cin >> dwarf[i]; // 입력
        sum += dwarf[i]; // 키의 총 합
    }
    
    bool flag = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 9; j++) {
            if (dwarf[i] + dwarf[j] == sum - 100) {
                dwarf[i] = dwarf[j] = 0;
                flag = 1;
            }
        }
        if (flag)
        break;
    }

    sort(dwarf, dwarf + 9);
    // 난쟁이 출력
    for (int i = 2; i < 9; i++) {
        cout << dwarf[i] << '\n';
    }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  solve();
}