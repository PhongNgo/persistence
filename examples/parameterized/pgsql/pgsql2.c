volatile _Bool latch = 0;
volatile _Bool work_to_do = 0;
volatile _Bool existWaiter = 0;

void* waiter1(void* arg) 
{  
  for(;;) 
  {   
    // ResetLatch();
    latch = 0;

    //check work;
    if(work_to_do) 
    { 
      //do work here; 
      work_to_do = 0;
    } 

    //WaitLatch();
    while(!latch) {} 

  } 
}

void* waker1(void* arg)
{
  
  for(;;)
  {
    work_to_do = 1;

    //SetLatch();
    if(latch == 0)
    {
      latch = 1;
    } else {
  	//return in SetLatch();
    }
  }

}


int main()
{
__CPROVER_ASYNC_1: waiter1(0);
__CPROVER_ASYNC_2: waker1(0);

  return 0;
}

