/*
 * @Date: 2022-09-09 22:22:14
 * @Author: 泡泡的部落格
 * @LastEditors: 泡泡的部落格
 * @LastEditTime: 2022-09-11 21:19:45
 * @FilePath: \CppStl\type_identification\main.cc
 * @Git: https://github.com/ZZray/CppStl
 * @Video: https://space.bilibili.com/172172152
 * @Description:
 */
#include <typeinfo>
#include <vector>
#include <string>
#include <map>
#include <array>
#include <string_view>
#include <iostream>
#include <memory>
class PPJson
{
public:
  // shared data
  static PPJson parse(const std::string &strJson)
  {
    PPJson json;
    json._values = std::make_shared<std::map<std::string, std::string>>(); // 找到第一个引号
    auto keyStart = strJson.find('"');
    while (keyStart != std::string::npos)
    {
      // 找到下一个引号
      auto keyStop = strJson.find('"', ++keyStart);
      // 取中间的就是 key
      std::string key = strJson.substr(keyStart, keyStop - keyStart);

      // value是冒号分隔的
      auto valueStart = strJson.find(':', keyStop);
      // 结束的是 ,
      auto valueStop = strJson.find_first_of(",}", ++valueStart);
      // 获取中间的数据
      std::string value = strJson.substr(valueStart, valueStop - valueStart);
      //
      // if (value.front() == "\""){} // string

      json._values->insert({key, value}); // _values[key] = value;

      keyStart = strJson.find('"', ++keyStop);
    }
    return json;
  }
  std::string value(const std::string &key) const
  {
    return _values->at(key);
  }

private:
  std::shared_ptr<std::map<std::string, std::string>> _values;
};

// constexpr std::array<std::string_view, 3> user_keys = {"name", "age", "height"};

#if 0
// 编译时判断
// 统一转换
template <typename T>
bool assign(T &t, const std::string &value)
{
  if constexpr (std::is_same_v<T, int>)
  {
    t = std::stoi(value);
    return true;
  }
  else if constexpr (std::is_same_v<T, std::string>)
  {
    t = value;
    return true;
  }
  else if constexpr (std::is_same_v<T, double>)
  {
    t = std::stod(value);
    return true;
  }
  return false;
}
#endif
// 运行时判断 C++23增加编译时，即 constexpr
template <typename T>
bool assign(T &t, const std::string &value)
{
  if constexpr (typeid(T) == typeid(int))
  {
    t = std::stoi(value);
    return true;
  }
  else if constexpr (typeid(T) == typeid(std::string))
  {
    t = value;
    return true;
  }
  else if constexpr (typeid(T) == typeid(double))
  {
    t = std::stod(value);
    return true;
  }
  return false;
}
struct User
{
  std::string name;
  int age = 0;
  double height = 0;

  // User &operator=(const PPJson &json)
  // {
  //   assign(name, json.value("name"));
  //   assign(age, json.value("age"));
  //   assign(height, json.value("height"));
  //   return *this;
  // }

  friend std::ostream &operator<<(std::ostream &os, const User &user)
  {
    return os << "name: " << user.name << " age: " << user.age << " height: " << user.height;
  }
};

bool fromJson(const PPJson &json, User &user)
{
  assign(user.name, json.value("name"));
  assign(user.age, json.value("age"));
  assign(user.height, json.value("height"));
  return true;
}
int main(int argc, char *argv[])
{
  std::string strJson = R"({"name": "user", "age": 18, "height": 1.6})";
  // User user = PPJson::parse(strJson);
  if (User user; fromJson(PPJson::parse(strJson), user))
  {
    std::cout << user;
  }
  return 0;
}