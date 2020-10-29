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
vector<long long int> primes;
bool isPrime(long long int n){
    if(n == 2 || n == 3)
        return true;
    if(n%2 == 0 || n%3 == 0)
        return false;
    for(long long int i=5;i*i<=n;i+=6){
        if(n%i == 0 || n%(i+2) == 0)
            return false;
    }
    return true;
}
bool setter(long long int i,long long int j){
    stringstream ss,ss1;
    ss << primes[i] << primes[j];
    ss1 << primes[j] << primes[i];
    long long int n1,n2;
    ss >> n1;
    ss1 >> n2;
    return isPrime(n1)&isPrime(n2);
}
int main(){
	//freopen("input.txt","r",stdin);
	for(long long int i=3;i<30000;i+=2)
        if(isPrime(i))
            primes.push_back(i);
	for(long long int i=0;i<primes.size();++i){
        for(long long int j=i+1;j<primes.size()-i;++j){
            if(!setter(i,j))
                continue;
            for(long long int k=j+1;k<primes.size()-j;++k){
                if(!setter(i,k))
                    continue;
                if(!setter(k,j))
                    continue;
                for(long long int l=k+1;l<primes.size()-k;++l){
                    if(!setter(i,l))
                        continue;
                    if(!setter(l,j))
                        continue;
                    if(!setter(l,k))
                        continue;
                    for(long long int h=l+1;h<primes.size()-l;++h){
                        if(!setter(i,h))
                            continue;
                        if(!setter(h,j))
                            continue;
                        if(!setter(h,l))
                            continue;
                        if(!setter(h,k))
                            continue;
                        cout << primes[i] << " " << primes[j] << " " << primes[k] << "  " << primes[l] << " " << primes[h] << " "
                             << primes[i]+primes[j]+primes[k]+primes[l]+primes[h] << endl;
                        goto x;
                    }
                }
            }
        }
	}
	x:
	    int a=0;
	return 0;
}
