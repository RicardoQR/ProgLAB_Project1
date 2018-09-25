#include <iostream>
#include <include/data_structures/avl_tree.hpp>

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

	/*insert_node("Arturo",12,tree_pointer);
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
	GetMaxID(tree_pointer);*/


	vector<string> vect;
	vect.push_back("ricardo"); 
    vect.push_back("arturo"); 
    vect.push_back("gustavo");

    vector<int> vectnum;
    vectnum.push_back(10); 
    vectnum.push_back(5); 
    vectnum.push_back(3);

    create_tree(vect,vectnum,"TestTree");





	return 0;

}