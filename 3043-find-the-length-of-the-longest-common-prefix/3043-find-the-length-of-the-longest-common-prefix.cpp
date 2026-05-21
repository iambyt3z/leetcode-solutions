class TrieNode {
    public:
        bool endOfWord;
        TrieNode* children[10];

        TrieNode() {
            endOfWord = false;
            for(int i=0; i<10; i++)
                children[i] = nullptr;
        }        
};

class Trie {
    private:
        TrieNode* root;

    public:
        Trie() {
            root = new TrieNode();
        }

        Trie(vector<string> &keys) {
            root = new TrieNode();
            for(string &key: keys)
                this->insert(key);
        }

        void insert(string &key) {
            TrieNode* curr = root;
            for(char ch: key) {
                int ind = ch - '0';
                if(curr->children[ind] == nullptr) {
                    curr->children[ind] = new TrieNode();
                }

                curr = curr->children[ind];
            }

            curr->endOfWord = true;
        }

        int getMaxLengthPrefix(string &key) {
            int res = 0;
            TrieNode* curr = root;
            for(char ch: key) {
                int ind = ch - '0';
                curr = curr->children[ind];

                if(curr == nullptr)
                    break;

                res++;
            }

            return res;
        }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        vector<string> a1, a2;
        for(int num: arr1) a1.push_back(to_string(num));
        for(int num: arr2) a2.push_back(to_string(num));
        Trie* trie = new Trie(a1);

        int res = 0;
        for(string &num: a2) {
            int ri = trie->getMaxLengthPrefix(num);
            res = max(ri, res);
        }

        return res;
    }
};