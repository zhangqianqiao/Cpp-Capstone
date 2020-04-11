#ifndef GAME_H
#define GAME_H


#include <chrono>
#include <memory>
#include <random>

#include "gameblock.h"
#include "shape.h"
#include "controller.h"

//class controller;
class renderer;

class game
{
public:
    game(std::size_t well_width, std::size_t well_height);
    ~game() = default;

    void run(const controller &cntrllr, renderer &rndrr, std::size_t fps);


private:
    static constexpr int linesToChangeLevel = 10;
    static constexpr int maxLevel = 10;
    static constexpr int delayInterval = 50;

    std::size_t delay;
    std::size_t score;
    std::size_t clearedLines;
    std::size_t level;

    GameBlock gb;
    int x;
    int y;
    std::unique_ptr<Shape> current;

    std::chrono::time_point<std::chrono::system_clock> last_update;

    std::random_device dev;
    std::mt19937 engine;
    std::uniform_int_distribution<int> randomShape;

    void get_next_shape();

    std::size_t drop_down();
    bool move_down();
    bool move_left();
    bool move_right();

    bool gameblock_is_filled_up();
    bool rotateLeft();
    bool rotateRight();

    void update(input ievent);
    void update_delay();
    void update_level(std::size_t lines);
    void update_score(std::size_t cleared_lines, std::size_t dropped_lines);


    bool gameover;
    bool quit;

};



#endif