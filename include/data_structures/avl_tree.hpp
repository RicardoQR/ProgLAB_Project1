
#include <iostream>
#include <string>
#include <vector>

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

/*int search_node () {

}*/

/*int print_family(struct node *nodeptr) {
	cout << "###### For node with name " << nodeptr->name << " and ID: " << nodeptr->ID << " ###### "<< endl;
	cout << "Node's height: " << nodeptr->height << endl;	
	(nodeptr->parent)? cout << "Parent: " << nodeptr->parent->name << " ID: "<< nodeptr->parent->ID << endl : cout << "Parent: NULL. This node is the root" << endl;
	(nodeptr->right_child)? cout << "Right child: " << nodeptr->right_child->name << " ID: "<< nodeptr->right_child->ID  << endl : cout << "No right child!" << endl;
	(nodeptr->left_child)? cout << "Left child: " << nodeptr->left_child->name << " ID: "<< nodeptr->left_child->ID  << endl : cout << "No left child!" << endl;
}*/

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
		/*cout << "RC_height" << RC_height << endl; 
		cout << "LC_height" << LC_height << endl;*/ 		

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

		//cout << "TMPPOINTER IS: " << tmppointer->name << endl;

		//first we need to get the height of their children
		/*cout << tmppointer->right_child->name << endl;
		cout << tmppointer->left_child->name << endl;*/

		RC_height = (tmppointer->right_child)? (tmppointer->right_child)->height :  0; 
		LC_height = (tmppointer->left_child)? (tmppointer->left_child)->height : 0; 

		//finally we assign the value to the node:
		/*cout << "RC_height" << RC_height << endl; 
		cout << "LC_height" << LC_height << endl; */		

		tmppointer->height = (RC_height >= LC_height)? RC_height +1 : LC_height+1;

		//switches to the next level in the following iteration:

		tmppointer = tmppointer->parent;
	}

	return 0;
}


int LR_rotation (struct node *nodeA, struct node *nodeB) {

	//in this case we need to add the third involved node

	struct node *nodeC = nodeB->right_child;

	cout << nodeC->name << endl;

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

	//cout << "LR height update temppointer:" << tmppointer->name << endl;

	while (tmppointer) {

		//since the height refreshment is recursively going up (from son to parents), we need to
		//manually refresh the nodeC left son (nodeB in this case) otherwise the code would ignore this.
		//This wasn't needed in the previous rotations because the left or right node (LL or RR rotation )
		// didnt change their sons hence no height refreshment was needed.

		if (tmppointer == nodeC) {
			
			struct node *tmppointer2 = nodeC->left_child;

			/*(tmppointer2->right_child)? RC_height = (tmppointer2->right_child)->height : RC_height = 0; 
			(tmppointer2->left_child)? LC_height = (tmppointer2->left_child)->height : LC_height = 0; */

			//finally we assign the value to the node:
			/*cout << "RC_height" << RC_height << endl; 
			cout << "LC_height" << LC_height << endl; */		

			(RC_height >= LC_height)? tmppointer2->height = RC_height +1 : tmppointer2->height = LC_height+1;

		}		

		//first we need to get the height of their children
		(tmppointer->right_child)? RC_height = (tmppointer->right_child)->height : RC_height = 0; 
		(tmppointer->left_child)? LC_height = (tmppointer->left_child)->height : LC_height = 0; 

		//finally we assign the value to the node:
		/*cout << "RC_height" << RC_height << endl; 
		cout << "LC_height" << LC_height << endl; 	*/	

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

	cout << "RL height update temppointer:" << tmppointer->name << endl;

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
			/*cout << "RC_height" << RC_height << endl; 
			cout << "LC_height" << LC_height << endl;*/ 		

			(RC_height >= LC_height)? tmppointer2->height = RC_height +1 : tmppointer2->height = LC_height+1;

		}		

		//first we need to get the height of their children
		(tmppointer->right_child)? RC_height = (tmppointer->right_child)->height : RC_height = 0; 
		(tmppointer->left_child)? LC_height = (tmppointer->left_child)->height : LC_height = 0; 

		//finally we assign the value to the node:
		/*cout << "RC_height" << RC_height << endl; 
		cout << "LC_height" << LC_height << endl; */		

		(RC_height >= LC_height)? tmppointer->height = RC_height +1 : tmppointer->height = LC_height+1;

		//switches to the next level in the following iteration:

		tmppointer = tmppointer->parent;
	}

	return 0;	
}


int insert_node (string new_name, unsigned int newID, struct tree *treepointer, bool debug = false) {

	struct node *tmppointer;
	tmppointer = treepointer->tree_root;
	bool rc;
	bool leaf = false;

	/*if (tmppointer->parent) {
		//the inserted node is not a root
		cout << "no es un root" << endl;
		return -1;*/
	if (!treepointer->tree_root) {

		//means that the tree has not yet been initialized, hence it has no root.
		//We proceed to insert the first node.
		node* new_node = new node;

		if (!new_node) {
			return -2;
			//ran out of memory space
		} else {
			//create new node that
			treepointer->tree_root = new_node;
			new_node->ID = newID;
			new_node->name = new_name;

			cout << "Inserting first node.." << endl;

			/*if (debug) {
				print_family(new_node);
			}*/

			return 0;
		}
	} else {
		//firstly we look for where to insert the new node
		//path is followed until we meet a leaf
		do {
			if (newID > (tmppointer->ID)) {
				if (tmppointer->right_child) {	
					tmppointer = (tmppointer->right_child);
				} else {
					leaf = true;
				}
				rc = true;

			} else if (newID <= (tmppointer->ID)) {
				if (tmppointer->left_child) {
					tmppointer = (tmppointer->left_child);					
				} else {
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


			//first we need to refresh the height values from the last node going up

			struct node *tmpheight_ptr = tmppointer;
			int RC_height;
			int LC_height;

			while (tmpheight_ptr) {

				RC_height = (tmpheight_ptr->right_child)? (tmpheight_ptr->right_child)->height :  0; 
				LC_height = (tmpheight_ptr->left_child)? (tmpheight_ptr->left_child)->height : 0; 

			//finally we assign the value to the node:
				/*cout << "RC_height" << RC_height << endl; 
				cout << "LC_height" << LC_height << endl; */		

				tmpheight_ptr->height = (RC_height >= LC_height)? RC_height +1 : LC_height+1;

			//switches to the next level in the following iteration:

				tmpheight_ptr = tmpheight_ptr->parent;
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

				//if node doesnt exist then a value of 0 for its height is assigned;

				(tmppointer->right_child)? rc_height = (tmppointer->right_child->height) : rc_height = 0;
				(tmppointer->left_child)? lc_height = (tmppointer->left_child->height) : lc_height = 0;
				(parent_tmppointer->right_child)? parent_rc_height = (parent_tmppointer->right_child->height) : parent_rc_height = 0;
				(parent_tmppointer->left_child)? parent_lc_height = (parent_tmppointer->left_child->height) : parent_lc_height = 0;

				balance_factor = rc_height - lc_height;
				parent_balance_factor = parent_rc_height - parent_lc_height;

				//cout << "parent_rc_height " << parent_rc_height << endl;
				//cout << "parent_lc_height " << parent_lc_height << endl;

				/*cout << "balance_factor of:" << tmppointer->name <<" is: "<< balance_factor << endl;
				cout << "balance factor of:" << parent_tmppointer->name << " is: " << parent_balance_factor << endl;*/				

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

			/*if (debug) {
				print_family(new_node);
			}*/

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


struct tree* create_tree (vector<string> namevec, vector<int> IDvec, string TreeName = "NewTree") {

	//first we instanciate the new tree

	tree *treeptr = new tree;

	treeptr->tree_name = TreeName;

	cout << "Creating tree " << treeptr->tree_name << " ..." << endl;

	for (int i = 0; i < namevec.size(); i++) {
		cout << "Now reviewing the name: " << namevec[i] << " and ID " << IDvec[i] << endl;
		insert_node(namevec[i],IDvec[i],treeptr);
	}

	cout << "Tree Root: " << treeptr->tree_root->name << " with ID: "  << treeptr->tree_root->ID << endl;
	cout << "Right_child is: " << treeptr->tree_root->right_child->name << " with ID: "<< treeptr->tree_root->right_child->ID << endl ;
	cout << "Left_child is: " << treeptr->tree_root->left_child->name << " with ID: "<< treeptr->tree_root->left_child->ID << endl ;

	return treeptr;
}



