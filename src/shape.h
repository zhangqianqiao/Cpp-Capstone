#ifndef SHAPE_H
#define SHAPE_H

#include <map>
#include <vector>


enum class Direction
{
    kUp,
    kDown,
    kLeft,
    kRight
};

enum class Tetrominoes { NoShape, Zshape, Sshape, Lineshape, 
                  Tshape, Squareshape, Lshape, MirroredLshape };


class Shape
{
public:
    Shape();
    virtual ~Shape() = default;
    
    void RotateLeft();
    void RotateRight();


    virtual std::vector<int> boxVector() const = 0;
    virtual int getBoxSize() const = 0;
    virtual Tetrominoes type() const = 0;
    virtual std::size_t width() const = 0;
    virtual std::size_t heigth() const = 0;
    virtual std::size_t x_offset() const = 0;
    virtual std::size_t y_offset() const = 0;

    //Direction getDir(){ return dir; }
    Direction dir;
};

class LineShape : public Shape
{
private:
    static const std::map<Direction, std::vector<int>> shapeTables;

public:

    LineShape() = default;
    ~LineShape() = default;

    std::vector<int> boxVector() const override;
    int getBoxSize() const override;
    Tetrominoes type() const override;
    std::size_t width() const override;
    std::size_t heigth() const override;
    std::size_t x_offset() const override;
    std::size_t y_offset() const override;

};

class MirroredLShape : public Shape
{
private:
    static const std::map<Direction, std::vector<int>> shapeTables;

public:

    MirroredLShape() = default;
    ~MirroredLShape() = default;

    std::vector<int> boxVector() const override;
    int getBoxSize() const override;
    Tetrominoes type() const override;
    std::size_t width() const override;
    std::size_t heigth() const override;
    std::size_t x_offset() const override;
    std::size_t y_offset() const override;

};

class LShape : public Shape
{
private:
    static const std::map<Direction, std::vector<int>> shapeTables;

public:

    LShape() = default;
    ~LShape() = default;

    std::vector<int> boxVector() const override;
    int getBoxSize() const override;
    Tetrominoes type() const override;
    std::size_t width() const override;
    std::size_t heigth() const override;
    std::size_t x_offset() const override;
    std::size_t y_offset() const override;

};

class SquareShape : public Shape
{
private:
    static const std::map<Direction, std::vector<int>> shapeTables;

public:

    SquareShape() = default;
    ~SquareShape() = default;

    std::vector<int> boxVector() const override;
    int getBoxSize() const override;
    Tetrominoes type() const override;
    std::size_t width() const override;
    std::size_t heigth() const override;
    std::size_t x_offset() const override;
    std::size_t y_offset() const override;

};

class SShape : public Shape
{
private:
    static const std::map<Direction, std::vector<int>> shapeTables;

public:

    SShape() = default;
    ~SShape() = default;

    std::vector<int> boxVector() const override;
    int getBoxSize() const override;
    Tetrominoes type() const override;
    std::size_t width() const override;
    std::size_t heigth() const override;
    std::size_t x_offset() const override;
    std::size_t y_offset() const override;

};

class TShape : public Shape
{
private:
    static const std::map<Direction, std::vector<int>> shapeTables;

public:

    TShape() = default;
    ~TShape() = default;

    std::vector<int> boxVector() const override;
    int getBoxSize() const override;
    Tetrominoes type() const override;
    std::size_t width() const override;
    std::size_t heigth() const override;
    std::size_t x_offset() const override;
    std::size_t y_offset() const override;

};

class ZShape : public Shape
{
private:
    static const std::map<Direction, std::vector<int>> shapeTables;

public:

    ZShape() = default;
    ~ZShape() = default;

    std::vector<int> boxVector() const override;
    int getBoxSize() const override;
    Tetrominoes type() const override;
    std::size_t width() const override;
    std::size_t heigth() const override;
    std::size_t x_offset() const override;
    std::size_t y_offset() const override;

};




#endif