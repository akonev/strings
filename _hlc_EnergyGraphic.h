#ifndef _HLC_ENERGYGRAPHIC_H
#define _HLC_ENERGYGRAPHIC_H

//(*Headers(_hlc_EnergyGraphic)
#include <wx/glcanvas.h>
#include <wx/sizer.h>
#include <wx/slider.h>
#include <wx/frame.h>
#include <wx/timer.h>
#include <wx/statbmp.h>
//*)

#include "language.hpp"

class _hlc_EnergyGraphic: public wxFrame
{
	public:

		_hlc_EnergyGraphic(wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~_hlc_EnergyGraphic();

		//(*Declarations(_hlc_EnergyGraphic)
		wxSlider* _hlc_energy_graphic_Slider_zoom_x;
		wxTimer RenderTimer;
		wxSlider* _hlc_energy_graphic_Slider_zoom_y;
		wxGLCanvas* _hlc_EnergyGraphic_GLCanvas;
		wxStaticBitmap* StaticBitmap1;
		//*)

        bool is_gl_init;

        void SetLanguage(Language lang);

	protected:

		//(*Identifiers(_hlc_EnergyGraphic)
		static const long ID_GLCANVAS1;
		static const long ID_STATICBITMAP1;
		static const long ID_SLIDER1;
		static const long ID_SLIDER2;
		static const long ID_TIMER1;
		//*)

	private:

		//(*Handlers(_hlc_EnergyGraphic)
		void OnClose(wxCloseEvent& event);
		void OnRenderTimerTrigger(wxTimerEvent& event);
		void OnGLCanvas1Resize(wxSizeEvent& event);
		void On_hlc_EnergyGraphic_GLCanvasPaint(wxPaintEvent& event);
		void On_hlc_energy_graphic_Slider_zoom_yCmdSliderUpdated(wxScrollEvent& event);
		void On_hlc_energy_graphic_Slider_zoom_xCmdSliderUpdated(wxScrollEvent& event);
		//*)

		wxStaticBoxSizer* scale_sizer;

		DECLARE_EVENT_TABLE()
};

#endif
