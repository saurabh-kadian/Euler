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
int main(){
	//freopen("input.txt","r",stdin);
	for(long int cube = 1000000 ; cube < 1000001 ; ++cube){
        long int counter = 0;
        for(long int hole = 1 ; hole <= (cube-4)/4 ; ++hole){
            long int total = 0;
            long int previous = hole;
            while(total < cube){
                total += (previous+1)*4;
                previous += 2;
                if(total <= cube)
                    counter++;
            }
        }
        cout << "Project Euler 173 : " << counter << endl;
	}
	return 0;
}
