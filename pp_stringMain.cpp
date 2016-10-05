/***************************************************************
 * Name:      pp_stringMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Temior (temior.wl@gmail.com)
 * Created:   2012-03-01
 * Copyright: Temior (white-projects.6te.net)
 * License:
 **************************************************************/

#include "pp_stringMain.h"
#include <wx/msgdlg.h>

#include <wx/dcclient.h>

//(*InternalHeaders(pp_stringFrame)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/image.h>
//*)

#include "ppStringController.h"
#include "select.h"

//(*IdInit(pp_stringFrame)
const long pp_stringFrame::ID_STATICLINE1 = wxNewId();
const long pp_stringFrame::ID_string_3dview = wxNewId();
const long pp_stringFrame::ID_STATICTEXT2 = wxNewId();
const long pp_stringFrame::ID_STATICTEXT5 = wxNewId();
const long pp_stringFrame::ID_STATICTEXT4 = wxNewId();
const long pp_stringFrame::ID_STATICTEXT3 = wxNewId();
const long pp_stringFrame::ID_BITMAPBUTTON8 = wxNewId();
const long pp_stringFrame::ID_BITMAPBUTTON7 = wxNewId();
const long pp_stringFrame::ID_BITMAPBUTTON13 = wxNewId();
const long pp_stringFrame::ID_BITMAPBUTTON10 = wxNewId();
const long pp_stringFrame::ID_BITMAPBUTTON11 = wxNewId();
const long pp_stringFrame::ID_BITMAPBUTTON12 = wxNewId();
const long pp_stringFrame::ID_PANEL9 = wxNewId();
const long pp_stringFrame::ID_STATICBOX6 = wxNewId();
const long pp_stringFrame::ID_STATICBOX36 = wxNewId();
const long pp_stringFrame::ID_STATICBOX2 = wxNewId();
const long pp_stringFrame::ID_STATICBOX7 = wxNewId();
const long pp_stringFrame::ID_STATICBOX5 = wxNewId();
const long pp_stringFrame::ID_SLIDER2 = wxNewId();
const long pp_stringFrame::ID_SLIDER6 = wxNewId();
const long pp_stringFrame::ID_TEXTCTRL1 = wxNewId();
const long pp_stringFrame::ID_SLIDER4 = wxNewId();
const long pp_stringFrame::ID_TEXTCTRL3 = wxNewId();
const long pp_stringFrame::ID_TEXTCTRL4 = wxNewId();
const long pp_stringFrame::ID_TEXTCTRL5 = wxNewId();
const long pp_stringFrame::ID_BITMAPBUTTON6 = wxNewId();
const long pp_stringFrame::ID_BUTTON3 = wxNewId();
const long pp_stringFrame::ID_BUTTON4 = wxNewId();
const long pp_stringFrame::ID_TEXTCTRL2 = wxNewId();
const long pp_stringFrame::ID_PANEL1 = wxNewId();
const long pp_stringFrame::ID_STATICBOX35 = wxNewId();
const long pp_stringFrame::ID_STATICBOX1 = wxNewId();
const long pp_stringFrame::ID_STATICBOX26 = wxNewId();
const long pp_stringFrame::ID_STATICBOX27 = wxNewId();
const long pp_stringFrame::ID_STATICBOX3 = wxNewId();
const long pp_stringFrame::ID_STATICBOX19 = wxNewId();
const long pp_stringFrame::ID_SLIDER5 = wxNewId();
const long pp_stringFrame::ID_TEXTCTRL6 = wxNewId();
const long pp_stringFrame::ID_SLIDER3 = wxNewId();
const long pp_stringFrame::ID_TEXTCTRL7 = wxNewId();
const long pp_stringFrame::ID_SPINCTRL1 = wxNewId();
const long pp_stringFrame::ID_TEXTCTRL22 = wxNewId();
const long pp_stringFrame::ID_SPINCTRL2 = wxNewId();
const long pp_stringFrame::ID_TEXTCTRL8 = wxNewId();
const long pp_stringFrame::ID_BITMAPBUTTON5 = wxNewId();
const long pp_stringFrame::ID_BUTTON2 = wxNewId();
const long pp_stringFrame::ID_PANEL2 = wxNewId();
const long pp_stringFrame::ID_STATICBOX21 = wxNewId();
const long pp_stringFrame::ID_STATICBOX20 = wxNewId();
const long pp_stringFrame::ID_STATICBOX22 = wxNewId();
const long pp_stringFrame::ID_STATICBOX34 = wxNewId();
const long pp_stringFrame::ID_SLIDER8 = wxNewId();
const long pp_stringFrame::ID_TEXTCTRL10 = wxNewId();
const long pp_stringFrame::ID_SLIDER10 = wxNewId();
const long pp_stringFrame::ID_TEXTCTRL11 = wxNewId();
const long pp_stringFrame::ID_SLIDER7 = wxNewId();
const long pp_stringFrame::ID_TEXTCTRL9 = wxNewId();
const long pp_stringFrame::ID_SLIDER9 = wxNewId();
const long pp_stringFrame::ID_TEXTCTRL12 = wxNewId();
const long pp_stringFrame::ID_PANEL3 = wxNewId();
const long pp_stringFrame::ID_STATICBOX37 = wxNewId();
const long pp_stringFrame::ID_STATICBOX30 = wxNewId();
const long pp_stringFrame::ID_STATICBOX25 = wxNewId();
const long pp_stringFrame::ID_STATICBOX33 = wxNewId();
const long pp_stringFrame::ID_STATICBOX28 = wxNewId();
const long pp_stringFrame::ID_STATICBOX24 = wxNewId();
const long pp_stringFrame::ID_SPINCTRL4 = wxNewId();
const long pp_stringFrame::ID_SLIDER14 = wxNewId();
const long pp_stringFrame::ID_SLIDER17 = wxNewId();
const long pp_stringFrame::ID_TEXTCTRL21 = wxNewId();
const long pp_stringFrame::ID_TEXTCTRL18 = wxNewId();
const long pp_stringFrame::ID_SLIDER15 = wxNewId();
const long pp_stringFrame::ID_TEXTCTRL19 = wxNewId();
const long pp_stringFrame::ID_SLIDER16 = wxNewId();
const long pp_stringFrame::ID_TEXTCTRL20 = wxNewId();
const long pp_stringFrame::ID_BUTTON1 = wxNewId();
const long pp_stringFrame::ID_PANEL5 = wxNewId();
const long pp_stringFrame::ID_STATICBOX32 = wxNewId();
const long pp_stringFrame::ID_STATICBOX29 = wxNewId();
const long pp_stringFrame::ID_STATICBOX23 = wxNewId();
const long pp_stringFrame::ID_STATICBOX9 = wxNewId();
const long pp_stringFrame::ID_STATICBOX31 = wxNewId();
const long pp_stringFrame::ID_STATICBOX10 = wxNewId();
const long pp_stringFrame::ID_SLIDER18 = wxNewId();
const long pp_stringFrame::ID_TEXTCTRL23 = wxNewId();
const long pp_stringFrame::ID_SPINCTRL3 = wxNewId();
const long pp_stringFrame::ID_TEXTCTRL26 = wxNewId();
const long pp_stringFrame::ID_SLIDER19 = wxNewId();
const long pp_stringFrame::ID_TEXTCTRL24 = wxNewId();
const long pp_stringFrame::ID_SLIDER20 = wxNewId();
const long pp_stringFrame::ID_TEXTCTRL25 = wxNewId();
const long pp_stringFrame::ID_SPINCTRL5 = wxNewId();
const long pp_stringFrame::ID_PANEL6 = wxNewId();
const long pp_stringFrame::ID_STATICBOX4 = wxNewId();
const long pp_stringFrame::ID_STATICBOX38 = wxNewId();
const long pp_stringFrame::ID_STATICBOX12 = wxNewId();
const long pp_stringFrame::ID_STATICBOX11 = wxNewId();
const long pp_stringFrame::ID_SLIDER21 = wxNewId();
const long pp_stringFrame::ID_TEXTCTRL27 = wxNewId();
const long pp_stringFrame::ID_SLIDER22 = wxNewId();
const long pp_stringFrame::ID_TEXTCTRL28 = wxNewId();
const long pp_stringFrame::ID_TEXTCTRL30 = wxNewId();
const long pp_stringFrame::ID_TEXTCTRL31 = wxNewId();
const long pp_stringFrame::ID_SLIDER23 = wxNewId();
const long pp_stringFrame::ID_TEXTCTRL29 = wxNewId();
const long pp_stringFrame::ID_PANEL7 = wxNewId();
const long pp_stringFrame::ID_STATICBOX16 = wxNewId();
const long pp_stringFrame::ID_STATICBOX13 = wxNewId();
const long pp_stringFrame::ID_STATICBOX17 = wxNewId();
const long pp_stringFrame::ID_STATICBOX18 = wxNewId();
const long pp_stringFrame::ID_STATICBOX14 = wxNewId();
const long pp_stringFrame::ID_TEXTCTRL13 = wxNewId();
const long pp_stringFrame::ID_SLIDER11 = wxNewId();
const long pp_stringFrame::ID_TEXTCTRL15 = wxNewId();
const long pp_stringFrame::ID_SLIDER12 = wxNewId();
const long pp_stringFrame::ID_TEXTCTRL16 = wxNewId();
const long pp_stringFrame::ID_SLIDER13 = wxNewId();
const long pp_stringFrame::ID_TEXTCTRL14 = wxNewId();
const long pp_stringFrame::ID_TEXTCTRL17 = wxNewId();
const long pp_stringFrame::ID_PANEL4 = wxNewId();
const long pp_stringFrame::ID_PANEL8 = wxNewId();
const long pp_stringFrame::ID_STATICBOX8 = wxNewId();
const long pp_stringFrame::ID_STATICTEXT1 = wxNewId();
const long pp_stringFrame::ID_BITMAPBUTTON1 = wxNewId();
const long pp_stringFrame::ID_BITMAPBUTTON2 = wxNewId();
const long pp_stringFrame::ID_BITMAPBUTTON4 = wxNewId();
const long pp_stringFrame::ID_SLIDER1 = wxNewId();
const long pp_stringFrame::ID_BITMAPBUTTON3 = wxNewId();
const long pp_stringFrame::ID_PANELCONTROL = wxNewId();
const long pp_stringFrame::idMenuQuit = wxNewId();
const long pp_stringFrame::ID_MENUITEM1 = wxNewId();
const long pp_stringFrame::ID_MENUITEM2 = wxNewId();
const long pp_stringFrame::ID_MENUITEM3 = wxNewId();
const long pp_stringFrame::ID_MENUITEM4 = wxNewId();
const long pp_stringFrame::ID_MENUITEM5 = wxNewId();
const long pp_stringFrame::ID_MENUITEM6 = wxNewId();
const long pp_stringFrame::ID_MENUITEM7 = wxNewId();
const long pp_stringFrame::ID_MENUITEM9 = wxNewId();
const long pp_stringFrame::ID_MENUITEM10 = wxNewId();
const long pp_stringFrame::ID_MENUITEM8 = wxNewId();
const long pp_stringFrame::idMenuAA = wxNewId();
const long pp_stringFrame::idMenuHelp = wxNewId();
const long pp_stringFrame::idMenuAbout = wxNewId();
const long pp_stringFrame::ID_STATUSBAR1 = wxNewId();
const long pp_stringFrame::ID_TIMER1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(pp_stringFrame,wxFrame)
    //(*EventTable(pp_stringFrame)
    //*)
END_EVENT_TABLE()

_hlc_EnergyGraphic* _hlc_EnergyGraphicFrame;
_dstr_EnergyGraphic* _dstr_EnergyGraphicFrame;
_str_EnergyGraphic* _str_EnergyGraphicFrame;
_str_HarmGraphic* _str_HarmGraphicFrame;

void pp_stringFrame::OnString1(wxCommandEvent& event) {
    SetPause(event);
    HidePanels();
    _str_Panel->Show();
    GetSizer()->Layout();
    Update();
    pp_string_t->initString(_str, 7, _str_l, _str_N, _str_p, _str_force_x, _str_force_y, _str_sp_r, -1.0);
    OnBitmapButtonHomeClick(event);
}
void pp_stringFrame::OnString2(wxCommandEvent& event) {
    SetPause(event);
    HidePanels();
    _dstr_Panel->Show();
    GetSizer()->Layout();
    Update();
    pp_string_t->initString(_dstr, 6, _dstr_l, _dstr_w_n, _dstr__m, _dstr_force_n, _dstr_force_y, _dstr_N);
    OnBitmapButtonHomeClick(event);
}
void pp_stringFrame::OnString3(wxCommandEvent& event) {
    SetPause(event);
    HidePanels();
    _harmc_Panel->Show();
    GetSizer()->Layout();
    Update();
    pp_string_t->initString(_harmc, 7, _harmc_w, _harmc_A, _harmc_p, _harmc_N, _harmc_sl, _harmc_fl, _harmc_sp_r);
    OnBitmapButtonHomeClick(event);
}
void pp_stringFrame::OnString4(wxCommandEvent& event) {
    SetPause(event);
    HidePanels();
    _harmd_Panel->Show();
    GetSizer()->Layout();
    Update();
    pp_string_t->initString(_harmd, 7, _harmd_w, _harmd_A, _harmd_N, _harmd_m, _harmd_h, _harmd_sl, _harmd_fl);
    OnBitmapButtonHomeClick(event);
}
void pp_stringFrame::OnString5(wxCommandEvent& event) {
    SetPause(event);
    HidePanels();
    _hlc_Panel->Show();
    GetSizer()->Layout();
    Update();
    pp_string_t->initString(_hlc, 6, _hlc_l, _hlc_N, _hlc_p, _hlc_force_y, _hlc_sp_r, _hlc_harm_num);
    OnBitmapButtonHomeClick(event);
}
void pp_stringFrame::OnString6(wxCommandEvent& event) {
    SetPause(event);
    HidePanels();
    _hld_Panel->Show();
    GetSizer()->Layout();
    Update();
    pp_string_t->initString(_hld, 6, _hld_l, _hld_N, _hld_w_n, _hld_m, _hld_force_y, _hld_harm_num);
    OnBitmapButtonHomeClick(event);
}
void pp_stringFrame::OnString7(wxCommandEvent& event) {
    SetPause(event);
    HidePanels();
    _henv_Panel->Show();
    GetSizer()->Layout();
    Update();
    pp_string_t->initString(_henv, 8, _henv_w, _henv_N, _henv_p, _henv_p2, _henv_force_y, _henv_sl, _henv_fl, _henv_sp_r);
    OnBitmapButtonHomeClick(event);
}

void pp_stringFrame::OnChoiceRussian(wxCommandEvent& event) {
    SetLanguage(kRussian);
}

void pp_stringFrame::OnChoiceEnglish(wxCommandEvent& event) {
    SetLanguage(kEnglish);
}

void pp_stringFrame::OnChangeAntiAliasing(wxCommandEvent& event) {
    pp_string_t->enableAntiAliasing(!pp_string_t->isAntiAliasingEnabled());
}

void pp_stringFrame::HidePanels() {
    hello_panel_->Hide();
    _void_Panel->Hide();
    _str_Panel->Hide();
    _dstr_Panel->Hide();
    _harmc_Panel->Hide();
    _harmd_Panel->Hide();
    _hlc_Panel->Hide();
    _hld_Panel->Hide();
    _henv_Panel->Hide();
    GetSizer()->Layout();
    Update();
}

void pp_stringFrame::SetLanguage(Language lang) {
    cur_lang_ = lang;

    switch(lang) {
    case kEnglish:
        this->SetTitle(_("Vibrations and waves on string"));

        menu_bar->SetMenuLabel(0, _("File"));
        menu_bar->SetMenuLabel(1, _("Experiment"));
        menu_bar->SetMenuLabel(2, _("Preferences"));
        menu_bar->SetMenuLabel(3, _("Help"));

        menu_bar->SetLabel(idMenuQuit, _("Exit\tAlt-F4"));
        menu_bar->SetLabel(idMenuAbout, _("About"));
        menu_bar->SetLabel(ID_MENUITEM1, _("Vibrations of continuous strings"));
        menu_bar->SetLabel(ID_MENUITEM2, _("Vibrations of discrete strings"));
        menu_bar->SetLabel(ID_MENUITEM3, _("Transverse waves on a continuos string"));
        menu_bar->SetLabel(ID_MENUITEM4, _("Transverse waves on a discrete string"));
        menu_bar->SetLabel(ID_MENUITEM5, _("Standing waves on a continuos string"));
        menu_bar->SetLabel(ID_MENUITEM6, _("Standing waves on a discrete string"));
        menu_bar->SetLabel(ID_MENUITEM7, _("Wave on media border"));
        menu_bar->SetLabel(idMenuHelp, _("Help\tF1"));

        menu_item_11->SetLabel(ID_MENUITEM8, _("Language"));

        menu_bar->SetLabel(idMenuAA, _("Anti-aliasing"));

        StaticBox8->SetLabel(_("Control"));
        StaticText1->SetLabel(_("Exp.\nspeed"));

        //Vibrations of continuous strings
        StaticBox6->SetLabel(_("Length, m"));
        StaticBox36->SetLabel(_("Graphics"));
        StaticBox2->SetLabel(_("Init. deviation x(m), y(mm)"));
        StaticBox7->SetLabel(_("Tension force, N"));
        StaticBox5->SetLabel(_("Linear density, g/m"));
        _str_Button_energy_graphic->SetLabel(_("Energy"));
        _str_Button_harm_graphic->SetLabel(_("Harmonics"));

        //Vibrations of discrete strings
        StaticBox35->SetLabel(_("Graphics"));
        StaticBox1->SetLabel(_("Init. deviation n, y(mm)"));
        StaticBox26->SetLabel(_("Mass, kg"));
        StaticBox27->SetLabel( _("Count"));
        StaticBox3->SetLabel(_("Tension force, N"));
        StaticBox19->SetLabel(_("Length, m"));
        _dstr_Button_energy_graphic->SetLabel(_("Energy"));

        //Transverse waves on a continuos string
        StaticBox21->SetLabel(_("Tension force, N"));
        StaticBox20->SetLabel(_("Linear density, kg/m"));
        StaticBox22->SetLabel(_("Amplitude of the impact, N"));
        StaticBox34->SetLabel(_("Frequency of exposure, Hz"));

        //Standing waves on a continuos string
        StaticBox37->SetLabel(_("Graphics"));
        StaticBox30->SetLabel(_("№ harm."));
        StaticBox25->SetLabel(_("Tension force, N"));
        StaticBox33->SetLabel(_("Linear density, kg/m"));
        StaticBox28->SetLabel(_("Amplitude virations, mm"));
        StaticBox24->SetLabel(_("Length, m"));
        _hlc_Button_Graphic->SetLabel(_("Energy"));

        //Standing waves on a discrete string
        StaticBox32->SetLabel(_("Tension force, N"));
        StaticBox29->SetLabel(_("№ harm."));
        StaticBox23->SetLabel(_("Mass, kg"));
        StaticBox9->SetLabel(_("Count"));
        StaticBox31->SetLabel(_("Amplitude virations, mm"));
        StaticBox10->SetLabel(_("Length, m"));

        //Wave on media border
        StaticBox4->SetLabel(_("Tension force, N"));
        StaticBox38->SetLabel(_("Lin. density, [1с, 2с], kg/m"));
        StaticBox12->SetLabel(_("Amplitude virations, mm"));
        StaticBox11->SetLabel(_("Frequency of exposure, Hz"));

        //Transverse waves on a discrete string
        StaticBox16->SetLabel(_("Tension force, N"));
        StaticBox13->SetLabel(_("Amplitude of the impact, N"));
        StaticBox17->SetLabel(_("Mass, kg"));
        StaticBox18->SetLabel(_("Dist. between weights, m"));
        StaticBox14->SetLabel(_("Frequency of exposure, Hz"));

        text_about_play_button_->SetLabel(_("- start/pause demonstration of physics experiment"));
        text_about_stop_button_->SetLabel(_("- stop demonstration of physics experiment"));
        text_about_home_button_->SetLabel(_("- move camera toinitial position"));
        text_about_refresh_button_->SetLabel(_("- apply parameters changes"));
        break;

    case kRussian:
        this->SetTitle(_("Колебания и волны на струне"));

        menu_bar->SetMenuLabel(0, _("Файл"));
        menu_bar->SetMenuLabel(1, _("Эксперимент"));
        menu_bar->SetMenuLabel(2, _("Настройки"));
        menu_bar->SetMenuLabel(3, _("Помощь"));

        menu_bar->SetLabel(idMenuQuit, _("Выход\tAlt-F4"));
        menu_bar->SetLabel(idMenuAbout, _("О программе"));
        menu_bar->SetLabel(ID_MENUITEM1, _("Колебания непрерывной струны"));
        menu_bar->SetLabel(ID_MENUITEM2, _("Колебания дискретной струны"));
        menu_bar->SetLabel(ID_MENUITEM3, _("Поперечные волны на струне"));
        menu_bar->SetLabel(ID_MENUITEM4, _("Поперечные волны на дискретной струне"));
        menu_bar->SetLabel(ID_MENUITEM5, _("Стоячие волны на непрерывной струне"));
        menu_bar->SetLabel(ID_MENUITEM6, _("Стоячие волны на дискретной струне"));
        menu_bar->SetLabel(ID_MENUITEM7, _("Волны на границе раздела двух сред"));
        menu_bar->SetLabel(idMenuHelp, _("Справка\tF1"));

        menu_item_11->SetLabel(ID_MENUITEM8, _("Язык"));

        menu_bar->SetLabel(idMenuAA, _("Сглаживание"));

        StaticBox8->SetLabel(_("Контроль"));
        StaticText1->SetLabel(_("Скорость\nэксп."));

        StaticBox6->SetLabel(_("Длина, м"));
        StaticBox36->SetLabel(_("Графики"));
        StaticBox2->SetLabel(_("Нач. отклонение x(м), y(мм)"));
        StaticBox7->SetLabel(_("Сила натяжения, Н"));
        StaticBox5->SetLabel(_("Линейная плотность, г/м"));
        _str_Button_energy_graphic->SetLabel(_("Энергия"));
        _str_Button_harm_graphic->SetLabel(_("Гармоники"));

        StaticBox35->SetLabel(_("График"));
        StaticBox1->SetLabel(_("Нач. отклонение n, y(мм)"));
        StaticBox26->SetLabel(_("Масса гр., кг"));
        StaticBox27->SetLabel( _("Кол-во гр., шт"));
        StaticBox3->SetLabel(_("Сила натяжения, Н"));
        StaticBox19->SetLabel(_("Длина, м"));
        _dstr_Button_energy_graphic->SetLabel(_("Энергия"));

        StaticBox21->SetLabel(_("Сила натяжения, Н"));
        StaticBox20->SetLabel(_("Линейная плотность, кг/м"));
        StaticBox22->SetLabel(_("Амплитуда воздействия, Н"));
        StaticBox34->SetLabel(_("Частота воздействия, Гц"));

        StaticBox37->SetLabel(_("График"));
        StaticBox30->SetLabel(_("№ гарм."));
        StaticBox25->SetLabel(_("Сила натяжения, Н"));
        StaticBox33->SetLabel(_("Линейная плотность, кг/м"));
        StaticBox28->SetLabel(_("Амплитуда колебаний, мм"));
        StaticBox24->SetLabel(_("Длина, м"));
        _hlc_Button_Graphic->SetLabel(_("Энергия"));

        StaticBox32->SetLabel(_("Сила натяжения, Н"));
        StaticBox29->SetLabel(_("№ гарм."));
        StaticBox23->SetLabel(_("Масса гр., кг"));
        StaticBox9->SetLabel(_("Кол-во гр., шт"));
        StaticBox31->SetLabel(_("Амплитуда колебаний, мм"));
        StaticBox10->SetLabel(_("Длина, м"));

        StaticBox4->SetLabel(_("Сила натяжения, Н"));
        StaticBox38->SetLabel(_("Лин. плотность, [1с, 2с], кг/м"));
        StaticBox12->SetLabel(_("Амплитуда воздействия, Н"));
        StaticBox11->SetLabel(_("Частота воздействия, Гц"));

        //Поперечные волны на дискретной струне
        StaticBox16->SetLabel(_("Сила натяжения, Н"));
        StaticBox13->SetLabel(_("Амплитуда воздействия, Н"));
        StaticBox17->SetLabel(_("Масса гр., кг"));
        StaticBox18->SetLabel(_("Расст. м/г, м"));
        StaticBox14->SetLabel(_("Частота воздействия, Гц"));

        text_about_play_button_->SetLabel(_("- старт/пауза демонстрации физического эксперимента"));
        text_about_stop_button_->SetLabel(_("- остановка демонстрации физическогоэксперимента"));
        text_about_home_button_->SetLabel(_("- возвращение камеры в начальное положение"));
        text_about_refresh_button_->SetLabel(_("- применить изменения параметров эксперимента"));
        break;
    }

    if(_hlc_EnergyGraphicFrame)_hlc_EnergyGraphicFrame->SetLanguage(lang);
    if(_dstr_EnergyGraphicFrame)_dstr_EnergyGraphicFrame->SetLanguage(lang);
    if(_str_EnergyGraphicFrame)_str_EnergyGraphicFrame->SetLanguage(lang);
    if(_str_HarmGraphicFrame)_str_HarmGraphicFrame->SetLanguage(lang);
}
//*******************************************************************//

pp_stringFrame::pp_stringFrame(wxWindow* parent,wxWindowID id) {
    //(*Initialize(pp_stringFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxFlexGridSizer* FlexGridSizer1;
    wxFlexGridSizer* FlexGridSizer2;
    wxMenu* Menu1;
    wxMenu* Menu3;
    wxMenuItem* MenuItem3;
    wxBoxSizer* BoxSizer1;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem7;
    wxMenu* Menu2;
    wxMenuItem* MenuItem8;

    Create(parent, wxID_ANY, _("Колебания и волны на струне"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetBackgroundColour(wxColour(240,240,240));
    {
    	wxIcon FrameIcon;
    	FrameIcon.CopyFromBitmap(wxBitmap(wxImage(_T("data/icon.tga"))));
    	SetIcon(FrameIcon);
    }
    FlexGridSizer1 = new wxFlexGridSizer(1, 1, 0, 0);
    FlexGridSizer1->AddGrowableCol(0);
    FlexGridSizer1->AddGrowableRow(1);
    StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    FlexGridSizer1->Add(StaticLine1, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    int GLCanvasAttributes_1[] = {
    	WX_GL_RGBA,
    	WX_GL_DOUBLEBUFFER,
    	WX_GL_MIN_RED,         8,
    	WX_GL_MIN_GREEN,       8,
    	WX_GL_MIN_BLUE,        8,
    	WX_GL_MIN_ALPHA,       8,
    	WX_GL_DEPTH_SIZE,      16,
    	WX_GL_STENCIL_SIZE,    0,
    	WX_GL_MIN_ACCUM_RED,   8,
    	WX_GL_MIN_ACCUM_GREEN, 8,
    	0, 0 };
    _string_3dview = new wxGLCanvas(this, ID_string_3dview, wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER, _T("ID_string_3dview"), GLCanvasAttributes_1);
    _string_3dview->SetMinSize(wxSize(800,360));
    FlexGridSizer1->Add(_string_3dview, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2 = new wxFlexGridSizer(1, 2, 0, 0);
    FlexGridSizer2->AddGrowableCol(0);
    FlexGridSizer2->AddGrowableRow(0);
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    hello_panel_ = new wxPanel(this, ID_PANEL9, wxDefaultPosition, wxSize(630,112), wxTAB_TRAVERSAL, _T("ID_PANEL9"));
    hello_panel_->SetBackgroundColour(wxColour(240,240,240));
    text_about_play_button_ = new wxStaticText(hello_panel_, ID_STATICTEXT2, _("text_about_play_button_"), wxPoint(160,8), wxSize(408,24), 0, _T("ID_STATICTEXT2"));
    text_about_refresh_button_ = new wxStaticText(hello_panel_, ID_STATICTEXT5, _("text_about_refresh_button_"), wxPoint(160,80), wxSize(408,24), 0, _T("ID_STATICTEXT5"));
    text_about_home_button_ = new wxStaticText(hello_panel_, ID_STATICTEXT4, _("text_about_home_button_"), wxPoint(160,56), wxSize(408,24), 0, _T("ID_STATICTEXT4"));
    text_about_stop_button_ = new wxStaticText(hello_panel_, ID_STATICTEXT3, _("text_about_stop_button_"), wxPoint(160,32), wxSize(408,24), 0, _T("ID_STATICTEXT3"));
    english_lang_bitmap_button_ = new wxBitmapButton(hello_panel_, ID_BITMAPBUTTON8, wxBitmap(wxImage(_T("data/english.jpg"))), wxPoint(8,8), wxSize(72,48), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON8"));
    russian_lang_bitmap_button_ = new wxBitmapButton(hello_panel_, ID_BITMAPBUTTON7, wxBitmap(wxImage(_T("data/russian.gif"))), wxPoint(8,56), wxSize(72,48), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON7"));
    help_play_button_ = new wxBitmapButton(hello_panel_, ID_BITMAPBUTTON13, wxBitmap(wxImage(_T("data/start_button.tga"))), wxPoint(128,8), wxSize(24,24), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON13"));
    help_play_button_->SetBitmapDisabled(wxBitmap(wxImage(_T("data/pause_button.tga"))));
    help_play_button_->SetBitmapSelected(wxBitmap(wxImage(_T("data/start_button.tga"))));
    help_stop_button_ = new wxBitmapButton(hello_panel_, ID_BITMAPBUTTON10, wxBitmap(wxImage(_T("data/stop_button.tga"))), wxPoint(128,32), wxSize(24,24), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON10"));
    help_home_button_ = new wxBitmapButton(hello_panel_, ID_BITMAPBUTTON11, wxBitmap(wxImage(_T("data/home_button.tga"))), wxPoint(128,56), wxSize(24,24), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON11"));
    help_refresh_button_ = new wxBitmapButton(hello_panel_, ID_BITMAPBUTTON12, wxBitmap(wxImage(_T("data/refresh_button.tga"))), wxPoint(128,80), wxSize(24,24), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON12"));
    BoxSizer1->Add(hello_panel_, 1, wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    _str_Panel = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxSize(486,29), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    _str_Panel->Hide();
    _str_Panel->SetBackgroundColour(wxColour(240,240,240));
    StaticBox6 = new wxStaticBox(_str_Panel, ID_STATICBOX6, _("Длина, м"), wxPoint(8,0), wxSize(224,56), 0, _T("ID_STATICBOX6"));
    StaticBox36 = new wxStaticBox(_str_Panel, ID_STATICBOX36, _("Графики"), wxPoint(472,0), wxSize(104,88), 0, _T("ID_STATICBOX36"));
    StaticBox2 = new wxStaticBox(_str_Panel, ID_STATICBOX2, _("Нач. отклонение x(м), y(мм)"), wxPoint(240,56), wxSize(224,56), 0, _T("ID_STATICBOX2"));
    StaticBox7 = new wxStaticBox(_str_Panel, ID_STATICBOX7, _("Сила натяжения, Н"), wxPoint(8,56), wxSize(224,56), 0, _T("ID_STATICBOX7"));
    StaticBox5 = new wxStaticBox(_str_Panel, ID_STATICBOX5, _("Линейная плотность, кг/м"), wxPoint(240,0), wxSize(224,56), 0, _T("ID_STATICBOX5"));
    _str_Slider_l = new wxSlider(_str_Panel, ID_SLIDER2, 200, 50, 400, wxPoint(16,24), wxSize(120,24), 0, wxDefaultValidator, _T("ID_SLIDER2"));
    _str_Slider_N = new wxSlider(_str_Panel, ID_SLIDER6, 1000, 1, 500, wxPoint(16,80), wxSize(120,24), 0, wxDefaultValidator, _T("ID_SLIDER6"));
    _str_TextCtrl_N = new wxTextCtrl(_str_Panel, ID_TEXTCTRL1, _("50"), wxPoint(144,80), wxSize(80,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    _str_slider_p = new wxSlider(_str_Panel, ID_SLIDER4, 100, 1, 1000, wxPoint(248,24), wxSize(120,24), 0, wxDefaultValidator, _T("ID_SLIDER4"));
    _str_TextCtrl_p = new wxTextCtrl(_str_Panel, ID_TEXTCTRL3, _("10"), wxPoint(376,24), wxSize(80,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    _str_TextCtrl_force_x = new wxTextCtrl(_str_Panel, ID_TEXTCTRL4, _("10"), wxPoint(248,80), wxSize(80,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    _str_TextCtrl_force_y = new wxTextCtrl(_str_Panel, ID_TEXTCTRL5, _("2"), wxPoint(336,80), wxSize(80,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    _str_BitmapButton_change_force = new wxBitmapButton(_str_Panel, ID_BITMAPBUTTON6, wxBitmap(wxImage(_T("data/change_dot_button.tga"))), wxPoint(424,80), wxSize(32,24), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON6"));
    _str_Button_energy_graphic = new wxButton(_str_Panel, ID_BUTTON3, _("Энергия"), wxPoint(480,24), wxSize(88,24), 0, wxDefaultValidator, _T("ID_BUTTON3"));
    _str_Button_harm_graphic = new wxButton(_str_Panel, ID_BUTTON4, _("Гармоники"), wxPoint(480,56), wxSize(88,24), 0, wxDefaultValidator, _T("ID_BUTTON4"));
    _str_TextCtrl_l = new wxTextCtrl(_str_Panel, ID_TEXTCTRL2, _("20"), wxPoint(144,24), wxSize(80,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    BoxSizer1->Add(_str_Panel, 1, wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    _dstr_Panel = new wxPanel(this, ID_PANEL2, wxDefaultPosition, wxSize(486,30), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    _dstr_Panel->Hide();
    _dstr_Panel->SetBackgroundColour(wxColour(240,240,240));
    StaticBox35 = new wxStaticBox(_dstr_Panel, ID_STATICBOX35, _("График"), wxPoint(472,0), wxSize(88,56), 0, _T("ID_STATICBOX35"));
    StaticBox1 = new wxStaticBox(_dstr_Panel, ID_STATICBOX1, _("Нач. отклонение n, y(мм)"), wxPoint(240,56), wxSize(224,56), 0, _T("ID_STATICBOX1"));
    StaticBox26 = new wxStaticBox(_dstr_Panel, ID_STATICBOX26, _("Масса гр., кг"), wxPoint(360,0), wxSize(104,56), 0, _T("ID_STATICBOX26"));
    StaticBox27 = new wxStaticBox(_dstr_Panel, ID_STATICBOX27, _("Кол-во гр., шт"), wxPoint(240,0), wxSize(120,56), 0, _T("ID_STATICBOX27"));
    StaticBox3 = new wxStaticBox(_dstr_Panel, ID_STATICBOX3, _("Сила натяжения, Н"), wxPoint(8,56), wxSize(224,56), 0, _T("ID_STATICBOX3"));
    StaticBox19 = new wxStaticBox(_dstr_Panel, ID_STATICBOX19, _("Длина, м"), wxPoint(8,0), wxSize(224,56), 0, _T("ID_STATICBOX19"));
    _dstr_slider_l = new wxSlider(_dstr_Panel, ID_SLIDER5, 200, 50, 400, wxPoint(16,24), wxSize(120,24), 0, wxDefaultValidator, _T("ID_SLIDER5"));
    _dstr_TextCtrl_l = new wxTextCtrl(_dstr_Panel, ID_TEXTCTRL6, _("20"), wxPoint(144,24), wxSize(80,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL6"));
    _dstr_slider_N = new wxSlider(_dstr_Panel, ID_SLIDER3, 1000, 0, 1000, wxPoint(16,80), wxSize(120,24), 0, wxDefaultValidator, _T("ID_SLIDER3"));
    _dstr_TextCtrl_N = new wxTextCtrl(_dstr_Panel, ID_TEXTCTRL7, _("100"), wxPoint(144,80), wxSize(80,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL7"));
    _dstr_SpinCtrl_w_n = new wxSpinCtrl(_dstr_Panel, ID_SPINCTRL1, _T("40"), wxPoint(248,24), wxSize(104,24), 0, 1, 100, 40, _T("ID_SPINCTRL1"));
    _dstr_SpinCtrl_w_n->SetValue(_T("40"));
    _dstr_TextCtrl_m = new wxTextCtrl(_dstr_Panel, ID_TEXTCTRL22, _("1"), wxPoint(368,24), wxSize(88,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL22"));
    _dstr_SpinCtrl_force_n = new wxSpinCtrl(_dstr_Panel, ID_SPINCTRL2, _T("3"), wxPoint(248,80), wxSize(88,24), 0, 1, 100, 3, _T("ID_SPINCTRL2"));
    _dstr_SpinCtrl_force_n->SetValue(_T("3"));
    _dstr_TextCtrl_force_y = new wxTextCtrl(_dstr_Panel, ID_TEXTCTRL8, _("2"), wxPoint(344,80), wxSize(72,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL8"));
    _dstr_BitmapButton_change_force = new wxBitmapButton(_dstr_Panel, ID_BITMAPBUTTON5, wxBitmap(wxImage(_T("data/change_dot_button.tga"))), wxPoint(424,80), wxSize(32,24), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON5"));
    _dstr_Button_energy_graphic = new wxButton(_dstr_Panel, ID_BUTTON2, _("Энергия"), wxPoint(480,24), wxSize(72,24), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer1->Add(_dstr_Panel, 1, wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    _harmc_Panel = new wxPanel(this, ID_PANEL3, wxDefaultPosition, wxSize(486,30), wxTAB_TRAVERSAL, _T("ID_PANEL3"));
    _harmc_Panel->Hide();
    _harmc_Panel->SetBackgroundColour(wxColour(240,240,240));
    StaticBox21 = new wxStaticBox(_harmc_Panel, ID_STATICBOX21, _("Сила натяжения, Н"), wxPoint(240,56), wxSize(224,56), 0, _T("ID_STATICBOX21"));
    StaticBox20 = new wxStaticBox(_harmc_Panel, ID_STATICBOX20, _("Линейная плотность, кг/м"), wxPoint(240,0), wxSize(224,56), 0, _T("ID_STATICBOX20"));
    StaticBox22 = new wxStaticBox(_harmc_Panel, ID_STATICBOX22, _("Амплитуда воздействия, Н"), wxPoint(8,56), wxSize(224,56), 0, _T("ID_STATICBOX22"));
    StaticBox34 = new wxStaticBox(_harmc_Panel, ID_STATICBOX34, _("Частота воздействия, 1/c"), wxPoint(8,0), wxSize(224,56), 0, _T("ID_STATICBOX34"));
    _harmc_Slider_w = new wxSlider(_harmc_Panel, ID_SLIDER8, 100, 10, 350, wxPoint(16,24), wxSize(120,24), 0, wxDefaultValidator, _T("ID_SLIDER8"));
    _harmc_TextCtrl_w = new wxTextCtrl(_harmc_Panel, ID_TEXTCTRL10, _("10"), wxPoint(144,24), wxSize(80,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL10"));
    _harmc_Slider_A = new wxSlider(_harmc_Panel, ID_SLIDER10, 400, 10, 800, wxPoint(16,80), wxSize(120,24), 0, wxDefaultValidator, _T("ID_SLIDER10"));
    _harmc_TextCtrl_A = new wxTextCtrl(_harmc_Panel, ID_TEXTCTRL11, _("400"), wxPoint(144,80), wxSize(80,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL11"));
    _harmc_Slider_p = new wxSlider(_harmc_Panel, ID_SLIDER7, 100, 50, 1000, wxPoint(248,24), wxSize(120,24), 0, wxDefaultValidator, _T("ID_SLIDER7"));
    _harmc_TextCtrl_p = new wxTextCtrl(_harmc_Panel, ID_TEXTCTRL9, _("10"), wxPoint(376,24), wxSize(80,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL9"));
    _harmc_Slider_N = new wxSlider(_harmc_Panel, ID_SLIDER9, 1000, 50, 1000, wxPoint(248,80), wxSize(120,24), 0, wxDefaultValidator, _T("ID_SLIDER9"));
    _harmc_TextCtrl_N = new wxTextCtrl(_harmc_Panel, ID_TEXTCTRL12, _("100"), wxPoint(376,80), wxSize(80,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL12"));
    BoxSizer1->Add(_harmc_Panel, 1, wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    _hlc_Panel = new wxPanel(this, ID_PANEL5, wxDefaultPosition, wxSize(486,30), wxTAB_TRAVERSAL, _T("ID_PANEL5"));
    _hlc_Panel->Hide();
    _hlc_Panel->SetBackgroundColour(wxColour(240,240,240));
    StaticBox37 = new wxStaticBox(_hlc_Panel, ID_STATICBOX37, _("График"), wxPoint(472,56), wxSize(88,56), 0, _T("ID_STATICBOX37"));
    StaticBox30 = new wxStaticBox(_hlc_Panel, ID_STATICBOX30, _("№ гарм."), wxPoint(472,0), wxSize(96,56), 0, _T("ID_STATICBOX30"));
    StaticBox25 = new wxStaticBox(_hlc_Panel, ID_STATICBOX25, _("Сила натяжения, Н"), wxPoint(240,56), wxSize(224,56), 0, _T("ID_STATICBOX25"));
    StaticBox33 = new wxStaticBox(_hlc_Panel, ID_STATICBOX33, _("Линейная плотность, кг/м"), wxPoint(240,0), wxSize(224,56), 0, _T("ID_STATICBOX33"));
    StaticBox28 = new wxStaticBox(_hlc_Panel, ID_STATICBOX28, _("Амплитуда воздействия, Н"), wxPoint(8,56), wxSize(224,56), 0, _T("ID_STATICBOX28"));
    StaticBox24 = new wxStaticBox(_hlc_Panel, ID_STATICBOX24, _("Длина, м"), wxPoint(8,0), wxSize(224,56), 0, _T("ID_STATICBOX24"));
    _hlc_SpinCtrl_harm_num = new wxSpinCtrl(_hlc_Panel, ID_SPINCTRL4, _T("1"), wxPoint(480,24), wxSize(80,24), 0, 1, 10, 1, _T("ID_SPINCTRL4"));
    _hlc_SpinCtrl_harm_num->SetValue(_T("1"));
    _hlc_Slider_l = new wxSlider(_hlc_Panel, ID_SLIDER14, 200, 50, 400, wxPoint(16,24), wxSize(120,24), 0, wxDefaultValidator, _T("ID_SLIDER14"));
    _hlc_Slider_force_y = new wxSlider(_hlc_Panel, ID_SLIDER17, 2, 1, 8, wxPoint(16,80), wxSize(120,24), 0, wxDefaultValidator, _T("ID_SLIDER17"));
    _hlc_TextCtrl_force_y = new wxTextCtrl(_hlc_Panel, ID_TEXTCTRL21, _("2"), wxPoint(144,80), wxSize(80,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL21"));
    _hlc_TextCtrl_l = new wxTextCtrl(_hlc_Panel, ID_TEXTCTRL18, _("20"), wxPoint(144,24), wxSize(80,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL18"));
    _hlc_Slider_p = new wxSlider(_hlc_Panel, ID_SLIDER15, 100, 1, 1000, wxPoint(248,24), wxSize(120,24), 0, wxDefaultValidator, _T("ID_SLIDER15"));
    _hlc_TextCtrl_p = new wxTextCtrl(_hlc_Panel, ID_TEXTCTRL19, _("10"), wxPoint(376,24), wxSize(80,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL19"));
    _hlc_Slider_N = new wxSlider(_hlc_Panel, ID_SLIDER16, 1000, 1, 1000, wxPoint(248,80), wxSize(120,24), 0, wxDefaultValidator, _T("ID_SLIDER16"));
    _hlc_TextCtrl_N = new wxTextCtrl(_hlc_Panel, ID_TEXTCTRL20, _("100"), wxPoint(376,80), wxSize(80,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL20"));
    _hlc_Button_Graphic = new wxButton(_hlc_Panel, ID_BUTTON1, _("Энергия"), wxPoint(480,80), wxSize(72,24), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer1->Add(_hlc_Panel, 1, wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    _hld_Panel = new wxPanel(this, ID_PANEL6, wxDefaultPosition, wxSize(486,30), wxTAB_TRAVERSAL, _T("ID_PANEL6"));
    _hld_Panel->Hide();
    _hld_Panel->SetBackgroundColour(wxColour(240,240,240));
    StaticBox32 = new wxStaticBox(_hld_Panel, ID_STATICBOX32, _("Сила натяжения, Н"), wxPoint(240,56), wxSize(224,56), 0, _T("ID_STATICBOX32"));
    StaticBox29 = new wxStaticBox(_hld_Panel, ID_STATICBOX29, _("№ гарм."), wxPoint(472,0), wxSize(96,56), 0, _T("ID_STATICBOX29"));
    StaticBox23 = new wxStaticBox(_hld_Panel, ID_STATICBOX23, _("Масса гр., кг"), wxPoint(360,0), wxSize(104,56), 0, _T("ID_STATICBOX23"));
    StaticBox9 = new wxStaticBox(_hld_Panel, ID_STATICBOX9, _("Кол-во гр., шт"), wxPoint(240,0), wxSize(120,56), 0, _T("ID_STATICBOX9"));
    StaticBox31 = new wxStaticBox(_hld_Panel, ID_STATICBOX31, _("Амплитуда воздействия, Н"), wxPoint(8,56), wxSize(224,56), 0, _T("ID_STATICBOX31"));
    StaticBox10 = new wxStaticBox(_hld_Panel, ID_STATICBOX10, _("Длина, м"), wxPoint(8,0), wxSize(224,56), 0, _T("ID_STATICBOX10"));
    _hld_Slider_l = new wxSlider(_hld_Panel, ID_SLIDER18, 200, 50, 400, wxPoint(16,24), wxSize(120,24), 0, wxDefaultValidator, _T("ID_SLIDER18"));
    _hld_TextCtrl_l = new wxTextCtrl(_hld_Panel, ID_TEXTCTRL23, _("20"), wxPoint(144,24), wxSize(80,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL23"));
    _hld_SpinCtrl_w_n = new wxSpinCtrl(_hld_Panel, ID_SPINCTRL3, _T("10"), wxPoint(248,24), wxSize(104,24), 0, 1, 50, 10, _T("ID_SPINCTRL3"));
    _hld_SpinCtrl_w_n->SetValue(_T("10"));
    _hld_TextCtrl_m = new wxTextCtrl(_hld_Panel, ID_TEXTCTRL26, _("1"), wxPoint(368,24), wxSize(88,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL26"));
    _hld_Slider_force_y = new wxSlider(_hld_Panel, ID_SLIDER19, 2, 1, 8, wxPoint(16,80), wxSize(120,24), 0, wxDefaultValidator, _T("ID_SLIDER19"));
    _hld_TextCtrl_force_y = new wxTextCtrl(_hld_Panel, ID_TEXTCTRL24, _("2"), wxPoint(144,80), wxSize(80,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL24"));
    _hld_Slider_N = new wxSlider(_hld_Panel, ID_SLIDER20, 1000, 5, 1000, wxPoint(248,80), wxSize(120,24), 0, wxDefaultValidator, _T("ID_SLIDER20"));
    _hld_TextCtrl_N = new wxTextCtrl(_hld_Panel, ID_TEXTCTRL25, _("100"), wxPoint(376,80), wxSize(80,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL25"));
    _hld_SpinCtrl_harm_num = new wxSpinCtrl(_hld_Panel, ID_SPINCTRL5, _T("1"), wxPoint(480,24), wxSize(80,24), 0, 1, 10, 1, _T("ID_SPINCTRL5"));
    _hld_SpinCtrl_harm_num->SetValue(_T("1"));
    BoxSizer1->Add(_hld_Panel, 1, wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    _henv_Panel = new wxPanel(this, ID_PANEL7, wxDefaultPosition, wxSize(486,30), wxTAB_TRAVERSAL, _T("ID_PANEL7"));
    _henv_Panel->Hide();
    _henv_Panel->SetBackgroundColour(wxColour(240,240,240));
    StaticBox4 = new wxStaticBox(_henv_Panel, ID_STATICBOX4, _("Сила натяжения, Н"), wxPoint(240,56), wxSize(224,56), 0, _T("ID_STATICBOX4"));
    StaticBox38 = new wxStaticBox(_henv_Panel, ID_STATICBOX38, _("Лин. плотность, [1с, 2с], кг/м"), wxPoint(240,0), wxSize(224,56), 0, _T("ID_STATICBOX38"));
    StaticBox12 = new wxStaticBox(_henv_Panel, ID_STATICBOX12, _("Амплитуда воздействия, Н"), wxPoint(8,56), wxSize(224,56), 0, _T("ID_STATICBOX12"));
    StaticBox11 = new wxStaticBox(_henv_Panel, ID_STATICBOX11, _("Частота воздействия, 1/c"), wxPoint(8,0), wxSize(224,56), 0, _T("ID_STATICBOX11"));
    _henv_Slider_w = new wxSlider(_henv_Panel, ID_SLIDER21, 100, 10, 350, wxPoint(16,24), wxSize(120,24), 0, wxDefaultValidator, _T("ID_SLIDER21"));
    _henv_TextCtrl_w = new wxTextCtrl(_henv_Panel, ID_TEXTCTRL27, _("10"), wxPoint(144,24), wxSize(80,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL27"));
    _henv_Slider_force_y = new wxSlider(_henv_Panel, ID_SLIDER22, 20, 10, 400, wxPoint(16,80), wxSize(120,24), 0, wxDefaultValidator, _T("ID_SLIDER22"));
    _henv_TextCtrl_force_y = new wxTextCtrl(_henv_Panel, ID_TEXTCTRL28, _("2"), wxPoint(144,80), wxSize(80,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL28"));
    _henv_TextCtrl_p = new wxTextCtrl(_henv_Panel, ID_TEXTCTRL30, _("10"), wxPoint(248,24), wxSize(96,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL30"));
    _henv_TextCtrl_p2 = new wxTextCtrl(_henv_Panel, ID_TEXTCTRL31, _("1"), wxPoint(360,24), wxSize(96,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL31"));
    _henv_Slider_N = new wxSlider(_henv_Panel, ID_SLIDER23, 1000, 5, 1000, wxPoint(248,80), wxSize(120,24), 0, wxDefaultValidator, _T("ID_SLIDER23"));
    _henv_TextCtrl_N = new wxTextCtrl(_henv_Panel, ID_TEXTCTRL29, _("100"), wxPoint(376,80), wxSize(80,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL29"));
    BoxSizer1->Add(_henv_Panel, 1, wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    _harmd_Panel = new wxPanel(this, ID_PANEL4, wxDefaultPosition, wxSize(486,30), wxTAB_TRAVERSAL, _T("ID_PANEL4"));
    _harmd_Panel->Hide();
    _harmd_Panel->SetBackgroundColour(wxColour(240,240,240));
    StaticBox16 = new wxStaticBox(_harmd_Panel, ID_STATICBOX16, _("Сила натяжения, Н"), wxPoint(240,56), wxSize(224,56), 0, _T("ID_STATICBOX16"));
    StaticBox13 = new wxStaticBox(_harmd_Panel, ID_STATICBOX13, _("Амплитуда воздействия, Н"), wxPoint(8,56), wxSize(224,56), 0, _T("ID_STATICBOX13"));
    StaticBox17 = new wxStaticBox(_harmd_Panel, ID_STATICBOX17, _("Масса гр., кг"), wxPoint(240,0), wxSize(120,56), 0, _T("ID_STATICBOX17"));
    StaticBox18 = new wxStaticBox(_harmd_Panel, ID_STATICBOX18, _("Расст. м/г, м"), wxPoint(360,0), wxSize(104,56), 0, _T("ID_STATICBOX18"));
    StaticBox14 = new wxStaticBox(_harmd_Panel, ID_STATICBOX14, _("Частота воздействия, 1/c"), wxPoint(8,0), wxSize(224,56), 0, _T("ID_STATICBOX14"));
    _harmd_TextCtrl_m = new wxTextCtrl(_harmd_Panel, ID_TEXTCTRL13, _("1"), wxPoint(248,24), wxSize(104,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL13"));
    _harmd_Slider_w = new wxSlider(_harmd_Panel, ID_SLIDER11, 100, 10, 350, wxPoint(16,24), wxSize(120,24), 0, wxDefaultValidator, _T("ID_SLIDER11"));
    _harmd_TextCtrl_w = new wxTextCtrl(_harmd_Panel, ID_TEXTCTRL15, _("10"), wxPoint(144,24), wxSize(80,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL15"));
    _harmd_Slider_A = new wxSlider(_harmd_Panel, ID_SLIDER12, 40, 10, 1000, wxPoint(16,80), wxSize(120,24), 0, wxDefaultValidator, _T("ID_SLIDER12"));
    _harmd_TextCtrl_A = new wxTextCtrl(_harmd_Panel, ID_TEXTCTRL16, _("40"), wxPoint(144,80), wxSize(80,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL16"));
    _harmd_Slider_N = new wxSlider(_harmd_Panel, ID_SLIDER13, 1000, 5, 1000, wxPoint(248,80), wxSize(120,24), 0, wxDefaultValidator, _T("ID_SLIDER13"));
    _harmd_TextCtrl_h = new wxTextCtrl(_harmd_Panel, ID_TEXTCTRL14, _("2"), wxPoint(368,24), wxSize(88,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL14"));
    _harmd_TextCtrl_N = new wxTextCtrl(_harmd_Panel, ID_TEXTCTRL17, _("100"), wxPoint(376,80), wxSize(80,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL17"));
    BoxSizer1->Add(_harmd_Panel, 1, wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    _void_Panel = new wxPanel(this, ID_PANEL8, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL8"));
    _void_Panel->Hide();
    _void_Panel->SetBackgroundColour(wxColour(240,240,240));
    BoxSizer1->Add(_void_Panel, 1, wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2->Add(BoxSizer1, 1, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    PanelControl = new wxPanel(this, ID_PANELCONTROL, wxDefaultPosition, wxSize(176,109), wxTAB_TRAVERSAL, _T("ID_PANELCONTROL"));
    PanelControl->SetBackgroundColour(wxColour(240,240,240));
    StaticBox8 = new wxStaticBox(PanelControl, ID_STATICBOX8, _("Контроль"), wxPoint(0,0), wxSize(176,112), 0, _T("ID_STATICBOX8"));
    StaticText1 = new wxStaticText(PanelControl, ID_STATICTEXT1, _("Скорость\nэксп."), wxPoint(8,72), wxSize(72,30), 0, _T("ID_STATICTEXT1"));
    BitmapButtonStart = new wxBitmapButton(PanelControl, ID_BITMAPBUTTON1, wxBitmap(wxImage(_T("data/start_button.tga"))), wxPoint(8,16), wxSize(32,32), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
    BitmapButtonStart->SetBitmapDisabled(wxBitmap(wxImage(_T("data/pause_button.tga"))));
    BitmapButtonStart->SetBitmapSelected(wxBitmap(wxImage(_T("data/start_button.tga"))));
    BitmapButtonStop = new wxBitmapButton(PanelControl, ID_BITMAPBUTTON2, wxBitmap(wxImage(_T("data/stop_button.tga"))), wxPoint(48,16), wxSize(32,32), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON2"));
    BitmapButtonHome = new wxBitmapButton(PanelControl, ID_BITMAPBUTTON4, wxBitmap(wxImage(_T("data/home_button.tga"))), wxPoint(96,16), wxSize(32,32), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON4"));
    SpeedSlider = new wxSlider(PanelControl, ID_SLIDER1, 100, 1, 300, wxPoint(80,56), wxSize(88,48), wxSL_LABELS, wxDefaultValidator, _T("ID_SLIDER1"));
    BitmapButtonRefresh = new wxBitmapButton(PanelControl, ID_BITMAPBUTTON3, wxBitmap(wxImage(_T("data/refresh_button.tga"))), wxPoint(136,16), wxSize(32,32), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON3"));
    BitmapButtonRefresh->SetDefault();
    FlexGridSizer2->Add(PanelControl, 1, wxEXPAND|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(FlexGridSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Выход\tAlt-F4"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("Файл"));
    Menu3 = new wxMenu();
    MenuItem3 = new wxMenuItem(Menu3, ID_MENUITEM1, _("Колебания непрерывной струны"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem3);
    MenuItem4 = new wxMenuItem(Menu3, ID_MENUITEM2, _("Колебания дискретной струны"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem4);
    MenuItem5 = new wxMenuItem(Menu3, ID_MENUITEM3, _("Поперечные волны на струне"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem5);
    MenuItem6 = new wxMenuItem(Menu3, ID_MENUITEM4, _("Поперечные волны на дискретной струне"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem6);
    MenuItem7 = new wxMenuItem(Menu3, ID_MENUITEM5, _("Стоячие волны на непрерывной струне"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem7);
    MenuItem8 = new wxMenuItem(Menu3, ID_MENUITEM6, _("Стоячие волны на дискретной струне"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem8);
    MenuItem9 = new wxMenuItem(Menu3, ID_MENUITEM7, _("Волны на границе раздела двух сред"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem9);
    MenuBar1->Append(Menu3, _("Эксперимент"));
    Menu4 = new wxMenu();
    MenuItem11 = new wxMenu();
    MenuItem12 = new wxMenuItem(MenuItem11, ID_MENUITEM9, _("Русский"), wxEmptyString, wxITEM_RADIO);
    MenuItem11->Append(MenuItem12);
    MenuItem13 = new wxMenuItem(MenuItem11, ID_MENUITEM10, _("English"), wxEmptyString, wxITEM_RADIO);
    MenuItem11->Append(MenuItem13);
    Menu4->Append(ID_MENUITEM8, _("Язык"), MenuItem11, wxEmptyString);
    MenuItem14 = new wxMenuItem(Menu4, idMenuAA, _("Сглаживание"), wxEmptyString, wxITEM_CHECK);
    Menu4->Append(MenuItem14);
    MenuBar1->Append(Menu4, _("Настройки"));
    Menu2 = new wxMenu();
    MenuItem10 = new wxMenuItem(Menu2, idMenuHelp, _("Справка\tF1"), wxEmptyString, wxITEM_NORMAL);
    Menu2->Append(MenuItem10);
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("О программе"), wxEmptyString, wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Помощь"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    RenderTimer.SetOwner(this, ID_TIMER1);
    RenderTimer.Start(1, false);
    FlexGridSizer1->Fit(this);
    FlexGridSizer1->SetSizeHints(this);

    _string_3dview->Connect(wxEVT_PAINT,(wxObjectEventFunction)&pp_stringFrame::On_string_3dviewPaint,0,this);
    _string_3dview->Connect(wxEVT_KEY_UP,(wxObjectEventFunction)&pp_stringFrame::OnKeyUp,0,this);
    _string_3dview->Connect(wxEVT_MOTION,(wxObjectEventFunction)&pp_stringFrame::On_string_3dviewLeftDown,0,this);
    _string_3dview->Connect(wxEVT_MOUSEWHEEL,(wxObjectEventFunction)&pp_stringFrame::On_string_3dviewMouseWheel,0,this);
    _string_3dview->Connect(wxEVT_SIZE,(wxObjectEventFunction)&pp_stringFrame::On_string_3dviewResize,0,this);
    Connect(ID_BITMAPBUTTON8,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&pp_stringFrame::OnEnglishLangBitmapButtonClick);
    Connect(ID_BITMAPBUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&pp_stringFrame::OnRussianLangBitmapButtonClick);
    Connect(ID_SLIDER2,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&pp_stringFrame::On_str_Slider_l_CmdSliderUpdated);
    Connect(ID_SLIDER6,wxEVT_SCROLL_TOP|wxEVT_SCROLL_BOTTOM|wxEVT_SCROLL_LINEUP|wxEVT_SCROLL_LINEDOWN|wxEVT_SCROLL_PAGEUP|wxEVT_SCROLL_PAGEDOWN|wxEVT_SCROLL_THUMBTRACK|wxEVT_SCROLL_THUMBRELEASE|wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&pp_stringFrame::On_str_Slider_NCmdScroll);
    Connect(ID_SLIDER6,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&pp_stringFrame::On_str_slider_NCmdSliderUpdated);
    Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&pp_stringFrame::On_str_TextCtrl_NTextEnter);
    Connect(ID_SLIDER4,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&pp_stringFrame::On_str_slider_pCmdSliderUpdated);
    Connect(ID_TEXTCTRL3,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&pp_stringFrame::On_str_TextCtrl_pTextEnter);
    Connect(ID_TEXTCTRL4,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&pp_stringFrame::On_str_TextCtrl_force_xTextEnter);
    Connect(ID_TEXTCTRL5,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&pp_stringFrame::On_str_TextCtrl_force_yTextEnter);
    Connect(ID_BITMAPBUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&pp_stringFrame::On_str_change_force_buttonClick);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&pp_stringFrame::On_str_Button_energy_graphicClick);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&pp_stringFrame::On_str_Button_harm_graphicClick);
    Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&pp_stringFrame::On_str_TextCtrl_lTextEnter);
    Connect(ID_SLIDER5,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&pp_stringFrame::On_dstr_slider_lCmdSliderUpdated);
    Connect(ID_TEXTCTRL6,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&pp_stringFrame::On_dstr_TextCtrl_lTextEnter);
    Connect(ID_SLIDER3,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&pp_stringFrame::On_dstr_slider_NCmdSliderUpdated);
    Connect(ID_TEXTCTRL7,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&pp_stringFrame::On_dstr_TextCtrl_NTextEnter);
    Connect(ID_SPINCTRL1,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&pp_stringFrame::On_dstr_SpinCtrl_w_nChange);
    Connect(ID_TEXTCTRL22,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&pp_stringFrame::On_dstr_TextCtrl_mTextEnter);
    Connect(ID_SPINCTRL2,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&pp_stringFrame::On_dstr_SpinCtrl_force_nChange);
    Connect(ID_TEXTCTRL8,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&pp_stringFrame::On_dstr_TextCtrl_force_yTextEnter);
    Connect(ID_BITMAPBUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&pp_stringFrame::On_dstr_BitmapButton_change_forceClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&pp_stringFrame::On_dstr_Button_energy_graphicClick);
    Connect(ID_SLIDER8,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&pp_stringFrame::On_harmc_Slider_wCmdSliderUpdated);
    Connect(ID_TEXTCTRL10,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&pp_stringFrame::On_harmc_TextCtrl_wTextEnter);
    Connect(ID_SLIDER10,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&pp_stringFrame::On_harmc_Slider_ACmdSliderUpdated);
    Connect(ID_TEXTCTRL11,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&pp_stringFrame::On_harmc_TextCtrl_ATextEnter);
    Connect(ID_SLIDER7,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&pp_stringFrame::On_harmc_Slider_pCmdSliderUpdated);
    Connect(ID_TEXTCTRL9,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&pp_stringFrame::On_harmc_TextCtrl_pTextEnter);
    Connect(ID_SLIDER9,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&pp_stringFrame::On_harmc_Slider_NCmdSliderUpdated);
    Connect(ID_TEXTCTRL12,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&pp_stringFrame::On_harmc_TextCtrl_NTextEnter);
    Connect(ID_SPINCTRL4,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&pp_stringFrame::On_hlc_SpinCtrl_harm_numChange);
    Connect(ID_SLIDER14,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&pp_stringFrame::On_hlc_Slider_lCmdSliderUpdated);
    Connect(ID_SLIDER17,wxEVT_SCROLL_TOP|wxEVT_SCROLL_BOTTOM|wxEVT_SCROLL_LINEUP|wxEVT_SCROLL_LINEDOWN|wxEVT_SCROLL_PAGEUP|wxEVT_SCROLL_PAGEDOWN|wxEVT_SCROLL_THUMBTRACK|wxEVT_SCROLL_THUMBRELEASE|wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&pp_stringFrame::On_hlc_Slider_force_yCmdScroll);
    Connect(ID_SLIDER17,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&pp_stringFrame::On_hlc_Slider_force_yCmdSliderUpdated);
    Connect(ID_TEXTCTRL21,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&pp_stringFrame::On_hlc_TextCtrl_force_yText);
    Connect(ID_TEXTCTRL21,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&pp_stringFrame::On_hlc_TextCtrl_force_yTextEnter);
    Connect(ID_TEXTCTRL18,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&pp_stringFrame::On_hlc_TextCtrl_lTextEnter);
    Connect(ID_SLIDER15,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&pp_stringFrame::On_hlc_Slider_pCmdSliderUpdated);
    Connect(ID_TEXTCTRL19,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&pp_stringFrame::On_hlc_TextCtrl_pTextEnter);
    Connect(ID_SLIDER16,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&pp_stringFrame::On_hlc_Slider_NCmdSliderUpdated);
    Connect(ID_TEXTCTRL20,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&pp_stringFrame::On_hlc_TextCtrl_NTextEnter);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&pp_stringFrame::OnButton1Click2);
    Connect(ID_SLIDER18,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&pp_stringFrame::On_hld_Slider_lCmdSliderUpdated);
    Connect(ID_TEXTCTRL23,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&pp_stringFrame::On_hld_TextCtrl_lTextEnter);
    Connect(ID_SPINCTRL3,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&pp_stringFrame::On_hld_SpinCtrl_w_nChange);
    Connect(ID_TEXTCTRL26,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&pp_stringFrame::On_hld_TextCtrl_mTextEnter);
    Connect(ID_SLIDER19,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&pp_stringFrame::On_hld_Slider_force_yCmdSliderUpdated);
    Connect(ID_TEXTCTRL24,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&pp_stringFrame::On_hld_TextCtrl_force_yTextEnter);
    Connect(ID_SLIDER20,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&pp_stringFrame::On_hld_Slider_NCmdSliderUpdated);
    Connect(ID_TEXTCTRL25,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&pp_stringFrame::On_hld_TextCtrl_NTextEnter);
    Connect(ID_SPINCTRL5,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&pp_stringFrame::On_hld_SpinCtrl_harm_numChange);
    Connect(ID_SLIDER21,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&pp_stringFrame::On_henv_Slider_wCmdSliderUpdated);
    Connect(ID_TEXTCTRL27,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&pp_stringFrame::On_henv_TextCtrl_wTextEnter);
    Connect(ID_SLIDER22,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&pp_stringFrame::On_henv_Slider_force_yCmdSliderUpdated);
    Connect(ID_TEXTCTRL28,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&pp_stringFrame::On_henv_TextCtrl_force_yTextEnter);
    Connect(ID_TEXTCTRL30,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&pp_stringFrame::On_henv_TextCtrl_pTextEnter);
    Connect(ID_TEXTCTRL31,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&pp_stringFrame::On_henv_TextCtrl_p2TextEnter);
    Connect(ID_SLIDER23,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&pp_stringFrame::On_henv_Slider_NCmdSliderUpdated);
    Connect(ID_TEXTCTRL29,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&pp_stringFrame::On_henv_TextCtrl_NTextEnter);
    Connect(ID_TEXTCTRL13,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&pp_stringFrame::On_harmd_TextCtrl_mTextEnter);
    Connect(ID_SLIDER11,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&pp_stringFrame::On_harmd_Slider_wCmdSliderUpdated);
    Connect(ID_TEXTCTRL15,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&pp_stringFrame::On_harmd_TextCtrl_wTextEnter);
    Connect(ID_SLIDER12,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&pp_stringFrame::On_harmd_Slider_ACmdSliderUpdated);
    Connect(ID_TEXTCTRL16,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&pp_stringFrame::On_harmd_TextCtrl_AText);
    Connect(ID_TEXTCTRL16,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&pp_stringFrame::On_harmd_TextCtrl_ATextEnter);
    Connect(ID_SLIDER13,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&pp_stringFrame::On_harmd_Slider_NCmdSliderUpdated);
    Connect(ID_TEXTCTRL14,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&pp_stringFrame::On_harmd_TextCtrl_hTextEnter);
    Connect(ID_TEXTCTRL17,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&pp_stringFrame::On_harmd_TextCtrl_NTextEnter);
    Connect(ID_BITMAPBUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&pp_stringFrame::OnBitmapButtonStartClick);
    Connect(ID_BITMAPBUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&pp_stringFrame::OnBitmapButtonStopClick);
    Connect(ID_BITMAPBUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&pp_stringFrame::OnBitmapButtonHomeClick);
    Connect(ID_SLIDER1,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&pp_stringFrame::OnSpeedSliderCmdSliderUpdated);
    Connect(ID_BITMAPBUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&pp_stringFrame::OnBitmapButtonRefreshClick);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&pp_stringFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&pp_stringFrame::OnAbout);
    Connect(ID_TIMER1,wxEVT_TIMER,(wxObjectEventFunction)&pp_stringFrame::OnRenderTimerTrigger);
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&pp_stringFrame::OnClose);
    Connect(wxEVT_KEY_UP,(wxObjectEventFunction)&pp_stringFrame::OnKeyUp);
    //*)

    Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&pp_stringFrame::OnString1);
    Connect(ID_MENUITEM2,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&pp_stringFrame::OnString2);
    Connect(ID_MENUITEM3,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&pp_stringFrame::OnString3);
    Connect(ID_MENUITEM4,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&pp_stringFrame::OnString4);
    Connect(ID_MENUITEM5,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&pp_stringFrame::OnString5);
    Connect(ID_MENUITEM6,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&pp_stringFrame::OnString6);
    Connect(ID_MENUITEM7,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&pp_stringFrame::OnString7);
    Connect(idMenuHelp,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&pp_stringFrame::OnHelp);

    Connect(ID_MENUITEM9,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&pp_stringFrame::OnChoiceRussian);
    Connect(ID_MENUITEM10,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&pp_stringFrame::OnChoiceEnglish);

    Connect(idMenuAA,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&pp_stringFrame::OnChangeAntiAliasing);

    _is_gl_init = false;
    _hlc_EnergyGraphicFrame = NULL;
    _dstr_EnergyGraphicFrame = NULL;
    _str_EnergyGraphicFrame = NULL;
    _str_HarmGraphicFrame = NULL;

    _str_l = 20, _str_N = 100, _str_p = 10, _str_force_x = 10, _str_force_y = 2, _str_sp_r = 0.05, _str_init = -1.0f;
    _dstr_l = 20, _dstr_w_n = 40, _dstr__m = 1, _dstr_force_n = 3, _dstr_force_y = 2, _dstr_N = 100;
    _harmc_w = 10, _harmc_A = 400, _harmc_p = 10, _harmc_N = 100, _harmc_sl = -10, _harmc_fl = 10, _harmc_sp_r = 0.02;
    _harmd_w = 10, _harmd_A = 40, _harmd_N = 100, _harmd_m = 1, _harmd_h = 2, _harmd_sl = -10, _harmd_fl = 10;
    _hlc_l = 20, _hlc_N = 100, _hlc_p = 10, _hlc_force_y = 2,  _hlc_harm_num = 1, _hlc_sp_r = 0.05;
    _hld_l = 20, _hld_N = 100, _hld_w_n = 10, _hld_m = 1, _hld_force_y = 2,  _hld_harm_num = 1;
    _henv_w = 10, _henv_N = 100, _henv_p = 10, _henv_p2 = 1, _henv_force_y = 2, _henv_sl = -20, _henv_fl = 20, _henv_sp_r = 0.05;

    menu_bar = MenuBar1;
    menu_item_11 = Menu4;

    SetLanguage(kRussian);
}

int Round(float a) {
    return (a - int(a)<0.5) ? int(a) : int(a)+1;
}

double RoundCut(double value) {
    return Round(value*1000)/1000.0;
}

int wxStringToDouble(wxString str, double & val) {
    if(str.ToDouble(&val))
        return 1;

    wxString tmp = str;

    tmp.Replace(wxT(","), wxT("."));
    if(tmp.ToDouble(&val))
        return 1;

    tmp.Replace(wxT("."), wxT(","));
    if(tmp.ToDouble(&val))
        return 1;

    return 0;
}

pp_stringFrame::~pp_stringFrame() {
    //(*Destroy(pp_stringFrame)
    //*)
}

void pp_stringFrame::OnQuit(wxCommandEvent& event) {
    Close();
}

void pp_stringFrame::OnAbout(wxCommandEvent& event) {
    wxString msg;

    switch(cur_lang_) {
    case kEnglish:
        msg = _("Creater by NSTU students from FAMCS, group ПМ-01:\nZubarev A.Y., Konev A.M., Ryahovskiy M.I.\n\nTutor: Baranov A.V., c.p.m.s, associate professor, department of general physics\n\n                           Novosibirsk, 2013г.");
        wxMessageBox(msg, _("About"));
        break;

    case kRussian:
        msg = _("Выполнили студенты 2-го курса НГТУ ФПМИ группы ПМ-01:\nЗубарев А.Ю., Конев А.М., Ряховский М.И.\n\nРуководитель: Баранов А.В., к. ф. м. н., \nдоцент кафедры общей физики\n\n                           Новосибирск, 2013г.");
        wxMessageBox(msg, _("О программе"));
        break;

    default:
        break;
    }
}

void pp_stringFrame::OnHelp(wxCommandEvent& event) {
#ifdef _WIN32
    WinExec("hh.exe data/help.chm",SW_SHOW);
#endif
}

void pp_stringFrame::OnClose(wxCloseEvent& event) {
    RenderTimer.Stop();

    if(_hlc_EnergyGraphicFrame)  _hlc_EnergyGraphicFrame->Destroy();
    if(_dstr_EnergyGraphicFrame) _dstr_EnergyGraphicFrame->Destroy();
    if(_str_EnergyGraphicFrame)  _str_EnergyGraphicFrame->Destroy();
    if(_str_HarmGraphicFrame)    _str_HarmGraphicFrame->Destroy();

    Destroy();
}

void pp_stringFrame::On_string_3dviewResize(wxSizeEvent& event) {
    pp_string_t->setContextSize(kString3dView, _string_3dview->GetSize().x, _string_3dview->GetSize().y);
    _string_3dview->Refresh();
}

void pp_stringFrame::On_string_3dviewLeftDown(wxMouseEvent& event) {
    pp_string_t->coordX = event.GetX();
    pp_string_t->coordY = event.GetY();

    if(event.RightIsDown() == true) {
        _string_3dview->SetFocus();

        float delta = 0.5f / (_string_3dview->GetSize().x/_string_3dview->GetSize().y);
        if(pp_string_t->jump==true) {
            pp_string_t->lastX = pp_string_t->coordX;
            pp_string_t->lastY = pp_string_t->coordY;
            pp_string_t->jump=false;
        }
        if(pp_string_t->coordX > pp_string_t->lastX && pp_string_t->rot < 180) {
            pp_string_t->rot = pp_string_t->rot + delta*(pp_string_t->coordX - pp_string_t->lastX);
            pp_string_t->lastX = pp_string_t->coordX;
        }
        if(pp_string_t->coordX < pp_string_t->lastX && pp_string_t->rot > 0) {
            pp_string_t->rot = pp_string_t->rot - delta*(pp_string_t->lastX - pp_string_t->coordX);
            pp_string_t->lastX = pp_string_t->coordX;
        }
        if(pp_string_t->rot > 180) pp_string_t->rot = 180;
        if(pp_string_t->rot < 0) pp_string_t->rot = 0;

        if(pp_string_t->coordY > pp_string_t->lastY && pp_string_t->tilt > -90) {
            pp_string_t->tilt = pp_string_t->tilt - delta*(pp_string_t->coordY - pp_string_t->lastY);
            pp_string_t->lastY = pp_string_t->coordY;
        }
        if(pp_string_t->coordY < pp_string_t->lastY && pp_string_t->tilt < 90) {
            pp_string_t->tilt = pp_string_t->tilt + delta*(pp_string_t->lastY - pp_string_t->coordY);
            pp_string_t->lastY = pp_string_t->coordY;

        }
        if(pp_string_t->tilt > 90) pp_string_t->tilt = 90;
        if(pp_string_t->tilt < -90) pp_string_t->tilt = -90;
    } else if(event.LeftIsDown() == true) {
        _string_3dview->SetFocus();

        if(pp_string_t->jump==true) {
            pp_string_t->lastX = pp_string_t->coordX;
            pp_string_t->lastY = pp_string_t->coordY;
            pp_string_t->jump=false;
        }
        if(event.ControlDown()) {
            switch(pp_string_t->getCurStringType()) {
            case _str:
                if(!pp_string_t->cube_move) {
                    if(SelectLine::intersect_triangle_line(vec3(_str_force_x-0.1,_str_force_y-0.1,0),
                                                           vec3(_str_force_x+0.1,_str_force_y-0.1,0),
                                                           vec3(_str_force_x+0.1,_str_force_y+0.1,0),
                                                           vec3(0,0,1),
                                                           pp_string_t->p1_, pp_string_t->p2_, pp_string_t->pc_) ||
                            SelectLine::intersect_triangle_line(vec3(_str_force_x-0.1,_str_force_y-0.1,0),
                                    vec3(_str_force_x-0.1,_str_force_y+0.1,0),
                                    vec3(_str_force_x+0.1,_str_force_y+0.1,0),
                                    vec3(0,0,-1),
                                    pp_string_t->p1_, pp_string_t->p2_, pp_string_t->pc_))
                        pp_string_t->cube_move = true;
                }
                if(pp_string_t->cube_move) {
                    if(!SelectLine::intersect_triangle_line(vec3(-100,-100,0),vec3(-100,100,0),vec3(100,100,0),vec3(0,0,-1),pp_string_t->p1_, pp_string_t->p2_, pp_string_t->pc_))
                        SelectLine::intersect_triangle_line(vec3(100,100,0),vec3(-100,-100,0),vec3(100,-100,0),vec3(0,0,1), pp_string_t->p1_, pp_string_t->p2_, pp_string_t->pc_);

                    float max_deviation_x = _str_l-1;
                    float min_deviation_x = 1.0f;
                    float max_deviation_y = _str_l / 2.0f;
                    float min_deviation_y = 0.0f;

                    if(pp_string_t->pc_.x > max_deviation_x) pp_string_t->pc_.x = max_deviation_x;
                    if(pp_string_t->pc_.x < min_deviation_x) pp_string_t->pc_.x = min_deviation_x;
                    if(pp_string_t->pc_.y > max_deviation_y) pp_string_t->pc_.y = max_deviation_y;
                    if(pp_string_t->pc_.y < min_deviation_y) pp_string_t->pc_.y = min_deviation_y;

                    _str_force_x = pp_string_t->pc_.x;
                    _str_force_y = pp_string_t->pc_.y;
                    pp_string_t->lastX = pp_string_t->coordX;
                    pp_string_t->lastY = pp_string_t->coordY;

                    if(!pp_string_t->is_pause) {
                        pp_string_t->is_pause = !pp_string_t->is_pause;
                        BitmapButtonStart->SetBitmapLabel(BitmapButtonStart->GetBitmapSelected());
                    }

                    _str_init = -1.0f;
                    pp_string_t->initString(_str, 7, _str_l, _str_N, _str_p, _str_force_x, _str_force_y, _str_sp_r, _str_init);

                    wxString tmp;
                    tmp << RoundCut(_str_force_x);
                    _str_TextCtrl_force_x->SetValue(tmp);

                    tmp.clear();
                    tmp << RoundCut(_str_force_y);
                    _str_TextCtrl_force_y->SetValue(tmp);
                }
                break;

            case _dstr:
                if(!pp_string_t->cube_move) {
                    float n_w_n = (_dstr_l/(_dstr_w_n+1));

                    for(int i=1; i<=_dstr_w_n; i++) {
                        if(SelectLine::intersect_triangle_line(vec3(i*n_w_n-0.1,0-0.1,0),
                                                               vec3(i*n_w_n+0.1,0-0.1,0),
                                                               vec3(i*n_w_n+0.1,0+0.1,0),
                                                               vec3(0,0,1),
                                                               pp_string_t->p1_, pp_string_t->p2_, pp_string_t->pc_) ||
                                SelectLine::intersect_triangle_line(vec3(i*n_w_n-0.1,0-0.1,0),
                                        vec3(i*n_w_n-0.1,0+0.1,0),
                                        vec3(i*n_w_n+0.1,0+0.1,0),
                                        vec3(0,0,-1),
                                        pp_string_t->p1_, pp_string_t->p2_, pp_string_t->pc_)) {
                            pp_string_t->cube_move = true;
                            _dstr_force_n = i;
                            break;
                        }
                    }
                }
                if(pp_string_t->cube_move) {
                    if(!SelectLine::intersect_triangle_line(vec3(-100,-100,0),vec3(-100,100,0),vec3(100,100,0),vec3(0,0,-1), pp_string_t->p1_, pp_string_t->p2_, pp_string_t->pc_))
                        SelectLine::intersect_triangle_line(vec3(100,100,0),vec3(-100,-100,0),vec3(100,-100,0),vec3(0,0,1), pp_string_t->p1_, pp_string_t->p2_, pp_string_t->pc_);

                    float max_deviation = _dstr_l / 2.0f;
                    float min_deviation = 0.0f;
                    if(pp_string_t->pc_.y > max_deviation) pp_string_t->pc_.y = max_deviation;
                    if(pp_string_t->pc_.y < min_deviation) pp_string_t->pc_.y = min_deviation;

                    //_dstr_force_n = 3;
                    _dstr_force_y = pp_string_t->pc_.y;
                    pp_string_t->lastX = pp_string_t->coordX;
                    pp_string_t->lastY = pp_string_t->coordY;
                    pp_string_t->initString(_dstr, 6, _dstr_l, _dstr_w_n, _dstr__m, _dstr_force_n, _dstr_force_y, _dstr_N);


                    _dstr_SpinCtrl_force_n->SetValue(_dstr_force_n);

                    wxString tmp;
                    tmp << RoundCut(_dstr_force_y);
                    _dstr_TextCtrl_force_y->SetValue(tmp);
                }
                break;

            default:
                break;
            }

        } else {
            pp_string_t->transX += (pp_string_t->coordX - pp_string_t->lastX)/100.0;
            pp_string_t->transY += -(pp_string_t->coordY - pp_string_t->lastY)/100.0;
            pp_string_t->lastX = pp_string_t->coordX;
            pp_string_t->lastY = pp_string_t->coordY;
        }
    } else pp_string_t->jump=true;
}

void pp_stringFrame::On_string_3dviewMouseWheel(wxMouseEvent& event) {
    pp_string_t->zoom += event.GetWheelRotation()/1000.0;
    if(pp_string_t->zoom > 5.0) pp_string_t->zoom = 5.0;
    if(pp_string_t->zoom < 0.2) pp_string_t->zoom = 0.2;
}

void pp_stringFrame::OnBitmapButtonStartClick(wxCommandEvent& event) {
    pp_string_t->is_pause = !pp_string_t->is_pause;

    if(pp_string_t->getCurStringType() == _str && _str_init == -1.0f)
        OnBitmapButtonRefreshClick(event);

    if(pp_string_t->is_pause)
        BitmapButtonStart->SetBitmapLabel(BitmapButtonStart->GetBitmapSelected());
    else
        BitmapButtonStart->SetBitmapLabel(BitmapButtonStart->GetBitmapDisabled());
}

void pp_stringFrame::OnBitmapButtonRefreshClick(wxCommandEvent& event) {
    wxString status;
    status <<  _("Пожалуйста подождите. Происходит инициализация.");
    StatusBar1->SetStatusText(status);

    wxSpinEvent _tmp_spin_event;

    switch(pp_string_t->getCurStringType()) {
    case _str:
        _str_init = 1.0f;
        On_str_TextCtrl_lTextEnter(event);
        On_str_TextCtrl_NTextEnter(event);
        On_str_TextCtrl_pTextEnter(event);
        On_str_TextCtrl_force_xTextEnter(event);
        On_str_TextCtrl_force_yTextEnter(event);
        pp_string_t->initString(_str, 7, _str_l, _str_N, _str_p, _str_force_x, _str_force_y, _str_sp_r, _str_init);
        break;

    case _dstr:
        On_dstr_TextCtrl_lTextEnter(event);
        On_dstr_TextCtrl_NTextEnter(event);
        On_dstr_SpinCtrl_w_nChange(_tmp_spin_event);
        On_dstr_SpinCtrl_force_nChange(_tmp_spin_event);
        On_dstr_TextCtrl_force_yTextEnter(event);
        On_dstr_TextCtrl_mTextEnter(event);
        pp_string_t->initString(_dstr, 6, _dstr_l, _dstr_w_n, _dstr__m, _dstr_force_n, _dstr_force_y, _dstr_N);
        break;

    case _harmc:
        On_harmc_TextCtrl_pTextEnter(event);
        On_harmc_TextCtrl_wTextEnter(event);
        On_harmc_TextCtrl_ATextEnter(event);
        On_harmc_TextCtrl_NTextEnter(event);
        pp_string_t->initString(_harmc, 7, _harmc_w, _harmc_A, _harmc_p, _harmc_N, _harmc_sl, _harmc_fl, _harmc_sp_r);
        break;

    case _harmd:
        On_harmd_TextCtrl_ATextEnter(event);
        On_harmd_TextCtrl_hTextEnter(event);
        On_harmd_TextCtrl_mTextEnter(event);
        On_harmd_TextCtrl_NTextEnter(event);
        On_harmd_TextCtrl_wTextEnter(event);
        pp_string_t->initString(_harmd, 7, _harmd_w, _harmd_A, _harmd_N, _harmd_m, _harmd_h, _harmd_sl, _harmd_fl);
        break;

    case _hlc:
        On_hlc_TextCtrl_force_yTextEnter(event);
        On_hlc_TextCtrl_lTextEnter(event);
        On_hlc_TextCtrl_NTextEnter(event);
        On_hlc_TextCtrl_pTextEnter(event);
        On_hlc_SpinCtrl_harm_numChange(_tmp_spin_event);
        pp_string_t->initString(_hlc, 6, _hlc_l, _hlc_N, _hlc_p, _hlc_force_y, _hlc_sp_r, _hlc_harm_num);
        break;

    case _hld:
        On_hld_TextCtrl_force_yTextEnter(event);
        On_hld_TextCtrl_lTextEnter(event);
        On_hld_TextCtrl_mTextEnter(event);
        On_hld_TextCtrl_NTextEnter(event);
        On_hld_SpinCtrl_w_nChange(_tmp_spin_event);
        On_hld_SpinCtrl_harm_numChange(_tmp_spin_event);
        pp_string_t->initString(_hld, 6, _hld_l, _hld_N, _hld_w_n, _hld_m, _hld_force_y, _hld_harm_num);
        break;

    case _henv:
        On_henv_TextCtrl_pTextEnter(event);
        On_henv_TextCtrl_p2TextEnter(event);
        On_henv_TextCtrl_wTextEnter(event);
        On_henv_TextCtrl_NTextEnter(event);
        On_henv_TextCtrl_force_yTextEnter(event);
        pp_string_t->initString(_henv, 8, _henv_w, _henv_N, _henv_p, _henv_p2, _henv_force_y, _henv_sl, _henv_fl, _henv_sp_r);
        break;

    default:
        break;
    }

    status.clear();
    status << _("");
    StatusBar1->SetStatusText(status);
}

float TextCtrlEnter(wxTextCtrl* text, float min, float max) {
    wxString tmp;
    tmp = text->GetValue();

    float param = 0.0f;

    double tmp_float;
    if(wxStringToDouble(tmp,tmp_float)) {
        float eps = 0.0001;
        if(tmp_float > max+eps) {
            tmp_float = max;
            wxString tmp_str;
            tmp_str << RoundCut(max);
            text->SetValue(tmp_str);
            wxMessageBox(_("Неверный параметр!\nЗначение вне диапазона."),_("Ошибка"));
        } else if(tmp_float < min-eps) {
            tmp_float = min;
            wxString tmp_str;
            tmp_str << RoundCut(min);
            text->SetValue(tmp_str);
            wxMessageBox(_("Неверный параметр!\nЗначение вне диапазона."),_("Ошибка"));
        }

        param = tmp_float;
    } else {
        param = min;
        wxString tmp_str;
        tmp_str << RoundCut(min);
        text->SetValue(tmp_str);
        wxMessageBox(_("Неверный параметр!\nЗначение не корректно."),_("Ошибка"));
    }

    return param;
}

float TextCtrlEnterWithSliderRefreshing(wxTextCtrl* text, wxSlider* slider, float div) {
    wxString tmp;
    tmp = text->GetValue();

    float max = slider->GetMax()/div;
    float min = slider->GetMin()/div;

    float param = 0.0f;

    double tmp_float;
    if(wxStringToDouble(tmp,tmp_float)) {
        float eps = 0.0001;
        if(tmp_float > max+eps) {
            tmp_float = max;
            wxString tmp_str;
            tmp_str << RoundCut(max);
            text->SetValue(tmp_str);
            wxMessageBox(_("Неверный параметр!\nЗначение вне диапазона."),_("Ошибка"));
        } else if(tmp_float < min-eps) {
            tmp_float = min;
            wxString tmp_str;
            tmp_str << RoundCut(min);
            text->SetValue(tmp_str);
            wxMessageBox(_("Неверный параметр!\nЗначение вне диапазона."),_("Ошибка"));
        }

        param = tmp_float;
        slider->SetValue(int(tmp_float*div));
    } else {
        param = min;
        wxString tmp_str;
        tmp_str << RoundCut(min);
        text->SetValue(tmp_str);
        slider->SetValue(int(min*div));
        wxMessageBox(_("Неверный параметр!\nЗначение не корректно."),_("Ошибка"));
    }
    return param;
}

float SliderUpdateWithTextCtrlRefreshing(wxTextCtrl* text, wxSlider* slider, float div) {
    float param = slider->GetValue()/div;

    wxString tmp;
    tmp << RoundCut(param);
    text->SetValue(tmp);

    return param;
}

void pp_stringFrame::On_str_Slider_l_CmdSliderUpdated(wxScrollEvent& event) {
    _str_l = SliderUpdateWithTextCtrlRefreshing(_str_TextCtrl_l,_str_Slider_l,10.0f);
}

void pp_stringFrame::On_str_TextCtrl_lTextEnter(wxCommandEvent& event) {
    _str_l = TextCtrlEnterWithSliderRefreshing(_str_TextCtrl_l,_str_Slider_l,10.0f);
}

void pp_stringFrame::On_str_slider_NCmdSliderUpdated(wxScrollEvent& event) {
    _str_N = SliderUpdateWithTextCtrlRefreshing(_str_TextCtrl_N,_str_Slider_N,10.0f);
}

void pp_stringFrame::On_str_TextCtrl_NTextEnter(wxCommandEvent& event) {
    _str_N = TextCtrlEnterWithSliderRefreshing(_str_TextCtrl_N,_str_Slider_N,10.0f);
}

void pp_stringFrame::On_str_slider_pCmdSliderUpdated(wxScrollEvent& event) {
    _str_p = SliderUpdateWithTextCtrlRefreshing(_str_TextCtrl_p,_str_slider_p,10.0f);
}

void pp_stringFrame::On_str_TextCtrl_pTextEnter(wxCommandEvent& event) {
    _str_p = TextCtrlEnterWithSliderRefreshing(_str_TextCtrl_p,_str_slider_p,10.0f);
}

void pp_stringFrame::On_str_TextCtrl_force_xTextEnter(wxCommandEvent& event) {
    _str_force_x = TextCtrlEnter(_str_TextCtrl_force_x,1,_str_l-1);
}

void pp_stringFrame::On_str_TextCtrl_force_yTextEnter(wxCommandEvent& event) {

    _str_force_y = TextCtrlEnter(_str_TextCtrl_force_y,0.0,_str_l/2.0f);
}

void pp_stringFrame::On_str_change_force_buttonClick(wxCommandEvent& event) {
    _str_init = -1.0f;
    pp_string_t->is_pause = true;
    _string_3dview->SetFocus();
    BitmapButtonStart->SetBitmapLabel(BitmapButtonStart->GetBitmapSelected());
    pp_string_t->initString(_str, 7, _str_l, _str_N, _str_p, _str_force_x, _str_force_y, _str_sp_r, _str_init);
}

void pp_stringFrame::OnSpeedSliderCmdSliderUpdated(wxScrollEvent& event) {
    pp_string_t->exp_speed = SpeedSlider->GetValue()/100.0;
}

void pp_stringFrame::OnBitmapButtonHomeClick(wxCommandEvent& event) {
    switch(pp_string_t->getCurStringType()) {
    case _str:
    case _hlc:
        pp_string_t->transX = -pp_string_t->getStringLength()/2.0f;
        break;

    case _dstr:
        pp_string_t->transX = -(pp_string_t->getStringLength()+0.5f)/2.0f;
        break;

    case _hld:
        pp_string_t->transX = -(pp_string_t->getStringLength()+2)/2.0f;
        break;

    default:
        pp_string_t->transX = 0;
        break;
    }
    pp_string_t->transY = 0.0;
    pp_string_t->rot = 90.0;
    pp_string_t->tilt = -15.0;
    pp_string_t->zoom = 0.5;
}

void pp_stringFrame::SetPause(wxCommandEvent& event) {
    pp_string_t->is_pause = true;
    BitmapButtonStart->SetBitmapLabel(BitmapButtonStart->GetBitmapSelected());
    OnBitmapButtonRefreshClick(event);
}

void pp_stringFrame::OnBitmapButtonStopClick(wxCommandEvent& event) {
    SetPause(event);
}

void pp_stringFrame::On_dstr_TextCtrl_lTextEnter(wxCommandEvent& event) {
    _dstr_l = TextCtrlEnterWithSliderRefreshing(_dstr_TextCtrl_l,_dstr_slider_l,10.0f);
}

void pp_stringFrame::On_dstr_slider_lCmdSliderUpdated(wxScrollEvent& event) {
    _dstr_l = SliderUpdateWithTextCtrlRefreshing(_dstr_TextCtrl_l,_dstr_slider_l,10.0f);
}

void pp_stringFrame::On_dstr_slider_NCmdSliderUpdated(wxScrollEvent& event) {
    _dstr_N = SliderUpdateWithTextCtrlRefreshing(_dstr_TextCtrl_N,_dstr_slider_N,10.0f);
}

void pp_stringFrame::On_dstr_TextCtrl_NTextEnter(wxCommandEvent& event) {
    _dstr_N = TextCtrlEnterWithSliderRefreshing(_dstr_TextCtrl_N,_dstr_slider_N,10.0f);
}

void pp_stringFrame::On_dstr_SpinCtrl_w_nChange(wxSpinEvent& event) {
    _dstr_w_n = _dstr_SpinCtrl_w_n->GetValue();
}

void pp_stringFrame::On_dstr_SpinCtrl_force_nChange(wxSpinEvent& event) {
    _dstr_force_n = _dstr_SpinCtrl_force_n->GetValue();
}

void pp_stringFrame::On_dstr_TextCtrl_force_yTextEnter(wxCommandEvent& event) {
    _dstr_force_y = TextCtrlEnter(_dstr_TextCtrl_force_y,0.0,_dstr_l/2.0f);
}

void pp_stringFrame::On_dstr_BitmapButton_change_forceClick(wxCommandEvent& event) {
    pp_string_t->cube_move = false;
    pp_string_t->is_pause = true;
    _string_3dview->SetFocus();
    BitmapButtonStart->SetBitmapLabel(BitmapButtonStart->GetBitmapSelected());
    pp_string_t->initString(_dstr, 6, _dstr_l, _dstr_w_n, _dstr__m, _dstr_force_n, 0.0, _dstr_N);
}

void pp_stringFrame::On_harmc_Slider_pCmdSliderUpdated(wxScrollEvent& event) {
    _harmc_p = SliderUpdateWithTextCtrlRefreshing(_harmc_TextCtrl_p,_harmc_Slider_p,10.0f);
}

void pp_stringFrame::On_harmc_TextCtrl_pTextEnter(wxCommandEvent& event) {
    _harmc_p = TextCtrlEnterWithSliderRefreshing(_harmc_TextCtrl_p,_harmc_Slider_p,10.0f);
}

void pp_stringFrame::On_harmc_Slider_wCmdSliderUpdated(wxScrollEvent& event) {
    _harmc_w = SliderUpdateWithTextCtrlRefreshing(_harmc_TextCtrl_w,_harmc_Slider_w,10.0f);
}

void pp_stringFrame::On_harmc_TextCtrl_wTextEnter(wxCommandEvent& event) {
    _harmc_w = TextCtrlEnterWithSliderRefreshing(_harmc_TextCtrl_w,_harmc_Slider_w,10.0f);
}

void pp_stringFrame::On_harmc_TextCtrl_ATextEnter(wxCommandEvent& event) {
    _harmc_A = TextCtrlEnterWithSliderRefreshing(_harmc_TextCtrl_A,_harmc_Slider_A,1.0f);
}

void pp_stringFrame::On_harmc_Slider_ACmdSliderUpdated(wxScrollEvent& event) {
    _harmc_A = SliderUpdateWithTextCtrlRefreshing(_harmc_TextCtrl_A,_harmc_Slider_A,1.0f);
}

void pp_stringFrame::On_harmc_TextCtrl_NTextEnter(wxCommandEvent& event) {
    _harmc_N = TextCtrlEnterWithSliderRefreshing(_harmc_TextCtrl_N,_harmc_Slider_N,10.0f);
}

void pp_stringFrame::On_harmc_Slider_NCmdSliderUpdated(wxScrollEvent& event) {
    _harmc_N = SliderUpdateWithTextCtrlRefreshing(_harmc_TextCtrl_N,_harmc_Slider_N,10.0f);
}

void pp_stringFrame::On_harmd_Slider_wCmdSliderUpdated(wxScrollEvent& event) {
    _harmd_w = SliderUpdateWithTextCtrlRefreshing(_harmd_TextCtrl_w,_harmd_Slider_w,10.0f);
}

void pp_stringFrame::On_harmd_TextCtrl_wTextEnter(wxCommandEvent& event) {
    _harmd_w = TextCtrlEnterWithSliderRefreshing(_harmd_TextCtrl_w,_harmd_Slider_w,10.0f);
}

void pp_stringFrame::On_harmd_Slider_ACmdSliderUpdated(wxScrollEvent& event) {
    _harmd_A = SliderUpdateWithTextCtrlRefreshing(_harmd_TextCtrl_A,_harmd_Slider_A,1.0f);
}

void pp_stringFrame::On_harmd_TextCtrl_ATextEnter(wxCommandEvent& event) {
    _harmd_A = TextCtrlEnterWithSliderRefreshing(_harmd_TextCtrl_A,_harmd_Slider_A,1.0f);
}

void pp_stringFrame::On_harmd_Slider_NCmdSliderUpdated(wxScrollEvent& event) {
    _harmd_N = SliderUpdateWithTextCtrlRefreshing(_harmd_TextCtrl_N,_harmd_Slider_N,10.0f);
}

void pp_stringFrame::On_harmd_TextCtrl_NTextEnter(wxCommandEvent& event) {
    _harmd_N = TextCtrlEnterWithSliderRefreshing(_harmd_TextCtrl_N,_harmd_Slider_N,10.0f);
}

void pp_stringFrame::On_harmd_TextCtrl_mTextEnter(wxCommandEvent& event) {
    _harmd_m = TextCtrlEnter(_harmd_TextCtrl_m,0.01,100);
}

void pp_stringFrame::On_harmd_TextCtrl_hTextEnter(wxCommandEvent& event) {
    _harmd_h = TextCtrlEnter(_harmd_TextCtrl_h,0.01,1000);
}

void pp_stringFrame::On_hlc_Slider_lCmdSliderUpdated(wxScrollEvent& event) {
    _hlc_l = SliderUpdateWithTextCtrlRefreshing(_hlc_TextCtrl_l,_hlc_Slider_l,10.0f);
}

void pp_stringFrame::On_hlc_TextCtrl_lTextEnter(wxCommandEvent& event) {
    _hlc_l = TextCtrlEnterWithSliderRefreshing(_hlc_TextCtrl_l,_hlc_Slider_l,10.0f);
}

void pp_stringFrame::On_hlc_Slider_pCmdSliderUpdated(wxScrollEvent& event) {
    _hlc_p = SliderUpdateWithTextCtrlRefreshing(_hlc_TextCtrl_p,_hlc_Slider_p,10.0f);
}

void pp_stringFrame::On_hlc_TextCtrl_pTextEnter(wxCommandEvent& event) {
    _hlc_p = TextCtrlEnterWithSliderRefreshing(_hlc_TextCtrl_p,_hlc_Slider_p,10.0f);
}

void pp_stringFrame::On_hlc_Slider_force_yCmdSliderUpdated(wxScrollEvent& event) {
    _hlc_force_y = SliderUpdateWithTextCtrlRefreshing(_hlc_TextCtrl_force_y,_hlc_Slider_force_y,1.0f);
}

void pp_stringFrame::On_hlc_TextCtrl_force_yTextEnter(wxCommandEvent& event) {
    _hlc_force_y = TextCtrlEnterWithSliderRefreshing(_hlc_TextCtrl_force_y,_hlc_Slider_force_y,1.0f);
}

void pp_stringFrame::On_hlc_Slider_NCmdSliderUpdated(wxScrollEvent& event) {
    _hlc_N = SliderUpdateWithTextCtrlRefreshing(_hlc_TextCtrl_N,_hlc_Slider_N,10.0f);
}

void pp_stringFrame::On_hlc_TextCtrl_NTextEnter(wxCommandEvent& event) {
    _hlc_N = TextCtrlEnterWithSliderRefreshing(_hlc_TextCtrl_N,_hlc_Slider_N,10.0f);
}

void pp_stringFrame::On_dstr_TextCtrl_mTextEnter(wxCommandEvent& event) {
    _dstr__m = TextCtrlEnter(_dstr_TextCtrl_m,0.01,100);
}

void pp_stringFrame::On_hld_Slider_lCmdSliderUpdated(wxScrollEvent& event) {
    _hld_l = SliderUpdateWithTextCtrlRefreshing(_hld_TextCtrl_l,_hld_Slider_l,10.0f);
}

void pp_stringFrame::On_hld_TextCtrl_lTextEnter(wxCommandEvent& event) {
    _hld_l = TextCtrlEnterWithSliderRefreshing(_hld_TextCtrl_l,_hld_Slider_l,10.0f);
}

void pp_stringFrame::On_hld_Slider_force_yCmdSliderUpdated(wxScrollEvent& event) {
    _hld_force_y = SliderUpdateWithTextCtrlRefreshing(_hld_TextCtrl_force_y,_hld_Slider_force_y,1.0f);
}

void pp_stringFrame::On_hld_TextCtrl_force_yTextEnter(wxCommandEvent& event) {
    _hld_force_y = TextCtrlEnterWithSliderRefreshing(_hld_TextCtrl_force_y,_hld_Slider_force_y,1.0f);
}

void pp_stringFrame::On_hld_Slider_NCmdSliderUpdated(wxScrollEvent& event) {
    _hld_N = SliderUpdateWithTextCtrlRefreshing(_hld_TextCtrl_N,_hld_Slider_N,10.0f);
}

void pp_stringFrame::On_hld_TextCtrl_NTextEnter(wxCommandEvent& event) {
    _hld_N = TextCtrlEnterWithSliderRefreshing(_hld_TextCtrl_N,_hld_Slider_N,10.0f);
}

void pp_stringFrame::On_hld_SpinCtrl_w_nChange(wxSpinEvent& event) {
    _hld_w_n = _hld_SpinCtrl_w_n->GetValue();
}

void pp_stringFrame::On_hld_TextCtrl_mTextEnter(wxCommandEvent& event) {
    _hld_m = TextCtrlEnter(_hld_TextCtrl_m,0.01,100);
}

void pp_stringFrame::On_hlc_SpinCtrl_harm_numChange(wxSpinEvent& event) {
    _hlc_harm_num = _hlc_SpinCtrl_harm_num->GetValue();
}

void pp_stringFrame::On_hld_SpinCtrl_harm_numChange(wxSpinEvent& event) {
    _hld_harm_num = _hld_SpinCtrl_harm_num->GetValue();
}

void pp_stringFrame::On_henv_TextCtrl_pTextEnter(wxCommandEvent& event) {
    _henv_p = TextCtrlEnter(_henv_TextCtrl_p,0.01,1000);
}

void pp_stringFrame::On_henv_TextCtrl_p2TextEnter(wxCommandEvent& event) {
    _henv_p2 = TextCtrlEnter(_henv_TextCtrl_p2,0.01,1000);
}

void pp_stringFrame::On_henv_Slider_wCmdSliderUpdated(wxScrollEvent& event) {
    _henv_w = SliderUpdateWithTextCtrlRefreshing(_henv_TextCtrl_w,_henv_Slider_w,10.0f);
}

void pp_stringFrame::On_henv_TextCtrl_wTextEnter(wxCommandEvent& event) {
    _henv_w = TextCtrlEnterWithSliderRefreshing(_henv_TextCtrl_w,_henv_Slider_w,10.0f);
}

void pp_stringFrame::On_henv_Slider_force_yCmdSliderUpdated(wxScrollEvent& event) {
    _henv_force_y = SliderUpdateWithTextCtrlRefreshing(_henv_TextCtrl_force_y,_henv_Slider_force_y,10.0f);
}

void pp_stringFrame::On_henv_TextCtrl_force_yTextEnter(wxCommandEvent& event) {
    _henv_force_y = TextCtrlEnterWithSliderRefreshing(_henv_TextCtrl_force_y,_henv_Slider_force_y,10.0f);
}

void pp_stringFrame::On_henv_Slider_NCmdSliderUpdated(wxScrollEvent& event) {
    _henv_N = SliderUpdateWithTextCtrlRefreshing(_henv_TextCtrl_N,_henv_Slider_N,10.0f);
}

void pp_stringFrame::On_henv_TextCtrl_NTextEnter(wxCommandEvent& event) {
    _henv_N = TextCtrlEnterWithSliderRefreshing(_henv_TextCtrl_N,_henv_Slider_N,10.0f);
}

void pp_stringFrame::OnButton1Click2(wxCommandEvent& event) {
    if(!_hlc_EnergyGraphicFrame) {
        _hlc_EnergyGraphicFrame = new _hlc_EnergyGraphic(this);
        _hlc_EnergyGraphicFrame->is_gl_init = false;
        _hlc_EnergyGraphicFrame->SetLanguage(cur_lang_);
        _hlc_EnergyGraphicFrame->Show();
    }
}

void pp_stringFrame::On_dstr_Button_energy_graphicClick(wxCommandEvent& event) {
    if(!_dstr_EnergyGraphicFrame) {
        _dstr_EnergyGraphicFrame = new _dstr_EnergyGraphic(this);
        _dstr_EnergyGraphicFrame->is_gl_init = false;
        _dstr_EnergyGraphicFrame->SetLanguage(cur_lang_);
        _dstr_EnergyGraphicFrame->Show();
    }

}

void pp_stringFrame::On_str_Button_energy_graphicClick(wxCommandEvent& event) {
    if(!_str_EnergyGraphicFrame) {
        _str_EnergyGraphicFrame = new _str_EnergyGraphic(this);
        _str_EnergyGraphicFrame->is_gl_init = false;
        _str_EnergyGraphicFrame->SetLanguage(cur_lang_);
        _str_EnergyGraphicFrame->Show();
    }
}

void pp_stringFrame::On_str_Button_harm_graphicClick(wxCommandEvent& event) {
    if(!_str_HarmGraphicFrame) {
        pp_string_t->cur_str_harm_graphic_num = 1;
        _str_HarmGraphicFrame = new _str_HarmGraphic(this);
        _str_HarmGraphicFrame->is_gl5_init = false;
        _str_HarmGraphicFrame->SetLanguage(cur_lang_);
        _str_HarmGraphicFrame->Show();
    }
}

void _hlc_EnergyGraphic::OnClose(wxCloseEvent& event) {
    RenderTimer.Stop();

    _hlc_EnergyGraphicFrame = NULL;

    Destroy();
}

void _dstr_EnergyGraphic::OnClose(wxCloseEvent& event) {
    RenderTimer.Stop();

    _dstr_EnergyGraphicFrame = NULL;

    Destroy();
}

void _str_EnergyGraphic::OnClose(wxCloseEvent& event) {
    RenderTimer.Stop();

    _str_EnergyGraphicFrame = NULL;

    Destroy();
}

void _str_HarmGraphic::OnClose(wxCloseEvent& event) {
    RenderTimer.Stop();

    _str_HarmGraphicFrame = NULL;

    Destroy();
}

void _dstr_EnergyGraphic::On_dstr_SpinCtrl_graphic_wheit_numChange(wxSpinEvent& event) {
    pp_string_t->cur_dstr_graphic_wheight = _dstr_SpinCtrl_graphic_wheit_num->GetValue();
    if(pp_string_t->cur_dstr_graphic_wheight >= pp_string_t->test_dstr.draw_number) {
        pp_string_t->cur_dstr_graphic_wheight = pp_string_t->test_dstr.draw_number-1;
        _dstr_SpinCtrl_graphic_wheit_num->SetValue(pp_string_t->test_dstr.draw_number-1);
    }
}

void pp_stringFrame::OnRenderTimerTrigger(wxTimerEvent& event) {
    //_string_3dview->Update();
    _string_3dview->Refresh();
}

void pp_stringFrame::On_string_3dviewPaint(wxPaintEvent& event) {
    wxPaintDC dc(_string_3dview);
    _string_3dview->SetCurrent();

    if(!_is_gl_init) {
        _string_3dview->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
        pp_string_t->setContextSize(kString3dView, _string_3dview->GetSize().x, _string_3dview->GetSize().y);
        pp_string_t->initContext(kString3dView);
        pp_string_t->enableAntiAliasing(false);
        _is_gl_init = true;
    }

    pp_string_t->render(kString3dView);

    glFlush();
    _string_3dview->SwapBuffers();
    glFinish();
}

void pp_stringFrame::OnKeyUp(wxKeyEvent& event) {
    //pp_string_t->cube_move = false;
}

void pp_stringFrame::On_harmd_TextCtrl_AText(wxCommandEvent& event) {
}

void pp_stringFrame::On_hlc_Slider_force_yCmdScroll(wxScrollEvent& event) {
}

void pp_stringFrame::On_hlc_TextCtrl_force_yText(wxCommandEvent& event) {
}

void pp_stringFrame::On_str_Slider_NCmdScroll(wxScrollEvent& event) {
}

void pp_stringFrame::OnEnglishLangBitmapButtonClick(wxCommandEvent& event) {
    SetLanguage(kEnglish);
}

void pp_stringFrame::OnRussianLangBitmapButtonClick(wxCommandEvent& event) {
    SetLanguage(kRussian);
}
