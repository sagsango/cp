/*Firstly, let's run bfs on the given graph and calculate distances for all
vertices. In fact, we don't need distances, we need their parities. 
The second part is to find all vertices with an even distance, 
all vertices with and odd distance, and print the smallest by size part.
Why is it always true? Firstly, it is obvious that at least one of these 
sizes will not exceed ⌊𝑛/2⌋

. And secondly, because we are checking just parities of distances, it is 
obvious that each vertex of some parity is connected with at least one vertex 
of the opposite parity (because it has this parity from some vertex of the
opposite parity).
*/
