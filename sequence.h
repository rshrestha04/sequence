/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sequence.h
 * Author: Ronish Shrestha
 *
 * Created on February 1, 2018, 7:33 PM
 */

#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <cstdlib>

namespace csis3700{
    class sequence{
        
        
        public:
            typedef char value_type;
            static const std::size_t CAPACITY =100;
            
            sequence();
            std::size_t size() const;
            const value_type& at(std::size_t i) const;
            void add(const value_type& i);
            void insert(std::size_t index, const value_type& value);
            void remove(std::size_t index);
            
            
            void operator+=(const sequence& other);
        
        
        private:
            
           
           value_type items[CAPACITY];
           std ::size_t used;
        };
    
    sequence operator +(const sequence& s1,const sequence& s2);
}



#endif /* SEQUENCE_H */

