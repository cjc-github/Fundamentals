#include "TestWrapper.h"
#include "test_class.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif 

void register_c(Register_Request rr){
    test(rr);
}

#ifdef __cplusplus
};
#endif 
