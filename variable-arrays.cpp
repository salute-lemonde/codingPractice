#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//array of vectors 
vector<vector<int>> vecArr;

//nested variable array
vector<int> intArr;

int getQuery(int a, int b) { 
    for(int r=0; r<vecArr.size(); r++) { 
        for(int s=0; s<intArr.size(); s++) {
            return vecArr[a][b]; 
        }
    }
    return 0; 
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N, q; 
    cin >> N >> q; 
    cout << "N: " << N << "q: " << q << endl; 
            
    //to populate the arrays 
    
    for(int i=0; i<N; i++) {
        int k; 
        cin >> k; 
        
        intArr.clear(); 
        for(int j=0; j<k; j++) {
            int kVal; 
            cin >> kVal; 
            intArr.push_back(kVal); 
        }
        vecArr.push_back(intArr); 
        
    }
    
    //test print the content of the arrays 
    for(int f=0; f<vecArr.size(); f++) { 
        for(int g=0; g<intArr.size(); g++) { 
            cout << "[" << f << "," << g << "]" << vecArr[f][g] << endl; 
        }
    }
    int i, j; 
    vector<int> ansArr; 
    for(int i=0; i<q; i++) { 
        cin >> i >> j; 
        ansArr.push_back(getQuery(i, j)); 
    }
    
    //result
    for(int v=0; v<ansArr.size(); v++) { 
        cout << ansArr[v] << endl; 
    }
    
    return 0;
}