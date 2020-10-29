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
long long int square(long long int n){
    return n*n;
}
long long int fastExp(long long int base,long long int power){
    if(power == 1)
        return base;
    if(power == 0)
        return 1;
    if(power == 2)
        return square(base);
    if(power % 2 == 0)
        return square(fastExp(base,power/2));
    else
        return base * fastExp(base,power-1);
}
long long int nextAmicable(long long int n){
    vector<pair<long long int,long long int> > primeDiv;
    long long int temp = n;
    if(temp == 1 || temp == 0)
        return 0;
    while(temp != 1){
        long long int i=0;
        for(i = 0;i<primes.size();++i)
            if(temp%primes[i] == 0)
                break;
        temp /= primes[i];
        bool found = false;
        for(long long int J=0;J < primeDiv.size();++J)
            if(primeDiv[J].first == primes[i])
                primeDiv[J].second++,found = true;
        if(!found)
            primeDiv.push_back(pair<long long int,long long int>(primes[i],1));
    }
    long long int total = 1;
    for(long long int i=0;i < primeDiv.size();++i)
        total *= ((fastExp(primeDiv[i].first,primeDiv[i].second+1)-1)/(primeDiv[i].first-1));
    return total - n;
}
int main(){
	//freopen("input.txt","r",stdin);
    prime();
    pair<long long int,long long int> chain(-1,-1);
    for(long long int q = 1000;q < 1000000;q++){
        vector<long long int> all;
        long long int n = q;
        while(1){
            n = nextAmicable(n);
            vector<long long int>::iterator it = find(all.begin(),all.end(),n);
            if(it != all.end())
                break;
            if(n > 1000000)
                break;
            all.push_back(n);
            if(n == q)
                break;
        }
        vector<long long int>::iterator sameNumber = find(all.begin(),all.end(),q);
        if(all.size() > chain.first && sameNumber != all.end())
            chain.first = all.size(),chain.second = *min_element(all.begin(),all.end());
        if(chain.first == 28)
              break;
    }
    cout << "ProjectEuler 95 : " << chain.second << endl;
   	return 0;
}
