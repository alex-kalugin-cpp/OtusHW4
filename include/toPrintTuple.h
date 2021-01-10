/*!
\file
\brief Заголовочный файл с вспмогательными функциями печати условного IP адреса из std::tuple

Данный файл содержит в себе шаблонные функции, реализующие
печать условного IP адреса из std::tuple  и проверку аргументов исходного tuple
Адрес должен быть представлен в виде кортежа с одинаковыми типами
*/
#pragma once
#include <tuple>
#include <type_traits>
#include <iostream>
/*!
\brief Функция с реакцией на ошибочный кортеж
Функция выводит предупреждение (бросает исключение)
в случае неидетничных элементов кортежа
\param[out] str Поток вывода
*/
void warning(std::ostream& str)
{
   // or throw exeption
   str << "WARNING: Tulpe members are not same type";
}
/*!
\brief Вспомогательная структура для шаблонной магии
\param[in] typename ...T  набор типов элементов
*/
template <typename ...T>
struct pack {};
/*!
\brief Функция проверяет набор типов элементов на принадлежность одному типу
Функция проверяет набор типов элементов на принадлежность одному типу
Найдена в комментариях к этой теме: https://www.cyberforum.ru/cpp/thread1652384.html
\param[in] typename T, typename... V  набор типов элементов
\warning DANGER! TEMPLATE MAGIC!!!
*/
template <typename T, typename... V>
struct is_all_same
    : std::is_same< pack<T, V...>, pack<V..., T> >
{ };

/*!
\brief namespace содержит функции печати кортежа
namespace tupleprint содержит шаблонные функции печати кортежа
каркас структур TuplePrinter и функции print взяты с cppreference
*/
// helper function to print a tuple of any size
namespace tupleprint
{
/*!
\brief печать кортежа с N элементомами
вывод на печать печать кортежа с несколькими элементом
\param[out] str  поток вывода
\param[in] N число элементов
\param[in] t кортеж
\warning N>2
*/
template<class Tuple, std::size_t N>
struct TuplePrinter {
     static void print(std::ostream& str,const Tuple& t)
    {

        TuplePrinter<Tuple, N-1>::print(str,t);
        str << "." << std::get<N-1>(t);
    }

};
/*!
\brief печать кортежа с одним элементом
вывод на печать печать кортежа с одним элементом
\param[out] str  поток вывода
\param[in] t кортеж
*/
template<class Tuple>
struct TuplePrinter<Tuple, 1>{
       static void print(std::ostream& str,const Tuple& t)
    {
        str << std::get<0>(t);
    }
  };
/*!
\brief печать кортежа
печать кортежа с проверкой идентичности типов
\param[out] str  поток вывода
\param[in] Args... набор типов кортежа
\param[in] t кортеж
*/
template<class... Args>
void print(std::ostream& str, const std::tuple<Args...>& t)
{
    //static_assert(is_all_same<Args...>::value,"Tulpe members are not same type");
    //  TuplePrinter<decltype(t), sizeof...(Args)>::print(str,t);

    is_all_same<Args...>::value
        ?
    TuplePrinter<decltype(t), sizeof...(Args)>::print(str,t)//;
        :
          warning(str)
        ;

}
/*!
\brief печать пустого кортежа
печать пустого кортежа
\param[out] str  поток вывода
\param[in] t кортеж
*/
void print(std::ostream& str, const std::tuple<>& t)
{
    //бестолковый код
    //написан лишь бы компилятор не ругался на неиспользуемые str и t
    std::tuple<> tt;
    if(t==tt)
    str << "";

}
}




