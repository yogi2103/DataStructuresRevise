#include<iostream>
using namespace std;
#include "Trie.h"
int main(){
	Trie t;
	t.insertWord("and");
	t.insertWord("are");
	t.insertWord("dot");
	cout<<t.search("are");
	t.removeword("are");
	cout<<t.search("are");
}
