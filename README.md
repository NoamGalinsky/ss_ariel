#ReadMe
in this file i will explain all my function in my project
##data_structure
in adta_structure.hpp i was declare about all my data structure and there function,
in addition i was add the implemention of DynamicList and Pair becose there are using template.
###DynamicList
i build the DynamicList with dinamic array of T
resize():
  when the array is full we add size*2 to our array
constructor
  we build new array of size 10
operator= 
  copy all the other component to the original
add()
  add new element to the DinamicList
getNumOfElements()
  return the num of elements in the array
remove()
  delete the last element in the DinamicList
remove(index)
  delete the element in the index place
get(index)
  return reference of the element in the index place
isEmpty()
return if our DynamicList is empty or not
###Pair
object of key and value
the function of pair is very simple, only geter and seter
###Edge
edge is consist from 3 integer while the first is for the origin the second is for destination and the fhird is for wegiht
get() set()
geter and seter
operator= and operator==
is for to copy edge and check if 2 edges are equal
relax()
for dijekstra, check if the destination of some edge from the start vertx is greater from the destination of is negiboor + there weight
and change if it is
###Myqueue
represent a queue with only the function i need
put()
  add element in the last place of my queue
get()
  get the first element that we put in the queue and deleted him
empty()
  return true if the queue is empty
###MyStack
  represent a stack with only the function i need
push()
  add element to my stack
peek()
  retern the last element we puse the stack
empty()
  return true if the stack is empty
remove()
  delete the last elemnt we pushed
###PriorityQueue
is priority queue for edge while the edge element are
origin - the index of the vetex
weight - the disstance from the start vertex
that sort the vertexes by there weight
add, empty and getSize are very basic and simple function
extractMin()
  going thrue all the element and return and delete the vertex with the minimum wehit
###unionFind
is build from Pair, while the
key - group number
value - vertex number
add()
  adding new item with new key
find()
  return the group number of some vertex
make union()
  get 2 group and union them 
