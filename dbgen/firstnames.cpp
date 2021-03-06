/*!****************************************************************************

	@file	firstnames.h
	@file	firstnames.cpp

	@brief	Data access for "firstnames" file archive

	@noop	author:	Francesco Settembrini
	@noop	last update: 23/6/2021
	@noop	e-mail:	mailto:francesco.settembrini@poliba.it

******************************************************************************/

#include <vcl.h>
#pragma hdrstop

#include "TFormDebug.h"
#include "firstnames.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)


TFirstNamesArchive::TFirstNamesArchive()
{

}

void __fastcall TFirstNamesArchive::Clear()
{
	m_FirstNames.clear();
}

int __fastcall TFirstNamesArchive::GetCount()
{
	return m_FirstNames.size();
}

bool __fastcall TFirstNamesArchive::LoadFromFile(AnsiString strFileName)
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
            TFirstName FirstName;

            if( Parse(pList->Strings[i], FirstName) )
            {
                m_FirstNames.push_back(FirstName);
            }
        }

        delete pList;

        bResult = true;
	}

	return bResult;
}

bool __fastcall TFirstNamesArchive::Parse(AnsiString strTuple, TFirstName& FirstName)
{
	bool bResult = true;

    FirstName.m_strName = strTuple.SubString(0, strTuple.Pos(",") - 1);

    //strTuple = strTuple.SubString(strTuple.Pos(",") + 1, strTuple.Length());
    //strTuple = strTuple.SubString(0, strTuple.Pos(",") + 1, strTuple.Length());
    strTuple = strTuple.SubString(strTuple.Pos(",") + 1, strTuple.Length());
    AnsiString strFreq = strTuple.SubString(0, strTuple.Pos(",") - 1);
//FormDebug->Print(strFreq);

    if( !strFreq.IsEmpty() )
    {
		try
        {
			FirstName.m_nFreq = strFreq.ToInt();
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

    return bResult && FirstName.m_strName.Length();
}

void __fastcall TFirstNamesArchive::GetFirstNames(TVecFirstNames& FirstNames)
{
	FirstNames = m_FirstNames;
}

