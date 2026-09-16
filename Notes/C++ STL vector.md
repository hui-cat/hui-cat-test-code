# 📘 C++ STL：`vector` 容器与常用算法函数完全指南

> **适用场景**：OJ 刷题与日常开发中，处理一维/二维动态数组，以及配合泛型算法进行排序、去重、查找、交换等操作。
> **核心头文件**：`#include <vector>`（容器），`#include <algorithm>`（算法），`#include <utility>`（`swap` 等）。

## 一、 `vector` 核心概念与初始化

`vector` 是 C++ 标准模板库（STL）中的动态数组。它在堆内存中分配空间，能够自动扩容，并保证元素在内存中的**连续存储**。
*   **优势**：支持随机访问（$O(1)$），尾部插入/删除效率高（均摊 $O(1)$），自动管理内存。
*   **劣势**：中间或头部插入/删除效率低（需要挪动后续所有元素，$O(n)$），扩容时产生性能开销。

### 1. 初始化方式
```cpp
// 1. 默认初始化：空的 vector
vector<int> v1; 

// 2. 指定大小并初始化（默认值为 0）
vector<int> v2(5);        // 包含 5 个元素，均为 0

// 3. 指定大小和初始值
vector<int> v3(5, 10);    // 包含 5 个元素，均为 10

// 4. 列表初始化（C++11 特性）
vector<int> v4 = {1, 2, 3, 4, 5};

// 5. 从数组或其他容器拷贝初始化
int arr[] = {1, 2, 3};
vector<int> v5(arr, arr + 3);

// 6. 二维 vector 初始化
vector<vector<int>> v2d(3, vector<int>(4, 0)); // 3行4列，全为 0
```

## 二、 `vector` 核心成员函数详解

### 1. 容量与大小
*   **`size()`**：返回当前容器中实际存放的**元素个数**。返回类型是 `size_t`（无符号整数）。
*   **`capacity()`**：返回当前容器在不重新分配内存的情况下，**最多能容纳的元素个数**。
    *   *扩容机制*：当 `size == capacity` 时，再插入元素会触发扩容。系统通常会申请一块原容量 **1.5 倍或 2 倍**的新内存，搬移旧数据，再释放旧内存。
*   **`empty()`**：判断容器是否为空，返回 `bool`。比 `size() == 0` 更高效。
*   **`reserve(n)`**：**预分配内存**，将 `capacity` 设为 `n`。避免频繁扩容，提升性能。
*   **`resize(n, val)`**：改变 `size` 为 `n`。变大则用 `val` 填充，变小则截断多余部分。

### 2. 元素访问
*   **`at(index)`**：**带边界检查**的访问，越界抛出 `std::out_of_range` 异常。
*   **`v[index]`**：**不带边界检查**的数组式访问，越界是未定义行为（UB），可能引发崩溃。
*   **`front()`**：返回第一个元素的引用。
*   **`back()`**：返回最后一个元素的引用。**⚠️ 对空 `vector` 调用 `back()` 是未定义行为！**
*   **`data()`**：返回指向底层数组的指针（C++11）。

### 3. 修改操作
*   **`push_back(val)`**：在尾部添加一个元素。**最常用操作**。
*   **`pop_back()`**：删除尾部的一个元素。
*   **`clear()`**：清空所有元素，`size` 变为 0，但 **`capacity` 不变**。
*   **`insert(pos, val)`**：在迭代器 `pos` 位置插入元素（效率低，慎用）。
*   **`erase(pos)`**：删除迭代器 `pos` 位置的元素（效率低，慎用）。

### 4. 迭代器
*   **`begin()`**：返回指向第一个元素的迭代器。
*   **`end()`**：返回指向最后一个元素的下一个位置的迭代器（左闭右开区间 `[begin, end)`）。
*   *注意*：`end()` 不指向任何实际元素，不能解引用 `*end()`。

## 三、 二维动态数组：`new` 与 `vector` 双轨制

### 1. 为什么 `int array[m][n]` 会报错？
C++ 标准（C++11及以后）**不支持变长数组（VLA, Variable Length Array）**。虽然某些编译器作为扩展允许通过编译，但这是一种极其危险的做法。动态开辟内存（堆内存）是标准方案。

### 2. 方法一：使用 `new` 指针（手动内存管理，了解即可）
```cpp
int m = 3, n = 4;
// 第一步：分配行指针
int **array = new int *[m]; 
// 第二步：为每一行分配列内存（关键！）
for (int i = 0; i < m; i++) {
    array[i] = new int[n]; 
}
// 第三步：释放内存（顺序与分配相反）
for (int i = 0; i < m; i++) {
    delete[] array[i]; 
}
delete[] array; 
```
*(💡 缺点：写法繁琐，极易因忘记 `delete[]` 导致内存泄漏，日常刷题被 `vector` 取代。)*

### 3. 方法二：使用 `vector`（⭐ 强烈推荐，OJ 首选）

#### 💡 基础用法：指定行列大小
```cpp
// 创建 m 行 n 列的二维数组，初始值默认全为 0
vector<vector<int>> array(m, vector<int>(n)); 
// 访问和修改：array[y][x] = 1; 
```

#### 🛠️ 进阶用法 1：动态添加行（不预先分配列）
在图论邻接表中，不知道每行多少数据，不需要提前指定列大小。
```cpp
vector<vector<int>> graph(m); // 创建 m 个空容器
graph[0].push_back(10); // 动态增加列
graph[1].push_back(30);
```
*💡 注意：这种“每行列数不同”的数组称为“锯齿数组（Jagged Array）”。*

#### 🛠️ 进阶用法 2：带权图的邻接表
```cpp
vector<vector<pair<int, int>>> adj(n + 1); 
adj[u].push_back({v, w}); // 存边
```

#### ⚠️ 内存结构与性能避坑
*   **不是连续内存**：`vector<vector<int>>` 底层不是一整块连续内存。它是多个独立的 `vector` 组成的，行与行之间的内存不连续，CPU 缓存命中率略低于原生二维数组。
*   **OJ 建议**：对于 **10^5 x 10^5** 这种极其巨大的网格，`vector<vector<int>>` 的内存开销和分配开销会很大，容易导致 MLE。此时应尽量用一维数组模拟二维（例如 `vector<int> arr(m * n)`）。

## 四、 常用泛型算法（STL Algorithms）

> **核心概念**：以下所有操作区间均为左闭右开 `[first, last)`。需要 `#include <algorithm>`。

### 1. 排序与去重：`sort()` 与 `unique()`

**`sort()`**：对区间 `[first, last)` 内元素进行排序（默认升序），时间复杂度 $O(N \log N)$。
```cpp
vector<int> v = {5, 2, 8, 1, 9};
sort(v.begin(), v.end()); // 升序
sort(v.begin(), v.end(), greater<int>()); // 降序
```

**`unique()`**：去除区间内**相邻**的重复元素，返回去重后最后一个有效元素的下一个位置的迭代器。
**⚠️ 核心规则**：使用前**必须排序**。`unique` 不会改变容器的 `size()`。
```cpp
vector<int> v = {1, 1, 2, 3, 3, 3, 4, 5, 5};
auto it = unique(v.begin(), v.end());
// v 变为: {1, 2, 3, 4, 5, 1, 2, 3, 5} (后四个是残留垃圾)
v.erase(it, v.end()); // 真正删除

// 黄金组合缩写（去重唯一写法）：
sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end());
```

### 2. 元素反转：`reverse()` 与 `reverse_copy()`

**`reverse()`**：原地反转区间 `[first, last)` 内的元素。时间复杂度 $O(N)$。
```cpp
vector<int> v = {1, 2, 3, 4, 5};
reverse(v.begin(), v.end()); // v 变为 {5, 4, 3, 2, 1}
```

**`reverse_copy()`**：反转后**拷贝**到以 `result` 起始的目标区间。**不修改原区间**。
```cpp
vector<int> src = {1, 2, 3, 4, 5};
vector<int> dest(5); // ⚠️ 必须提前分配足够空间！
reverse_copy(src.begin(), src.end(), dest.begin());
```

### 3. 拷贝与填充：`copy()` 与 `fill()`

**`copy()`**：将区间元素拷贝到目标区间。
```cpp
vector<int> src = {1, 2, 3};
vector<int> dest(3); // 提前分配空间
copy(src.begin(), src.end(), dest.begin());
```

**`fill()`**：将区间内所有元素设置为指定值。
```cpp
vector<int> v(5);
fill(v.begin(), v.end(), 10); // v 变为 {10, 10, 10, 10, 10}
int arr[5];
fill(arr, arr + 5, 0); // 数组快速清零
```

### 4. 元素交换：`swap()`
**功能**：交换两个对象的值。对于 STL 容器，时间复杂度是 **$O(1)$**（仅交换内部指针，不拷贝实际数据）。
```cpp
int a = 5, b = 10;
swap(a, b); // a=10, b=5

vector<int> v1 = {1, 2, 3};
vector<int> v2 = {4, 5, 6};
swap(v1, v2); // v1={4, 5, 6}, v2={1, 2, 3}
```

**使用场景与性能优势：**
*   **二维数组交换两行**：无需 `for` 循环逐个拷贝，`swap(nums[m], nums[n])` 直接交换底层指针，复杂度 $O(1)$。
*   **清空并释放 `vector` 内存**：`vector<int>().swap(v);` 可以强制释放 `v` 的内存。

### 5. 极值与查找：`min_element()`, `max_element()`, `count()`

**`min_element()` / `max_element()`**：返回区间内最小值/最大值**所在的迭代器**。若有多个极值，返回**第一个**出现的位置。
```cpp
vector<int> v = {5, 2, 8, 1, 9};
auto it_min = min_element(v.begin(), v.end());
cout << *it_min << endl; // 取值需解引用
int pos = it_min - v.begin(); // 获取下标
```

**`count()`**：统计区间内指定值出现的次数。
```cpp
vector<int> v = {1, 2, 2, 3, 2, 4};
int cnt = count(v.begin(), v.end(), 2); // cnt = 3
```

### 6. 二分查找：`lower_bound()` 与 `upper_bound()`
**前置条件**：区间**必须是有序的**（通常先 `sort`）。
*   `lower_bound()`：查找第一个 **大于等于 ( >= )** 目标值的元素位置。
*   `upper_bound()`：查找第一个 **大于 ( > )** 目标值的元素位置。
```cpp
vector<int> v = {1, 2, 2, 3, 4, 5};
auto it1 = lower_bound(v.begin(), v.end(), 2); // 指向下标 1
auto it2 = upper_bound(v.begin(), v.end(), 2); // 指向下标 3
int cnt = it2 - it1; // 计算元素 2 的个数，cnt = 2
int index1 = it1 - v.begin(); // 获取下标
```

## 五、 ⚠️ OJ 避坑指南与性能优化

1.  **`size_t` 的无符号陷阱**：`v.size()` 返回无符号整数。如果 `v` 为空，`v.size() - 1` 会变成一个巨大的正数，导致循环越界崩溃。推荐用 `int len = v.size();` 接收。
2.  **迭代器失效**：当 `vector` 发生**扩容**时，原有的所有迭代器、指针、引用都会失效。在遍历中使用 `push_back` 极易引发崩溃。
3.  **`unique` 不改变 `size()`**：`unique` 本质是“把不重复的往前挪”，必须配合 `erase` 使用。
4.  **`min_element` 与 `lower_bound` 返回值**：它们返回的是**迭代器**，取值需要解引用（`*`）或减去 `v.begin()` 才能得到下标。
5.  **自定义比较函数的严格弱序**：在 `sort` 中使用 Lambda 时，写成 `return a >= b;` 可能引发段错误。必须写成严格的 `<` 或 `>`（`return a > b;`）。
6.  **`swap` 的高效利用**：在二维数组或容器矩阵操作中，交换整行/整列数据务必使用 `swap(v1, v2)` 替换手写 `for` 循环，这是 $O(1)$ 与 $O(N)$ 的本质区别。
7.  **`reverse_copy` 与 `copy` 的目标空间**：目标容器**必须已经分配了足够的内存**，否则引发越界写内存。
8.  **`vector` 提前 `reserve`**：若已知要 `push_back` 一万次，提前 `v.reserve(10000);` 可以避免多次扩容和数据拷贝。