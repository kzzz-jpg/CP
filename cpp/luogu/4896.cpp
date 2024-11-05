#include<bits/stdc++.h>
using namespace std;
map<string,int> stu,tch;
string come=" came!",leave=" left!",start=" started playing games!",stop=" stopped playing games!";
set<string> ans;
vector<string> stu_nm(5);
int has;
int n;
signed main(){
	cin>>n;
	string s,mes;
	for(int i=0;i<3;i++){
		cin>>s;
		tch[s]=1;
	}
	for(int i=0;i<5;i++){
		cin>>stu_nm[i];
		stu[stu_nm[i]]=1;
	}
	while(n--){
		cin>>s;
		getline(cin,mes);
		if(tch[s]==1&&mes==come){
			has++;
			for(int i=0;i<5;i++){
				if(stu[stu_nm[i]]==2) ans.insert(stu_nm[i]);
			}
			tch[s]=2;
		}else if(tch[s]==2&&mes==leave){
			has--;
			tch[s]=1;
		}else if(stu[s]==1&&mes==start){
			stu[s]=2;
			if(has) ans.insert(s);
		}else if(stu[s]==2&&mes==stop){
			stu[s]=1;
		}else continue;
	}
	if(ans.size()==0){
		cout<<"How Good Oiers Are!\n";
	}else{
		for(auto output_ans:ans) cout<<output_ans<<' ';
		cout<<'\n';
		if(ans.size()==5) cout<<"How Bad Oiers Are!\n";
	}
}

