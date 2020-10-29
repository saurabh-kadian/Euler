#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <cstdlib>
#include <string>
#include <cmath>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <iterator>
using namespace std;
long long int gcd ( long long int a, long long int b )
{
  long long int c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}
vector<long long int> primes;
void prime(){
    long long int n = 1000000;
    bool all[n+2];
    for(long int i = 0 ; i < n+2 ; ++i)
        all[i] = true;
    for(long long int i = 2; i*i < n+2 ; ++i){
        if(all[i] == true){
            for(long long int j = i*i ; j < n+2 ; j += i)
                all[j] = false;
        }
    }
    for(long long int i = 2; i < n+2 ; ++i)
        if(all[i] == true)
            primes.push_back(i);
}
int main(){
	//freopen("input.txt","r",stdin);
	prime();
	long long int counter = 1000000 - 1;
    for(long long int i=2;i<=1000000;++i){
        if(binary_search(primes.begin(),primes.end(),i))
            counter += i-2;
        else{
            long long int temp = i;
            set<long long int> factors;
            for(long long int q=0;temp != 1;++q){
                if(temp%primes[q] == 0){
                    factors.insert(primes[q]);
                    temp /= primes[q];
                    q = -1;
                }
            }
            long long int totaler = i;
            for(set<long long int>::iterator it = factors.begin();it != factors.end();++it)
                totaler /= *it,totaler *= (*it-1);
            counter += totaler - 1;
        }
    }
    cout << "ProjectEuler 72 : "  << counter << endl;
    return 0;
}
