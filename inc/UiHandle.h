#ifndef UIHANDLE_H
#define UIHANDLE_H
#include "ui.h"
#include <iostream>
using namespace std;
class MainTestWindow;
class StressTestWindow;
class DisplayTestWindow;

class UiHandle: public QObject
{
    Q_OBJECT

    public:
        UiHandle();
        ~UiHandle();
        MainTestWindow *maintestwindow;
        StressTestWindow *stresstestwindow;
        DisplayTestWindow *displaytestwindow;

    public:
        void add_interface_test_button(string item);
        void add_main_label(string item, string result);
        void add_main_test_button(string item);
        void confirm_test_result_dialog(string title);
        void set_test_result(string item, string result, string ui_log);
        void show_display_ui();
        void show_stress_test_ui();
        void update_screen_log(string textInfo);
        void update_stress_label_value(string item, string result);
        void sync_main_test_ui();
        void to_show_main_test_ui();
        void add_complete_or_single_test_label(string config);
        void show_sn_mac_message_box();
        QPushButton *get_qobject(string name);

    signals:
        void to_draw_main_test_window();
        void need_to_show_main_test();
        void print_result(QString func, QString result, QString log);


};


#endif//UIHANDLE_H
