//Cach 1
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("LOCK.INP", "r", stdin);
    freopen("LOCK.OUT", "w", stdout);

    int n; string s;
    cin >> n >> s;
    string ans(1000, '9');

    for(int i = 0; i < n; ++i) {
        int cnt = (10 - (s[i] - '0')) % 10;
        string cur = "0";

        for(int j = i + 1; j < n; ++j) {
            int si = (s[j] - '0' + cnt) % 10;
            cur.push_back(char(si + '0'));
        }

        for(int j = 0; j < i; ++j) {
            int si = (s[j] - '0' + cnt) % 10;
            cur.push_back(char(si + '0'));
        }

        if(cur < ans)
            ans = cur;
        }

    cout << ans << "\n";
    return 0;
}

//Cach 2
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; string s;
    cin >> n >> s;
    string ans(n, '9');

    for (int k = 0; k < 10; ++k) {
        string t = s;
        for (int i = 0; i < n; ++i) {
            int si = (t[i] - '0' + k) % 10;
            t[i] = char(si + '0');
        }

        for(int i = 0; i < n; ++i) {
            string cur = "";
            for (int j = i ; j < n; ++j) cur.push_back(t[j]);
            for (int j = 0; j < i; ++j) cur.push_back(t[j]);
            if ( cur < ans ) ans = cur;
        }
    }

    cout << ans << endl;
    return 0;
    }
