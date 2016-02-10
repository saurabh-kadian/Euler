// PE58
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
bool is_prime(long long int k){
    if(k==1)
        return false;
    if(k==2)
        return true;
    if(k%2==0)
        return false;
    long long int sq =sqrt(k);
    for(long long int i=3;i<=sq;i++)
        if(k%i==0)
            return false;
    return true;
}
int main(){
    long long int n = 3,number = 1;
    double pc = 0,total = 1;
    while(1){
        double ratioVal = 0;
        for(int i=0;i<4;++i){
            number += n-1;
            if(is_prime(number))
                pc++;
            total++;
        }
        ratioVal = pc/total;
        if(ratioVal < 0.1)
            break;
        n+=2;
    }
    cout << n << endl;
return 0;}
