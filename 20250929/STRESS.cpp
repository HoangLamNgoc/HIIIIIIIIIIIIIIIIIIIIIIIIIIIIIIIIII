#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 

    freopen("STRESS.INP", "r", stdin);
    freopen("STRESS.OUT", "w", stdout); 
    
    long long n; 
    cin >> n; 

    vector<long long> v;
    if ((n & 1) == 1) {
        n = n & ~(1 << 0);
        v.push_back(n); 
    } 

    bool found = false; 
    long long m = n;  
    while (!found) {
        long long pos = __builtin_popcount(n);
        if (pos == 1) found = true; 
        pos = __builtin_ctz(n); 
        v.push_back(m - pos - 1); 
        long long b = n >> pos; 
        n = b; 
        m -= (pos + 1); 
    }
    cout << v.size() << endl; 
    for (long long& i : v) cout << i << ' '; 
}
