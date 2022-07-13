#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

string findIntStr(int n) {
    string IntArr[9] = {"one", "two", "three", "four", "five", "six","seven", "eight", "nine" };
   
    if(n == 9) return "nine";
    for(int i=1; i<10; i++) {
        if(n == i) return IntArr[i-1]; 
         
    }
    
    return 0; 
}

int returnVal(int n) { 

    //invalid input
    string nStr = " "; 
    if(n < 1 || n > pow(10, 9)) { 
        return 0; 
    }

    else if(n < 9 || n == 9) {
        nStr = findIntStr(n); 
        cout << nStr << endl; 
    }

    else cout << "Greater than 9" << endl; 
   
    return 0; 
} 

int main()
{
    string n_temp;
    getline(cin, n_temp);
    
    //cout << "n_temp: " << n_temp << endl; 

    int n = stoi(ltrim(rtrim(n_temp)));

    // Write your code here
    returnVal(n);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
