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
#include <iomanip>
#include <limits.h>
#define debug(v) for(long long int i=0;i<v.size();++i)cout<<v[i]<<" ";cout<<endl;
using namespace std;
vector<long long int> primes;
void prime(){
    long long int n = 100;
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
    long long int sopf[100] = {0};
    long long int kappa[100] = {0};
    sopf[0] = sopf[1] = 0;
    sopf[2] = sopf[4] = 2;
    sopf[3] = 3;
    kappa[0] = 1;
    kappa[1] = 0;
    kappa[2] = kappa[3] = kappa[4] = 1;
    for(long long int i = 4;i < 100;++i){
        long long int temp = i;
        set<long long int> factors;
        for(long long int q=0;temp != 1;++q){
            if(temp%primes[q] == 0){
                factors.insert(primes[q]);
                temp /= primes[q];
                q = -1;
            }
        }
        long long int totaler = 0;
        for(set<long long int>::iterator it = factors.begin();it != factors.end();++it)
            totaler += *it;
        sopf[i] = totaler;
        long long int x = sopf[i];
        for(long long int j=1;j<i;++j)
            x += sopf[j]*kappa[i-j];
        kappa[i] = x/i;
    }
    long long int i=0;
    for(i=0;i<100;++i)
        if(kappa[i] >= 5000)
            break;
    cout << "ProjectEuler 77 : " << i << endl;
   	return 0;
}
