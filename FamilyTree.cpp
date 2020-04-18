/*

AUTHORS: liad ben moshe


*/
#include "FamilyTree.hpp"
#include <bits/stdc++.h> 
#include <iostream>
#include <stdexcept>
#include <string>
#include <exception>

using namespace std;
using namespace family;

Tree::Tree() {}
Tree::~Tree() {
	
	deleteT();
}
Tree::Tree(string name) {
	
	this->me.assign(name);
	this->dad = NULL;
	this->mom = NULL;
	this->san = NULL;
	
	
}
Tree& Tree::addFather(string child, string father) {
	
	
	if (this->me == child ){
		if(this->dad == NULL) 
		{
		
		this->dad = new Tree(father);
		this->dad->san = this;
		this->dad->sex='m';
		
		}else
			throw runtime_error ("alrady have a father");
		
		
	}
	else if(this->dad!=NULL) {
		 this->dad->addFather(child, father);
	}
	else if(this->mom!=NULL){
		 this->dad->addFather(child, father);
	   }
	
		return *this;

}

Tree& Tree::addMother(string child, string mother) {
	
	
	if (this->me == child){
		if (this->mom == NULL) {
			
			this->mom = new Tree(mother);
			this->mom->san = this;
			this->mom->sex = 'f';
		}
		else
			throw runtime_error("alrady have a mom");
		
	}
	else if (this->dad != NULL) {
		 this->dad->addMother(child,mother);
	}
	else if (this->mom != NULL) {
		 this->mom->addMother(child, mother);
	}
	
		return *this;
	
}

string Tree::relation(string s1) {
	Tree* temp = this->relationPrivate(s1);
	int count=0;
	char c;
	if (temp != NULL) {
		c = temp->sex;
		while (temp->san != NULL) {
			count++;
			temp = temp->san;
		}
		
		if (count == 0) {
			return "me";
		}
		if (count == 1) {
			
			if (c =='m') {
				return "father";
			}
			else {
				return "mother";
			}
		}
		else if (count == 2) {
			if (c == 'f') {
				return "grandmother";
			}
			else {
				return "grandfather";
			}
		}
		else if(count>2)
		{
			string s = "";
			for (int i = 0; i < count - 2; i++) {
				s += "great-";
			}
			if (c == 'm') {
				s += "grandfather";
				return s;
			}
			else
			{
				s += "grandmother";
				return s;

			}
				
		}


	}
	return "unrelated";

	
	

}

Tree* Tree::relationPrivate(string s1) {
	Tree* temp=NULL;
	if (this->me == s1) {
		return this;
	}
	else if(this->dad!=NULL)
	{
		temp = this->dad->relationPrivate(s1);
	}
	if (temp == NULL && this->mom != NULL) {
		temp = this->mom->relationPrivate(s1);
	}
	
	return temp;
	

	

}


string Tree::find(string s1) {
	Tree* temp=NULL;
	if (s1 == me) {
		return this->me;
	}
	else if (s1 == "mother" && this->mom!=NULL) {
		return this->mom->me;
	}
	else if (s1 == "father" && this->dad!=NULL) {
		return this->dad->me;
	}
	else {
		stringstream iss(s1);
		string w1;
		int count = 0;
		char c;
		while (getline(iss, w1, '-')) {
			count++;
		}
		
		if (w1 == "grandfather") {
			c = 'm';
		}
		else if(w1=="grandmother"){
			c = 'f';
		}
		else
		{
			throw runtime_error("The tree cannot handle the " + s1 + " relation");
		}
		
		if (this->dad != NULL) {
			
			temp = this->dad->findPrivate(count, c);
		}
		if (temp == NULL && this->mom != NULL) {
			
			temp = this->mom->findPrivate(count, c);
		}
	
	}
	if (temp == NULL) {
		throw runtime_error("The tree cannot handle the " + s1 + " relation");
	}
	return temp->me;
	
	
}


Tree* Tree::findPrivate(int num,char c) {
	Tree* temp=NULL;
	if (num == 1) {
		if (c == 'm' && this->dad != NULL) {
			return this->dad;
		}
		if (c == 'f' && this->mom != NULL) {
			return this->mom;
		}
	}
	else if (num > 1 && this->dad!=NULL) {
		temp = this->dad->findPrivate(num - 1, c);

	}
	if (num > 1 && temp == NULL && this->mom != NULL) {
		temp = this->mom->findPrivate(num - 1, c);
	}
	return temp;
}



void Tree::remove(string s1) {
	if ( this->dad!=NULL &&	this->dad->me == s1) {
		cout << this->dad->me <<" delete"<< endl;
		delete this->dad;
		this->dad = NULL;
		return;
	}
	else if (this->mom != NULL && this->mom->me == s1) {
		cout << this->mom->me <<" delete"<< endl;
		delete this->mom;
		this->mom = NULL;
		return;
	}
	else if(this->dad!=NULL)
	{
		this->dad->remove(s1);
	}
	else if (this->mom != NULL) {
		this->mom->remove(s1);
	}
	else
	{
		throw runtime_error("cannot delete this name");
	}


	
}
void Tree::display() {
	this->print2D(this, 5);
	
	
	
}

void Tree::print2D(Tree* root, int space)
{
	

	// Increase distance between levels  
	space += 10;

	// Process right child first  
	if (root->mom != NULL) {
		this->print2D(root->mom, space);
	}
	

	// Print current node after space  
	// count  
	cout << endl;
	for (int i = 10; i < space; i++)
		cout << " ";
	if(root->san==NULL)
		cout << root->me << "\n";
	else if(root->sex=='m')
		cout <<"Dad: "<<root->me << "\n";
	else
		cout <<"Mom: " <<root->me << "\n";

	// Process left child 
	if (root->dad != NULL) {
		this->print2D(root->dad, space);
	}
}


void Tree::deleteT() {
	if (this->mom!= NULL) {
		delete this->mom;
	}
	if (this->dad!= NULL) {
		delete this->dad;
	}


}


