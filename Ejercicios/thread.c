//g++ -std=c++0x -pthread thread.cpp
/*ps -laT
 *ps -lat | grep exe
 */ 
#include <iostream>
#include <thread>
#include <chrono>
#include <string>
using namespace std;

int contador;

void pause_thread(int n,string sign) {
  std::cout<<"thread with ID "<<sign<<n<<std::endl;
  contador++;
}

int main() {
  contador = 0;
  string str = " -> ";
  std::cout<<"Inician los thread \n";
  
  for(int x=1; x<20; x++) 
  {
    std::thread(pause_thread,x,str).detach();
  }

  std::cout<<"End thread"<<std::endl;
  for(int i=0;i<contador;i++){}

  return 0;
}
