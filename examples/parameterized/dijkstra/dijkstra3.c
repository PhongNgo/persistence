volatile int flag[3] = {0,0,0}, turn = 0;

int N = 3;

void * thr0(void * arg)
{
  int i = 0;
  int j = 0;
  while (1) {
  L: 	flag[0] = 1;
        while (turn != i) {
   		if (flag[turn] == 0) turn = i;
        }
	flag[i] = 2;
	for (j=0; j<N; j++) {
		if ( j != i && flag[j] == 2) goto L;
	}
        // CS
	flag[i] = 0;
  }
}

void * thr1(void * arg)
{
  int i = 1;
  int j = 0;
  while (1) {
  L: 	flag[0] = 1;
        while (turn != i) {
   		if (flag[turn] == 0) turn = i;
        }
	flag[i] = 2;
	for (j=0; j<N; j++) {
		if ( j != i && flag[j] == 2) goto L;
	}
        // CS
	flag[i] = 0;
  }
}


void * thr2(void * arg)
{
  int i = 2;
  int j = 0;
  while (1) {
  L: 	flag[0] = 1;
        while (turn != i) {
   		if (flag[turn] == 0) turn = i;
        }
	flag[i] = 2;
	for (j=0; j<N; j++) {
		if ( j != i && flag[j] == 2) goto L;
	}
        // CS
	flag[i] = 0;
  }
}

int main()
{
  __CPROVER_ASYNC_0: thr0(0);
  __CPROVER_ASYNC_1: thr1(0);
  __CPROVER_ASYNC_2: thr2(0);
//thr2(0);

return 0;
}

