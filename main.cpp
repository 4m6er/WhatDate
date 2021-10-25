#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

void WhatDate(int);
time_t now = time(0);

tm * ltm = localtime(&now);
int Y=1900+ltm->tm_year;
int M=1+ltm->tm_mon;
int D=ltm->tm_mday;

vector<int> arr={31,28,31,30,31,30,31,31,30,31,30,31};
vector<int> arr_special={31,29,31,30,31,30,31,31,30,31,30,31};

int main() {

    int days;


    cout<<"enter days"<<endl;
    cin>>days;
    if(days>0) {
        WhatDate(days);
        cout<<Y<<"/"<<M<<"/"<<D<<endl;

    }
    else     cout<<Y<<"/"<<M<<"/"<<D<<endl;

    return 0;

}

void WhatDate(int x){
    vector<int> ar=arr;
    for(int i=1;i<=x;i++){
        if((Y-2020)%4==0) ar = arr_special;
        else ar=arr;
        D++;
        if(D>ar[M-1]){
            M++;
            D=1;
            if(M==13){
                Y++;
                M=1;

            }
        }


    }

}


