# N-Queen Problem

## Breakdown of The Code

### 1. Check Check If It's Safe to Place a Queen (`isSafe`)

This function **ensures** that placing a queen at `board[row][col]` doesn't break the rules.
- It checks **all the rows above** the current row (`row`).
- It checks **all column lef** of the current column (`col`).
- It checks **the upper left diagonal**.
- It checks **the upper right diagonal**.

### 2. Solve N-Queen Using Backtracking (NQueen)

This function places the queens row by row recursively.

- **Base Case** → If all `n` queens are placed, **print the board**.
- **Loop Through Columns** → Try placing a queen in every column of the current row.
- **Check Safety** → Use `isSafe()` to see if the position is valid.
- **Recursive calls** → If safe, place the queen and move to the next row.
- **Backtrack** → Remove the queen after exploring that possibility.

## Time Complexity Analysis

The **worst-case** time complexity of the N-Queens problem using backtracking is `O(N!)` because:

1. We place the queen in each row.
2. We check multiple column placement recursively.
3. The number of valid placement decreases as we move down.

This is why **N-Queens is solved efficiently for smaller values of** `N`, but for larger values, optimization techniques like **bit masking** or **branch pruning** are used.