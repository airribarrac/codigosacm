vector<bool> isprime;
vector<int> primes;
void sieve(int n) {
	isprime.assign(n + 1,true);
	
	isprime[1] = false; isprime[2] = true;
	for (int i = 2; i <= n; i++) {
		if (isprime[i]) {
			for (int j = i*i;  j < n; j+=i) {
					isprime[j] = false;
			}
		}
	}
	for (int i = 2; i < n; i++) {
		if (isprime[i]) {
			primes.push_back(i);
		}
	}
	return;
}
