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
    vector<long long int> all;
    all.push_back(1),all.push_back(1),all.push_back(2);
    long long int n = 3;
    while(all[all.size()-1]%1000000 != 0){
        long long int posi = 1,negi = 2;
        long long int total = 0;
        for(long long int i = 1;1;++i){
            posi = i*(3*i - 1);
            posi /= 2;
            negi = -1*i*(3*-1*i - 1);
            negi /= 2;
            if(i%2 == 0){
                if(n-posi >= 0)
                    total -= all[n-posi];
                if(n-negi >= 0)
                    total -= all[n-negi];
            }
            else{
                if(n-posi >= 0)
                    total += all[n-posi];
                if(n-negi >= 0)
                    total += all[n-negi];
            }
            if(n-posi < 0 && n-negi < 0)
                break;
        }
        all.push_back(total%1000000);
        n++;
    }
    cout << "ProjectEuler 78 : " << all.size()-1 << endl;
   	return 0;
}
