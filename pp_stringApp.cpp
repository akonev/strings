/***************************************************************
 * Name:      pp_stringApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Temior (temior.wl@gmail.com)
 * Created:   2012-03-01
 * Copyright: Temior (white-projects.6te.net)
 * License:
 **************************************************************/

#include "pp_stringApp.h"

//(*AppHeaders
#include "pp_stringMain.h"
#include <wx/image.h>
//*)

#include "ppStringController.h"

std::auto_ptr<ppStringController> pp_string_t;

IMPLEMENT_APP(pp_stringApp);

bool pp_stringApp::OnInit() {
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
        pp_string_t.reset(new ppStringController);
    	pp_stringFrame* Frame = new pp_stringFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
