#include "Node.h"

Node::Node(int value, char color, Node *father, Node *left, Node *right){
	this->value = value;
	this->color = color;
	this->father = father;
	this->left = left;
	this->right = right;		
}
