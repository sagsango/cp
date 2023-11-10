All the problmes are simple.
Last Problem:
		->	Implementation is good.
		->	make an undirected waighted graph.
		->	Now assigning weight to the edge is tricky.
				->	Just mention the edge number i not weight.
				->	And remember w[i], a[i], b[i] 
				->	So during traveral you can get +w[i] or -w[i]
		-> So for eveycomponent take a node assign coradinate to 0
				-> Do dfs
				-> assign the coordinate with the help of parent
				-> if you visit an already visited node then it is time to 
				   check the possibility of solution, here visited node coordiante
				   should match, means new coordinate = old already siigned coordinate


	
