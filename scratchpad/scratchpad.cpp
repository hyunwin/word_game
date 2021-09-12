#include <iostream>
#include <myLib.h>
#include <unordered_map>


// // int printIntersection(std::vector<std::string> dictionary, std::vector<std::string> possible, int m, int n) 
// // { 
// //   int i = 0, j = 0; 
// //   while (i < m && j < n) 
// //   { 
// //     if (dictionary[i] < possible[j]) 
// //        i++; 
// //     else if (possible[j] < dictionary[i]) 
// //        j++; 
// //     else /* if arr1[i] == arr2[j] */
// //     { 
// //        std::cout << possible[j] << " "; 
// //        i++; 
// //        j++; 
// //     } 
// //   } 
// // } 

int main(){
    std::unordered_map<std::string, bool> hashy;
    std::vector<std::string> dictionary = readWordsFile("misc/english.txt");

    for (int i = 0; i < dictionary.size(); i++){
        hashy.insert({dictionary[i], true});
    }
    
    std::vector<std::string> possible = getAllPossibleSubstrings("MIXMIXMIX");

    for (int j = 0; j < possible.size(); j++){
        auto pos = hashy.find(possible[j]);

        if (pos == hashy.end()){
        std::cout << possible[j] + "Not Found" << std::endl;
    }
    else{
        std::cout << possible[j] + "Found" << std::endl;
        }
    }
    
    
    	// std::vector<std::string> dictionary;
	
	// // std::unordered_map<std::string, bool> stringHashmap;

	// dictionary = readWordsFile("misc/english.txt");

    // for (int i = 0; i < dictionary.size(); i++){
    //     stringHashmap.insert({dictionary[i], 1});
    // }
        
    // auto pos = stringHashmap.find("hello");

    // if (pos == stringHashmap.end()){
    //     std::cout << "Not Found..." << std::endl;
    // }
    // else{
    //     std::cout << "Found..." << std::endl;
	// }
	
    // std::string answer;

//     std::string word = "MIX";

//     std::vector<std::string> possible = getAllPossibleSubstrings(word);

//     // for (int i = 0; i < possible.size(); i++){
//     //     if (checkWord(possible[i])["valid"] == true){
//     //          std::cout << possible[i] << std::endl;
//     //     }
//     //     else {
//     //         std::cout << possible[i] + " wrong" << std::endl;
//     //     }
//     // }
    
//     for (int i = 0; i < possible.size(); i++) {
//        if (checkWord(possible[i])["valid"] == true){
//           std::cout << possible[i] + " O" << std::endl;
//        }
//        else {
//            std::cout << possible[i] + " X" << std::endl;       
//         }
//     }
// 	return 0;
// }

// void printRepeating(int arr[], int size) { 
// int i; 
// std::cout << "The repeating elements are:" << std::endl; 
// for (i = 0; i < size; i++) { 
//     if (arr[abs(arr[i])] >= 0) 
//     arr[abs(arr[i])] = -arr[abs(arr[i])]; 
//     else
//     std::cout << abs(arr[i]) << " "; 
// } 
// } 
  
// // Driver Code 
// int main() 
// { 
//     std::vector<std::string> dictionary = readWordsFile("misc/english.txt");
//     std::vector<std::string> possible = getAllPossibleSubstrings("MIX");
//     int arr_size = sizeof(dictionary)/sizeof(possible); 
//     printRepeating(possible, arr_size); 
    return 0; 
} 
