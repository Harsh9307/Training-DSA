#include<bits/stdc++.h>
using namespace std;


void solve(vector<int> &a, int n, int target, string ans, int sum) {
    if (sum == target) {
        cout << ans << endl;
        return;
    }
    if (n == 0) {
        return;
    }

    // Include current element
    solve(a, n - 1, target, ans + to_string(a[n - 1]) + " ", sum + a[n - 1]);

    // Exclude current element
    solve(a, n - 1, target, ans, sum);
}


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int target = 7;
    string ans = "";
    int sum = 0;
    solve(a, n, target, ans, sum);
    return 0;
}
