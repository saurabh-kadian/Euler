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
vector<unsigned long long int> primes;
void prime(){
    unsigned long long int n = 50000000;
    vector<bool>all(n+2);
    for(long int i = 0 ; i < n+2 ; ++i)
        all[i] = true;
    for(unsigned long long int i = 2; i*i < n+2 ; ++i){
        if(all[i] == true){
            for(unsigned long long int j = i*i ; j < n+2 ; j += i)
                all[j] = false;
        }
    }
    for(unsigned long long int i = 2; i < n+2 ; ++i)
        if(all[i] == true)
            primes.push_back(i);
}
int main(){
    prime();
    unsigned long long int counter = 0;
    for(unsigned long long int i=0;i<primes.size();++i){
        for(unsigned long long int j=i;j<primes.size();++j){
            if((primes[i]*primes[j]) < 100000000)
                counter++;
            else
                break;
        }
    }
    cout << "ProjectEuler 187 : " << counter << endl;
	return 0;
}
