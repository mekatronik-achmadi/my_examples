///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.9.0 Feb  8 2021)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "gui.h"

///////////////////////////////////////////////////////////////////////////

MainFrameBase::MainFrameBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* mainSizer;
	mainSizer = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bControl;
	bControl = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bMainSetting;
	bMainSetting = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bPort;
	bPort = new wxBoxSizer( wxHORIZONTAL );

	m_lblPort = new wxStaticText( this, wxID_ANY, _("Port"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_lblPort->Wrap( -1 );
	bPort->Add( m_lblPort, 1, wxALL, 5 );

	wxArrayString m_chPortChoices;
	m_chPort = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_chPortChoices, 0 );
	m_chPort->SetSelection( 0 );
	bPort->Add( m_chPort, 1, wxALL, 5 );


	bMainSetting->Add( bPort, 1, wxEXPAND, 5 );

	wxBoxSizer* bBaud;
	bBaud = new wxBoxSizer( wxHORIZONTAL );

	m_lblBaud = new wxStaticText( this, wxID_ANY, _("Baudrate"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_lblBaud->Wrap( -1 );
	bBaud->Add( m_lblBaud, 1, wxALL, 5 );

	wxArrayString m_chBaudChoices;
	m_chBaud = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_chBaudChoices, 0 );
	m_chBaud->SetSelection( 0 );
	bBaud->Add( m_chBaud, 1, wxALL, 5 );


	bMainSetting->Add( bBaud, 1, wxEXPAND, 5 );

	wxBoxSizer* bDataBit;
	bDataBit = new wxBoxSizer( wxHORIZONTAL );

	m_lblDataBit = new wxStaticText( this, wxID_ANY, _("Data Bit"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_lblDataBit->Wrap( -1 );
	bDataBit->Add( m_lblDataBit, 1, wxALL, 5 );

	wxString m_chDataBitChoices[] = { _("8") };
	int m_chDataBitNChoices = sizeof( m_chDataBitChoices ) / sizeof( wxString );
	m_chDataBit = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_chDataBitNChoices, m_chDataBitChoices, 0 );
	m_chDataBit->SetSelection( 0 );
	m_chDataBit->Enable( false );

	bDataBit->Add( m_chDataBit, 1, wxALL, 5 );


	bMainSetting->Add( bDataBit, 1, wxEXPAND, 5 );


	bControl->Add( bMainSetting, 1, 0, 5 );

	wxBoxSizer* bSecondSetting;
	bSecondSetting = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bStopBit;
	bStopBit = new wxBoxSizer( wxHORIZONTAL );

	m_lblStopBit = new wxStaticText( this, wxID_ANY, _("Stop Bit"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_lblStopBit->Wrap( -1 );
	bStopBit->Add( m_lblStopBit, 1, wxALL, 5 );

	wxString m_chStopBitChoices[] = { _("1") };
	int m_chStopBitNChoices = sizeof( m_chStopBitChoices ) / sizeof( wxString );
	m_chStopBit = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_chStopBitNChoices, m_chStopBitChoices, 0 );
	m_chStopBit->SetSelection( 0 );
	m_chStopBit->Enable( false );

	bStopBit->Add( m_chStopBit, 1, wxALL, 5 );


	bSecondSetting->Add( bStopBit, 1, wxEXPAND, 5 );

	wxBoxSizer* bParity;
	bParity = new wxBoxSizer( wxHORIZONTAL );

	m_lblParity = new wxStaticText( this, wxID_ANY, _("Parity"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_lblParity->Wrap( -1 );
	bParity->Add( m_lblParity, 1, wxALL, 5 );

	wxString m_chParityChoices[] = { _("None") };
	int m_chParityNChoices = sizeof( m_chParityChoices ) / sizeof( wxString );
	m_chParity = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_chParityNChoices, m_chParityChoices, 0 );
	m_chParity->SetSelection( 0 );
	m_chParity->Enable( false );

	bParity->Add( m_chParity, 1, wxALL, 5 );


	bSecondSetting->Add( bParity, 1, wxEXPAND, 5 );

	wxBoxSizer* bFlowCon;
	bFlowCon = new wxBoxSizer( wxHORIZONTAL );

	m_lblFlowCon = new wxStaticText( this, wxID_ANY, _("Flow Control"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_lblFlowCon->Wrap( -1 );
	bFlowCon->Add( m_lblFlowCon, 1, wxALL, 5 );

	wxString m_chFlowConChoices[] = { _("None") };
	int m_chFlowConNChoices = sizeof( m_chFlowConChoices ) / sizeof( wxString );
	m_chFlowCon = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_chFlowConNChoices, m_chFlowConChoices, 0 );
	m_chFlowCon->SetSelection( 0 );
	m_chFlowCon->Enable( false );

	bFlowCon->Add( m_chFlowCon, 1, wxALL, 5 );


	bSecondSetting->Add( bFlowCon, 1, wxEXPAND, 5 );


	bControl->Add( bSecondSetting, 1, wxEXPAND, 5 );

	wxBoxSizer* bButton;
	bButton = new wxBoxSizer( wxVERTICAL );

	m_btnPortReload = new wxButton( this, wxID_ANY, _("Refresh"), wxDefaultPosition, wxDefaultSize, 0 );
	bButton->Add( m_btnPortReload, 1, wxALL|wxEXPAND, 5 );

	m_btnPortOpen = new wxButton( this, wxID_ANY, _("Open"), wxDefaultPosition, wxDefaultSize, 0 );
	bButton->Add( m_btnPortOpen, 1, wxALL|wxEXPAND, 5 );

	m_btnAbout = new wxButton( this, wxID_ANY, _("About"), wxDefaultPosition, wxDefaultSize, 0 );
	bButton->Add( m_btnAbout, 1, wxALL|wxEXPAND, 5 );


	bControl->Add( bButton, 1, wxEXPAND, 5 );


	mainSizer->Add( bControl, 0, wxEXPAND, 5 );

	m_txtTermOut = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxTE_MULTILINE|wxTE_READONLY );
	mainSizer->Add( m_txtTermOut, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSend;
	bSend = new wxBoxSizer( wxHORIZONTAL );

	m_txtTermIn = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSend->Add( m_txtTermIn, 1, wxALL, 5 );

	m_btnSend = new wxButton( this, wxID_ANY, _("Send"), wxDefaultPosition, wxDefaultSize, 0 );
	bSend->Add( m_btnSend, 0, wxALL, 5 );


	mainSizer->Add( bSend, 0, wxEXPAND, 5 );


	this->SetSizer( mainSizer );
	this->Layout();
	m_statusBar = this->CreateStatusBar( 2, wxSTB_SIZEGRIP, wxID_ANY );

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MainFrameBase::OnCloseFrame ) );
	m_chPort->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MainFrameBase::onPortChoice ), NULL, this );
	m_chBaud->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MainFrameBase::onBaudChoice ), NULL, this );
	m_btnPortOpen->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnBtnPortOpen ), NULL, this );
	m_btnAbout->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnBtnAbout ), NULL, this );
	m_btnSend->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnBtnSend ), NULL, this );
}

MainFrameBase::~MainFrameBase()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MainFrameBase::OnCloseFrame ) );
	m_chPort->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MainFrameBase::onPortChoice ), NULL, this );
	m_chBaud->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MainFrameBase::onBaudChoice ), NULL, this );
	m_btnPortOpen->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnBtnPortOpen ), NULL, this );
	m_btnAbout->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnBtnAbout ), NULL, this );
	m_btnSend->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnBtnSend ), NULL, this );

}
