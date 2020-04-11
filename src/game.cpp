#include <chrono>
#include <memory>
#include <thread>

#include "controller.h"
#include "game.h"
#include "gameblock.h"
#include "renderer.h"
#include "shape.h"

game::game(std::size_t well_width, std::size_t well_height)
    : gameover(false),
      quit(false),
      delay(0),
      score(0),
      clearedLines(0),
      level(1),
      gb(GameBlock(well_width, well_height)),
      x(0),
      y(0),
      current(nullptr),
      last_update(std::chrono::system_clock::now()),
      engine(dev()),
      randomShape(0, 7)
{
    update_delay();
}

void game::run(const controller &cntrllr, renderer &rndrr, std::size_t fps)
{
    const std::size_t target_frame_duration = 1000 / fps;
    bool running = true;

    get_next_shape();

    while (!gameover && !quit)
    {
        const auto frame_start = std::chrono::system_clock::now();

        const input inpt = cntrllr.getInput();
        update(inpt);
        rndrr.render(gb, *current, x, y, score, level);

        // If the time for this frame is too small (i.e. frame_duration is
        // smaller than the target ms per frame), delay the loop o achieve
        // the correct frame rate.
        const auto frame_end = std::chrono::system_clock::now();
        const auto frame_duration = std::chrono::duration_cast<std::chrono::milliseconds>(frame_end - frame_start).count();
        if (frame_duration < target_frame_duration)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(target_frame_duration - frame_duration));
        }
    }

    if (!quit)
    {
        // Wait until the user quits the game by closing the window.
        while (cntrllr.getInput() != input::Quit)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(target_frame_duration));
        }
    }
}

void game::get_next_shape()
{
    const int type = randomShape(engine);
    switch (type)
    {
    case 0:
        current = std::make_unique<LineShape>();
        break;
    
    case 1:
        current = std::make_unique<MirroredLShape>();
        break;
    
    case 2:
        current = std::make_unique<LShape>();
        break;

    case 3:
        current = std::make_unique<SquareShape>();
        break;

    case 4:
        current = std::make_unique<SShape>();
       break;
    
    case 5:
        current = std::make_unique<TShape>();
        break;
    
    default:
        current = std::make_unique<ZShape>();
        break;
    }

    // Sets the starting point within the playfield (half of the topmost row).
    x = (gb.getColumns() - current->getBoxSize()) / 2;
    y = 0;

    // Update the time point to calculate the next falling instant.
    last_update = std::chrono::system_clock::now();
}

std::size_t game::drop_down()
{
    std::size_t count = 0;
    // Ground is reached when the tetromino cannot go further down.
    while (move_down())
    {
        ++count;
    }
    update_score(0, count);
    return count;
}

bool game::move_down()
{
    bool success = false;
    if (gb.moveShapeToWell(*current, x, y + 1))
    {
        ++y;
        success = true;
    }
    else
    {
        // The tetromino has touched ground if it cannot go further down, so store it
        // into the playfield and update game state.
        gb.storeShapeInWell(*current, x, y);
        const std::size_t count = gb.clearRows();
        update_score(count, 0);
        update_level(count);
        get_next_shape();
    }
    return success;
}

bool game::move_left()
{
    bool success = false;
    if (gb.moveShapeToWell(*current, x - 1, y))
    {
        --x;
        success = true;
    }
    return success;
}


bool game::move_right()
{
    bool success = false;
    if (gb.moveShapeToWell(*current, x + 1, y))
    {
        ++x;
        success = true;
    }
    return success;
}

bool game::gameblock_is_filled_up() 
{
   
    return !gb.moveShapeToWell(*current, x, y);
    
}

bool game::rotateLeft()
{
    bool success = false;
    current->RotateLeft();
    if (gb.moveShapeToWell(*current, x, y))
    {
        success = true;
    }else
    {
        current->RotateRight();
    }
    return success;   
}


bool game::rotateRight()
{
    bool success = false;
    current->RotateRight();
    if (gb.moveShapeToWell(*current, x, y))
    {
        success = true;
    }
    else
    {
        current->RotateLeft();
    }
    return success;   
}

void game::update(input iEvent)
{
    switch (iEvent)
    {
    case input::Drop:
        drop_down();
        break;
        
    case input::Down:
        move_down();
        break;
    
    case input::Right:
        move_right();
        break;    

    case input::Left:
        move_left();
        break;

    case input::RotateLeft:
        rotateLeft();
        break;
    case input::RotateRight:
        rotateRight();
        break;
    case input::None:
        // Is it time to make the current tetromino fall one more cell?
        if (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - last_update).count() > delay)
        {
            move_down();
            last_update = std::chrono::system_clock::now();
        }
        break;

    case input::Quit:
        quit = true;
        break;

    default:
        break;
    }

    gameover = gameblock_is_filled_up();
}

void game::update_delay()
{
    delay = ((maxLevel + 1 - level) * delayInterval);
}

void game::update_level(std::size_t lines)
{
    if (level < maxLevel)
    {
        clearedLines += lines;
        if (clearedLines >= linesToChangeLevel)
        {
            ++level;
            clearedLines -= linesToChangeLevel;
        }
        update_delay();
    }
}

void game::update_score(std::size_t cleared_lines, std::size_t dropped_lines)
{
    constexpr uint ppl[] { 0, 40, 100, 300, 1200, };
    score += 2 * dropped_lines;
    score += (ppl[cleared_lines] * (level + 1));
}

