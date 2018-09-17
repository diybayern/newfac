#include "inc/messageform.h"

MessageForm* gstr_message_form = NULL;

MessageForm::MessageForm(QWidget *parent, const int mode, const int timeout) : QDialog(parent)
{
    gstr_message_form = this;
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
    setWindowModality(Qt::ApplicationModal);
    setFocusPolicy(Qt::StrongFocus);
    //setAttribute(Qt::WA_DeleteOnClose, false);
    setAttribute(Qt::WA_TranslucentBackground,true);

    if (this->objectName().isEmpty()) {
        this->setObjectName(QString::fromUtf8("MessageFormClass"));
    }
    resize(600, 300);
    frame = new QFrame(this);
    frame->setObjectName(QString::fromUtf8("frame"));
    frame->setGeometry(QRect(0, 0, 600, 300));
    frame->setStyleSheet("QFrame#frame{border-image:url(./img/dialog_600x300.jpg);}");

    lb_title = new QLabel(frame);
    lb_title->setObjectName(QString::fromUtf8("lb_title"));
    lb_title->setGeometry(QRect(20, 16, 560, 40));

    QFont font;
    font.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
    font.setPointSize(14);
    lb_title->setFont(font);
    lb_title->setStyleSheet("background-color: rgb(0, 255, 255);");
    lb_title->setAlignment(Qt::AlignCenter);
    groupBox = new QGroupBox(frame);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));


    this->mode = mode;

    if (mode != NOICON) {
        groupBox->setGeometry(QRect(20, 60, 560, 140));
        groupBox->setFont(font);

        lb_icon = new QLabel(groupBox);
        lb_icon->setObjectName(QString::fromUtf8("lb_icon"));
        lb_icon->setGeometry(QRect(0, 40, 80, 80));

        if (mode == Message)
        {
            lb_icon->setPixmap(QPixmap("./img/message.png"));
        }
        else if (mode == Warnning)
        {
            lb_icon->setPixmap(QPixmap("./img/warning.png"));
        }
        else if (mode == Error)
        {
            lb_icon->setPixmap(QPixmap("./img/error.png"));
        }

    }

    if (mode != SNMAC) {
        lb_text = new QLabel(groupBox);
        lb_text->setObjectName(QString::fromUtf8("lb_text"));
        lb_text->setGeometry(QRect(95, 10, 500, 130));

        lb_text->setFont(font);
        lb_text->setAlignment(Qt::AlignLeading|Qt::AlignCenter);
        lb_text->setWordWrap(true);
    } else {
        ly_snmac = new QHBoxLayout(groupBox);
        ly_snmac->setObjectName(QString::fromUtf8("ly_snmac"));
        lb_snmac = new QLabel;
        lb_snmac->setObjectName(QString::fromUtf8("lb_snmac"));
        lb_snmac->setFont(font);
        le_snmac = new QLineEdit;
        le_snmac->setObjectName(QString::fromUtf8("le_snmac"));
        ly_snmac->addWidget(lb_snmac);
        ly_snmac->addWidget(le_snmac);
        le_snmac->setFocusPolicy(Qt::StrongFocus);
        le_snmac->installEventFilter(this);
    }

    if (mode == Message || mode == Error || mode == Warnning || mode == Confirm || mode == NOICON || mode == SNMAC)
    {
        if (mode == Warnning) {
            lb_title->setStyleSheet("background-color: rgb(255, 255, 0);");
        } else if (mode == Error) {
            lb_title->setStyleSheet("background-color: rgb(255, 0, 0);");
        } else if (mode == Confirm) {
            lb_title->setStyleSheet("background-color: rgb(255, 255, 127);");
        } else if (mode == Message || mode == SNMAC) {
            lb_title->setStyleSheet("background-color: rgb(174, 238, 238);");
        }

        if (mode != SNMAC) {
            bt_ok = new QPushButton(frame);
            bt_ok->setObjectName(QString::fromUtf8("bt_ok"));
            if (mode == NOICON) {
                bt_ok->setGeometry(QRect(350, 250, 100, 40));
            } else {
                bt_ok->setGeometry(QRect(350, 230, 100, 40));
            }

            bt_ok->setFont(font);
            bt_ok->setText(tr("PASS"));

            bt_fail = new QPushButton(frame);
            bt_fail->setObjectName(QString::fromUtf8("bt_fail"));
            if (mode == NOICON) {
                bt_fail->setGeometry(QRect(350, 250, 100, 40));
            } else {
                bt_fail->setGeometry(QRect(470, 230, 100, 40));
            }

            bt_fail->setFont(font);
            bt_fail->setText(tr("FAIL"));

            connect(bt_ok, SIGNAL(clicked()), this, SLOT(proButtonOK()));
            connect(bt_fail, SIGNAL(clicked()), this, SLOT(proButtonFail()));
        } else {
            bt_snmac = new QPushButton(frame);
            bt_snmac->setObjectName(QString::fromUtf8("bt_snmac"));
            bt_snmac->setGeometry(QRect(470, 230, 100, 40));
            bt_snmac->setFont(font);
            bt_snmac->setText(tr("CANCEL"));
            connect(bt_snmac, SIGNAL(clicked()), this, SLOT(proButtonCancel()));
        }
    }

}

MessageForm::~MessageForm()
{
    if (gstr_message_form != NULL) {
        gstr_message_form = NULL;
    }
}

void MessageForm::keyPressEvent(QKeyEvent *event)
{



}

bool MessageForm::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == le_snmac && event->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        if (keyEvent->key() == Qt::Key_Enter || keyEvent->key() == Qt::Key_Return)
        {
            QString str = le_snmac->text();
            _set_sn_mac_text(str);
            QTimer::singleShot(1000, gstr_maintestwindow, SLOT(resume_message_box()));
        }
    }

    return QObject::eventFilter(obj, event);
}

void MessageForm::_set_sn_mac_text(QString &str)
{
    m_sn_mac_msg = str;
}

QString MessageForm::get_sn_mac_text()
{
    return m_sn_mac_msg;
}

void MessageForm::proButtonOK()
{
    accept();
}

void MessageForm::proButtonFail()
{
    reject();
}

void MessageForm::proButtonCancel()
{
    reject();
}

int MessageForm::startExec()
{
    show();
    return exec();
}

bool MessageBox(QWidget *parent,const int mode,const QString &title,const QString &text,const int timeout)
{
    int timeoutTemp = timeout;

    QPointer<MessageForm> form = new MessageForm(NULL, mode, timeoutTemp);

    form->setTitle(title);
    if (mode != MessageForm::SNMAC) {
        form->setText(text);
    } else {
        form->setLabel(text);
    }

    int ret = form->startExec();

    delete form;
    form = NULL;
    return !!ret;
}


