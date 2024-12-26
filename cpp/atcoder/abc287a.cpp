#include<bits/stdc++.h>
using namespace std;
signed main(){
        string s;
        int n,a=0,b=0;
        cin>>n;
        while(n--){
                cin>>s;
                if(s=="For") a++;
                else b++;
        }
        cout<<(a>b?"Yes\n":"No\n");
}
