volatile int msg = 0, ack=0;

void * thr1(void * arg)
{
L0:  msg = 0;
  if (ack != 0){
	 goto L0;}
L1: msg = 1;
   if (ack != 1){
	 goto L1;}
}

void * thr2(void * arg)
{
  L0:  ack = 1;
  if (msg != 0){
 	goto L0;}
L1: ack = 0;
   if (msg != 1){
	goto L1;}
}


int main()
{
  __CPROVER_ASYNC_0: thr1(0);
  __CPROVER_ASYNC_1: thr2(0);
//thr2(0);

return 0;
}

