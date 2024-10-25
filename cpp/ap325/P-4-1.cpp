#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MI 1<<30
signed main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        int ans=0;
        while(t>=50){
            ans++;
            t-=50;
        }
        while(t>=10){
            ans++;
            t-=10;
        }
        while(t>=5){
            ans++;
            t-=5;
        }
        while(t){
            ans++;
            t--;
        }
        cout<<ans<<endl;
    }
    return 0;
}