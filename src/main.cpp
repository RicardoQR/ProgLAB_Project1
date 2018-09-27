 

#include <iostream>
#include <include/data_structures/avl_tree.hpp>
#include <fstream>
#include <vector>
#include <regex>
#include <chrono>


int main () {

	ifstream infile;
	infile.open("../misc/inputs/lista_1000.txt");

	string name;
	string strID;
	unsigned int ID;

	vector<string> namevec;
	vector<int> IDvec;

	regex valid_name("[a-z]+");

	//start execution chronometer:


	while (!infile.eof()) {
		getline(infile,name,',');
		getline(infile,strID,'\n');

		try {
			ID = stoi(strID);
		} catch (const out_of_range& e) {
			cout << "Name: " << name << "with ID: " << strID << "wasnt added because ID size exceeds the maximum number allowed..." << endl;
		}

		//now we add each of the line contents to the respective vector:
		if (regex_search(name,valid_name)) {
			namevec.push_back(name);
			IDvec.push_back(ID);
			cout << "name is: " << name << endl;
			cout << regex_search(name,valid_name) << endl;
			cout << "ID is: " << ID << endl; 
		}

	}

	// Record start time
	auto start = chrono::high_resolution_clock::now();


	//Then we create the tree with all the information of the text files

	struct tree *treeptr = create_tree(namevec,IDvec,"Tree1");

	// Now we look for the lowest and highest ID value of the list.

	cout << endl;
	cout << "##############################################" << endl;
	cout << endl;

	GetMaxID(treeptr);
	GetMinID(treeptr);



	// Record end time
	auto finish = chrono::high_resolution_clock::now();

	// Save the time in a special variable
	chrono::duration<double> elapsed = finish - start;

	cout << "TIMESTAMP: the execution of the program took: " << elapsed.count() << " seconds... " << endl;
	
	cout << endl;
	cout << "##############################################" << endl;
	cout << endl;

	return 0;

}