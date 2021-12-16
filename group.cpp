/// Program that check given set of numbers
/// and dictionary is a group or not

#include <bits/stdc++.h>

typedef std::pair<size_t, size_t> Pair;

bool IsGroup(std::set<size_t> &set, std::map<Pair, size_t> &map) {
    size_t inverse_element = 0;
    size_t neutral_element;
    size_t counter = 0;
    /// in case dictionary is empty we don't do anything
    if (map.empty()) {
        return false;
    }
    /// First check the size of the our dictionary with the elements of the set
    if (map.size() != (size_t) std::pow(set.size(), 2))
        return false;
    std::vector<size_t> vec;
    for (auto i: set) {
        for (auto j: set) {
            /// Check whether the elements of our set exist in dictionary or not
            if (!set.contains(map[std::make_pair(i, j)])) {
                return false;
            }
            /// Check for associativity property
            for (auto k: set) {
                size_t first_temp = map[std::make_pair(i, j)];
                size_t second_temp = map[std::make_pair(j, k)];
                if (map[std::make_pair(first_temp, k)] != map[std::make_pair(i, second_temp)]) {
                    return false;
                }
            }
            /// if i find the neutral element in the set i will make equal to the second key of dictionary
            /// the purpose of the increasing the counter one is that when i find the different  neutral element
            /// i will return false after this if because of uniqueness of the neutral element 
            if (map[std::make_pair(i, j)] == i && counter == 0) {
                neutral_element = j;
                counter++;
            }
            /// why counter is >0 because i set is as 1 and when i come here and check whether i have 2 different 
            /// neutral elements and i return false
            if (map[std::make_pair(i, j)] == i && counter > 0 && j != neutral_element)
                return false;
            if (map[std::make_pair(i, j)] == neutral_element)
                inverse_element++;
        }
    }
    /// If our inverse element doesnt suit with the size of our set return false
    if (inverse_element != set.size())
        return false;
    return true;
}

bool IsAbelianGroup(std::set<size_t> &vector, std::map<Pair, size_t> &map) {

    /// firstly check whether it is a group or not
    if (!IsGroup(vector, map)) {
        return false;
    }
    /// Check whether it has commutativity property
    for (auto i: vector) {
        for (auto j: vector) {
            if (map[std::make_pair(i, j)] != map[std::make_pair(j, i)]) {
                return false;
            }
        }
    }
    return true;
}

void Solve() {
    size_t size_of_map;
    std::cout << "Enter size of map: ";
    std::cin >> size_of_map;
    std::set<size_t> set = {0, 1, 2};
    std::map<Pair, size_t> dict;
    /// Make a dictionary
    for (int i = 0; i < size_of_map; ++i) {
        size_t m, n, value;
        std::cin >> m >> n >> value;
        dict.insert(std::make_pair(std::make_pair(m, n), value));
    }
    if (IsGroup(set, dict)) {
        std::cout << "Our set is a group" << "\n";
        if (IsAbelianGroup(set, dict)) {
            std::cout << "Our set is an Abelian group" << "\n";
        } else {
            std::cout << "Our set is not an Abelian group" << "\n";
        }
    } else {
        std::cout << "Our set is not  a group" << "\n";
    }
}

int main() {
    Solve();
    return 0;
}
/// Sample input, you can easily copy and paste to check for the being group

/**
0 0 0
0 1 1
0 2 2
0 3 3
0 4 4
1 0 1
1 1 2
1 2 3
1 3 4
1 4 0
2 0 2
2 1 3
2 2 4
2 3 0
2 4 1
3 0 3
3 1 4
3 2 0
3 3 1
3 4 2
4 0 4
4 1 0
4 2 1
4 3 2
4 4 3
 **/
