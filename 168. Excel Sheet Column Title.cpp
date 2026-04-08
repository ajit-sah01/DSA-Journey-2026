#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        
        while (columnNumber > 0) {
            // Shift to 0-indexed to handle the 'Z' (26) case correctly
            columnNumber--; 
            
            // Get the remainder (0-25)
            int remainder = columnNumber % 26;
            
            // Convert remainder to character ('A' + remainder)
            result += (char)('A' + remainder);
            
            // Move to the next "digit"
            columnNumber /= 26;
        }
        
        // The characters were added from right to left, so reverse the string
        reverse(result.begin(), result.end());
        
        return result;
    }
};