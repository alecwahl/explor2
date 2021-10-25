/* libapportion.h */
#include <stddef.h>
#include <assert.h>


void *apportion(unsigned int size){
  size += 4;
  void *p = sbrk(0);
  void *request = sbrk(size);
  if(request == (void *)-1){
    return NULL;
  }else{
    assert(p == request);
    ((int *)request)[0] = size - 4;
    return p + 4;
  }

}


// Uncomment this part for part 3!
void release(void *ptr){
  int size = ((int *)ptr)[-1];
  //printf("Size: %p",ptr - 4);
  brk(ptr - 4);
}
