#include <bits/stdc++.h>
#include <stdio.h>

int main() {
    int i=0,n=10;
    std::set<long long> s = {1};
    s.insert(3);s.insert(3);s.insert(3);
    for (i=0;i<n;i++) printf("%lu",s.count(i));
    
}