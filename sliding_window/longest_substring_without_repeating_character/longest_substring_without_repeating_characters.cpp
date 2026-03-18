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

    // Brute Force


    // for(int i=0; i<s.length(); i++){
    //     for(int j=i; j<s.length(); j++){
    //         if(checkRepetition(i,j,s))
    //             res = max(res, j-i+1);
    //     }
    // }

    

    // Using Hash Map

    // unordered_map <char, int> chars;

    // int i=0,j=0;

    // while(j<s.length()){
    //     char r = s[j];
    //     chars[r]++;

    //     while(chars[r]>1){
    //         char l = s[i];
    //         chars[l]--;
    //         i++;
    //     }

    //     res = max(res, j-i+1);
    //     j++;
    // }

    // Optimized Hash Map solution

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