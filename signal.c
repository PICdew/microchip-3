#define Max_Signals 64

struct signal
{
  int id;
  int value;
  int type;
};

enum signals
{
  POWER_ON,POWER_OFF,MONITOR_ON,MONITOR_OFF,VOICE_ON,VOICE_OFF,MIC_ON,MIC_OFF,SOCK_ON,SOCK_OFF,ROTATE_ON,ROTATE_OFF,
  WATER_ON,WATER_OFF,SMELL_ON,SMELL_OFF,MOVING_ON,MOVING_OFF
};

signal signal_que[Max_Signals];
int current_signal=0;

void addSignal(signal arg)
{
  for(int i=0;i<Max_Signals;i++)
  {
    if(signal_que[i]==NULL)
    {
      signal_que[i]=arg;
    }
  }
}

bool pushSignal(signal arg)
{
  bool ret=false;
  for(int i=0;i<Max_Signals;i++)
  {
    if(signal_que[i]==NULL)
    {
      signal_que[i]=arg;
      ret=true;
    }
  }
  return ret;
}

signal popSignal()
{
  if(current_signal<Max_Signals)
  {
    if(signal_que[current_signal]!=NULL)
    {
      current_signal++;
      return signal_que[current_signal-1];
    }
    else
    {
      popSignal();
    }
  }
  else
  {
    current_signal=0;
    popSignal();
  }
}

