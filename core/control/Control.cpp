#include "../../inc/Control.h"
#include "../../inc/fac_log.h"


Control::Control():QObject()
{
    uihandle                = new UiHandle();
    _funcBase[MEM]          = new MemTest(this);
	_funcBase[USB]          = new UsbTest(this);
	_funcBase[CPU]          = new CpuTest(this);
	_funcBase[EDID]         = new CpuTest(this);
	_funcBase[NET]          = new NetTest(this);
	_funcBase[HDD]          = new CpuTest(this);
	_funcBase[FAN]          = new FanTest(this);
	_funcBase[WIFI]         = new CpuTest(this);
	_funcBase[SOUND]        = new SoundTest(this);
	_funcBase[BRIGHT]       = new SoundTest(this);
	_funcBase[CAMARA]       = new SoundTest(this);
	_funcBase[STRESS]       = new StressTest(this);
	_funcBase[UPLOAD_LOG]   = new SoundTest(this);
	_funcBase[NEXT_PROCESS] = new SoundTest(this);
	
    _baseInfo               = new BaseInfo;
    _hwInfo                 = new HwInfo;
	_facArg                 = new FacArg;

	_funcFinishStatus       = new FuncFinishStatus;
	_funcFinishStatus->mem_finish       = false;
    _funcFinishStatus->usb_finish       = false;
    _funcFinishStatus->net_finish       = false;
    _funcFinishStatus->edid_finish      = false;
    _funcFinishStatus->hdd_finish       = false;
    _funcFinishStatus->fan_finish       = false;
    _funcFinishStatus->wifi_finish      = false;
    _funcFinishStatus->sound_finish     = false;
    _funcFinishStatus->screen_finish    = false;
    _funcFinishStatus->bright_finish    = false;
    _funcFinishStatus->camera_finish    = false;

	_testStep = STEP_IDLE;
	_stress_test_stage = "";
    
    init_base_info();
    init_hw_info();
    ui_init();
	init_func_test();
	init_fac_config();

	combine_fac_log_to_mes("/tmp/fac_config.conf");
	sprintf(_facArg->ftp_dest_path,"%sfac_config.conf",_facArg->ftp_dest_path);
	char* response = ftp_send_file("/tmp/fac_config.conf",_facArg);
	response = response_to_chinese(response);
	LOG_INFO("ddsds%s",response);

	auto_start_stress_test();
}

Control* Control::_control = NULL;
Control* Control::get_control()
{
    if (!_control) {
        _control = new Control();
    }
    return _control;
}

void Control::init_base_info()
{
    string dmi = "CPU:i5-6200U;MEM:8;USB:1/2;SSD:256;EMMC:0;HDD:500;WIFI:1;FAN:3800;VGA:1;HDMI:1;LCD:1920*1080;BRT:6;CAM:1";
    get_baseinfo(_baseInfo,dmi);
}

void Control::init_hw_info()
{
    get_hwinfo(_hwInfo);
}

void Control::ui_init()
{
    uihandle->add_main_label("产品型号:", "Rain410");
    uihandle->add_main_label("硬件版本:", "V1.00");
    uihandle->add_main_label("SN序列号:", "12345678");
    uihandle->add_main_label("MAC地址:", "00:11:22:33:44:55:66");
    uihandle->add_main_label("CPU型号:", "i3-6100U");
    
    uihandle->add_main_test_button("接口测试");
    
    uihandle->add_interface_test_button("内存测试");
    uihandle->add_interface_test_button("USB测试");
    uihandle->add_interface_test_button("网口测试");
    uihandle->add_interface_test_button("EDID测试");
    uihandle->add_interface_test_button("CPU测试");
    
    if (_baseInfo->hdd_cap != "0") {
        uihandle->add_interface_test_button("HDD测试");
    }
    
    if (_baseInfo->fan_speed != "0") {
        uihandle->add_interface_test_button("FAN测试");
    }

    if (_baseInfo->wifi_exist != "0") {
        uihandle->add_interface_test_button("WIFI测试");
    }

    uihandle->add_main_test_button("音频测试");
    uihandle->add_main_test_button("显示测试");
    
    if (_baseInfo->bright_level != "0"){
        uihandle->add_main_test_button("亮度测试");
    }
    
    if (_baseInfo->camara_exist != "0") {
        uihandle->add_main_test_button("摄像头测试");
    }
    
    uihandle->add_main_test_button("拷机测试");
    uihandle->add_main_test_button("上传日志");
    uihandle->add_main_test_button("下道工序");
    
    uihandle->add_complete_or_single_test_label("整机测试");
    
    uihandle->sync_main_test_ui();
    
    
    connect(uihandle->get_qobject("内存测试"), SIGNAL(clicked()), this, SLOT(start_mem_test()));
    connect(uihandle->get_qobject("USB测试"), SIGNAL(clicked()), this, SLOT(start_usb_test()));
    connect(uihandle->get_qobject("网口测试"), SIGNAL(clicked()), this, SLOT(start_net_test()));
    connect(uihandle->get_qobject("EDID测试"), SIGNAL(clicked()), this, SLOT(start_edid_test()));
    connect(uihandle->get_qobject("CPU测试"), SIGNAL(clicked()), this, SLOT(start_cpu_test()));
    if (_baseInfo->hdd_cap != "0") {
        connect(uihandle->get_qobject("HDD测试"), SIGNAL(clicked()), this, SLOT(start_hdd_test()));
    }
    
    if (_baseInfo->fan_speed != "0") {
        connect(uihandle->get_qobject("FAN测试"), SIGNAL(clicked()), this, SLOT(start_fan_test()));
    }

    if (_baseInfo->wifi_exist != "0") {
        connect(uihandle->get_qobject("WIFI测试"), SIGNAL(clicked()), this, SLOT(start_wifi_test()));
    }

    connect(uihandle->get_qobject("音频测试"), SIGNAL(clicked()), this, SLOT(start_sound_test()));
    connect(uihandle->get_qobject("显示测试"), SIGNAL(clicked()), this, SLOT(start_display_est()));

    if (_baseInfo->bright_level != "0"){
        connect(uihandle->get_qobject("亮度测试"), SIGNAL(clicked()), this, SLOT(start_bright_test()));
    }
    if (_baseInfo->camara_exist != "0") {
        connect(uihandle->get_qobject("摄像头测试"), SIGNAL(clicked()), this, SLOT(start_camera_test()));
    }
    connect(uihandle->get_qobject("拷机测试"), SIGNAL(clicked()), this, SLOT(start_stress_test()));
    connect(uihandle->get_qobject("上传日志"), SIGNAL(clicked()), this, SLOT(start_upload_log()));
    connect(uihandle->get_qobject("下道工序"), SIGNAL(clicked()), this, SLOT(start_next_process()));
    
}

void Control::init_func_test()
{
	cout << "init func" << endl;
}

void Control::init_fac_config()
{
    get_fac_config_from_conf(FAC_CONFIG_FILE, _facArg);
	cout << _facArg->ftp_dest_path << endl;
	cout << _facArg->ftp_dest_path << endl;
	cout << _facArg->ftp_dest_path << endl;
	cout << _facArg->ftp_dest_path << endl;
	cout << _facArg->ftp_dest_path << endl;
}

void Control::start_mem_test()
{
    _testStep = STEP_MEM;
    _funcBase[MEM]->start_test(_baseInfo);
    LOG_INFO("start mem test");
}

void Control::start_cpu_test()
{
    _funcBase[CPU]->start_test(_baseInfo);
    LOG_INFO("start cpu test");
}


void Control::start_usb_test()
{
    _funcBase[USB]->start_test(_baseInfo);
    LOG_INFO("start usb test");
}

void Control::start_net_test()
{
    _funcBase[NET]->start_test(_baseInfo);
    LOG_INFO("start net test");
}

void Control::start_edid_test()
{
    
    cout << "2" << endl;
}

void Control::start_hdd_test()
{
    
    cout << "2" << endl;
}

void Control::start_fan_test()
{
    _testStep = STEP_FAN;
    _funcBase[FAN]->start_test(_baseInfo);
    LOG_INFO("start fan test");
}

void Control::start_wifi_test()
{
    
    cout << "2" << endl;
}

void Control::start_sound_test()
{
    
    _funcBase[SOUND]->start_test(_baseInfo);
    LOG_INFO("start sound test");
}

void Control::start_display_test()
{
    
    cout << "2" << endl;
}

void Control::start_bright_test()
{
    
    cout << "2" << endl;
}

void Control::start_camera_test()
{
    
    cout << "2" << endl;
}

void Control::start_stress_test()
{
    _funcBase[STRESS]->start_test(_baseInfo);
    cout << "start_stress_test" << endl;
}

void Control::start_upload_log()
{
    
    cout << "2" << endl;
}

void Control::start_next_process()
{
    
    cout << "2" << endl;
}

void Control::set_test_result(string func,string result,string ui_log)

{
    cout << "func:" << func << endl;
    cout << "result:" << result << endl;
    cout << "ui_log:" << ui_log << endl;
    uihandle->set_test_result(func, result, ui_log);
}

void Control::show_main_test_ui()
{
    uihandle->to_show_main_test_ui();
}

int Control::get_test_step()
{
	return _testStep;
}

void Control::auto_start_stress_test()
{
    if (check_file_exit(STRESS_LOCK_FILE.c_str())) {
		LOG_INFO("auto start stress test");
        _stress_test_stage = execute_command("cat " + STRESS_LOCK_FILE);
		LOG_INFO("stress stage:%s",_stress_test_stage.c_str());
		_funcBase[STRESS]->start_test(_baseInfo);
	}
}

