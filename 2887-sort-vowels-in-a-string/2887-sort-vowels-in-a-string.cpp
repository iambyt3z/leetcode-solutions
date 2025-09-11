class Solution {
public:
    bool isVowel(char ch) {
        return (
            (ch == 'a') || (ch == 'A') ||
            (ch == 'e') || (ch == 'E') ||
            (ch == 'i') || (ch == 'I') ||
            (ch == 'o') || (ch == 'O') ||
            (ch == 'u') || (ch == 'U')
        );
    }

    string sortVowels(string s) {
        string temp = "";

        for(char si: s) {
            if(isVowel(si))
                temp += si;
        }

        sort(temp.begin(), temp.end());
        int tl = temp.size();
        int sl = s.size();
        int j = 0;

        for(int i=0; i<sl; i++) {
            if(isVowel(s[i])) {
                s[i] = temp[j];
                j++;
            }
        }

        return s;
    }
};