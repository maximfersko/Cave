#ifndef A1_MAZE_0_CAVE_H
#define A1_MAZE_0_CAVE_H

#include <random>

#include "matrix/matrix.h"

namespace model {

enum condition { kDead = 0, kAlive };

class Cave {
   private:
    int rows_ = 0;
    int columns_ = 0;
    Matrix<bool> map_;
    int birth_limit_, death_limit_;
    std::string path_;

   private:
    int countNeighbors(const Matrix<bool> &map, int i, int j);
    int generateRandomPercent(const int percent);

   public:
    Cave() = default;
    ~Cave() = default;
    Cave(size_t rows, size_t columns);
    Cave(const std::string &path);
    void initSizeFromFile();
    void initMap();
    size_t getRows() { return rows_; }
    size_t getColumns() { return columns_; }
    Matrix<bool> getMap() { return map_; }
    void setPath(const std::string &path) { path_ = path; }
    void generateMap(const int rows, const int columns, const int chance);
    void updateMap();
    void setLimits(int birth, int death) {
        birth_limit_ = birth;
        death_limit_ = death;
    }
};
}  // namespace model

#endif  // A1_MAZE_0_CAVE_H
