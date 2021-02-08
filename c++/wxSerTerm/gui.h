///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.9.0 Feb  8 2021)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/choice.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/textctrl.h>
#include <wx/statusbr.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MainFrameBase
///////////////////////////////////////////////////////////////////////////////
class MainFrameBase : public wxFrame
{
	private:

	protected:
		wxStaticText* m_lblPort;
		wxChoice* m_chPort;
		wxStaticText* m_lblBaud;
		wxChoice* m_chBaud;
		wxStaticText* m_lblDataBit;
		wxChoice* m_chDataBit;
		wxStaticText* m_lblStopBit;
		wxChoice* m_chStopBit;
		wxStaticText* m_lblParity;
		wxChoice* m_chParity;
		wxStaticText* m_lblFlowCon;
		wxChoice* m_chFlowCon;
		wxButton* m_btnPortReload;
		wxButton* m_btnPortOpen;
		wxButton* m_btnAbout;
		wxTextCtrl* m_txtTermOut;
		wxTextCtrl* m_txtTermIn;
		wxButton* m_btnSend;
		wxStatusBar* m_statusBar;

		// Virtual event handlers, override them in your derived class
		virtual void OnCloseFrame( wxCloseEvent& event ) { event.Skip(); }
		virtual void onPortChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void onBaudChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnBtnPortOpen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnBtnAbout( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnBtnSend( wxCommandEvent& event ) { event.Skip(); }


	public:

		MainFrameBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,700 ), long style = wxCLOSE_BOX|wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MainFrameBase();

};

