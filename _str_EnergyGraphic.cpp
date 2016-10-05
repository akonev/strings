#include "_str_EnergyGraphic.h"

//(*InternalHeaders(_str_EnergyGraphic)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/image.h>
//*)

#include <wx/dcclient.h>
#include <wx/statbox.h>

#include "ppStringController.h"

//(*IdInit(_str_EnergyGraphic)
const long _str_EnergyGraphic::ID_GLCANVAS1 = wxNewId();
const long _str_EnergyGraphic::ID_STATICBITMAP1 = wxNewId();
const long _str_EnergyGraphic::ID_SLIDER3 = wxNewId();
const long _str_EnergyGraphic::ID_SLIDER2 = wxNewId();
const long _str_EnergyGraphic::ID_TIMER1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(_str_EnergyGraphic,wxFrame)
    //(*EventTable(_str_EnergyGraphic)
    //*)
END_EVENT_TABLE()

_str_EnergyGraphic::_str_EnergyGraphic(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size) {
    //(*Initialize(_str_EnergyGraphic)
    wxStaticBoxSizer* StaticBoxSizer2;
    wxFlexGridSizer* FlexGridSizer1;
    wxBoxSizer* BoxSizer1;

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
    _str_EnergyGraphic_GLCanvas = new wxGLCanvas(this, ID_GLCANVAS1, wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER, _T("ID_GLCANVAS1"), GLCanvasAttributes_1);
    _str_EnergyGraphic_GLCanvas->SetMinSize(wxSize(640,480));
    FlexGridSizer1->Add(_str_EnergyGraphic_GLCanvas, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    StaticBitmap1 = new wxStaticBitmap(this, ID_STATICBITMAP1, wxBitmap(wxImage(_T("data/legend.tga"))), wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER, _T("ID_STATICBITMAP1"));
    BoxSizer1->Add(StaticBitmap1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Масштаб (x,y)"));
    _str_energy_graphic_Slider_zoom_x = new wxSlider(this, ID_SLIDER3, 100, 10, 1000, wxDefaultPosition, wxSize(100,30), 0, wxDefaultValidator, _T("ID_SLIDER3"));
    StaticBoxSizer2->Add(_str_energy_graphic_Slider_zoom_x, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    _str_energy_graphic_Slider_zoom_y = new wxSlider(this, ID_SLIDER2, 100, 10, 1000, wxDefaultPosition, wxSize(100,30), 0, wxDefaultValidator, _T("ID_SLIDER2"));
    StaticBoxSizer2->Add(_str_energy_graphic_Slider_zoom_y, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(StaticBoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(BoxSizer1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(FlexGridSizer1);
    RenderTimer.SetOwner(this, ID_TIMER1);
    RenderTimer.Start(1, false);
    FlexGridSizer1->Fit(this);
    FlexGridSizer1->SetSizeHints(this);

    _str_EnergyGraphic_GLCanvas->Connect(wxEVT_PAINT,(wxObjectEventFunction)&_str_EnergyGraphic::On_str_EnergyGraphic_GLCanvasPaint,0,this);
    _str_EnergyGraphic_GLCanvas->Connect(wxEVT_SIZE,(wxObjectEventFunction)&_str_EnergyGraphic::On_str_EnergyGraphic_GLCanvasResize,0,this);
    Connect(ID_SLIDER3,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&_str_EnergyGraphic::On_str_energy_graphic_Slider_zoom_xCmdSliderUpdated);
    Connect(ID_SLIDER2,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&_str_EnergyGraphic::On_str_energy_graphic_Slider_zoom_yCmdSliderUpdated);
    Connect(ID_TIMER1,wxEVT_TIMER,(wxObjectEventFunction)&_str_EnergyGraphic::OnRenderTimerTrigger);
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&_str_EnergyGraphic::OnClose);
    //*)

    pp_string_t->setContextSize(kStrEnergy, _str_EnergyGraphic_GLCanvas->GetSize().x, _str_EnergyGraphic_GLCanvas->GetSize().y);

    scale_sizer = StaticBoxSizer2;
}

_str_EnergyGraphic::~_str_EnergyGraphic() {
    is_gl_init = false;
    pp_string_t->_str_energy_graphic_zoom_x = 1.0;
    pp_string_t->_str_energy_graphic_zoom_y = 1.0;
    //(*Destroy(_str_EnergyGraphic)
    //*)
}


void _str_EnergyGraphic::On_str_EnergyGraphic_GLCanvasResize(wxSizeEvent& event) {
    pp_string_t->setContextSize(kStrEnergy, _str_EnergyGraphic_GLCanvas->GetSize().x, _str_EnergyGraphic_GLCanvas->GetSize().y);
}

void _str_EnergyGraphic::OnRenderTimerTrigger(wxTimerEvent& event) {
    _str_EnergyGraphic_GLCanvas->Refresh();
}

void _str_EnergyGraphic::On_str_energy_graphic_Slider_zoom_xCmdSliderUpdated(wxScrollEvent& event) {
    pp_string_t->_str_energy_graphic_zoom_x = _str_energy_graphic_Slider_zoom_x->GetValue()/100.0;
}

void _str_EnergyGraphic::On_str_energy_graphic_Slider_zoom_yCmdSliderUpdated(wxScrollEvent& event) {
    pp_string_t->_str_energy_graphic_zoom_y = _str_energy_graphic_Slider_zoom_y->GetValue()/100.0;
}

void _str_EnergyGraphic::On_str_EnergyGraphic_GLCanvasPaint(wxPaintEvent& event) {
    wxPaintDC dc(_str_EnergyGraphic_GLCanvas);

    _str_EnergyGraphic_GLCanvas->SetCurrent();

    if(!is_gl_init) {
        _str_EnergyGraphic_GLCanvas->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
        pp_string_t->initContext(kStrEnergy);
        is_gl_init = true;
    }

    pp_string_t->render(kStrEnergy);

    glFlush();
    _str_EnergyGraphic_GLCanvas->SwapBuffers();
    glFinish();
}

void _str_EnergyGraphic::SetLanguage(Language lang) {
    switch(lang) {
    case kEnglish:
        this->SetTitle(_("The kinetic and potential energy"));

        scale_sizer->GetStaticBox()->SetLabel(_("Scale (x,y)"));
        break;

    case kRussian:
        this->SetTitle(_("Кинетическая и потенциальная энергии груза"));

        scale_sizer->GetStaticBox()->SetLabel(_("Масштаб (x,y)"));
        break;
    }
}
