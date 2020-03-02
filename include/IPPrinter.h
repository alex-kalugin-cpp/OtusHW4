/*!
\file
\brief Заголовочный файл с функциями печати условного IP адреса

Данный файл содержит в себе шаблонные функции, реализующие
печать условного IP адреса.
Адрес может быть представлен: интегральным типом, в виде строки, в виде контейнера, в виде кортежа с одинаковыми типами
Идея для определения контейнеров и интергальных типов взята отсюда: http://scrutator.me/post/2016/12/12/sfinae.aspx
Идея определения кортежа отсюда:https://stackoverflow.com/questions/13101061/detect-if-a-type-is-a-stdtuple
Определение строки тривиально.
*/
#pragma once
#include <iostream>
#include <algorithm>
#include "toPrintTuple.h"
/*!
\brief Печать IP адреса из контейнера
Функция печатает IP адрес из контейнера
Выводим поэлементно начиная с первого с символом . в качестве разделителя
\param[out] str Поток вывода
\param[in] Т параметр шаблонного класса (контейнера)
\param[in] container контейнер с данными
*/
template <typename T>
decltype(begin(std::declval<T>()), end(std::declval<T>()), void())  ///<контейнер если есть методы begin и end
//typename std::enable_if<!std::is_integral<T>::value, void>::type  ///<bad solution
printIP(std::ostream& str,const T& container)
{

    for(auto it = begin(container); it != end(container); ++it )
    {
        if(it != begin(container)) str  << ".";
        str << *it;
    }

}

/*!
\brief Печать IP адреса из строки
Функция печатает IP адрес из строки как есть (просто выводит строку в поток)
\param[out] str Поток вывода
\param[in] value строка с данными
\warning Функция не шаблонная!
*/
void printIP(std::ostream& str, const std::string& value)
{
    str << value;
}
/*!
\brief Печать IP адреса из строкового литерала
Функция печатает IP адрес из строкового литерала как есть (просто выводит в поток)
Функция добавлена для совместимости со стороками с стиле С
\param[out] str Поток вывода
\param[in] value строковый литерал
\warning Функция не шаблонная!
*/
void printIP(std::ostream& str, const char* value)
{
    str << value;

}
/*!
\brief Печать IP адреса из интергальых типов
Функция печатает IP адрес из стандартных целочисленных типов
Выводим побайтово начиная со старшего с символом . в качестве разделителя
\param[out] str Поток вывода
\param[in] Т параметр шаблонного класса (числа)
\param[in] value число
*/
template <typename T>
//decltype(std::cout << std::declval<T>(), void())
typename std::enable_if<std::is_integral<T>::value, void>::type ///<проверка на целочисленные типы
printIP(std::ostream& str,T value)
{
   std::size_t size = sizeof(value);
   uint8_t bytes[size];
     std::reverse_copy(
                static_cast<const char*>(static_cast<const void*>(&value)),
                static_cast<const char*>(static_cast<const void*>(&value)) + size,
                bytes
                );
    for(std::size_t i=0;i< size;++i)
    {
        if(i!=0) str << ".";
        str << +bytes[i];
    }
 }
/*!
\brief Печать IP адреса из std::tuple
Функция печатает IP адрес из кортежа
Выводим поэлементно начиная с первого с символом . в качестве разделителя
Все элементы кортежа должны быть одного типа
\param[out] str Поток вывода
\param[in] Args... множество типов элементов кортежа
\param[in] value кортеж с данными
*/
template<class... Args>
void printIP(std::ostream& str, const std::tuple<Args...>& value)
{
   //str << "TUPLE";
    tupleprint::print(str, value);
}
