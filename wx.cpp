//
// Created by omar on 26/11/24.
//
#include <wx/wx.h>
#include "Raccoglitore.h"
#include <vector>
class MyApp : public wxApp{
public:
    bool OnInit() override;

};

// This defines the equivalent of main() for the current platform.
wxIMPLEMENT_APP(MyApp);
class MyFrame : public wxFrame{
public:
    MyFrame();
    Raccoglitore & getRaccoglitore()   { return iphone; }

    void OnCheckboxClicked(wxCommandEvent &event);
    void OnChildClosed(wxCloseEvent& event); // Handler for child frame closure




protected:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnNewNote(wxCommandEvent& event);
    void OnPrintNote(wxCommandEvent& event);// Handler for the button click
    void OnNewCartella(wxCommandEvent& event);
    void addNoteToFolder(wxCommandEvent& event);
    void printFolderNotes(wxCommandEvent& event);
    void OnModifyNoteText(wxCommandEvent& event);
    void OnRemoveNote(wxCommandEvent& event);
    void OnShowSecondFrame(MyFrame *parent);

    wxCheckBox *checkbox;
    Raccoglitore iphone;
    wxFrame* secondFrame = nullptr;
};

class MyFrame2 : public wxFrame {
public:
    explicit MyFrame2(MyFrame* parent);
    void showNote(const std::shared_ptr<Note> & nota) const ;
    void OnRadioBoxSelected(wxCommandEvent& event);
    void OnAddOption(const wxString & title);
private:
    void RecreateRadioBox();
    wxRadioBox* myRadioBox;
    wxStaticText * label;
    std::vector<wxString> folders;
    MyFrame* parent;
    wxStaticText * folderLabel;


};
bool MyApp::OnInit(){
    auto *frame = new MyFrame();
    frame->Show();
    return true;
}
enum{
    ID_New_Note = 2,
    ID_Print_Note = 3,
    ID_New_Cartella = 4,
    ID_AddNoteToFolder =5,
    ID_Folder_Notes = 6,
    ID_Modify_Note_Text = 7,
    ID_Remove_Note = 8,
};

MyFrame::MyFrame()
        : wxFrame(nullptr, wxID_ANY, "Action Frame", wxDefaultPosition, wxSize(800, 600)) {
    wxMenu *menuFile = new wxMenu;

    OnShowSecondFrame(this);

    menuFile->Append(wxID_EXIT);
    menuFile->AppendSeparator();
    menuFile->Append(ID_Modify_Note_Text, "modify note");
    menuFile->AppendSeparator();
    menuFile->Append(ID_Remove_Note, "remove note");


    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");

    SetMenuBar(menuBar);

    CreateStatusBar();


    wxButton *NewNote = new wxButton(this, ID_New_Note, "Create New Note", wxPoint(20, 50));
    wxButton *PrintNote = new wxButton(this, ID_Print_Note, "Stampa la nota", wxPoint(20, 100));
    wxButton *NewCartella = new wxButton(this, ID_New_Cartella, "Create New Cartella", wxPoint(20, 150));
    wxButton *addNoteToFolder = new wxButton(this, ID_AddNoteToFolder, "Add Note To Folder", wxPoint(20, 200));

    Bind(wxEVT_MENU, &MyFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_MENU, &MyFrame::OnModifyNoteText, this, ID_Modify_Note_Text);
    Bind(wxEVT_MENU, &MyFrame::OnRemoveNote, this, ID_Remove_Note);
    Bind(wxEVT_BUTTON, &MyFrame::OnNewNote, this, ID_New_Note);
    Bind(wxEVT_BUTTON, &MyFrame::OnPrintNote, this, ID_Print_Note);
    Bind(wxEVT_BUTTON, &MyFrame::OnNewCartella, this, ID_New_Cartella);
    Bind(wxEVT_BUTTON, &MyFrame::addNoteToFolder, this, ID_AddNoteToFolder);
}

void MyFrame::OnExit(wxCommandEvent& event){
    Close(true);
}
void MyFrame::OnAbout(wxCommandEvent& event){
    wxMessageBox("This is a wxwWidgets note taking app",
                 "Note app", wxOK | wxICON_INFORMATION);
}

void MyFrame::OnNewNote(wxCommandEvent& event) {
    wxString noteTitle = wxGetTextFromUser(wxT("Scrivi qui il titolo della nota"), wxT("TITOLO") );
    wxString noteText = wxGetTextFromUser(wxT("scrivi qui il testo della nota"), wxT("TEXT") );
    std::string noteTitleString = std::string(noteTitle.mb_str());
    std::string noteTextString = std::string(noteText.mb_str());
    iphone.createNewNote(noteTitleString, noteTextString);
    auto *frame2 = dynamic_cast<MyFrame2 *>(secondFrame);
    frame2->OnRadioBoxSelected(event);
}

void MyFrame::OnPrintNote(wxCommandEvent &event) {
    wxString noteTitle = wxGetTextFromUser(wxT("Scrivi qui il titolo della nota cercata"), wxT("Print My note") );
    std::string noteTitleString = std::string(noteTitle.mb_str());
    std::shared_ptr<Note> nota = iphone.findNote(noteTitleString);
    if (nota!= nullptr) {
        wxMessageBox(nota->getText(), nota->getTitle(), wxOK | wxICON_INFORMATION);

        auto frame2 = dynamic_cast<MyFrame2 *>(secondFrame);
        if (frame2)
            frame2->showNote(nota);
    }
    else
        wxMessageBox("Non è presente la nota cercata","Error");

}

void MyFrame::OnNewCartella(wxCommandEvent& event) {
    wxString cartellaTitle = wxGetTextFromUser(wxT("Scrivi qui il titolo della Cartella"), wxT("TITOLO") );
    std::string cartellaTitleString = std::string(cartellaTitle.mb_str());
    iphone.createCartella(cartellaTitleString);
    auto frame2 = dynamic_cast<MyFrame2 *>(secondFrame);
    if (frame2)
        frame2->OnAddOption(cartellaTitle);
}

void MyFrame::addNoteToFolder(wxCommandEvent &event) {
    wxString noteTitle = wxGetTextFromUser(wxT("Scrivi qui il titolo della nota che si vuole aggiungere alla cartella"), wxT("Find My note") );
    wxString folderTitle = wxGetTextFromUser(wxT("Scrivi qui il titolo della cartella a cui si vuole aggiungere la nota"), wxT("FolderTitle") );
    std::string noteTitleString = std::string(noteTitle.mb_str());
    std::string folderTitleString = std::string(folderTitle.mb_str());
    iphone.addNoteToFolder(folderTitleString, noteTitleString);
}

void MyFrame::OnModifyNoteText(wxCommandEvent &event) {
    wxString noteTitle = wxGetTextFromUser(wxT("Scrivi qui il titolo della nota che si vuole modificare"),wxT("Find My note"));
    wxString newText = wxGetTextFromUser(wxT("Scrivi qui il nuovo testo della nota"), wxT("New Text"));
    std::string noteTitleString = std::string(noteTitle.mb_str());
    std::string newTextString = std::string(newText.mb_str());
    iphone.modifyText(newTextString, noteTitleString);
}
void MyFrame::OnRemoveNote(wxCommandEvent &event) {
    wxString noteTitle = wxGetTextFromUser(wxT("Scrivi qui il titolo della nota che si vuole rimuovere"),wxT("Find My note"));
    std::string noteTitleString = std::string(noteTitle.mb_str());
    iphone.removeNote (noteTitleString);
}

void MyFrame::OnShowSecondFrame(MyFrame *parent) {
    if (secondFrame == nullptr) {
        parent= this;
        secondFrame = new MyFrame2(parent); // Crea il secondo frame se ancora non esiste
    }
    secondFrame->Show();
}






MyFrame2::MyFrame2(MyFrame* parent)
        : wxFrame(nullptr, wxID_ANY, "Second Frame", wxDefaultPosition, wxSize(1000, 800)), parent(parent) {
    parent->Bind(wxEVT_CLOSE_WINDOW, &MyFrame::OnChildClosed ,parent, this->GetId());
    enum{
        ID_label = 9
    };
    label = new wxStaticText(this, ID_label, "", wxPoint(20, 50));
    folderLabel = new wxStaticText(this, wxID_ANY, "", wxPoint(500, 200));
    folders = { "iphoneNotes" };
    myRadioBox = new wxRadioBox(this, wxID_ANY, "Cartelle  \n premi per vedere le note", wxPoint(500, 50), wxDefaultSize,
                                folders.size(), folders.data(),  wxRA_SPECIFY_ROWS);

    Bind(wxEVT_RADIOBOX, &MyFrame2::OnRadioBoxSelected, this, myRadioBox->GetId());
}

void MyFrame2::showNote(const std::shared_ptr<Note> & nota)const  {
    label->SetLabel("Titolo: " + nota->getTitle() + "\n Testo: " + nota->getText() + "\n");
}

void MyFrame2::OnRadioBoxSelected(wxCommandEvent& event) {
    int selection = myRadioBox->GetSelection(); // Get the selected index
    wxString choice = myRadioBox->GetString(selection); // Get the selected label
    std::string FolderTitleString = std::string(choice.mb_str());
    if(choice == "iphoneNotes") {
        std::string output;
        parent->getRaccoglitore().printRaccoglitoreNotes(output);
        wxString outputString(output.c_str(), wxConvUTF8);
        folderLabel->SetLabel(outputString);
    }else{
            std::string output;
            parent->getRaccoglitore().printFolderNotes(FolderTitleString, output);
            wxString outputString(output.c_str(), wxConvUTF8);
            folderLabel->SetLabel(outputString);
    }
}

void MyFrame2::OnAddOption(const wxString & title) {
    folders.push_back(wxString::Format(title, folders.size() + 1));
    RecreateRadioBox();
}

void MyFrame2::RecreateRadioBox() { //distruggo la vecchia radiobox e ne creo una nuova
    delete myRadioBox;
    myRadioBox = new wxRadioBox(this, wxID_ANY, "Cartelle  \n premi per vedere le note", wxPoint(500, 50), wxDefaultSize,
                                folders.size(), folders.data(), 1, wxRA_SPECIFY_ROWS);
    Bind(wxEVT_RADIOBOX, &MyFrame2::OnRadioBoxSelected, this, myRadioBox->GetId());
}

void MyFrame::OnChildClosed(wxCloseEvent& event) {
    secondFrame = nullptr;
    event.Skip();
}

