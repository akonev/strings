#ifndef _STR_HARMGRAPHIC_H
#define _STR_HARMGRAPHIC_H

//(*Headers(_str_HarmGraphic)
#include <wx/glcanvas.h>
#include <wx/spinctrl.h>
#include <wx/sizer.h>
#include <wx/slider.h>
#include <wx/frame.h>
#include <wx/timer.h>
//*)

#include "language.hpp"

class _str_HarmGraphic: public wxFrame
{
	public:

		_str_HarmGraphic(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~_str_HarmGraphic();

		//(*Declarations(_str_HarmGraphic)
		wxGLCanvas* _str_HarmGraphic_GLCanvas;
		wxSlider* _str_harm_graphic_Slider_zoom_y;
		wxSlider* _str_harm_graphic_Slider_zoom_x;
		wxTimer RenderTimer;
		wxSpinCtrl* _str_SpinCtrl_harm_num;
		//*)

		bool is_gl5_init;

		void SetLanguage(Language lang);

	protected:

		//(*Identifiers(_str_HarmGraphic)
		static const long ID_GLCANVAS1;
		static const long ID_SPINCTRL1;
		static const long ID_SLIDER1;
		static const long ID_SLIDER2;
		static const long ID_TIMER1;
		//*)

	private:

		//(*Handlers(_str_HarmGraphic)
		void On_str_HarmGraphic_GLCanvasResize(wxSizeEvent& event);
		void OnClose(wxCloseEvent& event);
		void OnRenderTimerTrigger(wxTimerEvent& event);
		void On_str_SpinCtrl_harm_numChange(wxSpinEvent& event);
		void On_str_harm_graphic_Slider_zoom_xCmdSliderUpdated(wxScrollEvent& event);
		void On_str_harm_graphic_Slider_zoom_yCmdSliderUpdated(wxScrollEvent& event);
		void On_str_HarmGraphic_GLCanvasPaint(wxPaintEvent& event);
		//*)

		wxStaticBoxSizer* scale_sizer;
		wxStaticBoxSizer* number_sizer;

		DECLARE_EVENT_TABLE()
};

#endif
