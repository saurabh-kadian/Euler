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
vector<long long int> cubes;
void cube(){
    for(long long int i=1;i<=600;++i)
        cubes.push_back(i*i*i);
}
int main(){
	//freopen("input.txt","r",stdin);
	prime();
	cube();
	long long int counter = 0;
    for(long long int i=0;i<cubes.size();++i){
        for(long long int j=0;j<primes.size();++j){
            double x = primes[j]+cubes[i];
            x = cbrt(x);
            if(floor(x) == x)
                counter++;
        }
    }
    cout << "ProjectEuler 131: " << counter << endl;
	return 0;
}
