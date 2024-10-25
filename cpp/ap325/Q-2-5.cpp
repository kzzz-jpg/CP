#include<bits/stdc++.h>
using namespace std;
#define int long long
int P=1000000007;
vector<vector<int>> mult(vector<vector<int>> x,vector<vector<int>> y){
    vector<vector<int>> ans(2,vector<int>(2,0)); 
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                ans[i][j]=(ans[i][j]+x[i][k]*y[k][j])%P;
            }
        }
    }
    return ans;
}
vector<vector<int>> fp(int pw){
    vector<vector<int>> ans={{1,0},{0,1}},proc={{1,1},{1,0}};
    for(;pw;pw>>=1,proc=mult(proc,proc)){
        if(pw&1){
            ans=mult(ans,proc);
        }
    }
    return ans;
}
signed main(){
    int n;
    while(cin>>n){
        if(n==-1) return 0;
        n--;
        vector<vector<int>> ans=fp(n);
        cout<<ans[0][0]<<endl;
    }
}