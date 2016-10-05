#ifndef _DSTR_ENERGYGRAPHIC_H
#define _DSTR_ENERGYGRAPHIC_H

//(*Headers(_dstr_EnergyGraphic)
#include <wx/glcanvas.h>
#include <wx/spinctrl.h>
#include <wx/sizer.h>
#include <wx/slider.h>
#include <wx/frame.h>
#include <wx/timer.h>
#include <wx/statbmp.h>
//*)

#include "language.hpp"

class _dstr_EnergyGraphic: public wxFrame
{
	public:

		_dstr_EnergyGraphic(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~_dstr_EnergyGraphic();

		//(*Declarations(_dstr_EnergyGraphic)
		wxTimer RenderTimer;
		wxGLCanvas* _dstr_EnergyGraphic_GLCanvas;
		wxSlider* _dstr_energy_graphic_Slider_zoom_x;
		wxSpinCtrl* _dstr_SpinCtrl_graphic_wheit_num;
		wxStaticBitmap* StaticBitmap1;
		wxSlider* _dstr_energy_graphic_Slider_zoom_y;
		//*)

		bool is_gl_init;

		void SetLanguage(Language lang);

	protected:

		//(*Identifiers(_dstr_EnergyGraphic)
		static const long ID_GLCANVAS1;
		static const long ID_STATICBITMAP1;
		static const long ID_SPINCTRL1;
		static const long ID_SLIDER2;
		static const long ID_SLIDER1;
		static const long ID_TIMER1;
		//*)

	private:

		//(*Handlers(_dstr_EnergyGraphic)
		void OnGLCanvas1Resize(wxSizeEvent& event);
		void OnClose(wxCloseEvent& event);
		void OnTimer1Trigger(wxTimerEvent& event);
		void On_dstr_SpinCtrl_graphic_wheit_numChange(wxSpinEvent& event);
		void On_dstr_energy_graphic_Slider_zoom_xCmdSliderUpdated(wxScrollEvent& event);
		void On_dstr_EnergyGraphic_GLCanvasPaint(wxPaintEvent& event);
		void On_dstr_energy_graphic_Slider_zoom_yCmdSliderUpdated(wxScrollEvent& event);
		//*)

    wxStaticBoxSizer* scale_sizer;
		wxStaticBoxSizer* number_sizer;

		DECLARE_EVENT_TABLE()
};

#endif
