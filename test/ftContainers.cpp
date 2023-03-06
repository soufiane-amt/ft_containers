/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftContainers.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 23:04:17 by samajat           #+#    #+#             */
/*   Updated: 2023/03/06 23:48:32 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/containers/map.hpp"
#include "../includes/containers/stack.hpp"
#include "../includes/containers/vector.hpp"


int main() 
{
  // Create an empty vector
  ft::vector<int> ftVect;

  // Add elements to the vector
  ftVect.push_back(1);
  ftVect.push_back(2);
  ftVect.push_back(3);
  ftVect.push_back(4);

  // Print the elements of the vector using iterator
  std::cout << "Elements : ";
  for (ft::vector<int>::iterator it = ftVect.begin(); it != ftVect.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  // Get the size of the vector
  std::cout << "Size of ftVect: " << ftVect.size() << std::endl;

  // Resize the vector
  ftVect.resize(6, 0);

  // Print the elements of the vector again
  std::cout << "Elements  after resize: ";
  for (ft::vector<int>::iterator it = ftVect.begin(); it != ftVect.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  // Get the maximum size of the vector
  std::cout << "Maximum size of ftVect: " << ftVect.max_size() << std::endl;

  // Reserve space for elements in the vector
  ftVect.reserve(10);

  // Get the capacity of the vector
  std::cout << "Capacity of ftVect: " << ftVect.capacity() << std::endl;

  // Check if the vector is empty
  std::cout << "Is ftVect empty?: " << (ftVect.empty() ? "yes" : "no") << std::endl;

  // Access elements of the vector using operator []
  std::cout << "Element at index 2 of ftVect: " << ftVect[2] << std::endl;

  // Access elements of the vector using at()
  std::cout << "Element at index 3 of ftVect using at(): " << ftVect.at(3) << std::endl;

  // Get the first element of the vector
  std::cout << "First element of ftVect: " << ftVect.front() << std::endl;

  // Get the last element of the vector
  std::cout << "Last element of ftVect: " << ftVect.back() << std::endl;

  // Assign a value to all the elements in the vector
  ftVect.assign(6, 5);

  // Print the elements of the vector again
  std::cout << "Elements  after assign: ";
  for (ft::vector<int>::iterator it = ftVect.begin(); it != ftVect.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  // Insert an element at a specific position
  ftVect.insert(ftVect.begin() + 2, 7);

  // Print the elements of the vector again
  std::cout << "Elements  after insert: ";
  for (ft::vector<int>::iterator it = ftVect.begin(); it != ftVect.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  // Erase an element at a specific position
  ftVect.erase(ftVect.begin() + 3);

  // Print the elements of the
std::cout << "Elements   after erase: ";
for (ft::vector<int>::iterator it = ftVect .begin(); it != ftVect .end(); ++it) {
std::cout << *it << " ";
}
std::cout << std::endl;

// Clear all the elements from the vector
ftVect .clear();

// Print the elements of the vector again
std::cout << "Elements   after clear: ";
for (ft::vector<int>::iterator it = ftVect .begin(); it != ftVect .end(); ++it) {
std::cout << *it << " ";
}
std::cout << std::endl;

// Create a new vector
ft::vector<int> anotherVec;

// Add some elements to the new vector
anotherVec.push_back(10);
anotherVec.push_back(20);
anotherVec.push_back(30);

// Swap the contents of the two vectors
ftVect .swap(anotherVec);

// Print the elements of the first vector after swap
std::cout << "Elements   after swap: ";
for (ft::vector<int>::iterator it = ftVect .begin(); it != ftVect .end(); ++it) {
std::cout << *it << " ";
}
std::cout << std::endl;

// Print the elements of the second vector after swap
std::cout << "Elements of anotherVec after swap: ";
for (ft::vector<int>::iterator it = anotherVec.begin(); it != anotherVec.end(); ++it) {
std::cout << *it << " ";
}
std::cout << std::endl;

// Check the type of the allocator used by the vector
ft::vector<int>::allocator_type myAllocator = ftVect .get_allocator();
std::cout << "Type of the allocator used by ftVect : " << typeid(myAllocator).name() << std::endl;

// Get iterators to the beginning and end of the vector
ft::vector<int>::iterator itBegin = ftVect .begin();
ft::vector<int>::iterator itEnd = ftVect .end();

// Get const iterators to the beginning and end of the vector
ft::vector<int>::const_iterator constItBegin = ftVect .begin();
ft::vector<int>::const_iterator constItEnd = ftVect .end();

// Get reverse iterators to the beginning and end of the vector
ft::vector<int>::reverse_iterator rItBegin = ftVect .rbegin();
ft::vector<int>::reverse_iterator rItEnd = ftVect .rend();

// Get const reverse iterators to the beginning and end of the vector
ft::vector<int>::const_reverse_iterator constRItBegin = ftVect .rbegin();
ft::vector<int>::const_reverse_iterator constRItEnd = ftVect .rend();

return 0;
}