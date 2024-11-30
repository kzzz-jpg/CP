#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    cin>>a;
    int i=0;
    int c[4]={0};
    int max=0,temp=1;
    while(a[i]!='\0'){
        if(a[i]==a[i+1]){
            temp++;
        }else{
            if(temp>max)max=temp;
            temp=1;
        }
        i++;
    }
    cout<<max<<endl;
    return 0;
}
