# PowerGrid

Concordia University 2019
### 
Advanced program design with C++ / COMP 345

## Contributors:
* Rose Dufresne
* Elsa Donovan
* Deniz Akcal
* Isabelle Gourchette

## Gameplay

### To find Rule Book, Download here:
http://riograndegames.com/Game/1339-Power-Grid-recharged

## Structure

### GraphBuilder.h and GraphBuilder.cpp

GraphBuilder is the base structure of the game. Without it, the game would have no game board, and hence no functional game (Imagine playing monopoly without the game board... What kind of game would that be). The GraphBuilder describes this map:

![](map.jpg)

The Graph is built as an Adjacency List. This means that there is a vector of Cities (City Objects) where each city points towards a list of other cities that it is adjacent to, which, in a way, creates the edges between them. For example, from the Germany map displayed above, Flensburg would be the first city in the vector. Flensburg would point to the city Kiel and Kiel would also point towards the city Flensburg creating a two-way pointer that becomes an edge. 
