volatile int ccf = 0, buf = 0;
 
void* writer(void * arg) {
   int ccf_writer;
L0:   ccf_writer = ccf;
   ccf = ccf_writer + 1;
   buf = 1;
   ccf = ccf_writer + 2;
   goto L0;
}

void* write_reader(void * arg) {
   int ccf_reader, ccf_begin, ccf_end, value;

L1:   ccf_reader = ccf;
   ccf = ccf_reader + 1;
   buf = 1;
   ccf = ccf_reader + 2;

L0:   
   ccf_begin = ccf;
   value = buf;
   ccf_end = ccf;

   if (ccf_end != ccf_begin || ccf_begin == 1){ 
     goto L0;}

   goto L1;

} 
   

int main()
{
  __CPROVER_ASYNC_1: writer(0);
  __CPROVER_ASYNC_2: write_reader(0);

return 0;
}
