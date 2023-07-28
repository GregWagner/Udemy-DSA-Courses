#include <iostream>

auto main() -> int
{
    int a[101][101];

    std::cout << "Enter the number of rows and columns: ";
    int rows{}, columns{};
    std::cin >> rows >> columns;

    for (size_t r{}; r < rows; ++r)
    {
        for (size_t c{}; c < columns; ++c)
        {
            std::cin >> a[r][c];
        }
    }

    int xPosition{}, yPosition{};
    int sum{};
    while (xPosition < columns && yPosition < rows)
    {
        sum += a[xPosition][yPosition];
        int nextValue{};
        int bestX{-1};
        int bestY{-1};

        // check right
        if (yPosition + 1 < columns)
        {
            nextValue = a[xPosition][yPosition + 1];
            bestX = xPosition;
            bestY = yPosition;
        }

        // check down
        if (xPosition + 1 < rows)
        {
        }

        // check diagonal
    }
}
