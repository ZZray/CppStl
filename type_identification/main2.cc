#include <iostream>
#include <typeinfo>
#include <source_location>
class A
{
};
class B : public A
{
};
class C : A
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
int main(int argc, char *argv[])
{
  try
  {
    A *a = new A;
    A *b = new B;
    C *c = new C;

    print_type(a);
    print_type(b);
    print_type(c);
  }
  catch (std::bad_typeid &e)
  {
    // 当 typeid 表达式中的实参为空值时抛出的异常
    std::cout << e.what() << std::endl;
  }
  // 可以点进入看一下源码，在不同的标准下有不同的实现。
}
// 输出
// print_type: class A * __ptr64 hascode: 7975377594211774730
// print_type: class B * __ptr64 hascode: 9847873382690236939
// print_type: class C * __ptr64 hascode: 9223567381966856156
