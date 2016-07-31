#ifndef _AOI_STRUCT_H_
#define _AOI_STRUCT_H_

#include "VisionType.h"
#include "opencv2/core/core.hpp"
#include "BaseType.h"

using namespace cv;

namespace AOI
{
namespace Vision
{

using VectorOfDMatch = std::vector<cv::DMatch> ;
using VectorOfVectorOfDMatch = std::vector<VectorOfDMatch>;
using VectorOfKeyPoint =  std::vector<cv::KeyPoint> ;
using VectorOfVectorKeyPoint = std::vector<VectorOfKeyPoint> ;
using VectorOfPoint = std::vector<cv::Point2f>;
#define ToInt32(param)      (static_cast<Int32>(param))
#define ToFloat(param)      (static_cast<float>(param))

struct PR_LEARN_TMPL_CMD
{
	PR_ALIGN_ALGORITHM      enAlgorithm;
	cv::Mat                 mat;
	cv::Mat                 mask;
	cv::Rect2f              rectLrn;
};

struct PR_LEARN_TMPL_RPY
{
	Int16                  nStatus;
	std::vector<KeyPoint>  vecKeyPoint;
	cv::Mat                matDescritor;
	cv::Mat                matTmpl;
	Point2f                ptCenter;
    Int32                  nRecordID;
};

struct PR_SRCH_TMPL_CMD
{
	PR_ALIGN_ALGORITHM     enAlgorithm;
	cv::Rect2f             rectLrn;
	cv::Mat                mat;
	cv::Rect               rectSrchWindow;
	cv::Point2f            ptExpectedPos;
    Int32                  nRecordID;
};

struct PR_SRCH_TMPL_RPY
{
	Int16					nStatus;
	float					fMatchScore;
	cv::Mat					matHomography;
	cv::Point2f				ptObjPos;
	cv::Size2f				szOffset;
	float					fRotation;
};

struct PR_AlignCmd
{
	cv::Rect2f				rectLrn;
	cv::Mat					matInput;
	cv::Mat					matTmpl;
	cv::Point2f				ptExpectedPos;
	cv::Rect2f				rectSrchWindow;
	std::vector<KeyPoint>	vecModelKeyPoint;
	cv::Mat					matModelDescritor;
};

struct PR_AlignRpy
{
	Int16					nStatus;
	cv::Mat					matAffine;
	cv::Point2f				ptObjPos;
	cv::Size2f				szOffset;
	float                   fRotation;
};

struct PR_DefectCriteria
{
	PR_DEFECT_ATTRIBUTE		enAttribute;
	Byte					ubContrast;
	float					fArea;	// For general defect.
	float					fLength;// For line defect only. If != 0, will regard as line defect detecton and rAreaThreshold will be ignored
	float					fWidth;	// For noise removal. Note: unit is in 8192 coord sys (in old convention is phy coord sys, which is no good)
};

struct PR_INSP_SURFACE_CMD
{
	cv::Mat					matInsp;	
	cv::Mat					matTmpl;
    cv::Mat					matMask;
	cv::Rect2f				rectLrn;
	cv::Point2f				ptObjPos;
	float					fRotation;
	UInt16					u16NumOfDefectCriteria;
	PR_DefectCriteria		astDefectCriteria[MAX_NUM_OF_DEFECT_CRITERIA];
};

struct PR_Defect
{
	PR_DEFECT_TYPE		enType;
	float				fArea;
	float				fRadius;
	float				fLength;
	Int16				n16Constrast;
};

struct PR_INSP_SURFACE_RPY
{
	Int16				nStatus;
	Int16				n16NDefect;
	PR_Defect			astDefect[MAX_NUM_OF_DEFECT_RESULT];
};

template<typename _Tp> class PR_Line_
{
public:
	PR_Line_()
	{
		pt1.x = 0;
		pt1.y = 0;
		pt2.x = 0;
		pt2.y = 0;
	}
	PR_Line_(Point_<_Tp> inPt1, Point_<_Tp> inPt2 ) : pt1( inPt1 ), pt2 ( inPt2)
	{
	}
	Point_<_Tp> pt1;
	Point_<_Tp> pt2;
};

using PR_Line = PR_Line_<int>;
using PR_Line2f = PR_Line_<float>;

/******************************************
* Device Inspection Section
******************************************/ 
#define PR_MAX_DEVICE_COUNT         (100)
#define PR_MAX_CRITERIA_COUNT       (5)

struct PR_INSP_DEVICE_ITEM
{
	bool        bCheckMissed;			//check if the device is missed
	bool        bCheckShift;			//check if the device shift exceed tolerance
    bool        bCheckRotation;         //check if rotation exceed tolerance
    bool        bCheckScale;
};

struct PR_SINGLE_DEVICE_INFO
{
    cv::Point2f             stCtrPos;
    cv::Size2f              stSize;
    cv::Rect2f              rectSrchWindow;
    PR_INSP_DEVICE_ITEM     stInspItem;
    Int16                   nCriteriaNo;
};

struct PR_INSP_DEVICE_CRITERIA
{
	float                   fMaxOffsetX; 
	float                   fMaxOffsetY;
    float                   fMaxRotate;
    float                   fMaxScale;
    float                   fMinScale;
};

struct PR_LRN_DEVICE_CMD
{
    cv::Mat                 matInput;
    cv::Rect2f              rectDevice;
    bool                    bAutoThreshold;
    Int16                   nElectrodeThreshold;
};

struct PR_LRN_DEVICE_RPY
{
    Int32                   nStatus;
    Int32                   nRecordID;
    Int32                   nElectrodeThreshold;
};

struct PR_INSP_DEVICE_CMD
{
    cv::Mat                 matInput;
    Int32                   nRecordID;
    Int32                   nDeviceCount;
    Int16                   nElectrodeThreshold;
    PR_SINGLE_DEVICE_INFO   astDeviceInfo[PR_MAX_DEVICE_COUNT];
    PR_INSP_DEVICE_CRITERIA astCriteria[PR_MAX_CRITERIA_COUNT];
};

struct PR_INSP_DEVICE_RPY
{
    Int32                   nStatus;
    Int32                   nDeviceCount;
    Int32                   anDeviceStatus[PR_MAX_DEVICE_COUNT];
};

/******************************************
* Device Inspection Section
******************************************/

}
}
#endif