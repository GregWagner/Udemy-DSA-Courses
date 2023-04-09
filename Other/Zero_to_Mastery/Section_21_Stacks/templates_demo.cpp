#include <iostream>

template <typename T, typename V>
class Pair {
    public:
        void setX(T x) {
            this->x = x;
        }

        T getX() const {
            return x;
        }

        void setY(V y) {
            this->y = y;
        }

        V getY() const {
            return y;
        }

    private:
        T x; 
        V y;
};

int main() {
    Pair<int, double> p1;
    p1.setX(1);
    p1.setY(2.2);
    std::cout << "P1: " << p1.getX() << " " << p1.getY() <<'\n';

    Pair<double, double> p2;
    p2.setX(1.1);
    p2.setY(2.2);
    std::cout << "P2: " << p2.getX() << " " << p2.getY() <<'\n';

    // triplet
    Pair<Pair<int,double>, double> p3;
}
