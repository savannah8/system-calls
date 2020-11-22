#include <iostream>
#include <unistd.h>
using namespace std;
int main() {
  int parentId = getpid();

  int childId = fork();
  if(childId == 0) {
    childId = getpid();
    int grchildId = fork();
    if (grchildId == 0)  {
      grchildId = getpid();

      cout << "My process id is " << grchildId << "\n" ;
      cout << "My parent's id is " << childId << "\n";
      cout << "My Grandparent's id is " << parentId << "\n";
  }
}
}


