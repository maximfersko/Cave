#include "controller.h"

namespace model {

controller::controller() : cave_(new Cave) {}

controller::controller(Cave *cave) : cave_(cave) {}

controller::~controller() {
    if (cave_) delete cave_;
}

void controller::initiliazeMapCaveFromFile(const std::string &path) {
    cave_->setPath(path);
    cave_->initSizeFromFile();
    cave_->initMap();
}

void controller::generateMapCave(int rows, int columns, int chance) {
    cave_->generateMap(rows, columns, chance);
}

std::pair<std::size_t, std::size_t> controller::getMapCaveSize() {
    return std::make_pair(cave_->getRows(), cave_->getColumns());
}
Matrix<bool> controller::getMapCave() { return cave_->getMap(); }

void controller::setLimits(int deathLimit, int birthLimit) {
    cave_->setLimits(birthLimit, deathLimit);
}

void controller::updateMapCave() { cave_->updateMap(); }

}  // namespace model
