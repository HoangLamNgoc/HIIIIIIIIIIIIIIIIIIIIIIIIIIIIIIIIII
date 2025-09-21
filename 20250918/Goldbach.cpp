#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 
const int maxN = 1e6 + 5; 
bool d[maxN]; 
int n; 
vector<int> prime; 

void sieve() {
    for (int i = 2; i * i <= maxN; ++i) {
        if(!d[i]) {
 			    for(int j = i * i; j <= maxN; j += i) {
				      d[j] = true; 
			    }
		    }
	  }
	for (int i = 3; i <= maxN; ++i) {
		if (!d[i]) prime.push_back(i); 
	}
}

int main() {
	freopen("GOLDBACH.INP", "r", stdin); 
	freopen("GOLDBACH.OUT", "w", stdout);
	
	sieve(); 
	while (cin >> n) {
	  long long ans = 1;
		int i = 0; 
		int j = upper_bound(prime.begin(), prime.end(), 2 * n ) - prime.begin() - 1; 
		while ( i <= j ) { 
			if( prime[i] + prime[j] > 2 * n) j--;
			else {
				ans += j - i + 1; 
				++i; 
			}
		}
		cout << ans << endl; 
	}	
	return 0; 
}
    
