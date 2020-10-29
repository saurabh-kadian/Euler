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
float area(int x1, int y1, int x2, int y2, int x3, int y3){
   return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}
bool isInside(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y){
   float A = area (x1, y1, x2, y2, x3, y3);
   float A1 = area (x, y, x2, y2, x3, y3);
   float A2 = area (x1, y1, x, y, x3, y3);
   float A3 = area (x1, y1, x2, y2, x, y);
   return (A == A1 + A2 + A3);
}
int main(){
	freopen("input 102.txt","r",stdin);
    int c = 0;
    for(int i=0;i<1000;++i){
        long long int x,y,a,b,o,p;
        scanf("%lld,%lld,%lld,%lld,%lld,%lld",&x,&y,&a,&b,&o,&p);
        if(isInside(x,y,a,b,o,p,0,0))
            c++;
    }
    cout << "ProjectEuler 102 : " << c << endl;
	return 0;
}
