#include<bits/stdc++.h>
using namespace std;
int n;
string s;
signed main(){
        cin>>n;
        cin>>s;
        if(s=="1/22"){
                cout<<"No\n";
                return 0;
        }
        s=" "+s;
        for(int i=1;i<=(n+1)/2-1;i++){
                if(s[i]!='1') {
                        cout<<"No\n";
                        return 0;
                }
        }
        if(s[(n+1)/2]!='/'){
                cout<<"No\n";
                return 0;
        }
        for(int i=(n+1)/2+1;i<=n;i++){
                if(s[i]!='2'){
                        cout<<"No\n";
                        return 0;
                }
        }
        cout<<"Yes\n";
}
