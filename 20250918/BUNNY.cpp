#include <iostream>
#include <algorithm>

using namespace std; 

int main() {
    freopen("BUNNY.INP", "r", stdin);
    freopen("BUNNY.OUT", "w", stdout); 
  
    long long n; 
    cin >> n; 

    long long k = n % 6; 
    n /= 6; 

    if ( k == 0 ) cout << 1 + k * ( k + 1 ) * 3 + n * k; 
    else cout << k + k * ( k + 1 ) * 3 + n * k; 

    return 0; 
}
