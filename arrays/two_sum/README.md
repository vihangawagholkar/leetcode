# Two Sum

## Problem
Given an array of integers and a target, return indices of two numbers that add up to the target.

## Approaches

### 1. Brute Force
Check every pair.

Time: O(n²)  
Space: O(1)

### 2. Hash Map (Optimal)

Store number → index in a hash map.

For each element:
complement = target - nums[i]

Check if complement exists in the map.

Time: O(n)  
Space: O(n)

## Key Insight
Instead of checking every pair, store numbers you've seen and check if the complement already exists.

## Pattern
Hash Map lookup for complements

## Mistakes I Made
- Forgot to check if indices were the same
- Did two map lookups instead of storing iterator