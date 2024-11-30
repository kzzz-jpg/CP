#include<bits/stdc++.h>
#define int long long
int n,k,lft,rht,cnt;
int V1[30],V2[30],V3[1<<22];
void p(int in){
    if (in==n){
        lft=0;
        rht=0;
        for (int i=0;i<n;i++){
            if (V2[i]==0){
                lft+=V1[i];
            }
            else if (V2[i]==1){
                rht+=V1[i];
            }
        }
        V3[cnt++]=std::abs(lft-rht);
        return;
    }
    V2[in]=0;
    p(in+1);
    V2[in]=1;
    p(in+1);
}
signed main(){
    std::cin >> n;
    for (int i=0;i<n;i++){
        std::cin >> V1[i];
    }
    p(0);
    int ans=1e15;
    for(int i=0;i<cnt;i++) {
        ans=std::min(ans,V3[i]);
    }
    std::cout<<ans<<'\n';
}
