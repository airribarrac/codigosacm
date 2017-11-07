struct SparseTable{
    //se puede cambiar gcd por funcion f que cumpla
    // f(a,b,c)=f(a,f(b,c))=f(f(a,b),c)
    int table[10000][17],n;
    int ZERO;   // f(ZERO,x)=f(x,ZERO)=x
    vector<int> A;
    SparseTable(vector<int> &_A){
        A=_A;
        ZERO=0;
        n=A.size();
        for(int i=0;i<n;i++){
            table[i][0]=A[i];
        }
        for(int j=1;j<=17;j++){
            for(int i=0;i<=n-(1<<j);i++){
                table[i][j]=__gcd(table[i][j-1],table[i+(1<<(j-1))][j-1]);
            }
        }
    }
    int query(int L,int R){
        int answer=ZERO;
        for(int j=17;j>=0;j--){
            if(L+(1<<j)-1<=R){
                answer=__gcd(answer,table[L][j]);
                L+=1<<j;
            }
        }
        return answer;
    }
};
