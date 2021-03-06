
class BSTNode{
private:
	int value;
	BSTNode* left;
	BSTNode* right;
public:
	BSTNode(int value){
		this->value = value;
		left = NULL;
		right = NULL;
	}
	int getValue(){ return this->value; }
	bool add(int value);
	bool search(int value);
	BSTNode* remove(int value, BSTNode* parent);
	int minValue();
};

bool BSTNode::add(int value){
	if(value == this->value){
		return false;
	}else if(value < this->value){
		if(left == NULL){
			left = new BSTNode(value);
			return true;
		}else{
			return left->add(value);
		}
	}else if(value > this->value){
		if(right == NULL){
			right = new BSTNode(value);
			return true;
		}else{
			return right->add(value);
		}
	}
	return false;
}

bool BSTNode::search(int value){
	if(value == this->value){
		return true;
	}else if(value < this->value){
		if(left == NULL){
			return false;
		}else{
			return left->search(value);
		}
	}else if(value > this->value){
		if(right == NULL){
			return false;
		}else{
			return right->search(value);
		}
	}
	return false;
}

BSTNode* BSTNode::remove(int value, BSTNode* parent){
	if(value < this->value){
		if(left != NULL){
			return left->remove(value, this);
		}else{
			return NULL;
		}
	}else if(value > this->value){
		if(right != NULL){
			return right->remove(value, this);
		}else{
			return NULL;
		}
	}else{
		if(left != NULL && right != NULL){
			this->value = right->minValue();
			return right->remove(this->value, this)
		}else if(parent->left == this){
			parent->left = (left != NULL) ? left:right;
			return this;
		}else if(parent->right == this){
			parent->right = (left != NULL) ? left:right;
			return this;
		}
	}
}

int BSTNode::minValue(){
	if(left == NULL){
		return value;
	}else{
		return left->minValue();
	}
}

class BinarySearchTree{
private:
	BSTNode* root;
public:
	BinarySearchTree(){
		root = NULL;
	}
	bool add(int value);
	bool search(int value);
};

bool BinarySearchTree::add(int value){
	if(root == NULL){
		root = new BSTNode(value);
		return true;
	}else{
		return root->add(value);
	}
}

bool BinarySearchTree::search(int value){
	if(root == NULL){
		return false;
	}else{
		return root->search(value);		
	}
}


bool BinarySearchTree::remove(int value){
	if(root == NULL){
		return false;
	}else{
		if(root->getValue() == value){
			BSTNode auxRoot(0);
			auxRoot.setLeftChild(Root);
			BSTNode* removedNode = root->remove(value, &auxRoot);
			root = auxRoot.getLeft();
			if(removedNode != NULL){
				delete removedNode;
				return true;
			}else{
				return false;
			}
		}else{
			BSTNode* removedNode = root->remove(value, NULL);
			if(removedNode != NULL){
				delete removedNode;
				return true;
			}else{
				return false;
			}
		}
	}
}




