#include <iostream>
#include <regex>
#include <string>
#include <vector>

using namespace std;

//vector to store all the rows 
vector<vector<int>> rowVec;

//adds newly created rows to vector
void addNew(vector<int> newRow) {
  rowVec.push_back(newRow); 
  //return vector<int> newRow; 
}
  
//checks for the minimum element in a row
int getMin(vector<int> vecA) {
  int min = vecA[0]; 
  for(int i = 0; i < vecA.size(); i++) {
    if(vecA[i] < min) { min = vecA[i]; } 
    
  }
  return min; 
}

int solution(vector<int> A)
{
  // Your solution goes here.
    
  int pos = 0; 
  
  //initialization: create a new row 
  vector<int> newRow; 
  newRow.push_back(A[pos]); 
  addNew(newRow);
  pos++; 
  
    
  while(pos < A.size()) { 
    //traverse vector of rows
    bool assignedRow = false; 
    for(int a = 0; a < rowVec.size(); a++) { 
      int min = getMin(rowVec[a]); //get the minimum element of each row
      //if arr element < min at curr row, push arr element to row
      if(A[pos] < min) { 
        /*cout << "val at pos: " << A[pos] << endl; 
        cout << "min: " << min << endl; */
        rowVec[a].push_back(A[pos]); 
        assignedRow = true; 
        pos++; 
        break; 
      } 
    }
    
    if(!assignedRow) {
      vector<int> newRow0; 
      newRow0.push_back(A[pos]); 
      addNew(newRow0); 
      pos++; 
    }
  }
  
  int rowCount = rowVec.size(); 
  for(int i = 0; i < rowVec.size(); i++) {
     for(int j=0; j < rowVec[i].size(); j++) {
         cout<< "Row " <<i+1<<": "<< rowVec[i][j] << endl;
     }
  }
  cout << "Number of Rows: ";
  return rowCount; 
}

//turns a string into a vector arr of ints   
vector<int> toIntVector(string str)
{
  //cout << "string: " << str <<endl;
  std::vector<int> out;
  std::string i;
  std::istringstream tokenStream(str);
    while (std::getline(tokenStream, i, ',')) {
    out.push_back(atoi(i.c_str()));
    //cout<< "value: " << i << endl; 
  }
  //cout<<"vec size: "<< out.size() <<endl; 
  /*for(int i=0; i<out.size(); i++) {
      cout << out[i] <<"  "; 
  }
   cout << endl;*/
  return out;
}

int main()
{
  // Read in from stdin, solve the problem, and write answer to stdout.
  string AS;
  cin >> AS;
  vector<int> A = toIntVector(AS);
  /*for(int i = 0; i < A.size(); i++) {
      cout<< "Element " <<i<<": "<< A[i] << endl; 
  }*/
  cout << "Number of rows: " << solution(A);
}