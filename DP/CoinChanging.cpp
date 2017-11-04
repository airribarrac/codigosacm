/*
DP sobre la cantidad de formas de pagar X dado un set de monedas(cantidad infinita)
Complejidad X*|Monedas|
*/

#include <bits/stdc++.h>

using namespace std;

int solution(int total, vector<int>&monedas){
	vector <int> temp(total+1,0);
	temp[0] = 1;
	for(int i = 0; i < monedas.size();i++){
		for(int j = 1; j <= total; j++)
			if(j >= monedas[i])temp[j]+= temp[j-monedas[i]];
	}
	return temp[total];
}

int main(){
	int total = 15;
    vector <int> monedas;
    monedas.push_back(3);
    monedas.push_back(4);
	monedas.push_back(6);
	monedas.push_back(7);
	monedas.push_back(9);
    printf("%d\n",solution(total,monedas));
	return 0;
}