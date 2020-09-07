//
// Created by matanhalfon on 9/4/19.
//

#ifndef CPP_EX2_FRACTAL_H
#define CPP_EX2_FRACTAL_H


/**
 * an Father Fractal class
 */
class Fractal
{
protected:
    int dim;

public:
    /**
 * a default dtor
 */
    virtual ~Fractal() = default;

    /**
     * a default copy ctor
     * @param other
     */
    Fractal(const Fractal &other) = default;

    /**
     * an assign operator
     * @param other  anther  fractal
     * @return this  fractal
     */
    Fractal &operator=(const Fractal &other) = default;

    /**
     * an Move Ctor
     * @param other anther  fractal
     */
    Fractal(Fractal && other) noexcept = default;

    /**
     * an Move Operator
     * @param other anther  fractal
     * @return this  fractal
     */
    Fractal &operator=(Fractal && other) noexcept = default;
    /**
    * an ctor for Fractal is protected so only the children can use it
    * @param dimtion
    */
    explicit Fractal(int dimtion) : dim(dimtion)
    {}

    /**
     * a pure virtual fuction that all of the childs of Fractal will implement
     * @param n  the dim
     */
    virtual void drewF(int n) = 0;

    /**
     * a function  that return if the current index is # or " "
     * @param x the x cord
     * @param y the y cord
     * @param factor the size factor 2- Ss 3-Sc
     * @return true if # flase if " "
     */
    virtual bool isMarked(int x, int y, int factor);

    /**
     * return the dim of the fractal
     * @return the dim of the fractal
     */
    int getDim();
};

/**
 * a  class of a ‫‪Sierpinski‬‬ ‫‪Carpet dervied  from Fractal
 */
class Sc : public Fractal
{
public:
    explicit Sc(int dimtion1) : Fractal(dimtion1)
    {}

    /**
     * a default copy ctor
     * @param other
     */
    Sc(const Sc &other) = default;

    /**
     * an assign operator
     * @param other  anther Sc fractal
     * @return this Sc fractal
     */
    Sc &operator=(const Sc &other) = default;

    /**
     * an Move Ctor
     * @param other anther Sc fractal
     */
    Sc(Sc && other) noexcept = default;

    /**
     * an Move Operator
     * @param other anther Sc fractal
     * @return this Sc fractal
     */
    Sc &operator=(Sc && other) noexcept = default;

/**
 * the function of the ‫‪Sierpinski‬‬ ‫‪Carpet Fractal that prints out the fractal according to it dimentions
 * @param n
 */
    void drewF(int n) override;
};

/**
 *  a  class of a ‫‪Sierpinski‬‬ ‫‪Sieve dervied  from Fractal
 */
class Ss : public Fractal
{
public:
    explicit Ss(int dimtion1) : Fractal(dimtion1)
    {}

    /**
     * a default copy ctor
     * @param other
     */
    Ss(const Ss &other) = default;

    /**
     * an assin operator
     * @param other anther Ss fractal
     * @return  this fractal
     */
    Ss &operator=(const Ss &other) = default;

    /**
     * a Move ctor
     * @param other anther fractal
     */
    Ss(Ss && other) noexcept = default;

    /**
     * a Move operator
     * @param other anther Ss fractal
     * @return this Ss fractal
     */
    Ss &operator=(Ss && other) noexcept = default;

    /**
 * the function of the ‫‪Sierpinski‬‬ ‫‪Carpet Fractal that prints out the fractal according to it dimentions
 * @param n
 */
    void drewF(int n) override;
};

/**
 * a  class of a ‫‪Sierpinski‬‬ ‫‪Carpet dervied  from Fractal
 */
class Cd : public Fractal
{
public:
    explicit Cd(int dimtion1) : Fractal(dimtion1)
    {}


    /**
     * a default copy ctor
     * @param other
     */
    Cd(const Cd &other) = default;

    /**
     * an default assignment
     * @param other  other CD fractal
     * @return this Fractal
     */
    Cd &operator=(const Cd &other) = default;

    /**
     * an Move ctor
     * @param other anther CD fractal
     */
    Cd(Cd && other) noexcept = default;

    /**
     * an Move operator
     * @param other anther Cd fractal
     * @return this fractal
     */
    Cd &operator=(Cd && other) noexcept = default;

/**
 * an override fucntion for the it Father and return if it we need to print # or " " at that index
 * @param x xcord
 * @param y ycord
 * @return true if # false if ' '
 */
    bool isMarked(int x, int y);

/**
 * prints out an CD fractal according to the dim
 * @param n
 */
    void drewF(int n) override;
};


#endif //CPP_EX2_FRACTAL_H
