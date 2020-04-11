#include "shape.h"

Shape::Shape() : dir(Direction::kDown)
{
}

void Shape::RotateLeft()
{
    switch (dir)
    {
    case Direction::kDown:
        dir = Direction::kLeft;
        break;
    
    case Direction::kLeft:
        dir = Direction::kUp;
        break;
    
    case Direction::kUp:
        dir = Direction::kRight;
        break;
    
    case Direction::kRight:
        dir = Direction::kDown;
        break;
    
    default:
        break;
    }
}

void Shape::RotateRight()
{
    switch (dir)
    {
    case Direction::kDown:
        dir = Direction::kRight;
        break;
    
    case Direction::kRight:
        dir = Direction::kUp;
        break;
    
    case Direction::kUp:
        dir = Direction::kLeft;
        break;
    
    case Direction::kLeft:
        dir = Direction::kDown;
        break;
    
    default:
        break;
    }
}

//LineShape
const std::map<Direction, std::vector<int>> LineShape::shapeTables = {

    { Direction::kDown,  { 0, 0, 0, 0,
                           1, 1, 1, 1,
                           0, 0, 0, 0,
                           0, 0, 0, 0, },
    },

    { Direction::kLeft,  { 0, 0, 1, 0,
                           0, 0, 1, 0,
                           0, 0, 1, 0,
                           0, 0, 1, 0, },
    },

    { Direction::kUp,    { 0, 0, 0, 0,
                           0, 0, 0, 0,
                           1, 1, 1, 1,
                           0, 0, 0, 0, },
    },

    { Direction::kRight, { 0, 1, 0, 0,
                           0, 1, 0, 0,
                           0, 1, 0, 0,
                           0, 1, 0, 0, },
    },
};


std::vector<int> LineShape::boxVector() const
{
    return shapeTables.at(dir);
}

int LineShape::getBoxSize() const { return 4; }

Tetrominoes LineShape::type() const { return Tetrominoes::Lineshape; }

std::size_t LineShape::width() const
{
    return dir == Direction::kDown || dir == Direction::kUp ? 4 : 1;
}

std::size_t LineShape::heigth() const
{
    return dir == Direction::kDown || dir == Direction::kUp ? 1 : 4;
}

std::size_t LineShape::x_offset() const
{

     switch (dir)
    {
    case Direction::kLeft:
        return 2;

    case Direction::kRight:
        return 1;

    default:
        return 0;
    }
}


std::size_t LineShape::y_offset() const
{
    switch (dir)
    {
    case Direction::kDown:
        return 1;

    case Direction::kUp:
        return 2;

    default:
        return 0;
    }
}

//MirroredLShape
const std::map<Direction, std::vector<int>> MirroredLShape::shapeTables = {

    { Direction::kDown,  { 1, 0, 0,
                           1, 1, 1,
                           0, 0, 0, },
    },

    { Direction::kLeft,  { 0, 1, 1,
                           0, 1, 0,
                           0, 1, 0, },
    },

    { Direction::kUp,    { 0, 0, 0, 
                           1, 1, 1, 
                           0, 0, 1, },
    },

    { Direction::kRight, { 0, 1, 0,
                           0, 1, 0,
                           1, 1, 0, },
    },
};

std::vector<int> MirroredLShape::boxVector() const
{
    return shapeTables.at(dir);
}

int MirroredLShape::getBoxSize() const { return 3; }

Tetrominoes MirroredLShape::type() const { return Tetrominoes::MirroredLshape; }

std::size_t MirroredLShape::width() const
{
    return dir == Direction::kDown || dir == Direction::kUp ? 3 : 2;
}

std::size_t MirroredLShape::heigth() const
{
    return dir == Direction::kDown || dir == Direction::kUp ? 2 : 3;
}

std::size_t MirroredLShape::x_offset() const
{
    return dir == Direction::kLeft ? 1 : 0;
}


std::size_t MirroredLShape::y_offset() const
{
    return dir == Direction::kUp ? 1 : 0;
}

// LShape
const std::map<Direction, std::vector<int>> LShape::shapeTables = {

    { Direction::kDown,  { 0, 0, 1,
                           1, 1, 1,
                           0, 0, 0, },
    },

    { Direction::kLeft,  { 0, 1, 0,
                           0, 1, 0,
                           0, 1, 1, },
    },

    { Direction::kUp,    { 0, 0, 0, 
                           1, 1, 1, 
                           1, 0, 0, },
    },

    { Direction::kRight, { 1, 1, 0,
                           0, 1, 0,
                           0, 1, 0, },
    },
};

std::vector<int> LShape::boxVector() const
{
    return shapeTables.at(dir);
}

int LShape::getBoxSize() const { return 3; }

Tetrominoes LShape::type() const { return Tetrominoes::Lshape; }

std::size_t LShape::width() const
{
    return dir == Direction::kDown || dir == Direction::kUp ? 3 : 2;
}

std::size_t LShape::heigth() const
{
    return dir == Direction::kDown || dir == Direction::kUp ? 2 : 3;
}

std::size_t LShape::x_offset() const
{
    return dir == Direction::kLeft ? 1 : 0;
}


std::size_t LShape::y_offset() const
{
    return dir == Direction::kUp ? 1 : 0;
}


//SquareShape
const std::map<Direction, std::vector<int>> SquareShape::shapeTables = {

    { Direction::kDown,  { 1, 1,
                           1, 1,},
    },

    { Direction::kLeft,  { 1, 1,
                           1, 1, },
    },

    { Direction::kUp,    {1, 1,
                          1, 1, },
    },

    { Direction::kRight, {1, 1,
                          1, 1,},
    },
};

std::vector<int> SquareShape::boxVector() const
{
    return shapeTables.at(dir);
}

int SquareShape::getBoxSize() const { return 2; }

Tetrominoes SquareShape::type() const { return Tetrominoes::Squareshape; }

std::size_t SquareShape::width() const
{
    return 2;
}

std::size_t SquareShape::heigth() const
{
    return 2;
}

std::size_t SquareShape::x_offset() const
{
    return 0;
}


std::size_t SquareShape::y_offset() const
{
    return 0;
}

//SShape

const std::map<Direction, std::vector<int>> SShape::shapeTables = {

    { Direction::kDown,  { 0, 1, 1,
                           1, 1, 0,
                           0, 0, 0, },
    },

    { Direction::kLeft,  { 0, 1, 0,
                           0, 1, 1,
                           0, 0, 1, },
    },

    { Direction::kUp,    { 0, 0, 0, 
                           0, 1, 1, 
                           1, 1, 0, },
    },

    { Direction::kRight, { 1, 0, 0,
                           1, 1, 0,
                           0, 1, 0, },
    },
};

std::vector<int> SShape::boxVector() const
{
    return shapeTables.at(dir);
}

int SShape::getBoxSize() const { return 3; }

Tetrominoes SShape::type() const { return Tetrominoes::Sshape; }

std::size_t SShape::width() const
{
    return dir == Direction::kDown || dir == Direction::kUp ? 3 : 2;;
}

std::size_t SShape::heigth() const
{
    return dir == Direction::kDown || dir == Direction::kUp ? 2 : 3;
}

std::size_t SShape::x_offset() const
{
    return dir == Direction::kLeft ? 1 : 0;
}


std::size_t SShape::y_offset() const
{
    return dir == Direction::kUp ? 1 : 0;
}


//TShape
const std::map<Direction, std::vector<int>> TShape::shapeTables = {

    { Direction::kDown,  { 0, 1, 0,
                           1, 1, 1,
                           0, 0, 0, },
    },

    { Direction::kLeft,  { 0, 1, 0,
                           0, 1, 1,
                           0, 1, 0, },
    },

    { Direction::kUp,    { 0, 0, 0, 
                           1, 1, 1, 
                           0, 1, 0, },
    },

    { Direction::kRight, { 0, 1, 0,
                           1, 1, 0,
                           0, 1, 0, },
    },
};

std::vector<int> TShape::boxVector() const
{
    return shapeTables.at(dir);
}

int TShape::getBoxSize() const { return 3; }

Tetrominoes TShape::type() const { return Tetrominoes::Tshape; }

std::size_t TShape::width() const
{
    return dir == Direction::kDown || dir == Direction::kUp ? 3 : 2;;
}

std::size_t TShape::heigth() const
{
    return dir == Direction::kDown || dir == Direction::kUp ? 2 : 3;
}

std::size_t TShape::x_offset() const
{
    return dir == Direction::kLeft ? 1 : 0;
}


std::size_t TShape::y_offset() const
{
    return dir == Direction::kUp ? 1 : 0;
}

//ZShape
const std::map<Direction, std::vector<int>> ZShape::shapeTables = {

    { Direction::kDown,  { 1, 1, 0,
                                 0, 1, 1,
                                 0, 0, 0, },
    },

    { Direction::kLeft,  { 0, 0, 1,
                                 0, 1, 1,
                                 0, 1, 0, },
    },

    { Direction::kUp,    { 0, 0, 0, 
                                 1, 1, 0, 
                                 0, 1, 1, },
    },

    { Direction::kRight, { 0, 1, 0,
                                 1, 1, 0,
                                 1, 0, 0, },
    },
};

std::vector<int> ZShape::boxVector() const
{
    return shapeTables.at(dir);
}

int ZShape::getBoxSize() const { return 3; }

Tetrominoes ZShape::type() const { return Tetrominoes::Zshape; }

std::size_t ZShape::width() const
{
    return dir == Direction::kDown || dir == Direction::kUp ? 3 : 2;;
}

std::size_t ZShape::heigth() const
{
    return dir == Direction::kDown || dir == Direction::kUp ? 2 : 3;
}

std::size_t ZShape::x_offset() const
{
    return dir == Direction::kLeft ? 1 : 0;
}


std::size_t ZShape::y_offset() const
{
    return dir == Direction::kUp ? 1 : 0;
}