// AVI MetaEdit GUI - A GUI for AVI MetaEdit
//
// This code was created in 2010 for the Library of Congress and the
// other federal government agencies participating in the Federal Agencies
// Digitization Guidelines Initiative and it is in the public domain.
//
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//---------------------------------------------------------------------------
#include "GUI/Qt/GUI_Main_Output_stderr.h"
#include "Common/Core.h"
#include "ZenLib/Ztring.h"
#include <QtGui/QLabel>
#include <QtCore/QEvent>
#include <QtGui/QFont>
//---------------------------------------------------------------------------

//***************************************************************************
// Constructor/Destructor
//***************************************************************************

//---------------------------------------------------------------------------
GUI_Main_Output_stderr::GUI_Main_Output_stderr(Core* _C, QWidget* parent)
: QTextEdit(parent)
{
    //Internal
    C=_C;

    //Configuration
    setLineWrapMode(QTextEdit::NoWrap);
    setReadOnly(true);
}

//***************************************************************************
// Actions
//***************************************************************************

//---------------------------------------------------------------------------
bool GUI_Main_Output_stderr::event (QEvent *Event) 
{
    if (Event->type()==QEvent::User)
    {
        //Showing
        clear();
        setPlainText(QString().fromUtf8(ZenLib::Ztring(C->Text_stderr.str()).To_Local().c_str()));

        Event->accept();
        return true;
    }

    return QTextEdit::event(Event);
}