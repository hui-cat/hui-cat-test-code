

> **适用场景**：OJ 中处理字符串输入、回文判断、字符串匹配、大小写转换等。
> **核心头文件**：`#include <string>`（STL string），`#include <cstring>`（C 风格），`#include <cctype>`（字符检测与转换）。

## 一、 C 风格字符串（char 数组）

C 语言没有专门的字符串类型，而是使用以空字符 `\0` 结尾的字符数组。

```cpp
char str[] = "hello"; // 实际存储为: 'h','e','l','l','o','\0'
```

### 1. 常用 C 风格函数（需 `#include <cstring>`）
| 函数 | 功能 | 注意事项 |
| :--- | :--- | :--- |
| `strlen(str)` | 返回字符串长度（不含 `\0`） | 时间复杂度 O(N) |
| `strcpy(dest, src)` | 将 `src` 拷贝到 `dest` | 必须确保 `dest` 空间足够大 |
| `strcat(dest, src)` | 将 `src` 拼接到 `dest` 后面 | 必须确保 `dest` 空间足够大 |
| `strcmp(str1, str2)` | 比较两个字符串 | 返回 0 表示相等，<0 表示 str1 < str2，>0 表示 str1 > str2 |

### 2. 优缺点
*   **优点**：直接操作内存，执行效率极高，与底层系统接口兼容性好。
*   **缺点**：极度容易越界，安全性极差，必须手动管理内存（`malloc`/`free` 或栈分配）。

## 二、 C++ STL `string` 类

`string` 是 C++ 标准库封装好的动态字符串类，自动管理内存，安全且功能强大。

### 1. 初始化与赋值
```cpp
string s1;              // 空字符串
string s2 = "hello";    // 直接赋值
string s3(5, 'a');      // "aaaaa"
string s4(s2);          // 拷贝构造
string s5(s2, 1, 3);    // 从 s2 下标1开始取3个字符 -> "ell"
```

### 2. 核心成员函数
*   **容量**：`size()`, `length()`, `empty()`, `clear()`, `resize(n)`。
*   **访问**：`s[i]`（不检查越界），`s.at(i)`（越界抛出异常），`front()`, `back()`。
*   **修改**：`push_back(c)`, `pop_back()`, `insert(pos, str)`, `erase(pos, len)`, `replace(pos, len, str)`。
*   **查找**：`find(str)` 返回第一次出现的下标，找不到返回 `string::npos`；`rfind(str)` 从后往前找。
*   **截取**：`substr(pos, len)` 返回从 `pos` 开始的 `len` 个字符。
*   **转换**：`.c_str()` 返回 C 风格的 `const char*` 指针。

### 3. 字符串拼接与比较
```cpp
string a = "hello", b = " world";
string c = a + b; // "hello world"
a += "!";         // a 变为 "hello!"

// 比较：按字典序比较 ASCII 码
if (a == b) cout << "相等";
if (a < b)  cout << "a 在 b 前面";
```

### 4. 遍历方式
```cpp
// 下标遍历
for (int i = 0; i < s.size(); i++) cout << s[i];

// 范围 for 循环（C++11）
for (char c : s) cout << c;

// 迭代器遍历
for (auto it = s.begin(); it != s.end(); ++it) cout << *it;
```

### 5. 字符串与数字的转换（C++11 特性）
```cpp
// 字符串转数字
int n = stoi("123");
long long ln = stoll("123456789012");
double d = stod("3.14");

// 数字转字符串
string s = to_string(42); // "42"
```

## 三、 字符检测与转换函数（`<cctype>`）

这些函数用于对单个字符进行判断或修改，是 OJ 字符串题的高频工具。

### 1. 检测函数
| 函数 | 功能 | 返回值 |
| :--- | :--- | :--- |
| `isdigit(c)` | 判断是否为数字 `0-9` | 非零（真）/ 0（假） |
| `isalpha(c)` | 判断是否为字母 `a-z` / `A-Z` | 非零 / 0 |
| `isalnum(c)` | 判断是否为字母或数字 | 非零 / 0 |
| `islower(c)` | 判断是否为小写字母 | 非零 / 0 |
| `isupper(c)` | 判断是否为大写字母 | 非零 / 0 |
| `isspace(c)` | 判断是否为空白字符（空格、`\t`、`\n` 等） | 非零 / 0 |
| `ispunct(c)` | 判断是否为标点符号 | 非零 / 0 |

### 2. 转换函数
*   `tolower(c)`：将大写字母转换为小写（如果不是大写字母，原样返回）。
*   `toupper(c)`：将小写字母转换为大写。

### 3. ⚠️ 参数陷阱：为什么参数是 `unsigned char` 或 `EOF`？
标准库中这些函数的参数类型是 `int`，但**要求传入的值必须能表示为 `unsigned char` 或等于 `EOF`**。

```cpp
char c = 'A';
// ❌ 危险写法：如果 char 是有符号的，且 c 为负数（如汉字、某些扩展ASCII字符），
// 直接传 c 会导致未定义行为（UB）
if (isdigit(c)) { ... }

// ✅ 安全写法：强制转换为 unsigned char
if (isdigit(static_cast<unsigned char>(c))) { ... }
```
在 OJ 中，如果只处理纯英文字符串，直接写 `isdigit(s[i])` 通常也能过，但严谨起见（尤其是在涉及中文或特殊编码时），建议加上 `(unsigned char)` 强制转换。

## 四、 OJ 常见实战技巧

### 1. 回文串判断（双指针 vs 反转法）
```cpp
// 双指针（O(1) 额外空间，推荐）
bool isPalindrome(string s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++; j--;
    }
    return true;
}

// 反转法（O(N) 额外空间，代码简洁）
bool isPalindrome2(string s) {
    string r(s.rbegin(), s.rend());
    return s == r;
}
```

### 2. 字符串大小写转换
```cpp
string s = "Hello World";
for (char &c : s) {
    c = tolower(c); // 全部转小写
}
// s 变为 "hello world"
```

### 3. 字符串查找与替换
```cpp
string s = "hello world";
size_t pos = s.find("world"); // 6
if (pos != string::npos) {
    s.replace(pos, 5, "C++"); // "hello C++"
}
```

### 4. 字符串分割（结合 `stringstream`）
```cpp
string s = "apple,banana,orange";
stringstream ss(s);
string token;
while (getline(ss, token, ',')) {
    cout << token << endl; // 依次输出 apple, banana, orange
}
```

### 5. 字符串去除前导/后置空格
```cpp
string s = "   hello   ";
// 去除前导空格
s.erase(0, s.find_first_not_of(" "));
// 去除后置空格
s.erase(s.find_last_not_of(" ") + 1);
```

## 五、 ⚠️ 避坑指南与性能优化

1.  **`size()` 的无符号陷阱**：
    `string::size()` 返回无符号整数。如果 `s` 为空，`s.size() - 1` 会变成巨大的正数，导致循环越界崩溃。推荐用 `int len = s.size();`。
2.  **频繁拼接字符串**：
    频繁使用 `s = s + "a"` 会创建大量临时对象。建议使用 `s += "a"` 或 `s.append("a")`。
3.  **`c_str()` 的使用**：
    `c_str()` 返回一个指向 `string` 内部数据的指针，**不要试图修改它**，也不要在这个指针被使用期间对原 `string` 进行扩容（因为底层内存可能被重新分配）。
4.  **`find()` 的返回值**：
    `find()` 找不到时返回 `string::npos`（一个极大的无符号数），千万不要写成 `if (s.find(x) == -1)`，必须写成 `if (s.find(x) == string::npos)`。
5.  **`isdigit()` 的参数安全**：
    上文提到的 `(unsigned char)` 强制转换，在处理非 ASCII 字符（如中文 UTF-8 编码）时极其重要，否则可能引发程序崩溃。
6.  **字符串比较的时间复杂度**：
    `s1 == s2` 的时间复杂度是 O(min(len1, len2))，在循环中频繁比较可能会超时，注意优化算法。