#include<bits/stdc++.h>
using namespace std;
int n;
char c;
signed main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>c;
        if(c=='1'){
            if(i&1) cout<<"Aoki\n";
            else cout<<"Takahashi\n";
            return 0;
        }
    }
}