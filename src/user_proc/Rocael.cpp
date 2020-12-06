#include "pch.h"
#include "Rocael.h"

int Rocael::grayWorld(cv::Mat& src, cv::Mat& dst) {
    if (src.empty() || src.type() != CV_8UC3)
        return -1;
    if (dst.empty() || src.type() != dst.type() || src.size() != dst.size())
    {
        dst.create(src.size(), CV_8UC3);
    }
    int nrows = src.rows;
    int ncols = src.cols;
    int jMax = ncols * src.channels();

    double dr = 0.0;
    double dg = 0.0;
    double db = 0.0;

    int i = 0;
    int j = 0;

    for (i = 0; i < nrows; i++)
    {
        uchar* pdate = src.ptr<uchar>(i);
        for (j = 0; j < jMax;)
        {
            db += static_cast<double>(pdate[j++]);
            dg += static_cast<double>(pdate[j++]);
            dr += static_cast<double>(pdate[j++]);
        }
    }
    double dsize = nrows * ncols;
    db = db / dsize;
    dg = dg / dsize;
    dr = dr / dsize;
    double dAvg = db / 3 + dg / 3 + dr / 3;

    db = dAvg / (db + DBL_EPSILON);
    dg = dAvg / (dg + DBL_EPSILON);
    dr = dAvg / (dr + DBL_EPSILON);

    int itemp = 0;
    for (i = 0; i < nrows; i++)
    {
        uchar* pdate = src.ptr<uchar>(i);
        uchar* pdst = dst.ptr<uchar>(i);
        for (j = 0; j < jMax;)
        {
            itemp = static_cast<int>(db * pdate[j]);
            pdst[j] = static_cast<uchar>(itemp > 255 ? 255 : itemp);
            j++;
            itemp = static_cast<int>(dg * pdate[j]);
            pdst[j] = static_cast<uchar>(itemp > 255 ? 255 : itemp);
            j++;
            itemp = static_cast<int>(dr * pdate[j]);
            pdst[j] = static_cast<uchar>(itemp > 255 ? 255 : itemp);
            j++;
        }
    }
    return 0;
}