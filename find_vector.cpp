#include <iostream>
#include <vector>
#include <map>

int main() {

	/// Program to check wheter the values of the map contained 
	///in set of vectors or not
	
	std::vector<int> vec = {1,3,4,5,6};
    	std::map<std::pair<int, int>, int> map = {
            {{0, 0}, 0},
            {{0, 1}, 1},
            {{0, 2}, 2},
            {{0, 3}, 3},
            {{1, 0}, 1},
            {{1, 1}, 2},
            {{1, 2}, 3},
            {{1, 3}, 0},
            {{2, 0}, 2},
            {{2, 1}, 3},
            {{2, 2}, 0},
            {{2, 3}, 1},
            {{3, 0}, 3},
            {{3, 1}, 0},
            {{3, 2}, 1},
            {{3, 3}, 2}
    };
    auto it = std::find(vec.begin(), vec.end(), map[std::make_pair(1,2)]);
    for (auto i : vec) {
        if (it != vec.end())
            std::cout << *it.base() << "\n";
    }
    return 0;
}
