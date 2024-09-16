#include <iostream>
#include<vector>
using namespace std;
class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool terminal;

public:
    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        terminal = false;
    }
};
class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode('\0');
    }
    void insertWordHelper(TrieNode *root, string word)
    {
        // Base case
        if (word.size() == 0)
        {
            root->terminal = true;
            return;
        }

        // small calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        insertWordHelper(child, word.substr(1));
    }
    void insertword(string word)
    {
        insertWordHelper(root, word);
    }
    bool search(string word)
    {
        // Write your code here
        return helpsearch(root, word);
    }
    bool helpsearch(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            // root->isTerminal = true;
            return true;
        }
        bool check = false;

        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
            check = helpsearch(child, word.substr(1));
            if (check && word.size() == 1)
            {
                if (child->terminal)
                {
                    check = true;
                }
                else
                {
                    return false;
                }
            }
        }
        else
        {
            return false;
        }
        return check;
    }
    void removeWordHelper(TrieNode* root, string word){
        if(word.size()==0){
            root->terminal=false;
            return;
        }
        TrieNode* child;
        int index=word[0]-'a';
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            //root not found
            return;
        }
        removeWordHelper(child,word.substr(1));

        //Removing child node if requuired
        if(child->terminal==false){
            for(int i=0;i<26;i++){
                if(child->children[i] != NULL){
                    return;
                }
            }
            delete child;
            root->children[index]=NULL;
        }
    }
    void removeword(string word){
        removeWordHelper(root,word);
    }

    bool isPalindromePair(vector<string> words){
        for(int i=0;i<words.size();i++){
            this->insertword(reverseWord(words[i]));
        }
    }
    string reverseWord(string word){
        string rev="";
        for(int i=0;i<word.length();i++){
            rev=word[i]+rev;
        }
        return rev;
    }
    bool isPalindromePair(TrieNode* root, vector<string> words){
        if(words.size()==0){
            return false;
        }
        for(int i=0;i<words.size();i++){
            if(istherePair(root, words[i],0)){
                return true;
            }
        }
        return false;
    }
    bool istherePair(TrieNode* root, string word, int startIndex){
        if(word.length()==0){
            return true;
        }
        if(startIndex==word.length()){
            if(root->terminal){
                return true;
            }
            return checkremainingbranches(root,"");
        }
        int index=word[startIndex]-'a';
        TrieNode* child=root->children[index];
        if(child==NULL){
            if(root->terminal){
                return checkwordforPalindrome(word.substr(startIndex));
            }
            return false;
        }
        return istherePair(child,word,startIndex+1);
    }
    bool checkremainingbranches(TrieNode* root, string word){
        if(root->terminal){
            if(checkwordforPalindrome(word)){
                return true;
            }
        }
        for(int i=0;i<26;i++){
            TrieNode* child=root->children[i];
            if(child==NULL){
                continue;
            }
            string fwd=word + child->data;
            if(checkremainingbranches(child,fwd)){
                return true;
            }
        }
        return false;
    }
    bool checkwordforPalindrome(string word){
        int si=0;
        int ei=word.length()-1;
        while(si<ei){
            if(word[si]!=word[ei]){
                return false;
            }
            si++;
            ei--;
        }
        return true;
    }
};
int main()
{

    return 0;
}