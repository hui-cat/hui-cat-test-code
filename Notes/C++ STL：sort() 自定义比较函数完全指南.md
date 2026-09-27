`std::sort()` 是 C++ 算法竞赛中最常用的函数，但它的自定义比较函数（Comparator）也是新手最容易踩坑的地方。

你之前做过“学生成绩排序”，遇到过降序写成升序、`return i.s > j.s` 等问题，所以对这个细节感到模糊是非常正常的。

我为你整理了一份**“sort() 自定义比较函数完全指南”**，方便你彻底吃透这个概念并加入你的笔记库。

# 📘 C++ STL：`std::sort()` 自定义比较函数完全指南

> **核心前提**：`std::sort` 默认是**升序（从小到大）**。一旦遇到结构体、多关键字排序，或者需要降序，就必须自定义比较规则。

## 一、 核心规则：`compare(a, b)` 返回值到底是什么？

这是理解一切的关键。你需要把 `compare(a, b)` 理解为：**“a 是否应该排在 b 的前面？”**

*   **返回 `true`**：表示 **a 必须排在 b 的前面**。
*   **返回 `false`**：表示 **a 不必排在 b 的前面**（即 a 排在 b 的后面）。

让我们用最简单的升序（从小到大）来验证：
```cpp
bool cmp(int a, int b) {
    return a < b; // 如果 a < b，则 a 排在 b 前面，这就是升序！
}
```
现在，如果你想**降序（从大到小）**，只需要把符号反过来：
```cpp
bool cmp(int a, int b) {
    return a > b; // 如果 a > b，则 a 排在 b 前面，这就是降序！
}
```

## 二、 严格弱序（Strict Weak Ordering）：最隐蔽的致命错误

这是 `std::sort` 最容易引发程序**崩溃（段错误 RE）**或**答案错误（WA）**的陷阱。

**核心法则**：比较函数必须满足**严格弱序**。
*   对于任何元素 `a`，`cmp(a, a)` **必须返回 `false`**。
*   如果 `cmp(a, b)` 为 `true`，那么 `cmp(b, a)` **必须为 `false`**（不能互相认为对方应该排在前面）。
*   比较必须具有传递性。如果 `cmp(a, b)` 为 `true` 且 `cmp(b, c)` 为 `true`，则 `cmp(a, c)` 必须为 `true`。

**❌ 致命错误写法（绝对不要写！）**：
```cpp
bool cmp(int a, int b) {
    return a >= b; // ⚠️ 错误！当 a == b 时，返回 true，违反了严格弱序！
}
```
当容器中存在相等的元素时，`sort` 内部的双指针可能会因为 `a >= b` 和 `b >= a` 同时为 `true` 而陷入死循环，或者越界访问内存，导致程序直接崩掉（Runtime Error）。

**✅ 正确写法**：
```cpp
bool cmp(int a, int b) {
    return a > b; // 当相等时，返回 false，满足严格弱序
}
```

## 三、 三种编写比较函数的方式

### 1. 普通函数（最常用，适合 OJ）
写在 `sort` 调用之前。
```cpp
struct Student {
    int score;
    string name;
};

// 必须使用 const 引用，避免拷贝，提升性能
bool compare(const Student& a, const Student& b) {
    if (a.score != b.score) return a.score > b.score; // 成绩降序
    return a.name < b.name;                             // 成绩相同时，姓名升序
}

int main() {
    vector<Student> stu;
    sort(stu.begin(), stu.end(), compare);
}
```

### 2. Lambda 表达式（C++11 特性，最简洁）
如果你只想在某个 `main` 函数里临时用一下，又不想在外面单独写个函数，可以用 Lambda。
```cpp
sort(stu.begin(), stu.end(), [](const Student& a, const Student& b) {
    if (a.score != b.score) return a.score > b.score;
    return a.name < b.name;
});
```
**Lambda 语法拆解**：
*   `[]`：捕获列表（不需要外部变量就留空）。
*   `(const Student& a, const Student& b)`：参数列表。
*   `{ ... }`：函数体。

### 3. 仿函数（Functor，适合工程开发）
通过重载结构体的 `operator()` 来实现，常用于 STL 的 `priority_queue`。
```cpp
struct Cmp {
    bool operator()(const Student& a, const Student& b) const {
        return a.score > b.score; 
    }
};
// 调用：sort(stu.begin(), stu.end(), Cmp());
```

## 四、 多关键字排序的通用模板（必背）

在 OJ 中，经常遇到“主关键字相同，按次关键字排序”的题目。通用模板如下：

```cpp
bool compare(const Type& a, const Type& b) {
    // 第一关键字：降序（>）
    if (a.key1 != b.key1) return a.key1 > b.key1;
    // 第二关键字：升序（<）
    if (a.key2 != b.key2) return a.key2 < b.key2;
    // 第三关键字：降序（>）
    return a.key3 > b.key3;
}
```

## 五、 极端易错点：浮点数排序

如果你按 `double` 排序，千万不要直接写 `return a.score > b.score;`（如果两个数在极小的精度范围内相等，可能会引发随机错误）。
**稳妥做法**：使用 `eps` 容差，或者对于 OJ 题目，如果分数是一位小数，干脆把 `double` 乘 10 变成 `int` 排序，彻底规避精度问题。

## 六、 ⚠️ OJ 避坑速查表

| 错误类型 | 错误写法示例 | 后果 | 正确写法 |
| :--- | :--- | :--- | :--- |
| **方向写反** | `return a.s < b.s;` (想要降序) | WA (答案错误) | `return a.s > b.s;` |
| **严格弱序违规** | `return a.s >= b.s;` | RE (运行崩溃) / WA | `return a.s > b.s;` |
| **参数拷贝开销** | `bool cmp(Student a, Student b)` | TLE (时间超限) | `bool cmp(const Student& a, const Student& b)` |
| **多关键字遗漏** | `return a.s > b.s;` (同分未处理) | WA (答案错误) | `if (a.s != b.s) return a.s > b.s; return a.name < b.name;` |
| **混用 `size_t`** | `for (size_t i = n-1; i >= 0; i--)` | 死循环/越界 | 使用 `int i` |

## 七、 为什么不推荐手写冒泡排序？

`std::sort` 底层使用的是**内省排序（Introsort）**，结合了快排、堆排和插入排序，时间复杂度稳定在 $O(N \log N)$。
而手写冒泡排序的时间复杂度是 $O(N^2)$。
对于 $N = 10^5$ 的数据，`sort` 可能需要 0.01 秒，而冒泡需要 10 秒以上，必然 TLE。

**OJ 口诀**：**“能调库绝不手写，用 sort 必写 cmp，严格弱序记心间，多关键字不能乱。”**

把这份文档加入你的笔记，以后每次写 `sort` 之前扫一眼避坑速查表，绝对能帮你省下大量 WA 的时间！加油！🐳