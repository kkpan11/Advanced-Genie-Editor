#include "Common.h"
using std::string;
using boost::lexical_cast;
using boost::bad_lexical_cast;

//	The purpose of these custom text controls is that you get specified error messages
//	when your mouse cursor focus gets off from a data edit box.

#ifndef AGE_TextControls_h
#define AGE_TextControls_h

class TextCtrl_Byte: public wxTextCtrl
{
	public:

	TextCtrl_Byte(wxWindow *parent):
	wxTextCtrl(parent, wxID_ANY, "0", wxDefaultPosition, wxSize(0, 20))
	{
		Container = NULL;
		SetBackgroundColour(wxColour(255, 235, 215));
		Connect(GetId(), wxEVT_KILL_FOCUS, wxFocusEventHandler(TextCtrl_Byte::OnKillFocus));	// Must-have
	}

//	Events

	void OnKillFocus(wxFocusEvent &Event){SaveEdits();}
	bool SaveEdits();

//	Member Variables

	char *Container;
	void *LinkedBox;	//	These are for check and combo boxes.
};

class TextCtrl_UByte: public wxTextCtrl
{
	public:

	TextCtrl_UByte(wxWindow *parent):
	wxTextCtrl(parent, wxID_ANY, "0", wxDefaultPosition, wxSize(0, 20))
	{
		Container = NULL;
		SetBackgroundColour(wxColour(255, 235, 215));
		Connect(GetId(), wxEVT_KILL_FOCUS, wxFocusEventHandler(TextCtrl_UByte::OnKillFocus));	// Must-have
	}

//	Events

	void OnKillFocus(wxFocusEvent &Event){SaveEdits();}
	bool SaveEdits();

//	Member Variables

	unsigned char *Container;
	void *LinkedBox;	//	These are for check and combo boxes.
};

class TextCtrl_Float: public wxTextCtrl
{
	public:

	TextCtrl_Float(wxWindow *parent):
	wxTextCtrl(parent, wxID_ANY, "0", wxDefaultPosition, wxSize(0, 20))
	{
		Container = NULL;
		SetBackgroundColour(wxColour(255, 225, 255));
		Connect(GetId(), wxEVT_KILL_FOCUS, wxFocusEventHandler(TextCtrl_Float::OnKillFocus));
	}

//	Events

	void OnKillFocus(wxFocusEvent &Event){SaveEdits();}
	bool SaveEdits();

//	Member Variables

	float *Container;
	void *LinkedBox;
};

class TextCtrl_Long: public wxTextCtrl
{
	public:

	TextCtrl_Long(wxWindow *parent):
	wxTextCtrl(parent, wxID_ANY, "0", wxDefaultPosition, wxSize(0, 20))
	{
		Container = NULL;
		SetBackgroundColour(wxColour(215, 255, 255));
		Connect(GetId(), wxEVT_KILL_FOCUS, wxFocusEventHandler(TextCtrl_Long::OnKillFocus));
	}

//	Events

	void OnKillFocus(wxFocusEvent &Event){SaveEdits();}
	bool SaveEdits();

//	Member Variables

	int32_t *Container;
	void *LinkedBox;
};

class TextCtrl_Short: public wxTextCtrl
{
	public:

	TextCtrl_Short(wxWindow *parent):
	wxTextCtrl(parent, wxID_ANY, "0", wxDefaultPosition, wxSize(0, 20))
	{
		Container = NULL;
		SetBackgroundColour(wxColour(210, 230, 255));
		Connect(GetId(), wxEVT_KILL_FOCUS, wxFocusEventHandler(TextCtrl_Short::OnKillFocus));
	}

//	Events

	void OnKillFocus(wxFocusEvent &Event){SaveEdits();}
	bool SaveEdits();

//	Member Variables

	int16_t *Container;
	void *LinkedBox;
};

class TextCtrl_UShort: public wxTextCtrl
{
	public:

	TextCtrl_UShort(wxWindow *parent):
	wxTextCtrl(parent, wxID_ANY, "0", wxDefaultPosition, wxSize(0, 20))
	{
		Container = NULL;
		SetBackgroundColour(wxColour(210, 230, 255));
		Connect(GetId(), wxEVT_KILL_FOCUS, wxFocusEventHandler(TextCtrl_UShort::OnKillFocus));
	}

//	Events

	void OnKillFocus(wxFocusEvent &Event){SaveEdits();}
	bool SaveEdits();

//	Member Variables

	uint16_t *Container;
	void *LinkedBox;
};

class TextCtrl_String: public wxTextCtrl
{
	public:

	TextCtrl_String(wxWindow *parent, int16_t CLength = -1):
	wxTextCtrl(parent, wxID_ANY, "", wxDefaultPosition, wxSize(0, 20))
	{
		Container = NULL;
		MaxSize = CLength;
		SetBackgroundColour(wxColour(220, 255, 220));
		Connect(GetId(), wxEVT_KILL_FOCUS, wxFocusEventHandler(TextCtrl_String::OnKillFocus));
	}

//	Events

	void OnKillFocus(wxFocusEvent &Event){SaveEdits();}
	bool SaveEdits();
	void SetMaxSize(int16_t Size){MaxSize = Size;}

//	Member Variables

	int16_t MaxSize;
	string *Container;
};

#endif
