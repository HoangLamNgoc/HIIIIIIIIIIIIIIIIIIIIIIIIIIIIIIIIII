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
    while (cin >> n) { 
        int res = n - 1; 
        long long start2 = 1;
        while (res--){
            start *= 10; 
        }
        long long end2 = start2 * 10;
        for (long long i = start2 ; i < end2; ++i) {
            long long y = i * i; 
            long long j = y % end2;
            y /= end2; 
            if ( y + j == i ) cout << i << " ";
        }
    }
    return 0; 
}
