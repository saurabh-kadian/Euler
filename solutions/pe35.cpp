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
    long long int counter = 4;
    for(long long int i=11;i<1000000;i+=2){
        if(is_prime(i) == false)
            continue;
        string number;
        ostringstream convert;
        convert << i;
        number = convert.str();
        bool flag = true;
        for(long long int l=0;l<number.length();++l){
            istringstream con(number);
            long long int k;
            con >> k;
            if(is_prime(k) == false){
                flag = false;
                break;
            }
            string temp = number;
            for(long long int p=0;p<number.length();++p){
                if(p == number.length()-1)
                    temp[0] = number[number.length()-1];
                temp[p+1] = number[p];
            }
            number = temp;
        }
        if(flag == true)
            counter++;
    }
    cout << counter << endl;
return 0;}
