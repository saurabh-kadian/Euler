#include <iostream>
#include <iomanip>
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
	unsigned long long int peter = 0,colin = 0;
	unsigned long long int peterSet[37] = {0},colinSet[37] = {0};
	for(int a=1;a<=6;++a)
        for(int b=1;b<=6;++b)
            for(int c=1;c<=6;++c)
                for(int d=1;d<=6;++d)
                    for(int e=1;e<=6;++e)
                        for(int f=1;f<=6;++f)
                            colin++,colinSet[a+b+c+d+e+f]++;
	for(int a=1;a<=4;++a)
        for(int b=1;b<=4;++b)
            for(int c=1;c<=4;++c)
                for(int d=1;d<=4;++d)
                    for(int e=1;e<=4;++e)
                        for(int f=1;f<=4;++f)
                            for(int g=1;g<=4;++g)
                                for(int h=1;h<=4;++h)
                                    for(int i=1;i<=4;++i)
                                        peter++,peterSet[a+b+c+d+e+f+g+h+i]++;
    unsigned long long int total = peter*colin;
    unsigned long long int peteW = 0;
    for(int i=0;i<37;++i){
        for(int j=0;j<37;++j){
            if(j >= i)
                break;
            if(i > j)
                peteW += peterSet[i]*colinSet[j];
        }
    }
    cout << "Project Euler 205 : " << setprecision(10) << (double)((double)peteW/(double)total) << endl;
	return 0;
}
