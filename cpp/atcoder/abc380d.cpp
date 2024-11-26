#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int q;
char rev(char c){
        if(c>='a'&&c<='z') return c-'a'+'A';
        return c-'A'+'a';
}
signed main(){
        cin>>s;
        cin>>q;
        int n;
        while(q--){
                cin>>n;
                n--;
                int pos=n/s.size();
                n=n%s.size();
                int flag=0;
                while(pos){
                        flag^=pos&1;
                        pos>>=1;
                }
                if(flag){
                        cout<<rev(s[n])<<' ';
                }else{
                        cout<<s[n]<<' ';
                }
        }
}
