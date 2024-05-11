/***************************************************************
 * Name:      MontyMain.h
 * Purpose:   Defines Application Frame
 * Author:    Y ()
 * Created:   2024-04-27
 * Copyright: Y ()
 * License:
 **************************************************************/

#ifndef MONTYMAIN_H
#define MONTYMAIN_H

//(*Headers(MontyFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/gauge.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/spinctrl.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
//*)


#include <string>
#include <exception>
#include <wx/log.h>
#include <vector>
#include <wx/event.h>
#include <wx/log.h>
#include <vector>

#include "Logic.h"

#define OKFORGAUGE 200

class MontyFrame: public wxFrame
{
    public:

        MontyFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~MontyFrame();

    private:

        //(*Handlers(MontyFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnBSimulerClick(wxCommandEvent& event);
        //*)

        //(*Identifiers(MontyFrame)
        static const long ID_STATICTEXT1;
        static const long ID_SPINCTRL1;
        static const long ID_STATICTEXT2;
        static const long ID_SPINCTRL2;
        static const long ID_STATICTEXT3;
        static const long ID_SPINCTRL3;
        static const long ID_GAUGE1;
        static const long ID_STATICTEXT4;
        static const long ID_STATICTEXT5;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_PANEL1;
        static const long idMenuQuit;
        static const long Informationsurlapplication;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(MontyFrame)
        wxButton* BSimuler;
        wxButton* Button1;
        wxGauge* GaugeSimulation;
        wxPanel* Panel1;
        wxSpinCtrl* SpinCars;
        wxSpinCtrl* SpinTries;
        wxSpinCtrl* Spingoats;
        wxStaticText* STChangeResult;
        wxStaticText* STNoChangeResult;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxStaticText* StaticText3;
        wxStatusBar* StatusBar1;
        //*)

        Logic *logic = nullptr;
        int NumberOfGoats = 0;
        int NumberOfCars = 0;
        void makeTests();

        DECLARE_EVENT_TABLE()


};

#endif // MONTYMAIN_H
