#include <iostream>
#include <string>
#include <utility>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main(){
    freopen("roman.txt","r",stdin);
pair <char,int> roman[7];
roman[0].first = 'I';
roman[0].second = 1;
roman[1].first = 'V';
roman[1].second = 5;
roman[2].first = 'X';
roman[2].second = 10;
roman[3].first = 'L';
roman[3].second = 50;
roman[4].first = 'C';
roman[4].second = 100;
roman[5].first = 'D';
roman[5].second = 500;
roman[6].first = 'M';
roman[6].second = 1000;
string arr[1000];
long long int diff = 0;
for(int i=0;i<1000;++i){
    cin >> arr[i];
    unsigned long long int number = 0;
    for(int j=0;j<arr[i].length();++j){
        if(j!=arr[i].length()-1){
            if(arr[i][j] == 'I' && arr[i][j+1] == 'X'){
                number += 9;
                j++;
            }
            else if(arr[i][j] == 'I' && arr[i][j+1] == 'V')
                {number += 4;j++;}
            else if(arr[i][j] == 'X' && arr[i][j+1] == 'L')
                {number += 40;j++;}
            else if(arr[i][j] == 'X' && arr[i][j+1] == 'C')
                {number += 90;j++;}
            else if(arr[i][j] == 'C' && arr[i][j+1] == 'D')
                {number += 400;j++;}
            else if(arr[i][j] == 'C' && arr[i][j+1] == 'M')
                {number += 900;j++;}
            else{
                for(int t=0;t<7;++t){
                    if(arr[i][j] == roman[t].first){
                        number += roman[t].second;
                        break;
                    }
                }
            }
        }
        else{
                for(int t=0;t<7;++t){
                    if(arr[i][j] == roman[t].first){
                        number += roman[t].second;
                        break;
                    }
                }
            }
    }
    long int temper = number;
    int org = arr[i].length();
    int newSize = 0;
    if(number%10 == 4 || number%10 == 9){
        newSize+=2;
        if(number%10 == 4)
            number -= 4;
        else
            number -= 9;
        }
    if((number%100 >= 40 && number%100 <=49) || (number%100 >= 90 && number%100 <=99)){
        newSize+=2;
        if(number%100 >= 40 && number%100 <=49)
            number -= 40;
        else
            number -= 90;
        }
    if((number%1000 >= 400 && number%1000 <=499) || (number%1000 >= 900 && number%1000 <=999)){
        newSize+=2;
        if(number%1000 >= 400 && number%1000 <=499)
            number -= 400;
        else
            number -= 900;
        }
    newSize += number/1000;
    number %= 1000;
    newSize += number/500;
    number %= 500;
    newSize += number/100;
    number %= 100;
    newSize += number/50;
    number %= 50;
    newSize += number/10;
    number %= 10;
    newSize += number/5;
    number %= 5;
    newSize += number/1;
    if(org-newSize > 0)
        cout << arr[i] << " " << temper << " " << org-newSize << endl;
        diff += (org-newSize);
}
cout << diff << endl;
return 0;
}
