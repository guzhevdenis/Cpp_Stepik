#include <iostream>
#include <map>
//ключ должен быть уникальным
//map хранит упорядоченное отображение (как дерево поиска по ключю).
int main()
{
    std::map<std::string, int> phonebook;
    phonebook.emplace("Marge", 2128506);
    phonebook.emplace("Lisa", 2128507);
    phonebook.emplace("Bart", 2128507);

    auto it = phonebook.find("Marge");
     if ( it != phonebook.end())
     {
         std::cout <<"Marge:" << it->second <<"\n";
     }

    return 0;
}