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
	
}
Tree& Tree::addFather(string child, string father) {
	
	
	if (this->me == child ){
		if(this->dad == NULL) 
		{
		
		this->dad = new Tree(father);
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
	
	
	return "gh";
}
string Tree::find(string s1) { return "gg"; }


void Tree::remove(string s1) {
	if ( this->dad!=NULL &&	this->dad->me == s1) {
		cout << this->dad->me << endl;
		delete this->dad;
		this->dad = NULL;
		return;
	}
	else if (this->mom != NULL && this->mom->me == s1) {
		cout << this->mom->me << endl;
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
	
}

void Tree::deleteT() {
	if (this->mom!= NULL) {
		delete this->mom;
	}
	if (this->dad!= NULL) {
		delete this->dad;
	}


}


