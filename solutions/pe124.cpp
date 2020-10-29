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
int main(){
	//freopen("input.txt","r",stdin);
	prime();
	long long int rad[100001] = {0};
	rad[1] = 1;
    for(long long int i=2;i<=100000;++i){
        set<long long int> factors;
        long long int temp = i;
        for(long long int n=0;n<primes.size() && temp != 1;++n)
            if(temp%primes[n] == 0)
                factors.insert(primes[n]),temp/=primes[n],n=-1;
        long long int number = 1;
        for(set<long long int>::iterator it = factors.begin();it != factors.end();++it)
            number *= (*it);
        rad[i] = number;
    }
    vector<pair<long long int,long long int> >arr;
    for(long long int i=1;i<100001;++i)
        arr.push_back(pair<long long int,long long int>(rad[i],i));
    sort(arr.begin(),arr.end());
    cout << "ProjectEuler 124 : " << arr[9999].second << endl;
	return 0;
}
