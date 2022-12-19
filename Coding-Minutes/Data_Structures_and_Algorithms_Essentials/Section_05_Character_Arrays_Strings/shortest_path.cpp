/*
 * Given a long route containing NSEW directions, find the shortest
 * path to reach the location.
 * Example
 *      SNNNEWE -> NNE
 */
#include <iostream>
#include <sstream>

std::pair<int, int> calculatePosition(const std::string& route) {
    int x_position {};
    int y_position {};

    for (const auto c : route) {
        if (c == 'N') {
            ++y_position;
        } else if (c == 'S') {
            --y_position;
        } else if (c == 'E') {
            ++x_position;
        } else {
            --x_position;
        }
    }
    return { x_position, y_position };
}

void printFinalPosition(std::pair<int, int> position) {
    std::ostringstream output;

    int x_position { position.first };
    int y_position { position.second };

    bool going_north = y_position > 0;
    while (y_position--) {
        output << (going_north ? 'N' : 'S');
    }

    bool going_east = x_position > 0;
    while (x_position--) {
        output << (going_east ? 'E' : 'W');
    }
    std::cout << output.str() << '\n';
}

int main() {
    std::string route = "SNNNEWE";

    auto final_position = calculatePosition(route);
    printFinalPosition(final_position);
}
