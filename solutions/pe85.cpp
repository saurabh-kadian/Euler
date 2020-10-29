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
	long long int m,n,diffMin = 9999999;
	for(long long int i=2;i<3000;++i){
        for(long long int j=2;j<3000;++j){
            long long int l = ((i)*(i+1)*(j)*(j+1))/4;
            if(abs(l-2000000) < diffMin)
                diffMin = abs(l-2000000),m=i,n=j;
            if(l > 2000000)
                break;
        }
	}
	cout << m*n << endl;
	return 0;
}
