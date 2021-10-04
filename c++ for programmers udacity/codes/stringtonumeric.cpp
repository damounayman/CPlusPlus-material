# include "Header.hpp"
# include <sstream>

int main(int argc, char const *argv[])
{
    /* code */
    string mynumb;
    cout<<"input your favorite numbre :";
    getline(cin,mynumb);
    int num;
    stringstream(mynumb) >> num;
    int fois2;
    fois2 = num*2;
    cout<<fois2;
    return 0;
}
