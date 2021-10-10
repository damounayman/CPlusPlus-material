#include <iostream>
#include <string>

using namespace std;

int main() {
	// Complete the program
    string line1;
    string line2;

    getline(cin,line1);
    getline(cin,line2);

    cout<<line1.size()<<" "<<line2.size()<<endl;
    cout<<line1+line2<<endl;
    char tmp = line1[0];
    char tmp1 = line2[0];
    cout<<tmp1+line1.erase(0,1)+" "+tmp+line2.erase(0,1)<<endl;

  
    return 0;
}