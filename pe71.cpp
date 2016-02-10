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
    double compare = 3.0/7.0;
    double num=0,deno=0,mini = 999;
    for(double d = 1000000;d >= 1;--d){
        double n = compare*d;
        double nm1 = (n-1)/d;
        double ans = compare - nm1;
        if(ans < mini)
            mini = ans,deno=d,num=n-1;
        //if(!(fmod(d,100000)))
        //    cout << d << " : " << num << " " << deno << endl;
    }
    cout << "ProjectEuler 71 : " << num << endl;
	return 0;
}
