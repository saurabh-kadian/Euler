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
	long long int arr[11] = {0};
	vector<long long int> vals(1000001,0);
	for(long long int hole = 1; hole <= (1000000-4)/4;++hole){
        long long int total = 0;
        long long int previous = hole;
        while(total <= 1000000){
                total += ((previous+1)*4);
                previous += 2;
                if(total > 1000000)
                    break;
                vals[total]++;
        }
	}
	for(long long int i=0;i<1000001;++i)
        if(vals[i] <= 10)
            arr[vals[i]]++;
	long long int counter = 0;
	for(int i=1;i<11;++i)
        counter += arr[i];
    cout << "ProjectEuler 174 : " << counter << endl;
	return 0;
}
