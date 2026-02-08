#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<queue>
#include<stack>
#include<unordered_map>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char d){
        this->data = d;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        this->isTerminal = false;
    }
};

struct Node {
    int data;
    Node* next;
};

bool checkCircular(Node* head){
    unordered_map<Node*, bool> visited;
    Node* temp = head;

    while(temp!= NULL){
        if(visited.find(temp) != visited.end()){
            visited[temp] = true;
        }
        else{
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void insertWord(TrieNode* root, string word){
    //base case
    if(word.length() == 0){
        root->isTerminal = true;
        return;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;
    //present
    if(root->children[index] != NULL){
        child = root->children[index];
    }
    else{
        //not present
        child = new TrieNode(ch);
        root->children[index] = child;
    }

    //recursion sambhal lega
    insertWord(child, word.substr(1));
}

bool searchWord(TrieNode* root, string str){
    //base case
    if(str.length() == 0){
        return root->isTerminal;
    }

    char ch = str[0];
    int index = ch - 'a';
    TrieNode* child;

    //present
    if(root->children[index] != NULL){
        child = root->children[index];
    }
    else{
        return false;
    }

    //rec call 
    return searchWord(child, str.substr(1));
}

int main(){
    string str = "thiruvananthapuram";
    unordered_map<char, int> freq;

    for(int i=0; i<str.length(); i++){
        char ch = str[i];
        freq[ch]++;
    }

    for(auto i: freq){
        cout << i.first << " : " << i.second << endl; 
    }

    TrieNode* root = new TrieNode('-');
    //root->insertWord("coding");
    insertWord(root, "coding");
    insertWord(root, "codde");
    insertWord(root, "coder");
    cout << "Searching : " << endl;
    if(searchWord(root, "coding")){
        cout << "Present" << endl;
    }
    else{
        cout << "absent" << endl;
    }
    return 0;
}