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
	double a = 0.99;
	double bCount = 0,numbers = 0;
	for(long long int i=99;1;++i,numbers=i){
        stringstream ss;
        ss << i;
        string str = ss.str();
        bool bouncy = false;
        bool inc = true,dec = true;
        for(long long int j=0;j<str.length()-1;++j)
            if(!(str[j] <= str[j+1]))
                inc = false;
        for(long long int j=0;j<str.length()-1;++j)
            if(!(str[j] >= str[j+1]))
                dec = false;
        bouncy = !(inc|dec);
        if(bouncy)
            bCount++;
        if(bCount/(double)i >= a)
            break;
	}
	cout << (long long int)bCount << " " << (long long int)numbers << endl;
	return 0;
}
