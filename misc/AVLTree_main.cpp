
#include <iostream>
#include <string>

using namespace std;

struct tree {
	string tree_name;
	struct node *tree_root = NULL;
};


struct node {

	int height = 1;
	unsigned int ID;
	string name;
	struct node *parent = NULL;
	struct node *right_child = NULL;
	struct node *left_child = NULL;
};

int search_node () {

}

int LL_rotation (struct node *nodeA, struct node *nodeB) {
	//first we search if the parent node is either a right or left child
	bool rc;
	if (nodeA->parent) {
		if (nodeA == ((nodeA->parent)->right_child)) {
			rc = true;
		} else {
			rc = false;
		}

		//now add the new node as a child of A former parent
		if (rc) {
			(nodeA->parent)->right_child = nodeB;
		} else {
			(nodeA->parent)->left_child = nodeB;
		}
	}

	//then we proceed to calculate the left rotation:

	if (nodeA->parent) {
		nodeB->parent = nodeA->parent;
	} else {
		nodeB->parent = NULL;
	}


	if (nodeA->parent){
		if (rc) {
			(nodeA->parent)->right_child = nodeB;
		} else {
			(nodeA->parent)->left_child = nodeB;
		}
	}
	nodeA->parent = nodeB;

	//if B node has a right child, it must be relocated:

	if (nodeB->right_child) {
		(nodeB->right_child)->parent = nodeA;
		nodeA->left_child = nodeB->right_child;
	} else {
		nodeA->left_child = NULL;
	}

	//finally we connect the newly located node to its new child

	nodeB->right_child = nodeA;


	//now we need to update the height number of the affected nodes and their parents
	
	//%%%%%% HEIGHT UPDATE %%%%%%

	struct node *tmppointer = nodeA;

	int RC_height;
	int LC_height;

	while (tmppointer) {

		//first we need to get the height of their children
		(tmppointer->right_child)? RC_height = (tmppointer->right_child)->height : RC_height = 0; 
		(tmppointer->left_child)? LC_height = (tmppointer->left_child)->height : LC_height = 0; 

		//finally we assign the value to the node:
		cout << "RC_height" << RC_height << endl; 
		cout << "LC_height" << LC_height << endl; 		

		(RC_height >= LC_height)? tmppointer->height = RC_height +1 : tmppointer->height = LC_height+1;

		//switches to the next level in the following iteration:

		tmppointer = tmppointer->parent;
	}

	return 0;
}


int RR_rotation (struct node *nodeA, struct node *nodeB) {
	//first we search if the parent node is either a right or left child
	bool rc;
	if (nodeA->parent) {
		if (nodeA == ((nodeA->parent)->right_child)) {
			rc = true;
		} else {
			rc = false;
		}

		//now add the new node as a child of A former parent
		if (rc) {
			(nodeA->parent)->right_child = nodeB;
		} else {
			(nodeA->parent)->left_child = nodeB;
		}
	}

	//then we proceed to calculate the right rotation:

	if (nodeA->parent) {
		nodeB->parent = nodeA->parent;
	} else {
		nodeB->parent = NULL;
	}


	if (nodeA->parent){
		if (rc) {
			(nodeA->parent)->right_child = nodeB;
		} else {
			(nodeA->parent)->left_child = nodeB;
		}
	}
	nodeA->parent = nodeB;

	//if B node has a left child, it must be relocated:

	if (nodeB->left_child) {
		(nodeB->left_child)->parent = nodeA;
		nodeA->right_child = nodeB->left_child;
	} else {
		nodeA->right_child = NULL;
	}

	//finally we connect the newly located node to its new child

	nodeB->left_child = nodeA;


	//now we need to update the height number of the affected nodes and their parents
	
	//%%%%%% HEIGHT UPDATE %%%%%%

	struct node *tmppointer = nodeA;

	int RC_height;
	int LC_height;

	while (tmppointer) {

		//first we need to get the height of their children
		(tmppointer->right_child)? RC_height = (tmppointer->right_child)->height : RC_height = 0; 
		(tmppointer->left_child)? LC_height = (tmppointer->left_child)->height : LC_height = 0; 

		//finally we assign the value to the node:
		cout << "RC_height" << RC_height << endl; 
		cout << "LC_height" << LC_height << endl; 		

		(RC_height >= LC_height)? tmppointer->height = RC_height +1 : tmppointer->height = LC_height+1;

		//switches to the next level in the following iteration:

		tmppointer = tmppointer->parent;
	}

	return 0;
}


int LR_rotation (struct node *nodeA, struct node *nodeB) {

	//in this case we need to add the third involved node

	struct node *nodeC = nodeB->right_child;

	bool rc;
	if (nodeA->parent) {
		if (nodeA == ((nodeA->parent)->right_child)) {
			rc = true;
		} else {
			rc = false;
		}

		//now add the new node as a child of A former parent
		if (rc) {
			(nodeA->parent)->right_child = nodeC;
		} else {
			(nodeA->parent)->left_child = nodeC;
		}
	}

	//then assign a parent to nodeC:

	if (nodeA->parent) {
		nodeC->parent = nodeA->parent;
	} else {
		nodeC->parent = NULL;
	}

	//now asigning the new parents of the other two modified nodes:

	nodeB->parent = nodeC;
	nodeA->parent = nodeC;

	//if nodeC had children previously, they must be reassigned:

	if (nodeC->left_child) {
		(nodeC->left_child)->parent = nodeB;
		nodeB->right_child = nodeC->left_child;
	} else {
		nodeB->right_child = NULL;
	}


	if (nodeC->right_child) {
		(nodeC->right_child)->parent = nodeA;
		nodeA->left_child = nodeC->right_child;
	} else {
		nodeA->left_child = NULL;
	}

	//lastly, we need to assign both nodes A and B as new children of C:

	nodeC->right_child = nodeA;
	nodeC->left_child = nodeB;
	

	//now we need to update the height number of the affected nodes and their parents
	
	//%%%%%% HEIGHT UPDATE %%%%%%

	struct node *tmppointer = nodeA;

	int RC_height;
	int LC_height;

	cout << "LR height update temppointer:" << tmppointer->name << endl;

	while (tmppointer) {

		//since the height refreshment is recursively going up (from son to parents), we need to
		//manually refresh the nodeC left son (nodeB in this case) otherwise the code would ignore this.
		//This wasn't needed in the previous rotations because the left or right node (LL or RR rotation )
		// didnt change their sons hence no height refreshment was needed.

		if (tmppointer == nodeC) {
			
			struct node *tmppointer2 = nodeC->left_child;

			(tmppointer2->right_child)? RC_height = (tmppointer2->right_child)->height : RC_height = 0; 
			(tmppointer2->left_child)? LC_height = (tmppointer2->left_child)->height : LC_height = 0; 

			//finally we assign the value to the node:
			cout << "RC_height" << RC_height << endl; 
			cout << "LC_height" << LC_height << endl; 		

			(RC_height >= LC_height)? tmppointer2->height = RC_height +1 : tmppointer2->height = LC_height+1;

		}		

		//first we need to get the height of their children
		(tmppointer->right_child)? RC_height = (tmppointer->right_child)->height : RC_height = 0; 
		(tmppointer->left_child)? LC_height = (tmppointer->left_child)->height : LC_height = 0; 

		//finally we assign the value to the node:
		cout << "RC_height" << RC_height << endl; 
		cout << "LC_height" << LC_height << endl; 		

		(RC_height >= LC_height)? tmppointer->height = RC_height +1 : tmppointer->height = LC_height+1;

		//switches to the next level in the following iteration:

		tmppointer = tmppointer->parent;
	}

	return 0;	

}

int RL_rotation (struct node *nodeA, struct node *nodeB) {
	//in this case we need to add the third involved node

	struct node *nodeC = nodeB->left_child;

	bool rc;
	if (nodeA->parent) {
		if (nodeA == ((nodeA->parent)->right_child)) {
			rc = true;
		} else {
			rc = false;
		}

		//now add the new node as a child of A former parent
		if (rc) {
			(nodeA->parent)->right_child = nodeC;
		} else {
			(nodeA->parent)->left_child = nodeC;
		}
	}

	//then assign a parent to nodeC:

	if (nodeA->parent) {
		nodeC->parent = nodeA->parent;
	} else {
		nodeC->parent = NULL;
	}

	//now asigning the new parents of the other two modified nodes:

	nodeB->parent = nodeC;
	nodeA->parent = nodeC;

	//if nodeC had children previously, they must be reassigned:

	if (nodeC->left_child) {
		(nodeC->left_child)->parent = nodeA;
		nodeA->right_child = nodeC->left_child;
	} else {
		nodeA->right_child = NULL;
	}


	if (nodeC->right_child) {
		(nodeC->right_child)->parent = nodeB;
		nodeB->left_child = nodeC->right_child;
	} else {
		nodeB->left_child = NULL;
	}

	//lastly, we need to assign both nodes A and B as new children of C:

	nodeC->right_child = nodeB;
	nodeC->left_child = nodeA;
	

	//now we need to update the height number of the affected nodes and their parents
	
	//%%%%%% HEIGHT UPDATE %%%%%%

	struct node *tmppointer = nodeA;

	int RC_height;
	int LC_height;

	cout << "LR height update temppointer:" << tmppointer->name << endl;

	while (tmppointer) {

		//since the height refreshment is recursively going up (from son to parents), we need to
		//manually refresh the nodeC left son (nodeB in this case) otherwise the code would ignore it.
		// This wasn't needed in the previous rotations because the left or right node (LL or RR rotation )
		// didnt change their sons hence no height refreshment was needed.

		if (tmppointer == nodeC) {
			
			struct node *tmppointer2 = nodeC->right_child;

			(tmppointer2->right_child)? RC_height = (tmppointer2->right_child)->height : RC_height = 0; 
			(tmppointer2->left_child)? LC_height = (tmppointer2->left_child)->height : LC_height = 0; 

			//finally we assign the value to the node:
			cout << "RC_height" << RC_height << endl; 
			cout << "LC_height" << LC_height << endl; 		

			(RC_height >= LC_height)? tmppointer2->height = RC_height +1 : tmppointer2->height = LC_height+1;

		}		

		//first we need to get the height of their children
		(tmppointer->right_child)? RC_height = (tmppointer->right_child)->height : RC_height = 0; 
		(tmppointer->left_child)? LC_height = (tmppointer->left_child)->height : LC_height = 0; 

		//finally we assign the value to the node:
		cout << "RC_height" << RC_height << endl; 
		cout << "LC_height" << LC_height << endl; 		

		(RC_height >= LC_height)? tmppointer->height = RC_height +1 : tmppointer->height = LC_height+1;

		//switches to the next level in the following iteration:

		tmppointer = tmppointer->parent;
	}

	return 0;	
}


int insert_node (string new_name, unsigned int newID, struct tree *treepointer) {

	struct node *tmppointer;
	tmppointer = treepointer->tree_root;
	bool rc;
	bool leaf = false;

	if (tmppointer->parent) {
		//the inserted node is not a root
		cout << "no es un root" << endl;
		return -1;
	} else {
		//firstly we look for where to insert the new node
		//path is followed until we meet a leaf
		do {
			if (newID > (tmppointer->ID)) {
				if (tmppointer->right_child) {	

					//depending on whether the node was inserted on the right or the left, 
					//and depending on which side was longer, we decide if we add to the 
					//parents height or not	

					if (!(tmppointer->left_child) || (tmppointer->left_child->height <= tmppointer->right_child->height)) {
						tmppointer->height = (tmppointer->height)+1;
					}

					tmppointer = (tmppointer->right_child);
				} else {
					if (!(tmppointer->left_child)) {
						tmppointer->height = (tmppointer->height)+1;
					}
					leaf = true;
				}
				rc = true;

			} else if (newID <= (tmppointer->ID)) {
				if (tmppointer->left_child) {
					if (!(tmppointer->right_child) || (tmppointer->right_child->height <= tmppointer->left_child->height)) {
						tmppointer->height = (tmppointer->height)+1;
						cout << "holis" << endl;
					}
					tmppointer = (tmppointer->left_child);					
				} else {
					if (!(tmppointer->right_child)) {
						tmppointer->height = (tmppointer->height)+1;
					}
					leaf = true;
				}			
				rc = false;
			}

		} while (!leaf);

		//now that we've found the parent node for the newly inserted node,
		//we proceed to insert it (and its related data):

		node* new_node = new node;

		if (!new_node) {
			return -2;
			//ran out of memory space
		} else {
			new_node->ID = newID;
			new_node->name = new_name;
			new_node->parent = tmppointer;

			//now adding the information to the parent

			if (rc) {
				tmppointer->right_child = new_node;
			} else {
				tmppointer->left_child = new_node;
			}


			// then we need to analyze if a rotation is needed or not, going from the buttom-up


			struct node *parent_tmppointer = NULL;

			bool rotated = false;
			bool nodeISroot = false;
			int balance_factor = 0;
			int parent_balance_factor = 0;
			int rc_height;
			int lc_height;
			int parent_rc_height;
			int parent_lc_height;

			while (tmppointer->parent && !rotated) {
				parent_tmppointer = tmppointer->parent;

				//checks if current parent node is the root of the tree. If it is and it needs to be rotated,
				//then the new parent should be linked to the tree struct as its root

				(parent_tmppointer->parent)? nodeISroot = false : nodeISroot = true;

				//we determine the balance factor of each node by looking at the height of their nodes;

				//if node doesnt exit then a value of 0 for its height is assigned;

				(tmppointer->right_child)? rc_height = (tmppointer->right_child->height) : rc_height = 0;
				(tmppointer->left_child)? lc_height = (tmppointer->left_child->height) : lc_height = 0;
				(parent_tmppointer->right_child)? parent_rc_height = (parent_tmppointer->right_child->height) : parent_rc_height = 0;
				(parent_tmppointer->left_child)? parent_lc_height = (parent_tmppointer->left_child->height) : parent_lc_height = 0;

				balance_factor = rc_height - lc_height;
				parent_balance_factor = parent_rc_height - parent_lc_height;

				//cout << "parent_rc_height " << parent_rc_height << endl;
				//cout << "parent_lc_height " << parent_lc_height << endl;

				cout << "balance_factor of:" << tmppointer->name <<" is: "<< balance_factor << endl;
				cout << "balance factor of:" << parent_tmppointer->name << " is: " << parent_balance_factor << endl;				

				//now we analyze each case to see if a rotation is needed. If it is, the we look for the appropiate
				//rotation depending on the situation.

				if (parent_balance_factor == -2 && balance_factor == -1 ) {
					if (nodeISroot) {
						treepointer->tree_root =  tmppointer;
					}
					LL_rotation(parent_tmppointer,tmppointer);
					rotated = true;
					cout << "LL rotating A ( " <<parent_tmppointer->ID << ") : " << parent_tmppointer->name << " with B ( " << tmppointer->ID << ") :" << tmppointer->name << endl;
				} else if (parent_balance_factor == 2 && balance_factor == 1 ) {
					if (nodeISroot) {
						treepointer->tree_root =  tmppointer;
					}
					RR_rotation(parent_tmppointer,tmppointer);
					rotated = true;
					cout << "RR rotating A ( " <<parent_tmppointer->ID << ") : " << parent_tmppointer->name << " with B ( " << tmppointer->ID << ") :" << tmppointer->name << endl;
									
				} else if (parent_balance_factor == -2 && balance_factor == 1 ) {
					if (nodeISroot) {
						treepointer->tree_root =  tmppointer->right_child;
					}
					LR_rotation(parent_tmppointer,tmppointer);
					rotated = true;
					cout << "LR rotating A ( " <<parent_tmppointer->ID << ") : " << parent_tmppointer->name << " with B ( " << tmppointer->ID << ") :" << tmppointer->name << endl;
									
				} else if (parent_balance_factor == 2 && balance_factor == -1 ) {
					if (nodeISroot) {
						treepointer->tree_root =  tmppointer->left_child;
					}
					RL_rotation(parent_tmppointer,tmppointer);
					rotated = true;
					cout << "RL rotating A ( " <<parent_tmppointer->ID << ") : " << parent_tmppointer->name << " with B ( " << tmppointer->ID << ") :" << tmppointer->name << endl;
									
				}

				//tmppointer is moved to the next parent

				tmppointer = parent_tmppointer;
			}


			return 0;
		}
	}
}


//wont be implemented yet

/*int delete_node () {

}*/

int GetMaxID (struct tree *treeptr) {
	struct node *nodeptr;
	nodeptr = treeptr->tree_root;

	while (nodeptr->right_child) {
		nodeptr = nodeptr->right_child;
	}

	cout << "The Max Value is: " << nodeptr->ID << " which corresponds to the user: " << nodeptr->name << endl;

	return 0;

}

int GetMinID (struct tree *treeptr) {
	struct node *nodeptr;
	nodeptr = treeptr->tree_root;

	while (nodeptr->left_child) {
		nodeptr = nodeptr->left_child;
	}

	cout << "The Min Value is: " << nodeptr->ID << " which corresponds to the user: " << nodeptr->name << endl;

	return 0;
}


int create_tree () {

	return 0;
}



int main () {


	//%%%%%%%%%% INSERT TEST %%%%%%%%%%

	/*struct node root;
	root.name = "Ricardo";
	root.ID = 10;

	//cout << root.nombre << endl;


	//struct node node1;
	//node1.name = "Arturo";
	//node1.ID = 12;

	//root.right_child = &node1;
	//node1.parent = &root;

	struct node *testpointer;
	struct node *son_pointer;


	insert_node("Arturo",7,&root);
	insert_node("Rocio",5,&root);
	//insert_node("Adrian",3,&root);
	//insert_node("Valeria",2,&root);
	//insert_node("Eduardo",7,&root);

	testpointer = &root;

	//cout << testpointer->name << endl;
	//cout << (testpointer->left_child)->name << endl;
	cout << (testpointer->right_child)->name << endl;
	cout << (testpointer->left_child)->name << endl;
	//cout << (testpointer->parent)->name << endl;
	//cout << (testpointer->parent)->name << endl;
	//cout << (testpointer->left_child)->balance_factor << endl;
	/*if (testpointer->left_child) {
		cout << "holis, si hay puntero" << endl;
	} else {
		cout << "no hay nada :(" << endl;
	}*/


	//%%%%%%%% LL ROTATION TEST %%%%%%%%%%%%	



	/*struct node root;
	root.name = "Ricardo";
	root.ID = 10;
	root.balance_factor = -2;

	struct node node1;
	node1.name = "Arturo";
	node1.ID = 8;
	node1.balance_factor = -1;

	struct node node2;
	node2.name = "Rocio";
	node2.ID = 7;
	node2.balance_factor = 0;

	root.left_child = &node1;
	node1.left_child = &node2;

	struct node *testpointer;

	testpointer = &root;

	cout << testpointer->name << endl;
	cout << (testpointer->left_child)->name << endl;
	cout << ((testpointer->left_child)->left_child)->name << endl;

	LL_rotation(&root,&node1);

	testpointer = &node1;

	cout << testpointer->name << endl;
	cout << (testpointer->left_child)->name << endl;
	cout << (testpointer->right_child)->name << endl;*/

	struct tree trial_tree;


	struct node root;
	root.name = "Ricardo";
	root.ID = 10;

	trial_tree.tree_name = "first_tree";
	trial_tree.tree_root = &root;

	struct node *testpointer;

	struct tree *tree_pointer;
	tree_pointer = &trial_tree;



	//%%%% FIRST TEST %%%%%%%

	/*insert_node("Arturo",7,tree_pointer);
	insert_node("Rocio",5,tree_pointer);
	insert_node("Adrian",3,tree_pointer);
	insert_node("Valeria",2,tree_pointer);*/

	//%%%% SECOND TEST %%%%%%

	//insert_node("Arturo",7,tree_pointer);
	//insert_node("Rocio",11,tree_pointer);
	//insert_node("Adrian",3,tree_pointer);

	//insert_node("Valeria",2,&root);
	//insert_node("Eduardo",7,&root);

	//%%%% RR TEST %%%%%%

	//insert_node("Moni",11,tree_pointer);
	//insert_node("Pri",12,tree_pointer);

	//%%%%% LR Test %%%%%%

	//insert_node("Arturo",7,tree_pointer);
	//insert_node("Rocio",8,tree_pointer);
	//insert_node("Adrian",3,tree_pointer);

	//%%%%% RL Test %%%%%%

	insert_node("Arturo",12,tree_pointer);
	insert_node("Rocio",11,tree_pointer);


	testpointer = &root;

	//cout << testpointer->name << endl;
	//cout << (testpointer->left_child)->name << endl;

	cout << "the new tree root is ( " << (tree_pointer->tree_root)->ID << ") :" << (tree_pointer->tree_root)->name << endl;

	cout << (tree_pointer->tree_root)->name << " right_child: "<< ((tree_pointer->tree_root)->right_child)->name << "( " << ((tree_pointer->tree_root)->right_child)->ID << ") " << endl;
	cout << (tree_pointer->tree_root)->name << " left_child: "<<  ((tree_pointer->tree_root)->left_child)->name << "( " << ((tree_pointer->tree_root)->left_child)->ID << ") " << endl;
	//cout << (testpointer->parent)->name << endl;

	cout << "New heights" << endl;
	cout << (tree_pointer->tree_root)->name << " Height: "<< (tree_pointer->tree_root)->height << endl;
	cout << (tree_pointer->tree_root)->right_child->name << " Height: "<< ((tree_pointer->tree_root)->right_child)->height << endl;
	cout << (tree_pointer->tree_root)->left_child->name << " Height: "<< ((tree_pointer->tree_root)->left_child)->height << endl;

	GetMinID(tree_pointer);
	GetMaxID(tree_pointer);




	return 0;

}

