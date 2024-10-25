#include<bits/stdc++.h>
using  namespace std;
#define maxlong 1<<61
bool comp(pair<int,int> a,pair<int,int> b){
    return a.first<b.first;
}
int main(){
    int n,w;
    scanf("%d%d",&n,&w);
    vector<pair<int,int>> val(n+1);
    for(int i=1;i<=n;i++){
        scanf("%d",&val[i].first);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&val[i].second);
    }
    sort(val.begin(),val.end(),comp);
    vector<vector<int>> dp(n+1,vector<int>(w+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            if(val[i].first>j){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-val[i].first]+val[i].second);
            }
        }
    }
    cout<<dp[n][w]<<endl;
}