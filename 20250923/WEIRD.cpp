#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std; 

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 
    
    freopen("WEIRD.INP", "r", stdin);
    freopen("WEIRD.OUT", "w", stdout); 
    
    int n; 
    cin >> n; 

    long long start2 = pow(10, n - 1);
    long long end2 = pow(10, n); 

    vector<long long> v; 
    for (long long i = start2 ; i < end2; ++i) {
        long long y = i * i; 
        long long j = y % end2;
        y /= end2; 
        if ( y + j == i ) v.push_back(i);
    }

    if (!v.empty()) for (long long& i : v ) cout << i << " ";
    else cout << 0 << endl;
    return 0; 
}
