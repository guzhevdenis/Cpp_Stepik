#include <iostream>
#include <set>
//set хранит упорядоченное множество( как двоичное дерево поиска).
int main()
{
    std::set<int> primes = {2, 3, 5, 7, 11};
    // дальнейшее заполнение
    //решето Эратосфена
    if (primes.find(137) != primes.end())
        std::cout << 173 << " is prime \n";

   // std::pair <iterator, bool>
    
    auto res = primes.insert(3);

  //  std::cout << res.bool << std::endl;

std::multiset<int> fib = {0, 1, 1,2,3,5,8};
//iterator
auto result = fib.insert(13);

//pair <iterator, iterator>
auto eq = fib.equal_range(1);
    return 0;
}