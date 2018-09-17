#include <QApplication>
#include "inc/Control.h"
#include "inc/fac_utils.h"
#include "inc/fac_log.h"

void* semi_auto_test_control(void* arg)
{
    Control* control = Control::get_control();
    while(1){
		int testStep = control->get_test_step();
		FuncFinishStatus* funcFinishStatus = control->get_func_finish_status();
        usleep(500000);
        if(testStep != STEP_IDLE){
            if (funcFinishStatus->mem_finish && funcFinishStatus->fan_finish) {
				LOG_INFO("upload log");
			}
            
            switch(testStep){
                case STEP_MEM:
                {
                    if(funcFinishStatus->mem_finish){
                        testStep = STEP_FAN;
                        LOG_INFO("interface_finish OK.\n");
                        control->start_fan_test();
                    }
                }break;
                default:
                    break;
            }
        }
    }
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFont font("Microsoft YaHei", 14, QFont::Normal);
    a.setFont(font);

    Control::get_control()->show_main_test_ui();

	pthread_t tid;
    pthread_create(&tid,NULL,semi_auto_test_control,NULL);

    return a.exec();
}
