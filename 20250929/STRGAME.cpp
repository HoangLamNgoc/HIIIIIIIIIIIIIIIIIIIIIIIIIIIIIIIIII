#include <map>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main() {
    int n; 
    cin >> n; 

    string s; 
    cin >> s; 

    vector<int> v; 
    for (int i = 0; i < n; ++i) {
        if (find(v.begin(), v.end(), s[i] - 'a') == v.end()) 
            v.push_back(s[i] - 'a'); 
    }

    if (v.size() % 2 == 0) cout << "First" << endl;
    else cout << "Second" << endl;
}


/* 
c1, c2 -> số điểm 
gọi p1, p2,..., pk -> p1 < p2 < ... < pk ( do chiến lược đi tối ưu) 
k : số chữ cái phân biệt của chuỗi - 1
-> điểm ng1 : p1 + p3 + .... = X; 
-> điểm ng2 : p2 + p4 +...... = Y; 
=>>> NẾU CÓ Pk => WIN 
Pk > Pk - 1 
....
P3 > P2 
P1 
=>>>>> win 
*/
