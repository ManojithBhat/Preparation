# Stone Game 2 
[Problem Link](https://leetcode.com/problems/stone-game-ii/description/?envType=daily-question&envId=2024-08-20)

## Problem desciption 
Alice and Bob continue their games with piles of stones.  There are a number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].  The objective of the game is to end with the most stones. 

Alice and Bob take turns, with Alice starting first.  Initially, M = 1.

On each player's turn, that player can take all the stones in the first X remaining piles, where 1 <= X <= 2M.  Then, we set M = max(M, X).

The game continues until all the stones have been taken.

Assuming Alice and Bob play optimally, return the maximum number of stones Alice can get.

### Example 1:

> **Input:** piles = [2,7,9,4,4]<br>
> **Output:** 10<br>
> **Explanation:**  If Alice takes one pile at the beginning, Bob takes two piles, then Alice takes 2 piles again. Alice can get 2 + 4 + 4 = 10 piles in total. If Alice takes two piles at the beginning, then Bob can take all three piles left. In this case, Alice get 2 + 7 = 9  piles in total. So we return 10 since it's larger. <br>


## constraints
* 1 <= piles.length <= 100
* 1 <= piles[i] <= 104

## Code
```cpp

class Solution {
public:
    
    int n;
    int t[2][101][101]; //t[2][n+1][n+1] - 2*(n+1)*(n+1) ~n^2 * n ~ O(n^3)
    int solveForAlice(vector<int>& piles, int person, int i, int M) {
        
        if(i >= n)
            return 0;
        
        if(t[person][i][M] != -1)
            return t[person][i][M];
        
        int result = (person == 1) ? -1 : INT_MAX;
        
        int stones = 0;
        
        for(int x = 1; x <= min(2*M, n-i); x++) {
            
            stones += piles[i+x-1];
            
            if(person == 1) { //Alice
                result = max(result, stones + solveForAlice(piles, 0, i+x, max(M, x)));
            } else { //Bob
                result = min(result, solveForAlice(piles, 1, i+x, max(M, x)));
            }
            
        }
        
        return t[person][i][M] = result;
        
    }
    
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        
        memset(t, -1, sizeof(t));
        
        return solveForAlice(piles, 1, 0, 1);
    }
};


```

## Intuition
In a two-player game where one player (Alice) tries to maximize her score and the other player (Bob) tries to minimize Alice's score:

* Alice's Goal: Maximize her total number of stones. She wants to collect as many stones as possible.
  

* Bob's Goal: Minimize Alice's total number of stones. He wants to prevent Alice from collecting too many stones.

**The Role of min() and max():**

**Alice (Maximizing):**

When it's Alice's turn, she evaluates all possible moves she can make and chooses the one that gives her the maximum number of stones. This is why we use max() for Alice's moves—to maximize her outcome.

**Bob (Minimizing):**

When it's Bob's turn, his goal isn't just to collect as many stones as possible for himself; rather, it's to make the game as difficult as possible for Alice in her subsequent turns.
To achieve this, Bob evaluates all his possible moves and selects the one that minimizes Alice's potential future gain. This is why we use min() for Bob's moves—to minimize Alice's outcome.

By choosing the move that leaves Alice with the least favorable scenario (i.e., the fewest remaining stones or the least beneficial set of piles), Bob is effectively playing defensively to limit Alice's ability to maximize her score.

## Approach
In "Stone Game II," Alice and Bob are playing a game with piles of stones. They take turns, starting with Alice. On each turn, a player can take X number of piles, where X can be any number between 1 and 2 * M, where M is a value determined by the previous move. After each move, M may increase, depending on the number of piles taken.

Initialization:

The variable n holds the size of the piles vector.
The array t[2][101][101] is used for memoization to store already computed results. t[person][i][M] stores the result of the game starting from index i, with the maximum number of piles that can be taken being 2 * M, and person indicates whose turn it is (1 for Alice, 0 for Bob).
Recursive Function (solveForAlice):

This function computes the maximum stones Alice can collect if it's her turn (person == 1), or the minimum stones Bob can collect if it's his turn (person == 0).
If i >= n, it means there are no more piles to take, so the function returns 0.

If the result for this state has already been computed (t[person][i][M] != -1), the function returns the stored value to avoid redundant computations.
result is initialized to -1 for Alice (indicating she wants to maximize her result) and to INT_MAX for Bob (indicating he wants to minimize his result).
The loop iterates over all possible moves (from taking 1 pile to 2 * M piles), updating the number of stones collected and recursively calculating the best move for the other player.
Alice's Turn:

If it's Alice's turn (person == 1), she tries to maximize her total by choosing the move that gives her the most stones in the current turn plus the best possible outcome for her from the remaining stones (after Bob takes his turn).
Bob's Turn:

If it's Bob's turn (person == 0), he tries to minimize the total number of stones Alice can collect in future turns by choosing the move that leaves Alice with the least favorable outcome.
Return Statement:

The result is stored in the memoization table t and then returned.
Main Function (stoneGameII):

This function initializes the memoization table and calls the recursive function starting with Alice's turn, from index 0, and an initial value of M = 1.

**Why Alice is the Focus**

The problem's objective is to maximize the number of stones Alice can collect. The recursive function is designed to simulate the best strategies for both players, with Alice always aiming to maximize her gain and Bob to minimize Alice's gain. The focus on Alice comes from the fact that the final return value of stoneGameII should be the maximum number of stones Alice can collect if both players play optimally.

**Bob's Condition**

The code minimizes Alice's future gains when it's Bob's turn because Bob’s goal is to minimize Alice’s total. He tries to leave her in a less favorable position, forcing her to collect fewer stones in her subsequent turns. This doesn't mean Bob doesn't take any stones; instead, it means he's trying to leave Alice in the worst possible situation after his move. The strategy behind Bob's move is defensive—to minimize Alice's chances of winning.

## Complexity
- Time complexity: O(N^2)


- Space complexity:
