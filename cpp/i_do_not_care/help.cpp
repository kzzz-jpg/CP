#include <bits/stdc++.h>
using namespace std;

int chartoi(char c){
    int i = c - '0';
    return i;
}
char itochar(int i){
    char c = i + '0';
    return c;
}
void zero(char c[]){
    for(int i=0;i<21;i++){
        c[i] = '0';
    }
}

int main(int argc, char* argv[]) {
    
    // string str1;
    // str1 = argv[1];
    // ifstream cin("input1.txt"); 
    
    string c,d;
    while(cin >> c >> d){
        if(c=="0"&&d=="0") break;

        char a[22],b[22]; zero(a); zero(b);

        stringstream ss;
        int a1=c.size(); ss << c;
        while(ss>>a[21-a1]) a1--;
		ss.str("");
        ss.clear(); 
        int b1=d.size(); ss << d; 
        while(ss>>b[21-b1]) b1--;
		ss.str("");
        ss.clear();

        int carry = 0; int sum = 0; 
        char result[22]; zero(result);
        for(int i=20;i>=0;i--){
            sum += chartoi(a[i])+chartoi(b[i])+carry;
            if(sum>=10){
                carry = 1;
                sum -= 10;
                result[i] = itochar(sum);
            }
            else{
                carry = 0;
                result[i] = itochar(sum);
            }
            sum = 0;
        }
        if(result[0]!='0'){
            cout << "Overflow!" << endl;
        }
        else{
            int len;
            for(int i=0;i<21;i++){
                if(result[i]!='0'){
                    len = i; break;
                }
            }
            cout << "A + B = ";
            for(int i=len;i<21;i++){
                cout << result[i];
            }
            cout << endl;
        }
    }
    return 0;
}