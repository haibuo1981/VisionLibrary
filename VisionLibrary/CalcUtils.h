#ifndef _CALC_UTILS_H_
#define _CALC_UTILS_H_

#include "BaseType.h"
#include "VisionHeader.h"
#include <math.h>

namespace AOI
{
namespace Vision
{

class CalcUtils
{
private:
    CalcUtils();
    CalcUtils(CalcUtils const &);
    CalcUtils(CalcUtils const &&);
    CalcUtils &operator=(CalcUtils const &);        
    ~CalcUtils();
public:
    template<typename T>
    static float distanceOf2Point(const cv::Point_<T> &pt1, const cv::Point_<T> &pt2)
    {
        float fOffsetX = ( float ) pt1.x - pt2.x;
        float fOffsetY = ( float ) pt1.y - pt2.y;
        float fDistance = sqrt(fOffsetX * fOffsetX + fOffsetY * fOffsetY);
        return fDistance;
    }

    template<typename T>
    static double calcSlopeDegree(const cv::Point_<T> &pt1, const cv::Point_<T> &pt2)
    {
        return radian2Degree ( atan2f ( pt2.y - pt1.y, pt2.x - pt1.x ) );
    }

    template<typename T>
    static cv::Point_<T>midOf2Points(const cv::Point_<T> &pt1, const cv::Point_<T> &pt2)
    {
        return cv::Point_<T>( ( pt1.x + pt2.x ) / 2.f, ( pt1.y + pt2.y ) / 2.f );
    }

    template<typename T>
    static cv::Rect_<T> scaleRect(const cv::Rect_<T> &rectInput, float fScale)
    {
        return cv::Rect_<T> (cv::Point_<T>(rectInput.x + ( 1.f - fScale ) * rectInput.width, rectInput.y + ( 1.f - fScale ) * rectInput.height ),
            cv::Point_<T>(rectInput.x + ( 1.f + fScale ) * rectInput.width, rectInput.y + ( 1.f + fScale ) * rectInput.height ) );
    }

    template<typename T>
    static double MatSquareSum(const cv::Mat &mat)
    {
        double dSum = 0;
        for (int row = 0; row < mat.rows; ++row)
            for (int col = 0; col < mat.cols; ++col)
            {
                float fValue = mat.at<T>(row, col);
                dSum += fValue * fValue;
            }
        return dSum;
    }

    //Calculate deviation in one pass. The algorithm is get from https://www.strchr.com/standard_deviation_in_one_pass
    template<typename T>
    static double calcStdDeviation(std::vector<T> vecValue)
    {
        if (vecValue.empty())
            return 0.0;
        double sum = 0;
        double sq_sum = 0;
        for (const auto value : vecValue) {
            sum += value;
            sq_sum += value * value;
        }
        auto n = vecValue.size();
        double mean = sum / n;
        double variance = sq_sum / n - mean * mean;
        return sqrt(variance);
    }

    static double radian2Degree( double dRadian );
    static double degree2Radian( double dDegree );
    static double ptDisToLine(const cv::Point2f ptInput, float fSlope, float fIntercept );
    static PR_Line2f calcEndPointOfLine( const VectorOfPoint &vecPoint, float fSlope, float fIntercept );
    static cv::Point2f lineIntersect(float fSlope1, float fIntercept1, float fSlope2, float fIntercept2);
    static float lineSlope(const PR_Line2f &line);
};

}
}
#endif