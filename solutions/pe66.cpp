#include <iostream>
using namespace std;
int main(){
    long int d = 661;
    long int maxi = 0;
    long int maxd = 0;
    for(;d<=1000;++d){
        for(long long int x=140023;x<100000000;++x){
            for(long long int y=x-1;y>=1;--y){
                if(((x*x) - d*(y*y)) == 1){
                    if(x > maxi){
                        maxi = x;
                        maxd = d;
                        cout << maxi << " " << maxd << endl;
                    }
                    goto x;
                }
            }
        }
        x:
            int p =0;
    }
    cout << maxd << endl;
return 0;}
