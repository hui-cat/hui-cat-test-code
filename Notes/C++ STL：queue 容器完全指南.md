

> **核心概念**：队列（Queue）是一种**先进先出（FIFO, First In First Out）**的数据结构。类似于日常生活中的“排队买奶茶”，先来的人先买到，后来的人排在队尾。
> **头文件**：`#include <queue>`
> **底层结构**：默认基于 `deque`（双端队列）实现。

## 一、 核心成员函数

`queue` 的操作和 `stack` 非常相似，但访问端从“一端”变成了“两端”：

| 函数 | 功能 | 时间复杂度 | 注意事项 |
| :--- | :--- | :--- | :--- |
| `push(x)` | 将元素 `x` 放入**队尾** | $O(1)$ | 无返回值 |
| `pop()` | 弹出**队头**元素 | $O(1)$ | **不返回元素值**，只是删除 |
| `front()` | 获取**队头**元素的引用 | $O(1)$ | 必须是**非空队列** |
| `back()` | 获取**队尾**元素的引用 | $O(1)$ | 必须是**非空队列** |
| `empty()` | 判断队列是否为空 | $O(1)$ | 返回 `bool` |
| `size()` | 返回队列中元素个数 | $O(1)$ | 返回 `size_t`（无符号整数） |

## 二、 基础用法示例

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    
    // 1. 入队（从队尾添加）
    q.push(10);
    q.push(20);
    q.push(30); // 此时队列：10(队头) -> 20 -> 30(队尾)
    
    // 2. 获取大小
    cout << "队列大小: " << q.size() << endl; // 输出 3
    
    // 3. 访问队头和队尾（必须先判空！）
    if (!q.empty()) {
        cout << "队头元素: " << q.front() << endl; // 输出 10
        cout << "队尾元素: " << q.back() << endl;  // 输出 30
    }
    
    // 4. 出队（从队头弹出）
    q.pop(); // 弹出 10，此时队头变成 20
    cout << "弹出后队头: " << q.front() << endl; // 输出 20
    
    // 5. 清空队列
    while (!q.empty()) {
        q.pop();
    }
    cout << "队列是否为空: " << (q.empty() ? "是" : "否") << endl; // 输出 是
    
    return 0;
}
```

## 三、 重要特性与限制（与 `stack` 如出一辙）

1. **没有迭代器（Iterator）**：
   无法使用范围 for 循环（`for(auto x : q)`），也无法使用 `sort`、`reverse` 等 STL 算法。想要遍历队列，只能不断 `front()` 和 `pop()`，但这会清空队列。
2. **不支持随机访问**：
   不能使用 `q[i]` 访问元素。
3. **没有 `clear()` 方法**：
   清空队列只能循环 `pop()`，或者直接重新赋值 `q = queue<int>();`。
4. **没有 `top()` 方法**：
   这是新手最容易混的点。`stack` 用 `top()` 取栈顶；而 `queue` **没有** `top()`，只能用 `front()` 取队头，`back()` 取队尾。

## 四、 OJ 实战典型场景

### 场景 1：广度优先搜索（BFS） —— 高频核心
*   **思路**：BFS 是队列最经典的应用。从起点开始，将相邻节点放入队列，然后不断从队头取出节点进行扩展，以此实现“层序遍历”。
*   **关键代码骨架**：
    ```cpp
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        // 处理当前节点 cur
        for (int next : neighbors) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    ```

### 场景 2：模拟任务调度（如银行排队、打印机任务）
*   **思路**：按照时间顺序处理任务，`push` 新到达的任务，`pop` 处理完的任务。

### 场景 3：单调队列（求滑动窗口最大值）
*   **思路**：利用双端队列（`deque`）维护一个单调递减的下标序列，队头永远是当前窗口的最大值。

## 五、 ⚠️ 避坑指南（血泪经验）

1. **空队列调用 `front()`、`back()` 或 `pop()` 会导致段错误（RE）**：
   这是最致命的错误。**任何访问或弹出操作前，必须加 `if (!q.empty())` 判断！**
2. **`pop()` 不返回值**：
   必须先 `q.front()` 取值，再 `q.pop()` 删除。不能写 `cout << q.pop();`。
3. **勿混淆 `stack` 和 `queue` 的接口**：
   *   `stack`：`top()`。
   *   `queue`：`front()` 和 `back()`。
   *   在 OJ 中写错接口名会直接编译报错。
4. **`size()` 的无符号陷阱**：
   不要写 `for (int i = 0; i <= q.size() - 1; i++)`，当队列为空时 `0 - 1` 会导致死循环。老老实实用 `while (!q.empty())`。

## 六、 进阶：优先队列 `priority_queue`（高频考点）

如果你需要“每次取出队列中**优先级最高**（通常是最小或最大）的元素”，而不是按插入顺序，你需要使用 `priority_queue`。它的头文件同样是 `<queue>`。

```cpp
// 默认是大根堆（最大值先出队）
priority_queue<int> maxHeap; 
maxHeap.push(3); maxHeap.push(1); maxHeap.push(5);
cout << maxHeap.top(); // 输出 5

// 小根堆（最小值先出队），需要指定比较器
priority_queue<int, vector<int>, greater<int>> minHeap;
minHeap.push(3); minHeap.push(1); minHeap.push(5);
cout << minHeap.top(); // 输出 1
```
*   `priority_queue` 访问顶端用 **`top()`**（和 `stack` 一样），不是 `front()`。
*   底层通过**堆（Heap）**实现，`push` 和 `pop` 的时间复杂度是 $O(\log N)$，比普通队列的 $O(1)$ 略慢，但在需要动态维护极值的场景中极其强大。

把这份文档和 `stack` 的文档放在一起对比记忆，理解 LIFO（后进先出）与 FIFO（先进先出）的区别。接下来在 OJ 上遇到 BFS 或者括号匹配的变体，你就能迅速在大脑中调取对应的工具了。加油！🐳