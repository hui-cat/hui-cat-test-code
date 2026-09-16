
> **适用场景**：OJ 刷题与日常开发中，对数组（C-Style Array）和 `vector` 容器进行反转、排序、去重、查找、拷贝等操作。
> **核心头文件**：`#include <algorithm>`（`swap` 在 C++11 后位于 `<utility>`，但包含 `<algorithm>` 亦可使用）
> **核心概念**：所有操作区间均为左闭右开 `[first, last)`。

## 一、 元素反转：`reverse()` 与 `reverse_copy()`

### 1. `reverse()`
**功能**：将区间 `[first, last)` 内的元素**原地反转**。
**时间复杂度**：$O(N)$
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
**时间复杂度**：$O(N \log N)$
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

## 四、 元素交换：`swap()`

### 1. 基础用法
**功能**：交换两个对象（可以是基本变量、数组元素、STL 容器）的值。
**时间复杂度**：
*   对于基本数据类型（`int`, `double` 等）：$O(1)$。
*   对于 STL 容器（`vector`, `string`, `map` 等）：**$O(1)$**（仅交换内部的指针/控制块，不拷贝实际数据）。

```cpp
int a = 5, b = 10;
swap(a, b); // a=10, b=5

vector<int> v1 = {1, 2, 3};
vector<int> v2 = {4, 5, 6};
swap(v1, v2); // v1={4, 5, 6}, v2={1, 2, 3}
// 也可以写成 v1.swap(v2);
```

### 2. 使用场景与性能优势
**（1）二维数组交换两行（高频考点）**
在处理矩阵或二维 `vector` 时，交换两行数据如果使用 `for` 循环逐个拷贝，复杂度是 $O(列数)$。使用 `swap` 直接交换两个 `vector` 对象，复杂度仅为 **$O(1)$**。

```cpp
vector<vector<int>> nums(5, vector<int>(5));
int m = 1, n = 3;

// ❌ 慢：需要拷贝 5 次数据
// for(int i = 0; i < 5; i++) swap(nums[m][i], nums[n][i]);

// ✅ 快：O(1) 复杂度，直接交换两行的底层指针
swap(nums[m], nums[n]);
```

**（2）清空并释放 `vector` 内存**
`v.clear()` 只是将 `size` 设为 0，`capacity` 并没有释放。使用 `swap` 可以强制释放内存。
```cpp
vector<int> v(1000000, 1); 
// ... 使用完毕，想彻底释放内存 ...
vector<int>().swap(v); // 使用一个临时空 vector 与 v 交换，v 的内存被释放
```

### 3. ⚠️ 避坑指南
1.  **迭代器失效**：当使用 `swap` 交换两个 STL 容器时，原容器对应的所有迭代器、指针和引用**不会失效**（因为它们只是换到了另一个容器对象里），但它们指向的元素已经不属于原来的那个容器变量了，逻辑上极容易出错。
2.  **C++11 的保证**：C++11 之前，对 `vector` 使用 `std::swap` 不能保证是 $O(1)$。C++11 标准出台后，STL 容器保证 `swap` 是 $O(1)$ 且不会抛出异常。在 OJ 中可放心使用。
3.  **自交换安全**：`v.swap(v)` 或 `swap(v, v)` 是安全的，不会引发问题。
4.  **`std::swap` vs 成员函数**：推荐使用 `std::swap(v1, v2)` 的写法，它在泛型编程中兼容性最好。如果 `v1` 和 `v2` 类型不同（比如 `vector<int>` 和 `vector<long long>`），则无法直接 `swap`，必须先统一类型。

## 五、 极值与查找：`min_element()`, `max_element()`, `count()`

### 1. `min_element()` / `max_element()`
**功能**：返回区间内最小值/最大值**所在的迭代器**（不是值本身）。
**注意**：返回的是迭代器，取值需解引用 `*`。若存在多个极值，返回**第一个**出现的位置。

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
**时间复杂度**：$O(N)$。

```cpp
vector<int> v = {1, 2, 2, 3, 2, 4};
int cnt = count(v.begin(), v.end(), 2); // cnt = 3
```

## 六、 二分查找：`lower_bound()` 与 `upper_bound()`

**前置条件**：区间**必须是有序的**（通常先 `sort`）。
**底层原理**：二分查找，时间复杂度 $O(\log N)$。

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

## 七、 ⚠️ 避坑指南与性能优化

1. **头文件缺失**：以上所有函数均需要引入 `#include <algorithm>`。`swap` 虽在 `<utility>`，但包含 `<algorithm>` 亦可使用。
2. **`reverse_copy` 与 `copy` 的目标空间**：使用这两个函数时，目标容器**必须已经分配了足够的内存**（例如 `vector<int> dest(src.size())`），否则会引发越界写内存，导致程序崩溃。
3. **`unique` 不改变 `size()`**：`unique` 本质是“把不重复的往前挪”，它不负责删除。必须配合 `erase` 使用，否则你会看到数组中残留了一堆垃圾数据。
4. **`min_element` 返回的是迭代器**：新手极易犯错，直接 `int min_val = min_element(...)` 会编译报错。必须写成 `int min_val = *min_element(...)`。
5. **`lower_bound` 的计算**：`lower_bound` 返回迭代器。如果写成 `int pos = lower_bound(...)`，同样编译报错。必须写成 `int pos = lower_bound(...) - v.begin()`。
6. **自定义比较函数的严格弱序**：在 `sort` 中使用 Lambda 时，如果写成 `return a >= b;` 可能会在部分编译器上引发段错误（UB）。必须写成严格的 `<` 或 `>`（`return a > b;`）。
7. **`swap` 的高效利用**：在二维数组或容器矩阵操作中，交换整行/整列数据务必使用 `swap(v1, v2)` 替换手写 `for` 循环。这是 O(1) 与 O(N) 的本质区别。