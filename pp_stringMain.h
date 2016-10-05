/***************************************************************
 * Name:      pp_stringMain.h
 * Purpose:   Defines Application Frame
 * Author:    Temior (temior.wl@gmail.com)
 * Created:   2012-03-01
 * Copyright: Temior (white-projects.6te.net)
 * License:
 **************************************************************/

#ifndef PP_STRINGMAIN_H
#define PP_STRINGMAIN_H

//(*Headers(pp_stringFrame)
#include <wx/bmpbuttn.h>
#include <wx/glcanvas.h>
#include <wx/spinctrl.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/slider.h>
#include <wx/statusbr.h>
#include <wx/statbox.h>
#include <wx/statline.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/timer.h>
//*)

#include "language.hpp"

#include "_hlc_EnergyGraphic.h"
#include "_dstr_EnergyGraphic.h"
#include "_str_EnergyGraphic.h"
#include "_str_HarmGraphic.h"

class pp_stringFrame: public wxFrame {
public:

    pp_stringFrame(wxWindow* parent,wxWindowID id = -1);
    virtual ~pp_stringFrame();

private:

    //(*Handlers(pp_stringFrame)
    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnClose(wxCloseEvent& event);
    void OnButton1Click(wxCommandEvent& event);
    void On_string_3dviewResize(wxSizeEvent& event);
    void OnButtonInitClick(wxCommandEvent& event);
    void On_string_3dviewLeftDown(wxMouseEvent& event);
    void On_string_3dviewMouseWheel(wxMouseEvent& event);
    void OnBitmapButtonStartClick(wxCommandEvent& event);
    void OnBitmapButtonRefreshClick(wxCommandEvent& event);
    void On_str_Slider_l_CmdSliderUpdated(wxScrollEvent& event);
    void On_str_slider_NCmdScroll(wxScrollEvent& event);
    void On_str_slider_NCmdSliderUpdated(wxScrollEvent& event);
    void On_str_slider_pCmdSliderUpdated(wxScrollEvent& event);
    void On_str_TextCtrl_lTextEnter(wxCommandEvent& event);
    void On_str_TextCtrl_NTextEnter(wxCommandEvent& event);
    void On_str_TextCtrl_pTextEnter(wxCommandEvent& event);
    void On_str_TextCtrl_force_xTextEnter(wxCommandEvent& event);
    void On_str_TextCtrl_force_yTextEnter(wxCommandEvent& event);
    void On_str_PanelPaint(wxPaintEvent& event);
    void On_string_3dviewKeyDown(wxKeyEvent& event);
    void OnButton1Click1(wxCommandEvent& event);
    void On_str_change_force_buttonClick(wxCommandEvent& event);
    void OnSpeedSliderCmdSliderUpdated(wxScrollEvent& event);
    void OnBitmapButtonHomeClick(wxCommandEvent& event);
    void OnBitmapButtonStopClick(wxCommandEvent& event);
    void On_dstr_TextCtrl_lTextEnter(wxCommandEvent& event);
    void On_dstr_slider_lCmdSliderUpdated(wxScrollEvent& event);
    void On_dstr_slider_NCmdSliderUpdated(wxScrollEvent& event);
    void On_dstr_TextCtrl_NTextEnter(wxCommandEvent& event);
    void On_dstr_SpinCtrl_w_nChange(wxSpinEvent& event);
    void On_dstr_SpinCtrl_force_nChange(wxSpinEvent& event);
    void On_dstr_TextCtrl_force_yTextEnter(wxCommandEvent& event);
    void On_dstr_BitmapButton_change_forceClick(wxCommandEvent& event);
    void On_harmc_Slider_pCmdSliderUpdated(wxScrollEvent& event);
    void On_harmc_TextCtrl_pTextEnter(wxCommandEvent& event);
    void On_harmc_Slider_wCmdSliderUpdated(wxScrollEvent& event);
    void On_harmc_TextCtrl_wTextEnter(wxCommandEvent& event);
    void On_harmc_TextCtrl_ATextEnter(wxCommandEvent& event);
    void On_harmc_Slider_ACmdSliderUpdated(wxScrollEvent& event);
    void On_harmc_TextCtrl_NTextEnter(wxCommandEvent& event);
    void On_harmc_Slider_NCmdSliderUpdated(wxScrollEvent& event);
    void On_harmd_Slider_wCmdSliderUpdated(wxScrollEvent& event);
    void On_harmd_TextCtrl_wTextEnter(wxCommandEvent& event);
    void On_harmd_Slider_ACmdSliderUpdated(wxScrollEvent& event);
    void On_harmd_TextCtrl_ATextEnter(wxCommandEvent& event);
    void On_harmd_Slider_NCmdSliderUpdated(wxScrollEvent& event);
    void On_harmd_TextCtrl_NTextEnter(wxCommandEvent& event);
    void On_harmd_TextCtrl_mTextEnter(wxCommandEvent& event);
    void On_harmd_TextCtrl_hTextEnter(wxCommandEvent& event);
    void On_hlc_Slider_lCmdSliderUpdated(wxScrollEvent& event);
    void On_hlc_TextCtrl_lTextEnter(wxCommandEvent& event);
    void On_hlc_Slider_pCmdSliderUpdated(wxScrollEvent& event);
    void On_hlc_TextCtrl_pTextEnter(wxCommandEvent& event);
    void On_hlc_Slider_force_yCmdSliderUpdated(wxScrollEvent& event);
    void On_hlc_TextCtrl_force_yTextEnter(wxCommandEvent& event);
    void On_hlc_Slider_NCmdSliderUpdated(wxScrollEvent& event);
    void On_hlc_TextCtrl_NTextEnter(wxCommandEvent& event);
    void On_dstr_TextCtrl_mTextEnter(wxCommandEvent& event);
    void On_hld_Slider_lCmdSliderUpdated(wxScrollEvent& event);
    void On_hld_TextCtrl_lTextEnter(wxCommandEvent& event);
    void On_hld_Slider_force_yCmdSliderUpdated(wxScrollEvent& event);
    void On_hld_TextCtrl_force_yTextEnter(wxCommandEvent& event);
    void On_hld_Slider_NCmdSliderUpdated(wxScrollEvent& event);
    void On_hld_TextCtrl_NTextEnter(wxCommandEvent& event);
    void On_hld_SpinCtrl_w_nChange(wxSpinEvent& event);
    void On_hld_TextCtrl_mTextEnter(wxCommandEvent& event);
    void On_hlc_SpinCtrl_harm_numChange(wxSpinEvent& event);
    void On_hld_SpinCtrl_harm_numChange(wxSpinEvent& event);
    void On_henv_TextCtrl_pTextEnter(wxCommandEvent& event);
    void On_henv_TextCtrl_p2TextEnter(wxCommandEvent& event);
    void On_henv_Slider_wCmdSliderUpdated(wxScrollEvent& event);
    void On_henv_TextCtrl_wTextEnter(wxCommandEvent& event);
    void On_henv_Slider_force_yCmdSliderUpdated(wxScrollEvent& event);
    void On_henv_TextCtrl_force_yTextEnter(wxCommandEvent& event);
    void On_henv_Slider_NCmdSliderUpdated(wxScrollEvent& event);
    void On_henv_TextCtrl_NTextEnter(wxCommandEvent& event);
    void OnButton1Click2(wxCommandEvent& event);
    void On_dstr_Button_energy_graphicClick(wxCommandEvent& event);
    void On_str_Button_energy_graphicClick(wxCommandEvent& event);
    void On_str_Button_harm_graphicClick(wxCommandEvent& event);
    void OnRenderTimerTrigger(wxTimerEvent& event);
    void On_string_3dviewPaint(wxPaintEvent& event);
    void OnKeyUp(wxKeyEvent& event);
    void On_harmd_TextCtrl_AText(wxCommandEvent& event);
    void On_hlc_Slider_force_yCmdScroll(wxScrollEvent& event);
    void On_hlc_TextCtrl_force_yText(wxCommandEvent& event);
    void On_str_Slider_NCmdScroll(wxScrollEvent& event);
    void OnEnglishLangBitmapButtonClick(wxCommandEvent& event);
    void OnRussianLangBitmapButtonClick(wxCommandEvent& event);
    //*)

    void OnString1(wxCommandEvent& event);
    void OnString2(wxCommandEvent& event);
    void OnString3(wxCommandEvent& event);
    void OnString4(wxCommandEvent& event);
    void OnString5(wxCommandEvent& event);
    void OnString6(wxCommandEvent& event);
    void OnString7(wxCommandEvent& event);
    void OnHelp(wxCommandEvent& event);
    void OnChoiceRussian(wxCommandEvent& event);
    void OnChoiceEnglish(wxCommandEvent& event);
    void OnChangeAntiAliasing(wxCommandEvent& event);

    void HidePanels();
    void SetPause(wxCommandEvent& event);
    void SetLanguage(Language lang);

    //(*Identifiers(pp_stringFrame)
    static const long ID_STATICLINE1;
    static const long ID_string_3dview;
    static const long ID_STATICTEXT2;
    static const long ID_STATICTEXT5;
    static const long ID_STATICTEXT4;
    static const long ID_STATICTEXT3;
    static const long ID_BITMAPBUTTON8;
    static const long ID_BITMAPBUTTON7;
    static const long ID_BITMAPBUTTON13;
    static const long ID_BITMAPBUTTON10;
    static const long ID_BITMAPBUTTON11;
    static const long ID_BITMAPBUTTON12;
    static const long ID_PANEL9;
    static const long ID_STATICBOX6;
    static const long ID_STATICBOX36;
    static const long ID_STATICBOX2;
    static const long ID_STATICBOX7;
    static const long ID_STATICBOX5;
    static const long ID_SLIDER2;
    static const long ID_SLIDER6;
    static const long ID_TEXTCTRL1;
    static const long ID_SLIDER4;
    static const long ID_TEXTCTRL3;
    static const long ID_TEXTCTRL4;
    static const long ID_TEXTCTRL5;
    static const long ID_BITMAPBUTTON6;
    static const long ID_BUTTON3;
    static const long ID_BUTTON4;
    static const long ID_TEXTCTRL2;
    static const long ID_PANEL1;
    static const long ID_STATICBOX35;
    static const long ID_STATICBOX1;
    static const long ID_STATICBOX26;
    static const long ID_STATICBOX27;
    static const long ID_STATICBOX3;
    static const long ID_STATICBOX19;
    static const long ID_SLIDER5;
    static const long ID_TEXTCTRL6;
    static const long ID_SLIDER3;
    static const long ID_TEXTCTRL7;
    static const long ID_SPINCTRL1;
    static const long ID_TEXTCTRL22;
    static const long ID_SPINCTRL2;
    static const long ID_TEXTCTRL8;
    static const long ID_BITMAPBUTTON5;
    static const long ID_BUTTON2;
    static const long ID_PANEL2;
    static const long ID_STATICBOX21;
    static const long ID_STATICBOX20;
    static const long ID_STATICBOX22;
    static const long ID_STATICBOX34;
    static const long ID_SLIDER8;
    static const long ID_TEXTCTRL10;
    static const long ID_SLIDER10;
    static const long ID_TEXTCTRL11;
    static const long ID_SLIDER7;
    static const long ID_TEXTCTRL9;
    static const long ID_SLIDER9;
    static const long ID_TEXTCTRL12;
    static const long ID_PANEL3;
    static const long ID_STATICBOX37;
    static const long ID_STATICBOX30;
    static const long ID_STATICBOX25;
    static const long ID_STATICBOX33;
    static const long ID_STATICBOX28;
    static const long ID_STATICBOX24;
    static const long ID_SPINCTRL4;
    static const long ID_SLIDER14;
    static const long ID_SLIDER17;
    static const long ID_TEXTCTRL21;
    static const long ID_TEXTCTRL18;
    static const long ID_SLIDER15;
    static const long ID_TEXTCTRL19;
    static const long ID_SLIDER16;
    static const long ID_TEXTCTRL20;
    static const long ID_BUTTON1;
    static const long ID_PANEL5;
    static const long ID_STATICBOX32;
    static const long ID_STATICBOX29;
    static const long ID_STATICBOX23;
    static const long ID_STATICBOX9;
    static const long ID_STATICBOX31;
    static const long ID_STATICBOX10;
    static const long ID_SLIDER18;
    static const long ID_TEXTCTRL23;
    static const long ID_SPINCTRL3;
    static const long ID_TEXTCTRL26;
    static const long ID_SLIDER19;
    static const long ID_TEXTCTRL24;
    static const long ID_SLIDER20;
    static const long ID_TEXTCTRL25;
    static const long ID_SPINCTRL5;
    static const long ID_PANEL6;
    static const long ID_STATICBOX4;
    static const long ID_STATICBOX38;
    static const long ID_STATICBOX12;
    static const long ID_STATICBOX11;
    static const long ID_SLIDER21;
    static const long ID_TEXTCTRL27;
    static const long ID_SLIDER22;
    static const long ID_TEXTCTRL28;
    static const long ID_TEXTCTRL30;
    static const long ID_TEXTCTRL31;
    static const long ID_SLIDER23;
    static const long ID_TEXTCTRL29;
    static const long ID_PANEL7;
    static const long ID_STATICBOX16;
    static const long ID_STATICBOX13;
    static const long ID_STATICBOX17;
    static const long ID_STATICBOX18;
    static const long ID_STATICBOX14;
    static const long ID_TEXTCTRL13;
    static const long ID_SLIDER11;
    static const long ID_TEXTCTRL15;
    static const long ID_SLIDER12;
    static const long ID_TEXTCTRL16;
    static const long ID_SLIDER13;
    static const long ID_TEXTCTRL14;
    static const long ID_TEXTCTRL17;
    static const long ID_PANEL4;
    static const long ID_PANEL8;
    static const long ID_STATICBOX8;
    static const long ID_STATICTEXT1;
    static const long ID_BITMAPBUTTON1;
    static const long ID_BITMAPBUTTON2;
    static const long ID_BITMAPBUTTON4;
    static const long ID_SLIDER1;
    static const long ID_BITMAPBUTTON3;
    static const long ID_PANELCONTROL;
    static const long idMenuQuit;
    static const long ID_MENUITEM1;
    static const long ID_MENUITEM2;
    static const long ID_MENUITEM3;
    static const long ID_MENUITEM4;
    static const long ID_MENUITEM5;
    static const long ID_MENUITEM6;
    static const long ID_MENUITEM7;
    static const long ID_MENUITEM9;
    static const long ID_MENUITEM10;
    static const long ID_MENUITEM8;
    static const long idMenuAA;
    static const long idMenuHelp;
    static const long idMenuAbout;
    static const long ID_STATUSBAR1;
    static const long ID_TIMER1;
    //*)

    //(*Declarations(pp_stringFrame)
    wxMenu* MenuItem11;
    wxStaticBox* StaticBox31;
    wxStaticBox* StaticBox37;
    wxTextCtrl* _str_TextCtrl_force_x;
    wxTextCtrl* _henv_TextCtrl_force_y;
    wxSlider* _str_Slider_l;
    wxTextCtrl* _harmc_TextCtrl_w;
    wxBitmapButton* BitmapButtonHome;
    wxStaticBox* StaticBox25;
    wxTextCtrl* _hld_TextCtrl_l;
    wxPanel* _hld_Panel;
    wxStaticBox* StaticBox8;
    wxStaticBox* StaticBox7;
    wxBitmapButton* help_home_button_;
    wxTextCtrl* _harmc_TextCtrl_N;
    wxStaticBox* StaticBox36;
    wxTextCtrl* _dstr_TextCtrl_force_y;
    wxSpinCtrl* _hlc_SpinCtrl_harm_num;
    wxTextCtrl* _harmd_TextCtrl_A;
    wxStatusBar* StatusBar1;
    wxTextCtrl* _henv_TextCtrl_p;
    wxBitmapButton* russian_lang_bitmap_button_;
    wxSlider* _hld_Slider_N;
    wxSlider* _hld_Slider_force_y;
    wxStaticBox* StaticBox24;
    wxTextCtrl* _hlc_TextCtrl_p;
    wxSlider* _str_slider_p;
    wxMenuItem* MenuItem12;
    wxTextCtrl* _str_TextCtrl_N;
    wxPanel* _hlc_Panel;
    wxButton* _dstr_Button_energy_graphic;
    wxStaticBox* StaticBox11;
    wxTimer RenderTimer;
    wxTextCtrl* _dstr_TextCtrl_N;
    wxTextCtrl* _harmd_TextCtrl_w;
    wxTextCtrl* _hlc_TextCtrl_N;
    wxBitmapButton* _dstr_BitmapButton_change_force;
    wxBitmapButton* BitmapButtonStart;
    wxSlider* _hlc_Slider_N;
    wxBitmapButton* BitmapButtonStop;
    wxStaticBox* StaticBox22;
    wxTextCtrl* _hld_TextCtrl_m;
    wxStaticBox* StaticBox26;
    wxPanel* hello_panel_;
    wxStaticBox* StaticBox34;
    wxStaticBox* StaticBox12;
    wxStaticText* text_about_refresh_button_;
    wxStaticText* text_about_play_button_;
    wxStaticText* StaticText1;
    wxStaticBox* StaticBox9;
    wxSlider* _hlc_Slider_p;
    wxStaticBox* StaticBox18;
    wxSlider* _henv_Slider_force_y;
    wxStaticBox* StaticBox20;
    wxBitmapButton* english_lang_bitmap_button_;
    wxStaticBox* StaticBox2;
    wxStaticBox* StaticBox16;
    wxSlider* _harmc_Slider_A;
    wxButton* _hlc_Button_Graphic;
    wxSlider* _dstr_slider_N;
    wxStaticBox* StaticBox23;
    wxStaticText* text_about_home_button_;
    wxTextCtrl* _dstr_TextCtrl_m;
    wxButton* _str_Button_harm_graphic;
    wxSlider* _harmd_Slider_w;
    wxTextCtrl* _hlc_TextCtrl_l;
    wxPanel* _str_Panel;
    wxStaticLine* StaticLine1;
    wxTextCtrl* _str_TextCtrl_p;
    wxStaticText* text_about_stop_button_;
    wxBitmapButton* BitmapButtonRefresh;
    wxStaticBox* StaticBox32;
    wxMenuItem* MenuItem9;
    wxSlider* _harmd_Slider_N;
    wxMenu* Menu4;
    wxBitmapButton* help_refresh_button_;
    wxSlider* _str_Slider_N;
    wxTextCtrl* _harmc_TextCtrl_A;
    wxSlider* _hld_Slider_l;
    wxTextCtrl* _henv_TextCtrl_N;
    wxTextCtrl* _henv_TextCtrl_w;
    wxStaticBox* StaticBox27;
    wxSlider* _henv_Slider_w;
    wxPanel* _dstr_Panel;
    wxBitmapButton* _str_BitmapButton_change_force;
    wxSpinCtrl* _dstr_SpinCtrl_w_n;
    wxStaticBox* StaticBox1;
    wxSlider* _hlc_Slider_l;
    wxTextCtrl* _harmd_TextCtrl_h;
    wxTextCtrl* _harmd_TextCtrl_m;
    wxPanel* _harmc_Panel;
    wxGLCanvas* _string_3dview;
    wxStaticBox* StaticBox3;
    wxStaticBox* StaticBox10;
    wxMenuItem* MenuItem5;
    wxStaticBox* StaticBox14;
    wxTextCtrl* _hld_TextCtrl_N;
    wxStaticBox* StaticBox13;
    wxPanel* _henv_Panel;
    wxStaticBox* StaticBox29;
    wxStaticBox* StaticBox28;
    wxTextCtrl* _henv_TextCtrl_p2;
    wxStaticBox* StaticBox35;
    wxTextCtrl* _harmd_TextCtrl_N;
    wxSlider* _henv_Slider_N;
    wxStaticBox* StaticBox33;
    wxSlider* _harmc_Slider_w;
    wxMenuItem* MenuItem10;
    wxSlider* _harmc_Slider_N;
    wxBitmapButton* help_stop_button_;
    wxSlider* _hlc_Slider_force_y;
    wxPanel* _void_Panel;
    wxMenuItem* MenuItem6;
    wxMenuItem* MenuItem4;
    wxStaticBox* StaticBox4;
    wxStaticBox* StaticBox38;
    wxBitmapButton* help_play_button_;
    wxSlider* _dstr_slider_l;
    wxStaticBox* StaticBox19;
    wxMenuItem* MenuItem13;
    wxTextCtrl* _str_TextCtrl_force_y;
    wxSlider* SpeedSlider;
    wxPanel* _harmd_Panel;
    wxStaticBox* StaticBox5;
    wxSpinCtrl* _hld_SpinCtrl_harm_num;
    wxStaticBox* StaticBox21;
    wxStaticBox* StaticBox17;
    wxSlider* _harmd_Slider_A;
    wxSpinCtrl* _dstr_SpinCtrl_force_n;
    wxTextCtrl* _harmc_TextCtrl_p;
    wxTextCtrl* _str_TextCtrl_l;
    wxSpinCtrl* _hld_SpinCtrl_w_n;
    wxTextCtrl* _hld_TextCtrl_force_y;
    wxTextCtrl* _dstr_TextCtrl_l;
    wxStaticBox* StaticBox30;
    wxButton* _str_Button_energy_graphic;
    wxPanel* PanelControl;
    wxSlider* _harmc_Slider_p;
    wxMenuItem* MenuItem14;
    wxStaticBox* StaticBox6;
    wxTextCtrl* _hlc_TextCtrl_force_y;
    //*)

    Language cur_lang_;

    wxMenuBar*  menu_bar;
    wxMenu*     menu_item_11;

    bool  _is_gl_init;
    float _str_l, _str_N, _str_p, _str_force_x, _str_force_y, _str_sp_r, _str_init;
    float _dstr_l, _dstr_w_n, _dstr__m, _dstr_force_n, _dstr_force_y, _dstr_N;
    float _harmc_w, _harmc_A, _harmc_p, _harmc_N, _harmc_sl, _harmc_fl, _harmc_sp_r;
    float _harmd_w, _harmd_A, _harmd_N, _harmd_m, _harmd_h, _harmd_sl, _harmd_fl;
    float _hlc_l, _hlc_N, _hlc_p, _hlc_force_y,  _hlc_harm_num, _hlc_sp_r;
    float _hld_l, _hld_N, _hld_w_n, _hld_m, _hld_force_y,  _hld_harm_num;
    float _henv_w, _henv_N, _henv_p, _henv_p2, _henv_force_y, _henv_sl, _henv_fl, _henv_sp_r;


    DECLARE_EVENT_TABLE()
};

#endif // PP_STRINGMAIN_H
