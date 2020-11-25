#include <iostream>
#include <list>

int main()
{
    setlocale(LC_ALL, "Russian");
    using std::string;
    std::list<std::string> l = {"One", "Two"}; //двусвязный список
//добавление или удаление производятся за константое время
    l.emplace_back("Three");
    l.emplace_front("Zero");

for (string &s : l) //range-based for
    std::cout << s << std::endl;
//splice вырезает и вставляет часть списка

    std::cout << l.front() <<std::endl;

    //iterators

    std::list<string>::iterator i = l.begin();
    for (; i!= l.end(); ++i)
        if(*i == "Two")
            break;
    
    l.erase(i);
    for (string &s : l) //range-based for
    std::cout << s << std::endl;
    

    return 0;
}