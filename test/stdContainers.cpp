/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdContainers.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 23:04:19 by samajat           #+#    #+#             */
/*   Updated: 2023/03/06 23:56:10 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <stack>
#include <vector>

#include <iostream>


static void    test_map()
{
#include <iostream>
#include <map>

int main() {
    // Constructors
    std::map<int, char> map1;
    std::map<int, char> map2(map1);
    std::map<int, char, std::greater<int> > map3;
    std::map<int, char>::iterator it;
    for (int i = 0; i < 10; i++) {
        map3.insert(std::make_pair(i, 'a' + i));
    }
    std::map<int, char> map4(map3.begin(), map3.end());
    
    // Modifiers
    it = map1.insert(std::make_pair(1, 'a')).first;
    map1.insert(it, std::make_pair(2, 'b'));
    map1.insert(std::make_pair(3, 'c'));
    std::cout << "Map1 size after insertion: " << map1.size() << std::endl;
    map1.erase(2);
    std::cout << "Map1 size after erasing element with key 2: " << map1.size() << std::endl;
    map1.erase(map1.begin(), it);
    std::cout << "Map1 size after erasing elements up to key 1: " << map1.size() << std::endl;
    map1.clear();
    std::cout << "Map1 size after clearing: " << map1.size() << std::endl;
    map1[1] = 'a';
    std::cout << "Map1 value at key 1: " << map1[1] << std::endl;
    map1.swap(map4);
    std::cout << "Map1 size after swapping: " << map1.size() << std::endl;
    
    // Capacity
    std::cout << "Map1 empty? " << (map1.empty() ? "Yes" : "No") << std::endl;
    std::cout << "Map1 size: " << map1.size() << std::endl;
    std::cout << "Map1 max size: " << map1.max_size() << std::endl;
    
    // Element Access
    std::cout << "Map1 value at key 1: " << map1[1] << std::endl;
    std::cout << "Map1 value at key 2: " << map1.at(2) << std::endl;
    std::cout << "Map1 value at key 3: " << map1[3] << std::endl;
    
    // Lookup
    it = map1.find(3);
    if (it != map1.end()) {
        std::cout << "Map1 found element with key 3: " << it->second << std::endl;
    }
    std::cout << "Map1 count of elements with key 1: " << map1.count(1) << std::endl;
    std::cout << "Map1 count of elements with key 2: " << map1.count(2) << std::endl;
    std::cout << "Map1 count of elements with key 3: " << map1.count(3) << std::endl;
    it = map1.lower_bound(5);
    if (it != map1.end()) {
        std::cout << "Map1 lower bound for key 5: " << it->second << std::endl;
    }
    it = map1.upper_bound(5);
    if (it != map1.end()) {
        std::cout << "Map1 upper bound for key 5: " << it->second << std::endl;
        }
    std::pair<std::map<int, char>::iterator, std::map<int, char>::iterator> pair_it = map1.equal_range(3);
    std::cout << "Map1 equal range for key 3: " << pair_it.first->second << "-" << pair_it.second->second << std::endl;
    // Operations
    std::cout << "Map1 size before swapping with map2: " << map1.size() << std::endl;
    map1.swap(map2);
    std::cout << "Map1 size after swapping with map2: " << map1.size() << std::endl;
    std::cout << "Map1 and Map4 are " << (map1 == map4 ? "equal" : "not equal") << std::endl;

}



static void    test_vector ()
{
      // Create an empty vector
      std::vector<int> stlVect;
    
      // Add elements to the vector
      stlVect.push_back(1);
      stlVect.push_back(2);
      stlVect.push_back(3);
      stlVect.push_back(4);
    
      // Print the elements of the vector using iterator
      std::cout << "Elements : ";
      for (std::vector<int>::iterator it = stlVect.begin(); it != stlVect.end(); ++it) {
        std::cout << *it << " ";
      }
      std::cout << std::endl;
    
      // Get the size of the vector
      std::cout << "Size of stlVect: " << stlVect.size() << std::endl;
    
      // Resize the vector
      stlVect.resize(6, 0);
    
      // Print the elements of the vector again
      std::cout << "Elements  after resize: ";
      for (std::vector<int>::iterator it = stlVect.begin(); it != stlVect.end(); ++it) {
        std::cout << *it << " ";
      }
      std::cout << std::endl;
    
      // Get the maximum size of the vector
      std::cout << "Maximum size of stlVect: " << stlVect.max_size() << std::endl;
    
      // Reserve space for elements in the vector
      stlVect.reserve(10);
    
      // Get the capacity of the vector
      std::cout << "Capacity of stlVect: " << stlVect.capacity() << std::endl;
    
      // Check if the vector is empty
      std::cout << "Is stlVect empty?: " << (stlVect.empty() ? "yes" : "no") << std::endl;
    
      // Access elements of the vector using operator []
      std::cout << "Element at index 2 of stlVect: " << stlVect[2] << std::endl;
    
      // Access elements of the vector using at()
      std::cout << "Element at index 3 of stlVect using at(): " << stlVect.at(3) << std::endl;
    
      // Get the first element of the vector
      std::cout << "First element of stlVect: " << stlVect.front() << std::endl;
    
      // Get the last element of the vector
      std::cout << "Last element of stlVect: " << stlVect.back() << std::endl;
    
      // Assign a value to all the elements in the vector
      stlVect.assign(6, 5);
    
      // Print the elements of the vector again
      std::cout << "Elements  after assign: ";
      for (std::vector<int>::iterator it = stlVect.begin(); it != stlVect.end(); ++it) {
        std::cout << *it << " ";
      }
      std::cout << std::endl;
    
      // Insert an element at a specific position
      stlVect.insert(stlVect.begin() + 2, 7);
    
      // Print the elements of the vector again
      std::cout << "Elements  after insert: ";
      for (std::vector<int>::iterator it = stlVect.begin(); it != stlVect.end(); ++it) {
        std::cout << *it << " ";
      }
      std::cout << std::endl;
    
      // Erase an element at a specific position
      stlVect.erase(stlVect.begin() + 3);
    
      // Print the elements of the
    std::cout << "Elements   after erase: ";
    for (std::vector<int>::iterator it = stlVect .begin(); it != stlVect .end(); ++it) {
    std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // Clear all the elements from the vector
    stlVect .clear();
    
    // Print the elements of the vector again
    std::cout << "Elements   after clear: ";
    for (std::vector<int>::iterator it = stlVect .begin(); it != stlVect .end(); ++it) {
    std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // Create a new vector
    std::vector<int> anotherVec;
    
    // Add some elements to the new vector
    anotherVec.push_back(10);
    anotherVec.push_back(20);
    anotherVec.push_back(30);
    
    // Swap the contents of the two vectors
    stlVect .swap(anotherVec);
    
    // Print the elements of the first vector after swap
    std::cout << "Elements   after swap: ";
    for (std::vector<int>::iterator it = stlVect .begin(); it != stlVect .end(); ++it) {
    std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // Print the elements of the second vector after swap
    std::cout << "Elements of anotherVec after swap: ";
    for (std::vector<int>::iterator it = anotherVec.begin(); it != anotherVec.end(); ++it) {
    std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // Check the type of the allocator used by the vector
    std::vector<int>::allocator_type myAllocator = stlVect .get_allocator();
    std::cout << "Type of the allocator used by stlVect : " << typeid(myAllocator).name() << std::endl;
    
    // Get iterators to the beginning and end of the vector
    std::vector<int>::iterator itBegin = stlVect .begin();
    std::vector<int>::iterator itEnd = stlVect .end();
    
    // Get const iterators to the beginning and end of the vector
    std::vector<int>::const_iterator constItBegin = stlVect .begin();
    std::vector<int>::const_iterator constItEnd = stlVect .end();
    
    // Get reverse iterators to the beginning and end of the vector
    std::vector<int>::reverse_iterator rItBegin = stlVect .rbegin();
    std::vector<int>::reverse_iterator rItEnd = stlVect .rend();
    
    // Get const reverse iterators to the beginning and end of the vector
    std::vector<int>::const_reverse_iterator constRItBegin = stlVect .rbegin();
    std::vector<int>::const_reverse_iterator constRItEnd = stlVect .rend();

}
int main() 
{
    test_vector ();
    return 0;
}