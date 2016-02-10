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
#include <limits.h>
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
long long int solve(long long int base,long long int power,long long int mod){
    base %= mod;
    long long int answer = base;
    for(long long int i=1;i<power;++i){
        answer *= base;
        answer %= mod;
    }
    return answer;
}
int main(){
	//freopen("input.txt","r",stdin);
    prime();
    for(long long int i=0;i<primes.size();++i){
        long long int n = i+1;
        long long int pn = primes[i];
        long long int x = pn*pn;
        long long int y = pn-1;
        long long int z = pn+1;
        long long int yn = solve(y,n,x);
        long long int zn = solve(z,n,x);
        long long int answer = (yn%x+zn%x)%x;
        if(answer > 10000000000){
            cout << "ProjectEuler 123 : " << n << endl;
            break;
        }
    }
	return 0;
}
