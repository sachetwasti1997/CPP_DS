cmake_minimum_required(VERSION 3.23)
project(data_structures)

set(CMAKE_CXX_STANDARD 14)

find_package(SDL2 REQUIRED SDL2)

add_executable(data_structures
        depth_first_search/nested_list_weight_sum.cpp
        depth_first_search/find_leaves_bn_tree.cpp
        pairs/ppair.cpp
        vectors/vvectors.cpp
        strings/valid_anagrams.cpp
        program/life_universe.cpp
        trees/leafsimilartree.cpp
        trees/merge_trees.cpp
        trees/next_right_child.cpp
        trees/path_sum.cpp
        trees/find_path_with_sum.cpp
        trees/preorder_traversal.cpp
        trees/post_order.cpp
        trees/sum_root_to_leaf.cpp
        trees/inorder_succss_bst.cpp
        trees/count_univalue_subtree.cpp
        trees/house_robber_3.cpp
        trees/nestedlist_weightSum.cpp
        trees/vertical_order_traversal.cpp
        trees/post_order_cre_tree.cpp
        trees/NTree_dia.cpp
        trees/unq_bin_sch_trr.cpp
        trees/create_n_bst.cpp
        trees/sum_left.cpp
        linked_list/merge_in_between.cpp
        strings/find_replace_pattern.cpp linked_list/add_two_nums.cpp
        hash_map/word_subset.cpp
        graphs/course_schedule.cpp
        graphs/the_maze.cpp
        graphs/closest_node.cpp
        graphs/num_nodes_in_cycle.cpp
        graphs/bipartite.cpp
        graphs/possible_bipart.cpp
        graphs/pacific_atlantic_water_flow.cpp
        graphs/unreachable_nodes.cpp
        graphs/crt_binary_tree.cpp
        graphs/maximum_total_importance.cpp
        graphs/all_ancestor.cpp
        dp/uniq_paths.cpp play.cpp
        linked_list/swap_ndes.cpp
        dp/pascal's_triangle.cpp
        dp/count_bits.cpp
        dp/lcs.cpp
        dp/tribonacci.cpp
        dp/climbing_stairs.cpp
        dp/house_robber.cpp
        dp/min_cost_climbing_stairs.cpp
        dp/house_robber2.cpp
        trie/lexographic_numbers.cpp)

target_link_libraries(data_structures PRIVATE SDL2)
