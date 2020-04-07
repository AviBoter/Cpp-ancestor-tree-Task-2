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
Tree::~Tree() {}
Tree::Tree(string name) {}
Tree& Tree::addFather(string child, string father) {
	
	return *this;
}
Tree& Tree::addMother(string child, string mother) {
	
	return *this;
}
string Tree::relation(string s1) {
	return "gh";
}
string Tree::find(string s1) { return "gg"; }
Tree& Tree::remove(string s1) {
	
	return *this;
}
void Tree::display() {}


