
#include <iostream>

#define DLLEXPORT
#include "VisionAPI.h"
#include "VisionAlgorithm.h"
#include "TimeLog.h"
#include "RecordManager.h"
#include "Config.h"
#include "Version.h"
#include "SubFunctions.h"
#include "Log.h"
#include "CalcUtils.h"

#define PR_FUNCTION_ENTRY   \
try \
{

#define PR_FUNCTION_EXIT    \
}catch(std::exception &e)   \
{   \
    WriteLog(e.what()); \
    pstRpy->enStatus = VisionStatus::OPENCV_EXCEPTION;  \
    return VisionStatus::OPENCV_EXCEPTION;  \
}

namespace AOI
{
namespace Vision
{

VisionAPI void PR_GetVersion(PR_VERSION_INFO *pstVersionInfo)
{
    if ( nullptr != pstVersionInfo )
        _snprintf(pstVersionInfo->chArrVersion, sizeof (pstVersionInfo->chArrVersion), AOI_VISION_VERSION );
}

VisionAPI VisionStatus PR_Init()
{
    return RecordManager::getInstance()->load();
}

VisionAPI VisionStatus PR_LrnObj(const PR_LRN_OBJ_CMD *const pstCmd, PR_LRN_OBJ_RPY *const pstRpy)
{
PR_FUNCTION_ENTRY
    return VisionAlgorithm::lrnObj ( pstCmd, pstRpy );
PR_FUNCTION_EXIT
}

VisionAPI VisionStatus PR_SrchObj(const PR_SRCH_OBJ_CMD *const pstCmd, PR_SRCH_OBJ_RPY *const pstRpy)
{
PR_FUNCTION_ENTRY
        return VisionAlgorithm::srchObj ( pstCmd, pstRpy );
PR_FUNCTION_EXIT
}

VisionAPI VisionStatus PR_InspSurface(PR_INSP_SURFACE_CMD *const pInspCmd, PR_INSP_SURFACE_RPY *pInspRpy)
{
    try
    {
        VisionAlgorithmPtr pVA = VisionAlgorithm::create();
        return pVA->inspSurface ( pInspCmd, pInspRpy );
    }catch(std::exception &e)
    {
        WriteLog(e.what());
        return VisionStatus::OPENCV_EXCEPTION;
    }
}

VisionAPI void PR_DumpTimeLog(const std::string &strPath)
{
    TimeLog::GetInstance()->dumpTimeLog(strPath);
}

VisionAPI VisionStatus PR_FreeRecord(Int32 nRecordID)
{
    return RecordManager::getInstance()->free(nRecordID);
}

VisionAPI VisionStatus  PR_FreeAllRecord()
{
    return RecordManager::getInstance()->freeAllRecord();
}

VisionAPI VisionStatus  PR_LrnDevice(PR_LRN_DEVICE_CMD *pstLrnDeviceCmd, PR_LRN_DEVICE_RPY *pstLrnDeivceRpy)
{
    try
    {
        VisionAlgorithmPtr pVA = VisionAlgorithm::create();
        return pVA->lrnDevice ( pstLrnDeviceCmd, pstLrnDeivceRpy );
    }catch(std::exception &e)
    {
        WriteLog(e.what());
        return VisionStatus::OPENCV_EXCEPTION;
    }
}

VisionAPI VisionStatus PR_InspDevice(PR_INSP_DEVICE_CMD *pstInspDeviceCmd, PR_INSP_DEVICE_RPY *pstInspDeivceRpy)
{
    try
    {
        VisionAlgorithmPtr pVA = VisionAlgorithm::create();
        return pVA->inspDevice ( pstInspDeviceCmd, pstInspDeivceRpy );
    }catch(std::exception &e)
    {
        WriteLog(e.what());
        return VisionStatus::OPENCV_EXCEPTION;
    }
}

VisionAPI void PR_SetDebugMode(PR_DEBUG_MODE enDebugMode)
{
    Config::GetInstance()->setDebugMode(enDebugMode);
}

VisionAPI VisionStatus  PR_RunLogCase(const std::string &strPath)
{
    try
    {
        return VisionAlgorithm::runLogCase( strPath);
    }catch(std::exception &e)
    {
        WriteLog(e.what());
        return VisionStatus::OPENCV_EXCEPTION;
    }
}

VisionAPI VisionStatus PR_SrchFiducialMark(PR_SRCH_FIDUCIAL_MARK_CMD *pstCmd, PR_SRCH_FIDUCIAL_MARK_RPY *pstRpy)
{
    try
    {
        VisionAlgorithmPtr pVA = VisionAlgorithm::create();
        return pVA->srchFiducialMark ( pstCmd, pstRpy );
    }catch(std::exception &e)
    {
        WriteLog(e.what());
        return VisionStatus::OPENCV_EXCEPTION;
    }
}

VisionAPI VisionStatus  PR_FitLine(PR_FIT_LINE_CMD *pstCmd, PR_FIT_LINE_RPY *pstRpy)
{
PR_FUNCTION_ENTRY
    return VisionAlgorithm::fitLine ( pstCmd, pstRpy );
PR_FUNCTION_EXIT
}

VisionAPI VisionStatus  PR_Caliper(const PR_CALIPER_CMD *const pstCmd, PR_CALIPER_RPY *const pstRpy)
{
PR_FUNCTION_ENTRY
    return VisionAlgorithm::caliper ( pstCmd, pstRpy );
PR_FUNCTION_EXIT
}

VisionAPI VisionStatus  PR_FitParallelLine(PR_FIT_PARALLEL_LINE_CMD *pstCmd, PR_FIT_PARALLEL_LINE_RPY *pstRpy)
{
    try
    {
        VisionAlgorithmPtr pVA = VisionAlgorithm::create();
        return pVA->fitParallelLine ( pstCmd, pstRpy );
    }catch(std::exception &e)
    {
        WriteLog(e.what());
        return VisionStatus::OPENCV_EXCEPTION;
    }
}

VisionAPI VisionStatus  PR_FitRect(PR_FIT_RECT_CMD *pstCmd, PR_FIT_RECT_RPY *pstRpy)
{
    try
    {
        VisionAlgorithmPtr pVA = VisionAlgorithm::create();
        return pVA->fitRect ( pstCmd, pstRpy );
    }catch(std::exception &e)
    {
        WriteLog(e.what());
        pstRpy->enStatus = VisionStatus::OPENCV_EXCEPTION;
        return VisionStatus::OPENCV_EXCEPTION;
    }
}

VisionAPI VisionStatus  PR_FindEdge(PR_FIND_EDGE_CMD *pstCmd, PR_FIND_EDGE_RPY *pstRpy)
{
    try
    {
        VisionAlgorithmPtr pVA = VisionAlgorithm::create();
        return pVA->findEdge ( pstCmd, pstRpy );
    }catch(std::exception &e)
    {
        WriteLog(e.what());
        return VisionStatus::OPENCV_EXCEPTION;
    }
}

VisionStatus  PR_FitCircle(PR_FIT_CIRCLE_CMD *pstCmd, PR_FIT_CIRCLE_RPY *pstRpy)
{
    try
    {
        return VisionAlgorithm::fitCircle ( pstCmd, pstRpy );
    }catch(std::exception &e)
    {
        WriteLog(e.what());
        return VisionStatus::OPENCV_EXCEPTION;
    }
}

VisionAPI VisionStatus PR_GetErrorStr(VisionStatus enStatus, PR_GET_ERROR_STR_RPY *pstRpy)
{
    return GetErrorInfo(enStatus, pstRpy);
}

VisionAPI VisionStatus PR_Ocr(PR_OCR_CMD *pstCmd, PR_OCR_RPY *pstRpy)
{
    try
    {
        VisionAlgorithmPtr pVA = VisionAlgorithm::create();
        return pVA->ocr ( pstCmd, pstRpy );
    }catch(std::exception &e)
    {
        WriteLog(e.what());
        return VisionStatus::OPENCV_EXCEPTION;
    }
}

VisionAPI VisionStatus PR_PointLineDistance(PR_POINT_LINE_DISTANCE_CMD *pstCmd, PR_POINT_LINE_DISTANCE_RPY *pstRpy)
{
    pstRpy->fDistance = CalcUtils::ptDisToLine ( pstCmd->ptInput, pstCmd->bReversedFit, pstCmd->fSlope, pstCmd->fIntercept );
    return VisionStatus::OK;
}

VisionAPI VisionStatus PR_ColorToGray(PR_COLOR_TO_GRAY_CMD *pstCmd, PR_COLOR_TO_GRAY_RPY *pstRpy)
{
PR_FUNCTION_ENTRY
    return VisionAlgorithm::colorToGray ( pstCmd, pstRpy );
PR_FUNCTION_EXIT
}

VisionAPI VisionStatus PR_Filter(PR_FILTER_CMD *pstCmd, PR_FILTER_RPY *pstRpy)
{
PR_FUNCTION_ENTRY
    return VisionAlgorithm::filter( pstCmd, pstRpy );
PR_FUNCTION_EXIT
}

VisionAPI VisionStatus PR_AutoThreshold(PR_AUTO_THRESHOLD_CMD *pstCmd, PR_AUTO_THRESHOLD_RPY *pstRpy)
{
PR_FUNCTION_ENTRY
    return VisionAlgorithm::autoThreshold( pstCmd, pstRpy );
PR_FUNCTION_EXIT
}

VisionAPI VisionStatus PR_RemoveCC(PR_REMOVE_CC_CMD *pstCmd, PR_REMOVE_CC_RPY *pstRpy)
{
PR_FUNCTION_ENTRY
    return VisionAlgorithm::removeCC( pstCmd, pstRpy );
PR_FUNCTION_EXIT
}

VisionAPI VisionStatus PR_DetectEdge(PR_DETECT_EDGE_CMD *pstCmd, PR_DETECT_EDGE_RPY *pstRpy)
{
PR_FUNCTION_ENTRY
    return VisionAlgorithm::detectEdge( pstCmd, pstRpy );
PR_FUNCTION_EXIT
}

VisionAPI VisionStatus PR_CircleRoundness(PR_CIRCLE_ROUNDNESS_CMD *pstCmd, PR_CIRCLE_ROUNDNESS_RPY *pstRpy)
{
PR_FUNCTION_ENTRY
    return VisionAlgorithm::circleRoundness( pstCmd, pstRpy );
PR_FUNCTION_EXIT
}

VisionAPI VisionStatus PR_FillHole(PR_FILL_HOLE_CMD *const pstCmd, PR_FILL_HOLE_RPY *pstRpy)
{
PR_FUNCTION_ENTRY
    return VisionAlgorithm::fillHole( pstCmd, pstRpy );
PR_FUNCTION_EXIT
}

VisionAPI VisionStatus PR_MatchTmpl(PR_MATCH_TEMPLATE_CMD *const pstCmd, PR_MATCH_TEMPLATE_RPY *pstRpy)
{
PR_FUNCTION_ENTRY
    return VisionAlgorithm::matchTemplate( pstCmd, pstRpy );
PR_FUNCTION_EXIT
}

VisionAPI VisionStatus PR_PickColor(PR_PICK_COLOR_CMD *const pstCmd, PR_PICK_COLOR_RPY *pstRpy)
{
PR_FUNCTION_ENTRY
    return VisionAlgorithm::pickColor( pstCmd, pstRpy );
PR_FUNCTION_EXIT
}

VisionAPI VisionStatus PR_CalibrateCamera(const PR_CALIBRATE_CAMERA_CMD *const pstCmd, PR_CALIBRATE_CAMERA_RPY *const pstRpy)
{
PR_FUNCTION_ENTRY
    return VisionAlgorithm::calibrateCamera( pstCmd, pstRpy );
PR_FUNCTION_EXIT
}

VisionAPI VisionStatus PR_RestoreImage(const PR_RESTORE_IMG_CMD *const pstCmd, PR_RESTORE_IMG_RPY *const pstRpy)
{
PR_FUNCTION_ENTRY
    return VisionAlgorithm::restoreImage( pstCmd, pstRpy );
PR_FUNCTION_EXIT
}

VisionAPI VisionStatus PR_CalcUndistortRectifyMap(const PR_CALC_UNDISTORT_RECTIFY_MAP_CMD *const pstCmd, PR_CALC_UNDISTORT_RECTIFY_MAP_RPY *const pstRpy)
{
PR_FUNCTION_ENTRY
    return VisionAlgorithm::calcUndistortRectifyMap( pstCmd, pstRpy );
PR_FUNCTION_EXIT
}

VisionAPI VisionStatus PR_AutoLocateLead(const PR_AUTO_LOCATE_LEAD_CMD *const pstCmd, PR_AUTO_LOCATE_LEAD_RPY *const pstRpy)
{
PR_FUNCTION_ENTRY
    return VisionAlgorithm::autoLocateLead( pstCmd, pstRpy );
PR_FUNCTION_EXIT
}

VisionAPI VisionStatus PR_InspBridge(const PR_INSP_BRIDGE_CMD *const pstCmd, PR_INSP_BRIDGE_RPY *const pstRpy)
{
PR_FUNCTION_ENTRY
    return VisionAlgorithm::inspBridge( pstCmd, pstRpy );
PR_FUNCTION_EXIT
}

}
}