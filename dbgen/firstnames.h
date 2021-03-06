//---------------------------------------------------------------------------
#ifndef firstnamesH
#define firstnamesH

#include <vcl.h>
#pragma hdrstop

#include <vector>>

using namespace std;

struct TFirstName;
typedef vector<TFirstName> TVecFirstNames;

struct TFirstName
{
	AnsiString m_strName;
    int m_nFreq;
};

class TFirstNamesArchive
{
public:
	TFirstNamesArchive();

	void __fastcall Clear();
    int __fastcall GetCount();
    void __fastcall GetFirstNames(TVecFirstNames& FirstNames);

	bool __fastcall LoadFromFile(AnsiString strFileName);

protected:
	TVecFirstNames m_FirstNames;

    bool __fastcall Parse(AnsiString strTuple, TFirstName& FirstName);
};


//---------------------------------------------------------------------------
#endif
