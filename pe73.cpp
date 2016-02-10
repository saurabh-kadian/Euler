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
long long int gcd ( long long int a, long long int b )
{
  long long int c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}
int main(){
	//freopen("input.txt","r",stdin);
	double low = 1.0/3.0,upp = 1.0/2.0;long long int c=0;
	for(long long int d = 12000;d>=1;--d){
        for(long long int n = 12000;n>=1;--n){
            double x = (double)n/(double)d;
            if(x > low && x < upp && gcd(n,d) == 1)
                c++;
        }
	}
	cout << "ProjectEuler 73 : " << c << endl;
	return 0;
}
