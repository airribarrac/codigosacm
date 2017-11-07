class MSTree{
private:
    vector<vector<int> > st;
    int n;
    void merge(int n, int left, int right) {
        int lptr = 0, rptr = 0, cptr = 0;;
        while (lptr < st[left].size() || rptr < st[right].size()) {
            if (lptr == st[left].size()){
                st[n][cptr++] = st[right][rptr++];
            }else if (rptr == st[right].size()){
                st[n][cptr++] = st[left][lptr++];
            }else {
                if (st[left][lptr] < st[right][rptr])
                    st[n][cptr++] = st[left][lptr++];
                else
                    st[n][cptr++] = st[right][rptr++];
            }
        }
    }

    void construct(int n, int ll, int rl,vector<int> &a) {
        if (ll == rl) {
            st[n].push_back(a[ll]);
            return;
        }
        construct(2*n+1, ll, (ll+rl)/2,a);
        construct(2*n+2, (ll+rl)/2+1, rl,a);
        st[n].resize(rl-ll+1);
        merge(n, 2*n+1, 2*n+2);
    }

    int query(int n, int ll, int rl, int ql, int qr, int k) {
        if (rl < ql || ll > qr) return 0;
        if (ll >= ql && rl <= qr) {
            // modify here
            int t = st[n].end() - upper_bound(st[n].begin(), sizet[n].end(), k);
            return t;
        }
        int left = query(2*n+1, ll, (ll+rl)/2, ql, qr, k);
        int right = query(2*n+2, (ll+rl)/2+1, rl, ql, qr, k);
        return left + right;
    }
public:
    MSTree(vector<int> &a){
       
        n=a.size(   );

        st.resize(4*n+10);

        construct(0,0,n-1,a);
    }

    int query(int i,int j,int k){
        return query(0,0,n-1,i,j,k);
    }
};
