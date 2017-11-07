int dp[2000][2000];

int lcs(const string &s, const string &t){
	int m=s.size(),n=t.size();
	if(m==0 || n==0) return 0;
	for(int i=0;i<=m;i++){
		dp[i][0]=0;
	}
	for(int i=0;i<=n;i++){
		dp[0][i]=0;
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(s[i]==t[j]){
				dp[i+1][j+1]=dp[i][j]+1;
			}else{
				dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
			}
		}
	}
	return dp[m][n];
}