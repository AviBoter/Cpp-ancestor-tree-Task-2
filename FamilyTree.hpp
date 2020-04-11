#include <bits/stdc++.h> 
#include <iostream>
#include <stdexcept>
#include <string>
#include <exception>

using namespace std;


namespace family {
	class Tree
	{
	public:

		Tree();
		~Tree();
		Tree(string name);
		Tree& addFather(string child, string father);
		Tree& addMother(string child, string mother);
		string relation(string s1);
		string find(string s1);
		void remove(string s1);
		void display();
		void deleteT();



	private:

		string me;
		Tree* mom;
		Tree* dad;

	};
};