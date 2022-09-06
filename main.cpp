#include <iostream>
#include "utils.h"
#include <string>
#include <ctime>    // time
#include <cstdlib> // rand
#include <random>

using namespace std;
clock_t tbs,tes;//Timing
//If testing please remove the comment symbol!!!

int main() 
{
  BST* e_root = nullptr; //empty tree
/*
  //  Q2.1 create a predefined tree include 4 reservations
  //  BST* root = nullptr ;
  BST* n4 = setNode(1, 5, "Res 4", nullptr, nullptr);
  BST* n3 = setNode(30, 31, "Res 3", nullptr, nullptr);
  BST* n2 = setNode(7, 9, "Res 2", n4, nullptr);
  BST* n1 = setNode(15, 23, "Res 1", n2, n3);
  // print the tree
  cout << "Reservation information now: " << endl;
  printT(n1);
  cout << endl;
*/

/*
  //  Q2.2 add a new reservation
  BST* res5= new BST ;
  cout << "Please enter the begin time"<< endl;
  cin >> res5->data.b_time ;
  cout << "Please enter the end time"<< endl;
  cin >> res5->data.e_time;
  cout << "Please enter the User's name"<< endl;
  cin >> res5->data.name ; 
  n1 = add(res5,n1);
  // print the tree
  cout << endl;
  cout << "Reservation information now: " << endl;
  printT(n1);
*/

/*
  //  Q2.3 remove reservvation
  Res rnode; 
  cout << "Please enter the begin time"<< endl;
  cin >> rnode.b_time ;
  cout << "Please enter the end time"<< endl;
  cin >> rnode.e_time ;

  n1 = remove(rnode,n1);
  // print the tree
  cout << endl;
  cout << "Reservation information now: " << endl;
  printT(n1);
*/


///*
  //Q7 add several new reservations, suppose N=4（N,2N,4N,8N,...64N）
  int num = 0;
  cout << "How many users do you want to add?" <<endl;
  cin >> num;
  

  for(int j=0; j<num; j++)
  {
  //Generate random numbers
  random_device r;
  //choose a random mean between 1 and 365
  default_random_engine b(r());
  default_random_engine e(r());
  uniform_int_distribution<int> uniform_dist(1,365);

  int b_time = uniform_dist(b);
  int e_time = uniform_dist(e);
  while (b_time == e_time)
  {
    default_random_engine e(r());
  }
  if (b_time > e_time)
  {
    swap(b_time,e_time);
  }  
    
    BST* n = setNode(b_time, e_time, "new res",nullptr,nullptr);
    
    tbs = clock();
    e_root = add(n,e_root);
    tes = clock();
    //cout << "The "<< j+1 << "th "<<"time of add reservation is: " <<(float)(tes - tbs)/CLOCKS_PER_SEC << endl;
    double time = time + ((double)(tes - tbs)/CLOCKS_PER_SEC);
    cout << "The "<<"time required after the " << j+1 << "th" <<" addition is " <<time << endl;  
  }
    
  // print the tree
  cout << endl;
  cout << "Reservation information now: " << endl;
  printT(e_root);
//*/

/* 
  // remove reservvation
  Res rnode; 
  cout << "Please enter the begin time"<< endl;
  cin >> rnode.b_time ;
  cout << "Please enter the end time"<< endl;
  cin >> rnode.e_time ;

  e_root = remove(rnode,e_root);
  // print the tree
  cout << endl;
  cout << "Reservation information now: " << endl;
  printT(e_root);
*/
}

