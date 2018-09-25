 

#include <iostream>
#include <include/data_structures/avl_tree.hpp>
#include <fstream>
#include <vector>
#include <regex>


int main () {

	ifstream infile;
	infile.open("../misc/inputs/lista_10.txt");

	string name;
	string strID;
	unsigned int ID;

	vector<string> namevec;
	vector<int> IDvec;

	regex valid_name("[a-z]+");

	while (!infile.eof()) {
		getline(infile,name,',');
		getline(infile,strID,'\n');
		ID = stoi(strID);

		//now we add each of the line contents to the respective vector:
		if (regex_search(name,valid_name)) {
			namevec.push_back(name);
			IDvec.push_back(ID);
			cout << "name is: " << name << endl;
			cout << regex_search(name,valid_name) << endl;
			cout << "ID is: " << ID << endl; 
		}

	}

	create_tree(namevec,IDvec,"Tree1");
	
	return 0;

}