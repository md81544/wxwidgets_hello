#include <wx/wx.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/button.h>
#include <wx/menu.h>
#include <wx/sizer.h>

class MyFrame : public wxFrame
{
public:
    MyFrame() : wxFrame(nullptr, wxID_ANY, "wxWidgets Example", wxDefaultPosition, wxSize(400, 300))
    {
        // Disable resizing
        SetMinSize(GetSize());
        SetMaxSize(GetSize());

        // ===== Menu bar =====
        wxMenu *menuFile = new wxMenu;
        menuFile->Append(wxID_OPEN, "&Open...\tCtrl-O", "Open a file");
        menuFile->Append(wxID_PREFERENCES, "&Preferences...\tCtrl-,", "Edit preferences");
        menuFile->AppendSeparator();
        menuFile->Append(wxID_EXIT, "&Quit\tCtrl-Q", "Quit the application");
        // On macOS, wxID_EXIT and wxID_PREFERENCES will be moved to the Application menu

        wxMenu *menuHelp = new wxMenu;
        menuHelp->Append(wxID_ABOUT, "&About\tF1", "About this application");

        wxMenuBar *menuBar = new wxMenuBar;
        menuBar->Append(menuFile, "&File");
        menuBar->Append(menuHelp, "&Help");
        SetMenuBar(menuBar);

        // ===== Status bar =====
        CreateStatusBar();
        SetStatusText("Welcome to wxWidgets 3.3.1!");

        // ===== Main panel and controls =====
        wxPanel *panel = new wxPanel(this);

        // Inner sizer for controls
        wxBoxSizer *innerSizer = new wxBoxSizer(wxVERTICAL);

        wxStaticText *label = new wxStaticText(panel, wxID_ANY, "Enter some text:");
        innerSizer->Add(label, 0, wxALL, 5);

        textBox = new wxTextCtrl(panel, wxID_ANY);
        innerSizer->Add(textBox, 0, wxALL | wxEXPAND, 5);

        checkBox = new wxCheckBox(panel, wxID_ANY, "Check me!");
        innerSizer->Add(checkBox, 0, wxALL, 5);

        wxButton *btn = new wxButton(panel, wxID_ANY, "Click Me");
        innerSizer->Add(btn, 0, wxALL | wxALIGN_CENTER, 5);

        // Outer sizer for padding around all controls
        wxBoxSizer *outerSizer = new wxBoxSizer(wxVERTICAL);
        outerSizer->Add(innerSizer, 1, wxEXPAND | wxALL, 20); // 20px border

        panel->SetSizer(outerSizer);

        // ===== Event bindings =====
        Bind(wxEVT_MENU, &MyFrame::OnQuit, this, wxID_EXIT);
        Bind(wxEVT_MENU, &MyFrame::OnAbout, this, wxID_ABOUT);
        Bind(wxEVT_MENU, &MyFrame::OnOpen, this, wxID_OPEN);
        Bind(wxEVT_MENU, &MyFrame::OnPreferences, this, wxID_PREFERENCES);
        btn->Bind(wxEVT_BUTTON, &MyFrame::OnButtonClicked, this);
    }

private:
    wxTextCtrl *textBox;
    wxCheckBox *checkBox;

    void OnQuit(wxCommandEvent &)
    {
        Close(true);
    }

    void OnAbout(wxCommandEvent &)
    {
        wxMessageBox("This is a simple wxWidgets example for macOS.\nVersion 3.3.1",
                     "About", wxOK | wxICON_INFORMATION);
    }

    void OnOpen(wxCommandEvent &)
    {
        wxFileDialog openFileDialog(this, _("Open file"), "", "",
                                    "All files (*.*)|*.*",
                                    wxFD_OPEN | wxFD_FILE_MUST_EXIST);
        if (openFileDialog.ShowModal() == wxID_CANCEL)
            return;

        wxMessageBox("Selected file:\n" + openFileDialog.GetPath(),
                     "Open", wxOK | wxICON_INFORMATION);
    }

    void OnPreferences(wxCommandEvent &)
    {
        wxMessageBox("Preferences dialog placeholder.",
                     "Preferences", wxOK | wxICON_INFORMATION);
    }

    void OnButtonClicked(wxCommandEvent &)
    {
        wxString message = "Text: \"" + textBox->GetValue() + "\"  Checkbox: ";
        message += checkBox->IsChecked() ? "Checked" : "Unchecked";
        SetStatusText(message);
    }
};

class MyApp : public wxApp
{
public:
    bool OnInit() override
    {
        MyFrame *frame = new MyFrame();
        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(MyApp);
