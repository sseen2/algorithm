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
const int N = 1'000'005;

int n;
int arr[N];         // 정렬 X
vector<int> uni;    // 정렬 O

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; 
        uni.push_back(arr[i]);
    }
    sort(uni.begin(), uni.end());
    uni.erase(unique(uni.begin(), uni.end()), uni.end());

    for (int i = 0; i < n; i++) 
        cout << lower_bound(uni.begin(), uni.end(), arr[i]) - uni.begin() << " ";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}