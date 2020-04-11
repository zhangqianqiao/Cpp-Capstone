#ifndef GAMEBLOCK_H
#define GAMEBLOCK_H

#include <vector>

class Shape;

enum class BlockState
{
    NoBlock, 
    ZBlock, 
    SBlock, 
    LineBlock, 
    TBlock, 
    SquareBlock, 
    LBlock, 
    MirroredLBlock
};

class GameBlock
{
public:
    GameBlock(std::size_t width, std::size_t height);
    ~GameBlock() = default;

    std::vector<BlockState> getWell() const;
    std::size_t getColumns() const;
    std::size_t getRows() const;

    bool moveShapeToWell(const Shape &shape_, int x, int y);
    void storeShapeInWell(const Shape &shape_, int x, int y);

    bool RowCompleted(std::size_t row) const;
    std::vector<std::size_t> IndexCompletedRows() const;
    std::size_t clearRows();


private:
    std::size_t width;
    std::size_t height;
    std::vector<BlockState> well;

    BlockState getBlock(const Shape &shape_);
};

#endif