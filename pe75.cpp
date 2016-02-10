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
bool coPrime(long long int a,long long int b){
    long long int temp = a;
    a = max(a,b);
    b = min(temp,b);
    long long int r = a%b;
    while(r){
        a = b,b = r,r = a%b;
    }
    if(b == 1)
        return true;
    return false;
}
int main(){
	//freopen("input.txt","r",stdin);
	long long int counter = 0;
	vector<long long int> val(1500001,0);
    for(long long int m = 2;m*m <= 750000;++m){
        for(long long int n = 1;n < m;++n){
            if((m-n)%2 == 1 && coPrime(m,n)){
                long long int total = m*m*2 + 2*m*n;
                for(long long int i=1;total*i < 1500000;++i)
                    val[total*i]++;
            }
        }
    }
    for(long long int i=0;i<1500000;++i)
        if(val[i] == 1)
            counter++;
    cout << "ProjectEuler 75 : " << counter << endl;
	return 0;
}
