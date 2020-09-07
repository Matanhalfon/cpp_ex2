//
// Created by matanhalfon on 9/4/19.
//
#include <iostream>
#include "Fractal.h"
#include <stack>
#include <fstream>
#include <sstream>

#define INVALID "Invalid input\n"
#define USEGE "Usage: FractalDrawer <file path>\n"
#define  IOERROR "Exception opening/reading/closing file\n"
#define MEMOERROR "Memory alloction failed\n"
static const int CantorD = 3;
static const int SCarpet = 1;
static const int LsragestDim = 6;
static const int SmallestDim = 1;
static const int NumOfChars = 3;
static const int NumOfArgs = 2;

/**
 * a factory taht create the right  shpae acoording to the input
 * @param type
 * @param dim
 * @return
 */
Fractal *fractelFactory(int *type, int *dim)
{
    switch (*type)
    {
        case 1:
            return new Sc(*dim);
        case 2:
            return new Ss(*dim);
        case 3:
            return new Cd(*dim);
        default:
            return nullptr;
    }
}

/**
 * a function that read a file line into 2 int pointers
 * @param line the line to read
 * @param type the type of the Fractal to assign
 * @param dim the dim of the Fractla to assign
 * @return True if the line  is according to format  false if out of format
 */

bool readLine(const std::string &line, int *type, int *dim)
{
    char c;
    std::istringstream iss(line);
    iss >> *type >> c >> *dim;
    return !(line.length() != NumOfChars || c != ',' || iss.fail() || *type > CantorD || *type < SCarpet ||
             *dim > LsragestDim || *dim < SmallestDim);
}

/**
 * get an stack of Fractals and prints them to the consol
 * @param shapes the stack of Fractals
 */
void printout(std::stack<Fractal *> shapes)
{
    int sizes = (int) shapes.size();
    for (int i = 0; i < sizes; i++)
    {
        shapes.top()->drewF(shapes.top()->getDim());
        std::cout << std::endl;
        delete shapes.top();
        shapes.pop();
    }
}

/**
 * reads the Farctals from the file and set them into a stack
 * @param shapesa stack of Fractals to set the fractals in
 * @param csvFile the file to read factals according to the format
 * @returnif there is an ilegal lines returns false and prints out the mess
 * tre if all lines was legal
 */
bool getShapes(std::stack<Fractal *> &shapes, std::ifstream &csvFile)
{
    int type, dim;
    std::string line;
    while (csvFile.good())
    {
        std::getline(csvFile, line);
        if (line.empty())
        {
            if (csvFile.good())
            {
                std::cerr << INVALID;
                return false;
            }
            return true;
        }
        if (readLine(line, &type, &dim))
        {
            try//checks if allocation was failed
            {
                shapes.push(fractelFactory(&type, &dim));
            } catch (std::bad_alloc &ba)
            {
                std::cerr << MEMOERROR;
                return false;
            }
        }
        else
        {
            std::cerr << INVALID;
            return false;
        }
    }
    return true;
}

/**
 * the main function that reads lines of Fractals from the file and prints out the fractas according to thier dim and shapes
 * @param argc the number of args -2
 * @param argv the args
 * @return 1 if failed ,0 else
 */
int main(int argc, char *argv[])
{
    if (argc != NumOfArgs)
    {
        std::cerr << USEGE;
        return EXIT_FAILURE;
    }
    std::stack<Fractal *> shapes;
    try//open a stream
    {
        std::ifstream csvFile(argv[1]);

        if (csvFile.good())
        {
            if (!getShapes(shapes, csvFile))
            {
                int sizes = (int) shapes.size();
                for (int i = 0; i < sizes; i++)
                {
                    delete shapes.top();
                    shapes.pop();
                }
                return EXIT_FAILURE;
            }
        }
        else
        {
            std::cerr << INVALID;
            return EXIT_FAILURE;
        }
    } catch (std::ifstream::failure &e)
    {
        std::cerr << IOERROR;
    }

    printout(shapes);
    return EXIT_SUCCESS;
}
