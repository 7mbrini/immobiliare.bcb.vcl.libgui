/*!****************************************************************************

	@file	roads.h
	@file	roads.cpp

	@brief	Data access for "roads" file archive

	@noop	author:	Francesco Settembrini
	@noop	last update: 23/6/2021
	@noop	e-mail:	mailto:francesco.settembrini@poliba.it

******************************************************************************/

#include <vcl.h>
#pragma hdrstop

#include "TFormDebug.h"
#include "roads.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)


TRoadsArchive::TRoadsArchive()
{

}

void __fastcall TRoadsArchive::Clear()
{
	m_Roads.clear();
}

int __fastcall TRoadsArchive::GetCount()
{
	return m_Roads.size();
}

bool __fastcall TRoadsArchive::LoadFromFile(AnsiString strFileName)
{
	bool bResult = false;

    if( ::FileExists(strFileName) )
    {
                                            // First of all, clear old data!
        Clear();

        TStringList *pList = new TStringList;
        assert(pList);

        pList->LoadFromFile(strFileName);

                                                // i=1 --> skip first heading row
        for(int i=1; i<pList->Count; i++)
        {
            TRoad Road;

            if( Parse(pList->Strings[i], Road) )
            {
                m_Roads.push_back(Road);
            }
        }

        delete pList;

        bResult = true;
	}

	return bResult;
}

bool __fastcall TRoadsArchive::Parse(AnsiString strTuple, TRoad& Road)
{
	bool bResult = true;

    AnsiString strCode = strTuple.SubString(0, strTuple.Pos(";") - 1);

    Road.m_strName = strTuple.SubString(strTuple.Pos(";") + 1, strTuple.Length());
    //Road.m_strName = strTuple.SubString(0, strTuple.Pos(";") - 1);

    if( !strCode.IsEmpty() )
    {
		try
        {
			Road.m_nCode = strCode.ToInt();
        }
        catch(...)
        {
			bResult = false;
        }
    }
	else
    {
    	bResult = false;
    }

    return bResult && Road.m_strName.Length();
}

void __fastcall TRoadsArchive::GetRoads(TVecRoads& Roads)
{
	Roads = m_Roads;
}

