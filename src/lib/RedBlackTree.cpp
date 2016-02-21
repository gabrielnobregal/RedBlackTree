#include "RedBlackTree.h"

RedBlackTree::RedBlackTree(){
	this->treeRoot = NULL;
	nil = new Node(-1, BLACK, NULL, NULL, NULL); // Simboliza um nó nulo (Facilita a implementação)
}

void RedBlackTree::rotateLeft(Node *node){
	// Grava ponteiros para não serem sobrescritos
	Node *rightChild = node->right;
	Node *leftRightChild = node->right->left;
	Node *oldFather = node->father;
	
	// Atualiza filho direito de node
	rightChild->left = node;
	rightChild->father = oldFather;
	
	// Atualiza node
	node->father = rightChild;
	node->right = leftRightChild;
	
	// Atualiza filho direito do filho esquerdo de node
	leftRightChild->father = node;
	
	
	if(oldFather != nil){ // Se não for raiz atualiza o pai
					
		if(oldFather->left == node){
			oldFather->left = rightChild;
		}else{
			oldFather->right = rightChild;
		}
		
	}else{
		treeRoot = rightChild;			
	}
	
}

void RedBlackTree::rotateRight(Node *node){
	// Grava ponteiros para não serem sobrescritos
	Node *leftChild = node->left;
	Node *rightLeftChild = node->left->right;
	Node *oldFather = node->father;
		
	// Atualiza filho esquerdo de node
	leftChild->right = node;
	leftChild->father = oldFather;
	
	// Atualiza node
	node->father = leftChild;
	node->left = rightLeftChild;
	
	// Atualiza filho direito do filho esquerdo de node
	rightLeftChild->father = node;
	
	
	if(oldFather != nil){ // Se não for raiz atualiza o pai de node
					
		if(oldFather->left == node){
			oldFather->left = leftChild;
		}else{
			oldFather->right = leftChild;
		}
		
	}else{
		treeRoot = leftChild;			
	}
	
}


string RedBlackTree::internalViewTree(Node *node){
	stringstream buffer;	
	
	if(node == NULL || node == nil)
		return "";

	buffer<<"------------------------------------"<<endl;
	buffer<<"Node:"<<node->value<<"("<<node->color<<")"<<endl;
	
	if(node->father != nil && node->father != NULL)
	buffer<<"FATHER:"<<node->father->value<<endl<<endl;else
	buffer<<"FATHER:NA"<<endl<<endl;
	
	if(node->left != nil && node->left != NULL)
	buffer<<"LEFT:"<<node->left->value<<endl;else
	buffer<<"LEFT: NA"<<endl;

	if(node->right != nil && node->right != NULL)
	buffer<<"RIGHT:"<<node->right->value<<endl;else
	buffer<<"RIGHT: NA"<<endl;
	

	buffer<<internalViewTree(node->left);
	buffer<<internalViewTree(node->right);
	
	return buffer.str(); 
}

string RedBlackTree::viewTree(){
	return internalViewTree(treeRoot);
}


void RedBlackTree::fixUp(Node *node){
	
	
	while(node->father->color == RED){
		Node *grandFather = node->father->father;
		
		if(grandFather->left == node->father){ // O pai de z está a esquerda do avô de z
			Node *uncle = node->father->father->right; // Tio
			
			if(uncle->color == RED){
				
				node->father->color = BLACK;
				uncle->color = BLACK;
				grandFather->color = RED; // Se o pai é vermelho então o avô certamente é preto(se não ja teria infrigido a regra antes)
				node = grandFather; // Continua apartir do avô				
			}else{ // Tio é preto, temos dois casos (esquerda-esquerda ou esquerda-direita)
				if(node->father->right == node){ // Caso esquerda-direita
				
					node = node->father;
		    		//Aplica rotação a esquerda no pai
		 			rotateLeft(node);
				}
				
				node->father->color = BLACK;
				node->father->father->color = RED;
				rotateRight(node->father->father);
			}
			
		}else{ // O pai de z está a direita do avô de z
			Node *uncle = node->father->father->left; // Tio
			
			if(uncle->color == RED){
				
				node->father->color = BLACK;
				uncle->color = BLACK;
				grandFather->color = RED;
			}else{ // Tio é preto, temos dois casos (esquerda-esquerda ou esquerda-direita)
				
				if(node->father->left == node){
					node = node->father;
					rotateRight(node);
				}
				node->father->color = BLACK;
				node->father->father->color = RED;
				rotateLeft(node->father->father);
				
			}
		}		
		
	}
	
	// Colore a raiz com a cor preta
	treeRoot->color = BLACK;
}


void RedBlackTree::internalInsert(Node *node, int value){
	
	if(value <= node->value){
		if(node->left == nil){
			node->left = new Node(value, RED, node, nil, nil);
			fixUp(node->left);
		}else{
			internalInsert(node->left, value);
		}
	}else{
		if(node->right == nil){
			node->right = new Node(value, RED, node, nil, nil);
			fixUp(node->right);
		}else{
			internalInsert(node->right, value);
		}
	}
	
}

void RedBlackTree::insert(int value){	
	if(treeRoot == NULL){
		treeRoot = new Node(value, BLACK, nil, nil, nil); // Nó raiz é sempre preto
	}else{
		internalInsert(treeRoot,  value);	
	}	
}

string RedBlackTree::internalPreOrderedState(Node *node){
	stringstream buffer;
	
	if(node == NULL || node == nil){
		return "()";
	}

	buffer<< "(" << node->value << node->color << ",";
	buffer<< internalPreOrderedState(node->left) << ",";
	buffer<< internalPreOrderedState(node->right) << ")";

	return buffer.str(); 
}

string RedBlackTree::preOrderedState(){	
	return internalPreOrderedState(this->treeRoot);;
}

bool RedBlackTree::remove(int value){
	// Não implementado
	return false;
}

bool RedBlackTree::internalFind(Node *node, int value){

	if(node == NULL || node == nil)
		return false;	
	
	if(value > node->value)
		return internalFind(node->right, value);else
	if(value < node->value)
		return internalFind(node->left, value);else
		return true;

	return false;
}

bool RedBlackTree::find(int value){
	return internalFind(treeRoot, value);
}

string RedBlackTree::internalTraceFind(Node *node, int value){

	if(node == NULL || node == nil){
		return "";
	}
	
	stringstream buffer;
	
	// Adiciona somente virgula após um nó (ignora virgula antes do nó raiz) 
	if(node != treeRoot){
		buffer<<",";
	}

	buffer<< node->value << node->color;
		
	if(value < node->value){
		buffer<<internalTraceFind(node->left, value);
	}else
	if(value > node->value){
		buffer<< internalTraceFind(node->right, value);
	}

	return buffer.str();
}

string RedBlackTree::traceFind(int value){
	return internalTraceFind(treeRoot, value);
}

void RedBlackTree::internalRelease(Node *node){
	if(node == NULL || node == nil)
		return;
	
	internalRelease(node->left);
	internalRelease(node->right);
		
	delete node;
	
}

void RedBlackTree::release(){
	internalRelease(treeRoot);
	treeRoot = NULL;
}

RedBlackTree::~RedBlackTree(){	
	release();
	delete nil;
}
