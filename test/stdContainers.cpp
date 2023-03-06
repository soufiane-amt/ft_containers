/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdContainers.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 23:04:19 by samajat           #+#    #+#             */
/*   Updated: 2023/03/06 23:48:45 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <stack>
#include <vector>

#include <iostream>

int main() 
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

return 0;
}