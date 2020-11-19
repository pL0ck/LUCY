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
    enum Corners : unsigned int
    {
        None = 0x00,
        TopRight = 0x01,
        TopLeft = 0x02,
        BottomLeft = 0x04,
        BottomRight = 0x08,
        All = 0xF
    };

    ////////////////////////////////////////////////////////////
    /// \brief Specialized shape representing a rectangle
    /// with rounded corners
    ////////////////////////////////////////////////////////////
    class LUCY_API RoundedRectangle : public sf::Shape
    {
    public:
        ////////////////////////////////////////////////////////////
        /// \brief Default constructor
        ///
        /// \param size Size of the rectangle
        /// \param radius Radius for each rounded corner
        /// \param cornerPointCount Number of points of each corner
        ///
        ////////////////////////////////////////////////////////////
        explicit RoundedRectangle(const sf::Vector2f& size = sf::Vector2f(0, 0), float radius = 0, unsigned int cornerPointCount = 0, const unsigned int& displayCorners = Lucy::Corners::All);

        ////////////////////////////////////////////////////////////
        /// \brief Set the size of the rounded rectangle
        ///
        /// \param size New size of the rounded rectangle
        ///
        /// \see getSize
        ///
        ////////////////////////////////////////////////////////////
        void Size(const sf::Vector2f& size);

        ////////////////////////////////////////////////////////////
        /// \brief Get the size of the rounded rectangle
        ///
        /// \return Size of the rounded rectangle
        ///
        /// \see setSize
        ///
        ////////////////////////////////////////////////////////////
        const sf::Vector2f& Size() const;

        ////////////////////////////////////////////////////////////
        /// \brief Set the radius of the rounded corners
        ///
        /// \param radius Radius of the rounded corners
        ///
        /// \see getCornersRadius
        ///
        ////////////////////////////////////////////////////////////
        void CornerRadius(float radius);

        ////////////////////////////////////////////////////////////
        /// \brief Get the radius of the rounded corners
        ///
        /// \return Radius of the rounded corners
        ///
        /// \see setCornersRadius
        ///
        ////////////////////////////////////////////////////////////
        float CornerRadius() const;

        ////////////////////////////////////////////////////////////
        /// \brief Set the number of points of each corner
        ///
        /// \param count New number of points of the rounded rectangle
        ///
        /// \see getPointCount
        ///
        ////////////////////////////////////////////////////////////
        void CornerPointCount(unsigned int count);

        ////////////////////////////////////////////////////////////
        /// \brief Set the corners to display
        ///
        /// \param a list of corners
        ///
        ////////////////////////////////////////////////////////////
        void setDisplayCorners(unsigned int displayCorners);

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
