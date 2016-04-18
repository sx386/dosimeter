
  unsigned char Lang = 1;  // ���� (1: �������: 0: ����������)  
  unsigned char OnSTOP = 0;  // 1: ������� � ����� "����"
  unsigned int GenImp = 0;  // ���������� ��������� �������
  unsigned int GenImpDraw = 0;  // ���������� ��������� �������

/* --------------------------------- */
/* --- ��������� ------------------- */
/* --------------------------------- */

  unsigned char on_Generator = 0;  // ��� (1: �������; 0: ��������)
  unsigned char on_Button = 0;  // ������� ������ (1: �����������; 0: �� �����������)
  unsigned char on_Led = 1;  // �������� ��������� (1: ��������; 0: ���������)
  unsigned char on_Led_Lcd = 0;  // ��������� ������� (1: ��������; 0: ���������)
  unsigned char on_Sound = 0;  // �������� ��������� (1: ��������; 0: ���������)
  unsigned char process_Led = 0;  // �������� ��������� (1: � ��������; 0: ���������)

/* --------------------------------- */
/* --- ���� ------------------------ */
/* --------------------------------- */

  unsigned char TimeCount = 10;  // ������� ��� �����
  unsigned long int TimeRun = 0;  // ������� ����� ���������
  unsigned long int PowerDownTime = 3600;  // ����� �� ��������������� ����������, �
  unsigned char on_PowerDownTime = 1;  // �������������� ���������� (1: ��������; 0: ���������)

/* --------------------------------- */
/* --- ������ ---------------------- */
/* --------------------------------- */

  unsigned char Button = 0;  // ������� ������
  unsigned char Button_exec = 0;  // ��������� ������� ������
  unsigned char Button_time = 0;  // ������� ������: ������ �� 30 ��. 
  unsigned int TimeButtonAct = 0;  // ����� ����� ���������� ������� �� ������
  unsigned char ButtonDisable = 0;  // 0: ������ �������; (1... - ���������� �� 0,5�. ������������ ������)

/* --------------------------------- */
/* --- Led ��������� � ��������� --- */
/* --------------------------------- */

  unsigned int Led_count = 0;  // ������� �������� ���������
  unsigned int Led_Lcd_Percent = 70;  // ��������� ������� (0...99) 
  
/* --------------------------------- */
/* --- ����������� ----------------- */
/* --------------------------------- */

  unsigned long int alarm = 50;  // ������� �����������
  unsigned char on_alarm = 1;  // (1: ��������; 0: ���������)

/* --------------------------------- */
/* --- ������� --------------------- */
/* --------------------------------- */

  unsigned char cache [4] [112];  // ��� ������ �������
  unsigned char draw = 1;  // ������ ������ �� ���� � ������� (1: ���������)

/* --------------------------------- */
/* --- ���� ------------------------ */
/* --------------------------------- */

  unsigned char Menu1 = 0;   
  unsigned char Menu2 = 0;
  unsigned char MenuS = 0;
  unsigned char MenuS_enter = 0;

/* --------------------------------- */
/* --- ���������� ������� ---------- */
/* --------------------------------- */

  unsigned int Batt = 0;  // ���������� �������, ����� * 100
  unsigned int BattLow = 0;  // ���������� ��������� ����������� (���� ������������)
  unsigned int BattGet = 0;  // 1: ��������� ��������� ����������
  unsigned int BattPercent = 0;  // ���������� ������� � ����� (0...27)
  unsigned int Batt_max = 400;  // ������������ ����������
  unsigned int Batt_min = 352;  // ����������� ����������
  unsigned char Batt_Low_Power_Down = 0;  // ������� ��������� (1: ��, 0: ���)

/* -------------------------------- */
/* --- ��������� �������� --------- */
/* -------------------------------- */
  
  unsigned long int Geiger = 360;  // ������ ��������
  unsigned long int Dose = 0;  // ����������� ����
  unsigned int Rad_counter = 0;  // ������� ������� ��������
  unsigned int Rad = 0;  // �������� �������� (���/�)
  unsigned int Rad_time = 60;  // ����� ���������
  unsigned short int Rad_array [120];  // ������ ������� �� 0.5 ���.
  unsigned char Rad_array_cnt = 0;  // ������� ������� ������� �� 0.5 ���.
  unsigned int Rad_array_Second [200];  // ������ ������� �� 5 ���
  unsigned char Rad_array_Second_cnt = 0;  // ������� ������� ������� �� 5 ���.
  
  
   unsigned int temp = 0;
  
/* -------------------------------- */
/* --- ������� ���������� --------- */
/* -------------------------------- */

void var_reset (void) {
  
  TimeCount = 8;  // ������� ��� �����
  TimeRun = 0;  // ������� ����� ���������

  TimeButtonAct = 0;  // ����� ����� ���������� ������� �� ������
  ButtonDisable = 0;  // 0: ������ �������; (1... - ���������� �� 0,5�. ������������ ������)

  Led_count = 0;  // ������� �������� ���������

  Menu1 = 0;   
  Menu2 = 0;
  MenuS = 0;
  MenuS_enter = 0;

  Batt = 0;  // ���������� �������, ����� * 100
  BattLow = 0;  // ���������� ��������� ����������� (���� ������������)
  BattGet = 0;  // 1: ��������� ��������� ����������
  BattPercent = 0;  // ���������� ������� � ����� (0...27)
  Batt_Low_Power_Down = 0;   // ������� ��������� (1: ��, 0: ���)

  Rad_counter = 0;  // ������� ������� ��������
  Rad = 0;  // �������� �������� (���/�)

  char Index;
     
  // ������ ������� �� 0.5 ���.  
     for (Index = 0; Index < 120; Index ++) Rad_array [Index] = 0;
     
  // ������� ������� ������� �� 0.5 ���.    
     Rad_array_cnt = 0;  
     
  // ������ ������� �� 5 ���     
     for (Index = 0; Index < 200; Index ++) Rad_array_Second [Index] = 0;
     
  // ������� ������� ������� �� 5 ���.
     Rad_array_Second_cnt = 0;

     
     
  // ������� ���� �������
     CacheClear ();   
     
     
  // ������ ������ �� ���� � ������� (1: ���������)     
     draw = 1; 
}