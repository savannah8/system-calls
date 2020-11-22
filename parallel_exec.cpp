#include<iostream>
#include<unistd.h>
#include<fstream>
using namespace std;
int main(){

fstream file;
string path,filename;
filename = "input.txt";

file.open(filename.c_str());
while (file >> path)
    {
        cout << path << endl;
    }
return 0;
}
