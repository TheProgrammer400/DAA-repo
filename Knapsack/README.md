# Knapsack Problem

## 0/1 Knapsack Problem Statement

You are given `N` items, where each item has:
- A **weight** `weight[i]`
- A **value** `value[i]`

You also have a **Knapsack** with a given maximum weight capacity **W**.

Your task is to determine the **max value** you can obtain by selecting items, **without exceeding** the knapsack's weight limit.

### Constraints:

- Each item **can either be taken or not** (0/1 choice).
- You can't take **fraction** of an item.
- You can only take any item **once**.

### Input Format:

- An integer N (number of items).
- An integer W (max weight of the knapsack).
- Two arrays of size **N**:
    - `weight[]` (weights of each item).
    - `value[]` (value of each item).

### Output Format:

- An integer representing the **max total value** that can be obtained.

### Example:

**Input**:

```
N = 4  
W = 5  
weight[] = {2, 3, 4, 5}  
value[] = {3, 4, 5, 6}  
```

**Output**:

```
7
```

### Explanation:
 
- Take items with weights **2 and 3** (values **3 + 4 = 7**).
- Can't take item with weight **4 or 5** as it exceeds the limit.
- **Max value** that can be obtained = **7**.