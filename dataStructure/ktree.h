#include <iostream>

template<typename E>
class BinNode{
	public:
		virtual ~BinNode() {
		}
		
		virtual E& element() = 0;
		
		virtual void setElement(const E&) = 0;
		
		virtual BinNode* left() const = 0;
		
		virtual BinNode* right() const = 0;
		
		virtual void setLeft (BinNode* ) = 0;
		
		virtual void setRight (BinNode*) = 0;
		
		virtual bool isLeaf() = 0;
}; 

template <typename Key,typename E>
class BSTNode : public BinNode<E>{
	private:
		Key k;
		E it;
		BSTNode* lc;
		BSTNode* rc;
		
	public:
		BSTNode(){
			lc = rc = NULL;
		}
		
		BSTNode(Key K, E element, BSTNode* l =NULL, BSTNode* r =NULL)
		{
			k = K;
			lc = l;
			rc = r;
			it = element;
		}
		
		~BSTNode(){}
		
		E&  element()
		{
			return it;
		}
		
		void setElement(const E& e)
		{
			it = e;
		}
		
		Key& key(){	return k;
		}
		inline BSTNode* left() const { return lc;}
		
		void setLeft(BinNode<E>* b ){ lc = (BSTNode*)b;
		}
		
		inline BSTNode* right() const { return rc;}
		
		void setRight(BinNode<E>* b ){ rc = (BSTNode*)b;
		}
		
		bool isLeaf() {
			return (lc==NULL && rc==NULL);
		}
		
};
/*
template <typename E>
void preorder(BinNode<E>* root){
	if(root == NULL) return;
	visit(root); 				//perform whatever action desiered
	preorder(root->left());
	preorder(root->right());
}*/
