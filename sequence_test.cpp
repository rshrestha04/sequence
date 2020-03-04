/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "sequence.h"
#include <iostream>

using namespace std;
using namespace csis3700;

TEST_CASE("default size should be zero","[sequence]"){
    sequence a;
    REQUIRE (a.size()==0);
    
}

TEST_CASE("adding elements to sequence ","[sequence]"){
    sequence a;
    a.add(1);
    a.add(4);
    a.add(-2);
    REQUIRE (a.size()==3);
    REQUIRE (a.at(1)==4);
    REQUIRE (a.at(2)==-2);
    REQUIRE (a.at(0)==1);
    
}


TEST_CASE("inserting elements to sequence ","[sequence]"){
    sequence a;
    a.add(1);
    a.add(4);
    a.add(-2);
    a.insert(2,3);
    REQUIRE (a.size()==4);
    REQUIRE (a.at(1)==4);
    REQUIRE (a.at(2)==3);
    REQUIRE (a.at(3)==-2);
    
}

TEST_CASE("removing elements from sequence ","[sequence]"){
    sequence a;
    a.add(1);
    a.add(4);
    a.add(-2);
    a.insert(2,3);
    a.remove(0);
    REQUIRE (a.size()==3);
    REQUIRE (a.at(1)==3);
    REQUIRE (a.at(2)==-2);
    REQUIRE (a.at(0)==4);
    
    
}

TEST_CASE("using += sign","[sequence]"){
    sequence a;
    sequence b;
    a.add(0);
    a.add(1);
    a.add(2);
    b.add(3);
    b.add(4);
    b.add(5);
    a+=b;
    REQUIRE(a.size()==6);
    REQUIRE(a.at(3)==3);
    REQUIRE(a.at(4)==4);
}

TEST_CASE("addition operator working","[sequence]"){
    sequence a;
    sequence b,c;
    a.add(0);
    a.add(1);
    a.add(2);
    b.add(-3);
    b.add(-4);
    b.add(-5);
    c=a+b;
    REQUIRE(a.size()==3);
    REQUIRE(b.size()==3);
    REQUIRE(c.size()==6);
    REQUIRE(a.at(0)==0);
    REQUIRE(a.at(1)==1);
    REQUIRE(a.at(2)==2);
    REQUIRE(b.at(0)==-3);
    REQUIRE(b.at(1)==-4);
    REQUIRE(b.at(2)==-5);
    REQUIRE(c.at(0)==0);
    REQUIRE(c.at(1)==1);
    REQUIRE(c.at(2)==2);
    REQUIRE(c.at(3)==-3);
    REQUIRE(c.at(4)==-4);
    REQUIRE(c.at(5)==-5);

}

TEST_CASE("adding to empty sequence","[sequence]"){
    sequence a;
    sequence b;
    a.add(0);
    a.add(1);
    a.add(2);
    b+=a;
    REQUIRE (b.size()==3);
    REQUIRE (b.at(0)==0);
}

TEST_CASE("Shifting","[sequence]"){
    sequence s1;
    for(int x=0;x<100;x++){
        s1.insert(0,x);
    }
   
    REQUIRE(s1.at(0)==99);
    REQUIRE(s1.at(1)==98);
    
}

TEST_CASE("removing a single data","[sequence]"){
    sequence a;
    a.add(1);
    REQUIRE(a.size()==1);
    a.remove(0);
    REQUIRE( a.size()==0);
}


TEST_CASE("inserting at 0 in a used sequence"){
    sequence a;
    a.add(1);
    a.add(2);
    a.insert(0,0);
    REQUIRE(a.at(0)==0);
    REQUIRE(a.at(1)==1);
    REQUIRE(a.at(2)==2);
    REQUIRE(a.size()==3);
}

TEST_CASE("Given TEST CASES","[sequence]"){
    sequence s1 ; // [ ]
    s1.add( 5 ) ; // [ 5 ]
    s1.add( 9 ) ; // [ 5 , 9 ]
    s1.add( 2 ) ; // [ 5 , 9 , 2 ]
    s1.insert(1,15) ; // [ 5 , 1 5 , 9 , 2 ]
    s1.remove( 0 ) ; // [ 1 5 , 9 , 2 ]
    
    REQUIRE(s1.at(0)==15);
    REQUIRE(s1.size()== 3);
    s1.insert(0,3) ; // [ 3 , 1 5 , 9 , 2 ]
    s1.insert(0,22) ; // [ 2 2 , 3 , 1 5 , 9 , 2 ]
    
    sequence s2 ;
    s2.add( 7 ) ; // s2 = [ 7 ]
    s2.add( 5 ) ; // s2 = [ 7 , 5 ]
    sequence s3 = s1 + s2 ; // s3 = [ 1 7 , 3 , 1 5 , 9 , 2 , 7 , 5 ]
    REQUIRE(s3.at(0)==22);
    REQUIRE(s3.at(1)==3);
    REQUIRE(s3.at(2)==15);
    REQUIRE(s3.at(3)==9);
    REQUIRE(s3.at(4)==2);
    REQUIRE(s3.at(5)==7);
    REQUIRE(s3.at(6)==5);
    sequence s4;
    s4.add(1) ; // s4 = [ 1 ]
    s4+= s2 ; // s4 = [ 1 , 7 , 5 ]
    REQUIRE(s4.at(0)==1);
    REQUIRE(s4.at(1)==7);
    REQUIRE(s4.at(2)==5);
}




