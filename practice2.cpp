#include <iostream>
#include <regex>
#include <string>
#include <vector>

using namespace std;

vector<int> arrCopy; 

//returs the pos of the max elem in the arr 
int getMax(vector<int> arrVec) {
  int pos_max; 
  int max = arrVec[0]; 
  for(int i=0; i<arrVec.size(); i++) { 
    if(arrVec[i] > max) { 
      max = arrVec[i]; 
      pos_max = i; 
    }
  }
  //arrVec.erase(pos_max);
  return pos_max; 
}

int getSum(vector<int> arrVec) {
  int sum = 0; 
  for(int i=0; i<arrVec.size(); i++) {
    sum += arrVec[i]; 
  }
  return sum; 
}

//find the max value in the vec that is less than rem
int findClosest(int rem, vector<int> aVec) {
 //int pos;  
 int maxVal_pos = getMax(aVec); 

 //keep checking for a max element that is less than the rem
 while(!(rem >= aVec[maxVal_pos])) { 
    arrCopy.push_back(aVec[maxVal_pos]);    //push curr max to new vec
    aVec.erase(aVec.begin()+maxVal_pos);    //remove the curr max from old vec
    maxVal_pos = getMax(aVec);              //get new max_pos
     
 }
 return maxVal_pos; 
}

int solution(vector<int> A)
{
  // Put your solution here
  
  //get the sum of all ints in the array 
  int aTotal = getSum(A); 
  
  int mid = aTotal/2; 
  int loadV = 0; 
  int cMax_pos = getMax(A); 
  loadV += A[cMax_pos];
  A.erase(A.begin()+cMax_pos); 
  
  while(loadV < mid) {
    int rem = mid - loadV; 
    int addPos = findClosest(rem, A); 
    int addVal = A[addPos]; 
    if(addVal <= rem) {
      loadV += addVal; 
      A.erase(A.begin()+addPos); 
    }
  }
  
  cout << "loadV: " << loadV << endl; 
  //get sum of the remainder of the array 

  int sumA = 0; 
  if(A.size() > 0) {
      sumA = getSum(A); 
  }
  int lsum = sumA + getSum(arrCopy); 
  cout << "lsum: "<< lsum << endl; 
  
  int diff; 
  if(loadV > lsum) {diff = loadV - lsum; } 
  else diff = lsum - loadV; 
  
  
  //cerr << "Tip: Use cerr to write debug messages on the output tab.";
  return diff; 
}

vector<int> toIntVector(string str)
{
  std::vector<int> out;
  std::string i;
  std::istringstream tokenStream(str);
  while (std::getline(tokenStream, i, ','))
  {
    out.push_back(atoi(i.c_str()));
  }
  return out;
}

int main()
{
  // Read in from stdin, solve the problem, and write answer to stdout.
  string AS;
  cin >> AS;
  cout << solution(toIntVector(AS));
}