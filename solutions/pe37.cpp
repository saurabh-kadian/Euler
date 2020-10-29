#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;
bool is_prime(long long int k){
    long long int sq = sqrt(k);
    if(k==2)
        return true;
    else if(k == 1)
        return false;
    else if(k%2==0)
        return false;
    for(long long int i=3;i<=sq;++i)
        if(k%i == 0)
            return false;
    return true;
}
int main(){
    long long int i = 13;
    long long int counter = 0;
    long long int sum = 0;
    while(1){
        string number;
        ostringstream convert;
        convert << i;
        number = convert.str();
        string lefttrunc = number;
        string righttrunc = number;
        bool flag = true;
        while(lefttrunc.length()!=0){
            istringstream con(lefttrunc);
            long long int k;
            con >> k;
            if(is_prime(k)==false){
                flag = false;
                break;
            }
            lefttrunc.erase(lefttrunc.begin()+0);
        }
        if(flag == false){
            i+=2;
            continue;
        }
        while(righttrunc.length()!=0){
            istringstream con(righttrunc);
            long long int k;
            con >> k;
            if(is_prime(k)==false){
                flag = false;
                break;
            }
            righttrunc.erase(righttrunc.length()-1);
        }
        if(flag == true){
            cout << number << endl;
            counter++;
            sum += i;
        }
        i+=2;
        if(counter == 11)
            break;
    }
    cout << sum << endl;
return 0;
}
