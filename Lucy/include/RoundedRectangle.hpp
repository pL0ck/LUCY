#pragma once

#define _USE_MATH_DEFINES

#include <cmath>
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics/Shape.hpp>
#include "Config.hpp"

namespace Lucy
{

    ////////////////////////////////////////////////////////////
    /// \brief Specialized shape representing a rectangle
    /// with rounded corners
    ////////////////////////////////////////////////////////////
    class LUCY_API RoundedRectangle : public sf::Shape
    {
    public:
        RoundedRectangle();
        ////////////////////////////////////////////////////////////
        /// \brief Default constructor
        ///
        /// \param size PsetSize of the rectangle
        /// \param radius Radius for each rounded corner
        /// \param cornerPointCount Number of points of each corner
        ///
        ////////////////////////////////////////////////////////////
        void RoundedRectangle2(const sf::Vector2f& size = sf::Vector2f(0, 0), float radius = 0, unsigned int cornerPointCount = 0, const Lucy::Corners& displayCorners = Lucy::Corners::All);

        ////////////////////////////////////////////////////////////
        /// \brief Set the size of the rounded rectangle
        ///
        /// \param size New size of the rounded rectangle
        ///
        /// \see getSize
        ///
        ////////////////////////////////////////////////////////////
        void setSize(const sf::Vector2f& size);

        ////////////////////////////////////////////////////////////
        /// \brief Get the size of the rounded rectangle
        ///
        /// \return PsetSize of the rounded rectangle
        ///
        /// \see PsetSize
        ///
        ////////////////////////////////////////////////////////////
        const sf::Vector2f& getSize() const;

        ////////////////////////////////////////////////////////////
        /// \brief Set the radius of the rounded corners
        ///
        /// \param radius Radius of the rounded corners
        ///
        /// \see getCornersRadius
        ///
        ////////////////////////////////////////////////////////////
        void setCornerRadius(float radius);

        ////////////////////////////////////////////////////////////
        /// \brief Get the radius of the rounded corners
        ///
        /// \return Radius of the rounded corners
        ///
        /// \see setCornersRadius
        ///
        ////////////////////////////////////////////////////////////
        float getCornerRadius() const;

        ////////////////////////////////////////////////////////////
        /// \brief Set the number of points of each corner
        ///
        /// \param count New number of points of the rounded rectangle
        ///
        /// \see getPointCount
        ///
        ////////////////////////////////////////////////////////////
        void setCornerPointCount(unsigned int count);

        ////////////////////////////////////////////////////////////
        /// \brief Set the corners to display
        ///
        /// \param a list of corners
        ///
        ////////////////////////////////////////////////////////////
        void setDisplayCorners(const Lucy::Corners& displayCorners);

        ////////////////////////////////////////////////////////////
        /// \brief Get the number of points defining the rounded rectangle
        ///
        /// \return Number of points of the rounded rectangle
        ///
        ////////////////////////////////////////////////////////////
        virtual std::size_t getPointCount() const;

        ////////////////////////////////////////////////////////////
        /// \brief Get a point of the rounded rectangle
        ///
        /// The result is undefined if \a index is out of the valid range.
        ///
        /// \param index Index of the point to get, in range [0 .. GetPointCount() - 1]
        ///
        /// \return Index-th point of the shape
        ///
        ////////////////////////////////////////////////////////////
        virtual sf::Vector2f getPoint(std::size_t index) const;

        ////////////////////////////////////////////////////////////
        /// \brief Update teh shape when properties change
        ///
        ///
        ////////////////////////////////////////////////////////////
        void UpdateShape();


    private:
       ////////////////////////////////////////////////////////////
       // Member data
       ////////////////////////////////////////////////////////////
        sf::Vector2f mySize;
        float myRadius;
        unsigned int myCornerPointCount;
        unsigned int myCorners;
        unsigned int NumberOfRoundedCorners;
        unsigned int ActualPoints;
        double deltaAngle;
        mutable std::size_t centerIndex;
        unsigned int swapIndex[4];
        unsigned int IndexAdjustment[4] = { 0,0,0,0 };
    };
}
