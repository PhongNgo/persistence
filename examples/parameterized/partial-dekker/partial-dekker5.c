volatile int flag[5] = {0,0,0,0,0}, turn = 0;

void * thr0(void * arg)
{
  while (1) {
  	flag[0] = 1;
  	while(flag[1] >= 1 || flag[4] >= 1){
    		if(!(turn == 0))
      		{
        		flag[0] = 0;
       	 		while(!(turn == 0)){;}
        		flag[0] = 1;
      		}
	}
  	turn = 1;
  	flag[0] = 0;
  }
}

void * thr1(void * arg)
{
  while (1) {
  	flag[1] = 1;
  	while(flag[0] >= 1 || flag[2] >= 1){
    		if(!(turn == 1))
      		{
        		flag[1] = 0;
        		while(!(turn == 1)){;}
        		flag[1] = 1;
      }}
  turn = 2;
  flag[1] = 0;
 }
}


void * thr2(void * arg)
{
  while (1) {
  	flag[2] = 1;
  	while(flag[1] >= 1 || flag[3] >= 1){
    		if(!(turn == 2))
      		{
        		flag[2] = 0;
        		while(!(turn == 2)){;}
        		flag[2] = 1;
      }}
  turn = 3;
  flag[2] = 0;
 }
}

void * thr3(void * arg)
{
  while (1) {
  	flag[3] = 1;
  	while(flag[2] >= 1 || flag[4] >= 1){
    		if(!(turn == 3))
      		{
        		flag[3] = 0;
        		while(!(turn == 3)){;}
        		flag[3] = 1;
      }}
  turn = 4;
  flag[3] = 0;
 }
}

void * thr4(void * arg)
{
  while (1) {
  	flag[4] = 1;
  	while(flag[3] >= 1 || flag[0] >= 1){
    		if(!(turn == 4))
      		{
        		flag[4] = 0;
        		while(!(turn == 4)){;}
        		flag[4] = 1;
      }}
  turn = 0;
  flag[4] = 0;
 }
}

int main()
{
  __CPROVER_ASYNC_0: thr0(0);
  __CPROVER_ASYNC_1: thr1(0);
  __CPROVER_ASYNC_2: thr2(0);
  __CPROVER_ASYNC_3: thr3(0);
  __CPROVER_ASYNC_4: thr4(0);
//thr2(0);

return 0;
}

