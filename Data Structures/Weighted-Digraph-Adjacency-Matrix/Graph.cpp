/*
Title: Weighted Digraph (Adjacency Matrix)
Author: Edwin Khew
Description: Weighted digraph (adjacency matrix) class implementation.
Date Created: 7/18/2021
*/

#include <map>
#include <queue> //for BFS
#include <stack> //for DFS
#include <climits>

template <typename ItemType>
Graph<ItemType>::Graph():vertex_count_(0), matrix_size_(3), next_index_(0)
{
    matrix_ = new int*[matrix_size_];

    for(int i = 0; i < matrix_size_; i++)
    {
        matrix_[i] = new int[matrix_size_];

        //initialize every index with INT_MAX
        for(int j = 0; j < matrix_size_; j++)
        {
            matrix_[i][j] = NULL_EDGE_;
        }
    }
}

template <typename ItemType>
void Graph<ItemType>::addVertex(ItemType item)
{
    Vertex<ItemType> new_vertex = Vertex<ItemType>(item); //create a new vertex object with the specified item

    if(next_index_ == matrix_size_)
    {
        expandMatrix();
    }

    vertex_map_[new_vertex] = next_index_; //insert the new vertex into the vertex map as a key and assign its value as the next available index
    next_index_++;
    vertex_count_++;
}

template <typename ItemType>
void Graph<ItemType>::removeVertex(ItemType item)
{
    typename std::map<Vertex<ItemType>, int>::iterator v = vertex_map_.find(Vertex<ItemType>(item)); //find the vertex key with 'item1' and store into the iterator
    int shift = v->second; //the row/column index of the vertex to remove

    if(!isEmpty() && v != vertex_map_.end()) //can only remove vertex if the graph is not empty and the vertex exists
    {
        //decrement the index value of every vertex that comes after the vertex to be removed
        for(v; v != vertex_map_.end(); v++)
        {
            v->second = v->second - 1;
        }

        while(shift < matrix_size_ - 1)
        {
            //shift columns leftwards starting from the shift index
            for(int i = 0; i < matrix_size_; i++)
            {
                matrix_[i][shift] = matrix_[i][shift + 1];
            }

            //shift rows upwards starting from the shift index
            for(int i = 0; i < matrix_size_; i++)
            {
                matrix_[shift][i] = matrix_[shift + 1][i];
            }
            shift++;
        }

        vertex_map_.erase(Vertex<ItemType>(item)); //remove the vertex from the vertex map
        next_index_--;
        vertex_count_--;
    }
}

template <typename ItemType>
void Graph<ItemType>::addEdge(ItemType item1, ItemType item2, int weight)
{
    typename std::map<Vertex<ItemType>, int>::iterator i = vertex_map_.find(Vertex<ItemType>(item1)); //find the vertex key with 'item1' and store into the iterator
    typename std::map<Vertex<ItemType>, int>::iterator j = vertex_map_.find(Vertex<ItemType>(item2)); //find the vertex key with 'item2' and store into the iterator

    if(!isEmpty() && i != vertex_map_.end() && j != vertex_map_.end())
    {
        matrix_[i->second][j->second] = weight;
    }
}

template <typename ItemType>
void Graph<ItemType>::removeEdge(ItemType item1, ItemType item2)
{
    typename std::map<Vertex<ItemType>, int>::iterator i = vertex_map_.find(Vertex<ItemType>(item1)); //find the vertex key with 'item1' and store into the iterator
    typename std::map<Vertex<ItemType>, int>::iterator j = vertex_map_.find(Vertex<ItemType>(item2)); //find the vertex key with 'item2' and store into the iterator

    if(!isEmpty() && i != vertex_map_.end() && j != vertex_map_.end())
    {
        matrix_[i->second][j->second] = NULL_EDGE_;
    }
}

template <typename ItemType>
bool Graph<ItemType>::isEmpty() const
{
    return vertex_map_.size() == 0;
}

template <typename ItemType>
bool Graph<ItemType>::checkAdj(ItemType item1, ItemType item2) const
{
    typename std::map<Vertex<ItemType>, int>::const_iterator i = vertex_map_.find(Vertex<ItemType>(item1)); //find the vertex key with 'item1' and store into the iterator
    typename std::map<Vertex<ItemType>, int>::const_iterator j = vertex_map_.find(Vertex<ItemType>(item2)); //find the vertex key with 'item2' and store into the iterator

    if(!isEmpty() && i != vertex_map_.end() && j != vertex_map_.end())
    {
        return matrix_[i->second][j->second] != NULL_EDGE_;
    }

    return false;
}

template <typename ItemType>
void Graph<ItemType>::printAdjVertices(ItemType item) const
{
    typename std::map<Vertex<ItemType>, int>::const_iterator v = vertex_map_.find(Vertex<ItemType>(item)); //find the vertex key with 'item' and store into the iterator

    if(!isEmpty() && v != vertex_map_.end()) //can only print adjacent vertices if graph is not empty and vertex exist
    {
        typename std::map<Vertex<ItemType>, int>::const_iterator check = vertex_map_.begin(); //iterator used to check each column of the row for an edge

        while(check != vertex_map_.end()) //check every column where a vertex exists
        {
            //if an edge exists at the index, print the vertex at that column
            if(matrix_[v->second][check->second] != NULL_EDGE_)
            {
                std::cout << check->first.getItem() << " ";
            }

            check++;
        }
    }
    else
    {
        std::cout << "Vertex not found!";
    }
}

template <typename ItemType>
void Graph<ItemType>::BFS(ItemType start) const
{
    std::queue<Vertex<ItemType>> Q; //queue used to keep track of unvisited vertices
    std::map<Vertex<ItemType>, bool> visited_map; //map used to keep track of visited vertices; key = vertex and value = 'true'

    typename std::map<Vertex<ItemType>, int>::const_iterator i = vertex_map_.find(Vertex<ItemType>(start)); //find the starting vertex

    if(i != vertex_map_.end()) //can only begin BFS if the starting vertex exists
    {
        Q.push(i->first); //push the starting vertex into queue
        visited_map[i->first] = true; //mark starting vertex as visited

        while(!Q.empty()) //continue traversing while the queue is not empty
        {
            Vertex<ItemType> curr_vertex = Q.front();
            std::cout << curr_vertex.getItem() << " ";
            Q.pop();

            typename std::map<Vertex<ItemType>, int>::const_iterator j = vertex_map_.begin(); //iterates through every index of a row

            while(j != vertex_map_.end())
            {
                typename std::map<Vertex<ItemType>, bool>::const_iterator k = visited_map.find(Vertex<ItemType>(j->first)); //check if the vertex in the current index has already been visited
                typename std::map<Vertex<ItemType>, int>::const_iterator l = vertex_map_.find(Vertex<ItemType>(curr_vertex)); //find the row index of the current vertex

                if(k == visited_map.end() && matrix_[l->second][j->second] != NULL_EDGE_)
                {
                    Q.push(j->first);
                    visited_map[j->first] = true;
                }

                j++;
            }
        }
    }
    else
    {
        std::cout << "Start vertex not found!";
    }
}

template <typename ItemType>
void Graph<ItemType>::iterativeDFS(ItemType start) const
{
    std::stack<Vertex<ItemType>> S; //stack used to keep track of unvisited vertices
    std::map<Vertex<ItemType>, bool> visited_map; //map used to keep track of visited vertices; key = vertex and value = 'true'

    typename std::map<Vertex<ItemType>, int>::const_iterator i = vertex_map_.find(Vertex<ItemType>(start)); //find the starting vertex

    if(i != vertex_map_.end()) //can only begin DFS if the starting vertex exists
    {
        S.push(i->first); //push the starting vertex into stack
        visited_map[i->first] = true; //mark starting vertex as visited

        while(!S.empty()) //continue traversing while the stack is not empty
        {
            Vertex<ItemType> curr_vertex = S.top();
            std::cout << curr_vertex.getItem() << " ";
            S.pop();

            typename std::map<Vertex<ItemType>, int>::const_iterator j = vertex_map_.begin(); //iterates through every index of a row

            while(j != vertex_map_.end())
            {
                typename std::map<Vertex<ItemType>, bool>::const_iterator k = visited_map.find(Vertex<ItemType>(j->first)); //check if the vertex in the current index has already been visited
                typename std::map<Vertex<ItemType>, int>::const_iterator l = vertex_map_.find(Vertex<ItemType>(curr_vertex)); //find the row index of the current vertex

                if(k == visited_map.end() && matrix_[l->second][j->second] != NULL_EDGE_)
                {
                    S.push(j->first);
                    visited_map[j->first] = true;
                }

                j++;
            }
        }
    }
    else
    {
        std::cout << "Start vertex not found!";
    }
}

template <typename ItemType>
void Graph<ItemType>::recursiveDFS(ItemType start) const
{
    typename std::map<Vertex<ItemType>, int>::const_iterator i = vertex_map_.find(Vertex<ItemType>(start)); //search for the start vertex

    if(i != vertex_map_.end()) //can only begin DFS if the starting vertex exists
    {
        std::map<Vertex<ItemType>, bool> visited_map; //map used to keep track of visited vertices; key = vertex and value = 'true'

        recursiveDFSHelper(start, &visited_map);
    }
    else
    {
        std::cout << "Start vertex not found!";
    }
}

template <typename ItemType>
void Graph<ItemType>::recursiveDFSHelper(ItemType curr_vertex, std::map<Vertex<ItemType>, bool> *visited_map) const
{
    typename std::map<Vertex<ItemType>, int>::const_iterator i = vertex_map_.find(Vertex<ItemType>(curr_vertex)); //find the current vertex
    (*visited_map)[i->first] = true; //mark current vertex as visited

    std::cout << i->first.getItem() << " ";

    typename std::map<Vertex<ItemType>, int>::const_iterator j = vertex_map_.begin(); //iterates through every index of a row

    while(j != vertex_map_.end())
    {
        typename std::map<Vertex<ItemType>, bool>::const_iterator k = visited_map->find(Vertex<ItemType>(j->first)); //check if the vertex in the current index has already been visited
        typename std::map<Vertex<ItemType>, int>::const_iterator l = vertex_map_.find(Vertex<ItemType>(curr_vertex)); //find the row index of the current vertex

        if(k == visited_map->end() && matrix_[l->second][j->second] != NULL_EDGE_)
        {
            recursiveDFSHelper(j->first.getItem(), visited_map); //recursively call the function if the vertex has not been visited already and an edge exists
        }

        j++;
    }
}

template <typename ItemType>
void Graph<ItemType>::dijkstra(ItemType source) const
{
    int paths[vertex_count_]; //array to store the shortest paths
    bool visited[vertex_count_]; //array used to keep track of visited vertices

    //initialize every shortest path to 'INT_MAX', and every vertex to 'false' to mark as unvisited
    for(int i = 0; i < vertex_count_; i++)
    {
        paths[i] = INT_MAX;
        visited[i] = false;
    }

    typename std::map<Vertex<ItemType>, int>::const_iterator v = vertex_map_.find(Vertex<ItemType>(source)); //find the source vertex in the map to get its index
    paths[v->second] = 0; //distance from the source to itself is '0'

    for(int i = 0; i < vertex_count_ - 1; i++)
    {
        int min = minDistance(paths, visited); //index of the unvisited vertex with the current smallest path
        visited[min] = true; //mark the vertex as visited

        for(int j = 0; j < vertex_count_; j++) //relax every adjacent vertex, if possible
        {
            //if the adjacent vertex is not already visited, an edge exists, and a new smaller path is found, set the new smallest path
            if (!visited[j] && matrix_[min][j] != NULL_EDGE_ && paths[min] + matrix_[min][j] < paths[j])
            {
                paths[j] = paths[min] + matrix_[min][j];
            }
        }
    }

    dijkstraDisplay(paths);
}

template <typename ItemType>
int Graph<ItemType>::minDistance(int paths[], bool visited[]) const
{
    int min = INT_MAX; //current minimum path
    int min_index; //index of the current minimum path

    for(int i = 0; i < vertex_count_; i++)
    {
        if(visited[i] == false && paths[i] <= min)
        {
            min = paths[i];
            min_index = i;
        }
    }

    return min_index;
}

template <typename ItemType>
void Graph<ItemType>::dijkstraDisplay(int paths[]) const
{
    typename std::map<Vertex<ItemType>, int>::const_iterator v; //iterator used for label printing

    for(int i = 0; i < matrix_size_; i++)
    {
        if(i < vertex_count_) //indices that contain a vertex
        {
            for(v = vertex_map_.begin(); v != vertex_map_.end(); v++) //iterate through the vertex map
            {
                if(v->second == i) //when a vertex with the matching index is found, print the vertex and its shortest path
                {
                    std::cout << v->first.getItem() << " --> " << paths[i] << std::endl;
                }
            }

            v = vertex_map_.begin(); //reset the iterator
        }
    }
}

template <typename ItemType>
int Graph<ItemType>::getVertexCount() const
{
    return vertex_count_;
}

template <typename ItemType>
void Graph<ItemType>::display() const
{
    typename std::map<Vertex<ItemType>, int>::const_iterator v; //iterator used for label printing

    if(!isEmpty()) //can only display if the graph is not empty
    {
        std::cout << "   ";

        //print top row labels (order based on index value of vertex)
        for(int i = 0; i < matrix_size_; i++)
        {
            if(i < vertex_count_) //indices that contain a vertex
            {
                for(v = vertex_map_.begin(); v != vertex_map_.end(); v++) //iterate through the vertex map
                {
                    if(v->second == i) //when a vertex with the matching index is found, print the vertex
                    {
                        std::cout << v->first.getItem() << " ";
                    }
                }

                v = vertex_map_.begin(); //reset the iterator
            }
            else //indices that do not contain a vertex
            {
                std::cout << "-- ";
            }
        }

        std::cout << std::endl;

        //print rows
        for(int i = 0; i < matrix_size_; i++)
        {
            //print left column label of current row (order based on index value of vertex)
            if(i < vertex_count_) //indices that contain a vertex
            {
                for(v = vertex_map_.begin(); v != vertex_map_.end(); v++) //iterate through the vertex map
                {
                    if(v->second == i) //when a vertex with the matching index is found, print the vertex
                    {
                        std::cout << v->first.getItem() << " ";
                    }
                }

                v = vertex_map_.begin(); //reset the iterator
            }
            else //indices that do not contain a vertex
            {
                std::cout << "-- ";
            }

            //print matrix of current row
            for(int j = 0; j < matrix_size_; j++)
            {
                if(matrix_[i][j] == NULL_EDGE_) //if null, print 'x' instead of INT_MAX
                {
                    std::cout << "-  ";
                }
                else
                {
                    std::cout << matrix_[i][j] << "  ";
                }
            }

            std::cout << std::endl;
        }
    }
    else
    {
        std::cout << "Graph is empty!" << std::endl;
    }
}

template <typename ItemType>
void Graph<ItemType>::expandMatrix()
{
    int **temp_matrix = matrix_;
    int old_matrix_size = matrix_size_;
    matrix_size_ = matrix_size_ * 2;
    matrix_ = new int*[matrix_size_];

    for(int i = 0; i < matrix_size_; i++)
    {
        matrix_[i] = new int[matrix_size_];

        for(int j = 0; j < matrix_size_; j++)
        {
            if(i < old_matrix_size && j < old_matrix_size && temp_matrix[i][j] != NULL_EDGE_) //copy the old matrix into the new matrix
            {
                matrix_[i][j] = temp_matrix[i][j];
            }
            else //for the new indices that did not exist in the old matrix, set them to INT_MAX
            {
                matrix_[i][j] = NULL_EDGE_;
            }
        }
    }
}
