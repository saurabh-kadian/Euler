#include <iostream>
#include <string>
#include <cmath>
using namespace std;
bool is_prime(long long int k){
    if(k==2 || k == 3)
        return true;
    if(k%2==0 || k%3 == 0)
        return false;
    for(long long int i=3;i*i<=k;++i)
        if(k%i == 0 || k%(i+2) == 0)
            return false;
    return true;
}
int main()
{
    long long int maxi = 0,maxc= 0;
    for(long long int i=3;i<1000;i+=2){
        long long int sum = 0,counter=0;
        for(long long int j=i;j<100000;j+=2){
            if(is_prime(j) == true){
               sum += j;
               counter++;
               if(sum > 1000000)
                    break;
               if(is_prime(sum) == true && counter > maxc){
                    maxc = counter;
                    maxi = sum;}
            }
        }
    }
    cout << maxi << " " << maxc << endl;
    return 0;
}
