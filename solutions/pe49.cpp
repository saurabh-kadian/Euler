#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;
bool is_prime(long long int k){
    long long int sq = sqrt(k);
    if(k==2)
        return true;
    else if(k%2==0)
        return false;
    for(long long int i=3;i<=sq;++i)
        if(k%i == 0)
            return false;
    return true;
}
int main(){
    for(long int i= 1488;i<10000;++i){
        for(long long int diff = 1;diff<3334;++diff){
            long int n1 = i,n2 = i+diff, n3 = i+diff+diff;
            int check1[10] = {0},check3[10] = {0},check2[10] = {0};
            if(is_prime(n1) == true && is_prime(n2) == true && is_prime(n3) == true){
                string number;
            ostringstream convert;
            convert << n1;
            number = convert.str();
            string number1;
            ostringstream convert1;
            convert1 << n2;
            number1 = convert1.str();
            string number2;
            ostringstream convert2;
            convert2 << n3;
            number2 = convert2.str();
            for(int i=0;i<number.length();++i){
                int a = number[i]-48;
                check1[a]++;
                a = number1[i]-48;
                check2[a]++;
                a = number2[i]-48;
                check3[a]++;
            }
                bool flag = true;
            for(int i=0;i<10;++i){
                if(check1[i] != check2[i] || check2[i] != check3[i] || check1[i] != check3[i]){
                    flag = false;
                    break;
                }
            }
            if(flag == true){
                cout << " 1stnum : " << i << " diff:" << diff << endl;
                goto x;}
            }
        }
    }
    x:
return 0;}
