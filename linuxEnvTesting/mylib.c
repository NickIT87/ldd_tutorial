#include <igraph.h>

int main() 
{
	igraph_real_t avg_path;
	igraph_t graph;
	igraph_vector_t dimvector;
	igraph_vector_t edges;
	int i;
	
	igraph_vector_init(&dimvector, 2);
	VECTOR(dimvector)[0]=30;
	VECTOR(dimvector)[1]=30;
	igraph_lattice(&graph, &dimvector, 0, IGRAPH_UNDIRECTED, 0, 1);
	
	igraph_rng_seed(igraph_rng_default(), 42);
	igraph_vector_init(&edges, 20);
	for (i=0; i<igraph_vector_size(&edges); i++) {
		VECTOR(edges)[i] = rand() % (int)igraph_vcount(&graph);
	}
	
	igraph_average_path_length(&graph, &avg_path, IGRAPH_UNDIRECTED, 1);
	printf("Average path length (lattice):    %f\n", (double) avg_path);

	igraph_add_edges(&graph, &edges, 0);
	igraph_average_path_length(&graph, &avg_path, IGRAPH_UNDIRECTED, 1);
	printf("Average path len(random lattice): %f\n", (double) avg_path);
  
	igraph_vector_destroy(&dimvector);
	igraph_vector_destroy(&edges);
	igraph_destroy(&graph);

	return 0;
}
