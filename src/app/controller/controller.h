#pragma once

#include "../model/cave.h"
#include <memory>

namespace model {

class controller {
   private:
    Cave *cave_;

   public:
    controller();
    controller(Cave *cave);
    ~controller();

    void initiliazeMapCaveFromFile(const std::string &);
    std::pair<std::size_t, std::size_t> getMapCaveSize();
    Matrix<bool> getMapCave();
    void generateMapCave(int rows, int columns, int chance);
    std::pair<std::size_t, std::size_t> getMazeSizeRC();
    void setLimits(int deathLimit, int birthLimit);
    void updateMapCave();
    void saveFile(const std::string &path);
};

}  // namespace model
