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
int main(){
	//freopen("input.txt","r",stdin);
	long int counter = 0;
	set<long long int> finally;
    for(long long int i=2;i<=4000;++i){
        for(long long int j=0;j<i;++j){
            long long int number = (i*(i+1)*(2*i+1))/6;
            long long int diff = (j*(j+1)*(2*j+1))/6;
            if(j != 0)
                number -= diff;
            stringstream ss;
            ss << number;
            string str = ss.str();
            string rev = str;
            reverse(rev.begin(),rev.end());
            if(str == rev && number < 100000000 && j+1 != i)
                counter++,finally.insert(number);
        }
    }
    long long int total = 0;
    for(set<long long int>::iterator it = finally.begin();it != finally.end();++it)
        total += *it;
    cout << "Project Euler 125 : " << total << endl;
	return 0;
}
