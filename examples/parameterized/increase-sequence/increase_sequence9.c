volatile int msg = 0;

void * thr1(void * arg)
{
  int i=1;
  while (i<10) {
	// here we remove the non-deterministic loop   	
	msg = 1;
  }
}

void * thr2(void * arg)
{
  int val1, val2;
  msg  = 0;
  val1= msg;
  val2 = msg;
}

void * thr3(void * arg)
{
  int val1, val2;
  msg  = 0;
  val1= msg;
  val2 = msg;
}

void * thr4(void * arg)
{
  int val1, val2;
  msg  = 0;
  val1= msg;
  val2 = msg;
}

void * thr5(void * arg)
{
  int val1, val2;
  msg  = 0;
  val1= msg;
  val2 = msg;
}

void * thr6(void * arg)
{
  int val1, val2;
  msg  = 0;
  val1= msg;
  val2 = msg;
}


void * thr7(void * arg)
{
  int val1, val2;
  msg  = 0;
  val1= msg;
  val2 = msg;
}


void * thr8(void * arg)
{
  int val1, val2;
  msg  = 0;
  val1= msg;
  val2 = msg;
}


void * thr9(void * arg)
{
  int val1, val2;
  msg  = 0;
  val1= msg;
  val2 = msg;
}

int main()
{
  __CPROVER_ASYNC_0: thr1(0);
  __CPROVER_ASYNC_1: thr2(0);
  __CPROVER_ASYNC_2: thr3(0);
  __CPROVER_ASYNC_3: thr4(0);
  __CPROVER_ASYNC_4: thr5(0);
  __CPROVER_ASYNC_5: thr6(0);
  __CPROVER_ASYNC_6: thr7(0);
  __CPROVER_ASYNC_7: thr8(0);
  __CPROVER_ASYNC_8: thr9(0);
//thr2(0);

return 0;
}

