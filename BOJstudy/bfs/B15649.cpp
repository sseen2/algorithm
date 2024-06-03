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

int n, m;
int arr[10]; // 수열을 담을 배열
bool isused[10]; // 특정 수가 쓰였는지 확인하는 배열

void func(int k) { // 현재 k개까지 수를 택했음
    if (k == m) { // m개를 모두 택했으면
        for (int i = 0; i < m; i++) cout << arr[i] << ' ';
        cout << nl; // arr에 기록해둔 수를 출력
        return;
    }

    for (int i = 1; i <= n; i++) { // 1부터 n까지의 수에 대해
        if (!isused[i]) { // 아직 i가 사용되지 않았으면
            arr[k] = i; // k번째 수를 i로 정함
            isused[i] = 1; // i를 사용되었다고 표시
            func(k + 1); // 다음 수를 정하러 한 단계 더 들어감
            isused[i] = 0; 
            // k번째 수를 i로 정한 모든 경우에 대해 다 확인했으니 i를 이제 사용되지 않았다고 명시함.
        } 
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    func(0);
}