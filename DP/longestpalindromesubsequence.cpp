#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > dp(6200,vector<int>(6200,-1));
string str;

int solve(int l,int r){
	if(dp[l][r]!=-1)
		return dp[l][r];
	if(l==r)
		return dp[l][r]=1;
	if(l+1==r)
		return dp[l][r]=(str[l]==str[r])?2:1;
	if(str[l]==str[r]){
		return dp[l][r]=2+solve(l+1,r-1);
	}else{
		return dp[l][r]=max(solve(l,r-1),solve(l+1,r));
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>str;
		dp.assign(6200,vector<int>(6200,-1));
		cout<<solve(0,str.size())<<endl;
	}
	return 0;
}