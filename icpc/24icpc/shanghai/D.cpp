#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int INF = 5e18;
const int MOD = 998244353;

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    if (s[n - 1] == '0' && s[n - 2] == '0')
    {
        cout << "Yes" << '\n';
        return;
    }
    if(n==3){
        cout << "No" << '\n';
        return;
    }
    int pos = 0;
    for (int i = 0; i < n - 4;i++){
        while(pos<n-4&&(s[pos]!='0'||pos<=i))
            pos++;
        if(s[i]=='1'){
            if(s[i+1]=='1'){
                swap(s[i + 1], s[pos]);
                // cout << i << ' ' << pos << endl;
                // cout << s << endl;
            }
        }
    }
    //cout << s << endl;
    string f = s.substr(n - 4, 4);
    vector<string> res = {
        "1011", "1111", "1010", "1110", "1101"
    };
    vector<string> x = {
        "10111", "10110","11001","10101"
    };
    for (auto s1:res){
        if(f==s1){
            cout << "Yes" << '\n';
            return;
        }
    }
    if(n==4){
        cout << "No" << '\n';
        return;
    }
    f = s.substr(n - 5, 5);
    for(auto s1:x){
        if (f == s1)
        {
            cout << "Yes" << '\n';
            return;
        }
    }
    cout << "No" << '\n';
}

signed main()
{
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}