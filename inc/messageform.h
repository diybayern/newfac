#ifndef MESSAGEFORM_H
#define MESSAGEFORM_H

#include <QDialog>
#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include <QGroupBox>
#include <QLineEdit>
#include <QPointer>
#include <QHBoxLayout>
#include <QKeyEvent>
#include <QDebug>
#include <QTimer>
#include "../inc/ui.h"

class MessageForm : public QDialog
{
    Q_OBJECT
public:
    enum{
        Message = 0,
        Warnning,
        Error,
        Doing,
        Input,
        Confirm,
        SNMAC,
        NOICON
    };
    MessageForm(QWidget *parent = 0,const int mode=0,const int timeout = 0);
    ~MessageForm();
    int startExec();
    QString get_sn_mac_text();

public slots:
    void setTitle(const QString &title)   {lb_title->setText(title);lb_title->update();}
    void setText(const QString &str)      {lb_text->setText(str);lb_text->update();}
    void setLabel(const QString &str)     {lb_snmac->setText(str);lb_snmac->update();}

protected:
    void keyPressEvent(QKeyEvent *event);
    bool eventFilter(QObject *obj, QEvent *event);

private slots:
    void proButtonOK();
    void proButtonFail();
    void proButtonCancel();
    //void updateText();

public:
    QFrame          *frame;
    QLabel          *lb_title;
    QLabel          *lb_text;
    QPushButton     *bt_ok;
    QPushButton     *bt_fail;
    QPushButton     *bt_cancle;
    QLabel          *lb_icon;
    QLineEdit       *le_snmac;
    QHBoxLayout     *ly_snmac;
    QLabel          *lb_snmac;
    QPushButton     *bt_snmac;

private:
   int             mode;

  // QTimer          updatetimer;

   QString         m_sMsg;

   int             timerId;
   int             errTimerId;
   int             timeout;
   QGroupBox       *groupBox;
   QLineEdit       *le_input;
   QMovie          *movie;
   QString         m_sn_mac_msg;
   void _set_sn_mac_text(QString &str);
};

extern MessageForm* gstr_message_form;
extern bool MessageBox(QWidget *parent,const int mode,const QString &title,const QString &text,const int timeout);

#endif // MESSAGEFORM_H
