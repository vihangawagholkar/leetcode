# Longest Substring Without Repeating Characters

## Problem
Given a string `s`, find the **length of the longest substring without repeating characters**.

Example:

Input:

abcabcbb

Output:

3

Explanation:

The longest substring without repeating characters is:

abc

---

# Code

```cpp
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool checkRepetition(int start, int end, string s){

    unordered_set <char> chars;

    for(int i = start; i <= end; i++){
        char c = s[i];
        if(chars.count(c))
            return false;

        chars.insert(c);
    }
    return true;
}

int main(){

    cout<<"Enter a string: ";
    
    string s;

    cin>>s;
    cout<<s<<endl;

    int res = 0;

    unordered_map <char, int> charsSkip;

    for(int i=0,j=0; j<s.length(); j++){
        if(charsSkip[s[j]]>0){
            i = max(i, charsSkip[s[j]]);
        }

        res = max(res, j-i+1);
        charsSkip[s[j]] = j+1;
    }

    cout<<"The max count for the longest substring is : "<<res;

    return 0;
}


⸻

Approaches in This Code

1. Brute Force (commented)

Idea:

Check every possible substring.

for(int i=0; i<s.length(); i++){
    for(int j=i; j<s.length(); j++){
        if(checkRepetition(i,j,s))
            res = max(res, j-i+1);
    }
}

Time Complexity:

O(n³)

Reason:

Generate substring → O(n²)
Check duplicates → O(n)


⸻

2. Sliding Window with Frequency Map (commented)

Uses two pointers:

i → left pointer
j → right pointer

Window:

s[i ... j]

Logic:

unordered_map<char, int> chars;

while(j<s.length()){
    char r = s[j];
    chars[r]++;

    while(chars[r]>1){
        char l = s[i];
        chars[l]--;
        i++;
    }

    res = max(res, j-i+1);
    j++;
}

Time Complexity:

O(n)


⸻

3. Optimized Sliding Window (Active Solution)

This is the best solution.

Instead of shrinking the window slowly, we jump the left pointer directly.

Key idea:

unordered_map<char,int> charsSkip

Stores:

character → last seen index + 1

Main logic:

for(int i=0,j=0; j<s.length(); j++){
    if(charsSkip[s[j]]>0){
        i = max(i, charsSkip[s[j]]);
    }

    res = max(res, j-i+1);
    charsSkip[s[j]] = j+1;
}


⸻

Why j + 1 is Stored

Example:

a seen at index 3
store → 4

Reason:

Default map value = 0

So:

0 → not seen before


⸻

Example Walkthrough

Input:

abba

Steps:

j=0 → "a" → res=1
j=1 → "ab" → res=2
j=2 → duplicate 'b'
i jumps to 2
window = "b"
j=3 → "ba"

Result:

2


⸻

Complexity

Time Complexity:

O(n)

Space Complexity:

O(min(n, charset))


⸻

Concepts Used
	•	Strings
	•	Hash Maps
	•	Sliding Window
	•	Two Pointers

⸻

Key Insight

The substring between i and j always contains unique characters.

If a duplicate appears, we move i to:

lastSeenIndex + 1

instead of shrinking one step at a time.

⸻