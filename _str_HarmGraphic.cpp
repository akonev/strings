#include "_str_HarmGraphic.h"

//(*InternalHeaders(_str_HarmGraphic)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/image.h>
//*)

#include <wx/dcclient.h>
#include <wx/statbox.h>

#include "ppStringController.h"

//(*IdInit(_str_HarmGraphic)
const long _str_HarmGraphic::ID_GLCANVAS1 = wxNewId();
const long _str_HarmGraphic::ID_SPINCTRL1 = wxNewId();
const long _str_HarmGraphic::ID_SLIDER1 = wxNewId();
const long _str_HarmGraphic::ID_SLIDER2 = wxNewId();
const long _str_HarmGraphic::ID_TIMER1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(_str_HarmGraphic,wxFrame)
    //(*EventTable(_str_HarmGraphic)
    //*)
END_EVENT_TABLE()

_str_HarmGraphic::_str_HarmGraphic(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size) {
    //(*Initialize(_str_HarmGraphic)
    wxStaticBoxSizer* StaticBoxSizer2;
    wxFlexGridSizer* FlexGridSizer1;
    wxBoxSizer* BoxSizer3;
    wxBoxSizer* BoxSizer1;
    wxStaticBoxSizer* StaticBoxSizer1;

    Create(parent, wxID_ANY, _("Разложение на гармоники"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
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
        0, 0
    };
    _str_HarmGraphic_GLCanvas = new wxGLCanvas(this, ID_GLCANVAS1, wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER, _T("ID_GLCANVAS1"), GLCanvasAttributes_1);
    _str_HarmGraphic_GLCanvas->SetMinSize(wxSize(640,480));
    FlexGridSizer1->Add(_str_HarmGraphic_GLCanvas, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer3->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("№ гармоники"));
    _str_SpinCtrl_harm_num = new wxSpinCtrl(this, ID_SPINCTRL1, _T("1"), wxDefaultPosition, wxSize(50,-1), 0, 1, 100, 1, _T("ID_SPINCTRL1"));
    _str_SpinCtrl_harm_num->SetValue(_T("1"));
    StaticBoxSizer1->Add(_str_SpinCtrl_harm_num, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(StaticBoxSizer1, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Масштаб (x,y)"));
    _str_harm_graphic_Slider_zoom_x = new wxSlider(this, ID_SLIDER1, 100, 1, 1000, wxDefaultPosition, wxSize(100,30), 0, wxDefaultValidator, _T("ID_SLIDER1"));
    StaticBoxSizer2->Add(_str_harm_graphic_Slider_zoom_x, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    _str_harm_graphic_Slider_zoom_y = new wxSlider(this, ID_SLIDER2, 100, 1, 1000, wxDefaultPosition, wxSize(100,30), 0, wxDefaultValidator, _T("ID_SLIDER2"));
    StaticBoxSizer2->Add(_str_harm_graphic_Slider_zoom_y, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(StaticBoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(BoxSizer1, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(FlexGridSizer1);
    RenderTimer.SetOwner(this, ID_TIMER1);
    RenderTimer.Start(1, false);
    FlexGridSizer1->Fit(this);
    FlexGridSizer1->SetSizeHints(this);

    _str_HarmGraphic_GLCanvas->Connect(wxEVT_PAINT,(wxObjectEventFunction)&_str_HarmGraphic::On_str_HarmGraphic_GLCanvasPaint,0,this);
    _str_HarmGraphic_GLCanvas->Connect(wxEVT_SIZE,(wxObjectEventFunction)&_str_HarmGraphic::On_str_HarmGraphic_GLCanvasResize,0,this);
    Connect(ID_SPINCTRL1,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&_str_HarmGraphic::On_str_SpinCtrl_harm_numChange);
    Connect(ID_SLIDER1,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&_str_HarmGraphic::On_str_harm_graphic_Slider_zoom_xCmdSliderUpdated);
    Connect(ID_SLIDER2,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&_str_HarmGraphic::On_str_harm_graphic_Slider_zoom_yCmdSliderUpdated);
    Connect(ID_TIMER1,wxEVT_TIMER,(wxObjectEventFunction)&_str_HarmGraphic::OnRenderTimerTrigger);
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&_str_HarmGraphic::OnClose);
    //*)

    pp_string_t->setContextSize(kStrHarm, _str_HarmGraphic_GLCanvas->GetSize().x, _str_HarmGraphic_GLCanvas->GetSize().y);

    scale_sizer = StaticBoxSizer2;
    number_sizer = StaticBoxSizer1;
}

_str_HarmGraphic::~_str_HarmGraphic() {
    is_gl5_init = false;
    pp_string_t->_str_harm_graphic_zoom_x = 1.0;
    pp_string_t->_str_harm_graphic_zoom_y = 1.0;
    //(*Destroy(_str_HarmGraphic)
    //*)
}


void _str_HarmGraphic::On_str_HarmGraphic_GLCanvasResize(wxSizeEvent& event) {
    pp_string_t->setContextSize(kStrHarm, _str_HarmGraphic_GLCanvas->GetSize().x, _str_HarmGraphic_GLCanvas->GetSize().y);
}

void _str_HarmGraphic::OnRenderTimerTrigger(wxTimerEvent& event) {
    _str_HarmGraphic_GLCanvas->Refresh();
}

void _str_HarmGraphic::On_str_SpinCtrl_harm_numChange(wxSpinEvent& event) {
    pp_string_t->cur_str_harm_graphic_num = _str_SpinCtrl_harm_num->GetValue();
}

void _str_HarmGraphic::On_str_harm_graphic_Slider_zoom_xCmdSliderUpdated(wxScrollEvent& event) {
    pp_string_t->_str_harm_graphic_zoom_x = _str_harm_graphic_Slider_zoom_x->GetValue()/100.0;
}

void _str_HarmGraphic::On_str_harm_graphic_Slider_zoom_yCmdSliderUpdated(wxScrollEvent& event) {
    pp_string_t->_str_harm_graphic_zoom_y = _str_harm_graphic_Slider_zoom_y->GetValue()/100.0;
}

void _str_HarmGraphic::On_str_HarmGraphic_GLCanvasPaint(wxPaintEvent& event) {
    _str_SpinCtrl_harm_num->SetRange(1,pp_string_t->test_str.harm_max);

    wxPaintDC dc(_str_HarmGraphic_GLCanvas);

    _str_HarmGraphic_GLCanvas->SetCurrent();

    if(!is_gl5_init) {
        _str_HarmGraphic_GLCanvas->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
        pp_string_t->initContext(kStrHarm);
        is_gl5_init = true;
    }

    pp_string_t->render(kStrHarm);

    glFlush();
    _str_HarmGraphic_GLCanvas->SwapBuffers();
    glFinish();
}

void _str_HarmGraphic::SetLanguage(Language lang) {
    switch(lang) {
    case kEnglish:
        this->SetTitle(_("Decomposition into harmonics"));

        scale_sizer->GetStaticBox()->SetLabel(_("Scale (x,y)"));
        number_sizer->GetStaticBox()->SetLabel(_("№ of harm"));
        break;

    case kRussian:
        this->SetTitle(_("Разложение на гармоники"));

        scale_sizer->GetStaticBox()->SetLabel(_("Масштаб (x,y)"));
        number_sizer->GetStaticBox()->SetLabel(_("№ гармоники"));
        break;
    }
}
