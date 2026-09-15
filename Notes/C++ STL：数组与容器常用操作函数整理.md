# 📘 C++ STL：数组与容器常用操作函数整理

> **适用场景**：OJ 刷题与日常开发中，对数组（C-Style Array）和 `vector` 容器进行反转、排序、去重、查找、拷贝等操作。
> **核心头文件**：`#include <algorithm>`
> **核心概念**：所有操作区间均为左闭右开 `[first, last)`。

## 一、 元素反转：`reverse()` 与 `reverse_copy()`

### 1. `reverse()`
**功能**：将区间 `[first, last)` 内的元素**原地反转**。
**时间复杂度**：O(N)
**底层原理**：双指针从两端向中间靠拢，逐一交换元素。

```cpp
// 对 vector 反转
vector<int> v = {1, 2, 3, 4, 5};
reverse(v.begin(), v.end()); 
// v 变为: {5, 4, 3, 2, 1}

// 对普通数组反转
int arr[] = {1, 2, 3, 4, 5};
reverse(arr, arr + 5);
// arr 变为: {5, 4, 3, 2, 1}
```

### 2. `reverse_copy()`
**功能**：将区间 `[first, last)` 内的元素**反转后拷贝**到以 `result` 起始的目标区间。**不修改原区间**。
**返回值**：返回目标区间中最后一个被拷贝元素的下一个位置的迭代器。

```cpp
vector<int> src = {1, 2, 3, 4, 5};
vector<int> dest(5); // ⚠️ 必须提前分配足够空间！

reverse_copy(src.begin(), src.end(), dest.begin());
// src 不变，仍为 {1, 2, 3, 4, 5}
// dest 变为 {5, 4, 3, 2, 1}
```

## 二、 排序与去重：`sort()` 与 `unique()`

### 1. `sort()`
**功能**：对区间 `[first, last)` 内元素进行排序（默认升序）。
**时间复杂度**：O(N log N)
**自定义排序**：传入 Lambda 表达式或仿函数。

```cpp
vector<int> v = {5, 2, 8, 1, 9};
// 升序
sort(v.begin(), v.end()); // 1, 2, 5, 8, 9
// 降序
sort(v.begin(), v.end(), greater<int>()); // 9, 8, 5, 2, 1
// 自定义结构体排序
sort(v.begin(), v.end(), [](int a, int b) {
    return a > b; // 降序
});
```

### 2. `unique()`
**功能**：去除区间内**相邻**的重复元素（只保留一个），返回去重后最后一个有效元素的下一个位置的迭代器。
**⚠️ 核心规则**：使用前**必须排序**。
**⚠️ 特性**：`unique` 并不真正删除元素，仅仅是“把不重复的元素移到前面”，容器的 `size()` 不会改变。

```cpp
vector<int> v = {1, 1, 2, 3, 3, 3, 4, 5, 5};
// 必须先排序（此处已排好）
auto it = unique(v.begin(), v.end());
// v 变为: {1, 2, 3, 4, 5, 1, 2, 3, 5} (后四个是残留垃圾)
// it 指向 v[5]（第一个垃圾元素 1）

// 配合 erase 真正删除
v.erase(it, v.end());
// v 变为: {1, 2, 3, 4, 5}，size 变为 5

// 黄金组合缩写（去重唯一写法）：
sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end());
```

## 三、 拷贝与填充：`copy()` 与 `fill()`

### 1. `copy()`
**功能**：将区间 `[first, last)` 的元素拷贝到以 `result` 起始的目标区间。
**返回值**：返回目标区间中最后一个被拷贝元素的下一个位置的迭代器。

```cpp
vector<int> src = {1, 2, 3};
vector<int> dest(3); // 提前分配空间
copy(src.begin(), src.end(), dest.begin());
```

### 2. `fill()`
**功能**：将区间 `[first, last)` 内的所有元素设置为指定值。
**使用场景**：快速重置数组或容器，比循环赋值更简洁。

```cpp
vector<int> v(5);
fill(v.begin(), v.end(), 10); // v 变为 {10, 10, 10, 10, 10}

int arr[5];
fill(arr, arr + 5, 0); // 数组快速清零
```

## 四、 极值与查找：`min_element()`, `max_element()`, `count()`

### 1. `min_element()` / `max_element()`
**功能**：返回区间内最小值/最大值**所在的迭代器**（不是值本身）。
**注意**：返回的是迭代器，取值需解引用 `*`。

```cpp
vector<int> v = {5, 2, 8, 1, 9};
auto it_min = min_element(v.begin(), v.end());
auto it_max = max_element(v.begin(), v.end());

cout << *it_min << " " << *it_max << endl; // 输出 1 9

// 获取下标
int pos = it_min - v.begin(); // pos = 3
```

### 2. `count()`
**功能**：统计区间内指定值出现的次数。
**注意**：时间复杂度为 O(N)。

```cpp
vector<int> v = {1, 2, 2, 3, 2, 4};
int cnt = count(v.begin(), v.end(), 2); // cnt = 3
```

## 五、 二分查找：`lower_bound()` 与 `upper_bound()`

**前置条件**：区间**必须是有序的**（通常先 `sort`）。
**底层原理**：二分查找，时间复杂度 O(log N)。

### 1. `lower_bound()`
**功能**：查找第一个 **大于等于 ( >= )** 目标值的元素位置。
**返回值**：迭代器。

### 2. `upper_bound()`
**功能**：查找第一个 **大于 ( > )** 目标值的元素位置。
**返回值**：迭代器。

```cpp
vector<int> v = {1, 2, 2, 3, 4, 5};
// 查找第一个 >= 2 的位置
auto it1 = lower_bound(v.begin(), v.end(), 2); // 指向下标 1

// 查找第一个 > 2 的位置
auto it2 = upper_bound(v.begin(), v.end(), 2); // 指向下标 3

// 计算元素 2 的个数（区间 [it1, it2) 的长度）
int cnt = it2 - it1; // cnt = 2

// 转换为下标
int index1 = it1 - v.begin(); // index1 = 1
int index2 = it2 - v.begin(); // index2 = 3
```

## 六、 ⚠️ 避坑指南与性能优化

1. **头文件缺失**：以上所有函数均需要引入 `#include <algorithm>`。`reverse` 和 `sort` 不在 `<vector>` 里面，别忘记加。
2. **`reverse_copy` 与 `copy` 的目标空间**：使用这两个函数时，目标容器**必须已经分配了足够的内存**（例如 `vector<int> dest(src.size())`），否则会引发越界写内存，导致程序崩溃。
3. **`unique` 不改变 `size()`**：`unique` 本质是“把不重复的往前挪”，它不负责删除。必须配合 `erase` 使用，否则你会看到数组中残留了一堆垃圾数据。
4. **`min_element` 返回的是迭代器**：新手极易犯错，直接 `int min_val = min_element(...)` 会编译报错。必须写成 `int min_val = *min_element(...)`。
5. **`lower_bound` 的计算**：`lower_bound` 返回迭代器。如果写成 `int pos = lower_bound(...)`，同样编译报错。必须写成 `int pos = lower_bound(...) - v.begin()`。
6. **自定义比较函数的严格弱序**：在 `sort` 中使用 Lambda 时，如果写成 `return a >= b;` 可能会在部分编译器上引发段错误（UB）。必须写成严格的 `<` 或 `>`（`return a > b;`）。