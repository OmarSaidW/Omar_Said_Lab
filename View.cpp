//
// Created by omar on 23/11/24.
//

#include "View.h"
void View::onIncrementButtonClick( wxCommandEvent& event ) {
    controller->increment();
}
void View::onDecrementButtonClick( wxCommandEvent& event ) {
    controller->decrement();
}
View::View(Model* model, Controller* controller, wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style )
        : wxFrame( parent, id, title, pos, size, style ), model(model), controller(controller) {
    wxBoxSizer* bSizer1;
    bSizer1 = new wxBoxSizer( wxVERTICAL );
    staticText = new wxStaticText( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
    staticText->Wrap( -1 );
    bSizer1->Add( staticText, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
    textCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    bSizer1->Add( textCtrl, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
    incrementButton = new wxButton( this, wxID_ANY, wxT("Increment"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer1->Add( incrementButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
    decrementButton = new wxButton( this, wxID_ANY, wxT("Decrement"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer1->Add( decrementButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
    this->SetSizer( bSizer1 );
    this->Layout();
    this->Centre( wxBOTH );
    incrementButton->Bind( wxEVT_BUTTON, &View::onIncrementButtonClick, this );
    decrementButton->Bind( wxEVT_BUTTON, &View::onDecrementButtonClick, this );
    model->addObserver(this);
}
void View::update() {
    staticText->SetLabel(wxString::Format(wxT("%i"), model->getData()));
}
