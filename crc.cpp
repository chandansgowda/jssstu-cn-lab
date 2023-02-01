#include<iostream>
#include<string.h>
using namespace std;

string crc(string data, string poly, bool errChk){
    string rem = data;
    if (!errChk){
        for(int i=0; i<poly.length()-1;i++)
            rem.append("0");
    }
    for(int i=0;i<rem.length()-poly.length()+1;i++){
        if (rem[i]=='1'){
            for(int j=0; j<poly.length();j++){
                rem[i+j] = (rem[i+j]==poly[j]) ? '0': '1';
            }
        }
    }
    return rem.substr(rem.length()-poly.length()+1);
}

int main(){
    string data;
    string poly = "10000100010001010";

    cout << "Enter Data to be sent: " ;
    cin >> data;

    string rem = crc(data,poly,0);
    string codeword = data+rem;

    cout << "Remainder: " << rem << endl;
    cout << "Codeword: " << codeword << endl;

    //Checking error
    string recvCodeword;
    cout << "Enter received codeword: " ;
    cin >> recvCodeword;

    string recvRem = crc(recvCodeword, poly, 1);

    if (stoi(recvRem)==0){
        cout << "No Error";
    }
    else{
        cout << "Error Detected";
    }

    return 0;
}