# include <iostream>
# include <vector>
# include <string>

int main(int argc, char const *argv[])
{
    std::vector<int> vector0 {1,2,2};
    std::cout<<vector0[1]<<std::endl;
    
    std::vector<int> v1 {1,2,3};
    std::vector<int> v2 = {1,2,3};
    std::vector<int> v3;
    v3 = {1,2,3};

    for(std::vector<int>::const_iterator i = v1.begin();i != v1.end();++i)
        std::cout << *i << std::endl;
    
    using std::vector;
    vector<int> vect;
    vect.push_back(100);
    std::cout << vect[0]<<std::endl;
    std::cout << vect.size()<<std::endl;
    return 0;
}
