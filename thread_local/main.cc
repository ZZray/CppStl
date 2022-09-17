/*
 * @Date: 2022-09-17 21:09:48
 * @Author: 高效Cpp
 * @LastEditors: 高效Cpp
 * @LastEditTime: 2022-09-17 22:16:47
 * @FilePath: \CppStl\thread_local\main.cc
 * @Git: https://github.com/ZZray/CppStl
 * @Video: https://space.bilibili.com/172172152
 * @Description:
 */
#include <iostream>
#include <thread>
#include <memory>
// 高效 Cpp
void add()
{
	thread_local int a = 0;
	a++;
	std::cout << "a: " << a << std::endl;
}
int main()
{
	add();
	add();
	std::thread th1{[]
									{
										add();
										add();
									}};
	th1.join();
	return 0;
}
// #include <iostream>
// #include <iostream>
// #include <thread>
// class A
// {
// public:
// 	A()
// 	{
// 		std::cout << std::this_thread::get_id() << " " << __FUNCTION__ << std::endl;
// 	}
// 	~A()
// 	{
// 		std::cout << std::this_thread::get_id() << " " << __FUNCTION__ << std::endl;
// 	}
// 	void print()
// 	{
// 		//static int v = 0;
// 		std::cout << std::this_thread::get_id() << " " << ++v << std::endl;
// 		std::cout.flush();
// 	}
// 	// 前面说到成员变量必须加static，不然编译报错
// 	// C++17 inline static, 成员变量加上thread_local 表示该成员每个线程一个，不加thread_local 则是全局一个
// 	inline static thread_local int v = 0;
// };
// A a;
// int main()
// {
// 	// 主线程
// 	a.print();
// 	// 线程1
// 	std::thread th1([] { a.print(); });
// 	// 线程2
// 	std::thread th2{ [] { a.print(); } };
// 	th2.join();
// 	th1.join();
// 	return 0;
// }
