#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include<iostream>
#include "DoorClass.cpp"
using namespace std;

string key = "1234"; 

string testOPEN(){
    DOOR door = DOOR(key);
    
    return door.OPEN(key);
}
TEST_CASE("Test case 1"){
	REQUIRE(testOPEN() == "La puerta a sido abierta.");
}
string testCLOSE(){
    DOOR door = DOOR(key);
    
    return door.CLOSE();
}
TEST_CASE("Test case 2"){
	REQUIRE(testCLOSE() == "La puerta ya esta cerrada.");
}
string testUNLOCKED(){
    DOOR door = DOOR(key);
    
    return door.UNLOCKED(key);
}
TEST_CASE("Test case 3"){
	REQUIRE(testUNLOCKED() == "La puerta ya esta desbloqueada.");
}
string testLOCK(){
    DOOR door = DOOR(key);
    
    return door.LOCK(key);
}
TEST_CASE("Test case 4"){
	REQUIRE(testLOCK() == "La puerta a sido bloqueada.");
}
bool testISOPEN(){
    DOOR door = DOOR(key);
    
    return door.ISOPEN();
}
TEST_CASE("Test case 5"){
	REQUIRE(testISOPEN() == false);
}
bool testISCLOSE(){
    DOOR door = DOOR(key);
    
    return door.ISCLOSE();
}
TEST_CASE("Test case 6"){
	REQUIRE(testISCLOSE() == true);
}
bool testISLOCK(){
    DOOR door = DOOR(key);
    
    return door.ISLOCK();
}
TEST_CASE("Test case 7"){
	REQUIRE(testISLOCK() == false);
}
bool testISUNLOCK(){
    DOOR door = DOOR(key);
    
    return door.ISUNLOCK();
}
TEST_CASE("Test case 8"){
	REQUIRE(testISUNLOCK() == true);
}
string testOpenAndUnlocked(){
    DOOR door = DOOR(key);
    
    return door.OpenAndUnlocked(door, key);
}
TEST_CASE("Test case 9"){
	REQUIRE(testOpenAndUnlocked() == "La puerta ya esta abierta o desbloqueada");
}
string testOpenAndLocked(){
    DOOR door = DOOR(key);
    
    return door.OpenAndLocked(door, key);
}
TEST_CASE("Test case 10"){
	REQUIRE(testOpenAndLocked() == "La puerta a sido abierta. and La puerta a sido bloqueada.");
}
string testClosedAndUnlocked(){
    DOOR door = DOOR(key);
    
    return door.ClosedAndUnlocked(door, key);
}
TEST_CASE("Test case 11"){
	REQUIRE(testClosedAndUnlocked() == "La puerta ya esta cerrada o desbloqueada");
}
string testClosedAndLocked(){
    DOOR door = DOOR(key);
    
    return door.ClosedAndLocked(door, key);
}
TEST_CASE("Test case 12"){
	REQUIRE(testClosedAndLocked() == "La puerta ya esta cerrada o bloqueada");
}
