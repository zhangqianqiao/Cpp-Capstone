#include <algorithm>
#include <iostream>

#include "gameblock.h"
#include "shape.h"


GameBlock::GameBlock(std::size_t width, std::size_t height)
    : well(std::vector<BlockState>(width * height, BlockState::NoBlock)),
      width(width),
      height(height)
{
}

std::vector<BlockState> GameBlock::getWell() const
{
    return std::vector(well);
}

std::size_t GameBlock::getColumns() const
{
    return width;
}

std::size_t GameBlock::getRows() const
{
    return height;
}

bool GameBlock::moveShapeToWell(const Shape &shape_, int x, int y)
{
    const int x_start = x + shape_.x_offset();
    const int y_start = y + shape_.y_offset();

    // Check whether the tetromino fits within the playfield.
    if (x_start < 0 || x_start + shape_.width() > this->width ||
        y_start < 0 || y_start + shape_.heigth() > this->height)
    {
        return false;
    }

    // Check now whether every cell to be filled in by the tetromino is empty.
    const std::vector<int> tetrions = shape_.boxVector();
    for (std::size_t i = 0; i < tetrions.size(); ++i)
    {
        const std::size_t x_t = i % shape_.getBoxSize();
        const std::size_t y_t = i / shape_.getBoxSize();
        if (tetrions[i] && well[(y + y_t) * width + x + x_t] != BlockState::NoBlock)
        {
            return false;
        }
    }

    return true;
}

void GameBlock::storeShapeInWell(const Shape &shape_, int x, int y)
{
    const std::vector<int> tetrions = shape_.boxVector();
    for (std::size_t i = 0; i < tetrions.size(); ++i)
    {
        if (tetrions[i])
        {
            const std::size_t x_t = i % shape_.getBoxSize();
            const std::size_t y_t = i / shape_.getBoxSize();
            well[(y + y_t) * width + x + x_t] = getBlock(shape_);
        }
    }
}

BlockState GameBlock::getBlock(const Shape &shape_)
{
    switch (shape_.type())
    {
    case Tetrominoes::Lineshape:
        return BlockState::LineBlock;

    case Tetrominoes::MirroredLshape:
        return BlockState::MirroredLBlock;
        
    case Tetrominoes::Lshape:
        return BlockState::LBlock;
        
    case Tetrominoes::Squareshape:
        return BlockState::SquareBlock;
        
    case Tetrominoes::Sshape:
        return BlockState::SBlock;
        
    case Tetrominoes::Tshape:
        return BlockState::TBlock;
        
    default: /* tetromino_type::z_block */
        return BlockState::ZBlock;   
    }
}

bool GameBlock::RowCompleted(std::size_t row) const
{
    auto cell_is_not_empy = [] (BlockState st) { return st != BlockState::NoBlock; };
    return std::count_if(well.cbegin() + row * width,
                         well.cbegin() + (row + 1) * width,
                         cell_is_not_empy) == width;
}

std::vector<std::size_t> GameBlock::IndexCompletedRows() const
{
    std::vector<std::size_t> rows;
    for (std::size_t r = height; r > 0;)
    {
        if (RowCompleted(--r))
        {
            rows.push_back(r);
        }
        else if (rows.size() > 0)
        {
            break;
        }
        
    }
    return rows;
}

std::size_t GameBlock::clearRows()
{
    const auto rows = IndexCompletedRows();
    if (rows.size())
    {
        const std::size_t end_row = *(rows.begin()) + 1;
        const std::size_t start_row = *(rows.end() - 1);
        const std::size_t num_deleted_rows = end_row - start_row;
        std::vector<BlockState> tmp(well.size(), BlockState::NoBlock);
        std::copy(well.cbegin(), well.cbegin() + start_row * width,
                  tmp.begin() + num_deleted_rows * width);
        std::copy(well.cbegin() + end_row * width, well.cend(),
                  tmp.begin() + end_row * width);
        well = tmp;
    }
    return rows.size();
}