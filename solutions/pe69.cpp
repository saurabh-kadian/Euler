#include <iostream>
#include <cmath>
using namespace std;
bool is_prime(long long int k)
{
    if(k==2)
        return true;
    if(k%2==0)
        return false;
    long long int sq = sqrt(k);
    for(long long int i=3;i<=sq;++i)
        if(k%i==0)
            return false;
    return true;
}
int main()
{
    double primes[] =  {2,3,5,7,11,13,17,19,23,29,31,37,39,41,43,47,51,53,57,59};
    double num = 1;
    double deno = 1;
    double maxi = 0;
    double maxiN = 0;
    for(int i=0;i<20;++i){
        num *= primes[i]-1;
        deno *= primes[i];
            if( deno/num > maxi){
                maxi = deno/num;
                cout << (long long int)deno << " " << maxi << endl;
            }
            if(deno > 1000000)
                break;
    }
    cout << maxi << endl;
    return 0;
}
