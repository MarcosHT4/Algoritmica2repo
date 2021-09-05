#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef map<int, int> mii;

ll _sieve_size;
bitset<10000010> bs;                             // 10^7 is the rough limit
vll p;                                           // compact list of primes

void sieve(ll upperbound) {                      // range = [0..upperbound]
    _sieve_size = upperbound+1;                    // to include upperbound
    bs.set();                                      // all 1s
    bs[0] = bs[1] = 0;                             // except index 0+1
    for (ll i = 2; i < _sieve_size; ++i) if (bs[i]) {
        // cross out multiples of i starting from i*i
        for (ll j = i*i; j < _sieve_size; j += i) bs[j] = 0;
        p.push_back(i);                              // add prime i to the list
    }
}

bool isPrime(ll N) {                             // good enough prime test
    if (N < _sieve_size) return bs[N];             // O(1) for small primes
    for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i)
        if (N%p[i] == 0)
            return false;
        return true;                                   // slow if N = large prime
} // note: only guaranteed to work for N <= (last prime in vll p)^2

// second part

int numDiv(ll N) {
    int ans = 1;                                   // Empezamos con 1, ya que cuando se multiplica por 0, siempre da 0
    for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i) {
        int power = 0;                               // Nos indica a cuantos exponenetes se va a elevar un factor ej (2^4, power = 4)
        while (N%p[i] == 0) { N /= p[i]; ++power; }  //Acumulamos cantas potencias tiene el factor primo en cuestion
        ans *= power+1;                              // Al final vamos multiplicando, ya que recordemos (ep1 + 1)*(ep2+2)... El for se ocupa de multiplicar todos los factores
    }
    return (N != 1) ? 2*ans : ans;                 // El ultimo factor podria ser primo, por lo tanto si es asi, se multiplica por 2
}



int main() {
    // first part: the Sieve of Eratosthenes
    sieve(10000000);                               // up to 10^7 (<1s)
    printf("%lld\n", p.back());               // primes.back() = 9999991


    return 0;
}

