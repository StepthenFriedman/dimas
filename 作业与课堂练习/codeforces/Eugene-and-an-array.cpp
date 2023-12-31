#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        prefix[i + 1] = prefix[i] + x;
    }
    int begin = 0, end = 0;
    long long ans = 0;
    set<long long> s = {0};
    for(begin=0;begin<n;begin++) {
        while(end < n && !s.count(prefix[end+1])) s.insert(prefix[++end]);
        ans += end - begin;
        s.erase(prefix[begin]);
    }
    cout << ans << endl;
}