#include<bits/stdc++.h>
using namespace std;
int a[4];
string s;
signed main(){
        cin>>s;
        for(int i=0;i<s.size();i++) a[i]=s[i]-'0';
        if(a[0]==a[1]&&a[1]==a[2]&&a[2]==a[3]){
                return cout<<"Weak\n",0;
        }
        bool flag=1;

        for(int i=1;i<4;i++){
                if((a[i-1]+1)%10!=a[i]) flag=0;
        }
        if(flag){
                cout<<"Weak\n";
        }else{
                cout<<"Strong\n";
        }
}
