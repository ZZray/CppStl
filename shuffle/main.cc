#include <array>
#include <iostream>
#include <chrono>

#include <random>// 随机数生成器
#include <algorithm>// shuffle

template <class RandomIt, class F>
void shuffle(RandomIt first, RandomIt last, F&& f) { // shuffle [_First, _Last) using URNG _Func
	const auto len = last - first;
	for (auto it = first; it != last; ++it) {
		const auto index = it - first;
		std::swap(first[index], first[f() % len]);
	}
}

int main()
{
	// 洗牌重排序, 随机打乱一个数组
	std::array<int, 10> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	std::mt19937 rng(time(0));
	// std::shuffle(v.begin() + 3, v.end(), rng);
	::shuffle(v.begin() + 3, v.end(), rng);
	return 0;
}
