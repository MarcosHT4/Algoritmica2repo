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

vll primeFactors(ll N) {                         // pre-condition, N >= 1
    vll factors;       //Creamos un arreglo de factores
    for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i) //Recorremos hasta la mitad de N
        while (N%p[i] == 0) {                        // Si entra a este while, significa que p[i] el cual es un factor primo, es divisible entre N, se lo hace todas las veces que se pueda dividir N entre p[i]
            N /= p[i];                                 // Dividimos N entre el factor primo, para ir reduciendo el número
            factors.push_back(p[i]);                   //Ponemos el factor en el arreglo de factores primos
        }
    if (N != 1) factors.push_back(N);   // Recordemos que si N no es igual a 1, significa que N en sí es un primo
    return factors;
}

int main() {
    // first part: the Sieve of Eratosthenes
    sieve(10000000);                               // up to 10^7 (<1s)
    printf("%lld\n", p.back());               // primes.back() = 9999991
    for (int i = p.back()+1; ; ++i)
        if (isPrime(i)) {
            printf("The next prime beyond the last prime generated is %d\n", i);
            break;
        }
    printf("%d\n", isPrime((1LL<<31)-1));          // 8th Mersenne prime
    printf("%d\n", isPrime(136117223861LL));       // 104729*1299709
    printf("\n");

    // second part: prime factors
    vll r = primeFactors((1LL<<31)-1);              // slowest, Mersenne prime
    for (auto &pf : r)
        printf("> %d\n", pf);
    r = primeFactors(136117223861LL);              // slow, large prime
    for (auto &pf : r)
        printf("> %d\n", pf);                        // 104729*1299709
    r = primeFactors(142391208960LL);              // faster, large composite
    for (auto &pf : r)
       printf("> %d\n", pf);                        // 2^10*3^4*5*7^4*11*13
            // r = primeFactors(99999820000081LL);            // the limit: 9999991^2
            // for (auto &pf : r)
            //   printf("> %d\n", pf);
            // printf("\n");

    r = primeFactors(9999973LL*9999973LL);         // 9999973^2, the limit
    for (auto &pf : r)
        printf("> %d\n", pf);
         printf("\n");
            // r = primeFactors(9999991LL*9999991LL);         // 9999991^2, first crash
            // for (auto &pf : r)
            //   printf("> %d\n", pf);
            // printf("\n");

            // third part: functions involving prime factors

   return 0;
}
