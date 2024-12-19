#include<bits/stdc++.h>
using namespace std;
int n;
signed main(){
        cin>>n;
        if(n==0) return cout<<"Happy Birthday!\n",0;
        int t;
        while(n--){
                cin>>t;
                if(t%11==0) cout<<"How perfect this plate is!\n";
                else cout<<"Broken\n";
        }
}
