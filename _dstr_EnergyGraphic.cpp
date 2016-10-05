#include "_dstr_EnergyGraphic.h"

//(*InternalHeaders(_dstr_EnergyGraphic)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/image.h>
//*)

#include <wx/dcclient.h>
#include <wx/statbox.h>

#include "ppStringController.h"

//(*IdInit(_dstr_EnergyGraphic)
const long _dstr_EnergyGraphic::ID_GLCANVAS1 = wxNewId();
const long _dstr_EnergyGraphic::ID_STATICBITMAP1 = wxNewId();
const long _dstr_EnergyGraphic::ID_SPINCTRL1 = wxNewId();
const long _dstr_EnergyGraphic::ID_SLIDER2 = wxNewId();
const long _dstr_EnergyGraphic::ID_SLIDER1 = wxNewId();
const long _dstr_EnergyGraphic::ID_TIMER1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(_dstr_EnergyGraphic,wxFrame)
    //(*EventTable(_dstr_EnergyGraphic)
    //*)
END_EVENT_TABLE()

_dstr_EnergyGraphic::_dstr_EnergyGraphic(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size) {
    //(*Initialize(_dstr_EnergyGraphic)
    wxStaticBoxSizer* StaticBoxSizer2;
    wxFlexGridSizer* FlexGridSizer1;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer1;
    wxStaticBoxSizer* StaticBoxSizer1;

    Create(parent, wxID_ANY, _("Кинетическая и потенциальная энергии груза"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetMinSize(wxSize(640,480));
    SetBackgroundColour(wxColour(240,240,240));
    {
    	wxIcon FrameIcon;
    	FrameIcon.CopyFromBitmap(wxBitmap(wxImage(_T("data/icon.tga"))));
    	SetIcon(FrameIcon);
    }
    FlexGridSizer1 = new wxFlexGridSizer(2, 1, 0, 0);
    FlexGridSizer1->AddGrowableCol(0);
    FlexGridSizer1->AddGrowableRow(0);
    int GLCanvasAttributes_1[] = {
    	WX_GL_RGBA,
    	WX_GL_DOUBLEBUFFER,
    	WX_GL_DEPTH_SIZE,      16,
    	WX_GL_STENCIL_SIZE,    0,
    	0, 0 };
    _dstr_EnergyGraphic_GLCanvas = new wxGLCanvas(this, ID_GLCANVAS1, wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER, _T("ID_GLCANVAS1"), GLCanvasAttributes_1);
    _dstr_EnergyGraphic_GLCanvas->SetMinSize(wxSize(640,480));
    FlexGridSizer1->Add(_dstr_EnergyGraphic_GLCanvas, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    StaticBitmap1 = new wxStaticBitmap(this, ID_STATICBITMAP1, wxBitmap(wxImage(_T("data/legend.tga"))), wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER, _T("ID_STATICBITMAP1"));
    BoxSizer1->Add(StaticBitmap1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer2->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("№ груза"));
    _dstr_SpinCtrl_graphic_wheit_num = new wxSpinCtrl(this, ID_SPINCTRL1, _T("0"), wxDefaultPosition, wxDefaultSize, 0, 0, 100, 0, _T("ID_SPINCTRL1"));
    _dstr_SpinCtrl_graphic_wheit_num->SetValue(_T("0"));
    StaticBoxSizer2->Add(_dstr_SpinCtrl_graphic_wheit_num, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(StaticBoxSizer2, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Масштаб (x,y)"));
    _dstr_energy_graphic_Slider_zoom_x = new wxSlider(this, ID_SLIDER2, 100, 10, 1000, wxDefaultPosition, wxSize(100,30), 0, wxDefaultValidator, _T("ID_SLIDER2"));
    StaticBoxSizer1->Add(_dstr_energy_graphic_Slider_zoom_x, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    _dstr_energy_graphic_Slider_zoom_y = new wxSlider(this, ID_SLIDER1, 100, 10, 1000, wxDefaultPosition, wxSize(100,30), 0, wxDefaultValidator, _T("ID_SLIDER1"));
    StaticBoxSizer1->Add(_dstr_energy_graphic_Slider_zoom_y, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(StaticBoxSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(BoxSizer1, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(FlexGridSizer1);
    RenderTimer.SetOwner(this, ID_TIMER1);
    RenderTimer.Start(1, false);
    FlexGridSizer1->Fit(this);
    FlexGridSizer1->SetSizeHints(this);

    _dstr_EnergyGraphic_GLCanvas->Connect(wxEVT_PAINT,(wxObjectEventFunction)&_dstr_EnergyGraphic::On_dstr_EnergyGraphic_GLCanvasPaint,0,this);
    _dstr_EnergyGraphic_GLCanvas->Connect(wxEVT_SIZE,(wxObjectEventFunction)&_dstr_EnergyGraphic::OnGLCanvas1Resize,0,this);
    Connect(ID_SPINCTRL1,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&_dstr_EnergyGraphic::On_dstr_SpinCtrl_graphic_wheit_numChange);
    Connect(ID_SLIDER2,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&_dstr_EnergyGraphic::On_dstr_energy_graphic_Slider_zoom_xCmdSliderUpdated);
    Connect(ID_SLIDER1,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&_dstr_EnergyGraphic::On_dstr_energy_graphic_Slider_zoom_yCmdSliderUpdated);
    Connect(ID_TIMER1,wxEVT_TIMER,(wxObjectEventFunction)&_dstr_EnergyGraphic::OnTimer1Trigger);
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&_dstr_EnergyGraphic::OnClose);
    //*)

    pp_string_t->setContextSize(kDstrEnergy, _dstr_EnergyGraphic_GLCanvas->GetSize().x, _dstr_EnergyGraphic_GLCanvas->GetSize().y);

    scale_sizer = StaticBoxSizer1;
    number_sizer = StaticBoxSizer2;
}

_dstr_EnergyGraphic::~_dstr_EnergyGraphic() {
    is_gl_init = false;
    pp_string_t->_dstr_energy_graphic_zoom_x = 1.0;
    //(*Destroy(_dstr_EnergyGraphic)
    //*)
}

void _dstr_EnergyGraphic::OnTimer1Trigger(wxTimerEvent& event) {
    _dstr_EnergyGraphic_GLCanvas->Refresh();
}

void _dstr_EnergyGraphic::OnGLCanvas1Resize(wxSizeEvent& event) {
    pp_string_t->setContextSize(kDstrEnergy, _dstr_EnergyGraphic_GLCanvas->GetSize().x, _dstr_EnergyGraphic_GLCanvas->GetSize().y);
}

void _dstr_EnergyGraphic::On_dstr_energy_graphic_Slider_zoom_xCmdSliderUpdated(wxScrollEvent& event) {
    pp_string_t->_dstr_energy_graphic_zoom_x = _dstr_energy_graphic_Slider_zoom_x->GetValue()/100.0;
}

void _dstr_EnergyGraphic::On_dstr_energy_graphic_Slider_zoom_yCmdSliderUpdated(wxScrollEvent& event) {
    pp_string_t->_dstr_energy_graphic_zoom_y = _dstr_energy_graphic_Slider_zoom_y->GetValue()/100.0;
}

void _dstr_EnergyGraphic::On_dstr_EnergyGraphic_GLCanvasPaint(wxPaintEvent& event) {
    wxPaintDC dc(_dstr_EnergyGraphic_GLCanvas);

    _dstr_EnergyGraphic_GLCanvas->SetCurrent();

    if(!is_gl_init) {
        _dstr_EnergyGraphic_GLCanvas->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
        pp_string_t->initContext(kDstrEnergy);
        is_gl_init = true;
    }

    pp_string_t->render(kDstrEnergy);

    glFlush();
    _dstr_EnergyGraphic_GLCanvas->SwapBuffers();
    glFinish();
}

void _dstr_EnergyGraphic::SetLanguage(Language lang) {
    switch(lang) {
    case kEnglish:
        this->SetTitle(_("The kinetic and potential energy"));

        scale_sizer->GetStaticBox()->SetLabel(_("Scale (x,y)"));
        number_sizer->GetStaticBox()->SetLabel(_("№ of weight"));
        break;

    case kRussian:
        this->SetTitle(_("Кинетическая и потенциальная энергии груза"));

        scale_sizer->GetStaticBox()->SetLabel(_("Масштаб (x,y)"));
        number_sizer->GetStaticBox()->SetLabel(_("№ груза"));
        break;
    }
}

