#include <iostream>
#include <numeric>

using namespace std; 

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 
  
    freopen("FRACTION.INP", "r", stdin); 
    freopen("FRACTION.OUT", "w", stdout); 

    int T; 
    cin >> T; 

    while (T--) {
        int n; 
        cin >> n; 
      
        long long a = 1, b = 1; 
        for (int i = 1; i <= n; ++i ) {
            long long j; cin >> j;  
            a = a * j; 
        }

        for (int i = 1; i <= n; ++i ) {
            long long j; cin >> j;  
            b = b * j; 
        }

        long long k = __gcd(a, b); 
        a /= k; b/= k; 

        while ( b % 2 == 0 ) b /= 2; 
        while (b % 5 == 0 ) b /= 5;
      
        if ( b > 1 ) cout << "repeating" << endl;
        else cout << "finite" << endl;
    }
return 0; 
}
