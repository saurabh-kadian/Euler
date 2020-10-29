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
bool isPrime(long long int n){
    if(n == 2 || n == 3)
        return true;
    if(n%2 == 0 || n%3 == 0)
        return false;
    for(long long int i=5;i*i<=n;i+=6)
        if(n%i == 0 || n%(i+2) == 0)
            return false;
    return true;
}
int main(){
	//freopen("input.txt","r",stdin);
	vector<long long int> prime,primeSq,primeTri,primeQuad;
	prime.push_back(2);
	primeSq.push_back(4);
	primeTri.push_back(8);
	primeQuad.push_back(16);
	for(long long int i=3;i<1000000;i+=2){
        if(isPrime(i)){
            prime.push_back(i);
            if(i*i <= 50000000)
                primeSq.push_back(i*i);
            else
                break;
            if((i*(i*i)) <= 50000000)
                primeTri.push_back(i*(i*i));
            if((i*(i*(i*i))) <= 50000000)
                primeQuad.push_back((i*((i*i)*i)));
        }
	}
	set<long long int> counter;
	for(long long int i=0;i<primeSq.size();++i){
        for(long long int j=0;j<primeTri.size();++j){
            for(long long int k=0;k<primeQuad.size();++k){
                if(primeSq[i]+primeTri[j]+primeQuad[k] < 50000000)
                    counter.insert(primeQuad[k]+primeSq[i]+primeTri[j]);
            }
        }
	}
	cout << "PE 87 : " << counter.size()  <<endl;
	return 0;
}
