#pragma once 
#include <cmath>
#include <string>

#ifdef __WIN32__
#define DllExport __declspec( dllexport )
#define DllImport __declspec( dllimport )
#else
#define DllExport
#define DllImport
#endif

#ifdef EXPORT
#define EXPORT_NAME DllExport
#else
#define EXPORT_NAME DllImport
#endif // EXPORT

class EXPORT_NAME Environment
{
public:
    Environment(double left=-1, double right=-1, double top=-1, double bottom=1);

    double left(); //{ return -1; }
    double right() { return -1; }
    double top() { return -1; }
    double bottom() { return -1; }
};
