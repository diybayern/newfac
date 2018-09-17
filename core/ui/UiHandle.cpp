#include "inc/UiHandle.h"

UiHandle::UiHandle()
{
    maintestwindow = new MainTestWindow;
    connect(this, SIGNAL(to_draw_main_test_window()), maintestwindow, SLOT(draw_main_test_window()));
    connect(this, SIGNAL(need_to_show_main_test()), maintestwindow, SLOT(show_main_test_window()));
    connect(this, SIGNAL(print_result(QString,QString,QString)), maintestwindow, SLOT(get_result_string(QString,QString,QString)));
}

UiHandle::~UiHandle()
{

}

void UiHandle::add_interface_test_button(string item)
{
    maintestwindow->add_interface_test_button(QString::fromStdString(item));
}

void UiHandle::add_main_label(string item, string result)
{
    maintestwindow->add_main_label(QString::fromStdString(item), QString::fromStdString(result));
}

void UiHandle::add_main_test_button(string item)
{
    maintestwindow->add_main_test_button(QString::fromStdString(item));
}

void UiHandle::confirm_test_result_dialog(string title)
{
    maintestwindow->confirm_test_result_dialog(QString::fromStdString(title));
}

void UiHandle::set_test_result(string item, string result, string ui_log)
{
    emit print_result(QString::fromStdString(item), QString::fromStdString(result), QString::fromStdString(ui_log));
}

void UiHandle::sync_main_test_ui()
{
    emit to_draw_main_test_window();
}

void UiHandle::to_show_main_test_ui()
{
    emit need_to_show_main_test();
}

void UiHandle::show_display_ui()
{

}

void UiHandle::show_stress_test_ui()
{

}

void UiHandle::add_complete_or_single_test_label(string config)
{
    maintestwindow->add_complete_or_single_test_label(QString::fromStdString(config));
}

void UiHandle::update_screen_log(string textInfo)
{
    maintestwindow->update_screen_log(QString::fromStdString(textInfo));
}

void UiHandle::update_stress_label_value(string item, string result)
{


}

void UiHandle::show_sn_mac_message_box()
{
    maintestwindow->show_sn_mac_message_box();
}

QPushButton* UiHandle::get_qobject(string name)
{
    QObject *obj = new QObject;
    for (int i = 0 ; i < maintestwindow->itemlist.count(); i++)
    {
        string objname = (maintestwindow->itemlist.at(i).name).toStdString();
        if (objname == name)
        {
            obj = maintestwindow->itemlist.at(i).button;
            QPushButton *b = qobject_cast<QPushButton*>(obj);
            return b;
        }
    }
    return qobject_cast<QPushButton*>(obj);
}




