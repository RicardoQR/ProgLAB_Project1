
#include <iostream>
#include <include/data_structures/avl_tree.hpp>


//NOTE: This test's only purpose is to check if the rotations are done correctly. This test does not mean
//to  determine whether the function detects when and which rotation is needed, since this is not done
//at this function level but rather is done at the "insert_node" function level; hence this behaviour will
// be tested at that level.

int print_family(struct node *nodeptr) {
	cout << "###### For node with name " << nodeptr->name << " and ID: " << nodeptr->ID << " ###### "<< endl;
	(nodeptr->parent)? cout << "Parent: " << nodeptr->parent->name << " ID: "<< nodeptr->parent->ID << endl : cout << "Parent: NULL. This node is the root" << endl;
	(nodeptr->right_child)? cout << "Right child: " << nodeptr->right_child->name << " ID: "<< nodeptr->right_child->ID  << endl : cout << "No right child!" << endl;
	(nodeptr->left_child)? cout << "Left child: " << nodeptr->left_child->name << " ID: "<< nodeptr->left_child->ID  << endl : cout << "No left child!" << endl;
}

int main() {
	
	//first we create the tree manually (we need to add the heights manually since the correct height
	//gets calculated within the insert_node function):

	struct node node0;
	struct node node1;
	struct node node2;
	struct node node3;
	struct node node4;
	struct node node5;

	//first case:

	//first we initialize the nodes

	node0.ID = 100;
	node0.name = "Ricardo Quiros Redondo";

	node1.ID = 102;
	node1.name = "Arturo Hernandez Chavez";

	node2.ID = 80;
	node2.name = "Rocio Quiros Hernandez";

	node3.ID = 85;
	node3.name = "Gustavo Fernandez Mora";

	node4.ID = 73;
	node4.name = "Monica Jimenez Chaverri";

	node5.ID = 75;
	node5.name = "Raul Herrera Araya";

	//then we add parenthood and height of each node

	node0.height = 4;
	node0.right_child = &node1;
	node0.left_child = &node2;

	node1.parent = &node0;

	node2.height = 3;
	node2.parent = &node0;
	node2.right_child = &node3; 
	node2.left_child = &node4;

	node3.parent = &node2;

	node4.parent = &node2;
	node4.height = 2;
	node4.right_child = &node5;

	node5.parent = &node4;

	struct node *nodeptr_list[6];

	nodeptr_list[0] = &node0;
	nodeptr_list[1] = &node1;
	nodeptr_list[2] = &node2;
	nodeptr_list[3] = &node3;
	nodeptr_list[4] = &node4;
	nodeptr_list[5] = &node5;

	cout << "######## LL ROTATION TEST #########" << endl;
	cout << endl;


	cout << "NODE CONNECTION BEFORE ROTATION..." << endl;
	cout << endl;

	for (int i = 0; i < 6; i++) {
		print_family(nodeptr_list[i]);
		cout << endl;
	}

	cout << "APPLYING LL ROTATION..." << endl;
	cout << endl;

	LL_rotation(&node0,&node2);


	for (int i = 0; i < 6; i++) {
		print_family(nodeptr_list[i]);
		cout << endl;
	}

	//%%%%%%% RR ROTATION TEST %%%%%%%%%%
	//same nodes just need to do a reconnection:

	cout << "######## RR ROTATION TEST #########" << endl;
	cout << endl;

	node0.ID = 100;
	node1.ID = 120;
	node2.ID = 200;
	node3.ID = 90;
	node4.ID = 110;
	node5.ID = 125;

	node0.parent = NULL;
	node0.right_child = &node1;
	node0.left_child = &node3;
	node0.height = 4;

	node1.parent = &node0;
	node1.right_child = &node2;
	node1.left_child = &node4;
	node1.height = 3;

	node2.parent = &node1;
	node2.right_child = NULL;
	node2.left_child = &node5;
	node2.height = 2;

	node3.parent = &node0;
	node3.right_child = NULL;
	node3.left_child = NULL;
	node3.height = 1;

	node4.parent = &node1;
	node4.right_child = NULL;
	node4.left_child = NULL;
	node4.height = 1;

	node5.parent = &node2;
	node5.right_child = NULL;
	node5.left_child = NULL;
	node5.height = 1;


	cout << "NODE CONNECTION BEFORE ROTATION..." << endl;
	cout << endl;

	for (int i = 0; i < 6; i++) {
		print_family(nodeptr_list[i]);
		cout << endl;
	}

	cout << "APPLYING RR ROTATION..." << endl;
	cout << endl;

	RR_rotation(&node0,&node1);


	for (int i = 0; i < 6; i++) {
		print_family(nodeptr_list[i]);
		cout << endl;
	}



	//%%%%%%%%% LR ROTATION %%%%%%%%%%%%%

	cout << "######## LR ROTATION TEST #########" << endl;
	cout << endl;

	node0.ID = 100;
	node1.ID = 110;
	node2.ID = 90;
	node3.ID = 95;
	node4.ID = 98;
	node5.ID = 80;

	node0.parent = NULL;
	node0.right_child = &node1;
	node0.left_child = &node2;
	node0.height = 4;

	node1.parent = &node0;
	node1.right_child = NULL;
	node1.left_child = NULL;
	node1.height = 1;

	node2.parent = &node0;
	node2.right_child = &node3;
	node2.left_child = &node5;
	node2.height = 3;

	node3.parent = &node2;
	node3.right_child = &node4;
	node3.left_child = NULL;
	node3.height = 2;

	node4.parent = &node3;
	node4.right_child = NULL;
	node4.left_child = NULL;
	node4.height = 1;

	node5.parent = &node2;
	node5.right_child = NULL;
	node5.left_child = NULL;
	node5.height = 1;


	cout << "NODE CONNECTION BEFORE ROTATION..." << endl;
	cout << endl;

	for (int i = 0; i < 6; i++) {
		print_family(nodeptr_list[i]);
		cout << endl;
	}

	cout << "APPLYING LR ROTATION..." << endl;
	cout << endl;

	LR_rotation(&node0,&node2);


	for (int i = 0; i < 6; i++) {
		print_family(nodeptr_list[i]);
		cout << endl;
	}

	//%%%%%%%%% RL ROTATION %%%%%%%%%%%%%

	cout << "######## RL ROTATION TEST #########" << endl;
	cout << endl;

	node0.ID = 100;
	node1.ID = 130;
	node2.ID = 110;
	node3.ID = 140;
	node4.ID = 105;
	node5.ID = 90;

	node0.parent = NULL;
	node0.right_child = &node1;
	node0.left_child = &node5;
	node0.height = 4;

	node1.parent = &node0;
	node1.right_child = &node3;
	node1.left_child = &node2;
	node1.height = 3;

	node2.parent = &node1;
	node2.right_child = NULL;
	node2.left_child = &node4;
	node2.height = 2;

	node3.parent = &node1;
	node3.right_child = NULL;
	node3.left_child = NULL;
	node3.height = 1;

	node4.parent = &node2;
	node4.right_child = NULL;
	node4.left_child = NULL;
	node4.height = 1;

	node5.parent = &node0;
	node5.right_child = NULL;
	node5.left_child = NULL;
	node5.height = 1;


	cout << "NODE CONNECTION BEFORE ROTATION..." << endl;
	cout << endl;

	for (int i = 0; i < 6; i++) {
		print_family(nodeptr_list[i]);
		cout << endl;
	}

	cout << "APPLYING RL ROTATION..." << endl;
	cout << endl;

	RL_rotation(&node0,&node1);


	for (int i = 0; i < 6; i++) {
		print_family(nodeptr_list[i]);
		cout << endl;
	}






	return 0;


}