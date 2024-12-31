#include<bits/stdc++.h>
#define int long long
using namespace std;
int x,k;
int pw(int y){
        int ret=1;
        for(int i=1;i<=y;i++) ret*=10;
        return ret;
}
signed main(){
        cin>>x>>k;
        for(int i=1;i<=k;i++){
                int pos=pw(i);
                if((x%pos)/(pos/10)>=5){
                        x-=x%pos;
                        x+=pos;
                }else{
                        x-=x%pos;
                }
        }
        cout<<x<<'\n';
}
