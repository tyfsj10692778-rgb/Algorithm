
## 语法
###  如何调用
``` cpp

#include<map>
#include<unordered_map>

map<key,value> name; // 有序映射：底层红黑树，查找/插入单次 O(log n)
unordered_map<key,value> name; // 无序映射：底层哈希表，查找/插入平均 O(1)
```

**注意事项**
 1. key -> value
 
 2. map底层是一棵==平衡二叉树==。
 
	 每次查找、插入或删除，都相当于在树上走了一条从根节点到叶子节点的路径。
	
	 树的高度是 $\log_2 n$。所以，`map` 的单次查找时间复杂度是 **$O(\log n)$**。
	 
	 $O(n \log n)$ 是排序的复杂度。
 
 3. unordered_map是哈希表，无序，查找平均O(1)
 
 4. map和unordered_map都不可以加(n)：原因是内存不连续
 
 5. 不存在map[i]，但你访问了map[i]不报错。
	 
	 ==因为会先开辟一个内存，再让map[i]为0。==
	 
	 因此想要检查map中某个key x 由于没有对应的 value：
	 
	 map.count(x) || map.find(x)
	 
		 count(x) 和 find(x) 的区别：
		 
		 count(x) 只告诉你map里x这个key 有没有对应key。
		 
		 也就是说只返回一个true or false
		
		 而 find (x) 还把迭代器的地址返回给你了。
		 
		 你可以用一个变量接收这个地址。



# 应用

### 例题1 ： 寄包柜（洛谷P3613）

[P3613 【深基15.例2】寄包柜 - 洛谷](https://www.luogu.com.cn/problem/P3613)
 ```cpp
 
map<int, map<int, int>> name; 

name[i][j] = k;
 ```
 
要点：
1. 用name[key]的方式访问value

2. 用嵌套map模拟二阶数组，i 和 j 都是 key, i -> j - > value

3. 还要有一种对容器的敏感。
	这题有个特征：有很多个容器，并且每一个容器里都存了很多值。
	要先找到快递柜，然后找到格子编号，才能找到物品。
	这就有一个map的关系。

拓展：我们可以用pair一步到位绑定。
```cpp
map <pair<int,int>, int> locker;

locker[{i, j}] = k;

if (locker.count({i, j})) cout << locker[{i , j}];
```
### 例题2 ： 副本（牛客周赛 134529）

[B-小红的冷门副本_牛客周赛 Round 143](https://ac.nowcoder.com/acm/contest/134529/B)
``` cpp
unordered_map<long long, long long> cnt;
	long long k;
    cin >> k;
    cnt[k] ++;
    
     for(const auto& [c,t] : cnt)
    {
        visited ++;
        if (t <= x) less ++;
    }
```

要点：
1. 依然是map[i]的自动开辟内存问题

2. map 的 key 和 value 可以一起遍历，真的方便

3. 你发现了吗？其实我们用的是unordered__map，原因已经强调过很多次了

### 例题3 ： 定一议一，数对匹配
[P1102 A-B 数对 - 洛谷](https://www.luogu.com.cn/problem/P1102#ide)
```cpp
vector<long long> a(n);
unordered_map<long long,long long> cnt;
cin >> a[i];  
cnt[a[i]] ++;
if (cnt.count(target_A)) count += (long long)cnt[target_A]; // 保证加的过程不会爆int
```

要点：
1. 对内存中不存在的map[i]不会报错，先开辟一块内存，初始化为0，再做操作。

2. map.count(x) : 查询map中是否存在 值为 x 的 value

3. 本题数据量大，查询时用平均效率O(1)的unordered_map 效果更好


