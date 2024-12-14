#include<bits/stdc++.h>
using namespace std;
bool isp(int x){
        for(int i=2;i*i<=x;i++) {
                if(x%i==0) return 0;
        }
        return 1;
}
int n;
signed main(){
        cin>>n;
        for(int i=n;i<=1000000000;i++) if(isp(i)) return cout<<i<<'\n',0;
        return 0;
}
