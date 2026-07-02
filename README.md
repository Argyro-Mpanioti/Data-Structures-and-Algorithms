## - **main.cpp**

In main.cpp the file commands.txt is read and the commands written in it are executed. Specifically, each line of commands.txt is read and saved in the string *line* until the command that the line contains is executed. When the command gets executed, the process is repeated for the rest of the lines of until there are no other commands in commands.txt.
The content of line is saved in the character array *com*. This is done to allow the use of the function *strstr* later on. After this, there is an if...else if structure that checks which command is in com. According to the command the appropriate actions are executed. The execution time is counted and written in the "output.txt" file.


---

## - **minheap**


### 1. BUILD MINHEAP filename

In main, when the phrase BUILD MINHEAP is detected in a line of "commands.txt" then the name of the file that contains the heap values is saved in the character array filename. The name of the file is the string that follows "BUILD MINHEAP" in commands.txt.
After this, a minheap constructor is called. The parameter of the constructor is the filename. The constructor reads the values of the file called filename and inserts each value in the minheap.

The minheap class has 2 fields:
- *size*: the size of the minheap
- *value*: dynamic array that contains the values of the nodes in the heap

Minheap has the default constructor, that initializes the *size* field as 0 and assigns nullptr to the array *value*.

The method *build* gets as a parameter the name of the file from which it reads the values that should be added in the minheap.
Each value that is read from the file is saved in a string and then turned into an integer with the function "stoi".
After this, it is inserted in the heap with the call of the method *insert*.
If we encounter a problem while opening the file, the message "Couldn't open file." appears.

This constructor and this *build* method exist for all 5 structures of this project.


### 2. INSERT MINHEAP number

In main, when the phrase INSERT MINHEAP is detected in a line of "commands.txt" then the string that follows it is turned into an integer. After this, *insert* is called for minheap. We pass the integer as a paameter to *insert*.


In main:\
We turn the string into an integer and we save it in the variable *number*.
In the variable *number* we save the first character that follows "INSERT MINHEAP " after casting it from ASCII to an integer. After this, we turn it into the integer from of the initial number written on the file by subtracting 48.
Each time we encounter another character that is a number we multiply *number* by 10 and add the new integer after turning it into an integer.
We check whether the value of the node is non-negative. If it is negative then we do nothing. If it is non-negative, we call the method *insert* using *number* as a parameter.

In the method *insert* of the class minheap we insert the integer in the heap:
- We create an array of integers that has the same size as *value* increased by 1. In the array we copy the elements of *value* and add the new element. After this we increase the size of value and copy back the elements of the new array.
- We also increase the size of the heap. The new element is added in the end of the array. However, we need to make sure that the heap continues to be a minheap. We know that when we save a heap in an array, the element in position n has a parent that is in position (n-1)/2.
- Therefore, while the element we add has a value smaller than the value of its parent, we swap those 2 elements and continue checking. When the element has value greater than its parent's value then the process is complete.


### 3. GETSIZE MINHEAP

In main the size of the heap is written in the file "output.txt".
The size of the heap is a private field so in order to use it in main we call the getter getsize.

### 4. FINDMIN MINHEAP

In main the minimum element of the heap is written in the file "output.txt".
The minimum element of the heap is computed with the method findmin. findmin returns the content of the first element of the array *value*. This element is the root of the minheap because this is the root has the minimum value in minheap.


### 5. DELETEMIN MINHEAP

The method deletemin is called for the object minheap. This method deletes the element with the minimum value of minheap, which is the first element of th array *value*.
deletemin assigns the last element of the heap to the first. After that, it reduces the heap's size by 1 and it calls the method "sortdeleted" which performs the necessary swap so that the minheap can continue to be a minheap.
The parameter sortdeleted gets is the position of a parent in the array *value* and it checks whether the child with the smaller value has a value smaller than the parent's value.
If yes, then it swaps the values and it repeats the checks for the same parent and it's new children (if there are any). The way in which the method "sortdeleted" is implemented is explained in more detail in the method's comments.



---

## - **maxheap**

_Note: Maxheap is very similar to minheap. For this reason, I will only explain the parts that are different to the implementation of minheap._

### 1. BUILD MAXHEAP filename

In main, we follow the same process that we followed when we encountered BUILD MINHEAP.
The only things that change are:
1) the name of the variable which contains the name of the file from which we get the values that we add to the heap (so that we can assign values to maxheap and minheap from separate files)
2) the type and name of the object: we have a maxheap object called maxheap

The maxheap constructor is the same as the minheap constructor.
The *build* method of maxheap is the same as the *build* method of minheap.


### 2. INSERT MAXHEAP number

We follow the same process that we explained in "INSERT MINHEAP number". The method *insert* of maxheap is almost the same as the method *insert* of minheap.
Their only difference is that while the element that we are inserting has a value bigger than its parent's value, we switch those 2 elements and repeat the process.
When the value of the element becomes smaller than the value of its parent the process is done.

### 3. GETSIZE MAXHEAP

Same as GETSIZE MAXHEAP.

### 4. FINDMAX MAXHEAP

Same as FINDMIN MINHEAP. The content of position 0 of the *value* array of the maxheap is the value of the root of the maxheap. Therefore, it is the maximum value of the heap.

### 5. DELETE MAXHEAP

deletemax of maxheap is the same as deletemin of minheap.
sortdeleted of maxheap checks if the child with the biggest value has a value bigger than the parent's value (not smaller like sortdeleted of minheap). But other than this, it follows the same steps as sortdeleted of minheap.

---

## - **node**

In order to explain how the class avltree works we should first explain how the class node works. Each object of *node* is a node of an avltree.

The class node has 4 fields:
- value: integer that contains the value of the node
- lc: a pointer to the node that contains the left child. If the node doesn't have a left child then the pointer points to nullptr.
- rc: a pointer to the node that contains the right child. If the node doesn't have a right child then the pointer points to nullptr.
- pr: a pointer to the node that contains the parent. If the node doesn't have a parent (so if the node is the root) then the pointer points to nullptr.

The class node has the methods:
- A default constructor that makes the value of the node 0 and makes the children pointers point to nullptr
- A constructor that gets as a parameter an integer and makes it the value of the node and makes the pointers to the children point to nullptr
- Setters and getters for the private fields

---

## - **avltree**

_Note: For the avl tree I have also implemented the methods "preorder" and "inorder" that show the values of the tree with preorder and inorder traversal. These functions are not called in main but if you want to you can check the correctness of the AVL tree with them._


### 1. BUILD AVLTREE

For the AVL tree in main we follow the same steps that we have followed for the BUILD of previous structures.

The class of the AVL tree has 2 fields:
- root: pointer to an object with the type node. It points to the root of the tree.
- size: integer that contains the size of the AVL tree.

The class *avltree* has the default constructor that initializes the size of the tree to 0 and makes root point to nullptr.
It also has the method *build* that works in the same way that the *build* methods of the classes "minheap" and "maxheap" work.


### 2. INSERT AVLTREE number

In main, when the phrase INSERT AVLTREE is detected in a line of "commands.txt" then the string that follows it is turned into an integer (the same way it happened with the INSERT of previous structures). After this, we call *insert* for the object avltree with the integer as a parameter.

In the *insert* method of avltree:

The insertion of an element in the AVL tree is split in 2 parts:
- Insertion of the element in the tree in a way that allows the tree to remain a binary search tree.
- Execution of the necessary rotations so that the tree remains an AVL tree.

1) Insertion of the element in the tree in a way that allows the tree to remain a binary search tree:
   - If the element that we wish to insert is the first element of the tree then we make it the root.
   - Otherwise, we search for the parent of the element starting from the root.

2) Execution of the necessary rotations so that the tree remains an AVL tree:
   - For the execution of these rotations the method rotations is called. The parameter of the function is the pointer of the node we inserted.

The method rotations gets as a parameter a pointer to a node of the tree. The method has the bool variable "balanced". balanced is true when we do the rotation.
The method checks if a rotation is needed for the tree that has as a root the node it receives or any of its ancestors. If a rotation is needed, then it executes that rotation.

Specifically, if the node is empty or the necessary rotation has been executed for the tree to be an avltree then it returns. Otherwise, it calculates the height of the 2 subtrees using the function foo (the content of the function foo is explained later on).

If the height of the node's right subtree is bigger than the height of the node's left subtree and the difference is greater than or equal to 2 then we do a simple left rotation or a double RL rotation.
If the height of the node's right child's right subtree is greater than the height of the node's right child's left subtree then a simple left rotation is executed.
Otherwise, we execute a double RL rotation.
If one of the 2 rotations is executed then we assign the value true to "balanced".

If the height of the node's left subtree is bigger than the height of the node's right subtree and the difference is greater or equal to 2 then we do a simple right rotation or a double LR rotation.
If the height of the node's left child's left subtree is greater than the height of the node's left child's right subtree then a simple right rotation is executed.
Otherwise, we execute a double LR rotation.
If one of the 2 rotations is executed then we assign the value true to "balanced".

Functions that are used in the process we described above:
1) foo
2) left
3) right

Explanation of what the functions do:
1) foo:\
foo is a recursive function that finds and returns the height of the subtree that has "node" as its root.
The parameters we pass to foo are:
   1) the pointer to *node*
   2) an integer *height*

    The 2nd parameter is used for the recursive computation of the height. Basically, while recursions are executed the 2nd parameters the distance between the node we are currently examining and the node for whom we initially called *foo* for.

    In the end, this parameter is going to have the height of the subtree as value. This is why it's called "height".

    - If the node that the 1st parameter is pointing to is empty, then the 2nd parameter is returned. 
    - Otherwise, foo is called 2 times.
         - The 1st time it is called with the pointer to the right child as the 1st parameter and height+1 as the 2nd parameter.
         - The 2nd time it is called with the pointer to the left child as the 1st parameter and height+1 as the 2nd parameter.
    - The values that these 2 calls return are compared and the biggest value is returned.

2) left:\
left is a function that gets as a parameter the pointer to the node "node" and executes the simple left rotation of the subtree that has "node" as a root.

3) right:\
right is a function that gets as a parameter the pointer to the node "node" and executes the simple right rotation of the subtree that has "node" as a root.

In order to execute the double RL rotation of a subtree, we first call "right". The parameter we pass to "right" is the pointer to the right child of the subtree's root. After this, "left" is called. The parameter we pass to *left* is the pointer to the subtree's root.
In order to execute the double LR rotation of a subtree, we first call "left". The parameter we pass to "left" is the pointer to the left child of the subtree's root. After this, "right" is called. The parameter we pass to *right* is the pointer to the subtree's root.



### 3. GETSIZE AVLTREE

Same as the GETSIZE of previous structures.



### 4. FINDMIN AVLTREE

In main, when the phrase FINDMIN AVLTREE is detected in a line of "commands.txt" then we find the minimum element of the AVL tree by calling the *findmin* method of the avltree class.
In output.txt we write both the execution time and the minimum element of the AVL tree.


The AVL tree is a binary search tree so in order to find its smallest element we just need to find the most left element of the tree. 
Therefore, we start at the root and we check if it has a left child. 
If it does, we repeat the process for the left child. 
If it doesn't, then the value of the last node that we checked is the tree's minimum element.



### 5. SEARCH AVLTREE number

In main, when the phrase SEARCH AVLTREE is detected in a line of "commands.txt" then we save the integer that follows it in a variable called *number* in the same way that is described in "INSERT MINHEAP".
In output.txt we write the execution time. We also write whether *number* exists in the AVL tree. Specifically, we write "SUCCESS" if it exists and "FAILURE" if it doesn't.
We discover that using the method *search* of the avltree class.

The method *search* of the class avltree gets an integer as a parameter and returns "SUCCESS" if the value of the integer is a value of an element of the AVL tree and "FAILURE" if it isn't.

In the method *search*:\
The AVL tree is a binary search tree so the search happens in the following way:
We start examining the tree's nodes from the root.

- If the value of the node we are examining is bigger than *number*:
- If the node has a left child then we examine the left child.
- Otherwise, there is no node with *number* as its value in the tree so we return "FAILURE".

If the value of the node we are examining is smaller than number:
- If the node has a right child then we examine the right child.
- Otherwise, there is no node with number as its value in the tree so we return "FAILURE".

If we find the node, we return "SUCCESS".



### 6. DELETE AVLTREE number

In main, when the phrase DELETE AVLTREE is detected in a line of "commands.txt" then we  save the integer that follows it in a variable called *number* in the same way that is described in "INSERT MINHEAP".
In order to delete the node with the value *number*, we call the method *delete_node* for the object avltree with *number* as the parameter.

In the method delete_node we execute the process of searching, the same way we did in the method *search*.
We don't return the string "SUCCESS" when we find the node that has the value *number*. Instead, we delete the node from the AVL tree. Also, instead of returning the string "FAILURE" when there isn't such node in the tree, we do nothing.
If we haven't returned to main, then in the tree there is a node that has the same value as *number* so we delete the node from the tree using an if structure.
    
- 1st step: We delete the node from the tree so that the tree can remain a binary search tree.
- 2nd step: We execute the necessary rotations so that the tree can remain an AVL tree.

Initially, we have 2 bool variables, *is_root* and *is_right*.
- We make *is_root* true if the node we found while searching is the root.
- We make *is_right* true if the node we found while searching is the right child of its parent.

> If the node is a leaf:
>
> 1st step:
> - If the node is the root then we make the root point to nullptr.
> - Otherwise, if the node is its parent's right child, then the parent's right child becomes nullptr.
> - Otherwise, if the node is its parent's left child, then the parent's left child becomes nullptr.
> 
> 2nd step:
> - We call the function rotations. The parameter we pass is the pointer to the parent of the node we are deleting. This doesn't need to be done if the node is both a leaf and the root because then there are no other elements.

> If the node only has a right subtree:
>
> 1st step:
> - If the node is the root then the right child of the node becomes the root.
> - Otherwise, if the node is the right child of its parent, then the right child of the node becomes the right child of the node's parent.
> - Otherwise, the node is the left child of its parent. Then, the right child of the node becomes the left child of the node's parent.
> 
> 2nd step:
> - The method *rotations* is called. The parameter it takes is the pointer to the right child of the node we are deleting.

> Otherwise, if the node only has a left subtree:
> 
> 1st step:
> - If the node is the root then the left child of the node becomes the root.
> - Otherwise, if the node is the right child of its parent, then the left child of the node becomes the right child of the node's parent.
> - Otherwise, the node is the left child of its parent. Then, the left child of the node becomes the left child of the node's parent.
> 
> 2nd step:
> - The method *rotations* is called. The parameter it takes is the pointer to the left child of the node we are deleting.

> Otherwise, if the node has both a left and a right subtree:
> 
> 1st step:
> - The node is replaced by the smallest element of its right subtree and the left child of the element's parent points to nullptr. But if the right subtree only contains 1 element then the parent of the smallest element of the right subtree is the node itself. So, in this case the right child points to nullptr, not the left one.
> 
> 2nd step:
> - The method *rotations* is called. The parameter it takes is the pointer to the new smallest element of the right subtree of the node we are deleting.

Also, the size of the AVL tree is reduced by 1 when the deletion is done.

---

## - **vertex**

In order to explain how the graph works, we should first explain how the class *vertice* works. Each object of *vertex* is a vertex of the graph.

The class vertex has 6 fields:
- value: an integer that contains the value of the vertex.
- edges: a dynamic array that contains all the vertices with whom the vertex is connected.
- edges_count: an integer that contains the amount of incident edges of the vertex.
- weights: a dynamic array of integers that contains the weights of all its incident edges. The arrays edges and weights are parallel arrays.
- edges_positions: a dynamic array of integers in which we save the positions in the array *vertices* of all the vertices with whom this vertex is connected. The array is parallel to the arrays *edges* and "weights".
- position_in_vertices: an integer that contains the position of the vertex in the array *vertices*.

The methods of class *vertex* are:
- A default constructor, that initializes the value of the vertex as 0 and its degree as 0.
- A constructor that takes an integer as a parameter. The constructor makes the integer the value of the vertex and initializes its degree as 0.
- A copy constructor.
- The method *insert* that connects the vertex with a vertex that it gets as a parameter. The 2nd parameter is the weight of the edge that connects them. We make the assumption that the two edges are not already connected.
- The method *delete_edge* that gets a vertex as a parameter and deletes from the graph the edge that contents it to the vertex for which we called the method.
- setters and getters.
- Overload of the operator = so that it can also work for vertices.

More specifically, in the method *insert* we update the arrays *edges*,*weights*,*edges_positions*. We do so by increasing their size by 1 and by adding the new neighboring vertex, the weight of the new edge and its position in the arrays *edges*,"weights" and "edges_positions". Also, we increase edges_count by 1.

Initially, *delete_edge* checks if the edge that connects the vertices exists in the graph and if it discovers that the edge exists, then it saves its position in the arrays edges/weights/edges_position in the variable "position". The arrays are parallel so the position is the same in each array.
- If the edge doesn't exist, then we return. 
- Otherwise, we update the arrays edges,weights,edges_positions by removing the element in *position* from them and by reducing their size by 1.



---
## - **graph**


### 1. BUILD GRAPH filename

For the "BUILD" command pf graph we follow the same steps in main that we followed for the "BUILD" commands of previous structures.

The class *graph* has 3 fields:
- vertices: dynamic array that contains the vertices of the graph
- order: integer that contains the order of the graph, which is the amount of vertices it has
- size: integer that contains the size of the graph, which is the amount of edges it has

The class *graph* has the default constructor that initializes the order and size to 0.
It also has the method *build* that gets the name of a file as a parameter and reads the necessary data for the construction of the graph from said file and creates the graph. This happens with the call of the method *insert* with the values of the 2 vertices and the weight of the edge as parameters.



### 2. INSERT GRAPH number1 number2 weight

In main, when the phrase INSERT GRAPH is detected in a line of "commands.txt" then the 3 strings that follow it are turned into integers and the method insert is called for the graph object. The parameters we pass on it are the 3 integers.

With the method *insert*, we insert in the graph the vertices with values *n1* and *n2* if they don't already exist in the graph.
Also, we insert the edge that connects them with *w* as its weight.
Initially, we look for the 2 vertices in the graph.
If 1 of them doesn't exist then we insert it in the graph by adding it in the array *vertices* and increasing the order of the graph.
If both vertices already exist in the graph, then we just insert the edge that connects them.

The insertion of the edge happens this way:
- We call *insert* for both vertices n1 and n2. The parameter we pass is the other vertex, the weight of the edge and the position of the other vertex in the array *vertices*.
- We increase the graph's size by 1.



### 3. GETSIZE GRAPH

In main, when the phrase "GETSIZE GRAPH" is detected in a line of "commands.txt" then we write the size and order of the graph in the file "output.txt". We get the size from the method "getsize" and we get the size from the method *getorder*.

### 4. DELETE GRAPH number1 number2

In main, when the phrase DELETE GRAPH number1 number2 is detected in a line of "commands.txt" then we turn the 2 strings that follow "DELETE GRAPH" to integers and save them in the integer variables *n1* and *n2*.
In order to delete the edge from the graph we call the method *delete_graph_edge* for the object graph, which is our graph. The parameters we pass are the variables n1 and n2.

In *delete_graph_edge* we search for the 2 vertices to see whether they exist in the graph or not. If they both exist then we call the method *delete_edge* of vertex for each vertex with the other one as a parameter. We also reduce the size of the graph by 1.


### 5. COMPUTESHORTESTPATH GRAPH number1 number2

In main, when the phrase COMPUTESHORTESTPATH GRAPH number1 number2 is detected in a line of "commands.txt" then turn the 2 strings that follow "COMPUTESHORTESTPATH GRAPH" to integers. We save them in the integer variables *n1* and *n2*.
After this, the method *Dijkstra* is called for the graph. The parameters it uses are *n1*,*n2* and the result it returns is written in the file "output.txt".

In the *Dijkstra* method we also use an extra class that is very similar to the minheap class. This class is called minheap_graph. I report the differences between minheap and minheap_graph below.

Initially, minheap_graph receives the nodes of the graph instead of the integers that are the vertex's values. It saves them in the dynamic array *v*. Also, it has the dynamic array of integers "keys". The values of the heap are sorted based on the values of the "keys" array.
Also, it has the dynamic array *position_in_vertices* which contains the positions of the vertices of the array *v* in the array *vertices*. The 3 dynamic arrays are parallel.

- The class minheap_graph has the method decreasekey, which takes the vertex that it receives as the 1st parameter and it tracks its position in the heap.
It stores the 2nd parameter in the array keys. The position it is stored in is the position that it found.
After this, the method makes sure that the heap continues to be a minheap. It does so by calling the methods sortdeleted and sort.

- The class minheap_graph also has the recursive function "sort" that gets as a parameter the integer "position".
sort makes sure that the parent of the element in position "position" in the heap has a smaller value "keys" than the value "keys" of its child. If this isn't true then it swaps them and repeats the check for the element that is now the parent. Otherwise, it returns.

The function Dijkstra receives 2 integers *n1*, *n2* as parameters.
The function calculates and returns the cost of the minimum path between the node with value n1 and the node with value n2.
Tha function has an integer array "d" in which it saves the distances of each vertex of the graph to the vertex with the value n1.

In the function, every vertice of the graph is inserted in the minheap.
The parameters we pass on the insert function are the vertex, the vertex's element in d and the position the vertex has in the array *vertices*.
Dijkstra does the following: each time the root is deleted from the heap and the matrix d is updated it checks if by deleting the element from the heap, any of the distances of the *n1* node to its neighbor is deleted from the heap.

### 6. FINDCONNECTEDCOMPONENTS GRAPH

In main, when the phrase FINDCONNECTEDCOMPONENTS GRAPH is detected in a line of "commands.txt" then the method fcc of the graph is called and the value it returns is written in the file "output.txt".

In the method fcc there is the array "color" in which the color of each vertex is saved. If we haven't visited the vertex yet, the color is 'w'. While we are visiting it th color is 'g'. After we have visited it the color is 'b'. Initially, the color of each vertex is 'w'.
For each vertex that we haven't visited, we increase the count of connected components by 1and we visit the vertex and every vertex of the connected component it belongs in. This happens with the method DFSVisit.

The recursive function DFSVisit receives as a parameter the array "color" and the integer "u" and it traverses the elements of the component that contains the vertex tha is in the position "u" of the array *vertices*. The function updates the array "color".



### 7. COMPUTESPANNINGTREE GRAPH

In main, when the phrase COMPUTESPANNINGTREE GRAPH is detected in a line of "commands.txt" then the method cc2 is called for the graph and its result is written in the file "output.txt".
The result it returns is the cost of the graph's minimum spanning tree.

The method cc2 helps in the execution of the Prim algorithm for each connected component of the graph.
The method has the array color2 which contains the color of each vertex.
- If we haven't visited the vertex, then its color is 'w'.
- While we are visiting it, its color is 'g'.
- After we have visited it, its color is 'b'.

For each vertex we haven't visited we have the array color3. We initialize the array with 'w', and we call the method DFSVisit2. The parameters we pass are color2, the vertex's position in *vertices* and color3.
DFSVisit2 works like DFSVisit but in addition to this, it updates the array color3. Therefore, after the execution of DFSVisit, color3 contains the value 'b' only for the vertices of the connected component that contains the i-th vertex of the array *vertices*.

cc2 returns the cost of the minimum spanning tree that it computes with the variable "result".
Initially, result has the value 0 and after every execution of the method DFSVisit2 it is updated.
Every time result is increased by the value returned by the method Prim. The parameters we pass to Prim are the array color3 and the integer i that indicates the position.

The method Prim has 2 arrays: "color" and "key". We initialize color with 'w' and key with the biggest possible integer (INT_MAX). We have a minheap of the class minheap_graph in which we insert every vertex of the graph with its key and its position in the array *vertices*.

While the heap has elements we delete the root and store it in the vertex "u". For each neighboring vertex of "u" if we haven't visited and we can decrease the key of "u" through it then we update the "key" and the heap.

The method has the long int variable "weight" which contains the weight of the minimum spanning tree of the connected component that contains the elements that have color3 'b'. The weight will become the sum of the keys that have color3 'b'. The method returns the weight.


---

## - **hashtable**


The hash function we use is h(n)=(3*n+7) mod maxsize.

### 1. BUILD HASHTABLE filename

For the hashtable main we follow the same steps that we followed in the "BUILD" of the previous structures.

The class hashtable has 2 fields:
- data: dynamic array of integers that is the hashtable
- maxsize: integer that is data's size

The class hashtable has the default constructor that initializes "maxsize" as 50 and makes "data" an array with size 50.

The class also has the function *build* that receives as a parameter the name of the file that it reads the data from in order to construct the hashtable.
The method inserts the elements in the hashtable. This happens with the call of the method *insert* for each value that is read from the file. This value becomes a parameter to *insert*.



### 2. INSERT HASHTABLE number

In main, when the phrase INSERT GRAPH is detected in a line of "commands.txt" then the string that follows it is turned into an integer in the way we have described in the INSERT of previous structures.
After this, the method insert is called for the hashtable object. The parameter we pass on it is the integer.

With the method *insert* we insert the element with the value n in the hashtable. If the hashtable is full then we double its size. That means that the hash function changes.
Therefore, we re-insert the elements in the hashtable using the new hash function. This is done with the help of the array data2.
The insertion of each element in the hashtable is done this way: we calculate the position of the element in the hashtable.
- If the position in empty (that is to say the array contains -1 in this position) then we put the element in that position.
- If another element is placed on that position then we search for the next empty position.
- If while searching we reach the end of the array then we continue from the beginning.
- When we reach the empty position we place the element.



### 3. GETSIZE HASHTABLE

In main, when the phrase GETSIZE HASHTABLE is detected in a line of "commands.txt" then we write in the file "output.txt" the size of the hashtable. We get the size with the method "getsize".
The method *getsize* calculates and returns the amount of elements that there are in the hashtable.
More specifically, the method has the variable *elements_count* which contains the count of elements there are in the hashtable.
We initialize elements_count to 0. For each element in *data*, if the element is not -1 then we increase elements_count by 1. Finally, we return elements_count.



### 4. SEARCH HASHTABLE number

In main, when the phrase SEARCH HASHTABLE is detected in a line of "commands.txt" then we turn the string that follows it into an integer and save it in the variable *number* as we have described in "INSERT MINHEAP".
In the file "output.txt" we write the execution time and whether *number* exists in the hashtable or not. More specifically, we write "SUCCESS" if it exists and "FAILURE" if it doesn't. We find this using the method *search* of the class hashtable.

The method *search* has as a parameter the integer *n*. The method searches for the element with the value *n* in the hashtable.
If it finds it then it returns the string "SUCCESS".
Otherwise, it returns the string "FAILURE".

According to the hash function we have chosen, the element that we are searching for should be in the position (3*n+7) mod maxsize of the hashtable.

- If the position in which *n* should be contains -1 (that is to say it is empty) then the element we are looking for does not exist in the hashtable. Therefore, we return "FAILURE".
- If the position in which *n* should be is not empty and there hasn't been a collision (that is to say the position contains the element we are looking for), then we return "SUCCESS".
- If the position in which *n* should be is not empty and there has been a collision (that is to say the position doesn't contain the element we are looking for) then we follow these steps:
  - Starting from the position after the position the element should be in we check one by one the next elements of the hashtable.
    - If we find the element, then we return "SUCCESS".
    - If we find an empty position, then we return "FAILURE".
    - If we reach the end of the hashtable, then we continue searching from the start of the array.
    - If we have checked all the elements and we haven't found *n*, then we return "FAILURE".



---
EXAMPLE

Content of the file "commands.txt":\
BUILD MINHEAP input.txt\
GETSIZE MINHEAP\
INSERT MINHEAP 8\
FINDMIN MINHEAP\
DELETEMIN MINHEAP

BUILD MAXHEAP input.txt\
GETSIZE MAXHEAP\
INSERT MAXHEAP 72\
GETSIZE MAXHEAP\
FINDMAX MAXHEAP\
DELETEMAX MAXHEAP

BUILD AVLTREE input.txt\
GETSIZE AVLTREE\
FINDMIN AVLTREE\
SEARCH AVLTREE 5\
SEARCH AVLTREE 122\
INSERT AVLTREE 92\
DELETE AVLTREE 27

BUILD GRAPH inputgraph.txt\
GETSIZE GRAPH\
INSERT GRAPH 10 20 30\
GETSIZE GRAPH\
DELETE GRAPH 18	93\
GETSIZE GRAPH\
COMPUTESHORTESTPATH GRAPH 50 80\
COMPUTESHORTESTPATH GRAPH 48 79\
COMPUTESHORTESTPATH GRAPH 37 32\
FINDCONNECTEDCOMPONENTS GRAPH\
COMPUTESPANNINGTREE GRAPH

BUILD HASHTABLE input.txt\
GETSIZE HASHTABLE\
INSERT HASHTABLE 61\
GETSIZE HASHTABLE\
INSERT HASHTABLE 70\
GETSIZE HASHTABLE\
INSERT HASHTABLE 19\
GETSIZE HASHTABLE\
INSERT HASHTABLE 44\
GETSIZE HASHTABLE\
SEARCH HASHTABLE 90\
SEARCH HASHTABLE 150

Content of the file "input.txt":\
90\
54\
12\
64\
18\
45\
100\
22\
11\
19\
89 \
3\
63\
52\
80\
5\
40\
6\
200\
10\
32\
4\
7\
60\
27\
50\
13\
71\
88\
\
Στο αρχείο inputgraph.txt:\
15	59	100\
62	37	75\
87	79	51\
93	8	98\
30	89	79\
90	2	24\
97	37	40\
79	61	30\
52	75	24\
48	61	24\
52	11	91\
41	54	33\
18	93	73\
91	65	1\
65  17  2\
50  60  1\
60  70  2\
70 80 3\
11	32	93\
55	70	96\
82	41	42\
69	8	80\
40	37	3\
64	54	12\
27	43	23\
15	79	91\
87	83	16\
39	45	78\
81	72	73\
3	98	72\
52	16	4\
16  40  1\
9	28	51\
4 33 44\
\
\
Στο αρχείο output.txt έχουμε:\
Χρόνος εκτέλεσης της BUILD MINHEAP: 2.6e-05\
Το μέγεθος του σωρού ελαχίστων είναι: 29\
Χρόνος εκτέλεσης της GETSIZE MINHEAP: 2.3e-05\
Χρόνος εκτέλεσης της INSERT MINHEAP 8: 1e-06\
Το ελάχιστο στοιχείο από το σωρό ελαχίστων είναι το: 3\
Χρόνος εκτέλεσης της FINDMIN MINHEAP: 9e-06\
Χρόνος εκτέλεσης της DELETEMIN MINHEAP: 1e-06\
Χρόνος εκτέλεσης της BUILD MAXHEAP: 1.9e-05\
Το μέγεθος του σωρού μεγίστων είναι: 29\
Χρόνος εκτέλεσης της GETSIZE MAXHEAP: 1.6e-05\
Χρόνος εκτέλεσης της INSERT MAXHEAP 72: 1e-06\
Το μέγεθος του σωρού μεγίστων είναι: 30\
Χρόνος εκτέλεσης της GETSIZE MAXHEAP: 9e-06\
Το μέγιστο στοιχείο από το σωρό μεγίστων είναι το: 200\
Χρόνος εκτέλεσης της FINDMAX MAXHEAP: 1.4e-05\
Χρόνος εκτέλεσης της DELETEMAX MAXHEAP: 1e-06\
Χρόνος εκτέλεσης της BUILD AVLTREE: 2.2e-05\
Το μέγεθος του δένδρου AVL είναι: 29\
Χρόνος εκτέλεσης της GETSIZE AVLTREE: 1.4e-05\
Το ελάχιστο στοιχείο από το δένδρο AVL είναι το: 3\
Χρόνος εκτέλεσης της FINDMIN AVLTREE: 1e-05\
Βρέθηκε το στοιχείο με τιμή 5 στο δένδρο AVL? SUCCESS\
Χρόνος εκτέλεσης της SEARCH AVLTREE 5: 8e-06\
Βρέθηκε το στοιχείο με τιμή 122 στο δένδρο AVL? FAILURE\
Χρόνος εκτέλεσης της SEARCH AVLTREE 122: 1.1e-05\
Χρόνος εκτέλεσης της INSERT AVLTREE 92: 2e-06\
Χρόνος εκτέλεσης της DELETE AVLTREE 27: 2e-06\
Χρόνος εκτέλεσης της BUILD GRAPH: 6.6e-05\
Το μέγεθος του γράφου είναι: 34\
Η τάξη του γράφου είναι: 48\
Χρόνος εκτέλεσης της GETSIZE GRAPH: 2.9e-05\
Χρόνος εκτέλεσης της INSERT GRAPH 10 20 30: 7e-06\
Το μέγεθος του γράφου είναι: 35\
Η τάξη του γράφου είναι: 50\
Χρόνος εκτέλεσης της GETSIZE GRAPH: 2.8e-05\
Χρόνος εκτέλεσης της DELETE GRAPH 18 93: 2e-06\
Το μέγεθος του γράφου είναι: 34\
Η τάξη του γράφου είναι: 50\
Χρόνος εκτέλεσης της GETSIZE GRAPH: 2.9e-05\
Το κόστος της ελάχιστης διαδρομής από τον κόμβο 50 στον κόμβο 80 είναι: 6\
Χρόνος εκτέλεσης της COMPUTESHORTESTPATH GRAPH 50 80: 6e-05\
Το κόστος της ελάχιστης διαδρομής από τον κόμβο 48 στον κόμβο 79 είναι: 54\
Χρόνος εκτέλεσης της COMPUTESHORTESTPATH GRAPH 48 79: 5.1e-05\
Το κόστος της ελάχιστης διαδρομής από τον κόμβο 37 στον κόμβο 32 είναι: 192\
Χρόνος εκτέλεσης της COMPUTESHORTESTPATH GRAPH 37 32: 5.1e-05\
Το πλήθος των συνεκτικών συνιστώσεων του γράφου είναι: 16\
Χρόνος εκτέλεσης της FINDCONNECTEDCOMPONENTS GRAPH: 1.5e-05\
Το κόστος του ελάχιστου εκτεινόμενου δένδρου του γράφου είναι: 1487\
Χρόνος εκτέλεσης της COMPUTESPANNINGTREE GRAPH: 5.5e-05\
Χρόνος εκτέλεσης της BUILD HASHTABLE: 1.6e-05\
Το πλήθος των στοιχείων του πίνακα κατακερματισμού είναι: 29\
Χρόνος εκτέλεσης της GETSIZE HASHTABLE: 1.2e-05\
Χρόνος εκτέλεσης της INSERT HASHTABLE 61: 1e-06\
Το πλήθος των στοιχείων του πίνακα κατακερματισμού είναι: 30\
Χρόνος εκτέλεσης της GETSIZE HASHTABLE: 1e-05\
Χρόνος εκτέλεσης της INSERT HASHTABLE 70: 1e-06\
Το πλήθος των στοιχείων του πίνακα κατακερματισμού είναι: 31\
Χρόνος εκτέλεσης της GETSIZE HASHTABLE: 1.8e-05\
Χρόνος εκτέλεσης της INSERT HASHTABLE 19: 1e-06\
Το πλήθος των στοιχείων του πίνακα κατακερματισμού είναι: 32\
Χρόνος εκτέλεσης της GETSIZE HASHTABLE: 1e-05\
Χρόνος εκτέλεσης της INSERT HASHTABLE 44: 1e-06\
Το πλήθος των στοιχείων του πίνακα κατακερματισμού είναι: 33\
Χρόνος εκτέλεσης της GETSIZE HASHTABLE: 9e-06\
Βρέθηκε το στοιχείο με τιμή 90 στον πίνακα κατακερματισμού? SUCCESS\
Χρόνος εκτέλεσης της SEARCH HASHTABLE 90: 1.2e-05\
Βρέθηκε το στοιχείο με τιμή 150 στον πίνακα κατακερματισμού? FAILURE\
Χρόνος εκτέλεσης της SEARCH HASHTABLE 150: 1e-05