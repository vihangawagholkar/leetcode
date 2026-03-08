#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// int main() {
//     int n;
//     cin >> n; // number of elements in the array
//     vector<int> nums(n);
//     for (int i = 0; i < n; i++) {
//         cin >> nums[i];
//     }

//     int target;
//     cin >> target;

//     vector<int> result;
//     for (int i = 0; i < nums.size(); i++) {
//         for (int k = i + 1; k < nums.size(); k++) {
//             if (nums[i] + nums[k] == target) {
//                 result.push_back(i);
//                 result.push_back(k);
//                 break; // stop inner loop after finding a valid pair
//             }
//         }
//         if (!result.empty()) break; // stop outer loop after finding a valid pair
//     }

//     for (int i = 0; i < result.size(); i++) {
//         cout << result[i] << " ";
//     }
//     cout << endl;

//     return 0;
// };

// Hash map solution for better time complexity

int main() {
    int n;
    cin >> n; // number of elements in the array
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cin >> target;

    unordered_map<int, int> numMap; // map to store number and its index
    
    // for(int i=0; i<nums.size(); i++){
    //     numMap[nums[i]] = i;
    // }
    
    for(int i=0; i<nums.size(); i++){
        int complement = target - nums[i];
        if(numMap.find(complement) != numMap.end() && numMap[complement] != i){
            cout<< numMap[complement] <<" "<< i;
            break;}

        numMap[nums[i]] = i;
    }
    
    
    cout << endl;

    return 0;
};