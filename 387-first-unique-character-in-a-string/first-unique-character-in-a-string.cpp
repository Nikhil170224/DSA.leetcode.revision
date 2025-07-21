// class Solution {
// public:
//     int firstUniqChar(string s) {
//         int i =0; 
//         while(i< s.size()){
//             int j = 0;
//             while(j < s.size()){
//                 if(i != j && s[i]==s[j]){
//                     // i is not answer
//                     break;
//                 }
//                 j++;
//             }
//             // if i is not found duplicate inside second loop 
//             if(j == s.size()) return i;
//             i++;
//         }
//         return -1;
//     }
// };
class Solution {
public:
    int firstUniqChar(string s) {
        int arr[26]={0};
       for(int i = 0; i< s.size(); i++){
          arr[s[i] - 'a'] += 1; 
       }
       for(int i = 0; i< s.size(); i++){
        if(arr[s[i]-'a'] == 1){
            return i;
        }
       }
       return -1;
    }
};