/* -*- C++ -*- */
// $Id$

// ============================================================================
//
// = LIBRARY
//    ace
// 
// = FILENAME
//    Containers.h
//
// = AUTHOR
//    Doug Schmidt 
// 
// ============================================================================

#if !defined (ACE_CONTAINERS_H)
#define ACE_CONTAINERS_H

#include "ace/ACE.h"

template <class T>
class ACE_Bounded_Stack 
  // = TITLE
  //     Implement a generic LIFO abstract data type.
  //     
  // = DESCRIPTION
  //     This implementation of a Stack uses a bounded array
  //     that is allocated dynamically.
{
public:
  // = Initialization, assignemnt, and termination methods.

  ACE_Bounded_Stack (size_t size);
  // Initialize a new stack so that it is empty. 

  ACE_Bounded_Stack (const ACE_Bounded_Stack<T> &s);
  // The copy constructor (performs initialization). 

  void operator= (const ACE_Bounded_Stack<T> &s);
  // Assignment operator (performs assignment). 

  ~ACE_Bounded_Stack (void); 
 // Perform actions needed when stack goes out of scope. 

  // = Classic Stack operations.

  int push (const T &new_item);
  // Place a new item on top of the stack.  Returns -1 if the stack
  // is already full, 0 if the stack is not already full, and -1 if
  // failure occurs.

  int pop (T &item);
  // Remove and return the top stack item.  Returns -1 if the stack is
  // already empty, 0 if the stack is not already empty, and -1 if
  // failure occurs.

  int top (T &item) const; 
  // Return top stack item without removing it.  Returns -1 if the
  // stack is already empty, 0 if the stack is not already empty, and
  // -1 if failure occurs.

  // = Check boundary conditions.

  int is_empty (void) const;
  // Returns 1 if the container is empty, otherwise returns 0. 

  int is_full (void) const;
  // Returns 1 if the container is full, otherwise returns 0. 

  size_t size (void) const;
  // The number of items in the stack.

  void dump (void) const;
  // Dump the state of an object.

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

private:
  size_t size_;
  // Size of the dynamically allocated data.

  size_t top_; 
  // Keeps track of the current top of stack. 

  T *stack_; 
  // Holds the stack's contents. 
};

//----------------------------------------

template <class T, size_t SIZE>
class ACE_Fixed_Stack 
  // = TITLE
  //     Implement a generic LIFO abstract data type.
  //     
  // = DESCRIPTION
  //     This implementation of a Stack uses a fixed array
  //     with the size fixed at instantiation time.
{
public:
  // = Initialization, assignemnt, and termination methods.
  ACE_Fixed_Stack (void);
  // Initialize a new stack so that it is empty. 

  ACE_Fixed_Stack (const ACE_Fixed_Stack<T, SIZE> &s);
  // The copy constructor (performs initialization). 

  void operator= (const ACE_Fixed_Stack<T, SIZE> &s);
  // Assignment operator (performs assignment). 

  ~ACE_Fixed_Stack (void); 
  // Perform actions needed when stack goes out of scope. 

  // = Classic Stack operations.

  int push (const T &new_item);
  // Place a new item on top of the stack.  Returns -1 if the stack
  // is already full, 0 if the stack is not already full, and -1 if
  // failure occurs.

  int pop (T &item);
  // Remove and return the top stack item.  Returns -1 if the stack is
  // already empty, 0 if the stack is not already empty, and -1 if
  // failure occurs.

  int top (T &item) const; 
  // Return top stack item without removing it.  Returns -1 if the
  // stack is already empty, 0 if the stack is not already empty, and
  // -1 if failure occurs.

  // = Check boundary conditions.

  int is_empty (void) const;
  // Returns 1 if the container is empty, otherwise returns 0. 

  int is_full (void) const;
  // Returns 1 if the container is full, otherwise returns 0. 

  size_t size (void) const;
  // The number of items in the stack.

  void dump (void) const;
  // Dump the state of an object.

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

private:
  size_t size_;
  // Size of the allocated data.

  size_t top_; 
  // Keeps track of the current top of stack. 

  T stack_[SIZE];
  // Holds the stack's contents. 
};

//----------------------------------------

// Forward declarations.
template <class T> class ACE_Unbounded_Set;
template <class T> class ACE_Unbounded_Set_Iterator;
template <class T> class ACE_Unbounded_Queue;
template <class T> class ACE_Unbounded_Queue_Iterator;
template <class T> class ACE_Unbounded_Stack;
template <class T> class ACE_Unbounded_Stack_Iterator;

template<class T>
class ACE_Node
  // = TITLE
  //     Implementation element in a Queue
{
  friend class ACE_Unbounded_Queue<T>;
  friend class ACE_Unbounded_Queue_Iterator<T>;
  friend class ACE_Unbounded_Set<T>;
  friend class ACE_Unbounded_Set_Iterator<T>;
  friend class ACE_Unbounded_Stack<T>;
  friend class ACE_Unbounded_Stack_Iterator<T>;
private:
  // = Initialization methods
  ACE_Node (const T &i, ACE_Node<T> *n);
  ACE_Node (ACE_Node<T> *n = 0, int MS_SUCKS = 0);
  ACE_Node (const ACE_Node<T> &n);

  ~ACE_Node (void);
  // This isn't necessary, but it keeps the compiler happy.

  ACE_Node<T> *next_;
  // Pointer to next element in the list of <ACE_Node>s.

  T item_;
  // Current value of the item in this node.
};

template <class T>
class ACE_Unbounded_Stack 
  // = TITLE
  //     Implement a generic LIFO abstract data type.
  //     
  // = DESCRIPTION
  //     This implementation of an unbounded Stack uses a linked list.
{
  friend class ACE_Unbounded_Stack_Iterator<T>;
public:
  // = Initialization, assignemnt, and termination methods.
  ACE_Unbounded_Stack (void);
  // Initialize a new stack so that it is empty. 

  ACE_Unbounded_Stack (const ACE_Unbounded_Stack<T> &s);
  // The copy constructor (performs initialization). 

  void operator= (const ACE_Unbounded_Stack<T> &s);
  // Assignment operator (performs assignment). 

  ~ACE_Unbounded_Stack (void); 
  // Perform actions needed when stack goes out of scope. 

  // = Classic Stack operations.

  int push (const T &new_item);
  // Place a new item on top of the stack.  Returns -1 if the stack
  // is already full, 0 if the stack is not already full, and -1 if
  // failure occurs.

  int pop (T &item);
  // Remove and return the top stack item.  Returns -1 if the stack is
  // already empty, 0 if the stack is not already empty, and -1 if
  // failure occurs.

  int top (T &item) const; 
  // Return top stack item without removing it.  Returns -1 if the
  // stack is already empty, 0 if the stack is not already empty, and
  // -1 if failure occurs.

  // = Check boundary conditions.

  int is_empty (void) const;
  // Returns 1 if the container is empty, otherwise returns 0. 

  int is_full (void) const;
  // Returns 1 if the container is full, otherwise returns 0. 

  // = Auxiliary methods (not strictly part of the Stack ADT).

  int insert (const T &new_item);
  // Insert <new_item> into the Stack at the head (but doesn't allow
  // duplicates).  Returns -1 if failures occur, 1 if item is already
  // present, else 0.
  
  int remove (const T &item);
  // Remove <item> from the Stack.  Returns 0 if it removes the item,
  // -1 if it can't find the item, and -1 if a failure occurs.

  int find (const T &item) const;
  // Finds if <item> occurs the set.  Returns 0 if finds, else -1.

  size_t size (void) const;
  // The number of items in the stack.

  void dump (void) const;
  // Dump the state of an object.

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

private:
  void delete_all_nodes (void);
  // Delete all the nodes in the stack.

  void copy_all_nodes (const ACE_Unbounded_Stack<T> &s);
  // Copy all nodes from <s> to <this>.

  ACE_Node<T> *head_;
   // Head of the linked list of Nodes.

  size_t cur_size_;
  // Current size of the stack.
};

template <class T>
class ACE_Unbounded_Stack_Iterator
  // = TITLE
  //     Implement an iterator over an unbounded Stack.
{
public:
  // = Initialization method.
  ACE_Unbounded_Stack_Iterator (ACE_Unbounded_Stack<T> &);

  // = Iteration methods.

  int next (T *&next_item);
  // Pass back the <next_item> that hasn't been seen in the Stack.
  // Returns 0 when all items have been seen, else 1.

  int advance (void);
  // Move forward by one element in the Stack.  Returns 0 when all the
  // items in the Stack have been seen, else 1.

  int done (void) const;
  // Returns 1 when all items have been seen, else 0.

  void dump (void) const;
  // Dump the state of an object.

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

private:
  ACE_Node<T> *current_;
  // Pointer to the current node in the iteration.

  ACE_Unbounded_Stack<T> &stack_;
  // Pointer to the Stack we're iterating over.
};

template <class T>
class ACE_Unbounded_Queue;

template <class T>
class ACE_Unbounded_Queue_Iterator
  // = TITLE
  //     Implement an iterator over an unbounded queue.
{
public:
  // = Initialization method.
  ACE_Unbounded_Queue_Iterator (ACE_Unbounded_Queue<T> &);

  // = Iteration methods.

  int next (T *&next_item);
  // Pass back the <next_item> that hasn't been seen in the queue.
  // Returns 0 when all items have been seen, else 1.

  int advance (void);
  // Move forward by one element in the set.  Returns 0 when all the
  // items in the queue have been seen, else 1.

  int done (void) const;
  // Returns 1 when all items have been seen, else 0.

  void dump (void) const;
  // Dump the state of an object.

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

private:
  ACE_Node<T> *current_;
  // Pointer to the current node in the iteration.

  ACE_Unbounded_Queue<T> &queue_;
  // Pointer to the queue we're iterating over.
};

template <class T>
class ACE_Unbounded_Queue
  // = TITLE
  //     A Queue of "infinite" length.
  //
  // = DESCRIPTION
  //     This implementation of an unbounded queue uses a circular
  //     linked list with a dummy node.
{
  friend class ACE_Unbounded_Queue_Iterator<T>;
public:
  // = Initialization and termination methods.
  ACE_Unbounded_Queue (void);
  // construction.

  ACE_Unbounded_Queue (const ACE_Unbounded_Queue<T> &);
  // Copy constructor. 

  void operator= (const ACE_Unbounded_Queue<T> &);
  // Assignment operator.

  ~ACE_Unbounded_Queue (void);
  // construction.

  // = Check boundary conditions.

  int is_empty (void) const;
  // Returns 1 if the container is empty, otherwise returns 0. 

  int is_full (void) const;
  // Returns 1 if the container is full, otherwise returns 0. 

  // = Classic queue operations.

  int enqueue_tail (const T &new_item);
  // Adds <new_item> to the tail of the queue.  Returns 0 on success,
  // -1 on failure.

  int enqueue_head (const T &new_item);
  // Adds <new_item> to the head of the queue.  Returns 0 on success,
  // -1 on failure.

  int dequeue_head (T &item);
  // Removes and returns the first <item> on the queue.  Returns 0 on
  // success, -1 if the queue was empty.

  // = Additional utility methods.

  void reset (void);
  // Reset the <ACE_Unbounded_Queue> to be empty.

  int get (T *&item, size_t index = 0) const;
  // Get the <index>th element in the set.  Returns -1 if the element
  // isn't in the range <0..size() - 1>, else 0.

  int set (const T &item, size_t index);
  // Set the <index>th element in the set.  Will pad out the set with
  // empty nodes if <index> is beyond the range <0..size() - 1>.
  // Returns -1 on failure, 0 if <index> isn't initially in range, and
  // 0 otherwise.

  size_t size (void) const;
  // The number of items in the queue.

  void dump (void) const;
  // Dump the state of an object.

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

protected:
  void delete_nodes (void);
  // Delete all the nodes in the queue.

  void copy_nodes (const ACE_Unbounded_Queue<T> &);
  // Copy nodes into this queue.

  ACE_Node<T> *head_;
  // Pointer to the dummy node in the circular linked Queue.

  size_t cur_size_;
  // Current size of the queue.
};

template <class T>
class ACE_Unbounded_Set_Iterator
  // = TITLE
  //     Implement an iterator over an unbounded set.
{
public:
  // = Initialization method.
  ACE_Unbounded_Set_Iterator (ACE_Unbounded_Set<T> &s);

  // = Iteration methods.

  int next (T *&next_item);
  // Pass back the <next_item> that hasn't been seen in the Set.
  // Returns 0 when all items have been seen, else 1.

  int advance (void);
  // Move forward by one element in the set.  Returns 0 when all the
  // items in the set have been seen, else 1.

  int done (void) const;
  // Returns 1 when all items have been seen, else 0.

  void dump (void) const;
  // Dump the state of an object.

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

private:
  ACE_Node<T> *current_;
  // Pointer to the current node in the iteration.

  ACE_Unbounded_Set<T> &set_;
  // Pointer to the set we're iterating over.
};

template <class T>
class ACE_Unbounded_Set
  // = TITLE
  //     Implement a simple unordered set of <T> of unbounded size.
  //     
  // = DESCRIPTION
  //     This implementation of an unordered set uses a circular
  //     linked list with a dummy node.  This implementation does not
  //     allow duplicates.
{
friend class ACE_Unbounded_Set_Iterator<T>;
public:
  // = Initialization and termination methods.
  ACE_Unbounded_Set (void);
  // Constructor.

  ACE_Unbounded_Set (const ACE_Unbounded_Set<T> &);
  // Copy constructor. 

  void operator= (const ACE_Unbounded_Set<T> &);
  // Assignment operator.

  ~ACE_Unbounded_Set (void);
  // Destructor.

  // = Check boundary conditions.

  int is_empty (void) const;
  // Returns 1 if the container is empty, otherwise returns 0. 

  int is_full (void) const;
  // Returns 1 if the container is full, otherwise returns 0. 

  // = Classic unordered set operations.

  int insert (const T &new_item);
  // Insert <new_item> into the set (doesn't allow duplicates).
  // Returns -1 if failures occur, 1 if item is already present, else
  // 0.
  
  int remove (const T &item);
  // Remove first occurrence of <item> from the set.  Returns 0 if
  // it removes the item, -1 if it can't find the item, and -1 if a
  // failure occurs.

  int find (const T &item) const;
  // Finds if <item> occurs in the set.  Returns 0 if find succeeds,
  // else -1.

  size_t size (void) const;
  // Size of the set.

  void dump (void) const;
  // Dump the state of an object.

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

private:
  int insert_tail (const T &item);
  // Insert <item> at the tail of the set (doesn't check for
  // duplicates).

  void delete_nodes (void);
  // Delete all the nodes in the Set.

  void copy_nodes (const ACE_Unbounded_Set<T> &);
  // Copy nodes into this set.

  ACE_Node<T> *head_;
   // Head of the linked list of Nodes.

  size_t cur_size_;
  // Current size of the set.
};

// Forward declaration.
template <class T, size_t SIZE> 
class ACE_Fixed_Set;

template <class T, size_t SIZE>
class ACE_Fixed_Set_Iterator
  // = TITLE
  //     Interates through an unordered set.
  //     
  // = DESCRIPTION
  //     This implementation of an unordered set uses a fixed array.
  //     Allows deletions while iteration is occurring.
{
public:
  // = Initialization method.
  ACE_Fixed_Set_Iterator (ACE_Fixed_Set<T, SIZE> &s);

  // = Iteration methods.

  int next (T *&next_item);
  // Pass back the <next_item> that hasn't been seen in the Set.
  // Returns 0 when all items have been seen, else 1.

  int advance (void);
  // Move forward by one element in the set.  Returns 0 when all the
  // items in the set have been seen, else 1.

  int done (void) const;
  // Returns 1 when all items have been seen, else 0.

  void dump (void) const;
  // Dump the state of an object.

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

private:
  ACE_Fixed_Set<T, SIZE> &s_; 
  // Set we are iterating over.

  ssize_t next_;
  // How far we've advanced over the set.
};

template <class T, size_t SIZE>
class ACE_Fixed_Set
  // = TITLE
  //     Implement a simple unordered set of <T> with maximum <SIZE>.
  //     
  // = DESCRIPTION
  //     This implementation of an unordered set uses a fixed array.
  //     This implementation does not allow duplicates...
{
friend class ACE_Fixed_Set_Iterator<T, SIZE>;
public:
  // = Initialization and termination methods.
  ACE_Fixed_Set (void);
  // Constructor.

  ACE_Fixed_Set (size_t size);
  // Constructor.

  ACE_Fixed_Set (const ACE_Fixed_Set<T, SIZE> &);
  // Copy constructor. 

  void operator= (const ACE_Fixed_Set<T, SIZE> &);
  // Assignment operator.

  ~ACE_Fixed_Set (void);
  // Destructor.

  // = Check boundary conditions.

  int is_empty (void) const;
  // Returns 1 if the container is empty, otherwise returns 0. 

  int is_full (void) const;
  // Returns 1 if the container is full, otherwise returns 0. 

  // = Classic unordered set operations.

  int insert (const T &new_item);
  // Insert <new_item> into the set (doesn't allow duplicates).
  // Returns -1 if failures occur, 1 if item is already present, else
  // 0.
  
  int remove (const T &item);
  // Remove first occurrence of <item> from the set.  Returns 0 if
  // it removes the item, -1 if it can't find the item, and -1 if a
  // failure occurs.
  
  int find (const T &item) const;
  // Finds if <item> occurs in the set.  Returns 0 if finds, else -1.

  size_t size (void) const;
  // Size of the set.

  void dump (void) const;
  // Dump the state of an object.

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

private:
  struct
  {
    T item_;
    // Item in the set.

    int is_free_;
    // Keeps track of whether this item is in use or not.
  } search_structure_[SIZE];
  // Holds the contents of the set.

  size_t cur_size_;
  // Current size of the set.
  
  size_t max_size_;
  // Maximum size of the set.
};

// Forward declaration.
template <class T> 
class ACE_Bounded_Set;

template <class T>
class ACE_Bounded_Set_Iterator
  // = TITLE
  //     Interates through an unordered set.
  //     
  // = DESCRIPTION
  //     This implementation of an unordered set uses a Bounded array.
  //     Allows deletions while iteration is occurring.
{
public:
  // = Initialization method.
  ACE_Bounded_Set_Iterator (ACE_Bounded_Set<T> &s);

  // = Iteration methods.

  int next (T *&next_item);
  // Pass back the <next_item> that hasn't been seen in the Set.
  // Returns 0 when all items have been seen, else 1.

  int advance (void);
  // Move forward by one element in the set.  Returns 0 when all the
  // items in the set have been seen, else 1.

  int done (void) const;
  // Returns 1 when all items have been seen, else 0.

  void dump (void) const;
  // Dump the state of an object.

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

private:
  ACE_Bounded_Set<T> &s_; 
  // Set we are iterating over.

  ssize_t next_;
  // How far we've advanced over the set.
};

template <class T>
class ACE_Bounded_Set
  // = TITLE
  //     Implement a simple unordered set of <T> with maximum 
  //     set at creation time.
  // 
  // = DESCRIPTION
  //     This implementation of an unordered set uses a Bounded array.
  //     This implementation does not allow duplicates...
{
friend class ACE_Bounded_Set_Iterator<T>;
public:
  enum 
  {
    DEFAULT_SIZE = 10
  };

  // = Initialization and termination methods.
  ACE_Bounded_Set (void);
  // Constructor.

  ACE_Bounded_Set (size_t size);
  // Constructor.

  ACE_Bounded_Set (const ACE_Bounded_Set<T> &);
  // Copy constructor. 

  void operator= (const ACE_Bounded_Set<T> &);
  // Assignment operator.

  ~ACE_Bounded_Set (void);
  // Destructor

  // = Check boundary conditions.

  int is_empty (void) const;
  // Returns 1 if the container is empty, otherwise returns 0. 

  int is_full (void) const;
  // Returns 1 if the container is full, otherwise returns 0. 

  // = Classic unordered set operations.

  int insert (const T &new_item);
  // Insert <new_item> into the set (doesn't allow duplicates).
  // Returns -1 if failures occur, 1 if item is already present, else
  // 0.
  
  int remove (const T &item);
  // Remove first occurrence of <item> from the set.  Returns 0 if it
  // removes the item, -1 if it can't find the item, and -1 if a
  // failure occurs.
  
  int find (const T &item) const;
  // Finds if <item> occurs in the set.  Returns 0 if finds, else -1.

  size_t size (void) const;
  // Size of the set.

  void dump (void) const;
  // Dump the state of an object.

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

private:
  struct Search_Structure
  {
    T item_;
    // Item in the set.

    int is_free_;
    // Keeps track of whether this item is in use or not.
  };

  Search_Structure *search_structure_;
  // Holds the contents of the set.

  size_t cur_size_;
  // Current size of the set.
  
  size_t max_size_;
  // Maximum size of the set.
};

#if defined (__ACE_INLINE__)
#include "ace/Containers.i"
#endif /* __ACE_INLINE__ */

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Containers.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Containers.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#endif /* ACE_CONTAINERS_H */
