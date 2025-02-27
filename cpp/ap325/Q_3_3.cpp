#include<bits/stdc++.h>
using namespace std;
int ans,t,x;
char c;
signed main(){
    cin>>t;
    while(cin>>c>>x){
        if(c=='*'){
            t*=x;
        }else if(c=='/'){
            t/=x;
        }else if(c=='-'){
            ans+=t;
            t=-x;
        }else{
            ans+=t;
            t=x;
        }
    }
    cout<<ans+t<<'\n';
}