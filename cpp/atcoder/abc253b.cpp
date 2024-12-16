#include<bits/stdc++.h>
using namespace std;
int x,y,a,b,n,m;
char c;
signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>c;
            if(c=='o'){
                if(x) a=i,b=j;
                else x=i,y=j;
            }
        }
    }
    cout<<(abs(x-a)+abs(y-b))<<'\n';
}