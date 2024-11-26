//
// Created by omar on 23/11/24.
//

#ifndef NOTE_VIEW_H
#define NOTE_VIEW_H
#include "Observer.h"
#include "Model.h"
#include "Controller.h"
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class View : public wxFrame, public Observer {
private:
protected:
    Model* model;
    Controller* controller;
    wxStaticText* staticText;
    wxTextCtrl* textCtrl;
    wxButton* incrementButton;
    wxButton* decrementButton;
    virtual void onIncrementButtonClick( wxCommandEvent& event );
    virtual void onDecrementButtonClick( wxCommandEvent& event );
public:
    View(Model* model, Controller* controller, wxWindow* parent=NULL, wxWindowID id =
    wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos =
    wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style =
    wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
    virtual ~View();
    virtual void update() override;
};


#endif //NOTE_VIEW_H
