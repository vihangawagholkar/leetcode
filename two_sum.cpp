// #include <iostream>
// #include <vector>

// using namespace std;

// int main(){
//         vector <int> nums;
//         int i;
//         while(cin>>i){
//             nums.push_back(i);
//         }
//         int target;
//         cin>> target;
//         vector <int> result;
//         for(int i=0; i<nums.size(); i++){
//             for(int k=i+1; k<nums.size(); k++){
//                 if(target == nums[i] + nums[k]){
//                     result.push_back(i);
//                     result.push_back(k);}
//             }
//         }

//         for(int i=0; i<result.size(); i++){
//             cout<<result[i]<<" ";
//         }a
    
//     return 0;
    
// }

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n; // number of elements in the array
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cin >> target;

    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
        for (int k = i + 1; k < nums.size(); k++) {
            if (nums[i] + nums[k] == target) {
                result.push_back(i);
                result.push_back(k);
                break; // stop inner loop after finding a valid pair
            }
        }
        if (!result.empty()) break; // stop outer loop after finding a valid pair
    }

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
};