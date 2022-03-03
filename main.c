#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define CHAR_TO_INDEX(ch) ((int)ch - (int)'a')

struct TrieNode{
    struct TrieNode *child[26];
    bool endOfWord;
};

struct TrieNode *getNode(){
    struct TrieNode *newNode = NULL;
    newNode = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    if(newNode){
        for(int i=0;i<26;i++){
            newNode -> child[i] = NULL;
        }
        newNode -> endOfWord = false;
    }
    return newNode;
}

void insert(struct TrieNode *root,char *key){
    int len = strlen(key);
    int index;
    struct TrieNode *temp = root;
    for(int i=0;i<len;i++){
        index = CHAR_TO_INDEX(key[i]);
        if(!temp -> child[index]){
            temp -> child[index] = getNode();
        }    
        temp = temp -> child[index];
    }
    temp -> endOfWord = true;
}
            
            
bool search(struct TrieNode *root,char *key){
    int len = strlen(key);
    int index;
    struct TrieNode *temp = root;
    for(int i=0;i<len;i++){
        index = CHAR_TO_INDEX(key[i]);
        if(!temp -> child[index]){     
            return false;
        }
        temp = temp -> child[index];
    }
    return (temp != NULL && temp -> endOfWord);
}


int main(){
    //int num;
    
    char dict[][10]={"edmatrix","welcome","the","a","an","their","an","any","by"};
    
    struct TrieNode *root = getNode();
    for(int i =0;i<10;i++){
        insert(root,dict[i]);
    }
    printf("Enter the word to be searched:\n");
    char *str = (char*)malloc(64*sizeof(char));
    scanf("%s",str);
    if(search(root,str)){
        printf("%s is present in the trie",str);
    }
    else{
        printf("%s is not present in the trie",str);
    }
}


