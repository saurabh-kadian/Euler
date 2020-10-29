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
#include <iomanip>
#include <limits.h>
#define debug(v) for(long long int i=0;i<v.size();++i)cout<<v[i]<<" ";cout<<endl;
using namespace std;
int main(){
	//freopen("input.txt","r",stdin);
    vector<pair<long long int,long long int> > values;
    for(long long int i=0;i <= 50;++i)
        for(long long int j=0;j <= 50;++j)
            if(i != 0 || j != 0)
                values.push_back(pair<long long int,long long int>(i,j));
    //cout << values.size() << endl;
    long long int counter = 0;
    for(long long int i = 0;i < values.size()-1;++i){
        for(long long int  j = i + 1;j < values.size();++j){
            long long int x0 = 0,y0 = 0,x1 = values[i].first,y1 = values[i].second,x2 = values[j].first,y2 = values[j].second;
            long long int a = ((x1-x0)*(x1-x0) + (y1-y0)*(y1-y0));
            long long int b = ((x2-x0)*(x2-x0) + (y2-y0)*(y2-y0));
            long long int c = ((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
            if((a == b+c || b == a+c || c == a+b) && (a != 0 && b != 0 && c != 0))
                counter++;//cout << "(" << x0 << "," << y0 << ")" << " " << "(" << x1
                            //            << "," << y1 << ")" << " " << "(" << x2 << "," << y2 << ")" << endl;
        }
    }
    cout << "ProjectEuler 91 : " << counter << endl;
   	return 0;
}
