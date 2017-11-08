int Total(int x, vector<int>&f){
    int ans=0;
    while (x>0){
        ans=ans+f[x];
        x-=(x&(-x));
    }
    return ans;
}
int Total2(int x, int y, vector<int>&f){
    if (x==0)
        return Total(y, f);
    return Total(y, f)-Total(x-1, f);
} //SFSDFKDSJFL
void Update(int x, int val, vector<int>&f){
    while (x<f.size()){
        f[x]+=val;
        x+=(x&(-x));
    }
}
void init_F(vector<int>&K, vector<int>&f){
    for (int I=0;I<N;I++){
        Update(I+1, K[I], f);
    }
}


void Update_rang(int i, int j, int k, vector<int>&FT1, vector<int>&FT2){
    Update(i, k, FT1);
    Update(j+1, -k, FT1);
    Update(i, -k*(i-1), FT2);
    Update(j+1, k*j, FT2);
}

long long sum(int j, int i, vector<int>&FT1, vector<int>&FT2){
    if (j==0)
        return Total(i, FT1)*i+Total(i, FT2);
    return Total(i, FT1)*i-Total(j-1, FT1)*(j-1)+Total(i, FT2)-Total(j-1, FT2);
}
