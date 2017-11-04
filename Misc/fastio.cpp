
#define GETCHAR getchar_unlocked
#define PUTCHAR putchar_unlocked

inline void readInt(int &n){
	n = 0;
	bool flag=1;
	char c;
	int sign=1;
	while (1){
		c = GETCHAR();
		if(c=='-') sign=-1;
		else if(c>='0'&&c<='9') {n = n * 10 + c - '0';flag=0;}
		else if(flag!=1) break;
	}
	n *= sign;
}	