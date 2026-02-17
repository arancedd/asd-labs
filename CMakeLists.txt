cmake_minimum_required(VERSION 4.0)
project(asd_labs C)

set(CMAKE_C_STANDARD 11)


add_executable(p1_01
        exam/part1/01/main.c
        exam/part1/05/ricerca.h
        exam/part1/05/ricerca.h
)
add_executable(p1_02
        exam/part1/02/main.c)
add_executable(p1_03
        exam/part1/03/main.c)
add_executable(p1_04
        exam/part1/04/atleta.h
        exam/part1/04/atleta.c
        exam/part1/04/main.c)
add_executable(p1_05
        exam/part1/05/ricerca.h
        exam/part1/05/main.c
        exam/part1/05/ricerca.c)
add_executable(p2_01
        exam/part2/01/combinatorics.h
        exam/part2/01/main.c
        exam/part2/01/combinatorics.c)
add_executable(p2_02 exam/part2/02/main.c
        exam/part2/02/optimization.c
        exam/part2/02/optimization.h)
add_executable(p2_03 exam/part2/03/main.c
        exam/part2/03/knapsack.c
        exam/part2/03/knapsack.h)
add_executable(p3_01 exam/part3/01/main.c
        exam/part3/01/tree.c
        exam/part3/01/tree.h)
add_executable(p4_01 exam/part4/01/graph.c exam/part4/01/graph.h
        exam/part4/01/main.c)
add_executable(sim01 lab08/ex03/data.c
        lab08/ex03/data.h
        exam/sim01/ex01/matrix.c
        exam/sim01/ex01/matrix.h
        exam/sim01/ex02/list.c
        exam/sim01/ex02/list.h)
add_executable(sim01_03 exam/sim01/ex03/group.c exam/sim01/ex03/group.h
        exam/sim01/ex03/main.c)
add_executable(sim02_02 exam/sim02/ex02/bst.c exam/sim02/ex02/bst.h
        exam/sim02/ex02/main.c)
add_executable(sim02_03 exam/sim02/ex03/maze.c exam/sim02/ex03/maze.h
        exam/sim02/ex03/main.c)
add_executable(sim03_01 exam/sim03/ex01/extraction.c
        exam/sim03/ex01/extraction.h)
add_executable(sim03_02 exam/sim03/ex02/main.c
        exam/sim03/ex02/multiples.h
        exam/sim03/ex02/multiples.c)
add_executable(sim03_03 exam/sim03/ex03/backpack.c exam/sim03/ex03/backpack.h
        exam/sim03/ex03/main.c)
add_executable(sim04_02 exam/sim04/ex02/potatura.c exam/sim04/ex02/potatura.h
        exam/sim04/ex02/main.c)
add_executable(sim04_03 exam/sim04/ex03/cruciverba.c exam/sim04/ex03/cruciverba.h
        exam/sim04/ex03/main.c)
add_executable(sim05_01 exam/sim05/ex01/even.c exam/sim05/ex01/even.h
        exam/sim05/ex01/main.c)
add_executable(sim05_02 exam/sim05/ex02/compression.c exam/sim05/ex02/compression.h
        exam/sim05/ex02/main.c)
add_executable(sim05_03 exam/sim05/ex03/helper.c exam/sim05/ex03/helper.h
        exam/sim05/ex03/main.c)
