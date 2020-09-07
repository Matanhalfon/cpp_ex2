//
// Created by matanhalfon on 9/4/19.
//

#include "Fractal.h"
#include <math.h>
#include <iostream>

static const int ScFactor = 3;
static const int SsFactor = 2;
static const int CdFactor = 3;
static const int Middle = 1;

/**
 * the diffult function that return in which index to print # and
 * @param x xcord
 * @param y ycord
 * @param factor the size factor for the shape 2-‫‪Sierpinski‬‬ ‫‪Sieve 3-‫‪Sierpinski‬‬ ‫‪Carpet
 * @return
 */
bool Fractal::isMarked(int x, int y, int factor)
{
    while (x != 0 && y != 0)
    {
        if (x % factor == Middle && y % factor == Middle)
        {
            return false;
        }
        x /= factor;
        y /= factor;
    }
    return true;
}

/**
 * chaecks if the current cord is marked # or not for a ‫‪Cantor‬‬ ‫‪Dust‬‬ an override func
 * @param x x cord
 * @param y y cord
 * @return true if it needed to print #  false else
 */
bool Cd::isMarked(int x, int y)
{
    while (x != 0 || y != 0)
    {
        if (x % CdFactor == Middle || y % CdFactor == Middle)
        {
            return false;
        }
        x /= CdFactor;
        y /= CdFactor;
    }
    return true;
}

/**
 *Drew a ‫‪Cantor‬‬ ‫‪Dust‬‬‬‬‬ of the n dim
 * @param n an dimtion
 */
void Cd::drewF(int n)
{
    int hight = (int) (pow(CdFactor, n));
    for (int i = 0; i < hight; i++)
    {
        for (int j = 0; j < hight; j++)
        {
            if (isMarked(i, j))
            {
                std::cout << "#";
            }
            else
            {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}

/**
 *Drew a ‫‪Sierpinski‬‬ ‫‪Sieve‬‬‬‬ of the n dim
 * @param n an dimtion
 */
void Ss::drewF(int n)
{
    int hight = (int) (pow(SsFactor, n));
    for (int i = 0; i < hight; i++)
    {
        for (int j = 0; j < hight; j++)
        {
            if (isMarked(i, j, SsFactor))
            {
                std::cout << "#";
            }
            else
            {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}

/**
 *Drew a ‫‪Sierpinski‬‬ ‫‪Carpet‬‬ of the n dim
 * @param n an dimtion
 */
void Sc::drewF(int n)
{
    int hight = (int) (pow(ScFactor, n));
    for (int i = 0; i < hight; i++)
    {
        for (int j = 0; j < hight; j++)
        {
            if (isMarked(i, j, ScFactor))
            {
                std::cout << "#";
            }
            else
            {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}

/**
 * returns the Fractal dim
 * @return
 */
int Fractal::getDim()
{
    return dim;
}





