#include "RoundedRectangle.hpp"
#include <cmath>
#include <iostream>

namespace Lucy
{
    RoundedRectangle::RoundedRectangle()
    {
        std::cout << "Default constructor for RR" << "\n";
        mySize=sf::Vector2f(75.f,25.f);
        myRadius=5.f;
        myCornerPointCount=5;
        myCorners=Lucy::Corners::All;
        NumberOfRoundedCorners=0;
        ActualPoints = 0;
        centerIndex = 0;
        deltaAngle = 0;
        swapIndex[0] = 0;
        swapIndex[1] = 0;
        swapIndex[2] = 0;
        swapIndex[3] = 0;
    }

    ////////////////////////////////////////////////////////////
    void RoundedRectangle::RoundedRectangle2(const sf::Vector2f& size, float radius, unsigned int cornerPointCount, const Lucy::Corners& displayCorners)
    {
        std::cout << "Setting up RR" << "\n";
        setSize(size);
        setCornerRadius(radius);
        setCornerPointCount(cornerPointCount);
        setDisplayCorners(displayCorners);
        std::cout << "RR setup complete" << "\n";
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
    void RoundedRectangle::setDisplayCorners(const Lucy::Corners& displayCorners)
    {
        myCorners = displayCorners;
        update();
    }

    ////////////////////////////////////////////////////////////
    void RoundedRectangle::setSize(const sf::Vector2f& size)
    {
        mySize = size;
        std::cout << "Size: " << size.x << "," << size.y << "\n";
        //update();
        //std::cout << "Size update complete" << "\n";
    }

    ////////////////////////////////////////////////////////////
    const sf::Vector2f& RoundedRectangle::getSize() const
    {
        return mySize;
    }

    ////////////////////////////////////////////////////////////
    void RoundedRectangle::setCornerRadius(float radius)
    {
        myRadius = radius;
        update();
    }

    ////////////////////////////////////////////////////////////
    float RoundedRectangle::getCornerRadius() const
    {
        return myRadius;
    }

    ////////////////////////////////////////////////////////////
    void RoundedRectangle::setCornerPointCount(unsigned int count)
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
        if (index == 0)
            centerIndex = 0;

        if (index >= ActualPoints)
            return sf::Vector2f(0, 0);

        //Find out what corner we are working on
        if (index > swapIndex[centerIndex])
            centerIndex++;

        //this gives the current angle or segment we need to calculate for
        double idx = deltaAngle * ((double)index + (double)IndexAdjustment[centerIndex] - centerIndex);
        float myCos = myRadius * (float)cos(idx);
        float mySin = -myRadius * (float)sin(idx);
        sf::Vector2f tr;
        sf::Vector2f tl;
        sf::Vector2f bl;
        sf::Vector2f br;

        switch (centerIndex)
        {
        case 0:
            //Top Right
            tr= myCorners & Lucy::Corners::TopRight ? sf::Vector2f(myCos + mySize.x - myRadius, mySin + myRadius) : sf::Vector2f(mySize.x, 0);
            std::cout << "TR: " << tr.x << "," << tr.y << "\n";
            return myCorners & Lucy::Corners::TopRight ? sf::Vector2f(myCos + mySize.x - myRadius, mySin + myRadius) : sf::Vector2f(mySize.x, 0);
            break;
        case 1:
            //Top Left
            tl= myCorners & Lucy::Corners::TopLeft ? sf::Vector2f(myCos + myRadius, mySin + myRadius) : sf::Vector2f(0, 0);
            std::cout << "TL: " << tl.x << "," << tl.y << "\n";
            return myCorners & Lucy::Corners::TopLeft ? sf::Vector2f(myCos + myRadius, mySin + myRadius) : sf::Vector2f(0, 0);
            break;
        case 2:
            //Bottom Left
            bl= myCorners & Lucy::Corners::BottomLeft ? sf::Vector2f(myCos + myRadius, mySin + mySize.y - myRadius) : sf::Vector2f(0, mySize.y);
            std::cout << "BL: " << bl.x << "," << bl.y << "\n";
            return myCorners & Lucy::Corners::BottomLeft ? sf::Vector2f(myCos + myRadius, mySin + mySize.y - myRadius) : sf::Vector2f(0, mySize.y);
            break;
        case 3:
            //Bottom Right
            br= myCorners & Lucy::Corners::BottomRight ? sf::Vector2f(myCos + mySize.x - myRadius, mySin + mySize.y - myRadius) : sf::Vector2f(mySize.x, mySize.y);
            std::cout << "BR: " << br.x << "," << br.y << "\n";
            return myCorners & Lucy::Corners::BottomRight ? sf::Vector2f(myCos + mySize.x - myRadius, mySin + mySize.y - myRadius) : sf::Vector2f(mySize.x, mySize.y);
            break;
        }

        //drop here is there some dodge problem. Should never get here
        return sf::Vector2f(0, 0);
    }
    void RoundedRectangle::UpdateShape()
    {
        update();
    }
}
