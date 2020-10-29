#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
int main(){
    vector<long long int> nums;
    long long int i=1;
    while(i<100000){
        string pan;
        for(int l=1;l<10;++l){
            long long int temp = i*l;
            string number;
            ostringstream convert;
            convert << temp;
            number = convert.str();
            pan.append(number);
            if(pan.length()>=9)
                break;
        }
        if(pan.length()>9){
            i++;
            continue;
        }
        int check[10]={0};
        for(int a=0;a<pan.length();++a){
            long int o = pan[a]-48;
            check[o]++;
        }
        bool flag = true;
        for(int t=1;t<10;++t){
            if(check[t]!=1){
                flag = false;
                break;
            }
        }
        istringstream con(pan);
        long long int k;
        con >> k;
        if(flag == true){
            nums.push_back(k);
        }
        i++;
    }
    long long int maxi;
    maxi = *max_element(nums.begin(),nums.end());
    cout << maxi << endl;
    return 0;
}
