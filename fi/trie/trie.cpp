//
// Students: write your trie implementation below.
//

#include "trie.h"

//----------------------------------------------
// DO NOT MODIFY THE CONSTRUCTOR OR DESTRUCTOR.
//----------------------------------------------

SparseTrie::SparseTrie()
{
    // DO NOT MODIFY.
    // The root node is always present and represents an
    // empty string. It should never be removed until
    // the destructor runs.
    root = new TNode('\0', false);
}

SparseTrie::~SparseTrie()
{
    // LEAVE BLANK. Don't worry about deallocation.
}

void SparseTrie:: insert(std::string key){
	
	inserthelper(key,0,root);

}

void SparseTrie::inserthelper(std::string key, int index, TNode* curr){
	if(index == (int)key.size()){
		curr->terminal=true;
		return;
	}

	TNode*search=curr->children;

	while(search!=nullptr){
		if(search->letter==key[index]){
			return inserthelper(key,index+1,search);
		}
		search=search->next;
	}

	TNode*tem=curr->children;
	curr->children=new TNode(key[index],false,tem);
	return inserthelper(key,index+1,curr->children);
}

bool SparseTrie:: contains(std::string key){
	bool r=containhelper(key,0,root);
	return r;
}

bool SparseTrie::containhelper(std::string key, int index, TNode* curr){
	if(curr==nullptr){
		return false;
	}
	if(index == (int)key.size()){
		return curr->terminal;
	}

	TNode*search=curr->children;

	while(search!=nullptr){
		if(search->letter==key[index]){
			return containhelper(key,index+1,search);
		}
		search=search->next;
	}
	return false;
}

