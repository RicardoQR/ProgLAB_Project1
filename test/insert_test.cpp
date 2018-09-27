
#include <iostream>
#include <include/data_structures/avl_tree.hpp>

int print_family(struct node *nodeptr) {
	if (!nodeptr) {
		cout << "ERROR! Node is NULL. Check your input" << endl;
	} else {
		cout << "###### For node with name " << nodeptr->name << " and ID: " << nodeptr->ID << " ###### "<< endl;
		cout << "Node's height: " << nodeptr->height << endl;	
		(nodeptr->parent)? cout << "Parent: " << nodeptr->parent->name << " ID: "<< nodeptr->parent->ID << endl : cout << "Parent: NULL. This node is the root" << endl;
		(nodeptr->right_child)? cout << "Right child: " << nodeptr->right_child->name << " ID: "<< nodeptr->right_child->ID  << endl : cout << "No right child!" << endl;
		(nodeptr->left_child)? cout << "Left child: " << nodeptr->left_child->name << " ID: "<< nodeptr->left_child->ID  << endl : cout << "No left child!" << endl;

	}
	cout << endl;
}

int main () {
	
	struct tree test_tree;
	struct tree *treeptr = &test_tree;

	cout << "We first test out a simple node insertion" << endl;



	cout << "We then test the rotations embedded inside the insertion itself" << endl;

	bool debug = true;

	//%%%%%%%% FIRST ROTATION TEST RR %%%%%%%%%%%

	insert_node("Ricardo Chaves Montero",100,treeptr);
	insert_node("Arturo Hernandez Chavez",102,treeptr);
	insert_node("Rocio Quiros Hernandez",80,treeptr);
	insert_node("Roberto Parra Jaen",85,treeptr);
	insert_node("Pablo Esquivel Martinez",73,treeptr);
	insert_node("Raul Herrera Araya",75,treeptr);

	print_family(treeptr->tree_root);
	print_family(treeptr->tree_root->right_child);
	print_family(treeptr->tree_root->left_child);
	print_family(treeptr->tree_root->right_child->right_child);
	print_family(treeptr->tree_root->right_child->left_child);
	print_family(treeptr->tree_root->left_child->right_child);
	print_family(treeptr->tree_root->left_child->left_child);


	//%%%%%%%%% SECOND ROTATION TEST LL %%%%%%%%%

	struct tree tree2;
	treeptr = &tree2;


	insert_node("Ricardo Chaves Montero",100,treeptr);
	insert_node("Arturo Hernandez Chavez",120,treeptr);
	insert_node("Rocio Quiros Hernandez",200,treeptr);
	insert_node("Roberto Parra Jaen",90,treeptr);
	insert_node("Pablo Esquivel Martinez",110,treeptr);
	insert_node("Raul Herrera Araya",125,treeptr);

	print_family(treeptr->tree_root);
	print_family(treeptr->tree_root->right_child);
	print_family(treeptr->tree_root->left_child);
	print_family(treeptr->tree_root->right_child->right_child);
	print_family(treeptr->tree_root->right_child->left_child);
	print_family(treeptr->tree_root->left_child->right_child);
	print_family(treeptr->tree_root->left_child->left_child);


	//%%%%%%%%% THIRD ROTATION TEST LR %%%%%%%%%%


	struct tree tree3;
	treeptr = &tree3;


	insert_node("Ricardo Chaves Montero",100,treeptr);
	insert_node("Arturo Hernandez Chavez",110,treeptr);
	insert_node("Rocio Quiros Hernandez",90,treeptr);
	insert_node("Roberto Parra Jaen",95,treeptr);
	insert_node("Pablo Esquivel Martinez",80,treeptr);
	insert_node("Raul Herrera Araya",98,treeptr);

	print_family(treeptr->tree_root);
	print_family(treeptr->tree_root->right_child);
	print_family(treeptr->tree_root->left_child);
	print_family(treeptr->tree_root->right_child->right_child);
	print_family(treeptr->tree_root->right_child->left_child);
	print_family(treeptr->tree_root->left_child->right_child);
	print_family(treeptr->tree_root->left_child->left_child);


	//%%%%%%%% FOURTH ROTATION TEST RL %%%%%%%%%


	struct tree tree4;
	treeptr = &tree4;


	insert_node("Ricardo Chaves Montero",100,treeptr);
	insert_node("Arturo Hernandez Chavez",130,treeptr);
	insert_node("Rocio Quiros Hernandez",110,treeptr);
	insert_node("Roberto Parra Jaen",140,treeptr);
	insert_node("Pablo Esquivel Martinez",90,treeptr);
	insert_node("Raul Herrera Araya",105,treeptr);

	print_family(treeptr->tree_root);
	print_family(treeptr->tree_root->right_child);
	print_family(treeptr->tree_root->left_child);
	print_family(treeptr->tree_root->right_child->right_child);
	print_family(treeptr->tree_root->right_child->left_child);
	print_family(treeptr->tree_root->left_child->right_child);
	print_family(treeptr->tree_root->left_child->left_child);


	//struct node temppointer 

	//while ()

	return 0;
}