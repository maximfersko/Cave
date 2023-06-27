#include "cave.h"

namespace model {

Cave::Cave(const std::string &path) : path_(path) {}

Cave::Cave(size_t rows, size_t columns) : rows_(rows), columns_(columns) {}

void Cave::initSizeFromFile() {
    std::ifstream file(path_);
    if (file.is_open()) {
        std::string line;
        getline(file, line);
        rows_ = std::stoi(line.substr(0), nullptr);
        columns_ = std::stoi(line.substr(2), nullptr);
        file.close();
    }
}

void Cave::initMap() {
    map_ = Matrix<bool>(rows_, columns_);
    map_.initMatrix(path_);
}

int Cave::generateRandomPercent(const int percent) {
    static std::random_device random;
    static std::default_random_engine generator(random());
    static std::uniform_int_distribution<int> distribution(0, 100);
    return distribution(generator) <= percent;
}

void Cave::generateMap(const int rows, const int columns, const int chance) {
    rows_ = rows;
    columns_ = columns;
    map_ = Matrix<bool>(rows_, columns_);
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < columns_; ++j) {
            map_(i, j) = generateRandomPercent(chance);
        }
    }
}

int Cave::countNeighbors(const Matrix<bool> &map, int i, int j) {
    int count = 0;
    for (int x = -1; x <= 1; ++x) {
        for (int y = -1; y <= 1; ++y) {
            int neighbor_x = i + x;
            int neighbor_y = j + y;
            if (x == 0 && y == 0) {
            } else if (neighbor_x < 0 || neighbor_y < 0 ||
                       neighbor_x >= rows_ || neighbor_y >= columns_) {
                ++count;
            } else if (map(neighbor_x, neighbor_y) == kAlive) {
                ++count;
            }
        }
    }
    return count;
}

void Cave::updateMap() {
    if (rows_ > 0 && columns_ > 0) {
        Matrix<bool> new_map(rows_, columns_);
        for (int i = 0; i < map_.GetRows(); ++i) {
            for (int j = 0; j < map_.GetColumns(); ++j) {
                int neighbors = countNeighbors(map_, i, j);
                if (map_(i, j) == kAlive) {
                    new_map(i, j) = (neighbors < death_limit_) ? kDead : kAlive;
                } else {
                    new_map(i, j) = (neighbors > birth_limit_) ? kAlive : kDead;
                }
            }
        }
        map_ = new_map;
    }
}

}  // namespace model
