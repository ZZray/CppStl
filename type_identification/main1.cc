/*
 * @Date: 2022-09-09 07:51:49
 * @Author: 泡泡的部落格
 * @LastEditors: 泡泡的部落格
 * @LastEditTime: 2022-09-09 22:22:24
 * @FilePath: \CppStl\type_identification\main1.cc
 * @Git: https://github.com/ZZray/CppStl
 * @Video: https://space.bilibili.com/172172152
 * @Description:
 */

#include <iostream>
#include <typeinfo>
#include <source_location>
class A
{
};
template <typename T>
void print_type(T t)
{
  const auto &typeinfo_ = typeid(t);
  // same as auto typeinfo = typeid(T);
  std::cout << std::source_location::current().function_name() << ": "
            << typeinfo_.name() << " hascode: " << typeinfo_.hash_code() << std::endl;
}
template <typename T>
bool is_double(T t)
{
  return typeid(t) == typeid(double);
  // return typeid(T) == typeid(double);
}
int main(int argc, char *argv[])
{
  try
  {
    // 直接获取类型的类型
    std::cout << typeid(A &).name() << " ";
    std::cout << typeid(const A &).hash_code() << std::endl;
    std::cout << std::string(100, '=') << std::endl;
    // 获取对象的类型
    A a;
    const A &b = a;
    print_type(a);
    print_type(b);
    // 获取基本类型变量的类型
    double d = 0.;
    print_type(d);
    int i = 1;
    print_type(i);
    // 获取指针的类型
    double *d_ptr = new double;
    print_type(d_ptr);
    //
    std::cout << std::string(100, '=') << std::endl;

    // 这里注意一点，？ 的优先级
    std::cout << "d is " << (is_double(d) ? "" : "not ") << "a double value\n";
    std::cout << "i is " << (is_double(i) ? "" : "not ") << "a double value\n";
    // 获取表达式的类型
    std::cout << "i+1.0 is " << (is_double(i + 1.0) ? "" : "not ") << "a double value\n";
    std::cout << std::string(100, '=') << std::endl;
    //
    print_type(main);
    print_type(nullptr);
  }
  catch (std::bad_typeid &e)
  {
    // 当 typeid 表达式中的实参为空值时抛出的异常
    std::cout << e.what() << std::endl;
  }
  // 可以点进入看一下源码，在不同的标准下有不同的实现。
}
