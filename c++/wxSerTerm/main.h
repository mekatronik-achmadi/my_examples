/*********************************************************************
 * Name:      	main.h
 * Purpose:   	Declares simple wxWidgets application with GUI
 * 				created using wxFormBuilder.
 * Author:    
 * Created:   
 * Copyright: 
 * License:   	wxWidgets license (www.wxwidgets.org)
 * 
 * Notes:		Note that all GUI creation code is declared in
 * 				gui.h source file which is generated by wxFormBuilder.
 *********************************************************************/

#ifndef __main__
#define __main__

// main wxWidgets header file
#include <wx/wx.h>
#include <wx/timer.h>
#include <wx/msgdlg.h>
#include <wx/aboutdlg.h>
#include <wx/version.h>
// gui classes generated by wxFormBuilder
#include "gui.h"

//other declaration
#include "ceSerial.h"

////////////////////////////////////////////////////////////////////////////////
// application class declaration 
////////////////////////////////////////////////////////////////////////////////

class MainApp : public wxApp
{
	public:
		virtual bool OnInit();
};

// declare global static function wxGetApp()
DECLARE_APP(MainApp)

////////////////////////////////////////////////////////////////////////////////
// main application frame declaration 
////////////////////////////////////////////////////////////////////////////////

class MainFrame : public MainFrameBase
{
	public:
		MainFrame( wxWindow *parent );
		virtual ~MainFrame();
		
	protected:
		// protected event handlers
		virtual void OnCloseFrame( wxCloseEvent& event );
		virtual void OnExitClick( wxCommandEvent& event );
		
	private:	
		// copied from gui.h without references/implementation
		virtual void OnBtnAbout( wxCommandEvent& event );
		virtual void OnBtnPortOpen( wxCommandEvent& event );
		virtual void onPortChoice( wxCommandEvent& event );
		virtual void onBaudChoice( wxCommandEvent& event );
		virtual void OnBtnSend( wxCommandEvent& event );
		virtual void addListPort(void);
		virtual void addListBaud(void);
		virtual void closingPort(void);
		virtual void onCharReceive(char ch);
		virtual char* wxstr2char(wxString& Text);
		virtual void onTimerTick(wxTimerEvent& event);
		
		ce::ceSerial *serComm;
		wxString devPort;
		long devBaud;
		wxTimer *m_serTimer;
		wxString strRequest;
		bool ignoreLF;
};

#endif //__main__
