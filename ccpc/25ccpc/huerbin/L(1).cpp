#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 5e18;
const int MOD = 998244353;

void solve()
{
    int n,m;
    cin>>n>>m;
    int k;
    cin>>k;
    vector<pair<int,int>>za(k+1);
    vector<int>vis(m+2);
    vector<int>mp(m+2);
    for(int i=0;i<k;i++){
        int r,c;
        cin>>r>>c;
        za[i]={r,c};
        vis[c]=r;
        mp[c]=i;
    }
    vector<int>ans((1ll<<k)+2,-1);
    for(int x=0;x<(1ll<<(k));x++){
        vector<int>vv(k+2);
        for(int i=0;i<k;i++){
            int cur=(x>>i)&1;
            vv[i]=cur;
        }
        for(int i=1;i<=n;i++){
            int na=0;
            int nx=i;
            for(int j=2;j<=m;j++){
                if(vis[j]==0){
                    na++;
                    continue;
                }else if(vv[mp[j]]==1){
                    int cur=vis[j]+1;
                    if(cur>n){
                        na=-1;
                        break;
                    }
                    if(nx>=cur){
                        na++;
                        continue;
                    }
                    if(vv[mp[j-1]]==1||vis[j-1]==0){
                        na+=1+(cur-nx);
                        nx=cur;
                    }else{
                        na=-1;
                        break;
                    }
                }else if(vv[mp[j]]==0){
                    int cur=vis[j]-1;
                    if(cur<1){
                        na=-1;
                        break;
                    }
                    if(nx<=cur){
                        na++;
                        continue;
                    }
                    if(vv[mp[j-1]]==0||vis[j-1]==0){
                        na+=1+(nx-cur);
                        nx=cur;
                    }else{
                        na=-1;
                        break;
                    }
                }
            }
            if(ans[x]==-1){
                ans[x]=na;
            }else if(na!=-1){
                ans[x]=min(ans[x],na);
            }
        }
    }

    for(int i=0;i<(1ll<<(k));i++){
        cout<<ans[i]<<' ';
    }
    cout<<"\n";
}

signed main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
}