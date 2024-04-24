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

int n, mx = INT_MIN, mn = INT_MAX;
int num[15];
int opernum[4];    // 덧셈, 뺄셈, 곱셈, 나눗셈
int oper[15];

int cal() {
    int result = num[0];
    for (int i = 1; i < n; i++) {
        if (oper[i - 1] == 0) result += num[i];
        else if (oper[i - 1] == 1) result -= num[i];
        else if (oper[i - 1] == 2) result *= num[i];
        else result /= num[i];
    }
    return result;
}

void func(int k) {
    if (k == n - 1) {
        int c = cal();
        mx = max(mx, c);
        mn = min(mn, c);
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (opernum[i] == 0) continue;
        oper[k] = i;
        opernum[i]--;
        func(k + 1);
        opernum[i]++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    for (int i = 0; i < 4; i++) {
        cin >> opernum[i];
    }

    func(0);

    cout << mx << nl << mn;
}