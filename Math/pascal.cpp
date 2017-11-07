for(int i=1;i<150;i++){
		for(int j=1;j<i+3;j++){
			pascal[i][j]=pascal[i-1][j-1]+pascal[i-1][j];
		}
	}
	cin>>n;
	for(ll i=0;i<n+1;i++){
			printf("%lld ",pascal[n-1][i]);
	}
