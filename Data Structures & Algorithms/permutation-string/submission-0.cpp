class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       int n1 = s1.length();
       int n2 = s2.length();
       int count1[26] = {0};
       int count2[26] = {0};
       
       // If s1 is longer than s2, a permutation is impossible
       if (n1 > n2) {
           return false;
       }
       
       // Initialize the first window of size n1
       for (int i = 0; i < n1; i++) {
           count1[s1[i] - 'a']++;
           count2[s2[i] - 'a']++;
       }
       
       // Check the first window
       if (isEqual(count1, count2)) {
           return true;
       }
       
       // Slide the window through the rest of s2
       for (int i = n1; i < n2; i++) {
           count2[s2[i] - 'a']++;        // Add new character to the right
           count2[s2[i - n1] - 'a']--;   // Remove old character from the left
           
           if (isEqual(count1, count2)) {
               return true;
           }
       }
       
       return false;
    }

private:
    // Helper function to compare two frequency arrays element by element
    bool isEqual(int count1[], int count2[]) {
        for (int i = 0; i < 26; i++) {
            if (count1[i] != count2[i]) {
                return false;
            }
        }
        return true;
    }
};