# Sieve of Eratosthenes

[Problem Link](https://www.geeksforgeeks.org/problems/sieve-of-eratosthenes5242/1)

## Problem desciption 
Given a number N, calculate the prime numbers up to N using Sieve of Eratosthenes.  

### Example 1:

**Input:**
N = 10<br>
**Output:**
2 3 5 7<br>

**Explanation:**
Prime numbers less than equal to N 
are 2 3 5 and 7.<br>

## constraints
* 1<= N <= 104

## Code
```cpp
class Solution
{
public:
    vector<int> sieveOfEratosthenes(int N)
    {
        vector<int> arr(N+1,1);
        
        for(int i = 2;i*i<=N;i++){
            
            if(arr[i] == 1){
                for(int j = i*i ; j<=N;j+=i){
                    arr[j] = 0;
                }
            }
        }
        vector<int> prime;
        for(int i = 2;i<=N;i++){
            if(arr[i] == 1) prime.push_back(i);
        }
        return prime;
    }
};
```

## Intuition
The normal way of finding the prime number takes time complexity of ```O(n sqrt(n))``` and it is time consuming, so employ this procedure.

The **Sieve of Eratosthenes** is based on the idea that any non-prime number can be written as a product of smaller prime numbers. The goal is to systematically eliminate the multiples of each prime number, starting from the smallest, to leave only the prime numbers.

- You start by assuming every number is prime.
- Then, you systematically "sieve out" (eliminate) the multiples of each prime, starting from the smallest (2). 
- By the time you finish eliminating the multiples of all primes up to \(\sqrt{N}\), the remaining numbers are primes.

### Approach:

1. **Create a List**: Begin with a list of numbers from 2 to \(N\), assuming all of them are prime.

2. **Eliminate Non-Primes**: Start with the smallest prime (2) and eliminate all of its multiples because they cannot be prime (since they are divisible by 2).

3. **Move to the Next Prime**: After eliminating the multiples of 2, move to the next unmarked number (which is 3, the next prime), and repeat the process by eliminating all multiples of 3.

4. **Continue**: Repeat the process for all numbers up to \(\sqrt{N}\), since any composite number greater than \(\sqrt{N}\) will already have been marked by its smaller prime factors.

5. **Collect Primes**: After marking all non-prime numbers, the numbers that remain unmarked are the prime numbers up to \(N\).

### Why it works:
The sieve works efficiently because each non-prime is marked exactly once, as the multiple of its smallest prime factor. By the time you finish, all composite numbers have been "sieved out," leaving only primes.




## Complexity
- Time complexity: O(Nlog(log(N))) 


- Space complexity: O(N)
