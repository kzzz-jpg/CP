#include<bits/stdc++.h>
#define int long long
using namespace std;
int s,n;
signed main(){
        cin>>s>>n;
        for(int i=0;i<=s;i++){
                if(i*6480+(s-i)*980==n){
                        cout<<i<<' '<<(s-i)<<'\n';
                        return 0;
                }
        }
        cout<<-1<<' '<<-1<<'\n';
}
