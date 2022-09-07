#include <iostream>
#include <string>
void log(std::string_view message, const std::string &filename = __FILE__, int line = __LINE__)
{
  std::cout << "info:"
            << filename << ':'
            << line << ' '
            << message << '\n';
}

int main()
{
  // 是你期望的结果吗
  log("Hello world!");
}

// #include <iostream>
// #include <string_view>

// void log(std::string_view message,
//          std::string_view filename, int line)
// {
//   std::cout << "info:"
//             << filename << ':'
//             << line << ' '
//             << message << '\n';
// }

// int main()
// {
//   // 必须在这里进行宏展开
//   log("Hello world!", __FILE__, __LINE__);
// }
// 输出
// info:main.cc:16 Hello world!

// #include <iostream>
// #include <string_view>
// #include <source_location>

// void log(std::string_view message,
//          const std::source_location &location = std::source_location::current())
// {
//   std::cout << "info:"
//             << location.file_name() << ':'
//             << location.line() << ' '
//             << message << '\n';
// }

// int main()
// {
//   log("Hello world!");
// }
