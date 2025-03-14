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

## Breakdown of The Code (0/1 Knapsack)

In the **0/1 Knapsack Problem**, we iterate through the **sorted** weight array and check for each weight whether it can fit within the given capacity. If adding the current item does not exceed the knapsack's limit, we update the value at that position using the formula:

```C++
dp[i][w] = max(dp[i−1][w], value[i−1] + dp[i−1][w − weight[i−1]])
```

This means:

- If we **don't take** the item, the value remains the same as `dp[i-1][w]`.
- if we **take** the item, we add its value to `dp[i-1][w - weight[i-1]]` and take the maximum of the two cases.

This ensures that at each step, we optimize the selection without exceeding the weight limit. By filling the `dp` table, the final answer is stored at `dp[N][W]`, representing the maximum value achievable with the given weight capacity.



## Fractional Knapsack Problem

### Problem Statement

Given `N` items, each with a specific **weight** and **value**, and a knapsack with a **maximum weight capacity**, the objective is to **maximize the total value** that can be carried. Unlike the **0/1 Knapsack** problem, where items can only be **fully taken or not taken at all**, here we can take **fractions of an item**.

### Approach

1. **Sort** the items based on their **value-to-weight ratio** in **desending order**.
2. **Iterate** through the sorted list and pick as much of the highest ratio item as possible.
3. If an item **can't be taken fully**, take a **fraction** that fits in the remaining capacity.
4. **Continue** until the knapsack is **full**.