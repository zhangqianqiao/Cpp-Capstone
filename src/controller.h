#ifndef CONTROLLER_H
#define CONTROLLER_H


/**
 * Each of the user inputs.
 */
enum class input
{
    None,
    Drop,
    Down,
    Left,
    Right,
    RotateLeft,
    RotateRight,
    Quit,
};


/**
 * This class handles keyboard inputs using the SDL library.
 */
class controller
{
public:
    /**
     * Returns the current user input as defined by #input.
     */ 
    input getInput() const;
};


#endif  /* CONTROLLER_H */
