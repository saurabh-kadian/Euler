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
#include <float.h>
using namespace std;
vector<double> primes;
void prime(){
    long long int n = 50000;
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
bool isPerm(long long int i,long long int tot){
    stringstream ss,ss1;
    ss << tot;
    ss1 << i;
    string str = ss.str();
    string str1 = ss1.str();
    int c1[10] = {0},c2[10] = {0};
    for(long long int j=0;j<str.length();++j)
        c1[str[j]-48]++;
    for(long long int j=0;j<str1.length();++j)
        c2[str1[j]-48]++;
    bool found = true;
    for(int i=0;i<10;++i)
        if(c1[i] != c2[i])
           found = false;
    return found;
}
int main(){
    prime();
    double minimum = DBL_MAX,index = -1;
    for (long long int i = 0; i < primes.size(); i++) {
        for (int j = i+1; j < primes.size(); j++) {
            long n = primes[i] * primes[j];
            if (n > 10000000)
                break;
            long long int tot = (primes[i] - 1) * (primes[j] - 1);
            double nbytot = ((double)n) / ((double)tot);
            if(isPerm(n, tot) && minimum > nbytot) {
                index = n;
                minimum = nbytot;
            }
        }
    }
    cout << "Project Euler 70 : " << (long long int)index << endl;
    return 0;
}
