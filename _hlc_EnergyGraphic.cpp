#include "_hlc_EnergyGraphic.h"

//(*InternalHeaders(_hlc_EnergyGraphic)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/image.h>
//*)

#include <wx/dcclient.h>
#include <wx/statbox.h>

#include "ppStringController.h"

//(*IdInit(_hlc_EnergyGraphic)
const long _hlc_EnergyGraphic::ID_GLCANVAS1 = wxNewId();
const long _hlc_EnergyGraphic::ID_STATICBITMAP1 = wxNewId();
const long _hlc_EnergyGraphic::ID_SLIDER1 = wxNewId();
const long _hlc_EnergyGraphic::ID_SLIDER2 = wxNewId();
const long _hlc_EnergyGraphic::ID_TIMER1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(_hlc_EnergyGraphic,wxFrame)
    //(*EventTable(_hlc_EnergyGraphic)
    //*)
END_EVENT_TABLE()

_hlc_EnergyGraphic::_hlc_EnergyGraphic(wxWindow* parent,wxWindowID id) {
    //(*Initialize(_hlc_EnergyGraphic)
    wxFlexGridSizer* FlexGridSizer1;
    wxBoxSizer* BoxSizer1;
    wxStaticBoxSizer* StaticBoxSizer1;

    Create(parent, wxID_ANY, _("Энергия струны"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetMinSize(wxSize(640,480));
    SetBackgroundColour(wxColour(240,240,240));
    {
    	wxIcon FrameIcon;
    	FrameIcon.CopyFromBitmap(wxBitmap(wxImage(_T("data/icon.tga"))));
    	SetIcon(FrameIcon);
    }
    FlexGridSizer1 = new wxFlexGridSizer(1, 1, 0, 0);
    FlexGridSizer1->AddGrowableCol(0);
    FlexGridSizer1->AddGrowableRow(0);
    int GLCanvasAttributes_1[] = {
    	WX_GL_RGBA,
    	WX_GL_DOUBLEBUFFER,
    	WX_GL_DEPTH_SIZE,      16,
    	WX_GL_STENCIL_SIZE,    0,
    	0, 0 };
    _hlc_EnergyGraphic_GLCanvas = new wxGLCanvas(this, ID_GLCANVAS1, wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER, _T("ID_GLCANVAS1"), GLCanvasAttributes_1);
    _hlc_EnergyGraphic_GLCanvas->SetMinSize(wxSize(640,480));
    FlexGridSizer1->Add(_hlc_EnergyGraphic_GLCanvas, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    StaticBitmap1 = new wxStaticBitmap(this, ID_STATICBITMAP1, wxBitmap(wxImage(_T("data/legend.tga"))), wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER, _T("ID_STATICBITMAP1"));
    BoxSizer1->Add(StaticBitmap1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Масштаб (x,y)"));
    _hlc_energy_graphic_Slider_zoom_x = new wxSlider(this, ID_SLIDER1, 100, 10, 1000, wxDefaultPosition, wxSize(100,30), 0, wxDefaultValidator, _T("ID_SLIDER1"));
    StaticBoxSizer1->Add(_hlc_energy_graphic_Slider_zoom_x, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    _hlc_energy_graphic_Slider_zoom_y = new wxSlider(this, ID_SLIDER2, 100, 10, 1000, wxDefaultPosition, wxSize(100,30), 0, wxDefaultValidator, _T("ID_SLIDER2"));
    StaticBoxSizer1->Add(_hlc_energy_graphic_Slider_zoom_y, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(StaticBoxSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(BoxSizer1, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(FlexGridSizer1);
    RenderTimer.SetOwner(this, ID_TIMER1);
    RenderTimer.Start(1, false);
    FlexGridSizer1->Fit(this);
    FlexGridSizer1->SetSizeHints(this);

    _hlc_EnergyGraphic_GLCanvas->Connect(wxEVT_PAINT,(wxObjectEventFunction)&_hlc_EnergyGraphic::On_hlc_EnergyGraphic_GLCanvasPaint,0,this);
    _hlc_EnergyGraphic_GLCanvas->Connect(wxEVT_SIZE,(wxObjectEventFunction)&_hlc_EnergyGraphic::OnGLCanvas1Resize,0,this);
    Connect(ID_SLIDER1,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&_hlc_EnergyGraphic::On_hlc_energy_graphic_Slider_zoom_xCmdSliderUpdated);
    Connect(ID_SLIDER2,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&_hlc_EnergyGraphic::On_hlc_energy_graphic_Slider_zoom_yCmdSliderUpdated);
    Connect(ID_TIMER1,wxEVT_TIMER,(wxObjectEventFunction)&_hlc_EnergyGraphic::OnRenderTimerTrigger);
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&_hlc_EnergyGraphic::OnClose);
    //*)

    pp_string_t->setContextSize(kHlcEnergy, _hlc_EnergyGraphic_GLCanvas->GetSize().x, _hlc_EnergyGraphic_GLCanvas->GetSize().y);

    scale_sizer = StaticBoxSizer1;
}

_hlc_EnergyGraphic::~_hlc_EnergyGraphic() {
    is_gl_init = false;
    pp_string_t->_hlc_energy_graphic_zoom_x = 1.0f;
    //(*Destroy(_hlc_EnergyGraphic)
    //*)
}

void _hlc_EnergyGraphic::OnRenderTimerTrigger(wxTimerEvent& event) {
    _hlc_EnergyGraphic_GLCanvas->Refresh();
}

void _hlc_EnergyGraphic::OnGLCanvas1Resize(wxSizeEvent& event) {
    pp_string_t->setContextSize(kHlcEnergy, _hlc_EnergyGraphic_GLCanvas->GetSize().x, _hlc_EnergyGraphic_GLCanvas->GetSize().y);
}

void _hlc_EnergyGraphic::On_hlc_EnergyGraphic_GLCanvasPaint(wxPaintEvent& event) {
    wxPaintDC dc(_hlc_EnergyGraphic_GLCanvas);

    _hlc_EnergyGraphic_GLCanvas->SetCurrent();

    if(!is_gl_init) {
        _hlc_EnergyGraphic_GLCanvas->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
        pp_string_t->initContext(kHlcEnergy);
        is_gl_init = true;
    }

    pp_string_t->render(kHlcEnergy);

    glFlush();
    _hlc_EnergyGraphic_GLCanvas->SwapBuffers();
    glFinish();
}

void _hlc_EnergyGraphic::On_hlc_energy_graphic_Slider_zoom_yCmdSliderUpdated(wxScrollEvent& event) {
    pp_string_t->_hlc_energy_graphic_zoom_y = _hlc_energy_graphic_Slider_zoom_y->GetValue()/100.0;
}

void _hlc_EnergyGraphic::On_hlc_energy_graphic_Slider_zoom_xCmdSliderUpdated(wxScrollEvent& event) {
    pp_string_t->_hlc_energy_graphic_zoom_x = _hlc_energy_graphic_Slider_zoom_x->GetValue()/100.0;
}

void _hlc_EnergyGraphic::SetLanguage(Language lang) {
    switch(lang) {
    case kEnglish:
        this->SetTitle(_("String energy"));

        scale_sizer->GetStaticBox()->SetLabel(_("Scale (x,y)"));
        break;

    case kRussian:
        this->SetTitle(_("Энергия струны"));

        scale_sizer->GetStaticBox()->SetLabel(_("Масштаб (x,y)"));
        break;
    }
}
