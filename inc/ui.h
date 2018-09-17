#ifndef UI_H
#define UI_H

#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QLineEdit>
#include <QLabel>
#include <QCheckBox>
#include <QPushButton>
#include "UiHandle.h"
#include <QDesktopWidget>
#include <QDebug>
#include <QApplication>


class InterfaceTestItem
{
    public:
        QString itemname;
};

class MainLabelItem
{
    public:
        QString itemname;
        QString result;
};

class MainTestItem
{
    public:
        QString itemname;
};

class ItemCheck
{
    public:
        QString name;
        QObject *button;
        QObject *label;
};

class ConfigurationUtils
{
    public:
        static bool is_complete_test() {return _is_complete_test;}
        static QString get_current_configs() {return is_complete_test()?"SN" : "MAC";}
        static void set_sn_num(QString& _sn_num) {sn_num = _sn_num;}
        static void set_mac_addr(QString& _mac_addr) {mac_addr = _mac_addr;}
        static QString sn_num;
        static QString mac_addr;
        static const bool _is_complete_test = true;
};

class MainTestWindow : public QDialog
{
    Q_OBJECT

    public:
        enum {
            NO_PRODUCTID = 0,
            PRODUCTID,
        };
        explicit MainTestWindow(QWidget *parent = 0);
        ~MainTestWindow();
        void setupUI();
        void add_interface_test_button(QString item);
        void add_main_label(QString item, QString result);
        void add_main_test_button(QString item);
        void confirm_test_result_dialog(QString title);
        void update_screen_log(QString textInfo);
        void set_main_test_label_result(QString item, QString result, QString log);
        void add_complete_or_single_test_label(QString config);
        void show_sn_mac_message_box();
        QList<ItemCheck> itemlist;
        void _get_sn_num();
        void _get_mac_addr();

    private:
        //resolution
        QDesktopWidget *_desktopWidget;

        //main label layout
        QGridLayout *_main_label_layout;
        QVBoxLayout *_main_label_QVLayout;
        QHBoxLayout *_main_label_QHLayout;

        //main test layout
        QGridLayout *_main_test_layout;
        QVBoxLayout *_main_test_QVLayout;
        QHBoxLayout *_main_test_QHLayout;

        //testcount and autoupload layout
        QLineEdit *_test_count_edit;
        QCheckBox *_checkbox_auto_upload_log;
        QLabel *_lab_test_count;
        QHBoxLayout *_test_count_layout;
        QVBoxLayout *_test_count_auto_upload_layout;

        //bottom left layout
        QHBoxLayout *_bottom_left_QHlayout;

        //screen log layout
        QTextEdit *_editInfo;
        QString _editloglist;
        QVBoxLayout *_screenlog_layout;

        //function layout
        QVBoxLayout *_function_layout;

        //main test window layout
        QGridLayout *_main_test_window_layout;
        //others
        QFrame *_spilter_line;

        //lab of complete test or single board test
        QLabel *_lab_complete_or_single_test;

        void _prepare_main_label_layout();
        void _prepare_main_test_layout();
        void _prepare_screen_log_layout();
        void _prepare_test_count_and_upload_layout();
        void _prepare_spilter_line_layout();

        //buffer
        QList<InterfaceTestItem> _interface_test_list;
        QList<MainLabelItem> _main_label_item_list;
        QList<MainTestItem> _main_test_item_list;

        void _insert_item_record(ItemCheck &record);
        ItemCheck iteminfo;

        //label color
        QPalette _get_label_color(QString result);


    public slots:
        void draw_main_test_window();
        void show_main_test_window();
        void resume_message_box();
        void get_result_string(QString func, QString result, QString log);

};

class StressTestWindow : public QLabel
{
    Q_OBJECT





};

class DisplayTestWindow : public QLabel
{
    Q_OBJECT




};













extern MainTestWindow *gstr_maintestwindow;
#endif //UI_H
