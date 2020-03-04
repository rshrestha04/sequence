/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "sequence.h"
#include <iostream>
#include <cassert>





namespace csis3700{
    sequence::sequence(){
        used=0;
    }
    
     std:: size_t sequence::size() const{
        return used;
    }
    
    const sequence::value_type& sequence::at(std::size_t i) const{
        assert(i<size());
       return items[i];
    }
    
    void sequence::add(const sequence::value_type& i){
        assert(size()<CAPACITY);
        items[used]=i;
        used++;
            
    }
    
    void sequence::insert(std::size_t index, const value_type& value){
        assert (index<=size() and size()<CAPACITY);
        
        
        
        if (used==index){
            add(value);
            return;
        }
       
        std::size_t position= used;
        for(std::size_t x=used; x>index;){
            x--;
            items[position]=items[x];
            position--;
        }
        items[index]=value;
        used++;
    }
    
    void sequence::remove(std::size_t index){
        assert(index<size());
        std:: size_t position = index +1;
        for (std::size_t x=index; x < used; x ++){
            items[x]=items[position];
            position++;
        }
        
        used--;
    }
    //------------------OPERATOR OVERLOADING----------------------// 
    //Member function
    
    void sequence::operator+=(const sequence& other){
        assert (size()+other.size()<=CAPACITY);
        int position = used;
        for(int x= 0; x < other.size();x++){
            items[position]= other.items[x];
            position++;
        }
        
        used= used + other.size();
        }
    // Non- member function
    
    sequence operator +(const sequence& s1,const sequence& s2){
        assert(s1.size()+s2.size()<= 100);
        sequence answer;
        answer +=s1;
        answer +=s2;
        return answer;
    }
    

    
}

