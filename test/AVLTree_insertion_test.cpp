
#include “/home/ricardo/Documents/UCR/IIS_2018/Labo\ programacion/Proyecto1/include/data_structures/avl_tree.hpp“

//first unittest: insertion

int main () {


	struct node root;
	root.name = "Ricardo";
	root.ID = 10;

	//cout << root.nombre << endl;


	/*struct node node1;
	node1.name = "Arturo";
	node1.ID = 12;

	root.right_child = &node1;
	node1.parent = &root;*/

	struct node *testpointer;
	struct node *son_pointer;


	testpointer = &root;
	son_pointer = testpointer->right_child;

	insert_node("Arturo",12,&root);
	//insert_node("Rocio",13,&root);
	insert_node("Eduardo",7,&root);


	cout << testpointer->name << endl;
	cout << (testpointer->right_child)->name << endl;
	//cout << ((testpointer->right_child)->right_child)->name << endl;
	//cout << (testpointer->left_child)->name << endl;
	cout << testpointer->balance_factor << endl;
	cout << (testpointer->right_child)->balance_factor << endl;
	/*if (testpointer->left_child) {
		cout << "holis, si hay puntero" << endl;
	} else {
		cout << "no hay nada :(" << endl;
	}*/

	return 0;

}