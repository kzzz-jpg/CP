#include<bits/stdc++.h>
using namespace std;
string s[9];
int n,m;
bool flag;
bool chk(string &a,string &b){
        int ret=0;
        for(int i=0;i<m;i++){
                if(a[i]!=b[i]) ret++;
        }
        return ret==1;
}
signed main(){
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>s[i];
        sort(s+1,s+1+n);
        do{
                flag=1;
                for(int i=1;i<n;i++){
                        if(!chk(s[i],s[i+1])){
                                flag=0;
                                break;
                        }
                }
                if(flag){
                         cout<<"Yes\n";
                         return 0;
                }
        }while(next_permutation(s+1,s+1+n));
        cout<<"No\n";
}
