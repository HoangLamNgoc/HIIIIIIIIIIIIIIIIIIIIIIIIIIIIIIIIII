#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
const int maxN = 1e6;

long long hang(long long k) {
    long long dem = 1;
    long long n = ((int)sqrt(8 * k + 1) - 1) / 2;
    if(n * (n + 1) / 2 >= k ) return n;
    else return n + 1;
}

bool bien_phai(long long k) {
    if (k <= 0 ) return false;
    if (k == 1 ) return true;
    if (hang(k - 1) < hang(k)) return true;
    return false;
}
bool bien_trai(long long k) {
    if(k <= 0) return false;
    if(k == 1) return true;
    if(hang(k + 1) > hang(k)) return true;
    return false;
}

int main() {
    freopen("BOARDGAME.INP", "r", stdin);
    freopen("BOARDGAME.OUT", "w", stdout);

    long long pos;
    cin >> pos;

    long long tong = pos;
    string s;
    cin >> s;

    vector<string> v = {"ET", "WT", "NW", "NE", "SW", "SE"};
    long long i = 0, j = 1;

    while(j < s.length()) {
        string ans = "";
        ans.push_back(s[i]);
        ans.push_back(s[j]);
        i += 2;
        j += 2;

        long long cnt = hang(pos);
        long long d[6] = {1, -1, -cnt, -(cnt - 1), cnt, cnt + 1};

        if(bien_phai(pos)) if(ans == "WT" || ans == "NW" ) continue;
        if(bien_trai(pos)) if(ans == "ET" || ans == "NE" ) continue;

        bool anything = true;
        for(int i = 0; i < 6; ++i) {
            if(ans == v[i]) {
                pos += d[i];
                if(pos <= 0) {
                    pos -= d[i];
                    anything = false;
                    break;
                }
                if(anything) tong += pos;
                break;
            }
        }
        if(!anything) continue;
    }
    cout << tong << endl;
    return 0;
}
