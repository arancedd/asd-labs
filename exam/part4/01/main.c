//
// Created by Edoardo on 11/02/2026.
//

#include <stdio.h>
#include <string.h>
#include "graph.h"

int main () {

    Graph g;
    Graph gf;

    // Test manuale rapido
    init_graph(&g, 4);
    add_edge(&g, 0, 1);
    add_edge(&g, 0, 2);
    print_graph(&g);

    //Test da file
    load_graph_from_file(&gf, "graph_data.txt");
    print_graph(&gf);

    graph_dfs(&gf, 0);
    find_longest_path(&gf, 0);

    return 0;

}

