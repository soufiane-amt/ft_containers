/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdContainers.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 23:04:19 by samajat           #+#    #+#             */
/*   Updated: 2023/03/07 10:45:06 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <stack>
#include <vector>
#include <set>

#include <iostream>



static void printSeparation(std::string container)
{
std::cout << "\n\n\n\n/* ************************************************************************** */\n";
std::cout << "                          " << container << std::endl;
std::cout << "/* ************************************************************************** */\n";
}


static void test_set()
{
    // Constructors
    std::set<int> set1;
    std::set<int> set2(set1);
    int arr[] = {1, 2, 3, 4, 5};
    std::set<int> set3(arr, arr + sizeof(arr) / sizeof(int));
    std::set<int> set4;
    std::set<int> set5(set3);
    
    // Modifiers
    set1.insert(1);
    set1.insert(2);
    set1.insert(3);
    set1.erase(2);
    std::cout << "Set1 size after erasing element: " << set1.size() << std::endl;
    set1.clear();
    std::cout << "Set1 size after clearing: " << set1.size() << std::endl;
    std::cout << "Set1 empty after clearing? " << (set1.empty() ? "Yes" : "No") << std::endl;
    set4.swap(set5);
    std::cout << "Set4 size after swapping: " << set4.size() << std::endl;
    
    // Capacity
    std::cout << "Set1 empty? " << (set1.empty() ? "Yes" : "No") << std::endl;
    std::cout << "Set3 size: " << set3.size() << std::endl;
    
    // Element Access
    std::set<int>::iterator it = set3.find(5);
    if (it != set3.end()) {
        std::cout << "Set3 contains element 5" << std::endl;
    }
  }

static  void test_stack ()
{
    // Constructors
    std::stack<int> stack1;
    std::stack<int> stack2(stack1);
    std::stack<int, std::vector<int> > stack3;
    std::stack<int> stack4;
    for (int i = 0; i < 10; i++) {
        stack4.push(i);
    }
    std::stack<int> stack5(stack4);
    
    // Modifiers
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    std::cout << "Stack1 size after pushing elements: " << stack1.size() << std::endl;
    stack1.pop();
    std::cout << "Stack1 size after popping element: " << stack1.size() << std::endl;
    std::cout << "Stack1 top element after popping: " << stack1.top() << std::endl;
    
    // Capacity
    std::cout << "Stack1 empty? " << (stack1.empty() ? "Yes" : "No") << std::endl;
    std::cout << "Stack1 size: " << stack1.size() << std::endl;
    
    // Element Access
    std::cout << "Stack1 top element: " << stack1.top() << std::endl;
}



static void test_map() {
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
    map1.insert (map1.begin(), std::make_pair(1337, 'c'));
    std::cout << "Map1 size after insertion: " << map1.size() << std::endl;
    map1.erase(2);
    std::cout << "Map1 size after erasing element with key 2: " << map1.size() << std::endl;
    map1.erase(map1.begin(), it);
    std::cout << "Map1 size after erasing elements up to key 1: " << map1.size() << std::endl;
    map1.clear();
    std::cout << "Map1 size after clearing: " << map1.size() << std::endl;
    map1.swap(map2);
    map1[1] = 'a';
    map1[2] = 'b';
    map1[3] = 'c';
      // Element Access
    std::cout << "Map1 value at key 1: " << map1[1] << std::endl;
    std::cout << "Map1 value at key 2: " << map1.at(2) << std::endl;
    std::cout << "Map1 value at key 3: " << map1[3] << std::endl;

    std::cout << "Map1 size after swapping: " << map1.size() << std::endl;
    
    // Capacity
    std::cout << "Map1 empty? " << (map1.empty() ? "Yes" : "No") << std::endl;
    std::cout << "Map1 size: " << map1.size() << std::endl;
    std::cout << "Map1 max size: " << map1.max_size() << std::endl;
    
    
    // Lookup
    it = map1.find(1);
    if (it != map1.end()) {
        std::cout << "Map1 found element with key 1: " << it->second << std::endl;
    }
    std::cout << "Map1 count of elements with key 1: " << map1.count(1) << std::endl;
    std::cout << "Map1 count of elements with key 2: " << map1.count(2) << std::endl;
    std::cout << "Map1 count of elements with key 3: " << map1.count(3) << std::endl;
    it = map1.lower_bound(5);
    if (it != map1.end()) {
        std::cout << "Map1 lower bound for key 5: " << it->second << std::endl;
    }
    it = map1.upper_bound(5);
    if (it != map1.end()) 
        std::cout << "Map1 upper bound for key 5: " << it->second << std::endl;

    std::pair<std::map<int, char>::iterator, std::map<int, char>::iterator> pair_it = map1.equal_range(2);
    std::cout << "Map1 equal range for key 2: " << pair_it.first->second << "-" << pair_it.second->second << std::endl;
    // Operations
    std::cout << "Map1 size before swapping with map2: " << map1.size() << std::endl;
    map1.swap(map2);
    std::cout << "Map1 size after swapping with map2: " << map1.size() << std::endl;
    std::cout << "Map1 and Map4 are " << (map1 == map4 ? "equal" : "not equal") << std::endl;

}


static void    test_vector ()
{
      // Create an empty vector
      std::vector<int> Vect;
    
      // Add elements to the vector
      Vect.push_back(1);
      Vect.push_back(2);
      Vect.push_back(3);
      Vect.push_back(4);
    
      // Print the elements of the vector using iterator
      std::cout << "Elements : ";
      for (std::vector<int>::iterator it = Vect.begin(); it != Vect.end(); ++it) {
        std::cout << *it << " ";
      }
      std::cout << std::endl;
    
      // Get the size of the vector
      std::cout << "Size of Vect: " << Vect.size() << std::endl;
    
      // Resize the vector
      Vect.resize(6, 0);
    
      // Print the elements of the vector again
      std::cout << "Elements  after resize: ";
      for (std::vector<int>::iterator it = Vect.begin(); it != Vect.end(); ++it) {
        std::cout << *it << " ";
      }
      std::cout << std::endl;
    
      // Get the maximum size of the vector
      std::cout << "Maximum size of Vect: " << Vect.max_size() << std::endl;
    
      // Reserve space for elements in the vector
      Vect.reserve(10);
    
      // Get the capacity of the vector
      std::cout << "Capacity of Vect: " << Vect.capacity() << std::endl;
    
      // Check if the vector is empty
      std::cout << "Is Vect empty?: " << (Vect.empty() ? "yes" : "no") << std::endl;
    
      // Access elements of the vector using operator []
      std::cout << "Element at index 2 of Vect: " << Vect[2] << std::endl;
    
      // Access elements of the vector using at()
      std::cout << "Element at index 3 of Vect using at(): " << Vect.at(3) << std::endl;
    
      // Get the first element of the vector
      std::cout << "First element of Vect: " << Vect.front() << std::endl;
    
      // Get the last element of the vector
      std::cout << "Last element of Vect: " << Vect.back() << std::endl;
    
      // Assign a value to all the elements in the vector
      Vect.assign(6, 5);
    
      // Print the elements of the vector again
      std::cout << "Elements  after assign: ";
      for (std::vector<int>::iterator it = Vect.begin(); it != Vect.end(); ++it) {
        std::cout << *it << " ";
      }
      std::cout << std::endl;
    
      // Insert an element at a specific position
      Vect.insert(Vect.begin() + 2, 7);
    
      // Print the elements of the vector again
      std::cout << "Elements  after insert: ";
      for (std::vector<int>::iterator it = Vect.begin(); it != Vect.end(); ++it) {
        std::cout << *it << " ";
      }
      std::cout << std::endl;
    
      // Erase an element at a specific position
      Vect.erase(Vect.begin() + 3);
    
      // Print the elements of the
    std::cout << "Elements   after erase: ";
    for (std::vector<int>::iterator it = Vect .begin(); it != Vect .end(); ++it) {
    std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // Clear all the elements from the vector
    Vect .clear();
    
    // Print the elements of the vector again
    std::cout << "Elements   after clear: ";
    for (std::vector<int>::iterator it = Vect .begin(); it != Vect .end(); ++it) {
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
    Vect .swap(anotherVec);
    
    // Print the elements of the first vector after swap
    std::cout << "Elements   after swap: ";
    for (std::vector<int>::iterator it = Vect .begin(); it != Vect .end(); ++it) {
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
    std::vector<int>::allocator_type myAllocator = Vect .get_allocator();
    std::cout << "Type of the allocator used by Vect : " << typeid(myAllocator).name() << std::endl;
    
    // Get iterators to the beginning and end of the vector
    std::vector<int>::iterator itBegin = Vect .begin();
    std::vector<int>::iterator itEnd = Vect .end();
    (void)itBegin;(void)itEnd;

    // Get const iterators to the beginning and end of the vector
    std::vector<int>::const_iterator constItBegin = Vect .begin();
    std::vector<int>::const_iterator constItEnd = Vect .end();
    (void)constItBegin;(void)constItEnd;
    // Get reverse iterators to the beginning and end of the vector
    std::vector<int>::reverse_iterator rItBegin = Vect .rbegin();
    std::vector<int>::reverse_iterator rItEnd = Vect .rend();
    (void)rItBegin;(void)rItEnd;
    // Get const reverse iterators to the beginning and end of the vector
    std::vector<int>::const_reverse_iterator constRItBegin = Vect .rbegin();
    std::vector<int>::const_reverse_iterator constRItEnd = Vect .rend();
    (void)constRItBegin;(void)constRItEnd;
}


int main() 
{
    printSeparation("vector");
    test_vector ();
    printSeparation("map");
    test_map ();
    printSeparation("stack");
    test_stack ();
    printSeparation ("set");
    test_set();

    return 0;
}