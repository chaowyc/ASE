#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include "bign.h"
#define MAX 10000000
typedef long long LLI;
using namespace std;

LLI primes[MAX];
bool flag[MAX];

LLI MaxRange(LLI n)
{
    LLI res = (LLI)(n * log(n) * 1.5);
    return res;
}

void eratosthenes_sieve(LLI n)
{
    int totPrimes = 0;
    memset(flag, false, sizeof(flag));
    int sqrtn = sqrt(n + 0.5);
    for (int i = 2; i <= sqrtn; i++) {
        if (!flag[i]) {
            primes[totPrimes++] = i;
            for (int j = i * i; j <= n; j += i) {
                flag[j] = true;
            }
        }
    }
    for (int i = sqrtn + 1; i <= n; i++) {
        if (!flag[i])
            primes[totPrimes++] = i;
    }
}

void euler_sieve(LLI n)
{
    int totPrimes = 0;
    memset(flag, false, sizeof(flag));
    for (int i = 2; i <= n; i++) {
        if (!flag[i])
            primes[totPrimes++] = i;
        for (int j = 0; i * primes[j] <= n; j++) {
            flag[i*primes[j]] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
}

int main()
{
    long long int input;
    scanf("%lld", &input);
    ofstream out;
    out.open("primes.txt", ios::out);
    if(out.is_open())
    {
        euler_sieve(MaxRange(input));
        for(int i = 0; i < input; i++)
            out << i << ":" << primes[i] << endl;
    }
    out.close();
    return 0;
}
