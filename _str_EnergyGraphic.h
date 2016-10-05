#ifndef _STR_ENERGYGRAPHIC_H
#define _STR_ENERGYGRAPHIC_H

//(*Headers(_str_EnergyGraphic)
#include <wx/glcanvas.h>
#include <wx/sizer.h>
#include <wx/slider.h>
#include <wx/frame.h>
#include <wx/timer.h>
#include <wx/statbmp.h>
//*)

#include "language.hpp"

class _str_EnergyGraphic: public wxFrame {
public:

    _str_EnergyGraphic(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
    virtual ~_str_EnergyGraphic();

    //(*Declarations(_str_EnergyGraphic)
    wxTimer RenderTimer;
    wxSlider* _str_energy_graphic_Slider_zoom_x;
    wxGLCanvas* _str_EnergyGraphic_GLCanvas;
    wxStaticBitmap* StaticBitmap1;
    wxSlider* _str_energy_graphic_Slider_zoom_y;
    //*)

    bool is_gl_init;

    void SetLanguage(Language lang);

protected:

    //(*Identifiers(_str_EnergyGraphic)
    static const long ID_GLCANVAS1;
    static const long ID_STATICBITMAP1;
    static const long ID_SLIDER3;
    static const long ID_SLIDER2;
    static const long ID_TIMER1;
    //*)

private:

    //(*Handlers(_str_EnergyGraphic)
    void On_str_EnergyGraphic_GLCanvasResize(wxSizeEvent& event);
    void OnRenderTimerTrigger(wxTimerEvent& event);
    void OnClose(wxCloseEvent& event);
    void On_str_energy_graphic_Slider_zoom_xCmdSliderUpdated(wxScrollEvent& event);
    void On_str_energy_graphic_Slider_zoom_yCmdSliderUpdated(wxScrollEvent& event);
    void On_str_EnergyGraphic_GLCanvasPaint(wxPaintEvent& event);
    //*)

    wxStaticBoxSizer* scale_sizer;

    DECLARE_EVENT_TABLE()
};

#endif
