#include "RoundedRectangle.hpp"
#include <cmath>
#include <iostream>

namespace Lucy
{

    ////////////////////////////////////////////////////////////
    RoundedRectangle::RoundedRectangle(const sf::Vector2f& size, float radius, unsigned int cornerPointCount, const unsigned int& displayCorners)
    {
        mySize = size;
        myRadius = radius;
        myCornerPointCount = cornerPointCount;
        myCorners = displayCorners;
        NumberOfRoundedCorners = 0;

        if (displayCorners & Lucy::Corners::TopRight)
        {
            NumberOfRoundedCorners++;
            swapIndex[0] = myCornerPointCount - 1;
        }
        else
        {
            swapIndex[0] = 0;
            IndexAdjustment[1] = myCornerPointCount - 1;
        }

        if (displayCorners & Lucy::Corners::TopLeft)
        {
            NumberOfRoundedCorners++;
            swapIndex[1] = myCornerPointCount + swapIndex[0];
        }
        else
        {
            swapIndex[1] = 1 + swapIndex[0];
            IndexAdjustment[2] = myCornerPointCount - 1 + IndexAdjustment[1];
        }

        if (displayCorners & Lucy::Corners::BottomLeft)
        {
            NumberOfRoundedCorners++;
            swapIndex[2] = myCornerPointCount + swapIndex[1];
        }
        else
        {
            swapIndex[2] = 1 + swapIndex[1];
            IndexAdjustment[3] = myCornerPointCount - 1 + IndexAdjustment[2] + IndexAdjustment[1];
        }

        if (displayCorners & Lucy::Corners::BottomRight)
        {
            NumberOfRoundedCorners++;
            swapIndex[3] = myCornerPointCount + swapIndex[2];
        }
        else
        {
            swapIndex[3] = 1 + swapIndex[2];
        }

        ActualPoints = (myCornerPointCount * NumberOfRoundedCorners) + 4 - NumberOfRoundedCorners;

        //90 degress divided by the number of segments we want
        deltaAngle = M_PI_2 / (myCornerPointCount - 1);
        centerIndex = 0;
        update();
    }

    ////////////////////////////////////////////////////////////
    void RoundedRectangle::setDisplayCorners(unsigned int displayCorners)
    {
        myCorners = displayCorners;
        update();
    }

    ////////////////////////////////////////////////////////////
    void RoundedRectangle::Size(const sf::Vector2f& size)
    {
        mySize = size;
        update();
    }

    ////////////////////////////////////////////////////////////
    const sf::Vector2f& RoundedRectangle::Size() const
    {
        return mySize;
    }

    ////////////////////////////////////////////////////////////
    void RoundedRectangle::CornerRadius(float radius)
    {
        myRadius = radius;
        update();
    }

    ////////////////////////////////////////////////////////////
    float RoundedRectangle::CornerRadius() const
    {
        return myRadius;
    }

    ////////////////////////////////////////////////////////////
    void RoundedRectangle::CornerPointCount(unsigned int count)
    {
        myCornerPointCount = count;
        update();
    }

    ////////////////////////////////////////////////////////////
    std::size_t RoundedRectangle::getPointCount() const
    {
        //we need to see how many corners first
        return ActualPoints;
    }

    ////////////////////////////////////////////////////////////
    sf::Vector2f RoundedRectangle::getPoint(std::size_t index) const
    {
        if (index >= ActualPoints)
            return sf::Vector2f(0, 0);

        //Find out what corner we are working on
        if (index > swapIndex[centerIndex])
            centerIndex++;

        //this gives the current angle or segment we need to calculate for
        double idx = deltaAngle * ((double)index + (double)IndexAdjustment[centerIndex] - centerIndex);
        float myCos = myRadius * (float)cos(idx);
        float mySin = -myRadius * (float)sin(idx);

        switch (centerIndex)
        {
        case 0:
            //Top Right
            return myCorners & Lucy::Corners::TopRight ? sf::Vector2f(myCos + mySize.x - myRadius, mySin + myRadius) : sf::Vector2f(mySize.x, 0);
            break;
        case 1:
            //Top Left 
            return myCorners & Lucy::Corners::TopLeft ? sf::Vector2f(myCos + myRadius, mySin + myRadius) : sf::Vector2f(0, 0);
            break;
        case 2:
            //Bottom Left
            return myCorners & Lucy::Corners::BottomLeft ? sf::Vector2f(myCos + myRadius, mySin + mySize.y - myRadius) : sf::Vector2f(0, mySize.y);
            break;
        case 3:
            //Bottom Right
            return myCorners & Lucy::Corners::BottomRight ? sf::Vector2f(myCos + mySize.x - myRadius, mySin + mySize.y - myRadius) : sf::Vector2f(mySize.x, mySize.y);
            break;
        }

        //drop here is there some dodge problem. Should never get here
        return sf::Vector2f(0, 0);
    }
}
