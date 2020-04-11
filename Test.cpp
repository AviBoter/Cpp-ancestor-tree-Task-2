/*

AUTHORS: liad ben moshe


*/
#include "doctest.h"
#include "FamilyTree.hpp"
#include <string>

using namespace std;
using namespace family;

TEST_CASE("addMother and addFather, 16 tests") {
	Tree T1("Yosef");
	T1.addFather("Yosef", "Yakov");
	T1.addMother("Yosef", "Rachel");
	T1.addFather("Yakov", "Issac");
	T1.addMother("Yakov", "Rivka");
	T1.addFather("Issac", "Avram");
	T1.addMother("Isaac", "Sara");
	T1.addFather("Avram", "Terah");
	T1.addMother("Avram", "Amtalai");

	CHECK(T1.relation("Yosef") == string("me"));
	CHECK(T1.relation("Yakov") == string("father"));
	CHECK(T1.relation("Rachel") == string("mother"));
	CHECK(T1.relation("Rivka") == string("grandmother"));
	CHECK(T1.relation("Issac") == string("grandfather"));
	CHECK(T1.relation("Avram") == string("grand-grandfather"));
	CHECK(T1.relation("Sara") == string("grand-grandmother"));
	CHECK(T1.relation("Terah") == string("grand-grand-grandfather"));
	CHECK(T1.relation("Amtalai") == string("grand-grand-grandmother"));


	CHECK_THROWS_AS(T1.addFather("Yosef", "Shoki"),runtime_error);
	CHECK_THROWS_AS(T1.addMother("Yosef", "Grizelda"),runtime_error);
	CHECK_THROWS_AS(T1.addFather("Yakov", "Shoki"), runtime_error);
	CHECK_THROWS_AS(T1.addMother("Yakov", "Grizelda"), runtime_error);
	CHECK_THROWS_AS(T1.addFather("Issac", "Shoki"), runtime_error);
	CHECK_THROWS_AS(T1.addMother("Issac", "Grizelda"), runtime_error);
	CHECK_THROWS_AS(T1.addFather("Avram", "Grize"), runtime_error);
	CHECK_THROWS_AS(T1.addMother("Avram", "Gazel"), runtime_error);



}
TEST_CASE("find , 15 test") {
	Tree T2("Yosef");
	T2.addFather("Yosef", "Yakov");
	T2.addMother("Yosef", "Rachel");
	T2.addFather("Yakov", "Issac");
	T2.addMother("Yakov", "Rivka");
	T2.addFather("Issac", "Avram");
	T2.addMother("Isaac", "Sara");
	T2.addFather("Avram", "Terah");
	T2.addMother("Avram", "Amtalai");

	CHECK(T2.find("mother") == string("Rachel"));
	CHECK(T2.find("father") == string("Yakov"));
	CHECK(T2.find("grandmother") == string("Rivka"));
	CHECK(T2.find("grandfather") == string("Issac"));
	CHECK(T2.find("grand-grandfather") == string("Avram"));
	CHECK(T2.find("grand-grandmother") == string("Sara"));
	CHECK(T2.find("grand-grand-grandfather") == string("Terah"));
	CHECK(T2.find("grand-grand-grandmother") == string("Amtalai"));
	CHECK(T2.find("me") == string("Yosef"));

	CHECK_THROWS(T2.find("grand-grand-grand-grandmother"));
	CHECK_THROWS(T2.find("grand-grand-grand-grandfather"));
	CHECK_THROWS(T2.find("grand-grand-grand-grand-grandfather"));
	CHECK_THROWS(T2.find("grand-grand-grand-grand-grandmother"));
	CHECK_THROWS(T2.find("grand-grand-grand-grand-grand-grandfather"));
	CHECK_THROWS(T2.find("grand-grand-grand-grand-grand-grandmother"));

}

TEST_CASE("relation , 22 tests") {
	Tree T1("Yosef");
	T1.addFather("Yosef", "Yakov");
	T1.addMother("Yosef", "Rachel");
	T1.addFather("Yakov", "Issac");
	T1.addMother("Yakov", "Rivka");
	T1.addFather("Issac", "Avram");
	T1.addMother("Isaac", "Sara");
	T1.addFather("Avram", "Terah");
	T1.addMother("Avram", "Amtalai");

	CHECK(T1.relation("Yosef") == string("me"));
	CHECK(T1.relation("Yakov") == string("father"));
	CHECK(T1.relation("Rachel") == string("mother"));
	CHECK(T1.relation("Rivka") == string("grandmother"));
	CHECK(T1.relation("Issac") == string("grandfather"));
	CHECK(T1.relation("Avram") == string("grand-grandfather"));
	CHECK(T1.relation("Sara") == string("grand-grandmother"));
	CHECK(T1.relation("Terah") == string("grand-grand-grandfather"));
	CHECK(T1.relation("Amtalai") == string("grand-grand-grandmother"));

	CHECK(T1.relation("Yosef") == string("unrelated"));
	CHECK(T1.relation("Konal") == string("unrelated"));
	CHECK(T1.relation("Yter") == string("unrelated"));
	CHECK(T1.relation("Holyo") == string("unrelated"));
	CHECK(T1.relation("Tarev") == string("unrelated"));
	CHECK(T1.relation("Hplo") == string("unrelated"));
	CHECK(T1.relation("Ben") == string("unrelated"));
	CHECK(T1.relation("Avi") == string("unrelated"));
	CHECK(T1.relation("Omer") == string("unrelated"));
	CHECK(T1.relation("Yair") == string("unrelated"));
	CHECK(T1.relation("Yasmin") == string("unrelated"));
	CHECK(T1.relation("Oriel") == string("unrelated"));
	CHECK(T1.relation("Amichi") == string("unrelated"));
	


	



}

TEST_CASE("remove ,9 tests") {
	Tree T1("Yosef");
	T1.addFather("Yosef", "Yakov");
	T1.addMother("Yosef", "Rachel");
	T1.addFather("Yakov", "Issac");
	T1.addMother("Yakov", "Rivka");
	T1.addFather("Issac", "Avram");
	T1.addMother("Isaac", "Sara");
	T1.addFather("Avram", "Terah");
	T1.addMother("Avram", "Amtalai");

	CHECK_THROWS(T1.remove("Yosef"));//throw exeption
	T1.remove("Terah");
	CHECK(T1.relation("Terah") == string("unrelated"));
	T1.remove("Amtalai");
	CHECK(T1.relation("Amtalai") == string("unrelated"));
	T1.remove("Avram");
	CHECK(T1.relation("Avram") == string("unrelated"));
	T1.remove("Sara");
	CHECK(T1.relation("Sara") == string("unrelated"));
	T1.remove("Issac");
	CHECK(T1.relation("Issac") == string("unrelated"));
	T1.remove("Rivka");
	CHECK(T1.relation("Rivka") == string("unrelated"));
	T1.remove("Yakov");
	CHECK(T1.relation("Yakov") == string("unrelated"));
	T1.remove("Rachel");
	CHECK(T1.relation("Rachel") == string("unrelated"));
	
	
}
TEST_CASE("43 random tests") {
	Tree T1("Yosef");
	T1.addFather("Yosef", "Yakov");
	T1.addMother("Yosef", "Rachel");
	T1.addFather("Yakov", "Issac");
	T1.addMother("Yakov", "Rivka");
	T1.addFather("Issac", "Avram");
	T1.addMother("Isaac", "Sara");
	T1.addFather("Avram", "Terah");
	T1.addMother("Avram", "Amtalai");

	CHECK(T1.relation("Yosef") == string("me"));
	CHECK(T1.relation("Yakov") == string("father"));
	CHECK(T1.relation("Rachel") == string("mother"));
	CHECK(T1.relation("Rivka") == string("grandmother"));
	CHECK(T1.relation("Issac") == string("grandfather"));
	CHECK(T1.relation("Avram") == string("grand-grandfather"));
	CHECK(T1.relation("Sara") == string("grand-grandmother"));
	CHECK(T1.relation("Terah") == string("grand-grand-grandfather"));
	CHECK(T1.relation("Amtalai") == string("grand-grand-grandmother"));

	CHECK(T1.relation("Yosef") == string("unrelated"));
	CHECK(T1.relation("Konal") == string("unrelated"));
	CHECK(T1.relation("Yter") == string("unrelated"));
	CHECK(T1.relation("Holyo") == string("unrelated"));
	CHECK(T1.relation("Tarev") == string("unrelated"));
	CHECK(T1.relation("Hplo") == string("unrelated"));
	CHECK(T1.relation("Ben") == string("unrelated"));
	CHECK(T1.relation("Avi") == string("unrelated"));
	CHECK(T1.relation("Omer") == string("unrelated"));
	CHECK(T1.relation("Yair") == string("unrelated"));
	CHECK(T1.relation("Yasmin") == string("unrelated"));
	CHECK(T1.relation("Oriel") == string("unrelated"));
	CHECK(T1.relation("Amichi") == string("unrelated"));

	CHECK(T1.relation("Am") == string("unrelated"));
	CHECK(T1.relation("Ami") == string("unrelated"));
	CHECK(T1.relation("Fardes") == string("unrelated"));
	CHECK(T1.relation("Gas") == string("unrelated"));
	CHECK(T1.relation("Pol") == string("unrelated"));
	CHECK(T1.relation("Beny") == string("unrelated"));
	CHECK(T1.relation("Saes") == string("unrelated"));
	CHECK(T1.relation("Bibi") == string("unrelated"));
	CHECK(T1.relation("Bogi") == string("unrelated"));
	CHECK(T1.relation("Dai") == string("unrelated"));
	CHECK(T1.relation("Nimas") == string("unrelated"));
	CHECK(T1.relation("Ly") == string("unrelated"));
	CHECK(T1.relation("Lektov") == string("unrelated"));
	CHECK(T1.relation("Testim") == string("unrelated"));
	CHECK(T1.relation("Al") == string("unrelated"));
	CHECK(T1.relation("Ze") == string("unrelated"));
	CHECK(T1.relation("Bibi") == string("unrelated"));
	CHECK(T1.relation("Bogi") == string("unrelated"));
	CHECK(T1.relation("Dai") == string("unrelated"));
	CHECK(T1.relation("Nimas") == string("unrelated"));
	CHECK(T1.relation("Ly") == string("unrelated"));
	CHECK(T1.relation("Lektov") == string("unrelated"));
	CHECK(T1.relation("Testim") == string("unrelated"));
	CHECK(T1.relation("Al") == string("unrelated"));
	CHECK(T1.relation("Ze") == string("unrelated"));






}



