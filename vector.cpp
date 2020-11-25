#include <iostream>
#include <vector>
#include <thread>

int main()
{
    std::vector<std::string> v = {"One", "Two"};
    v.reserve(100);

    v.push_back("Three"); //создает временный объект

    v.emplace_back("Four"); //сразу передается в конструктор


    std::cout << v.capacity() << std::endl; //выводим полный объем контейнера
    v.shrink_to_fit(); //оптимизируем объем
    std::cout << v.capacity() << std::endl; 

    return 0;
}