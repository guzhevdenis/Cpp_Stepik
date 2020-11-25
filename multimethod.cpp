#include <typeinfo>
#include <typeindex>
#include <map>
#include <functional>
#include <utility>
#include <iostream>
typedef unsigned uint4;
typedef unsigned long long uint8;

// Base - базовый класс иерархии
// Result - тип возвращаемого значения мультиметода
// Commutative - флаг, который показывает, что
// мультиметод коммутативный (т.е. f(x,y) = f(y,x)).
// базовый класс фигуры (полиморфный)
struct Shape { virtual ~Shape(){} };

// прямоугольник
struct Rectangle : public virtual Shape { int a = 5; };

// треугольник
struct Triangle : public virtual Shape { int b = 6; };

// функция для проверки пересечения двух прямоугольников
bool is_intersect_r_r(Shape * a, Shape * b);


// функция для проверки пересечения прямоугольника и треугольника
bool is_intersect_r_t(Shape * a, Shape * b);
void cool ( const std::type_info & a,  const std::type_info & b, std::function<void (Shape*, Shape*)> f );
  
template<class Base, class Result, bool Commutative>
struct Multimethod2
{
    // устанавливает реализацию мультиметода
    // для типов t1 и t2 заданных через typeid 
    // f - это функция или функциональный объект
    // принимающий два указателя на Base 
    // и возвращающий значение типа Result 
    
 

    void addImpl( const std::type_info& t1, const std::type_info& t2, std::function<Result (Base*, Base*)>  f )
    {       
       auto key = std::make_pair(std::type_index(t1),std::type_index(t2));
       MethodCases.emplace(std::make_pair(key,f));  
    
    }
    
    // проверяет, есть ли реализация мультиметода
    // для типов объектов a и b
    bool hasImpl(Base * a, Base * b) const
    {
        // возвращает true, если реализация есть
        // если операция коммутативная, то нужно 
        // проверить есть ли реализация для b и а 
            auto key = std::make_pair(std::type_index(typeid(*a)),std::type_index(typeid(*b)));
            if (Multimethod2::MethodCases.find(key) != MethodCases.end()) {
            return 1;
        }
        if (Commutative)
        {
             key = std::make_pair(std::type_index(typeid(*b)),std::type_index(typeid(*a)));
            if (MethodCases.find(key) != MethodCases.end()) {
            return 1;
        }
        }
        else return 0;
    }

    // Применяет мультиметод к объектам
    // по указателям a и b
    Result call(Base * a, Base * b) const
    {             
        auto  key = std::make_pair(std::type_index(typeid(*a)),std::type_index(typeid(*b)));
        auto f = MethodCases.find(key)->second;
        
        if(Commutative == true)
        {
            std::cout <<" hello ";
             if(MethodCases.find(key) == MethodCases.end())
            {
                key = std::make_pair(std::type_index(typeid(*b)),std::type_index(typeid(*a)));
                f = MethodCases.find(key)->second;
                return f(b,a);
            }
            else{
                return f(a,b);
            }
        }
        
        else 
        { 
           return f(a,b);
        }
        
    }

   std::map<std::pair<std::type_index, std::type_index>,std::function<Result (Base*, Base*)>> MethodCases;
 
};



int main()
{
    Rectangle a;
    Triangle b;
 using namespace std;
  Multimethod2<Shape,bool,true> intersect;

    intersect.addImpl(typeid(a),typeid(b), is_intersect_r_t);
    Rectangle *c;
    Triangle *d;
    bool t = intersect.hasImpl(c, d);

    cout << "hellpL";

    return 0;
}

void cool ( const std::type_info & a,  const std::type_info & b, std::function<void (Shape*, Shape*)> f )
{
  auto t = std::make_pair(std::type_index(a), std::type_index(b));
    Rectangle *c;
    Triangle *d;

  return f(c,d);
  
}

bool is_intersect_r_t(Shape * a, Shape * b)
{
    
}


