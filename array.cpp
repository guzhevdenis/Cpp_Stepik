#include <iostream>
#include <array>

int main()
{
    std::array<std::string, 3> a = {"One", "Two", "Three"};
    std::cout << a.size() << std::endl;
    std::cout <<a[1] << std::endl; //иногда такое не работает
    std::cout<<a.at(1)<<std::endl;
    

    return 0;

}