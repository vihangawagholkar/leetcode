#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;


double merge(vector<int>& a, vector<int>& b){
    int n = a.size() + b.size();

    vector<int> merged;
    int i = 0, j = 0;

    while(i < a.size() && j < b.size()){
        if(a[i] < b[j]){
            merged.push_back(a[i]);
            i++;
        }
        else{
            merged.push_back(b[j]);
            j++;
        }
        
    }

    
    if(i < a.size()){
        merged.push_back(a[i]);
        i++;
    }

    else{
        merged.push_back(b[j]);
        j++;
    }

    if(n%2 == 0)
        return (merged[n/2 - 1] + merged[n/2]) / 2.0;

    else
        return (double) merged[n/2];
        
}


int solve (vector<int>& A, vector<int>& B, int k, int aStart, int aEnd, int bStart, int bEnd){

    if(aStart > aEnd)
        return B[k - aStart];

    if(bStart > bEnd)
        return A[k - bStart];

    int aIndex = (aStart + aEnd) / 2, bIndex = (bStart + bEnd) / 2;
    int aValue = A[aIndex], bValue = B[bIndex];

    if(aIndex + bIndex < k){
        if(aValue < bValue)
            return solve(A, B, k, aIndex + 1 , aEnd, bStart, bEnd);

        else
            return solve(A, B, k, aStart, aEnd, bIndex + 1, bEnd);
    }

    else
        if(aValue < bValue)
            return solve(A, B, k, aStart, aEnd, bStart, bIndex - 1);

        else
            return solve(A, B, k, aStart, aIndex - 1, bStart, bEnd);

    return 0.0;
}

double binaryMerged(vector<int>& a, vector<int>& b){
    int na = a.size(), nb = b.size();
    int n = na + nb;

    if(n % 2 == 0){
        return (solve(a, b, n/2-1, 0, na - 1, 0, nb - 1) + solve(a, b, n/2, 0, na - 1, 0, nb - 1)) / 2.0;;
    }

    else
        return (double)solve(a, b, n/2, 0, na - 1, 0, nb - 1);

    return 0.0;
}

double binaryMergedOptimized(vector<int>& a, vector<int>& b){
    if(a.size() > b.size()){
        return binaryMergedOptimized(b, a);
    }

    int m = a.size(), n = b.size();
    int left = 0, right = m;

    while(left <= right){
        int partitionA = (left + right)/2;
        int partitionB = (m + n + 1)/2 - partitionA;

        int maxLeftA = (partitionA == 0) ? INT_MIN : a[partitionA - 1];
        int minRightA = (partitionA == m) ? INT_MAX : a[partitionA];
        int maxLeftB = (partitionB == 0) ? INT_MIN : b[partitionB - 1];
        int minRightB = (partitionB == n) ? INT_MAX : b[partitionB];

        if(maxLeftA <= minRightB && maxLeftB <= minRightA){
            if((m+n)%2 == 0){
                return (max(maxLeftA, maxLeftB) + min(minRightA, minRightB))/2.0;
            }

            else
                return (double)(max(maxLeftA, maxLeftB));
        }

        else if(maxLeftA > minRightB){
            right = partitionA - 1;
        }

        else{
            left = partitionA + 1;
        }
    }

    return 0.0;
}

int main(){

    vector<int> a, b;
    string line;

    cout<<"Enter the first array: ";
    getline(cin, line);

    stringstream ss1(line);
    int temp;

    while(ss1 >> temp){
        a.push_back(temp);
    }

    cout<<"First array: ";
    
    for(auto i : a){
        cout<< i <<" ";
    }

    cout<<endl;

    cout<<"Enter the Second array: ";
    getline(cin, line);

    stringstream ss2(line);
    

    while(ss2 >> temp){
        b.push_back(temp);
    }

    cout<<"Second array: ";
    
    for(auto i : b){
        cout<< i <<" ";
    }

    cout<<endl;

    cout<<"Median of the 2 sorted arrays is: ";

    // cout<< merge(a, b);

    // cout<< binaryMerged(a, b);

    cout<<binaryMergedOptimized(a, b);

    return 0;
}