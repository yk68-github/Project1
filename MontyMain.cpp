/***************************************************************
 * Name:      MontyMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Y ()
 * Created:   2024-04-27
 * Copyright: Y ()
 * License:
 **************************************************************/

#include "MontyMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(MontyFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(MontyFrame)
const long MontyFrame::ID_STATICTEXT1 = wxNewId();
const long MontyFrame::ID_SPINCTRL1 = wxNewId();
const long MontyFrame::ID_STATICTEXT2 = wxNewId();
const long MontyFrame::ID_SPINCTRL2 = wxNewId();
const long MontyFrame::ID_STATICTEXT3 = wxNewId();
const long MontyFrame::ID_SPINCTRL3 = wxNewId();
const long MontyFrame::ID_GAUGE1 = wxNewId();
const long MontyFrame::ID_STATICTEXT4 = wxNewId();
const long MontyFrame::ID_STATICTEXT5 = wxNewId();
const long MontyFrame::ID_BUTTON1 = wxNewId();
const long MontyFrame::ID_BUTTON2 = wxNewId();
const long MontyFrame::ID_PANEL1 = wxNewId();
const long MontyFrame::idMenuQuit = wxNewId();
const long MontyFrame::Informationsurlapplication = wxNewId();
const long MontyFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(MontyFrame,wxFrame)
    //(*EventTable(MontyFrame)
    //*)
END_EVENT_TABLE()

MontyFrame::MontyFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(MontyFrame)
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer3;
    wxBoxSizer* BoxSizer4;
    wxBoxSizer* BoxSizer5;
    wxBoxSizer* BoxSizer6;
    wxBoxSizer* VBoxMain;
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(360,480));
    SetMinSize(wxSize(360,480));
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(240,248), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    VBoxMain = new wxBoxSizer(wxVERTICAL);
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Nombre d\'essais : "), wxDefaultPosition, wxSize(180,-1), 0, _T("ID_STATICTEXT1"));
    BoxSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinTries = new wxSpinCtrl(Panel1, ID_SPINCTRL1, _T("10"), wxDefaultPosition, wxDefaultSize, 0, 10, 2000000000, 10, _T("ID_SPINCTRL1"));
    SpinTries->SetValue(_T("10"));
    BoxSizer1->Add(SpinTries, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    VBoxMain->Add(BoxSizer1, 1, wxALL|wxALIGN_LEFT, 5);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Nombre de chèvres : "), wxDefaultPosition, wxSize(180,-1), 0, _T("ID_STATICTEXT2"));
    BoxSizer2->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Spingoats = new wxSpinCtrl(Panel1, ID_SPINCTRL2, _T("2"), wxDefaultPosition, wxDefaultSize, 0, 2, 8, 2, _T("ID_SPINCTRL2"));
    Spingoats->SetValue(_T("2"));
    BoxSizer2->Add(Spingoats, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    VBoxMain->Add(BoxSizer2, 1, wxALL|wxALIGN_LEFT, 5);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("Nombre de voitures : "), wxDefaultPosition, wxSize(180,-1), 0, _T("ID_STATICTEXT3"));
    BoxSizer3->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCars = new wxSpinCtrl(Panel1, ID_SPINCTRL3, _T("1"), wxDefaultPosition, wxDefaultSize, 0, 1, 8, 1, _T("ID_SPINCTRL3"));
    SpinCars->SetValue(_T("1"));
    BoxSizer3->Add(SpinCars, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    VBoxMain->Add(BoxSizer3, 1, wxALL|wxALIGN_LEFT, 5);
    BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    GaugeSimulation = new wxGauge(Panel1, ID_GAUGE1, 100, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_GAUGE1"));
    BoxSizer4->Add(GaugeSimulation, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    VBoxMain->Add(BoxSizer4, 1, wxALL|wxEXPAND, 5);
    BoxSizer6 = new wxBoxSizer(wxVERTICAL);
    STNoChangeResult = new wxStaticText(Panel1, ID_STATICTEXT4, _("Nombre de réussites sans changement = "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    BoxSizer6->Add(STNoChangeResult, 1, wxALL|wxALIGN_LEFT, 5);
    STChangeResult = new wxStaticText(Panel1, ID_STATICTEXT5, _("Nombre de réussites avec changement ="), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    BoxSizer6->Add(STChangeResult, 1, wxALL|wxALIGN_LEFT, 5);
    VBoxMain->Add(BoxSizer6, 1, wxALL|wxEXPAND, 5);
    BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
    BSimuler = new wxButton(Panel1, ID_BUTTON1, _("Exécuter la simulation"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BSimuler->SetDefault();
    BoxSizer5->Add(BSimuler, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button1 = new wxButton(Panel1, ID_BUTTON2, _("Quitter le programme"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer5->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    VBoxMain->Add(BoxSizer5, 1, wxALL|wxEXPAND, 5);
    Panel1->SetSizer(VBoxMain);
    VBoxMain->Fit(Panel1);
    VBoxMain->SetSizeHints(Panel1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quitter\tAlt-F4"), _("Quitter l\'application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&Fichiers"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, Informationsurlapplication, _("A propos...\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Aide"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MontyFrame::OnBSimulerClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MontyFrame::OnQuit);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MontyFrame::OnQuit);
    Connect(Informationsurlapplication,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MontyFrame::OnAbout);
    //*)

    logic = new Logic();
}

MontyFrame::~MontyFrame()
{
    //(*Destroy(MontyFrame)
    //*)
    delete logic;
}

void MontyFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void MontyFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Simulation du problème de Monty Hall"));
}

void MontyFrame::makeTests()
{
    bool result = false;
    int numberOfTries = SpinTries->GetValue();
    int successWithChange = 0;
    int successWithoutChange = 0;

    try
    {
        logic->setNumberOfGoats(Spingoats->GetValue());
        logic->setNumberOfCars(SpinCars->GetValue());

        if (numberOfTries > OKFORGAUGE)
        {
            int step = numberOfTries / 100;
            int totalSteps = 0;
            for(int i = 0; i < 99; i++)
            {
               totalSteps += step;
               result = logic->executeSimulation(step);
               GaugeSimulation->SetValue(i);
               successWithoutChange=successWithoutChange+logic->getSuccessWithoutChanges();
               successWithChange=successWithChange+logic->getSuccessWithChanges();
            }
               result = logic->executeSimulation(numberOfTries-totalSteps);
               successWithoutChange=successWithoutChange+logic->getSuccessWithoutChanges();
               successWithChange=successWithChange+logic->getSuccessWithChanges();
        }
            else
            {
                result = logic->executeSimulation(numberOfTries);
                successWithoutChange=logic->getSuccessWithoutChanges();
                successWithChange=logic->getSuccessWithChanges();
            }
    }
    catch(const std::invalid_argument& e)
    {
        wxString errorMessage = e.what();
        wxLogWarning(errorMessage);
    }
    catch(...)
    {
        wxLogWarning("Une erreur indéterminée s'est produite dans le module logique.");
        result = false;
    }

    GaugeSimulation->SetValue(0);
    GaugeSimulation->Refresh();
    GaugeSimulation->Update();
    wxString display;

    if (result)
    {
        display = wxString::Format("Nombre de réussites sans changement = %d", successWithoutChange);
        STNoChangeResult->SetLabel(display);
        display = wxString::Format("Nombre de réussites avec changement = %d", successWithChange);
        STChangeResult->SetLabel(display);
    }

}


void MontyFrame::OnBSimulerClick(wxCommandEvent& event)
{
    makeTests();
}
