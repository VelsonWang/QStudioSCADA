#include "functionedit.h"
#include "functioneditordialog.h"
#include <QHBoxLayout>
#include <QToolButton>
#include <QFocusEvent>

FunctionEdit::FunctionEdit(QWidget *parent)
    : QWidget(parent)
{
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setMargin(0);
    layout->setSpacing(0);
    theLabel_ = new QLabel(this);
    theLabel_->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred));
    QToolButton *button = new QToolButton(this);
    button->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred));
    button->setText(QLatin1String("..."));
    layout->addWidget(theLabel_);
    layout->addWidget(button);
    setFocusPolicy(Qt::StrongFocus);
    setAttribute(Qt::WA_InputMethodEnabled);
    connect(button, SIGNAL(clicked()), this, SLOT(buttonClicked()));
}

void FunctionEdit::buttonClicked()
{
    FunctionEditorDialog dlg(Q_NULLPTR, supportEvents_);
    dlg.setFunctions(funcs_);
    if(dlg.exec() == QDialog::Accepted) {
        QStringList funcs = dlg.getFunctions();
        setFunctions(funcs);
        QString szFuncs = funcs.join("|");
        theLabel_->setText(szFuncs);
        emit functionsChanged(szFuncs);
    }
}