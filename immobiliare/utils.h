/******************************************************************************
	author:	Francesco Settembrini
	last update: 23/6/2021, 08/11/2021, 28/11/2021
	e-mail:	mailto:francesco.settembrini@poliba.it
******************************************************************************/

#ifndef utilsH
#define utilsH

//#include <vcl.h>
#include <string>
#include <algorithm>

namespace utils
{
	std::string GetExePath();
    std::string GetDataPath();

	bool FileExists(std::string strFileName);

    std::string LowerCase(std::string strVal);

	bool ParseDate(std::string strDate,
    	unsigned short& nYear, unsigned short& nMonth, unsigned short& nDay);
};

//---------------------------------------------------------------------------
#endif
