#ifndef _AOI_UNWRAP_H_
#define _AOI_UNWRAP_H_

#include "VisionHeader.h"

namespace AOI
{
namespace Vision
{

using DATA_TYPE = float;

class Unwrap
{
public:
    Unwrap ();
    ~Unwrap ();
    static void calib3DBase(const std::vector<cv::Mat> &vecInputImgs, bool bEnableGaussianFilter, bool bReverseSeq, cv::Mat &matThickToThinStripeK, cv::Mat &matBaseSurfaceParam );
    static void calib3DHeight(const PR_CALIB_3D_HEIGHT_CMD *const pstCmd, PR_CALIB_3D_HEIGHT_RPY *const pstRpy);
    static void calc3DHeight(const PR_CALC_3D_HEIGHT_CMD *const pstCmd, PR_CALC_3D_HEIGHT_RPY *const pstRpy);
    static void calcMTF(const PR_CALC_MTF_CMD *const pstCmd, PR_CALC_MTF_RPY *const pstRpy);
private:
    static cv::Mat _getResidualPoint(const cv::Mat &matInput, cv::Mat &matPosPole, cv::Mat &matNegPole);
    static VectorOfPoint _selectLonePole(ListOfPoint &listPoint, int width, int height, size_t nLonePoneCount );
    static void _selectPolePair(const VectorOfPoint &vecPosPoint, const VectorOfPoint &vecNegPoint, int rows, int cols, VectorOfPoint &vecResult1, VectorOfPoint &vecResult2, VectorOfPoint &vecResult3 );
    static VectorOfPoint _getIntegralTree(const VectorOfPoint &vecResult1, const VectorOfPoint &vecResult2, const VectorOfPoint &vecResult3 );
    static cv::Mat _phaseUnwrapSurface(const cv::Mat &matPhase);
    static cv::Mat _phaseUnwrapSurfaceTrk ( const cv::Mat &matPhase, const cv::Mat &matBranchCut);
    static cv::Mat _phaseUnwrapSurfaceByRefer(const cv::Mat &matPhase, const cv::Mat &matRef );
    static cv::Mat _calculatePPz(const cv::Mat &matX, const cv::Mat &matY, const cv::Mat &matZ);
    static cv::Mat _calculateBaseSurface(int rows, int cols, const cv::Mat &matBaseSurfaceParam);
    static cv::Mat _setBySign(cv::Mat &matInput, DATA_TYPE value );
    static void _findUnstablePoint(const std::vector<cv::Mat> &vecInputImgs, float fDiffTol, float fAvgTol, cv::Mat &matDiffUnderTolIndex, cv::Mat &matAvgUnderTolIndex);
    static cv::Mat _drawHeightGrid(const cv::Mat &matHeight, int nGridRow, int nGridCol);
    static const int GUASSIAN_FILTER_SIZE =     11;
    static const int BEZIER_RANK =              5;
    static const int ERODE_WIN_SIZE =           41;

    static const float GUASSIAN_FILTER_SIGMA;
    static const float ONE_HALF_CYCLE;
    static const float UNSTABLE_DIFF;
    static const float REMOVE_HEIGHT_NOSIE_RATIO;
};

}
}
#endif /*_AOI_UNWRAP_H_*/