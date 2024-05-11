/***************************************************************
 * Name:      MontyApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Y ()
 * Created:   2024-04-27
 * Copyright: Y ()
 * License:
 **************************************************************/

#include "MontyApp.h"

//(*AppHeaders
#include "MontyMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(MontyApp);

bool MontyApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	MontyFrame* Frame = new MontyFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
