volatile int x = 0, y = 0, z = 0;

void * thr1(void * arg)
{
while (1) {
   	x = 0;
	z = 1;
	x = 0;
	y = 1;
}
}


void * thr2(void * arg)
{
while (1) {
   	x = 0;
	z = 1;
	x = 0;
	y = 1;
}
}

void * thr3(void * arg)
{
while (1) {
	y = 2;
	while (x!=0) {;}
}
}

void * thr4(void * arg)
{
while (1) {
	y = 2;
	while (x!=0) {;}
}
}

void * thr5(void * arg)
{
while (1) {
	y = 2;
	while (x!=0) {;}
}
}


int main()
{
  __CPROVER_ASYNC_0: thr1(0);
  __CPROVER_ASYNC_1: thr2(0);
  __CPROVER_ASYNC_2: thr3(0);
  __CPROVER_ASYNC_3: thr4(0);
  __CPROVER_ASYNC_4: thr5(0);
  return 0;
}

