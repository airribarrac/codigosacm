/*
DP para obtener la secuencia bitonic mas larga
BitonicSubsequence = secuencia que en primera instacia crece, y luego decrece.
Complejidas O(n^2)
Espaciio lineal
*/

#include <bits/stdc++.h>

using namespace std;

int bitonicSequence(vector <int> &bitonic){
	int lis[bitonic.size()],lds[bitonic.size()];
	for(int i = 0; i < bitonic.size();i++){
		lis[i] = 1;
		lds[i] = 1;
	}
	for(int i = 1; i < bitonic.size();i++){
		for(int j = 0; j < i; j++){
			if(bitonic[i] > bitonic[j])lis[i] = max(lis[i],lis[j]+1);
		}
	}
	for(int i = bitonic.size()-2; i >= 0 ;i--){
		for(int j = bitonic.size()-1; j > i; j--){
			if(bitonic[i] > bitonic[j])lds[i] = max(lds[i],lds[j]+1);
		}
	}
	int max = 0;
	for(int i = 0; i < bitonic.size();i++){
		if(max < lis[i] + lds[i]-1)max = lis[i] + lds[i]-1;
	}
	return max;
}

int main(){
	vector <int> bitonic;
	int n,aux;
	scanf("%d %d",&n);
	for(int i = 0; i < n; i++){
	scanf("%d",&aux);
	bitonic.push_back(aux);
	}
	printf("%d\n",bitonicSequence(bitonic));
	return 0;
}

/*
16
0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 5
*/