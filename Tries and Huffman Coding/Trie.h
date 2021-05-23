#include "TrieNode.h"
class Trie{
	TrieNode* root;
	public:
		Trie(){
			root=new TrieNode('\0');
		}
		
		void insertWord(TrieNode* root, string word){
			
			//base case
			if(word.size()==0){
				root->isTerminal=true;
				return; 
			}
			
			//small calculation
			//to find if the word already exists
			int index= word[0]-'a';
			TrieNode* child;
			if(root->children[index]!=NULL){
				child=root->children[index];
			}
			else{
				child= new TrieNode(word[0]);
				root->children[index]=child;
			}
			
			//Recursive call
			insertWord(child,word.substr(1));
		}
		
		void insertWord(string word){
			insertWord(root,word);
		}
		
		bool search(TrieNode* root, string word){
        
        //base case
        if(word.size()==0){
            return root->isTerminal;
        }
        
        int index=word[0]-'a';
        if(root->children[index]==NULL){
            return false;
        }
        return search(root->children[index],word.substr(1));
    }
    
    bool search(string word) {
        // Write your code here
        return search(root,word);
    }
    
    
    void removeword(TrieNode* root, string word){
    	
    		if(word.size()==0){
				root->isTerminal=false;
				return; 
			}
			
			//small calculation 
			TrieNode* child;
			int index=word[0]-'a';
			
			if(root->children[index]!=NULL){
				child=root->children[index];
			}
			
			removeword(child,word.substr(1));
			
			//remove child node if it has no further nodes & terminal is false
			if(child->isTerminal==false){
				for(int i=0;i<26;i++){
					if(child->children[i]!=NULL){
						return;
					}
				}
			}
			delete child;
			root->children[index]=NULL;
	}
    
    void removeword(string word){
    	return removeword(root,word);
	}
    
};
